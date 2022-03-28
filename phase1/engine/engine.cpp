#include "engine.h"
#include "tinyxml2.h"
using namespace tinyxml2;
int triangle_nmr;

//Triangle *tr_arr;
float c1=1.0, c2=0, c3=1.0;
int size = 10;
float posx = 0, posz = 0, angle = 0, scalex = 1, scaley = 1, scalez = 1;
float position_x=0, position_y=0, position_z=0, lx=0, ly=0 , lz=0, up_x=0, up_y=0, up_z=0, projfov=0, projnear=0, projfar=0;
vector<Group> groupbrothers;
int iBrothers= 0;
float rangle = 0,tx = 0,ty = 0, tz = 0,rx = 0,ry = 0,rz = 0;
float sx=1, sy=1, sz=1;
float r=5.0f;
float beta=0,alfa=0;
int nrTriangles = 0;


string vertexToString(Vertex v){
    string vertex_info = to_string(v.x) + ";" + to_string(v.y) + ";" + to_string(v.z);
    return vertex_info;
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
    /*
    xeye=r*cos(beta)*sin(beta);
    yeye=r*sin(beta);
    zeye=r*cos(beta)*cos(beta);
    gluLookAt(xeye,yeye,zeye,
              lx,ly,lz,
              up_x,up_y,up_z);*/

    glTranslatef(posx,0.0,posz);
    glRotatef(angle, 1.0, 0.0, .0);
    glScalef(scalex, scaley, scalez);

// put the geometric transformations here
 

// put drawing instructions here
 
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
    //cout << tr_arr.size() << endl;
    cout << iBrothers << endl;

    for (int j=0; j<iBrothers; j++) { //for each brother

        vector <Triangle> t_arr;
        int iForTranslate= 0;
        int iForRotate = 0;
        int iForScale = 0;
        glPushMatrix(); //push for brother
        cout << "tamanho de operacoes " << groupbrothers[j].orderTransform.size() << endl;
        for(int z=0; z < groupbrothers[j].orderTransform.size(); z++) {  // for each transform of each brother
            string order = groupbrothers[j].orderTransform[z];
            string t = "translate";
            string r = "rotate";
            string s = "scale";
            cout << "order " <<order<<endl;
            if (order == t){
                cout <<"render scene for translate" << endl;
                tx = groupbrothers[j].t[iForTranslate].x;
                ty = groupbrothers[j].t[iForTranslate].y;
                tz = groupbrothers[j].t[iForTranslate].z;
                iForTranslate++;
                glTranslated(tx, ty, tz);
            }

            if(order==r) {
                rangle = groupbrothers[j].r[iForRotate].angle;
                rx = groupbrothers[j].r[iForRotate].x;
                ry = groupbrothers[j].r[iForRotate].y;
                rz = groupbrothers[j].r[iForRotate].z;
                iForRotate++;
                glRotated(rangle, rx, ry, rz);
            }
            if(order==s) {
                sx = groupbrothers[j].s[iForScale].x;
                sy = groupbrothers[j].s[iForScale].y;
                sz = groupbrothers[j].s[iForScale].z;
                iForScale++;
                glScalef(sx, sy, sz);
            }

        }
        nrTriangles = 0;
        t_arr = read3dFiles(groupbrothers[j].files, groupbrothers[j].nrFiles, t_arr);
        nrTriangles= t_arr.size();
        cout << "nrTriangles: " << nrTriangles << endl;
        for(int i= 0; i< nrTriangles; i++){
            glBegin(GL_TRIANGLES);
            glColor3f(c1,c2,c3);
            glVertex3f(t_arr[i].v1.x, t_arr[i].v1.y, t_arr[i].v1.z);
            glVertex3f(t_arr[i].v2.x, t_arr[i].v2.y, t_arr[i].v2.z);
            glVertex3f(t_arr[i].v3.x, t_arr[i].v3.y, t_arr[i].v3.z);
            glEnd();
        }
        t_arr.clear();


        if (groupbrothers[j].nrchilds==0) {  //no childs

            glPopMatrix();}

        else{ //childs
            int x=0;
            cout << "FILHOS A DESENHAR" << groupbrothers[j].nrchilds << endl;
            while (x<groupbrothers[j].nrchilds){ //iterate each child
                iForTranslate= 0, iForRotate=0,iForScale=0;
                glPushMatrix(); //push matrix for a child
                for(int z=0; z < groupbrothers[j].groupchilds[x].orderTransform.size(); z++) {
                    string tr= groupbrothers[j].groupchilds[x].orderTransform[z];
                    string t = "translate";
                    string r = "rotate";
                    string s = "scale";
                    if (tr==t){
                        tx = groupbrothers[j].groupchilds[x].t[iForTranslate].x;
                        ty = groupbrothers[j].groupchilds[x].t[iForTranslate].y;
                        tz = groupbrothers[j].groupchilds[x].t[iForTranslate].z;
                        iForTranslate++;
                        glTranslated(tx, ty, tz);
                    }

                    if(tr==r) {
                        rangle = groupbrothers[j].groupchilds[x].r[iForRotate].angle;
                        rx = groupbrothers[j].groupchilds[x].r[iForRotate].x;
                        ry = groupbrothers[j].groupchilds[x].r[iForRotate].y;
                        rz = groupbrothers[j].groupchilds[x].r[iForRotate].z;
                        iForRotate++;
                        glRotated(rangle, rx, ry, rz);
                    }
                    if(tr==s) {
                        sx = groupbrothers[j].groupchilds[x].s[iForScale].x;
                        sy = groupbrothers[j].groupchilds[x].s[iForScale].y;
                        sz = groupbrothers[j].groupchilds[x].s[iForScale].z;
                        iForScale++;
                        glScalef(sx, sy, sz);
                    }


                }
                nrTriangles = 0;
                t_arr = read3dFiles(groupbrothers[j].groupchilds[x].files, groupbrothers[j].groupchilds[x].nrFiles, t_arr);
                nrTriangles= t_arr.size();
                cout << "nr :" << nrTriangles << endl;

                for(int i= 0; i< nrTriangles; i++){
                    glBegin(GL_TRIANGLES);
                    glColor3f(c1,c2,c3);
                    glVertex3f(t_arr[i].v1.x, t_arr[i].v1.y, t_arr[i].v1.z);
                    glVertex3f(t_arr[i].v2.x, t_arr[i].v2.y, t_arr[i].v2.z);
                    glVertex3f(t_arr[i].v3.x, t_arr[i].v3.y, t_arr[i].v3.z);
                    glEnd();

                }
                glPopMatrix(); //pop matrix because the childs are siblings
                t_arr.clear();
                x++;
            }

        }
    }


    // End of frame
    glutSwapBuffers();
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
    }
    glutPostRedisplay();
}


