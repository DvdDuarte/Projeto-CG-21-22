#include <IL/il.h>
#include <GL/glew.h>

#include "../include/engine.h"
#include "XMLParser/tinyxml2.h"
#include <tuple>
using namespace tinyxml2;

int triangle_nmr;

int i=0;
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
float alpha = 0.0f, omega = 0.5f, r = 20.0;
int nrTriangles = 0;
bool wh;
int startX, startY, tracking = 0;
unsigned int picked = 0;

float tess=0,delta_tess=0.001;
float time_curr=0;

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
    
    r = sqrt((X-X1) * (X-X1) + (Y-Y1) * (Y-Y1) + (Z-Z1) * (Z-Z1));
    alpha = atan2(X/r, Z/r);
    omega = asin(Y / r);
    alpha = alpha/3.14 * 180;
    omega = omega/ 3.14 * 180;
 
}

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

    
    gluLookAt(position_x,position_y,position_z,
              lx,ly,lz,
              up_x,up_y,up_z);
 
    //draw axis
    draw_axis();
    

    //renderCatmullRomCurve();
    i*=2;

    for (int iteratorBrothers=0; iteratorBrothers<iBrothers; iteratorBrothers++) { //for each brother
        glPushMatrix();
        glTranslatef(posx,0.0,posz);
        glRotatef(angle, 1.0, 0.0, .0);
        glScalef(scalex, scaley, scalez);
        draw(groupbrothers[iteratorBrothers],iteratorBrothers,false);
        
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
        betaAux = omega + deltaY;

        if (betaAux > 85.0)
            betaAux = 85.0;
        else if (betaAux < -85.0)
            betaAux = -85.0;

        rAux = r;
    }
    else if (tracking == 2) {

        alphaAux = alpha;
        betaAux = omega;
        rAux = r - deltaY;
        if (rAux < 3)
            rAux = 3;
    }



    position_x = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    position_z = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    position_y = rAux * 							     sin(betaAux * 3.14 / 180.0);



    glutPostRedisplay();
}


void calcPoint(float *m, float*p, float *res) {
    res[0] = res[1] = res[2] = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            res[i] += m[i*4+j] * p[j];
        }
    }
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
            glutPostRedisplay();
        }
    }
    else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha += (xx - startX);
            omega += (yy - startY);
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


// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");

// Required callback registry
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);


    glutKeyboardFunc(keyboardFunc);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);




// put here the registration of the keyboard callbacks

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glewInit();
  //  glEnableClientState(GL_VERTEX_ARRAY);
    ilInit();
    engine (argc,argv);
// enter GLUT's main cycle
    glutMainLoop();
    return 1;
}

void t_apply_aux(float time, vector <Point> points, bool talign){
    float up[3]={0,1,0};
    float g=0;
    float pos[3],deriv[3];
    renderCatmullRomCurve(points);
     if(time!=0){
        delta_tess=1/ (time * 60);
        }
    getGlobalCatmullRomPoint(tess,pos,deriv,points);
    cout<<tess<<" "<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<endl;
    glTranslatef(pos[0],pos[1],pos[2]);
    curveRotation(deriv, up);
    
    cout<<delta_tess<<" delta_tess"<<endl;
    if(talign){
    
        r_z[0]=deriv[0],r_z[1]=deriv[1],r_z[2]=deriv[2];
        cross(r_y,r_z,r_x);
        cross(r_z,r_x,r_y);
        normalize(r_x), normalize(r_y), normalize(r_z);
        buildRotMatrix(r_x, r_y, r_z, m);
        glMultMatrixf(m);
    }
    tess+=delta_tess;
}

