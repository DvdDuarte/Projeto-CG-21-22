#include "engine.h"
#include "tinyxml2.h"
using namespace tinyxml2;

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

    // Set perspective
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

// put the geometric transformations here




// put drawing instructions here


    // End of frame
    glutSwapBuffers();
}



// write function to process keyboard events





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
        name.append("/home/ema/Projeto-CG-21-22/phase1/test_files/").append(argv[1]);
        cout << "\033[1;33mFILENAME: \033[0m" << name << endl;
    }
    readXML(name);
    return 0;
}

void readXML(string filename){
    XMLDocument document;
    bool load = document.LoadFile(filename.c_str());
    cout << "\033[1;31mERROR: \033[0m" << load << endl;
    if(load != 0) return;
        vector <string> filesNames;
        int i = 0;
        XMLElement *world = document.FirstChildElement("world");
        XMLElement *camera = world->FirstChildElement("camera");
        XMLElement *group = camera->NextSiblingElement("group");
        XMLElement *models = group->FirstChildElement("models");
        XMLElement *model = models->FirstChildElement("model");
        for (model; model != nullptr; model = model->NextSiblingElement()) {
            filesNames.push_back(model->Attribute("file"));
            cout<< model->Attribute("file")<< endl;
            i++;
        }

}