void processSpecialKeys(int key, int xx, int yy) {
    //trabalho a ser feito
// put code to process special keys in here
   if(key== GLUT_KEY_UP){
       alfa+=M_PI/64;
   }else if(key==GLUT_KEY_DOWN){
       alfa-=M_PI/64;
       //bla
   }else if(key==GLUT_KEY_LEFT){
       //bla
       beta+=M_PI/64;
       if(beta>=M_PI/2)beta=0;
   }else if(key==GLUT_KEY_RIGHT){
       //bla
       beta-=M_PI/64;
       if(beta<=-M_PI/2)beta=0;

   }else;
    glutPostRedisplay();
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
    glutSpecialFunc(processSpecialKeys);
    
// put here the registration of the keyboard callbacks



//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();
    return 1;
}



Group readGroup (XMLElement *group) {
    cout << "ler grupo" << endl;
    Translate *translates= (Translate *)(malloc(20 * sizeof(Translate)));
    Rotate *rotates= (Rotate *)(malloc(20 * sizeof(Rotate)));
    Scale *scales= (Scale*)(malloc(20 * sizeof(Scale)));
    int iFiles=0;
    vector<string> filesNames;
    vector<string> listOfTransform;
    int  iChilds=0, iTranslate = 0, iRotate=0, iScale=0, iTransform=0;
    vector<Group> childs;
    vector<Group> brothers;
    int nB =0;
    XMLElement *scale ;
    XMLElement *rotate;
    XMLElement *translate;
    XMLElement *transform = group->FirstChildElement("transform");
    XMLElement *transformElement = transform->FirstChildElement();

    char* name = (char *)(transformElement->Name());
    while(strcmp (name,"end")!=0) {

        if (strcmp(name, "rotate") == 0) {
            rotate = transformElement;
            listOfTransform.push_back("rotate");
            iTransform++;
            rangle = 0, rx = 0, ry = 0, rz = 0;
            if (rotate->Attribute("angle") != nullptr)
                rangle = stof(rotate->Attribute("angle"));
            if (rotate->Attribute("axisX") != nullptr)
                rx = stof(rotate->Attribute("axisX"));
            if (rotate->Attribute("axisY") != nullptr)
                ry = stof(rotate->Attribute("axisY"));
            if (rotate->Attribute("axisZ"))
                rz = stof(rotate->Attribute("axisZ"));
            rotates[iRotate] = Rotate(rangle, rx, ry, rz);
            iRotate++;

        }
        if (strcmp(name, "translate") == 0) {
            translate = transformElement;

            listOfTransform.push_back("translate");
            iTransform++;
            float tx = 0, ty = 0, tz = 0;
            if (translate->Attribute("x") != nullptr)
                tx = stof(translate->Attribute("x"));
            if (translate->Attribute("y") != nullptr)
                ty = stof(translate->Attribute("y"));
            if (translate->Attribute("z") != nullptr)
                tz = stof(translate->Attribute("z"));
            translates[iTranslate] = Translate(tx, ty, tz);
            iTranslate++;
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

    XMLElement *models = transform->NextSiblingElement("models");
    for (models;models != nullptr; models = models->NextSiblingElement()) { //Percorrers os models irmaos no group
        XMLElement *model = models->FirstChildElement("model");
        for (model; model != nullptr; model = model->NextSiblingElement()) {
            cout << "file " << model->Attribute("file") << endl;
            filesNames.push_back(model->Attribute("file"));
            iFiles++;
        }
    }

    XMLElement *groupchild2;

        for (groupchild2 = group->FirstChildElement("group");groupchild2 != nullptr; groupchild2 = groupchild2->NextSiblingElement("group")) //for each brother, see the child
        {

            childs.push_back(readGroup(groupchild2));

            iChilds++;
        }





    Group g = Group(translates,rotates,scales,filesNames,childs,iChilds,listOfTransform, iFiles);
    cout << "a sair do group" << endl;
    return g;

}
void readCamera(XMLElement *world) {
    cout << "ler camera" << endl;
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
    //cout <<"readfiles" << endl;
    int i = 0;
    cout << "ler triangulos" << endl;
    while(i < nmr_files) {


        char * char_aux;
        string s = "../generator/build/" + files[i];
        cout << s << endl;
        char_aux = const_cast<char*> (s.c_str());

        FILE * fp;

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
    cout << "terminou a leitura dos triangulos " << endl;
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
    cout << "ler ficheiro xml" << endl;
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

        cout << "pai " << iBrothers << endl;
        groupbrothers.push_back(readGroup(group));
        iBrothers++;
        cout << "irmao " << iBrothers << endl;
    }

    cout << "end " << endl;
    return 0;
}