void draw (Group g, int itera, bool child) {
    time_curr=glutGet(GLUT_ELAPSED_TIME)*1000;
    int iForTranslate = 0;
    int iForRotate = 0;
    int iForScale = 0;
    int iForPoint=0;
    c1 = 0, c2 = 1, c3 = 1;
    for (int z = 0; z < g.orderTransform.size(); z++) { // for each transform of group

        string transform = g.orderTransform[z];
        string t = "translate";
        string r = "rotate";
        string s = "scale";

        if (transform == t) {
                cout << "translação" << endl;
                talign = g.t.at(iForTranslate).align;
                ttime = g.t.at(iForTranslate).time;
                
                if(g.t.at(iForTranslate).p.size()>=4){
                    //achar ponto na curva, usando os pontos
                    t_apply_aux(ttime,g.t.at(iForTranslate).p,talign);
                }
            iForTranslate++;
        }

        if (transform == r) {
            cout << "rotação" << endl;
            brtime=g.r.at(iForRotate).rtime;
            if(brtime){
                //falta testar
                //rotate according to rtime value
                rtime=g.r.at(iForRotate).angle;
                delta_rtangle=360/rtime;
                rangle = 0;//varia entre 0 e 360
                //delta_rtangle++;
                float r,g_aux;
                if(rtime!=0){
                        r = glutGet(GLUT_ELAPSED_TIME) % (int)(rtime * 1000);
                        g_aux = (r*360)/ (rtime * 1000);
                        
                        rx = g.r.at(iForRotate).x;
                        ry = g.r.at(iForRotate).y;
                        rz = g.r.at(iForRotate).z;
                        glRotated(g_aux, rx, ry, rz);
                       
                }
                       
            }else{
                rangle = g.r.at(iForRotate).angle; 
                rx = g.r.at(iForRotate).x;
                ry = g.r.at(iForRotate).y;
                rz = g.r.at(iForRotate).z; 
                glRotated(rangle, rx, ry, rz);
            }
           iForRotate++;
        }
        if (transform== s) {
            cout << "scale" << endl;
            sx = g.s.at(iForScale).x;
            sy = g.s.at(iForScale).y;
            sz = g.s.at(iForScale).z;
            glScalef(sx, sy, sz);
            iForScale++;
        }

    }


    nrTriangles = 0;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, itera);
    glVertexPointer(3, GL_FLOAT, 0, NULL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, g.numberOfVertices / 3);
    glFlush();



    int iterateChildren= 0;
    while (iterateChildren< g.nrchilds) {
        glPushMatrix();
        draw(g.groupchilds[iterateChildren],iterateChildren,true);
        glPopMatrix();
        iterateChildren++;
    }
}

