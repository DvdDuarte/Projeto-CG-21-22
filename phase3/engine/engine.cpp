#include "engine.h"
#include "tinyxml2.h"
using namespace tinyxml2;
int triangle_nmr;

#define POINT_COUNT 5//tem de variar

float p[POINT_COUNT][3];//tem de variar
//Triangle *tr_arr;
float c1=1.0, c2=0, c3=1.0;
int size = 10;
float posx = 0, posz = 0, angle = 0, scalex = 1, scaley = 1, scalez = 1;
float position_x=0, position_y=0, position_z=0, lx=0, ly=0 , lz=0, up_x=0, up_y=0, up_z=0, projfov=0, projnear=0, projfar=0;
vector<Group> groupbrothers;
int iBrothers= 0;

float rangle = 0,rtangle=0,delta_rtangle=0,rtime=0,taux=0,ttime= 0,rx = 0,ry = 0,rz = 0;
float m[16],r_x[3],r_y[3]={0,1,0},r_z[3];

bool brtime=false,talign=false;
float sx=1, sy=1, sz=1;
//float px=0,py=0,pz=0;//coordenadas de um ponto
vector<Point> t_points;//pontos de controlo por translate

float alpha = 0.0f, beta = 0.5f, r = 20.0;
int nrTriangles = 0;
bool wh;
int startX, startY, tracking = 0;
unsigned int picked = 0;

void buildRotMatrix(float *x, float *y, float *z, float *m) {

	m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
	m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
	m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}


void cross(float *a, float *b, float *res) {

	res[0] = a[1]*b[2] - a[2]*b[1];
	res[1] = a[2]*b[0] - a[0]*b[2];
	res[2] = a[0]*b[1] - a[1]*b[0];
}


void normalize(float *a) {

	float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] = a[0]/l;
	a[1] = a[1]/l;
	a[2] = a[2]/l;
}






string vertexToString(Vertex v){
    string vertex_info = to_string(v.x) + ";" + to_string(v.y) + ";" + to_string(v.z);
    return vertex_info;
}

void cart2spherical (){
    float X = position_x;
    float Y = position_y;
    float Z = position_z;
    float X1 = lx;
    float Y1 = ly;
    float Z1 = lz;
    // r = sqrt(X* X + Y*Y + Z*Z);
    r = sqrt((X-X1) * (X-X1) + (Y-Y1) * (Y-Y1) + (Z-Z1) * (Z-Z1));
    alpha = atan2(Z, X);
    beta = asin(Y / r);
  /*  position_x = r * cos(beta) * sin (alpha);
    position_y = r * sin(beta);
    position_z = r * cos(beta) * cos(alpha); */
}

void prepareVBO(){
//por fazer

}
//codigo curvas catmull-rom
void multMatrixVector(float *m, float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j * 4 + k];
		}
	}

}
void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *pos, float *deriv) {

	// catmull-rom matrix
	float m[4][4] = {	{-0.5f,  1.5f, -1.5f,  0.5f},
						{ 1.0f, -2.5f,  2.0f, -0.5f},
						{-0.5f,  0.0f,  0.5f,  0.0f},
						{ 0.0f,  1.0f,  0.0f,  0.0f}};
    float T[4]={(t*t*t),(t*t),t,1};
    float T_linha[4]={(3*t*t),2*t,1,0};

    //for each component x,y,z
    for(int i=0;i<3;i++){
        // Compute A = M * P
        float res[4];
        float paux[4];
        paux[0]=p0[i], paux[1]=p1[i], paux[2]=p2[i],paux[3]=p3[i];

        multMatrixVector((float *)m,paux,res);
        // Compute pos = T * A
        pos[i]=T[0]*res[0]+T[1]*res[1]+T[2]*res[2]+T[3]*res[3];
        // compute deriv = T' * A
        deriv[i]=T_linha[0]*res[0]+T_linha[1]*res[1]+T_linha[2]*res[2]+T_linha[3]*res[3];

    }

}

// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv) {
    //rever em relacao a variacao dos pontos de controle
	float t = gt * t_points.size(); // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment

	// indices store the points
    //talvez tenha de se mudar
	int indices[4]; 
	indices[0] = (index + t_points.size()-1)%t_points.size();	
	indices[1] = (indices[0]+1)%t_points.size();
	indices[2] = (indices[1]+1)%t_points.size(); 
	indices[3] = (indices[2]+1)%t_points.size();

    float p_temp[t_points.size()][3];
    for(int i=0;i<t_points.size();i++){
        p_temp[i][0]=t_points[i].x;
        p_temp[i][1]=t_points[i].y;
        p_temp[i][2]=t_points[i].z;
    }

	getCatmullRomPoint(t, p_temp[indices[0]], p_temp[indices[1]], p_temp[indices[2]], p_temp[indices[3]], pos, deriv);
}

