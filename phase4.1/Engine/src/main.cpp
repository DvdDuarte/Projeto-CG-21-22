#include <cstdlib>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../../Utils/Point3D.h"
#include "../include/Group.h"
#include "../include/VBO.h"
#include "../include/Lights/Light.h"
#include "../include/XMLParser/xmlParser.h"

#include "../include/colors.h"
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>

using namespace std;

bool Translation::showCurves=false;
bool Transform::paused=false;
float Transform::time_multiplier=1;
int Transform::retroceder=1;
bool axis=false,wire=true,firstCursor=true;
unordered_map<string,VBO> buffers;
vector<Group> groups;
vector<shared_ptr<Light>> lights;
int xMouseB4,yMouseB4;
float yaw=-155.0f,pitch=0.0f; //yaw horizontal turn//pitch vertical turn
float sensitivity = 0.3f; //sensibilidade do rato
float speed=1.0f;
int timebase;
float frames;

float position_x=0, position_y=0, position_z=0, lx=0, ly=0 , lz=0, up_x=0, up_y=0, up_z=0, projfov=0, projnear=0, projfar=0;//tentativa para melhorar camera

vector<Point3D> camera_def;
Point3D lookingAtPoint(-0.88,0,-0.48);
Point3D camPosition(200,0,109.5);
Point3D upVec(0,1,0);
Point3D proj(45.0f , 1.0f ,10000.0f);//fov,near,far
bool key_states[256];

float triangles = 0;


//por ver
float alpha=0;
float omega=0.5;
float r=20;


void cart2spherical (){
    float X = camPosition.x;
    float Y = camPosition.y;
    float Z = camPosition.z;
    float X1 = lookingAtPoint.x;
    float Y1 = lookingAtPoint.y;
    float Z1 = lookingAtPoint.z;
    
    r = sqrt((X-X1) * (X-X1) + (Y-Y1) * (Y-Y1) + (Z-Z1) * (Z-Z1));
    alpha = atan2(X/r, Z/r);
    omega = asin(Y / r);
    alpha = alpha/3.14 * 180;
    omega = omega/ 3.14 * 180;
 
}


void drawAxis() {
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	
	// X axis in red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-500.0f, 0.0f, 0.0f);
	glVertex3f( 500.0f, 0.0f, 0.0f);
	// Y Axis in Green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -500.0f, 0.0f);
	glVertex3f(0.0f,  500.0f, 0.0f);
	// Z Axis in Blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -500.0f);
	glVertex3f(0.0f, 0.0f,  500.0f);
	
	glEnd();
	glEnable(GL_LIGHTING);
}

void drawFigure(Figure figure) {

	VBO vbo = buffers["models/"+figure.filename];
	glBindBuffer(GL_ARRAY_BUFFER,vbo.vertixes);
 	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,vbo.normals);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,vbo.texCoords);
	glTexCoordPointer(2,GL_FLOAT,0,0);
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo.indexes);
	figure.apply();
 	glDrawElements(GL_TRIANGLES,
 		vbo.indexCount, // número de índices a desenhar
 		GL_UNSIGNED_INT, // tipo de dados dos índices
 		0);// parâmetro não utilizado
	glColor3f(0,0,0);
	triangles += (vbo.indexCount) / 3.0;
	figure.reset();

}

void drawFigures(Group g) {
	glPushMatrix();
	
	for (auto& transform : g.transformations) {
		//cout<< "DRAWFIGURES 1"<<endl;
		auto tr = transform->applyTransform();
	//	cout << BI_BRIGHT_BLUE << "transformation" << tr[0]<< endl;
		
		g.updateFigures(tr);
	}
	for (auto& modelFileName : g.models) {

			drawFigure(modelFileName.second);
	}
	for (auto& group : g.nestedGroups) {
		//cout<< "DRAWFIGURES 3"<<endl;
		drawFigures(group);
	}
	g.isDrawn = true;
	glPopMatrix();
}

void processKeyboardInput() {
	Point3D horizontal_look=lookingAtPoint.crossProduct(Point3D(0,1,0)); // cross product entre o look e o eixo y de modo a ter apenas o ponto para onde se deve dirigir horizontalmente
	if (key_states['w'])
			camPosition+=lookingAtPoint*speed;
	if (key_states['a'])
			camPosition-=horizontal_look*speed;
	if (key_states['s'])
			camPosition-=lookingAtPoint*speed;
	if (key_states['d'])
			camPosition+=horizontal_look*speed;
	if (key_states['g'])
			speed+=0.1f;
	if (key_states['f'])
			speed-=speed>0.1?0.1f:0;
	if (key_states['-']) 
			Transform::time_multiplier+=0.01;		
	if (key_states['+']) 
			Transform::time_multiplier-=Transform::time_multiplier>0.02?0.01:0;
}

