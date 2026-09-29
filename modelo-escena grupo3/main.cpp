#include <windows.h>
#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>

// ============================================================
// HABITACION 3D - CONVERSION DEL PROYECTO FREEGLUT ORIGINAL
// ============================================================
// WASD : mover camara | Q/E : subir/bajar
// Flechas : mirar | R : reset | ESC : salir
// ============================================================

float camX=0,camY=6,camZ=18, yaw=180,pitch=-8;
bool key[256]={0};
const float PI=3.14159265359f;
float R(float a){return a*PI/180.0f;}

void mat(float r,float g,float b,float shine=20){
    GLfloat d[]={r,g,b,1},a[]={r*.25f,g*.25f,b*.25f,1},s[]={.25f,.25f,.25f,1};
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,d); glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,a);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,s); glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
}
void cube(float x,float y,float z,float sx,float sy,float sz,float r,float g,float b){
    glPushMatrix(); glTranslatef(x,y,z); glScalef(sx,sy,sz); mat(r,g,b); glutSolidCube(1); glPopMatrix();
}
void sph(float x,float y,float z,float rad,float r,float g,float b){
    glPushMatrix();glTranslatef(x,y,z);mat(r,g,b);glutSolidSphere(rad,20,14);glPopMatrix();
}
void cyl(float x,float y,float z,float rad,float h,float r,float g,float b){
    glPushMatrix();glTranslatef(x,y,z);glRotatef(-90,1,0,0);mat(r,g,b);GLUquadric*q=gluNewQuadric();gluCylinder(q,rad,rad,h,20,1);gluDisk(q,0,rad,20,1);glTranslatef(0,0,h);gluDisk(q,0,rad,20,1);gluDeleteQuadric(q);glPopMatrix();
}
void line(float x1,float y1,float z1,float x2,float y2,float z2,float r,float g,float b,float w=2){
    glDisable(GL_LIGHTING);glColor3f(r,g,b);glLineWidth(w);glBegin(GL_LINES);glVertex3f(x1,y1,z1);glVertex3f(x2,y2,z2);glEnd();glEnable(GL_LIGHTING);
}

// ---------------- PISO Y PAREDES ----------------
void piso(){
    cube(0,-.25,0,24,.5,20,.55,.30,.16);
    for(float x=-11;x<=11;x+=2) cube(x,.02,0,.025,.03,19,.38,.18,.08);
    for(float z=-9;z<=9;z+=2.5) cube(0,.04,z,23,.025,.025,.38,.18,.08);
}
void paredes(){
    cube(0,6,-10,24,12,.35,.85,.82,.75);
    cube(-12,6,0,.35,12,20,.80,.78,.72);
    cube(12,6,0,.35,12,20,.94,.91,.84);
    cube(0,.3,-9.75,24,.35,.25,.42,.20,.10);
    cube(-11.75,.3,0,.25,.35,20,.42,.20,.10);
    cube(11.75,.3,0,.25,.35,20,.42,.20,.10);
}
void puerta(){
    cube(-11.7,4,-4.7,.28,7.5,3,.50,.27,.13);
    cube(-11.52,6,-4.7,.08,1.9,2.5,.68,.43,.23);
    cube(-11.52,2.4,-4.7,.08,1.4,2.5,.68,.43,.23);
    sph(-11.25,4,-3.0,.18,.90,.72,.28);
}

// ---------------- VENTANA ----------------
void ventana(){
    cube(3.8,7,-9.76,5.8,4.5,.25,.95,.95,.98);
    cube(3.8,7,-9.55,5.15,3.85,.10,.30,.58,.82);
    cube(3.8,7,-9.35,.12,3.8,.08,.92,.92,.92);
    cube(3.8,7,-9.35,5.1,.12,.08,.92,.92,.92);
    // cortinas
    cube(.55,6.7,-9.15,1.15,4.8,.28,.72,.20,.27);
    cube(7.05,6.7,-9.15,1.15,4.8,.28,.72,.20,.27);
    glPushMatrix();glTranslatef(.5,9.45,-9.0);glRotatef(90,0,1,0);cyl(0,0,0,.11,6.8,.25,.22,.14);glPopMatrix();
}