void renderCatmullRomCurve() {
    //alterar para a fase de desenhar
// draw curve using line segments with GL_LINE_LOOP
    float t=0;
    glBegin(GL_LINE_LOOP);
    float pos[3],deriv[3];
    while(t<1){
        getGlobalCatmullRomPoint(t,pos,deriv);
        glVertex3fv(pos);
        t+=0.01;
    }
    glEnd();
}
//codigo


void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective - projection
    gluPerspective(projfov ,ratio, projnear ,projfar);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();

    cart2spherical ();
    gluLookAt(position_x,position_y,position_z,
              lx,ly,lz,
              up_x,up_y,up_z);
 
    //draw axis
    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f( 100.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f,-100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
    
    int i;

    renderCatmullRomCurve();


    for (int iteratorBrothers=0; iteratorBrothers<iBrothers; iteratorBrothers++) { //for each brother
        glPushMatrix();
        glTranslatef(posx,0.0,posz);
        glRotatef(angle, 1.0, 0.0, .0);
        glScalef(scalex, scaley, scalez);
        draw(groupbrothers[iteratorBrothers]);
        glPopMatrix();
    }


    glutSwapBuffers();
}


unsigned char  picking(int x, int y) {

    unsigned char res[4];

    return res[0];
}

// write function to process keyboard events

void keyboardFunc(unsigned char key, int x, int y) {
    switch(key) {
        case 'a':
            posx -= 0.1;
            break;
        case 'd':
            posx += 0.1;
            break;
        case 's':
            posz += 0.1;
            break;
        case 'w':
            posz -= 0.1;
            break;
        case 'q':
            angle -= 5;
            break;
        case 'e':
            angle += 5;
            break;
        case 'i':
            scalez += 0.1;
            break;
        case 'k':
            scalez -= 0.1;
            break;
        case 'j':
            scalex -= 0.1;
            break;
        case 'l':
            scalex += 0.1;
            break;
        case 'u':
            scaley -= 0.1;
            break;
        case 'o':
            scaley += 0.1;
            break;
        case '+':
            scalex += 0.1;
            scaley += 0.1;
            scalez += 0.1;
            break;
        case '-':
            scalex -= 0.1;
            scaley -= 0.1;
            scalez -= 0.1;
            break;
        case 't':
            glPolygonMode(GL_FRONT_AND_BACK, wh?GL_LINE:GL_FILL);
            wh=!wh;
            break;
    }
    glutPostRedisplay();
}


void processMouseMotion(int xx, int yy)
{

    int deltaX, deltaY;
    int alphaAux, betaAux;
    int rAux;

    if (!tracking)
        return;

    deltaX = xx - startX;
    deltaY = yy - startY;

    if (tracking == 1) {


        alphaAux = alpha + deltaX;
        betaAux = beta + deltaY;

        if (betaAux > 85.0)
            betaAux = 85.0;
        else if (betaAux < -85.0)
            betaAux = -85.0;

        rAux = r;
    }
    else if (tracking == 2) {

        alphaAux = alpha;
        betaAux = beta;
        rAux = r - deltaY;
        if (rAux < 3)
            rAux = 3;
    }



    position_x = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    position_z = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    position_y = rAux * 							     sin(betaAux * 3.14 / 180.0);



    glutPostRedisplay();
}

void processMouseButtons(int button, int state, int xx, int yy)
{

    printf("%d %d\n", xx, yy);
    if (state == GLUT_DOWN)  {
        startX = xx;
        startY = yy;
        if (button == GLUT_LEFT_BUTTON)
            tracking = 1;
        else if (button == GLUT_RIGHT_BUTTON)
            tracking = 2;
        else { // Middle button
            tracking = 0;
            picked = picking(xx,yy);
            if (picked)
                printf("Picked Snowman number %d\n", picked);
            else
                printf("Nothing selected\n");
            glutPostRedisplay();
        }
    }
    else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha += (xx - startX);
            beta += (yy - startY);
        }
        else if (tracking == 2) {

            r -= yy - startY;
            if (r < 3)
                r = 3.0;
        }
        tracking = 0;
    }

}