void frameRate(){
    char title[50];
    frames++;
    double time = glutGet(GLUT_ELAPSED_TIME);
    
    if (time - timebase> 1000) {
        double fps = frames * 1000.0 / (time - timebase);
        timebase = time;
        frames = 0;
        sprintf(title, "CG@DI-UM | %lf FPS", fps);
        glutSetWindowTitle(title);
    }
}

void renderScene(void) {
	processKeyboardInput();
	triangles = 0;
	// clear buffers
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();

	gluLookAt(camPosition.x,camPosition.y,camPosition.z, 
		      lookingAtPoint.x,lookingAtPoint.y,lookingAtPoint.z,
			  upVec.x,upVec.y,upVec.z);
	lights[0]->applyLight();

// put drawing instructions here
	if (axis) drawAxis();
	for (auto& g : groups) {
		drawFigures(g);
	}

	//glutSetWindowTitle(("Triangles: " + std::to_string(triangles)).c_str());
	frameRate();
	// End of frame
	glutSwapBuffers();
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

	// Set perspective
	gluPerspective(proj.x ,ratio, proj.y ,proj.z);
	

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

double radians(double degree)
{
    return (degree * (M_PI / 180));
}

void mouseControls(int x,int y) {
	if (firstCursor)
    {
        xMouseB4 = x;
        yMouseB4 = y;
        firstCursor = false;
    }
	float xoffset = x - xMouseB4;
	float yoffset = yMouseB4 - y; // reversed since y-coordinates range from bottom to top
	
	xMouseB4=x;
	yMouseB4=y;

	//modifica o offset consoante a sensibilidade
	xoffset *= sensitivity;
	yoffset *= sensitivity;
	//modifica o ângulo do ponto para o qual está a olhar
	yaw+=xoffset;
	pitch+=yoffset;
	
	// manter o pitch dentro de -90 a 90
	if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

	//calcula o novo ponto para o qual está a olhar de forma normalizada
    lookingAtPoint.x = cosf(radians(yaw)) * cosf(radians(pitch));
    lookingAtPoint.y = sinf(radians(pitch));
    lookingAtPoint.z = sinf(radians(yaw)) * cosf(radians(pitch));
}

void readFile3D(string filename) {
	VBO vbo = VBO();
	ifstream fp(filename);
	int numVertexes, numTriangles;
	float x,y,z;
	string line;
	getline(fp,line);
	istringstream iss(line);
	iss >> numVertexes >> numTriangles;
	cout << BI_BRIGHT_GREEN << "NMVERTEX " << numVertexes << " NTR " << numTriangles << endl;
	vector<float> vertixes;
	vector<unsigned int> indexes;
	vector<float> normals;
	vector<float> textureCoordinates;
	int i;
	
	// Aquisição dos Pontos de Desenho dos Triangles do ficheiro
	for(i = 0; i < numVertexes; i++) {
		getline(fp,line);
		istringstream iss(line);
		if(!(iss >> x >> y >> z)) {
			std::cout << "Erro a ler vértices do ficheiro! \n";
			break;
		}
		//adição dos valores x y e z de cada ponto a vetor de vértices
		vertixes.push_back(x);
		vertixes.push_back(y);
		vertixes.push_back(z);
	}
	
	glBindBuffer(GL_ARRAY_BUFFER,vbo.vertixes); //liga o buffer pontos ao array
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertixes.size(), vertixes.data(), GL_STATIC_DRAW);
	vbo.vertixCount=vertixes.size();
	// Aquisição dos Triangles a partir de 3 Pontos do Ficheiro
	int indicePonto1, indicePonto2, indicePonto3;
	for(i = 0; i < numTriangles; i++) {
		getline(fp,line);
		istringstream iss(line);
		if(!(iss >> indicePonto1 >> indicePonto2 >> indicePonto3)) {
			cout << "Erro a ler índices do triangulo do ficheiro! \n";
			break;
		}
		//adição do índice de cada ponto do triângulo ao vetor de índices
		indexes.push_back(indicePonto1);
		indexes.push_back(indicePonto2);
		indexes.push_back(indicePonto3);
	}
	cout << "NMR TRIANG " << (indexes.size()) << endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vbo.indexes); //liga o buffer indices ao array
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int) * indexes.size(),indexes.data(),GL_STATIC_DRAW);
 	vbo.indexCount = indexes.size();
	float normalX, normalY, normalZ;
	for(i = 0; i < numVertexes; i++) {
		getline(fp,line);
		istringstream iss(line);
		if(!(iss >> normalX >> normalY >> normalZ)) {
			cout << "Erro a ler normais do ficheiro! \n";
			break;
		}
		normals.push_back(normalX);
		normals.push_back(normalY);
		normals.push_back(normalZ);
	}
	glBindBuffer(GL_ARRAY_BUFFER,vbo.normals); //liga o buffer indices ao array
	glBufferData(GL_ARRAY_BUFFER,sizeof(float) * normals.size(),normals.data(),GL_STATIC_DRAW);
	float texX, texY;
	for(i = 0; i < numVertexes; i++) {
		getline(fp,line);
		istringstream iss(line);
		if(!(iss >> texX >> texY)) {
			std::cout << "Erro a ler texturas do ficheiro! \n";
			break;
		}
		//adição do índice de cada ponto do triângulo ao vetor de índices
		textureCoordinates.push_back(texX);
		textureCoordinates.push_back(texY);
	}
	glBindBuffer(GL_ARRAY_BUFFER,vbo.texCoords); //liga o buffer indices ao array
	glBufferData(GL_ARRAY_BUFFER,sizeof(float) * textureCoordinates.size(),textureCoordinates.data(),GL_STATIC_DRAW);
	buffers[filename]=vbo;
	cout << "file3d aqui"<< endl;
}