Group readGroup (XMLElement *group, int x, bool child) {
    vbo v;
    float* vertices;
    vertices = {nullptr};
    vector<Point> points;
    vector<Translate> translates;
    vector<Rotate> rotates;
    vector<Scale> scales;
    int iFiles=0;
    vector<string> filesNames,listOfTransform;
    int  iChilds=0, iTransform=0;
    vector<Group> childs;
    XMLElement *scale,*rotate, *translate, *transform, *transformElement, *translateElement;

    char *debug = (char*) group->FirstChildElement()->Name();

    vector<Triangle> triangleVec;
    char *name;
    if (strcmp(debug,"models")!=0) {
        transform = group->FirstChildElement("transform");
        transformElement = transform->FirstChildElement();
        name = (char *) (transformElement->Name());
    }
    else {name = (char *) "end";}

        while (strcmp(name, "end") != 0) {
            if (strcmp(name, "rotate") == 0) {
                rotate = transformElement;
                listOfTransform.push_back("rotate");
                iTransform++;
                
                if (rotate->Attribute("angle") != nullptr){
                    rangle = stof(rotate->Attribute("angle"));
                    brtime=false;
                }
                if(rotate->Attribute("time") != nullptr){
                    rangle = stof(rotate->Attribute("time"));
                    brtime=true;
                }

                if (rotate->Attribute("x") != nullptr)
                    rx = stof(rotate->Attribute("x"));
                if (rotate->Attribute("y") != nullptr)
                    ry = stof(rotate->Attribute("y"));
                if (rotate->Attribute("z"))
                    rz = stof(rotate->Attribute("z"));
                
                rotates.push_back(Rotate(brtime,rangle, rx, ry, rz));
              
                rangle = 0, rx = 0, ry = 0, rz = 0;
                brtime=false;

            }
            if (strcmp(name, "translate") == 0) {
                float ttime=0;
                bool talign=false;
                translate = transformElement;
                listOfTransform.push_back("translate");
                iTransform++;
                if (translate->Attribute("time")!=nullptr)
                    ttime=stof(translate->Attribute("time"));
                if(translate->Attribute("align")!=nullptr){
                    char* aux=(char*)translate->Attribute("align");
                    if(strcmp(aux,"False")){
                        talign=false;
                    }else {
                        talign=true;
                        //casos de erro nao tratados
                    }
                }
              
                int i_points=0;
                for( translateElement=translate->FirstChildElement();translateElement!=nullptr; translateElement = translateElement->NextSiblingElement())
                { //Percorrers os points irmaos no translate
                    char *name2= (char *) (translateElement->Name());
                    if (strcmp(name2, "point") == 0) {
                        //points
                        float tx = 0, ty = 0, tz = 0;
                        if (translateElement->Attribute("x") != nullptr)
                            tx = stof(translateElement->Attribute("x"));
                        if (translateElement->Attribute("y") != nullptr)
                            ty = stof(translateElement->Attribute("y"));
                        if (translateElement->Attribute("z") != nullptr)
                            tz = stof(translateElement->Attribute("z"));

                        Point pAux=new Point(tx,ty,tz);
                        points.push_back(pAux);
                    }
                }
                translates.push_back( Translate(ttime,talign,points)) ;
                
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
                scales.push_back(Scale(sx, sy, sz));
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
        }
    int tamanho;
    if (child==0) {
        v.indexB = x;
        glGenBuffers(1, &v.indexB);
        glBindBuffer(GL_ARRAY_BUFFER, v.indexB);
        tie(vertices,tamanho) = read3dFiles(filesNames, iFiles, vertices);
        if(!filesNames.empty()) {
              glBufferData(GL_ARRAY_BUFFER, tamanho*sizeof(float), vertices, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, v.indexB);
        }
        else {
           glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, v.indexB);
        }
    }

    if (child==1) {
        v.indexC = x;
        glGenBuffers(1, &v.indexC);
        glBindBuffer(GL_ARRAY_BUFFER, v.indexC);
        tie(vertices, tamanho) = read3dFiles(filesNames, iFiles, vertices);
        if (!filesNames.empty()) {
            glBufferData(GL_ARRAY_BUFFER, tamanho * sizeof(float), vertices, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, v.indexC);
        }
        else {
            glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, v.indexC);
        }
    }


    XMLElement *groupchild2;
        int z2=0;
        for (groupchild2 = group->FirstChildElement("group");groupchild2 != nullptr; groupchild2 = groupchild2->NextSiblingElement("group")) //for each brother, see the child
        {
            childs.push_back(readGroup(groupchild2,z2,true));
            iChilds++;
            z2++;
        }
    free(vertices);
    Group g = Group(translates,rotates,scales,points,v,tamanho,childs,iChilds,listOfTransform);

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
    cart2spherical ();
}
void readXML(string filename){


}
tuple <float*,int> read3dFiles (vector<string >files, int nmr_files, float* vertices){
    int i = 0;
    int previous=9;
    vertices= (float*)malloc(9*sizeof(float));
    int iterator;
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
        int nextSize;


        if ((fp = fopen(char_aux, "r")) == NULL)
        {
            cout << s << endl;
            printf("Error %d \n", errno);
            break;
        }

        iterator=0;
        int value;
        while(fscanf(fp, "%f;%f;%f,%f;%f;%f,%f;%f;%f",&v1,&v2,&v3,&v4,&v5,&v6,&v7,&v8,&v9)>0 ){
            if(iterator==previous) {
                value = previous +9;
                vertices= (float*)realloc(vertices,value*sizeof(float));
                previous=previous+9;
            }

            vertices[iterator] = v1;
            vertices[iterator+1] = v2;
            vertices[iterator+2]  = v3;
            vertices[iterator+3] = v4;
            vertices[iterator+4] = v5;
            vertices[iterator+5] = v6;
            vertices[iterator+6] = v7;
            vertices[iterator+7] = v8;
            vertices[iterator+8] = v9;
            iterator+=9;
        }

        fclose(fp);
        i++;
    }

    return make_tuple(vertices,iterator);
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
        groupbrothers.push_back(readGroup(group,iBrothers,false));
        iBrothers++;
    }
    return 0;
}
