#ifndef __APPLE__
#endif
#ifdef __APPLE__
#include <il.h>
#else
#include <GL/glew.h>
#include <IL/il.h>
#endif
#include "../../include/Group.h"
#include "../../include/Transformations/Transform.h"
#include "../../include/Transformations/Scale.h"
#include "../../include/Transformations/Translation.h"
#include "../../include/Transformations/Rotation.h"
#include "../../include/XMLParser/xmlParser.h"
#include "../../include/Lights/Light.h"
#include "../../include/Lights/DirectionalLight.h"
#include "../../include/Lights/PointLight.h"
#include "../../include/Lights/SpotLight.h"
#include "../../include/colors.h"
#include "unordered_set"

using namespace std;

xmlContent::xmlContent() {
    filename = "configs/config.xml";
}

xmlContent::xmlContent(char* st) {
    filename = string(st);
}

xmlContent::xmlContent(string st) {
    filename = st;
}

Point3D readPoint(XMLElement* info) {
    const char * readX=info->Attribute("x");
    const char * readY=info->Attribute("y");
    const char * readZ=info->Attribute("z");
    float x=readX?atof(readX):0;
    float y=readY?atof(readY):0;
    float z=readZ?atof(readZ):0;
    return Point3D(x,y,z);
}
void xmlContent:: parseCamera(XMLElement * node){

    XMLElement* camera_Elem;
    cout << node->FirstChildElement()->Name() << endl;
    if(node->FirstChildElement("position")){
        camera_Elem=node->FirstChildElement("position");

        float x = atof(camera_Elem->Attribute("x"));
        float y = atof(camera_Elem->Attribute("y"));
        float z = atof(camera_Elem->Attribute("z"));

        Point3D c = Point3D(x,y,z);
        camera.push_back(c);
        
        camera_Elem=camera_Elem->NextSiblingElement();
       
        float x_look_at = atof(camera_Elem->Attribute("x"));
        float y_look_at = atof(camera_Elem->Attribute("y"));
        float z_look_at = atof(camera_Elem->Attribute("z"));
        Point3D c_look_at = Point3D(x_look_at,y_look_at,z_look_at);
        camera.push_back(c_look_at);

        camera_Elem=camera_Elem->NextSiblingElement();
        
        float x_up = atof(camera_Elem->Attribute("x"));
        float y_up = atof(camera_Elem->Attribute("y"));
        float z_up = atof(camera_Elem->Attribute("z"));
        Point3D c_up = Point3D(x_up,y_up,z_up);
        camera.push_back(c_up);

        camera_Elem=camera_Elem->NextSiblingElement();
        
        float x_projection = atof(camera_Elem->Attribute("fov"));
        float y_projection = atof(camera_Elem->Attribute("near"));
        float z_projection = atof(camera_Elem->Attribute("far"));
        
        Point3D c_projection = Point3D(x_projection,y_projection,z_projection);
        camera.push_back(c_projection);

        /** Debugging porposes
        cout << "x " << x << " y " << y << " z " << z << endl;
        cout << "x_look_at " << x_look_at << " y_look_at " << y_look_at << " z_look_at " << z_look_at << endl;
        cout << "x_up " << x_up << " y_up " << y_up << " z_up " << z_up << endl;
        cout << "x_projection " << x_projection << " y_projection " << y_projection << " z_projection " << z_projection << endl;
        */
    }
}

void xmlContent::parseLight(XMLElement * light) {
    XMLElement * lightEl = light->FirstChildElement();
    string type(lightEl->Attribute("type"));
    if(type=="point") {
        float x = atof(lightEl->Attribute("posx"));
        float y = atof(lightEl->Attribute("posy"));
        float z = atof(lightEl->Attribute("posz"));
        shared_ptr<PointLight> pl = make_shared<PointLight>(x,y,z);
        lights.push_back(pl);
    }
    else if(type=="directional") {
        float x = atof(lightEl->Attribute("dirx"));
        float y = atof(lightEl->Attribute("diry"));
        float z = atof(lightEl->Attribute("dirz"));
        shared_ptr<DirectionalLight> dl = make_shared<DirectionalLight>(x,y,z);
        lights.push_back(dl);
    }
    else if(type=="spot") {
        float x = atof(lightEl->Attribute("posx"));
        float y = atof(lightEl->Attribute("posy"));
        float z = atof(lightEl->Attribute("posz"));
        float dx = atof(lightEl->Attribute("dirx"));
        float dy = atof(lightEl->Attribute("diry"));
        float dz = atof(lightEl->Attribute("dirz"));
        float angle = atof(lightEl->Attribute("angle"));
        shared_ptr<SpotLight> sl = make_shared<SpotLight>(x,y,z,dx,dy,dz,angle);
        lights.push_back(sl);
    }
    else {
        cout << "Error parsing lights\n";
        exit(1);
    }
}