void readConfig(int argc, char **argv) {
	
	string name;
	xmlContent parser;
	if(argc == 2) {
		cout<< argv[1]<<endl;
		name = "configs/" + string(argv[1]);
		parser = xmlContent(name);
		
	}
	else {
		parser = xmlContent();
		
	}
	groups=parser.parse();
	unordered_set<string> files = parser.getModels(); //é um set para evitar repetidos
	for(auto& filename : files) {
		string model = "models/" + filename;
		cout<<filename<<endl;
		readFile3D(model);
	}
	lights=parser.getLights();
	
	//camera
	
	camera_def=parser.getCamera();
	camPosition = Point3D(camera_def[0]);//.x;
	lookingAtPoint = Point3D(camera_def[1]);
	upVec = Point3D(camera_def[2]);
	proj = Point3D(camera_def[3]);
	
	
}

void registerKeyDown(unsigned char key, int x, int y) {
	key_states[key]=true;
	if (key=='q')
		axis=!axis;
	if (key=='p') {
		glPolygonMode( GL_FRONT_AND_BACK, wire?GL_LINE:GL_FILL );
		wire=!wire;
	}
	if (key=='c') {
		Translation::showCurves=!Translation::showCurves;
	}
	if (key==' ')
		Transform::paused=!Transform::paused;
	if (key=='r')
		Transform::retroceder=-1*Transform::retroceder;
}

void registerKeyUp(unsigned char key, int x, int y) {
	key_states[key]=false;
}

void printCommands() {
	string commands = R"(Comandos:
		WASD - Mover Câmara
		Q - Mostrar Eixos"
		C - Mostrar Trajetórias
		'+' '-' - Aumentar/Diminuir velocidade da simulação
		SpaceBar - Pausar/Retomar simulação
		F G - Diminuir/Aumentar velocidade da câmara
		P - Mostrar PolygonMode
		R - Retroceder Simulação)";

	cout << commands << endl;
}

void init() {
	lookingAtPoint.x = cosf(radians(yaw)) * cosf(radians(pitch));
    lookingAtPoint.y = sinf(radians(pitch));
    lookingAtPoint.z = sinf(radians(yaw)) * cosf(radians(pitch));
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_RESCALE_NORMAL);
	printCommands();
}

int main(int argc, char **argv) {
// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG2021 Dream Team");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	#ifndef __APPLE__
	glewInit();
	#endif
	
// put here the registration of the keyboard callbacks
	glutIgnoreKeyRepeat(GL_TRUE);
	glutKeyboardFunc(registerKeyDown);
	glutKeyboardUpFunc(registerKeyUp);
	glutPassiveMotionFunc(mouseControls);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// Initializations
	init();
	readConfig(argc,argv); //lê o xml e configura os VBO's
	
// enter GLUT's main cycle
	glutMainLoop();
	return 1;
}