int main(int argc, char **argv) {
    engine (argc,argv);
// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");

// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);


    glutKeyboardFunc(keyboardFunc);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);


// put here the registration of the keyboard callbacks

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();
    return 1;
}


//como desenhar?
void draw (Group g) {
    int iForTranslate = 0;
    int iForRotate = 0;
    int iForScale = 0;
    int iForPoint=0;
    c1 = 0, c2 = 1, c3 = 1;
    for (int z = 0; z < g.orderTransform.size(); z++) {

        string transform = g.orderTransform[z];
        string t = "translate";
        string r = "rotate";
        string s = "scale";
        string p = "point";

        if (transform == t) {
            //rever
                talign = g.t[iForTranslate].align;
                ttime = g.t[iForTranslate].time;
                
                if(t_points.size()>=4){
                    //achar ponto na curva, usando os pontos
                    /*
                    for (int i=0; i<g.t[iForTranslate].p.size(); i++){
                        t_points.push_back(g.t[iForTranslate].p[i]);
                    }*/
                    float pos[3],deriv[3];

                    getGlobalCatmullRomPoint(ttime,pos,deriv);
                    glTranslatef(pos[0],pos[1],pos[3]);
                    if(talign){
                    r_x[0]=deriv[0],r_x[1]=deriv[1],r_x[2]=deriv[2];
                    cross(r_x,r_y,r_z);
                    cross(r_z,r_x,r_y);
                    normalize(r_x), normalize(r_y), normalize(r_z);
                    buildRotMatrix(r_x,r_y,r_z,m);
                    glMultMatrixf(m);
                    }

                }
                t_points.clear();
    
                iForTranslate++;
                //glTranslated(tx, ty, tz);
        }

        if (transform == r) {
            brtime=g.r[iForRotate].rtime;
            if(brtime){
                //falta testar
                //rotate according to rtime value
                rtime=g.r[iForRotate].angle;
                delta_rtangle=360/rtime;
                rangle = 0;//varia entre 0 e 360
                delta_rtangle++;
            }else{
                rangle = g.r[iForRotate].angle;    
            }
            rx = g.r[iForRotate].x;
                ry = g.r[iForRotate].y;
                rz = g.r[iForRotate].z;
                iForRotate++;
                glRotated(rtangle, rx, ry, rz);

        }
        if (transform== s) {
            sx = g.s[iForScale].x;
            sy = g.s[iForScale].y;
            sz = g.s[iForScale].z;
            glScalef(sx, sy, sz);
        }
        if(transform==p){
            float px=0,py=0,pz=0;
            px=g.p[iForPoint].x;
            py=g.p[iForPoint].y;
            pz=g.p[iForPoint].z;
            Point aux_p=Point(px,py,pz);
            t_points.push_back(aux_p);
            //guardar os pontos
        }

    }
    if(iForPoint<4){
        cout<<"erro"<<endl;//da erro
    }

    nrTriangles = 0;
    vector <Triangle> triangle_vector = g.files;
    
    //utilizar vbo para desenhar
    
    for (int i = 0; i <  triangle_vector.size(); i++) {
        // glPolygonMode(GL_FRONT,  GL_LINE);
        glBegin(GL_TRIANGLES);
        glColor3f(0,0.5,1.5);
        glVertex3f( triangle_vector[i].v1.x,  triangle_vector[i].v1.y,  triangle_vector[i].v1.z);
        glColor3f(0.0f, 0.0f, 0.5f);
        glVertex3f( triangle_vector[i].v2.x,  triangle_vector[i].v2.y,  triangle_vector[i].v2.z);
        glColor3f(0, 0, 1.5f);
        glVertex3f( triangle_vector[i].v3.x,  triangle_vector[i].v3.y, triangle_vector[i].v3.z);
        glEnd();
    }

    triangle_vector.clear();

    int iterateChildren= 0;
    while (iterateChildren< g.nrchilds) {
        glPushMatrix();
        draw(g.groupchilds[iterateChildren]);
        triangle_vector.clear();
        glPopMatrix();
        iterateChildren++;
    }
}