// ---------------- CAMA ----------------
void cama(){
    float x=6.2,z=3.3;
    cube(x,1.0,z,8.4,1.5,5.2,.43,.18,.09);
    cube(x,1.9,z,7.9,.65,4.85,.92,.46,.42);
    cube(x,4.2,z+2.2,8,5,.45,.45,.17,.09);
    cube(4.4,2.45,4.0,2.5,.5,1.6,.70,.74,.84);
    cube(7.0,2.45,4.0,2.5,.5,1.6,.83,.85,.89);
    cube(8.0,2.45,2.2,3.2,.16,2.3,.35,.46,.64);
    cube(7.4,2.65,1.7,1.5,.12,1.0,.55,.18,.20);
    cube(9.2,2.58,3.0,.7,.12,1.0,.07,.08,.10);
}

// ---------------- MESA DE NOCHE / LAMPARA ----------------
void lampara(){
    cyl(1.5,3.5,5.5,.18,1.7,.65,.65,.65);
    cube(1.5,3.45,5.5,1.5,.16,1.1,.82,.82,.82);
    glPushMatrix();glTranslatef(1.5,5.5,5.5);glRotatef(180,1,0,0);mat(1,.82,.45);glutSolidCone(1.15,1.5,24,8);glPopMatrix();
}
void mesaNoche(){
    cube(1.5,1.7,5.5,2.4,2.8,2.3,.42,.15,.08);cube(1.5,3.15,5.5,2.6,.25,2.5,.60,.30,.15);
    cube(1.5,2.35,4.32,1.8,.7,.12,.28,.10,.05);cube(1.5,1.35,4.32,1.8,.7,.12,.28,.10,.05);
    lampara();
    cube(1.5,3.5,5.0,1.1,1.7,.08,.55,.35,.20);cube(1.5,3.5,4.93,.85,1.35,.04,.50,.72,.82);
}

// ---------------- ESCRITORIO / PC / SILLA ----------------
void escritorio(){
    float x=-4.8,z=-3;
    cube(x,3.5,z,7,.45,2.8,.48,.23,.12);
    for(int i=-1;i<=1;i+=2) for(int j=-1;j<=1;j+=2) cube(x+i*2.8,1.7,z+j*.9,.35,3.2,.35,.25,.12,.06);
    cube(x-1.7,3,z+.15,2,.9,2.1,.38,.17,.08);
    // monitor
    cube(x,5,z+.35,4,2.6,.35,.12,.13,.15);cube(x,5,z+.15,3.55,2.15,.08,.05,.12,.22);
    cube(x,4,z+.25,.4,1.1,.4,.12,.13,.15);cube(x,3.45,z+.25,1.5,.18,.8,.12,.13,.15);
    cube(x+.3,3.85,z-.55,3.2,.12,.9,.55,.56,.60);sph(x+2.2,3.9,z-.55,.27,.10,.10,.11);
}
void silla(){
    float x=-4.8,z=.1;cube(x,2,z,2.6,.45,2.3,.10,.10,.12);cube(x,4.2,z+.8,2.6,4,.35,.12,.12,.15);
    cyl(x,.4,z,.25,1.7,.12,.12,.14);
    for(int i=0;i<5;i++){float a=i*72;cube(x+cos(R(a))*1.0,.25,z+sin(R(a))*1.0,1.4,.12,.18,.12,.12,.14);}
}