void xmlContent::parseColor(Point3D colors[],float& shininess, XMLElement * model) {
    const char * dr, *dg, *db, *sr, *sg, *sb, *er, *eg, *eb, *ar, *ag ,*ab , *shin_aux;
    
    bool color_exists=false;
    if(model->FirstChildElement("color")){
        XMLElement *color,*d,*a,*s,*e,*shin;
        color_exists=true;
        color=model->FirstChildElement("color");
        if(color->FirstChildElement("diffuse")){
            d=color->FirstChildElement("diffuse");
            dr = d->Attribute("R");
            dg = d->Attribute("G");
            db = d->Attribute("B");
        }
        if(color->FirstChildElement("ambient")){
            a=color->FirstChildElement("ambient");
            ar = a->Attribute("R");
            ag = a->Attribute("G");
            ab = a->Attribute("B");
        }
        if(color->FirstChildElement("specular")){
            s=color->FirstChildElement("specular");
            sr = s->Attribute("R");
            sg = s->Attribute("G");
            sb = s->Attribute("B");
        }
        if(color->FirstChildElement("emissive")){
            e=color->FirstChildElement("emissive");
            er = e->Attribute("R");
            eg = e->Attribute("G");
            eb = e->Attribute("B");
        }
        if(color->FirstChildElement("shininess")){
            shin=color->FirstChildElement("shininess");
            shin_aux = shin->Attribute("value");
        } 
    }
    cout << er << endl;
    //diffuse
    double dred   = color_exists ? atof(dr) : 200;
    double dgreen = color_exists ? atof(dg) : 200;
    double dblue  = color_exists ? atof(db) : 200;
    //specular
    double sred   = color_exists ? atof(sr) : 0;
    double sgreen = color_exists ? atof(sg) : 0;
    double sblue  = color_exists ? atof(sb) : 0;
    //emissive
    double ered   = color_exists ? atof(er) : 0;
    double egreen = color_exists ? atof(eg) : 0;
    double eblue  = color_exists ? atof(eb) : 0;
    //ambient
    double ared   = color_exists ? atof(ar) : 50;
    double agreen = color_exists ? atof(ag) : 50;
    double ablue  = color_exists ? atof(ab) : 50;
    
    shininess = color_exists ? atof(shin_aux) : 0;

    colors[0] = Point3D(dred,dgreen,dblue);
    colors[1] = Point3D(sred,sgreen,sblue);
    colors[2] = Point3D(ared,agreen,ablue);
    colors[3] = Point3D(ered,egreen,eblue);
}

void xmlContent::loadTexture(string s) {

	unsigned int t,tw,th;
	unsigned char *texData;
	unsigned int texID;

    ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	ilGenImages(1,&t);
	ilBindImage(t);
    cout << "Antes Load Tex"<< endl;
	ilLoadImage((ILstring)("textures/" + s).c_str());
    cout << "Apos Load Tex" << endl;
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);
	//cout << "Image Width: " << tw << endl;
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	texData = ilGetData();

	glGenTextures(1,&texID);
	
	glBindTexture(GL_TEXTURE_2D,texID);
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_S,		GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_WRAP_T,		GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MAG_FILTER,   	GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,	GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	textures[s] = texID;

}