Group readGroup (XMLElement *group) {
    Point *points=(Point*)(malloc(20 * sizeof(Point)));//20?
    Translate *translates= (Translate *)(malloc(20 * sizeof(Translate)));
    Rotate *rotates= (Rotate *)(malloc(20 * sizeof(Rotate)));
    Scale *scales= (Scale*)(malloc(20 * sizeof(Scale)));
    int iFiles=0;
    vector<string> filesNames;
    vector<string> listOfTransform;
    int  iChilds=0, iTranslate = 0, iRotate=0, iScale=0, iTransform=0,iPoint=0;
    vector<Group> childs;
    XMLElement *scale ;
    XMLElement *rotate;
    XMLElement *translate;
    XMLElement *transform;
    XMLElement *xml_point;
    XMLElement *transformElement;
    XMLElement *translateElement;

    char *debug = (char*) group->FirstChildElement()->Name();
    char *aux;//debug para o translate element

    vector<Triangle> triangleVec;
    char *name;
    if (strcmp(debug,"models")!=0) {
        transform = group->FirstChildElement("transform");
        transformElement = transform->FirstChildElement();
        name = (char *) (transformElement->Name());
    }
    else {
        name = (char *) "end";
    }
        while (strcmp(name, "end") != 0) {
            if (strcmp(name, "rotate") == 0) {
                rotate = transformElement;
                listOfTransform.push_back("rotate");
                iTransform++;
                rangle = 0, rx = 0, ry = 0, rz = 0;
                brtime=false;
                if (rotate->Attribute("angle") != nullptr){
                    rangle = stof(rotate->Attribute("angle"));
                    brtime=false;
                }
                else if(rotate->Attribute("time") != nullptr){
                    rangle = stof(rotate->Attribute("time"));
                    brtime=true;
                }
                if (rotate->Attribute("x") != nullptr)
                    rx = stof(rotate->Attribute("x"));
                if (rotate->Attribute("y") != nullptr)
                    ry = stof(rotate->Attribute("y"));
                if (rotate->Attribute("z"))
                    rz = stof(rotate->Attribute("z"));
                
                rotates[iRotate] = Rotate(brtime,rangle, rx, ry, rz);
                iRotate++;

            }
            if (strcmp(name, "translate") == 0) {
                float ttime=0;
                bool talign=false;
                translate = transformElement;
                if (translate->Attribute("time")!=nullptr)
                    ttime=stof(translate->Attribute("time"));
                if(translate->Attribute("align")!=nullptr){
                    const char* aux=(translate->Attribute("align"));
                    if(strcmp(aux,"False")){
                        talign=false;
                    }else {
                        talign=true;
                        //casos de erro nao tratados
                        //o que fazer
                    }
                }
                translateElement=translate->FirstChildElement();
                name = (char *) (translateElement->Name());
                int i_points=0;
                XMLElement *xml_points=translate->FirstChildElement();
                while(translateElement != nullptr){ //Percorrers os points irmaos no translate
                    if (strcmp(name, "point") == 0) {
                        //points
                        xml_point=translateElement;
                        listOfTransform.push_back("point");//?
                        iTransform++;//?
                        float tx = 0, ty = 0, tz = 0;
                        if (xml_point->Attribute("x") != nullptr)
                            tx = stof(translate->Attribute("x"));
                        if (xml_point->Attribute("y") != nullptr)
                            ty = stof(translate->Attribute("y"));
                        if (xml_point->Attribute("z") != nullptr)
                            tz = stof(translate->Attribute("z"));

                        translateElement = translateElement->NextSiblingElement();
                        if (translateElement!= nullptr) {
                        name = (char *) (translateElement->Name());
                        }
                        //sem restricao de 4 pontos
                        points[iPoint] = Point(tx, ty, tz);
                        iPoint++;
                    }
                }
            }

            if (strcmp(name, "scale") == 0) {
                scale = transformElement;
                listOfTransform.push_back("scale");
                iTransform++;
                sx = 1, sy = 1, sz = 1;
                if (scale->Attribute("x") != nullptr)
                    sx = stof(scale->Attribute("x"));
                if (scale->Attribute("y") != nullptr)
                    sy = stof(scale->Attribute("y"));
                if (scale->Attribute("z") != nullptr)
                    sz = stof(scale->Attribute("z"));
                scales[iScale] = Scale(sx, sy, sz);
                iScale++;
            }

            if (transformElement->NextSiblingElement() != nullptr) {
                transformElement = transformElement->NextSiblingElement();
                name = (char *) (transformElement->Name());

            } else name = (char *) "end";
        }
    XMLElement *models;
    if (strcmp(debug,"models")!=0) {
        models = transform->NextSiblingElement("models");
    }
    else {
        models = group->FirstChildElement("models");
    }
        for (models; models != nullptr; models = models->NextSiblingElement()) { //Percorrers os models irmaos no group
            XMLElement *model = models->FirstChildElement("model");
            for (model; model != nullptr; model = model->NextSiblingElement()) {
                cout << "file do model " << model->Attribute("file") << endl;
                filesNames.push_back(model->Attribute("file"));
                iFiles++;
            }
            triangleVec = read3dFiles(filesNames, iFiles,  triangleVec);

        }


    XMLElement *groupchild2;

        for (groupchild2 = group->FirstChildElement("group");groupchild2 != nullptr; groupchild2 = groupchild2->NextSiblingElement("group")) //for each brother, see the child
        {
            childs.push_back(readGroup(groupchild2));
            iChilds++;
        }

    Group g = Group(translates,rotates,scales,points, triangleVec,childs,iChilds,listOfTransform);

    return g;

}