// ---------------- REPISA Y DECORACION ----------------
void repisa(){
    cube(-2.5,8.0,-9.35,12,.45,1.0,.56,.28,.14);
    for(int i=0;i<3;i++) cube(-7+i*3,7,-9.1,.3,2,.35,.30,.14,.07);
    cube(-7,9,-8.9,.6,1.6,.8,.20,.40,.65);cube(-6.3,9,-8.9,.5,1.6,.8,.70,.25,.20);cube(-5.7,9,-8.9,.4,1.6,.8,.25,.55,.30);
    cyl(-3.5,9,-8.9,.55,1.0,.10,.48,.42);for(int i=0;i<5;i++)sph(-3.5+cos(R(i*72))*.4,10.3,-8.9+sin(R(i*72))*.4,.25,.20,.58,.22);
    cube(-.5,9.5,-8.9,1.7,2,.15,.55,.30,.16);cube(-.5,9.5,-8.78,1.35,1.6,.06,.65,.80,.88);
    // pila de libros
    cube(2.5,9,-8.9,2.5,.5,.8,.18,.35,.65);cube(2.5,9.6,-8.9,2.5,.5,.8,.70,.25,.20);cube(2.5,10.2,-8.9,2.5,.5,.8,.25,.55,.30);
    // libros verticales
    cube(6.0,9.8,-8.9,.6,2.2,.8,.20,.40,.75);cube(6.8,9.8,-8.9,.55,2.2,.8,.20,.65,.30);cube(7.55,9.8,-8.9,.55,2.2,.8,.75,.25,.25);
    // maceta
    cyl(4.2,9,-8.9,.65,.9,.70,.40,.22);for(int i=0;i<6;i++)sph(4.2+cos(R(i*60))*.5,10.1,-8.9+sin(R(i*60))*.5,.38,.20,.55,.25);
}
void espejo(){cube(-11.55,7.2,1.5,.2,5,2.5,.48,.30,.15);cube(-11.42,7.2,1.5,.07,4.3,1.95,.70,.86,.92);}
void reloj(){
    glPushMatrix();glTranslatef(-7.2,9.0,-9.0);mat(.25,.18,.10);glutSolidTorus(.15,1.05,16,30);mat(.95,.93,.84);glutSolidSphere(.92,24,16);glPopMatrix();
    line(-7.2,9,-8.05,-7.2,9.55,-8.05,.12,.12,.12,3);line(-7.2,9,-8.05,-6.5,9.25,-8.05,.12,.12,.12,3);
}
void cuadros(){
    cube(8.0,7.2,-9.45,3.3,3.2,.15,.30,.20,.12);cube(8,7.2,-9.32,2.8,2.7,.07,.90,.80,.62);
    cube(-9,7.2,-9.45,3,3,.15,.30,.20,.12);cube(-9,7.2,-9.32,2.5,2.5,.07,.30,.55,.70);
    // estrellas/luna
    sph(8.2,9.5,-9.25,.55,.95,.75,.30);sph(8.4,9.7,-9.15,.48,.90,.90,.85);
}
void jardinera(){
    cube(8.7,5.8,-9.0,2.7,.8,1.2,.40,.22,.12);cube(8.7,6.25,-8.95,2.4,.18,1.0,.28,.16,.08);
    for(int i=0;i<5;i++)sph(8.7+(i-2)*.45,7,-9,.3,.20,.58,.22);
}
void guirnalda(){
    for(int i=0;i<9;i++){float x=-8+i*2;float y=9.3-.5*sin(i*.7);sph(x,y,-9.1,.12,.98,.72,.20);}
}

// ---------------- OBJETOS DEL PISO ----------------
void alfombra(){cube(0,.10,1.3,9,.12,5.4,.78,.35,.30);cube(0,.18,1.3,8.2,.04,4.6,.88,.55,.45);}
void tacho(){cyl(-8,.2,3,.65,1.5,.22,.22,.23);cyl(-8,1.7,3,.72,.1,.12,.12,.13);}
void pelota(){sph(-7,.9,6.7,.85,.95,.95,.92);for(int i=0;i<5;i++)sph(-7+cos(R(i*72))*.55,.9+sin(R(i*72))*.4,6.7+sin(R(i*72))*.55,.16,.08,.08,.08);}
void mochila(){cube(-5,1.4,6.8,2.4,2.8,1.2,.10,.24,.42);cube(-5,2.8,6.2,1.7,.4,.3,.85,.42,.32);}
void zapatillas(){sph(-8,.65,5.3,.65,.88,.88,.86);sph(-9,.65,5.0,.65,.82,.82,.80);}
void banco(){cube(-2,2,-6,5,.7,2.4,.48,.26,.15);for(int i=-1;i<=1;i+=2)cube(-2+i*1.7,.9,-6,.35,2,.35,.40,.20,.10);}
void patineta(){
    cube(-7,.65,-6,5,.22,.7,.35,.15,.20);
    for(int i=-1;i<=1;i+=2)cyl(-7+i*1.7,.2,-6,.35,.35,.12,.12,.12);
}
void tachoPequeno(){cyl(-9,.2,1.8,.7,1.6,.25,.32,.40);}

// ---------------- DETALLES DE CAMA ----------------
void peluche(){
    sph(10.5,3.7,4.0,1.8,.75,.50,.28);sph(10.5,6.1,4.0,1.45,.78,.54,.30);
    sph(9.4,7.25,4,.45,.65,.40,.20);sph(11.6,7.25,4,.45,.65,.40,.20);
    sph(10,6.2,2.9,.25,.08,.06,.05);sph(11,6.2,2.9,.25,.08,.06,.05);sph(10.5,5.7,2.9,.3,.92,.72,.55);
}
void lentes(){
    glDisable(GL_LIGHTING);glColor3f(.05,.05,.05);glLineWidth(3);glBegin(GL_LINE_LOOP);glVertex3f(9,2.55,3.7);glVertex3f(10.3,2.55,3.7);glVertex3f(10.3,2.55,4.5);glVertex3f(9,2.55,4.5);glEnd();glBegin(GL_LINE_LOOP);glVertex3f(10.6,2.55,3.7);glVertex3f(11.9,2.55,3.7);glVertex3f(11.9,2.55,4.5);glVertex3f(10.6,2.55,4.5);glEnd();glBegin(GL_LINES);glVertex3f(10.3,2.55,4.1);glVertex3f(10.6,2.55,4.1);glEnd();glEnable(GL_LIGHTING);
}
void celular(){cube(9.2,2.55,2.8,.7,.12,1.4,.04,.04,.05);cube(9.2,2.63,2.8,.55,.03,1.15,.10,.20,.35);}

