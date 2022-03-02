#include "engine.h"
#include "tinyxml2.h"
using namespace tinyxml2;
int triangle_nmr;
Triangle * tr_arr;
float c1=1.0, c2=1.0, c3=1.0;

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

    for(int i= 0; i< triangle_nmr; i++){
            glBegin(GL_TRIANGLES);
            glColor3f(c1,c2,c3);
            glVertex3f(tr_arr[i].v1.x, tr_arr[i].v1.y, tr_arr[i].v1.z);
            glColor3f(c1,c2,c3);
            glVertex3f(tr_arr[i].v2.x, tr_arr[i].v2.y, tr_arr[i].v2.z);
            glColor3f(c1,c2,c3);
            glVertex3f(tr_arr[i].v3.x, tr_arr[i].v3.y, tr_arr[i].v3.z);
            glEnd();
    }


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
        name.append("/home/sleiman/Projeto-CG-21-22/phase1/test_files/").append(argv[1]);
        cout << BOLD_YELLOW << "FILENAME: " << RESET << name << endl;
    }
    readXML(name);
    return 0;
}

void readXML(string filename){
    XMLDocument document;
    bool load = document.LoadFile(filename.c_str());
    cout << BOLD_RED << "ERROR: " << RESET << load << endl;
    if(load != 0) return;
    string *filesNames;
    int i = 0;
    XMLElement *world = document.FirstChildElement("world");
    XMLElement *camera = world->FirstChildElement("camera");
    XMLElement *group = camera->NextSiblingElement("group");
    XMLElement *models = group->FirstChildElement("models");
    XMLElement *model = models->FirstChildElement("model");
    int j = 0;
    for (model; model != nullptr; model = model->NextSiblingElement()) {
        filesNames[j] = (model->Attribute("file"));
        cout<< model->Attribute("file")<< endl;
        j++;
    }
    read3dFiles(filesNames);

}

void read3dFiles (string *files){
    triangle_nmr = 2;
    int i = 0;
    tr_arr = (Triangle *) malloc (2 * triangle_nmr * sizeof(Triangle));
    
    while(files[i].c_str() != nullptr) {
        ifstream file_in;
        
        file_in.open("../generator/build/" + files[i]);

        if(file_in.fail()) {
            cerr << "ERROR on opening file " << files[i] << endl;
            file_in.close();
            exit(1);
        }

        string line, first;
        getline(file_in, first);

        string s = first;
        vector<string> out;
        const char ntr_delim = ':';
        tokengen(s,ntr_delim,out);
        triangle_nmr = stof(out.at(1));

        int index = 0;

        while(getline(file_in, line)){
            if(line == "|Triangle|") {
                cout << line << endl;
            } else if (line == "|EOT|") {
                cout << line << endl;
                index++;
            } else {
                Vertex vertexes[3];
                string vertex_line = line;
                const char delim = '$';
                vector<string> out;
                tokengen(vertex_line, delim, out);
                for(int j = 0; j < 3; j ++){
                    if(j == 3) j = 0;
                      
                    const char vertex_delim = ',';
                    string aux = out.at(j);
                    vector<string> out_1;
                    tokengen(aux, vertex_delim, out_1);
                    float v1, v2, v3;
                    v1 = stof(out_1.at(0));
                    v2 = stof(out_1.at(1));
                    v3 = stof(out_1.at(2));
                    vertexes[j] = new Vertex(v1,v2,v3);
                }
        
                Vertex *v1 = new Vertex(vertexes[0]);
                Vertex *v2 = new Vertex(vertexes[1]);
                Vertex *v3 = new Vertex(vertexes[2]);
                Triangle *tr1 = new Triangle(v1,v2,v3);
                if(index == triangle_nmr) {
                    triangle_nmr *= 2;
                    tr_arr = (Triangle *) (realloc(tr_arr, triangle_nmr * sizeof(Triangle)));
                }
                tr_arr[index] = tr1;
            }
            i++;
        }

    }
}

void tokengen (string const &line, const char delim, vector<string> &out){
    size_t start;
    size_t end = 0;

    while((start = line.find_first_not_of(delim, end)) != string::npos){
        end = line.find(delim,start);
        out.push_back(line.substr(start,end - start));
    }
}