void readCamera(XMLElement *world) {
    XMLElement *camera = world->FirstChildElement("camera");
    XMLElement *position = camera->FirstChildElement("position");
    XMLElement *lookat = position->NextSiblingElement("lookAt");
    XMLElement *up= lookat->NextSiblingElement("up");
    XMLElement *projection= up->NextSiblingElement("projection");

    if(position->Attribute("x")!= nullptr) position_x=stof(position->Attribute("x"));
    if(position->Attribute("y")!= nullptr) position_y=stof(position->Attribute("y"));
    if(position->Attribute("z")!= nullptr) position_z=stof(position->Attribute("z"));
    if(lookat->Attribute("x")!= nullptr) lx=stof(lookat->Attribute("x"));
    if(lookat->Attribute("y")!= nullptr) ly=stof(lookat->Attribute("y"));
    if(lookat->Attribute("z")!= nullptr) lz=stof(lookat->Attribute("z"));
    if(up->Attribute("x")!= nullptr) up_x= stof(up->Attribute("x"));
    if(up->Attribute("y")!= nullptr) up_y=stof(up->Attribute("y"));
    if(up->Attribute("z")!= nullptr) up_z=stof(up->Attribute("z"));
    if(projection->Attribute("fov")!= nullptr) projfov= stof(projection->Attribute("fov"));
    if(projection->Attribute("near")!= nullptr) projnear= stof(projection->Attribute("near"));
    if(projection->Attribute("far")!= nullptr) projfar= stof(projection->Attribute("far"));

}
void readXML(string filename){


}
vector<Triangle> read3dFiles (vector<string >files, int nmr_files, vector<Triangle> tr_arr){
    int i = 0;
    while(i < nmr_files) {

        char * char_aux;
        string s = "../generator/build/" + files[i];
        char_aux = const_cast<char*> (s.c_str());

        FILE * fp;
        cout<< "Ficheiro " << s << endl;
        errno = 0;
        fp = fopen (char_aux,"r+");

        int index = 1;
        float v1, v2, v3, v4,v5,v6,v7,v8,v9;

        string line;

        if ((fp = fopen(char_aux, "r")) == NULL)
        {
            cout << s << endl;
            printf("Error %d \n", errno);
         //   cout << "error in open" << endl;
            break;
        }
        while(fscanf(fp, "%f;%f;%f,%f;%f;%f,%f;%f;%f",&v1,&v2,&v3,&v4,&v5,&v6,&v7,&v8,&v9)>0 ){
                Vertex *vv1 = new Vertex(v1,v2,v3);
                Vertex *vv2 = new Vertex(v4,v5,v6);
                Vertex *vv3 = new Vertex(v7,v8,v9);
                Triangle *tr1 = new Triangle(vv1,vv2,vv3);
                tr_arr.push_back(tr1);
            }
        fclose(fp);
        i++;
    }
    return tr_arr;
}

int engine (int argc, char **argv) {
   // groupbrothers = (Group *) malloc(size * sizeof(Group));
    ifstream file;
    string name;
    if (argc != 1) {
        name.append("../test_files/").append(argv[1]);
        cout << BOLD_YELLOW << "FILENAME: " << RESET << name << endl;
    }
    XMLDocument document;
    bool load = document.LoadFile(name.c_str());
    cout << BOLD_RED << "ERROR: " << RESET << load << endl;
    if (load != 0) return -1;
    string *filesNames = (string *) malloc(10000 * sizeof(string));
    int i = 0;
    XMLElement *world = document.FirstChildElement("world");

    readCamera(world);
    XMLElement *camera = world->FirstChildElement("camera");
    XMLElement *group;

    for (group = camera->NextSiblingElement("group");group != nullptr; group = group->NextSiblingElement("group")) //iterator for brother
    {
        groupbrothers.push_back(readGroup(group));
        iBrothers++;
    }
    return 0;
}