Group xmlContent::parseGroup(XMLElement * group) {
    Group g = Group();
    XMLElement * translation = group->FirstChildElement("translate");
    XMLElement * rotation = group->FirstChildElement("rotate");
    XMLElement * scale = group->FirstChildElement("scale");
    if (translation) {
        shared_ptr<Transform> t;
        if (const char * timeString = translation->Attribute("time")) {
            double time = atof(timeString);
            vector<Point3D> vector_points;
            for (XMLElement * point = translation->FirstChildElement("point");point;point = point->NextSiblingElement()) {
                vector_points.push_back(readPoint(point));
            }
            t = make_shared<Translation>(time,vector_points);
        }
        else {
            Point3D point = readPoint(translation);
            t = make_shared<Translation>(point.x,point.y,point.z);
        }
        g.addTransform(t);
        cout << "ate aqui tudo bem 6" << endl;
    }
      
    if (rotation) {
        shared_ptr<Rotation> r;
        const char * readAngle;
        const char * readTime;

        const char * readX=rotation->Attribute("x");
        const char * readY=rotation->Attribute("y");
        const char * readZ=rotation->Attribute("z");
        
        double axisx = readX ? atof(readX) : 0;
        double axisy = readY ? atof(readY) : 0;
        double axisz = readZ ? atof(readZ) : 0;

        if (readTime=rotation->Attribute("time")) {
            const char * clockwise = rotation->Attribute("clockwise");
            r = make_shared<Rotation>(atof(readTime),string(clockwise).size(),axisx,axisy,axisz);
        }
        else {
            readAngle=rotation->Attribute("angle");
            r = make_shared<Rotation>(atof(readAngle),axisx,axisy,axisz);
        }
        g.addTransform(r);
        cout << "ate aqui tudo bem 7" << endl;
    }
    if (scale) {
        cout << "ate aqui tudo bem 8" << endl;
        const char * readX = scale->Attribute("x");
        const char * readY = scale->Attribute("y");
        const char * readZ = scale->Attribute("z");
        double scalex = readX ? atof(readX) : 1;
        double scaley = readY ? atof(readY) : 1;
        double scalez = readZ ? atof(readZ) : 1;
        shared_ptr<Scale> s = make_shared<Scale>(scalex,scaley,scalez);
        g.addTransform(s);
        
    }

    XMLElement * models = group->FirstChildElement("models");
    if (models) {

        XMLElement * model;
        for (model=models->FirstChildElement("model");model;model=model->NextSiblingElement()) {
            Point3D colors[4]; // 1. Diffuse   2. Specular   3. Ambient   4. Emissive
            float shininess;
            parseColor(colors,shininess,model);
            int texID = 0;
            /*
            if(model->Attribute("texture")){
                
                const char * texture = model->Attribute("texture");
                
                string text_file(texture);
                if(textures.find(text_file) == textures.end()){
                    
                    loadTexture(text_file);
                    
                }
                
                texID = textures[text_file];
            }
            */
            XMLElement * texture_elem;
            cout << BOLD_CYAN << "Model Name: " << RESET << model->Name() << endl;
            if(model->FirstChildElement("texture")){
                cout << BOLD_YELLOW << "Aqui" << endl;
                texture_elem=model->FirstChildElement("texture");
                if(texture_elem->Attribute("file")){

                    const char* f=texture_elem->Attribute("file");
                    string text_file(f);
                    cout<<text_file<<endl;
                
                    if(textures.find(text_file) == textures.end()){
                        
                        loadTexture(text_file);
                    }

                texID = textures[text_file];
                }

            }

           // cout << "ate aqui esta tudo bem 9" << endl;
            g.addFile(string(model->Attribute("file")),colors,shininess,texID);
            //cout << "ate aqui tudo bem 10" << endl;
        }
    
    }
    XMLElement *groupChild;
    for (groupChild = group->FirstChildElement("group");groupChild;groupChild=groupChild->NextSiblingElement()) {
        Group groupR = parseGroup(groupChild);
        g.addGroup(groupR); 
    }
    return g;
}

vector<Group> xmlContent::parse() {
    XMLDocument doc;
    
    int err = doc.LoadFile(filename.c_str());
    cout << err << endl;

    if(err == 0) {
        cout << "Success" << endl;
        XMLElement * first = doc.FirstChildElement("world");
        XMLElement * node= first->FirstChildElement();
        
        for(node ;node != NULL;node = node->NextSiblingElement()) {
            string name(node->Name());
             cout << "ate aqui tudo bem 1" << endl;
            if(name=="group") {
                cout << "ate aqui tudo bem 4" << endl;
                Group g = parseGroup(node);
                cout << "ate aqui tudo bem 5" << endl;
                groups.push_back(g);
                
            }
            else if(name=="lights") {
                parseLight(node);
            }else if(name=="camera"){
                parseCamera(node);
            }
            else {
                cout << "Error parsing xml!" << "\n";
                exit(2);
            }
              cout << "ate aqui tudo bem 2" << endl;
        }
         cout << "ate aqui tudo bem 3" << endl;
    }
    else {
        doc.PrintError();
    }
    return groups;
}

vector<Point3D> xmlContent::getCamera() {
    return camera;
}

vector<shared_ptr<Light>> xmlContent::getLights() {
    return lights;
}

unordered_set<string> xmlContent::getModels() {
    unordered_set<string> res;
    for (auto& g : groups) {
        unordered_set<string> models=g.getModels();
        for (auto& file : models) {
            res.insert(file);
        }
    }
    return res;
}