// ---------------- ILUMINACION ----------------
void luces(){
    GLfloat p0[]={0,11,0,1},d0[]={1,.95,.82,1},a0[]={.28,.28,.28,1};glLightfv(GL_LIGHT0,GL_POSITION,p0);glLightfv(GL_LIGHT0,GL_DIFFUSE,d0);glLightfv(GL_LIGHT0,GL_AMBIENT,a0);
    GLfloat p1[]={7,6,4,1},d1[]={.55,.68,1,1};glLightfv(GL_LIGHT1,GL_POSITION,p1);glLightfv(GL_LIGHT1,GL_DIFFUSE,d1);
}
void escena(){
    piso();paredes();puerta();ventana();
    cama();mesaNoche();escritorio();silla();repisa();espejo();reloj();cuadros();jardinera();guirnalda();alfombra();
    tacho();pelota();mochila();zapatillas();banco();patineta();tachoPequeno();
    peluche();celular();lentes();
}

// ---------------- CAMARA ----------------
void camera(){glRotatef(-pitch,1,0,0);glRotatef(-yaw,0,1,0);glTranslatef(-camX,-camY,-camZ);}
void update(){float v=.18;float fx=sin(R(yaw)),fz=cos(R(yaw));if(key['w']||key['W']){camX+=fx*v;camZ+=fz*v;}if(key['s']||key['S']){camX-=fx*v;camZ-=fz*v;}if(key['a']||key['A']){camX+=cos(R(yaw))*v;camZ-=sin(R(yaw))*v;}if(key['d']||key['D']){camX-=cos(R(yaw))*v;camZ+=sin(R(yaw))*v;}if(key['q']||key['Q'])camY+=v;if(key['e']||key['E'])camY-=v;glutPostRedisplay();}

void display(){glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glMatrixMode(GL_MODELVIEW);glLoadIdentity();camera();luces();escena();glutSwapBuffers();}
void reshape(int w,int h){if(h==0)h=1;glViewport(0,0,w,h);glMatrixMode(GL_PROJECTION);glLoadIdentity();gluPerspective(60,(double)w/h,.1,1000);glMatrixMode(GL_MODELVIEW);}
void keyDown(unsigned char k,int,int){key[k]=true;if(k==27)exit(0);if(k=='r'||k=='R'){camX=0;camY=6;camZ=18;yaw=180;pitch=-8;}}
void keyUp(unsigned char k,int,int){key[k]=false;}
void special(int k,int,int){if(k==GLUT_KEY_LEFT)yaw-=3;if(k==GLUT_KEY_RIGHT)yaw+=3;if(k==GLUT_KEY_UP)pitch-=2;if(k==GLUT_KEY_DOWN)pitch+=2;if(pitch>80)pitch=80;if(pitch<-80)pitch=-80;glutPostRedisplay();}
void timer(int){update();glutTimerFunc(16,timer,0);}
void init(){glClearColor(.07,.09,.12,1);glEnable(GL_DEPTH_TEST);glDepthFunc(GL_LEQUAL);glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);glEnable(GL_LIGHT1);glEnable(GL_COLOR_MATERIAL);glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);glEnable(GL_NORMALIZE);glShadeModel(GL_SMOOTH);GLfloat a[]={.20,.20,.20,1};glLightModelfv(GL_LIGHT_MODEL_AMBIENT,a);}
int main(int argc,char**argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);glutInitWindowSize(1280,720);glutCreateWindow("HABITACION 3D - FREEGLUT");init();glutDisplayFunc(display);glutReshapeFunc(reshape);glutKeyboardFunc(keyDown);glutKeyboardUpFunc(keyUp);glutSpecialFunc(special);glutTimerFunc(16,timer,0);glutMainLoop();return 0;}
