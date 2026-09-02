#include <windows.h>
#include <GL/freeglut.h>
#include <Math.h>
#define PI 3.14159265f
//GLfloat ballRadius = 10.0f;
//GLfloat ballX = 0.0f;
//GLfloat ballY = 0.0f;
void initGL(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//x -x -y y
gluOrtho2D(-100,100,-100,100);
glMatrixMode(GL_MODELVIEW);
}
void reshape(GLsizei w, GLsizei h){
GLfloat Aspect1, Aspect2;
Aspect1=(GLfloat)h/(GLfloat)w;
Aspect2=(GLfloat)w/(GLfloat)h;
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h){
gluOrtho2D(-100,100,-100*Aspect1, 100*Aspect1);
}
else{
gluOrtho2D(-50*Aspect2, 50*Aspect2,-100,100);
}
glMatrixMode(GL_MODELVIEW);
}
//Declaracion de Funciones
//EJES
void ejes(void);
//PARED FRONTAL
void pared_frontal(void);
void cortina (float, float);
void ventana (float);
void sombra_triangular_ventana(void);
void cuadro(void);
void puerta(float); // Recibe un paramero para determinar la opacidad
void salida(void);
void sombra_banco(void);
void banco(float);
//PARED FONDO
void pared_fondo(void);
void panel1(void);
void panel2(void);
void grifo(GLfloat, GLfloat);
void dispensador_agua(void);
//PARED CENTRO
void pared_central(void);
void foco(void);
void ascensor(float);
void bidon_agua(void);
void maceta(void);
//SOMBRAS
void figura_sombra_triangulo_frontal(void);
void figura_sombra_cuadrilatero_fondo(void);
void figura_sombra_cuadrilatero_central(void);
void display(){
//----
glClear (GL_COLOR_BUFFER_BIT);
//EJES
// glPushMatrix(); ejes(); glPopMatrix();
//PARED FRONTAL--
pared_frontal();
glPushMatrix(); glRotatef (180.0f, 0.0f, 1.0f, 0.0f); pared_frontal(); glPopMatrix();
//PANEL SALIDA
salida();
glPushMatrix(); glTranslatef (146.0f, 0.0f, 0.0f); salida(); glPopMatrix();
//SOMBRA TRIANGULO PARED FRONTAL
figura_sombra_triangulo_frontal();
glPushMatrix(); glRotatef (180.0f, 0.0f, 1.0f, 0.0f); figura_sombra_triangulo_frontal(); glPopMatrix();
//VENTANA
ventana(1.0f);
//SOMBRA
sombra_triangular_ventana();
//PUERTA
puerta(1.0f);
//VENTANA TRANSLATE
glPushMatrix(); glRotatef (180, 0.0f, 1.0f, 0.0f); glTranslatef (32.0f, 0.0f, 0.0f); ventana (1.0f); glPopMatrix();
//SOMBRA VENTANA TRANSLATE
glPushMatrix(); glTranslatef (145.0f, 0.0f, 0.0f); sombra_triangular_ventana(); glPopMatrix();
//PUERTA TRANSLATE
glPushMatrix(); glTranslatef (145.0f, 0.0f, 0.0f); puerta (1.0f); glPopMatrix();
//CUADRO
cuadro();
//CUADRO TRANSLATE
glPushMatrix(); glRotatef (180, 0.0f, 1.0f, 0.0f); glTranslatef(-44.0f, 20.0f, 0.0f); cuadro(); glPopMatrix();
//PUERTAS INVERTIDAS CON OPACIDAD 0.2f
glPushMatrix(); glRotatef (180, 1.0f, 0.0f, 0.0f); glTranslatef(0.0f, 136.0f, 0.0f); puerta (0.2);
glTranslatef(145.0f, 0.0f, 0.0f); puerta(0.2); glPopMatrix();
//PARED FONDO
pared_fondo();
glPushMatrix(); glRotatef (180.0f, 0.0f, 1.0f, 0.0f); pared_fondo(); glPopMatrix();
//PANELES PARED CENTRAL
panel1();
panel2();
//SOMBRA CUADRIALTERO FONDO
figura_sombra_cuadrilatero_fondo();
glPushMatrix(); glRotatef (180.0f, 0.0f, 1.0f, 0.0f); figura_sombra_cuadrilatero_fondo(); glPopMatrix();
//PARED CENTRAL-
glPushMatrix(); pared_central(); glPopMatrix();
//ASCENSOR
ascensor(1.0f);
//ASCENSOR INVERTIDO
glPushMatrix(); glRotatef (180.0, 1.0, 0.0, 0.0); glTranslatef (0.0f, 130.0f, 0.0f); ascensor(0.3f); glPopMatrix();
//SOMBRA CUADRILATERO CENTRAL
glPushMatrix(); figura_sombra_cuadrilatero_central(); glPopMatrix();
//FOCO 1
foco();
//FOCO 2
glPushMatrix(); glScalef(0.52f, 0.52f, 0.0f); glTranslatef (0.0f, 50.0f, 0.0f); foco(); glPopMatrix();
//MACETA
glPushMatrix(); glTranslatef(-8.0f,-28.0f, 0.0f); glScaled (0.6f,0.6f,0.0f); maceta(); glPopMatrix();
//BANCO
sombra_banco();
banco(1.0f);
//BANCO INVERTIDO
glPushMatrix(); glRotatef (180.0, 0.0, 1.0, 0.0); glTranslatef (30.0f, 0.0f, 0.0f); sombra_banco(); banco (1.0f); glPopMatrix();
//BANCO REFLEJO
glPushMatrix(); glRotatef (180.0, 1.0, 0.0, 0.0); glTranslatef (0.0f, 137.0f, 0.0f); banco(0.3f); glPopMatrix();
glPushMatrix(); glRotatef (180.0, 0.0, 1.0, 0.0); glRotatef (180.0, 1.0, 0.0, 0.0); glTranslatef (30.0f, 137.0f, 0.0f); banco (0.3f); glPopMatrix();
//DISPENSADOR DE AGUA
glPushMatrix(); glTranslatef(0.0f, -3.0f, 0.0f); dispensador_agua(); glPopMatrix();
//RENDERIZADO
glFlush ();
glutSwapBuffers ();
}
int main(int argc, char** argv) {
//Inicializar el gestor de ventanas GLUT y crear la ventana
glutInit(&argc, argv);
glutInitWindowSize(1200,600);
glutInitWindowPosition (100,80);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutCreateWindow("Pasillo");
//initGL ();
glutReshapeFunc (reshape);
glutDisplayFunc (display);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_BLEND);
glutMainLoop ();
return 0;
}
//EJES
void ejes(){
glBegin(GL_LINES);
//eje x
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (0.0f, 0.0f);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (-100.0f, 0.0f);
glEnd ();
glBegin(GL_LINES);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (0.0f, 0.0f);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (100.0f, 0.0f);
glEnd ();
//eje y
glBegin(GL_LINES);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (0.0f, 0.0f);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (0.0f, 100.0f);
glEnd ();
//eje -y
glBegin(GL_LINES);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (0.0f, 0.0f);
glColor3f(1.0f, 0.5f, 0.0f); glVertex2f (0.0f,-100.0f);
glEnd ();
}
//PARED FRONTAL
void pared_frontal(){
//TECHO FRONTAL
glBegin(GL_QUADS);
glColor4f(0.6039f, 0.5333f, 0.8235f, 1.0000f);
glVertex2f (-100.0f, 100.0f); //A
glColor4f(0.4549f, 0.4078f, 0.7412f, 1.0000f);
glVertex2f (-45.0f, 100.0f);//B
glColor4f(0.4549f, 0.4078f, 0.7412f, 1.0000f);
glVertex2f (-45.0f, -68.0f);//C
glColor4f(0.6039f, 0.5333f, 0.8235f, 1.0000f);
glVertex2f (-100.0f, -68.0f);//D
glEnd();
//PARED FRONTAL
glBegin(GL_QUADS);
glColor3f(0.8627f, 0.8353f, 0.9412f);
glVertex2f (-100.0f, 68.0f); //A
glVertex2f (-45.0f, 68.0f);//B
glVertex2f (-45.0f, -68.0f);//C
glVertex2f (-100.0f, -68.0f);//D
glEnd();
//PISO
glBegin(GL_QUADS);
glColor4f(0.5922f, 0.5647f, 0.7647f, 1.0000f);
glVertex2f (-100.0f, -68.0f);//D
glVertex2f (-45.0f, -68.0f);//C
glVertex2f (-45.0f, -100.0f);//C
glVertex2f (-100.0f, -100.0f);//D
glEnd();
//LOCETA SUPERIOR PARED
glColor4f(0.7098f, 0.6549f, 0.9922f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(-100.0f, -45.0f);
glVertex2f(-45.0f, -45.0f);
glVertex2f(-45.0f, -63.0f);
glVertex2f(-100.0f, -63.0f);
glEnd();
//LOCETA INFERIOR PARED
glBegin(GL_POLYGON);
glColor4f(0.9294f, 0.9333f, 1.0000f, 1.0000f);
glVertex2f(-100.0f, -63.0f);
glVertex2f(-45.0f, -63.0f);
glVertex2f (-45.0f, -68.0f);//C
glVertex2f (-100.0f, -68.0f);//D
glEnd();
//LINEA ABAJO DE LOCETA
glColor4f(0.8314f, 0.8118f, 0.9804f, 1.0000f);
glLineWidth(2.0);
glBegin(GL_LINES);
glVertex2f(-100.0f, -68.0f);
glVertex2f(-45.0f, -68.0f);
glEnd();
}
void cortina (float x, float y){
glColor4f(0.9882f, 0.9686f, 0.9686f, 0.4000f);
glBegin(GL_QUADS);
glVertex2f (x+6.0f, y-2.5f);
glVertex2f (x+8.0f, y -6.5f);
glVertex2f (x+8.0f, y - 38.0f);
glVertex2f (x+6.0f, y - 38.0f);
glEnd();
}
void ventana (float x){
float inicioX =-99.0f;
float inicioY =35.0;
//BORDES VENTANA
glColor4f(0.9804f, 0.9804f, 0.9804f,x);
glBegin(GL_QUADS);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 21.0f, inicioY);
glVertex2f(inicioX + 21.0f, inicioY - 40.0f);
glVertex2f(inicioX, inicioY - 40.0f);
glEnd();
//FONDO VENTANA
glColor4f(0.3569f, 0.5255f, 0.8431f, 0.7000f);
glBegin(GL_QUADS);
glVertex2f(inicioX + 1.0f, inicioY -2.3f);
glVertex2f(inicioX + 20.0f, inicioY - 2.3f);
glVertex2f(inicioX + 20.0f, inicioY - 38.0f);
glVertex2f(inicioX + 1.0f, inicioY - 38.0f);
glEnd();
//CORTINAS
cortina(inicioX, inicioY);
glPushMatrix(); glTranslatef (3.0f, 0.0f, 0.0f); cortina (inicioX, inicioY); glPopMatrix();
glPushMatrix(); glTranslatef (6.0f, 0.0f, 0.0f); cortina (inicioX, inicioY); glPopMatrix();
glPushMatrix(); glTranslatef (8.0f, 0.0f, 0.0f); cortina (inicioX, inicioY); glPopMatrix();
glPushMatrix(); glTranslatef (10.0f, 0.0f, 0.0f); cortina (inicioX, inicioY); glPopMatrix();
glPushMatrix(); glTranslatef (12.0f, 0.0f, 0.0f); cortina (inicioX, inicioY); glPopMatrix();
}
void sombra_triangular_ventana(){
float inicioX =-99.0f;
float inicioY =35.0;
//SOMBRA
glColor4f(0.2000f, 0.2000f, 0.2000f, 0.0600f);
glBegin(GL_TRIANGLES);
glVertex2f(inicioX + 1.0f, inicioY -2.3f);
glVertex2f(inicioX + 20.0f, inicioY - 38.0f);
glVertex2f(inicioX + 1.0f, inicioY - 38.0f);
glEnd();
}
//SOMBRA BANCO
void sombra_banco(){
float inicioX =-98.0f;
float inicioY =-40.0;
glColor4f(0.0000f, 0.0000f, 0.0000f, 0.2f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 8.0f, inicioY - 3.0f);
glVertex2f(inicioX + 21.5f, inicioY - 3.0f);
glVertex2f(inicioX + 21.5f, inicioY - 23.0f);
glVertex2f(inicioX + 20.0f, inicioY - 28.0f);
glVertex2f(inicioX + 4.0f, inicioY - 28.0f);
glEnd();
}
//BANCO
void banco(float x){
float inicioX =-98.0f;
float inicioY =-40.0;
glColor4f(0.9660f, 0.6470f, 0.3098f,x);
glBegin(GL_QUADS);
glVertex2f(inicioX +3.0f, inicioY);
glVertex2f(inicioX + 20.1f, inicioY);
glVertex2f(inicioX + 19.6f, inicioY - 15.0f);
glVertex2f(inicioX + 2.5f, inicioY - 15.0f);
glEnd();
//LATERAL
glColor4f(0.6313f, 0.1764f, 0.3686f,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 20.0f, inicioY);
glVertex2f(inicioX + 20.5f, inicioY - 1.0f);
glVertex2f(inicioX + 20.0f, inicioY - 18.0f);
glVertex2f(inicioX + 19.5f, inicioY - 18.0f);
glEnd();
//--
glColor4f(0.6313f, 0.1764f, 0.3686f,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 20.0f, inicioY - 18.0f);
glVertex2f(inicioX + 16.0f, inicioY - 18.0f);
glVertex2f(inicioX + 16.0f, inicioY - 15.5f);
glVertex2f(inicioX + 20.2f, inicioY - 15.0f);
glEnd();
//--frontal
//0
glColor4f(0.9960f, 0.9725f, 0.4549f,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 19.5f, inicioY - 15.0f);
glVertex2f(inicioX + 18.0f, inicioY - 15.5f);
glVertex2f(inicioX - 1.8f, inicioY - 15.5f);
glVertex2f(inicioX - 1.8f, inicioY - 15.0f);
glEnd();
//1
glColor4f(0.9660f, 0.6470f, 0.3098f,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 16.0f, inicioY - 18.0f);
glVertex2f(inicioX + 16.0f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 18.0f);
glEnd();
//2
glColor4f(0.9660f, 0.6470f, 0.3098f,x);
glPushMatrix(); glTranslatef(-6.0f,0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(inicioX + 16.0f, inicioY - 18.0f);
glVertex2f(inicioX + 16.0f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 18.0f);
glEnd();
glPopMatrix();
//3
glColor4f(0.9660f, 0.6470f, 0.3098f,x);
glPushMatrix(); glTranslatef(-12.0f,0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(inicioX + 16.0f, inicioY - 18.0f);
glVertex2f(inicioX + 16.0f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 18.0f);
glEnd();
glPopMatrix();
//Base negra
glColor4f(0.1882f, 0.0823f, 0.2196,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 20.0f, inicioY - 18.0f);
glVertex2f(inicioX + 20.0f, inicioY - 19.5f);
glVertex2f(inicioX - 2.0f, inicioY - 19.5f);
glVertex2f(inicioX - 2.0f, inicioY - 18.0f);
glEnd();
//Patas
glColor4f(0.1882f, 0.0823f, 0.2196,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 1.2f, inicioY - 19.5f);
glVertex2f(inicioX + 2.7f, inicioY - 19.5f);
glVertex2f(inicioX + 2.0f, inicioY - 27.5f);
glVertex2f(inicioX + 1.5f, inicioY - 27.5f);
glEnd();
//--
glColor4f(0.1882f, 0.0823f, 0.2196,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 1.0f, inicioY - 27.5f);
glVertex2f(inicioX + 2.5f, inicioY - 27.5f);
glVertex2f(inicioX + 2.9f, inicioY - 28.5f);
glVertex2f(inicioX + 0.6f, inicioY - 28.5f);
glEnd();
//--
glColor4f(0.1882f, 0.0823f, 0.2196,x);
glPushMatrix(); glTranslatef(+15.6f,0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(inicioX + 1.2f, inicioY - 19.5f);
glVertex2f(inicioX + 2.7f, inicioY - 19.5f);
glVertex2f(inicioX + 2.0f, inicioY - 27.5f);
glVertex2f(inicioX + 1.5f, inicioY - 27.5f);
glEnd();
glBegin(GL_QUADS);
glVertex2f(inicioX + 1.0f, inicioY - 27.5f);
glVertex2f(inicioX + 2.5f, inicioY - 27.5f);
glVertex2f(inicioX + 2.9f, inicioY - 28.5f);
glVertex2f(inicioX + 0.6f, inicioY - 28.5f);
glEnd();
glPopMatrix();
//sombras-parte baja
glColor4f(1.0000f, 0.5490f, 0.2117,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 10.2f, inicioY - 15.5f);
glVertex2f(inicioX + 10.5f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 18.0f);
glVertex2f(inicioX + 10.2f, inicioY - 18.0f);
glEnd();
//--
glColor4f(1.0000f, 0.5490f, 0.2117,x);
glPushMatrix(); glTranslatef(-6.0f,0.0f, 0.0f);
glBegin(GL_TRIANGLES);
glVertex2f(inicioX + 10.2f, inicioY - 15.5f);
glVertex2f(inicioX + 10.5f, inicioY - 15.5f);
glVertex2f(inicioX + 10.0f, inicioY - 18.0f);
glVertex2f(inicioX + 10.2f, inicioY - 18.0f);
glEnd();
glPopMatrix();
//sombras-espaldar
glColor4f(0.8941f, 0.4745f, 0.1882,x);
glBegin(GL_QUADS);
glVertex2f(inicioX + 8.0f, inicioY);
glVertex2f(inicioX + 7.5f, inicioY - 15.0f);
glVertex2f(inicioX + 7.7f, inicioY - 15.0f);
glVertex2f(inicioX + 8.4f, inicioY);
glEnd();
//--
glColor4f(0.8941f, 0.4745f, 0.1882,x);
glPushMatrix(); glTranslatef (+6.0f,0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(inicioX + 8.0f, inicioY);
glVertex2f(inicioX + 7.5f, inicioY - 15.0f);
glVertex2f(inicioX + 7.7f, inicioY - 15.0f);
glVertex2f(inicioX + 8.4f, inicioY);
glEnd();
glPopMatrix();
}
void cuadro(){
float inicioX = -55.0f;
float inicioY =18.0;
//SOMBRA CUADRO
glBegin(GL_POLYGON);
glColor4f(0.6549f, 0.5882f, 0.8039f, 1.0000f);
glVertex2f(inicioX + 1, inicioY -1);
glVertex2f(inicioX + 9.0f, inicioY -1);
glVertex2f(inicioX + 9.0f, inicioY -46.5f);
glVertex2f(inicioX +1, inicioY -46.5f);
glEnd();
//BORDES CUADRO
glBegin(GL_POLYGON);
glColor4f(0.9922f, 0.5059f, 0.1294f, 1.0000f);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 8.5f, inicioY);
glVertex2f(inicioX + 8.5f, inicioY -45.0f);
glVertex2f(inicioX, inicioY -45.0f);
glEnd();
//HOJA BLANCA
glBegin(GL_POLYGON);
glColor4f(0.9843f, 0.9882f, 1.0000f, 1.0000f);
glVertex2f(inicioX + 0.5f, inicioY - 1.0f);
glVertex2f(inicioX + 8.0f, inicioY - 1.0f);
glColor4f(0.8980f, 0.9059f, 0.9961f, 1.0000f);
glVertex2f(inicioX + 8.0f, inicioY -44.0f);
glVertex2f(inicioX + 0.5f, inicioY -44.0f);
glEnd();
//LINEA SUPERIOR HOJA
glColor4f(0.8157f, 0.7412f, 0.8510f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 0.5f, inicioY - 1.0f);
glVertex2f(inicioX + 8.0f, inicioY - 1.0f);
glVertex2f(inicioX + 8.0f, inicioY - 3.5f);
glVertex2f(inicioX + 0.5f, inicioY -3.5f);
glEnd();
//LINEAS HOJA
glColor4f(0.7765f, 0.7451f, 0.9059f, 1.0000f);
glLineWidth(6.0);
glBegin(GL_LINES);
glVertex2f(inicioX + 2.5f, inicioY - 13.0f);
glVertex2f(inicioX + 6.0f, inicioY - 13.0f);
glEnd();
glLineWidth(2.0);
glBegin(GL_LINES);
glVertex2f(inicioX + 1.5f, inicioY - 19.0f);
glVertex2f(inicioX + 7.0f, inicioY - 19.0f);
glEnd();
glLineWidth(2.0);
glBegin(GL_LINES);
glVertex2f(inicioX + 2.5f, inicioY - 21.0f);
glVertex2f(inicioX + 6.0f, inicioY - 21.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX + 2.5f, inicioY - 23.0f);
glVertex2f(inicioX + 6.0f, inicioY - 23.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX + 1.5f, inicioY - 25.0f);
glVertex2f(inicioX + 7.0f, inicioY - 25.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX + 2.5f, inicioY - 27.0f);
glVertex2f(inicioX + 6.0f, inicioY - 27.0f);
glEnd();
glLineWidth(4.0);
glBegin(GL_LINES);
glVertex2f(inicioX + 1.5f, inicioY - 41.0f);
glVertex2f(inicioX + 4.0f, inicioY - 41.0f);
glEnd();
}
void puerta(float x){
float inicioX = -76.0f;
float inicioY =27.0;
//BORDE BLANCO PUERTA
glColor4f(0.9804f, 0.9804f, 0.9804f,x);
glBegin(GL_POLYGON);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 20.0f, inicioY);
glVertex2f(inicioX + 20.0f, inicioY - 95.0f);
glVertex2f(inicioX, inicioY - 95.0f);
glEnd();
//RELLENO PUERTA
glColor4f(0.4000f, 0.3725f, 0.8745f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 1.5f, inicioY -3.5f);
glVertex2f(inicioX + 18.50f, inicioY -3.5f);
glVertex2f(inicioX + 18.5f, inicioY -95.0f);
glVertex2f(inicioX +1.5f, inicioY -95.0f);
glEnd();
//SOMBRA SUPERIOR PUERTA
glColor4f(0.0000f, 0.0000f, 0.0000f, 0.3f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 1.5f, inicioY -3.5f);
glVertex2f(inicioX + 18.50f, inicioY -3.5f);
glVertex2f(inicioX + 18.5f, inicioY -6.5f);
glVertex2f(inicioX +1.5f, inicioY -6.5f);
glEnd();
//PARTE METALIZADA PUERTA
glColor4f(0.8549f, 0.8549f, 0.8863f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 13.5f, inicioY -25.5f);
glVertex2f(inicioX + 17.0f, inicioY -25.5f);
glVertex2f(inicioX + 17.0f, inicioY -65.0f);
glVertex2f(inicioX + 13.5f, inicioY -65.0f);
glEnd();
//SOMBRA PARTE METALIZADA PUERTA
glColor4f(0.1294f, 0.1294f, 0.1294f, 0.4f);
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2f(inicioX + 13.5f, inicioY -25.5f);
glVertex2f(inicioX + 13.5f, inicioY -65.0f);
glEnd();
//FIGURA PUERTA CENTRO
glColor4f(0.8039f, 0.7843f, 0.9569f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 7.5f, inicioY -9.5f);
glVertex2f(inicioX + 13.0f, inicioY -9.5f);
glVertex2f(inicioX + 13.0f, inicioY -19.0f);
glVertex2f(inicioX + 7.5f, inicioY -19.0f);
glEnd();
//SOMBRA MANIJA PUERTA
glColor4f(0.1098f, 0.1098f, 0.1098f, 0.3f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 3.0f, inicioY -40.5f);
glVertex2f(inicioX + 4.8f, inicioY -40.5f);
glVertex2f(inicioX + 4.8f, inicioY -58.0f);
glVertex2f(inicioX + 3.0f, inicioY -58.0f);
glEnd();
//MANIJA PUERTA
glColor4f(0.7137f, 0.6863f, 0.6863f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 2.5f, inicioY -39.5f);
glVertex2f(inicioX + 4.3f, inicioY -39.5f);
glVertex2f(inicioX + 4.3f, inicioY -57.0f);
glVertex2f(inicioX + 2.5f, inicioY -57.0f);
glEnd();
//PUERTA SOMBRA INFERIOR
glColor4f(0.3059f, 0.2824f, 0.7765f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 18.5f, inicioY -95.0f);
glVertex2f(inicioX +1.5f, inicioY -95.0f);
glVertex2f(inicioX +1.5f, inicioY -88.0f);
glVertex2f(inicioX + 18.5f, inicioY -86.0f);
glEnd();
}
void salida(){
float inicioX = -57.0f;
float inicioY = 62.0;
//COLOR LETRERO SALIDA
glColor4f(0.4902f, 0.5216f, 0.9922f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX - 2.0f, inicioY);
glVertex2f(inicioX + 10.0f, inicioY);
glVertex2f(inicioX + 10.0f, inicioY -16.5f);
glVertex2f(inicioX - 2.0f, inicioY -16.5f);
glEnd();
//COLOR FLECHA Y RAYAS LETRERO SALIDA
glColor4f(0.9020f, 0.9020f, 0.9020f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 5.0, inicioY - 5.0f);
glVertex2f(inicioX + 7.0f, inicioY -5.0f);
glVertex2f(inicioX + 7.0f, inicioY -10.5f);
glVertex2f(inicioX + 5.0f, inicioY -10.5f);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2f(inicioX + 7.0, inicioY - 3.0f);
glVertex2f(inicioX + 9.0f, inicioY -8.0f);
glVertex2f(inicioX + 7.0f, inicioY -12.5f);
glEnd();
glLineWidth(3.0);
glBegin(GL_LINES);
glVertex2f(inicioX -1.0f, inicioY - 5.0f);
glVertex2f(inicioX + 4.0f, inicioY -5.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX -1.0f, inicioY - 7.0f);
glVertex2f(inicioX + 1.0f, inicioY -7.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX +1.4f, inicioY - 7.0f);
glVertex2f(inicioX + 4.0f, inicioY -7.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX -1.0f, inicioY - 9.0f);
glVertex2f(inicioX + 4.0f, inicioY -9.0f);
glEnd();
glBegin(GL_LINES);
glVertex2f(inicioX -1.0f, inicioY - 11.0f);
glVertex2f(inicioX + 4.0f, inicioY -11.0f);
glEnd();
}
//PARED FONDO
void pared_fondo(){
//LATERALES FONDO SUPERIOR
glBegin(GL_QUADS);
glColor4f(0.4549f, 0.4078f, 0.7412f, 1.0000f);
glVertex2f (-45.0f, 100.0f); //B
glVertex2f (-25.0f, 100.0f);//E
glVertex2f (-25.0f, -65.0f);//F
glVertex2f (-45.0f, -68.0f);//C
glEnd();
//LATERALES FONDO INTERMEDIOS
glBegin(GL_QUADS);
glColor4f(0.6588f, 0.6157f, 0.8824f, 1.0000f);
glVertex2f (-45.0f, 68.0f); //B
glVertex2f (-25.0f, 51.0f);//E
glVertex2f (-25.0f, -65.0f);//F
glVertex2f (-45.0f, -68.0f);//C
glEnd();
//LATERALES FONDO INFERIORES
glBegin(GL_QUADS);
glColor4f(0.5922f, 0.5647f, 0.7647f, 1.0000f);
glVertex2f (-45.0f, -68.0f);//C
glVertex2f (-25.0f, -65.0f);//F
glVertex2f (-25.0f, -100.0f);//F
glVertex2f (-45.0f, -100.0f);//C
glEnd();
//LOCETA INFERIOR FONDO
glColor4f(0.9294f, 0.9333f, 1.0000f, 1.0000f);
glBegin(GL_QUADS);
glVertex2f(-45.0f, -63.0f);
glVertex2f(-25.0f, -63.0f);
glVertex2f(-25.0f, -65.0f);
glVertex2f (-45.0f, -68.0f);
glEnd();
//LOCETA SUPERIOR FONDO
glColor4f(0.5529f, 0.4902f, 0.9765f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(-45.0f, -45.0f);
glVertex2f(-25.0f, -50.0f);
glVertex2f(-25.0f, -63.0f);
glVertex2f(-45.0f, -63.0f);
glEnd();
}
void panel1(){
float inicioX = -41.0f;
float inicioY = 32.0;
//PARTE INFERIOR PANEL
glColor4f(0.8000f, 0.8039f, 0.9765f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 1, inicioY -1);
glVertex2f(inicioX + 12.0f, inicioY -9);
glVertex2f(inicioX + 12.0f, inicioY -52.5f);
glVertex2f(inicioX +1, inicioY -46.5f);
glEnd();
//PARTE SUPERIOR PANEL
glColor4f(0.7098f, 0.7255f, 0.9725f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 1, inicioY -1);
glVertex2f(inicioX + 12.0f, inicioY -9);
glVertex2f(inicioX + 12.0f, inicioY -17.5f);
glVertex2f(inicioX +1, inicioY -10.5f);
glEnd();
}
void panel2(){
float inicioX = 35.0f;
float inicioY = 47.0;
//PARTE INFERIOR PANEL
glColor4f(0.8039f, 0.8000f, 0.9647f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 8.0f, inicioY +9);
glVertex2f(inicioX + 8.0f, inicioY -37.5f);
glVertex2f(inicioX, inicioY -46.5f);
glEnd();
//PARTE SUPERIOR PANEL
glColor4f(0.7176f, 0.7255f, 0.9569f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 8.0f, inicioY +9);
glVertex2f(inicioX + 8.0f, inicioY -0.0f);
glVertex2f(inicioX, inicioY -9.0f);
glEnd();
//PARTE INFERIOR CENTRAL PANEL
glColor4f(0.7176f, 0.7255f, 0.9569f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 0.5f, inicioY-13.0f);
glVertex2f(inicioX + 7.5f, inicioY -5.0f);
glVertex2f(inicioX + 7.5f, inicioY -20.0f);
glVertex2f(inicioX + 0.5f, inicioY -28.0f);
glEnd();
}
//PARED CENTRAL
void pared_central(){
//PARED CENTRAL SUPERIOR
glColor4f(0.4549f, 0.4078f, 0.7412f, 1.0000f);
glBegin(GL_QUADS);
glVertex2f (-25.0f, 100.0f); //E
glVertex2f (25.0f, 100.0f);//G
glVertex2f (25.0f, -65.0f);//H
glVertex2f (-25.0f, -65.0f);//F
glEnd();
//PARED CENTRAL
glColor3f(0.8549f, 0.8118f, 0.9804f);
glBegin(GL_QUADS);
glVertex2f (-25.0f, 51.0f); //E
glVertex2f (25.0f, 51.0f);//G
glVertex2f (25.0f, -65.0f);//H
glVertex2f (-25.0f, -65.0f);//F
glEnd();
//PARED CENTRAL INFERIOR
glColor4f(0.5922f, 0.5647f, 0.7647f, 1.0000f);
glBegin(GL_QUADS);
glVertex2f (-25.0f, -65.0f);//F
glVertex2f (25.0f, -65.0f);//H
glVertex2f (25.0f, -100.0f);//H
glVertex2f (-25.0f, -100.0f);//H
glEnd();
//LOCETA INFERIOR PARED CENTRAL
glColor4f(0.9294f, 0.9333f, 1.0000f, 1.0000f);
glBegin(GL_QUADS);
glVertex2f(-25.0f, -63.0f);
glVertex2f (25.0f, -63.0f);//G
glVertex2f (25.0f, -65.0f);//H
glVertex2f(-25.0f, -65.0f);
glEnd();
//LOCETA SUPERIOR PARED CENTRAL
glColor4f(0.6275f, 0.5647f, 0.9843f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(-25.0f, -50.0f);
glVertex2f (25.0f, -50.0f);//G
glVertex2f (25.0f, -63.0f);//H
glVertex2f(-25.0f, -63.0f);
glEnd();
}
void foco(){
//COLGANTES
glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-19.8f,87.5f);
glVertex2f(-19.8f,81.5f);
glVertex2f(-19.3f,81.5f);
glVertex2f(-19.3f,87.5f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(19.3f,87.5f);
glVertex2f(19.3f,81.5f);
glVertex2f(19.8f,81.5f);
glVertex2f(19.8f,87.5f);
glEnd();
//PARTE NEGRA
glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-26.0f,81.5f);
glVertex2f(-26.0f,80.0f);
glVertex2f(26.0f,80.0f);
glVertex2f(26.0f,81.5f);
glEnd();
//FOCO
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-26.0f,80.0f);
glVertex2f(-22.0f,76.0f);
glVertex2f(22.0f,76.0f);
glVertex2f(26.0f, 80.0f);
glEnd();
}
void ascensor(float x){
float inicioX = -13.0f;
float inicioY = 10.0;
//LATERALES ASCENSOR
glColor4f(0.4745f, 0.4902f, 0.8471f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 26.0f, inicioY);
glVertex2f(inicioX + 26.0f, inicioY -75.0f);
glVertex2f(inicioX, inicioY-75.0f);
glEnd();
//SUPERIOR ASCENSOR
glColor4f(0.2667f, 0.2627f, 0.6196f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 26.0f, inicioY);
glVertex2f(inicioX + 24.5f, inicioY -3.8f);
glVertex2f(inicioX+ 1.5f, inicioY -3.8f);
glEnd();
//LUMINOSIDAD CUADRILATEROS INTERNOS ASCENSOR
glColor4f(0.7451f, 0.6941f, 0.8000f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX+ 1.5f, inicioY -3.8f);
glVertex2f(inicioX + 24.5f, inicioY -3.8f);
glVertex2f(inicioX + 24.5f, inicioY -75.0f);
glVertex2f(inicioX + 1.5f, inicioY -75.0f);
glEnd();
glColor3f(0.6627f, 0.6078f, 0.7451f);
glLineWidth(0.0);
glBegin(GL_LINE_LOOP);
//
//
//
//
glVertex2f(inicioX+ 1.5f, inicioY -3.8f);
//
glVertex2f(inicioX + 1.5f, inicioY -75.0f);
//
glVertex2f(inicioX + 24.5f, inicioY -75.0f);
//
glVertex2f(inicioX + 24.5f, inicioY -3.8f);
//
glVertex2f(inicioX + 21.5f, inicioY -43.8f);
//
glVertex2f(0, inicioY -43.8f);
//
//
//
glVertex2f(0, inicioY -40.8f);
glVertex2f(inicioX+ 4.5f, inicioY -38.8f);
glEnd();
//ASCENSOR CUADRILATEROS Y TRIANGULOS INTERNOS SIN LUMINOSIDAD
glColor4f(0.6627f, 0.6078f, 0.7451f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX+ 1.5f, inicioY -38.8f);
glVertex2f(0, inicioY -40.8f);
glVertex2f(0, inicioY -75.0f);
glVertex2f(inicioX + 1.5f, inicioY -75.0f);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(0, inicioY -44.8f);
glVertex2f(inicioX + 24.5f, inicioY -44.8f);
glVertex2f(inicioX + 24.5f, inicioY -75.0f);
glVertex2f(0, inicioY -75.0f);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2f(inicioX+ 1.5f, inicioY -3.8f);
glVertex2f(inicioX + 5.5f, inicioY -40.8f);
glVertex2f(inicioX+ 1.5f, inicioY -38.8f);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2f(inicioX + 24.5f, inicioY -3.8f);
glVertex2f(inicioX + 20.0f, inicioY -44.8f);
glVertex2f(inicioX + 24.5f, inicioY-44.8f);
glEnd();
//CUADRILATERO ICONO ASCENSOR
glColor4f(0.1765f, 0.0745f, 0.2196f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 9.5f, inicioY + 12.8f);
glVertex2f(inicioX + 15.5f, inicioY + 12.8f);
glVertex2f(inicioX+ 15.5f, inicioY + 2.8f);
glVertex2f(inicioX+9.5f, inicioY + 2.8f);
glEnd();
//TRIANGULO ICONO ASCENSOR
glPushMatrix();
glScalef(0.5f, 0.5f, 0.0f);
glTranslatef(-0.5f, 18.5f, 0.0f);
glColor4f(0.0000f, 0.7843f, 0.8706f, x);
glBegin(GL_TRIANGLES);
glVertex2f(inicioX + 12.5f, inicioY + 12.8f);
glVertex2f(inicioX+ 15.5f, inicioY + 2.8f);
glVertex2f(inicioX+9.5f, inicioY + 2.8f);
glEnd();
glPopMatrix();
//LINEA INTERMEDIA ASCENSOR
glColor4f(0.7137f, 0.6039f, 0.7294f, x);
glBegin(GL_LINES);
glVertex2f(0, inicioY -3.8f);
glVertex2f(0, inicioY -75.0f);
glEnd();
//CONTENEDOR DE BOTON ASCENSOR
glColor4f(0.9137f, 0.8549f, 0.8667f, x);
glBegin(GL_POLYGON);
glVertex2f(inicioX + 27.5f, inicioY + -32.8f);
glVertex2f(inicioX + 30.5f, inicioY + -32.8f);
//CONTENEDOR DE BOTON ASCENSOR
glColor4f(0.6902f, 0.6706f, 0.8471f, x);
glVertex2f(inicioX + 30.5f, inicioY + -43.8f);
glVertex2f(inicioX + 27.5f, inicioY + -43.8f);
glEnd();
//SOMBRA BAJA ASCENSOR
glColor4f(0.4667f, 0.4471f, 0.7098f, 0.2f);
glBegin(GL_POLYGON);
glVertex2f(inicioX+ 1.5f, inicioY -65.8f);
glVertex2f(inicioX + 24.5f, inicioY -70.0f);
glVertex2f(inicioX + 24.5f, inicioY -75.0f);
glVertex2f(inicioX + 1.5f, inicioY -75.0f);
glEnd();
//BOTON ASCENSOR
float px = inicioX + 27.5f, py = inicioY + -32.8f, radio = 1.3, calx, caly;
glColor4f(0.6941f, 0.0588f, 0.3490f, x);
glBegin(GL_POLYGON);
for(float i = 0.0; i < 7; i+=0.001){
calx = radio * cos(i);
caly = radio * sin(i);
glVertex2f(calx + 16.1f, caly - 28.5f);
}
glEnd();
}
//SOMBRAS
void figura_sombra_triangulo_frontal(){
glBegin(GL_TRIANGLES);
glColor4f(0.4000f, 0.4000f, 0.4000f, 0.3000f);
glVertex2f (-100.0f, 68.0f); //A
glVertex2f (-45.0f, 68.0f);//B
glVertex2f (-45.0f, 48.0f);//M
glEnd();
}
void figura_sombra_cuadrilatero_fondo(){
glBegin(GL_QUADS);
glColor4f(0.0000f, 0.0000f, 0.0000f, 0.2f);
glVertex2f (-45.0f, 68.0f);//B
glVertex2f (-25.0f, 51.0f);//E
glVertex2f (-25.0f, -7.0f);//N
glVertex2f (-45.0f, 48.0f);//M
glEnd();
}
void figura_sombra_cuadrilatero_central(){
glBegin(GL_QUADS);
glColor4f(0.0000f, 0.0000f, 0.0000f, 0.2000f);
glVertex2f (-25.0f, 51.0f);//E
glVertex2f (25.0f, 51.0f);//G
glVertex2f (25.0f, -7.0f);//O
glVertex2f (-25.0f, -7.0f);//N
glEnd();
}
void grifo(GLfloat r, GLfloat b){
//----
glBegin(GL_POLYGON);
glColor3f(r,0.0f,b);
glVertex2f(34.7f,-37.8f);
glVertex2f(34.9f,-39.0f);
glVertex2f(36.0f,-39.0f);
glVertex2f(36.2f,-37.8f);
glEnd();
//-------
glBegin(GL_POLYGON);
glColor3f(0.8f,0.8f,0.8f);
glVertex2f(34.9f,-39.0f);
glVertex2f(35.0f,-42.8f);
glVertex2f(35.8f,-42.8f);
glVertex2f(36.0f,-39.0f);
glEnd();
}
void bidon_agua(){
//PARTE BAJA BIDON
glBegin(GL_POLYGON);
glColor3f(0.8f,0.8f, 1.0f);
glVertex2f(33.0f,-26.0f);
glVertex2f(33.0f,-27.0f);
glVertex2f(37.0f,-30.0f);
glVertex2f(38.5f,-30.0f);
glVertex2f(42.0f,-27.0f);
glVertex2f(42.0f,-26.0f);
glVertex2f(39.0f,-25.5f);
glVertex2f(36.0f,-25.5f);
glEnd();
//SUJETADOR INFERIOR BIDON
glBegin(GL_POLYGON);
glColor3f(0.8196f, 0.7804f, 0.9294f);
glVertex2f(33.0f,-24.4f);
glVertex2f(32.4f,-25.2f);
glVertex2f(32.4f,-26.2f);
glVertex2f(33.0f,-26.0f);
glVertex2f(36.0f,-25.5f);
glVertex2f(39.0f,-25.5f);
glVertex2f(42.0f,-26.0f);
glVertex2f(42.6f,-26.2f);
glVertex2f(42.6f,-25.2f);
glVertex2f(42.0f,-24.4f);
glVertex2f(39.0f,-24.0f);
glVertex2f(36.0f,-24.0f);
glEnd();
//INTERIOR SUPERIOR BIDON
glBegin(GL_POLYGON);
glColor3f(0.8,0.8f, 1.0f);
glVertex2f(33.0f,-16.0f);
glVertex2f(33.0f,-24.4f);
glVertex2f(36.0f,-24.0f);
glVertex2f(39.0f,-24.0f);
glVertex2f(42.0f,-24.4f);
glVertex2f(42.0f,-16.0f);
glEnd();
//SUJETADOR INFERIOR BIDON
glPushMatrix();
glTranslatef (0.0f,9.7f,0.0f);
glBegin(GL_POLYGON);
glColor3f(0.8196f, 0.7804f, 0.9294f);
glVertex2f(33.0f,-24.4f);
glVertex2f(32.4f,-25.2f);
glVertex2f(32.4f,-26.2f);
glVertex2f(33.0f,-26.0f);
glVertex2f(36.0f,-25.5f);
glVertex2f(39.0f,-25.5f);
glVertex2f(42.0f,-26.0f);
glVertex2f(42.6f,-26.2f);
glVertex2f(42.6f,-25.2f);
glVertex2f(42.0f,-24.4f);
glVertex2f(39.0f,-24.0f);
glVertex2f(36.0f,-24.0f);
glEnd();
glPopMatrix();
//PARTE SUPERIOR BIDON
glPushMatrix();
glScalef(0.83f,0.83f,0.0f);
glTranslatef (7.9f,7.9f,0.0f);
glBegin(GL_POLYGON);
glColor3f(0.8,0.8f, 1.0f);
glVertex2f(33.0f,-24.4f);
glVertex2f(32.4f,-25.2f);
glVertex2f(32.4f,-26.2f);
glVertex2f(33.0f,-26.0f);
glVertex2f(36.0f,-25.5f);
glVertex2f(39.0f,-25.5f);
glVertex2f(42.0f,-26.0f);
glVertex2f(42.6f,-26.2f);
glVertex2f(42.6f,-25.2f);
glVertex2f(42.0f,-24.4f);
glVertex2f(39.0f,-24.0f);
glVertex2f(36.0f,-24.0f);
glEnd();
glPopMatrix();
}
void dispensador_agua(){
//FRONTAL DISPENSADOR
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glColor3f(0.9647f, 0.9490f, 1.0000f);
glVertex2f(32.0f,-30.0f);
glVertex2f(32.0f,-65.0f);
glVertex2f(43.0f,-65.0f);
glVertex2f(43.0f,-30.0f);
glEnd();
//ESQUINA DISPENSADOR
glBegin(GL_POLYGON);
glColor3f(0.7882f, 0.7569f, 0.9608f);
glVertex2f(29.0f,-34.0f);
glVertex2f(29.0f,-65.0f);
glVertex2f(32.0f,-65.0f);
glVertex2f(32.0f,-30.0f);
glEnd();
//INTERIOR CAJA DISPENSADOR
glBegin(GL_POLYGON);
glColor3f(0.5176f, 0.4706f, 0.6196f);
glVertex2f(33.0f,-40.0f);
glVertex2f(33.0f,-53.0f);
glVertex2f(40.0f,-53.0f);
glVertex2f(40.0f,-40.0f);
glEnd();
//SUPERIOR INTERIOR DISPENSADOR
glBegin(GL_POLYGON);
glColor3f(0.6824f, 0.6314f, 0.7882f);
glVertex2f(34.0f,-36.5f);
glVertex2f(33.0f,-40.0f);
glVertex2f(40.0f,-40.0f);
glVertex2f(41.0f,-36.5f);
glEnd();
//LATERAL DERECHO INTERIOR DISPENSADOR
glBegin(GL_POLYGON);
glColor3f(0.7961f, 0.7569f, 0.8784f);
glVertex2f(40.0f,-40.0f);
glVertex2f(40.0f,-53.0f);
glVertex2f(41.0f,-53.0f);
glVertex2f(41.0f,-36.5f);
glEnd();
//CAÑOS
grifo(1.0f,0.0f);
glPushMatrix(); glTranslatef (3.0f, 0.0f, 0.0f), grifo (0.0f, 1.0f); glPopMatrix();
//BIDON DE AGUA
glPushMatrix(); glTranslatef(-0.5f, 0.0f, 0.0f), bidon_agua(); glPopMatrix();
/*PARTE BAJA PLASTICO PARTE 1
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(31.0f,-24.0f);//H
glVertex2f(37.0f,-30.0f);//E
glVertex2f(37.0f,-29.0f);//F
glVertex2f(32.0f,-24.0f);//G
glEnd();
//PARTE BAJA PLASTICO PARTE 2
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(31.0f,-24.0f);//H
glVertex2f(32.0f,-24.0f);//G
glVertex2f(32.0f,-20.0f);//1
glVertex2f(31.0f,-20.5f);//J
glEnd();
//PRIMERA LINEA BOTE
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f, 1.0f);
glVertex2f(31.0f,-20.5f);//J
glVertex2f(32.0f,-20.0f);//1
glVertex2f(31.5f,-19.4f);//K
glVertex2f(30.0f,-19.5f);//L
glEnd();
//CUADRO PARTE BAJA BOTE
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(31.0f,-19.5f);//O
glVertex2f(30.0f,-19.5f);//L
glVertex2f(30.0f,-16.6f);//M
glVertex2f(31.0f,-16.6f);//N
glEnd();
//CUADRO PARTE MEDIA BOTE
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(31.0f,-17.6f);//P
glVertex2f(32.0f,-17.6f);//Q
glVertex2f(32.0f,-3.2f);//R
glVertex2f(31.0f,-3.4f);//S
glEnd();
ggg
*/
/*
glPushMatrix(); glRotatef (180.0f,0.0f, 1.0f, 0.0f);
glTranslatef(-75.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(37.0f,-30.0f);//E
glVertex2f(37.0f,-29.0f);//F
glVertex2f(32.0f,-24.0f);//G
glVertex2f(31.0f,-24.0f);//H
glEnd();
glPopMatrix();
*/
}
//MACETA
void hoja(){
float inicioX =-30.0;
float inicioY =-30.0;
glBegin(GL_POLYGON);
glVertex2f(inicioX, inicioY);
glColor4f(0.4823f, 0.4784f, 0.0117f, 1.0f);
glVertex2f(inicioX-0.8, inicioY+1.0);
glVertex2f(inicioX-1.2, inicioY+2.0);
glVertex2f(inicioX-1.6, inicioY+3.0);
glVertex2f(inicioX-1.8, inicioY+5.0);
glVertex2f(inicioX-1.7, inicioY+6.0);
glVertex2f(inicioX-1.6, inicioY+6.0);
glVertex2f(inicioX-1.3, inicioY+8.0);
glVertex2f(inicioX-0.5, inicioY+10.0);
glColor4f(0.7098f, 0.7568f, 0.3725f, 1.0f);
glVertex2f(inicioX-0.4, inicioY+11.0);
glEnd();
glVertex2f(inicioX, inicioY+12.0);
glVertex2f(inicioX+0.4, inicioY+11.0);
glVertex2f(inicioX+0.5, inicioY+10.0);
glVertex2f(inicioX+1.3, inicioY+8.0);
glVertex2f(inicioX+1.6, inicioY+6.0);
glColor4f(0.7098f, 0.7568f, 0.3725f, 1.0f);
glVertex2f(inicioX+1.7, inicioY+6.0);
glVertex2f(inicioX+1.8, inicioY+5.0);
glVertex2f(inicioX+1.6, inicioY+3.0);
glVertex2f(inicioX+1.2, inicioY+2.0);
glColor4f(0.5254f, 0.6745f, 0.3882f, 1.0f);
glVertex2f(inicioX+0.8, inicioY+1.0);
}
void maceta(){
float inicioX =-30.0f;
float inicioY =-67.0;
//Maceta
glColor4f(0.9960f, 0.8470f, 0.7607f, 1.0000f);
glBegin(GL_QUADS);
glVertex2f(inicioX, inicioY);
glVertex2f(inicioX + 1.0f, inicioY + 17.0f);
glVertex2f(inicioX - 10.0f, inicioY + 22.0f);
glVertex2f(inicioX - 9.0f, inicioY);
glEnd();
glColor4f(0.9764f, 0.9843f, 0.7215f, 1.0000f);
glBegin(GL_POLYGON);
glVertex2f(inicioX - 10.0f, inicioY + 22.0f);
glVertex2f(inicioX + 1.0f, inicioY + 17.0f);
glVertex2f(inicioX, inicioY + 18.0f);
glVertex2f(inicioX - 1.0f, inicioY + 18.0f);
glVertex2f(inicioX - 2.0f, inicioY + 19.0f);
glVertex2f(inicioX - 3.0f, inicioY + 19.5f);
glVertex2f(inicioX - 4.0f, inicioY + 20.0f);
glVertex2f(inicioX - 5.0f, inicioY+20.7f);
glVertex2f(inicioX - 6.0f, inicioY + 20.8f);
glEnd();
//Hojas
glPushMatrix(); glTranslatef (5.0f,-28.0f, 0.0f); glRotatef(-20,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
//Rama
glColor4f(0.4705f, 0.2352f, 0.1803f, 1.0000f);
glLineWidth(3.0);
glBegin(GL_LINE_STRIP);
glVertex2f(inicioX - 4.0f, inicioY+20.0f);
glVertex2f(inicioX - 3.8f, inicioY+23.0f);
glVertex2f(inicioX - 4.2f, inicioY+24.0f);
glVertex2f(inicioX - 3.5f, inicioY+25.0f);
glVertex2f(inicioX - 1.5f, inicioY+31.0f);
glVertex2f(inicioX - 1.0f, inicioY+38.0f);
//--
glVertex2f(inicioX - 0.9f, inicioY+33.0f);
glVertex2f(inicioX - 0.9f, inicioY+31.0f);
glVertex2f(inicioX - 3.4f, inicioY+24.5f);
glVertex2f(inicioX - 3.5f, inicioY+19.6f);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2f(inicioX - 2.0f, inicioY+28.0f);
glVertex2f(inicioX - 3.0f, inicioY+35.0f);
glVertex2f(inicioX - 2.5f, inicioY+40.0f);
glVertex2f(inicioX - 2.8f, inicioY+45.0f);
glEnd();
//Hojas
/**/glPushMatrix(); glTranslatef(-10.0f,-5.0f, 0.0f); glRotatef (12,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
glPushMatrix(); glTranslatef(-10.0f,-5.0f, 0.0f); glRotatef (12,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
glPushMatrix(); glTranslatef(-16.0f,-7.0f, 0.0f); glRotatef (20,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
glPushMatrix(); glTranslatef (7.2f,-15.0f, 0.0f); glRotatef(-20,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
glPushMatrix(); glTranslatef(-15.0f, 7.0f, 0.0f); glRotatef (20,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
glPushMatrix(); glTranslatef (2.0f, 0.0f, 0.0f); glRotatef(-10,0.0f, 0.0f, 1.0f); hoja(); glPopMatrix();
}
