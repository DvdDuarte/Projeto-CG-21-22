#include "engine.h"
#include "tinyxml2.h"
using namespace tinyxml2;
int triangle_nmr;
vector<Triangle> tr_arr;
//Triangle *tr_arr;
float c1=1.0, c2=1.0, c3=1.0;
float posx = 0, posz = 0, angle = 0, scalex = 1, scaley = 1, scalez = 1;

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
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(5.0,5.0,5.0,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);


    glTranslatef(posx,0.0,posz);
    glRotatef(angle, 1.0, 0.0, .0);
    glScalef(scalex, scaley, scalez);

// put the geometric transformations here
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
    for( i= 0; i< tr_arr.size(); i++){
    //     cout << UNDERLINED_BRIGHT_MAGENTA << "Entrei render Tri" << RESET << endl;
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(tr_arr[i].v1.x, tr_arr[i].v1.y, tr_arr[i].v1.z);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(tr_arr[i].v2.x, tr_arr[i].v2.y, tr_arr[i].v2.z);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(tr_arr[i].v3.x, tr_arr[i].v3.y, tr_arr[i].v3.z);
        glEnd();
    }
    


// put drawing instructions here


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
            angle -= 15;
            break;
        case 'e':
            angle += 15;
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
// put here the registration of the keyboard callbacks



//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
    glutMainLoop();

    return 1;
}

int engine (int argc, char **argv) {
    ifstream file;
    string name;
    if (argc != 1) {
        name.append("../test_files/").append(argv[1]);
        //cout << BOLD_YELLOW << "FILENAME: " << RESET << name << endl;
    }
    readXML(name);
    return 0;
}

void readXML(string filename){
    XMLDocument document;
    bool load = document.LoadFile(filename.c_str());
    //cout << BOLD_RED << "ERROR: " << RESET << load << endl;
    if(load != 0) return;
    string *filesNames = (string*)malloc (10000 * sizeof(string));
    int i = 0;
    XMLElement *world = document.FirstChildElement("world");
    XMLElement *camera = world->FirstChildElement("camera");
    XMLElement *group = camera->NextSiblingElement("group");
    XMLElement *models = group->FirstChildElement("models");
    XMLElement *model = models->FirstChildElement("model");
    int j = 0;

    for (model; model != nullptr; model = model->NextSiblingElement()) {
        filesNames[j] = (model->Attribute("file"));
        //cout<< model->Attribute("file") << endl;
        j++;
    }

    //cout << "end of models "<< endl;
    read3dFiles(filesNames, j);

}

void read3dFiles (string *files, int nmr_files){
    //cout <<"readfiles" << endl;
    int i = 0;

    while(i < nmr_files) {
        FILE * fp;
        char * char_aux;
        string s = "../generator/build/";
        char_aux = strcpy(char_aux, s.c_str());
        char* name=  strcat (char_aux , files[i].c_str());
        errno = 0;
        fp = fopen (name,"r+");

        int index = 1;
        float v1, v2, v3, v4,v5,v6,v7,v8,v9;

        string line;


        if ((fp = fopen(name, "r")) == NULL)
        {
            //cout << name << endl;
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
}
