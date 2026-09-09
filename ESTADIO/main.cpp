#include <math.h>
#include <GL\freeglut.h>

//DEFINICION DE VARIABLES

GLUquadricObj *cilindro;

//Posicion de la camara
float pos_camX = 0, pos_camY = 0, pos_camZ = 0; 
  
//Movimiento del objeto: arrow_keys()
int eye_camX = 0, eye_camY = 0, eye_camZ = 0;
  
//Posicion de inicio de la camara
float posX=-60, posY=-35, posZ=-15;

//Otras variables
float aspect = 1.0;
  
//Propiedades de LUZ
GLfloat Diffuse[] = {1., 1.0, 0.5, 1.0};	// Luz ambiente de la fuente
GLfloat Specular[] = {1.0, 1.0, 1.0, 1.0};	// Luz especular
GLfloat Position[] = {0.0, 3.0, 0.0, 1.0};	// Posicion de la luz
GLfloat Position2[] = {0.0, 0.0, -5.0, 1.0};
 
void InitGL(){	// Inicializamos parametros
    glClearColor(0.0, 0.0, 0.0, 0.0);	// Color de Fondo
    glEnable(GL_TEXTURE_2D);
          
    //glShadeModel (GL_SMOOTH);     
    //Propideades de Luz
    glLightfv(GL_LIGHT0, GL_POSITION, Position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
    glEnable(GL_LIGHTING);	//Activar luces
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);	//Activar colores definidos al objeto*/
         
    glClearDepth(1.0);	// Configuramos Depth Buffer
    glEnable(GL_DEPTH_TEST);	// Habilitamos Depth Testing
    glDepthFunc(GL_LEQUAL);	// Tipo de Depth Testing a realizar
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
	
void Crear_Cilindros(){
	glColor3f(0.67,0.69,0.80);
	cilindro = gluNewQuadric();
	gluCylinder(cilindro, 0.1, 0.1, 1.5, 20, 20);	
}

void Crear_CilindrosV1(){
	glColor3f(1.0,1.0,0.4);
	cilindro = gluNewQuadric();
	gluCylinder(cilindro, 0.025, 0.025, 1.05, 20, 20);	
}

void Crear_CilindrosV2(){
	glColor3f(0.9,0.5,0.0);
	cilindro = gluNewQuadric();
	gluCylinder(cilindro, 0.025, 0.025, 0.45, 20, 20);	
}

void Letrero(){
	   
    //pared hueco marco derecha
    
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(122.76,105.75,0.00);
	glVertex3f(122.76,105.25,0.00);
    glVertex3f(122.71,105.25,6.00);
	glVertex3f(122.71,105.75,6.00);
    glEnd();
    
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(122.76,105.25,0.00);
	glVertex3f(123.01,105.25,0.00);
    glVertex3f(123.01,105.25,6.00);
	glVertex3f(122.76,105.25,6.00);
    glEnd();
    
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(123.01,105.25,0.00);
	glVertex3f(123.01,105.25,6.00);
    glVertex3f(123.06,105.75,6.00);
	glVertex3f(123.01,105.75,0.00);
    glEnd();
    
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(123.01,105.75,0.00);
	glVertex3f(122.76,105.75,0.00);
    glVertex3f(122.76,105.75,6.00);
	glVertex3f(123.01,105.75,6.00);
    glEnd();
    
    
    
    
    
     glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(122.76,100.25,0.00);
	glVertex3f(122.76,99.75,0.00);
    glVertex3f(122.71,99.75,6.00);
	glVertex3f(122.71,100.25,6.00);
    glEnd();
    
       glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(122.76,99.75,0.00);
	glVertex3f(123.01,99.75,0.00);
    glVertex3f(123.01,99.75,6.00);
	glVertex3f(122.76,99.75,6.00);
    glEnd();
    
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(123.01,99.75,0.00);
	glVertex3f(123.01,99.75,6.00);
    glVertex3f(123.06,100.25,6.00);
	glVertex3f(123.01,100.25,0.00);
    glEnd();
    
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
     glVertex3f(123.01,100.25,0.00);
	glVertex3f(122.76,100.25,0.00);
    glVertex3f(122.76,100.25,6.00);
	glVertex3f(123.01,100.25,6.00);
    glEnd();
    
    

    
    
    
  
    
      glColor3f(0.65,0.65,0.65);
    glBegin(GL_POLYGON);
    glVertex3f(122.76,105.64,6.05);
	    glVertex3f(122.76,105.22,6.49);
	    glVertex3f(122.71,104.04,7.06);
	    glVertex3f(122.71,103.88,7.27);
	    glVertex3f(122.71,103.32,7.41);
	    glVertex3f(122.71,102.75,7.45);
	    glVertex3f(122.71,102.18,7.41);
	    glVertex3f(122.71,101.61,7.27);
	    glVertex3f(122.71, 101.01,7.06);
	    glVertex3f(122.71, 100.61,6.77);
	    glVertex3f(122.71, 100.28,6.49);
	    glVertex3f(122.71, 100.28, 6.05);
    glEnd();
	   
}

void Piso(){
	  glColor3f(0.43,0.44,0.45);
    glBegin(GL_POLYGON);
	    glVertex3f(117.49,99.25,0.00);
	    glVertex3f(117.49, 101.25, 0.00);
	    glVertex3f(-3.01, 101.25, 0.00);
	    glVertex3f(-3.01, 99.25, 0.00);
    glEnd();
}

void Campo_Futbol(){
    //GRASS
    glColor3f(0.38,0.55,0.29);
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 90.0, 0.0);
	    glVertex3f(120.0, 90.0, 0.0);
	    glVertex3f(120.0, 0.0, 0.0);
	    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.0, 48.74, 0.0);
	    glVertex3f(0.0, 48.74, 0.0);
	    glVertex3f(0.0, 41.26, 0.0);
	    glVertex3f(-3.0, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.0, 48.74, 0.0);
	    glVertex3f(123.0, 48.74, 0.0);
	    glVertex3f(123.0, 41.26, 0.0);
	    glVertex3f(120.0, 41.26, 0.0);
    glEnd();
}

void Pasto_Extra(){
	glColor3f(0.56,0.63,0.36);
	
    glBegin(GL_POLYGON);
	    glVertex3f(-25.6, 48.74, 0.0);
	    glVertex3f(-25.15, 54.10, 0.0);
	    glVertex3f(-22.87, 62.95, 0.0);
	    glVertex3f(-19.14, 71.29, 0.0);
	    glVertex3f(-14.06, 78.89, 0.0);
	    glVertex3f(-7.79, 85.53, 0.0);
	    glVertex3f(-0.31, 91.17, 0.0);
	    glVertex3f(0.0, 91.17, 0.0);
	    glVertex3f(0.0, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-25.6, 48.74, 0.0);
	    glVertex3f(-3.0, 48.74, 0.0);
	    glVertex3f(-3.0, 41.26, 0.0);
	    glVertex3f(-25.6, 41.26, 0.0);
	    glVertex3f(-25.92, 45.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-25.6, 41.26, 0.0);
	    glVertex3f(0.0, 41.26, 0.0);
	    glVertex3f(0.0, -1.17, 0.0);
	    glVertex3f(-0.31, -1.17, 0.0);
	    glVertex3f(-7.79, 4.47, 0.0);
	    glVertex3f(-14.06, 11.11, 0.0);
	    glVertex3f(-19.14, 18.71, 0.0);
	    glVertex3f(-22.87, 27.05, 0.0);
	    glVertex3f(-25.15, 35.90, 0.0);
    glEnd();
	
    glBegin(GL_POLYGON);
	    glVertex3f(145.60, 48.74, 0.0);
	    glVertex3f(119.92, 48.74, 0.0);
	    glVertex3f(120.0, 90.0, 0.0);
	    glVertex3f(120.0, 91.17, 0.0);
	    glVertex3f(120.31, 91.17, 0.0);
	    glVertex3f(127.79, 85.53, 0.0);
	    glVertex3f(134.06, 78.89, 0.0);
	    glVertex3f(139.14, 71.29, 0.0);
	    glVertex3f(142.87, 62.95, 0.0);
	    glVertex3f(145.15, 54.10, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(145.60, 41.26, 0.0);
	    glVertex3f(123.0, 41.26, 0.0);
	    glVertex3f(123.0, 48.74, 0.0);
	    glVertex3f(145.6, 48.74, 0.0);
	    glVertex3f(145.92, 45.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
	    glVertex3f(145.60, 41.26, 0.0);
	    glVertex3f(145.15, 35.90, 0.0);
	    glVertex3f(142.87, 27.05, 0.0);
	    glVertex3f(139.14, 18.71, 0.0);
	    glVertex3f(134.06, 11.11, 0.0);
	    glVertex3f(127.79, 4.47, 0.0);
	    glVertex3f(120.31, -1.17, 0.0);
	    glVertex3f(120.0, -1.17, 0.0);
	    glVertex3f(120.0, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 91.17, 0.0);
	    glVertex3f(120.0, 91.17, 0.0);
	    glVertex3f(120.0, 90.0, 0.0);
	    glVertex3f(0.0, 90.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 0.0, 0.0);
	    glVertex3f(120.0, 0.0, 0.0);
	    glVertex3f(120.0, -1.17, 0.0);
	    glVertex3f(0.0, -1.17, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, 99.25, 0.0);
		glVertex3f(-2.68, 98.25, 0.0);
		glVertex3f(-12.53, 90.83, 0.0);
		glVertex3f(-13.20, 91.58, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-13.20, 91.58, 0.0);
		glVertex3f(-12.53, 90.83, 0.0);
		glVertex3f(-19.62, 83.32, 0.0);
		glVertex3f(-20.41, 83.95, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-20.41, 83.95, 0.0);
		glVertex3f(-19.62, 83.32, 0.0);
		glVertex3f(-25.36, 74.73, 0.0);
		glVertex3f(-26.24, 75.22, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-26.24, 75.22, 0.0);
		glVertex3f(-25.36, 74.73, 0.0);
		glVertex3f(-29.58, 65.30, 0.0);
		glVertex3f(-30.53, 65.63, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-30.53, 65.63, 0.0);
		glVertex3f(-29.58, 65.30, 0.0);
		glVertex3f(-32.16, 55.30, 0.0);
		glVertex3f(-33.15, 55.46, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-33.15, 55.46, 0.0);
		glVertex3f(-32.16, 55.30, 0.0);
		glVertex3f(-33.03, 45.0, 0.0);
		glVertex3f(-34.03, 45.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-34.03, 45.0, 0.0);
		glVertex3f(-33.03, 45.0, 0.0);
		glVertex3f(-32.16, 34.70, 0.0);
		glVertex3f(-33.15, 34.54, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-33.15, 34.54, 0.0);
		glVertex3f(-32.16, 34.70, 0.0);
		glVertex3f(-29.58, 24.70, 0.0);
		glVertex3f(-30.53, 24.37, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-30.53, 24.37, 0.0);
		glVertex3f(-29.58, 24.70, 0.0);
		glVertex3f(-25.36, 15.27, 0.0);
		glVertex3f(-26.24, 14.78, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-26.24, 14.78, 0.0);
		glVertex3f(-25.36, 15.27, 0.0);
		glVertex3f(-19.62, 6.68, 0.0);
		glVertex3f(-20.41, 6.05, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-20.41, 6.05, 0.0);
		glVertex3f(-19.62, 6.68, 0.0);
		glVertex3f(-12.53, -0.83, 0.0);
		glVertex3f(-13.20, -1.58, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-13.20, -1.58, 0.0);
		glVertex3f(-12.53, -0.83, 0.0);
		glVertex3f(-2.68, -8.25, 0.0);
		glVertex3f(-3.01, -9.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.68, 98.25, 0.0);
		glVertex3f(123.01, 99.25, 0.0);
		glVertex3f(133.20, 91.58, 0.0);
		glVertex3f(132.53, 90.83, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(132.53, 90.83, 0.0);
		glVertex3f(133.20, 91.58, 0.0);
		glVertex3f(140.41, 83.95, 0.0);
		glVertex3f(139.62, 83.32, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(139.62, 83.32, 0.0);
		glVertex3f(140.41, 83.95, 0.0);
		glVertex3f(146.24, 75.22, 0.0);
		glVertex3f(145.36, 74.73, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(145.36, 74.73, 0.0);
		glVertex3f(146.24, 75.22, 0.0);
		glVertex3f(150.53, 65.63, 0.0);
		glVertex3f(149.58, 65.30, 0.0);
    glEnd();

	glBegin(GL_POLYGON);
	    glVertex3f(149.58, 65.30, 0.0);
		glVertex3f(150.53, 65.63, 0.0);
		glVertex3f(153.15, 55.46, 0.0);
		glVertex3f(152.16, 55.30, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(152.16, 55.30, 0.0);
		glVertex3f(153.15, 55.46, 0.0);
		glVertex3f(154.03, 45.00, 0.0);
		glVertex3f(153.03, 45.00, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(153.03, 45.00, 0.0);
		glVertex3f(154.03, 45.00, 0.0);
		glVertex3f(153.15, 34.54, 0.0);
		glVertex3f(152.16, 34.70, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(152.16, 34.70, 0.0);
		glVertex3f(153.15, 34.54, 0.0);
		glVertex3f(150.53, 24.37, 0.0);
		glVertex3f(149.58, 24.70, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(149.58, 24.70, 0.0);
		glVertex3f(150.53, 24.37, 0.0);
		glVertex3f(146.24, 14.78, 0.0);
		glVertex3f(145.36, 15.27, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(145.36, 15.27, 0.0);
		glVertex3f(146.24, 14.78, 0.0);
		glVertex3f(140.41, 6.05, 0.0);
		glVertex3f(139.62, 6.68, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(139.62, 6.68, 0.0);
		glVertex3f(140.41, 6.05, 0.0);
		glVertex3f(133.20, -1.58, 0.0);
		glVertex3f(132.53, -0.83, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(132.53, -0.83, 0.0);
		glVertex3f(133.20, -1.58, 0.0);
		glVertex3f(123.01, -9.25, 0.0);
		glVertex3f(122.68, -8.25, 0.0);
    glEnd();
		
	glBegin(GL_POLYGON);
	    glVertex3f(-3.01, 99.25, 0.0);
		glVertex3f(123.01, 99.25, 0.0);
		glVertex3f(122.68, 98.25, 0.0);
		glVertex3f(-2.68, 98.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-2.68, -8.25, 0.0);
		glVertex3f(122.68, -8.25, 0.0);
		glVertex3f(123.01, -9.25, 0.0);
		glVertex3f(-3.01, -9.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(116.99, 99.25, 0.0);
		glVertex3f(116.99, 119.25, 0.0);
		glVertex3f(123.01, 119.25, 0.0);
		glVertex3f(123.01, 99.25, 0.0);
    glEnd();
}

void Pista_Atletica(){
	glColor3f(0.71,0.41,0.38);
	
	//Derecha
	glBegin(GL_POLYGON);
		glVertex3f(-2.68, 98.25, 0.0);
		glVertex3f(-0.31, 91.17, 0.0);
		glVertex3f(-7.79, 85.53, 0.0);
		glVertex3f(-12.53, 90.83, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    	glVertex3f(-12.53, 90.83, 0.0);
    	glVertex3f(-7.79, 85.53, 0.0);
    	glVertex3f(-14.06, 78.89, 0.0);
    	glVertex3f(-19.62, 83.32, 0.0);
    glEnd();
		
    glBegin(GL_POLYGON);
		glVertex3f(-19.62, 83.32, 0.0);
		glVertex3f(-14.06, 78.89, 0.0);
		glVertex3f(-19.14, 71.29, 0.0);
		glVertex3f(-25.36, 74.73, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-25.36, 74.73, 0.0);
		glVertex3f(-19.14, 71.29, 0.0);
		glVertex3f(-22.87, 62.95, 0.0);
		glVertex3f(-29.58, 65.30, 0.0);
    glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-29.58, 65.30, 0.0);
		glVertex3f(-22.87, 62.95, 0.0);
		glVertex3f(-25.15, 54.10, 0.0);
		glVertex3f(-32.16, 55.30, 0.0);
    glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-32.16, 55.30, 0.0);
		glVertex3f(-25.15, 54.10, 0.0);
		glVertex3f(-25.92, 45.0, 0.0);
		glVertex3f(-33.03, 45.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-33.03, 45.0, 0.0);
		glVertex3f(-25.92, 45.0, 0.0);
		glVertex3f(-25.15, 35.9, 0.0);
		glVertex3f(-32.16, 34.70, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-32.16, 34.70, 0.0);
		glVertex3f(-25.15, 35.9, 0.0);
		glVertex3f(-22.87, 27.05, 0.0);
		glVertex3f(-29.58, 24.70, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-29.58, 24.70, 0.0);
		glVertex3f(-22.87, 27.05, 0.0);
		glVertex3f(-19.14, 18.71, 0.0);
		glVertex3f(-25.36, 15.27, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-25.36, 15.27, 0.0);
		glVertex3f(-19.14, 18.71, 0.0);
		glVertex3f(-14.06, 11.11, 0.0);
		glVertex3f(-19.62, 6.68, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-19.62, 6.68, 0.0);
		glVertex3f(-14.06, 11.11, 0.0);
		glVertex3f(-7.79, 4.47, 0.0);
		glVertex3f(-12.53, -0.83, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(-12.53, -0.83, 0.0);
		glVertex3f(-7.79, 4.47, 0.0);
		glVertex3f(-0.31, -1.17, 0.0);
		glVertex3f(-2.68, -8.25, 0.0);
    glEnd();
	
	//Izquierda
	glBegin(GL_POLYGON);
		glVertex3f(120.31, 91.17, 0.0);
		glVertex3f(122.68, 98.25, 0.0);
		glVertex3f(132.53, 90.83, 0.0);
		glVertex3f(127.79, 85.53, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(127.79, 85.53, 0.0);
		glVertex3f(132.53, 90.83, 0.0);
		glVertex3f(139.62, 83.32, 0.0);
		glVertex3f(134.06, 78.89, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(134.06, 78.89, 0.0);
		glVertex3f(139.62, 83.32, 0.0);
		glVertex3f(145.36, 74.73, 0.0);
		glVertex3f(139.14, 71.29, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(139.14, 71.29, 0.0);
		glVertex3f(145.36, 74.73, 0.0);
		glVertex3f(149.58, 65.30, 0.0);
		glVertex3f(142.87, 62.95, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(142.87, 62.95, 0.0);
		glVertex3f(149.58, 65.30, 0.0);
		glVertex3f(152.16, 55.30, 0.0);
		glVertex3f(145.15, 54.10, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(145.15, 54.10, 0.0);
		glVertex3f(152.16, 55.30, 0.0);
		glVertex3f(153.03, 45.0, 0.0);
		glVertex3f(145.92, 45.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(145.92, 45.0, 0.0);
		glVertex3f(153.03, 45.0, 0.0);
		glVertex3f(152.16, 34.70, 0.0);
		glVertex3f(145.15, 35.90, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(145.15, 35.90, 0.0);
		glVertex3f(152.16, 34.70, 0.0);
		glVertex3f(149.58, 24.70, 0.0);
		glVertex3f(142.87, 27.05, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(142.87, 27.05, 0.0);
		glVertex3f(149.58, 24.70, 0.0);
		glVertex3f(145.36, 15.27, 0.0);
		glVertex3f(139.14, 18.71, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(139.14, 18.71, 0.0);
		glVertex3f(145.36, 15.27, 0.0);
		glVertex3f(139.62, 6.68, 0.0);
		glVertex3f(134.06, 11.11, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(134.06, 11.11, 0.0);
		glVertex3f(139.62, 6.68, 0.0);
		glVertex3f(132.53, -0.83, 0.0);
		glVertex3f(127.79, 4.47, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
		glVertex3f(127.79, 4.47, 0.0);
		glVertex3f(132.53, -0.83, 0.0);
		glVertex3f(122.68, -8.25, 0.0);
		glVertex3f(120.31, -1.17, 0.0);
    glEnd();
       
	glBegin(GL_POLYGON);
	    glVertex3f(-2.68, 98.25, 0.0);
	    glVertex3f(122.68, 98.25, 0.0);
	    glVertex3f(120.31, 91.17, 0.0);
	    glVertex3f(-0.31, 91.17, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-0.31, -1.17, 0.0);
	    glVertex3f(120.31, -1.17, 0.0);
	    glVertex3f(122.68, -8.25, 0.0);
	    glVertex3f(-2.68, -8.25, 0.0);
    glEnd();
	
}

void Lineas_de_Campo(){
    glColor3f(1.0,1.0,1.0);
    glLineWidth(2.5);
	//Bordes
	glBegin(GL_LINES);
		glVertex3f(0.0, 89.96, 0.0);
	    glVertex3f(120.0, 89.96, 0.0);
	    glVertex3f(119.96, 90.0, 0.0);
	    glVertex3f(119.96, 0.0, 0.0);
	    glVertex3f(120.0, 0.04, 0.0);
	    glVertex3f(0.0, 0.04, 0.0);
	    glVertex3f(0.04, 90.0, 0.0);
	    glVertex3f(0.04, 0.0, 0.0);
    //Linea del Medio
	    glVertex3f(60.0, 89.92, 0.0);
	    glVertex3f(60.0, 0.08, 0.0);
    glEnd();
    
    //Areas Grandes
    glBegin(GL_LINE_STRIP);
	    glVertex3f(0.08, 65.16, 0.0);
	    glVertex3f(16.5, 65.16, 0.0);
	    glVertex3f(16.50, 24.84, 0.0);
	    glVertex3f(0.08, 24.84, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
	    glVertex3f(119.92, 65.16, 0.0);
	    glVertex3f(103.50, 65.16, 0.0);
	    glVertex3f(103.5, 24.84, 0.0);
	    glVertex3f(119.92, 24.84, 0.0);
    glEnd();
    
    //Areas Chicas
    glBegin(GL_LINE_STRIP);
	    glVertex3f(0.08, 54.16, 0.0);
	    glVertex3f(5.5, 54.16, 0.0);
	    glVertex3f(5.50, 35.84, 0.0);
	    glVertex3f(0.08, 35.84, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
	    glVertex3f(119.92, 54.16, 0.0);
	    glVertex3f(114.5, 54.16, 0.0);
	    glVertex3f(114.5, 35.84, 0.0);
	    glVertex3f(119.92, 35.84, 0.0);
    glEnd();
    
    //Medias Lunas
    glBegin(GL_LINE_STRIP);
	    glVertex3f(16.5, 52.25, 0.0);
	    glVertex3f(17.91, 50.99, 0.0);
	    glVertex3f(19.23, 49.0, 0.0);
	    glVertex3f(19.98, 46.73, 0.0);
	    glVertex3f(20.13, 44.35, 0.0);
	    glVertex3f(19.65, 42.01, 0.0);
	    glVertex3f(18.58, 39.87, 0.0);
	    glVertex3f(16.99, 38.09, 0.0);
	    glVertex3f(16.5, 37.76, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
	    glVertex3f(103.48, 52.30, 0.0);
	    glVertex3f(101.78, 50.62, 0.0);
	    glVertex3f(100.57, 48.56, 0.0);
	    glVertex3f(99.94, 46.26, 0.0);
	    glVertex3f(99.92, 43.87, 0.0);
	    glVertex3f(100.52, 41.56, 0.0);
	    glVertex3f(101.70, 39.48, 0.0);
	    glVertex3f(103.38, 37.78, 0.0);
	    glVertex3f(103.5, 37.71, 0.0);
    glEnd();
    
    //Esquinas
    glBegin(GL_LINE_STRIP);
	    glVertex3f(0.99, 89.92, 0.0);
	    glVertex3f(0.95, 89.70, 0.0);
	    glVertex3f(0.84, 89.46, 0.0);
	    glVertex3f(0.68, 89.26, 0.0);
	    glVertex3f(0.46, 89.11, 0.0);
	    glVertex3f(0.22, 89.02, 0.0);
	    glVertex3f(0.08, 89.01, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
	    glVertex3f(119.0, 89.92, 0.0);
	    glVertex3f(119.06, 89.67, 0.0);
	    glVertex3f(119.18, 89.43, 0.0);
	    glVertex3f(119.35, 89.24, 0.0);
	    glVertex3f(119.57, 89.10, 0.0);
	    glVertex3f(119.82, 89.02, 0.0);
	    glVertex3f(119.92, 89.01, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
	    glVertex3f(119.92, 0.99, 0.0);
	    glVertex3f(119.81, 0.98, 0.0);
	    glVertex3f(119.56, 0.90, 0.0);
	    glVertex3f(119.35, 0.76, 0.0);
	    glVertex3f(119.17, 0.56, 0.0);
	    glVertex3f(119.05, 0.33, 0.0);
	    glVertex3f(119.0, 0.08, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    	glVertex3f(0.08, 0.99, 0.0);
    	glVertex3f(0.25, 0.97, 0.0);
    	glVertex3f(0.49, 0.87, 0.0);
    	glVertex3f(0.70, 0.71, 0.0);
    	glVertex3f(0.86, 0.51, 0.0);
    	glVertex3f(0.96, 0.27, 0.0);
    	glVertex3f(0.99, 0.08, 0.0);
    glEnd();
    
    //Circulos Pequeños de Penal y de Saque Inicial
    glBegin(GL_POLYGON);
   		glVertex3f(11.0, 45.0, 0.0);
   		for(int count=0; count<=360; count++){
   			glVertex3f(11.0 + sin((float)count) * 0.5, 45.0 + cos((float)count) * 0.5, 0.0);	
		}
	glEnd();
	glBegin(GL_POLYGON);
   		glVertex3f(109.0, 45.0, 0.0);
   		for(int count=0; count<=360; count++){
   			glVertex3f(109.0 + sin((float)count) * 0.5, 45.0 + cos((float)count) * 0.5, 0.0);	
		}	
	glEnd();
	glBegin(GL_POLYGON);
   		glVertex3f(60.0, 45.0, 0.0);
   		for(int count=0; count<=360; count++){
   			glVertex3f(60.0 + sin((float)count) * 0.5, 45.0 + cos((float)count) * 0.5, 0.0);	
		}	
	glEnd();
	
	//Circulo Grande Central
	float radio=9.01, calx, caly;
	glPointSize(2.5);
	glBegin(GL_POINTS);
   		for (float count=0.0; count<10; count+=0.001){
   			calx=radio*cos(count);
   			caly=radio*sin(count);
   			glVertex3f(calx+60, caly+45, 0.0);
		}	
	glEnd(); 
}

void Lineas_de_Pista_Atletica(){
	glColor3f(1.0,1.0,1.0);
    glLineWidth(2.5);

	glBegin(GL_LINES);
		glVertex3f(-2.68, 98.25, 0.0);
		glVertex3f(122.68, 98.25, 0.0);
		glVertex3f(-2.34, 97.25, 0.0);
		glVertex3f(122.34, 97.25, 0.0);
		glVertex3f(-2.01, 96.25, 0.0);
		glVertex3f(122.01, 96.25, 0.0);
		glVertex3f(-1.67, 95.25, 0.0);
		glVertex3f(121.67, 95.25, 0.0);
		glVertex3f(-1.34, 94.25, 0.0);
		glVertex3f(121.34, 94.25, 0.0);
		glVertex3f(-1.00, 93.25, 0.0);
		glVertex3f(121.00, 93.25, 0.0);
		glVertex3f(-0.67, 92.25, 0.0);
		glVertex3f(120.67, 92.25, 0.0);
		glVertex3f(-0.33, 91.25, 0.0);
		glVertex3f(120.33, 91.25, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
		glVertex3f(-0.33, -1.25, 0.0);
		glVertex3f(120.33, -1.25, 0.0);
		glVertex3f(-0.67, -2.25, 0.0);
		glVertex3f(120.67, -2.25, 0.0);
		glVertex3f(-1.00, -3.25, 0.0);
		glVertex3f(121.00, -3.25, 0.0);
		glVertex3f(-1.34, -4.25, 0.0);
		glVertex3f(121.34, -4.25, 0.0);
		glVertex3f(-1.67, -5.25, 0.0);
		glVertex3f(121.67, -5.25, 0.0);
		glVertex3f(-2.01, -6.25, 0.0);
		glVertex3f(122.01, -6.25, 0.0);
		glVertex3f(-2.34, -7.25, 0.0);
		glVertex3f(122.34, -7.25, 0.0);
		glVertex3f(-2.68, -8.25, 0.0);
		glVertex3f(122.68, -8.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-2.68, 98.25, 0.0);
    	glVertex3f(-12.53, 90.83, 0.0);
    	glVertex3f(-19.62, 83.32, 0.0);
    	glVertex3f(-25.36, 74.73, 0.0);
    	glVertex3f(-29.58, 65.30, 0.0);
    	glVertex3f(-32.16, 55.30, 0.0);
    	glVertex3f(-33.03, 45.00, 0.0);
    	glVertex3f(-32.16, 34.70, 0.0);
    	glVertex3f(-29.58, 24.70, 0.0);
    	glVertex3f(-25.36, 15.27, 0.0);
    	glVertex3f(-19.62, 6.68, 0.0);
    	glVertex3f(-12.53, -0.83, 0.0);
    	glVertex3f(-2.68, -8.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-2.34, 97.25, 0.0);
    	glVertex3f(-11.86, 90.08, 0.0);
    	glVertex3f(-18.84, 82.70, 0.0);
    	glVertex3f(-24.48, 74.25, 0.0);
    	glVertex3f(-28.63, 64.97, 0.0);
    	glVertex3f(-31.17, 55.13, 0.0);
    	glVertex3f(-32.02, 45.00, 0.0);
    	glVertex3f(-31.17, 34.87, 0.0);
    	glVertex3f(-28.63, 25.03, 0.0);
    	glVertex3f(-24.48, 15.75, 0.0);
    	glVertex3f(-18.84, 7.30, 0.0);
    	glVertex3f(-11.86, -0.08, 0.0);
		glVertex3f(-2.34, -7.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-2.01, 96.25, 0.0);
    	glVertex3f(-11.19, 89.34, 0.0);
    	glVertex3f(-18.05, 82.07, 0.0);
    	glVertex3f(-23.60, 73.76, 0.0);
    	glVertex3f(-27.69, 64.64, 0.0);
    	glVertex3f(-30.18, 54.96, 0.0);
    	glVertex3f(-31.02, 45.00, 0.0);
    	glVertex3f(-30.18, 35.04, 0.0);
    	glVertex3f(-27.69, 25.36, 0.0);
    	glVertex3f(-23.60, 16.24, 0.0);
    	glVertex3f(-18.05, 7.93, 0.0);
    	glVertex3f(-11.19, 0.66, 0.0);
		glVertex3f(-2.01, -6.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-1.67, 95.25, 0.0);
    	glVertex3f(-10.52, 88.59, 0.0);
    	glVertex3f(-17.27, 81.45, 0.0);
    	glVertex3f(-22.73, 73.27, 0.0);
    	glVertex3f(-26.74, 64.31, 0.0);
    	glVertex3f(-29.19, 54.79, 0.0);
    	glVertex3f(-30.02, 45.00, 0.0);
    	glVertex3f(-29.19, 35.21, 0.0);
    	glVertex3f(-26.74, 25.69, 0.0);
    	glVertex3f(-22.73, 16.73, 0.0);
    	glVertex3f(-17.27, 8.55, 0.0);
    	glVertex3f(-10.52, 1.41, 0.0);
		glVertex3f(-1.67, -5.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-1.34, 94.25, 0.0);
    	glVertex3f(-9.85, 87.84, 0.0);
    	glVertex3f(-16.48, 80.82, 0.0);
    	glVertex3f(-21.85, 72.79, 0.0);
    	glVertex3f(-25.79, 63.97, 0.0);
    	glVertex3f(-28.20, 54.62, 0.0);
    	glVertex3f(-29.01, 45.00, 0.0);
    	glVertex3f(-28.20, 35.38, 0.0);
    	glVertex3f(-25.79, 26.03, 0.0);
    	glVertex3f(-21.85, 17.21, 0.0);
    	glVertex3f(-16.48, 9.18, 0.0);
    	glVertex3f(-9.85, 2.16, 0.0);
		glVertex3f(-1.34, -4.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-1.00, 93.25, 0.0);
    	glVertex3f(-9.18, 87.09, 0.0);
    	glVertex3f(-15.70, 80.19, 0.0);
    	glVertex3f(-20.97, 72.30, 0.0);
    	glVertex3f(-24.84, 63.64, 0.0);
    	glVertex3f(-27.21, 54.45, 0.0);
    	glVertex3f(-28.01, 45.00, 0.0);
    	glVertex3f(-27.21, 35.55, 0.0);
    	glVertex3f(-24.84, 26.36, 0.0);
    	glVertex3f(-20.97, 17.70, 0.0);
    	glVertex3f(-15.70, 9.81, 0.0);
    	glVertex3f(-9.18, 2.91, 0.0);
		glVertex3f(-1.00, -3.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-0.67, 92.25, 0.0);
    	glVertex3f(-8.51, 86.34, 0.0);
    	glVertex3f(-14.91, 79.57, 0.0);
    	glVertex3f(-20.09, 71.82, 0.0);
    	glVertex3f(-23.90, 63.31, 0.0);
    	glVertex3f(-26.22, 54.29, 0.0);
    	glVertex3f(-27.01, 45.00, 0.0);
    	glVertex3f(-26.22, 35.71, 0.0);
    	glVertex3f(-23.90, 26.69, 0.0);
    	glVertex3f(-20.09, 18.18, 0.0);
    	glVertex3f(-14.91, 10.43, 0.0);
    	glVertex3f(-8.51, 3.66, 0.0);
		glVertex3f(-0.67, -2.25, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    	glVertex3f(-0.33, 91.25, 0.0);
    	glVertex3f(-7.84, 85.59, 0.0);
    	glVertex3f(-14.13, 78.94, 0.0);
    	glVertex3f(-19.21, 71.33, 0.0);
    	glVertex3f(-22.95, 62.98, 0.0);
    	glVertex3f(-25.23, 54.12, 0.0);
    	glVertex3f(-26.00, 45.00, 0.0);
    	glVertex3f(-25.23, 35.88, 0.0);
    	glVertex3f(-22.95, 27.02, 0.0);
    	glVertex3f(-19.21, 18.67, 0.0);
    	glVertex3f(-14.13, 11.06, 0.0);
    	glVertex3f(-7.84, 4.41, 0.0);
		glVertex3f(-0.33, -1.25, 0.0);
    glEnd();
    

    glBegin(GL_LINE_STRIP);
    	glVertex3f(122.68, 98.25, 0.0);
    	glVertex3f(132.53, 90.83, 0.0);
    	glVertex3f(139.62, 83.32, 0.0);
    	glVertex3f(145.36, 74.73, 0.0);
    	glVertex3f(149.58, 65.30, 0.0);
    	glVertex3f(152.16, 55.30, 0.0);
    	glVertex3f(153.03, 45.00, 0.0);
    	glVertex3f(152.16, 34.70, 0.0);
    	glVertex3f(149.58, 24.70, 0.0);
    	glVertex3f(145.36, 15.27, 0.0);
    	glVertex3f(139.62, 6.68, 0.0);
    	glVertex3f(132.53, -0.83, 0.0);
		glVertex3f(122.68, -8.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(122.34, 97.25, 0.0);
    	glVertex3f(131.86, 90.08, 0.0);
    	glVertex3f(138.84, 82.70, 0.0);
    	glVertex3f(144.48, 74.25, 0.0);
    	glVertex3f(148.63, 64.97, 0.0);
    	glVertex3f(151.17, 55.13, 0.0);
    	glVertex3f(152.02, 45.00, 0.0);
    	glVertex3f(151.17, 34.87, 0.0);
    	glVertex3f(148.63, 25.03, 0.0);
    	glVertex3f(144.48, 15.75, 0.0);
    	glVertex3f(138.84, 7.30, 0.0);
    	glVertex3f(131.86, -0.08, 0.0);
		glVertex3f(122.34, -7.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(122.01, 96.25, 0.0);
    	glVertex3f(131.19, 89.34, 0.0);
    	glVertex3f(138.05, 82.07, 0.0);
    	glVertex3f(143.60, 73.76, 0.0);
    	glVertex3f(147.69, 64.64, 0.0);
    	glVertex3f(150.18, 54.96, 0.0);
    	glVertex3f(151.02, 45.00, 0.0);
    	glVertex3f(150.18, 35.04, 0.0);
    	glVertex3f(147.69, 25.36, 0.0);
    	glVertex3f(143.60, 16.24, 0.0);
    	glVertex3f(138.05, 7.93, 0.0);
    	glVertex3f(131.19, 0.66, 0.0);
		glVertex3f(122.01, -6.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(121.67, 95.25, 0.0);
    	glVertex3f(130.52, 88.59, 0.0);
    	glVertex3f(137.27, 81.45, 0.0);
    	glVertex3f(142.73, 73.27, 0.0);
    	glVertex3f(146.74, 64.31, 0.0);
    	glVertex3f(149.19, 54.79, 0.0);
    	glVertex3f(150.02, 45.00, 0.0);
    	glVertex3f(149.19, 35.21, 0.0);
    	glVertex3f(146.74, 25.69, 0.0);
    	glVertex3f(142.73, 16.73, 0.0);
    	glVertex3f(137.27, 8.55, 0.0);
    	glVertex3f(130.52, 1.41, 0.0);
		glVertex3f(121.67, -5.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(121.34, 94.25, 0.0);
    	glVertex3f(129.85, 87.84, 0.0);
    	glVertex3f(136.48, 80.82, 0.0);
    	glVertex3f(141.85, 72.79, 0.0);
    	glVertex3f(145.79, 63.97, 0.0);
    	glVertex3f(148.20, 54.62, 0.0);
    	glVertex3f(149.01, 45.00, 0.0);
    	glVertex3f(148.20, 35.38, 0.0);
    	glVertex3f(145.79, 26.03, 0.0);
    	glVertex3f(141.85, 17.21, 0.0);
    	glVertex3f(136.48, 9.18, 0.0);
    	glVertex3f(129.85, 2.16, 0.0);
		glVertex3f(121.34, -4.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(121.00, 93.25, 0.0);
    	glVertex3f(129.18, 87.09, 0.0);
    	glVertex3f(135.70, 80.19, 0.0);
    	glVertex3f(140.97, 72.30, 0.0);
    	glVertex3f(144.84, 63.64, 0.0);
    	glVertex3f(147.21, 54.45, 0.0);
    	glVertex3f(148.01, 45.00, 0.0);
    	glVertex3f(147.21, 35.55, 0.0);
    	glVertex3f(144.84, 26.36, 0.0);
    	glVertex3f(140.97, 17.70, 0.0);
    	glVertex3f(135.70, 9.81, 0.0);
    	glVertex3f(129.18, 2.91, 0.0);
		glVertex3f(121.00, -3.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(120.67, 92.25, 0.0);
    	glVertex3f(128.51, 86.34, 0.0);
    	glVertex3f(134.91, 79.57, 0.0);
    	glVertex3f(140.09, 71.82, 0.0);
    	glVertex3f(143.90, 63.31, 0.0);
    	glVertex3f(146.22, 54.29, 0.0);
    	glVertex3f(147.01, 45.00, 0.0);
    	glVertex3f(146.22, 35.71, 0.0);
    	glVertex3f(143.90, 26.69, 0.0);
    	glVertex3f(140.09, 18.18, 0.0);
    	glVertex3f(134.91, 10.43, 0.0);
    	glVertex3f(128.51, 3.66, 0.0);
		glVertex3f(120.67, -2.25, 0.0);
    glEnd();
	
	glBegin(GL_LINE_STRIP);
    	glVertex3f(120.33, 91.25, 0.0);
    	glVertex3f(127.84, 85.59, 0.0);
    	glVertex3f(134.13, 78.94, 0.0);
    	glVertex3f(139.21, 71.33, 0.0);
    	glVertex3f(142.95, 62.98, 0.0);
    	glVertex3f(145.23, 54.12, 0.0);
    	glVertex3f(146.00, 45.00, 0.0);
    	glVertex3f(145.23, 35.88, 0.0);
    	glVertex3f(142.95, 27.02, 0.0);
    	glVertex3f(139.21, 18.67, 0.0);
    	glVertex3f(134.13, 11.06, 0.0);
    	glVertex3f(127.84, 4.41, 0.0);
		glVertex3f(120.33, -1.25, 0.0);
    glEnd();
}

void Cercado_Cilindros(){
	
	glPushMatrix();
    glTranslatef(-3.01, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-3.01, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-3.01 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-13.20, 91.58, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-13.20, 91.58, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-13.20 + sin((float)count) * 0.1, 91.58 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-20.41, 83.95, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-20.41, 83.95, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-20.41 + sin((float)count) * 0.1, 83.95 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-26.24, 75.22, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-26.24, 75.22, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-26.24 + sin((float)count) * 0.1, 75.22 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-30.53, 65.63, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-30.53, 65.63, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-30.53 + sin((float)count) * 0.1, 65.63 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-33.15, 55.46, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-33.15, 55.46, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-33.15 + sin((float)count) * 0.1, 55.46 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-34.03, 45.00, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-34.03, 45.00, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-34.03 + sin((float)count) * 0.1, 45.00 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-33.15, 34.54, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-33.15, 34.54, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-33.15 + sin((float)count) * 0.1, 34.54 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-30.53, 24.37, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-30.53, 24.37, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-30.53 + sin((float)count) * 0.1, 24.37 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-26.24, 14.78, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-26.24, 14.78, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-26.24 + sin((float)count) * 0.1, 14.78 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-20.41, 6.05, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-20.41, 6.05, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-20.41 + sin((float)count) * 0.1, 6.05 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-13.20, -1.58, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-13.20, -1.58, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-13.20 + sin((float)count) * 0.1, -1.58 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(-3.01, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(-3.01, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(-3.01 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(123.01, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(123.01, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(123.01 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(133.20, 91.58, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(133.20, 91.58, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(133.20 + sin((float)count) * 0.1, 91.58 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(140.41, 83.95, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(140.41, 83.95, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(140.41 + sin((float)count) * 0.1, 83.95 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(146.24, 75.22, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(146.24, 75.22, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(146.24 + sin((float)count) * 0.1, 75.22 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(150.53, 65.63, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(150.53, 65.63, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(150.53 + sin((float)count) * 0.1, 65.63 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(153.15, 55.46, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(153.15, 55.46, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(153.15 + sin((float)count) * 0.1, 55.46 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(154.03, 45.00, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(154.03, 45.00, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(154.03 + sin((float)count) * 0.1, 45.00 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(153.15, 34.54, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(153.15,  34.54, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(153.15 + sin((float)count) * 0.1, 34.54 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(150.53, 24.37, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(150.53, 24.37, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(150.53 + sin((float)count) * 0.1, 24.37 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(146.24, 14.78, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(146.24, 14.78, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(146.24 + sin((float)count) * 0.1, 14.78 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(140.41, 6.05, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(140.41, 6.05, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(140.41 + sin((float)count) * 0.1, 6.05 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(133.20, -1.58, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(133.20, -1.58, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(133.20 + sin((float)count) * 0.1, -1.58 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(123.01, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(123.01, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(123.01 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(17.09, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(17.09, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(17.09 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(22.51, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(22.51, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(22.51 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(42.61, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(42.61, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(42.61 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(62.71, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(62.71, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(62.71 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(82.81, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(82.81, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(82.81 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(102.91, 99.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(102.91, 99.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(102.91 + sin((float)count) * 0.1, 99.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(17.09, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(17.09, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(17.09 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(37.19, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(37.19, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(37.19 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(57.24, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(57.24, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(57.24 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(62.71, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(62.71, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(62.71 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(82.81, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(82.81, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(82.81 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	/*---------------------------------------------------------------------*/
	glPushMatrix();
    glTranslatef(102.91, -9.25, 0.0);
    Crear_Cilindros();
	glPopMatrix();
    glBegin(GL_POLYGON);
   		glVertex3f(102.91, -9.25, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(102.91 + sin((float)count) * 0.1, -9.25 + cos((float)count) * 0.1, 1.5);	
		}
	glEnd();
	
	
    
}

void Banca_Grande(){
	
	//Piso de la banca
	glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(116.99, 101.25, 0.00);
	    glVertex3f(116.99, 119.25, 0.00);
	    glVertex3f(-3.01, 119.25, 0.00);
	    glVertex3f(-3.01, 101.25, 0.00);
    glEnd();
    
    
	//Primer escalon 1 cara lateral
	glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(-3.01, 101.75, 0.00);
	    glVertex3f(-3.01, 100.75, 0.00);
	    glVertex3f(-3.01, 100.75, 1.40);
	    glVertex3f(-3.01, 101.75, 1.40);
    glEnd();
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.25, 0.00);
	    glVertex3f(-3.01, 101.75, 0.00);
	    glVertex3f(-3.01, 101.75, 1.80);
	    glVertex3f(-3.01, 102.25, 1.80);
    glEnd();
    
    //Primer Escalon 2 Cara Lateral
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(116.99, 101.75, 0.00);
	    glVertex3f(116.99, 100.75, 0.00);
	    glVertex3f(116.99, 100.75, 1.40);
	    glVertex3f(116.99, 101.75, 1.40);
    glEnd();
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(116.99, 102.25, 0.00);
	    glVertex3f(116.99, 101.75, 0.00);
	    glVertex3f(116.99, 101.75, 1.80);
	    glVertex3f(116.99, 102.25, 1.80);
    glEnd();
    
    //Segundo escalon 1 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.75, 2.20);
	    glVertex3f(-3.01, 102.75, 1.80);
	    glVertex3f(-3.01, 102.25, 1.80);
	    glVertex3f(-3.01, 102.25, 2.20);
    glEnd();
    
    //Segundo Escalon 2 Cara Lateral
    glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
		glVertex3f(116.99, 102.25, 2.20);
		glVertex3f(116.99, 102.25, 1.80);
	    glVertex3f(116.99, 102.75, 1.80);
	    glVertex3f(116.99, 102.75, 2.20);
    glEnd();
    
    //Tercer escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 103.25, 2.60);
	    glVertex3f(-3.01, 103.25, 2.20);
	    glVertex3f(-3.01, 102.75, 2.20);
	    glVertex3f(-3.01, 102.75, 2.60);
    glEnd();
    
    //Tercer escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 103.25, 2.60);
	    glVertex3f(116.99, 103.25, 2.20);
	    glVertex3f(116.99, 102.75, 2.20);
	    glVertex3f(116.99, 102.75, 2.60);
    glEnd();
    
    //Cuarto escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 103.75, 3.00);
	    glVertex3f(-3.01, 103.75, 2.60);
	    glVertex3f(-3.01, 103.25, 2.60);
	    glVertex3f(-3.01, 103.25, 3.00);
    glEnd();
    
    //Cuarto escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 103.75, 3.00);
	    glVertex3f(116.99, 103.75, 2.60);
	    glVertex3f(116.99, 103.25, 2.60);
	    glVertex3f(116.99, 103.25, 3.00);
    glEnd();
    /*
    	float posy1=103.75;
    	float posy2=103.25;
    	float posz1=3.00;
    	float posz2=2.60;
    	float posy11=posy1 +0.5;
    	float posy12=posy2 +0.5;
    	float posz11=posz1 +0.4;
    	float posz12=posz2 +0.4;
    for(int i=0;i<33;i++)
    {
    
    	glColor3f(1.00,1.00,1.00);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, posy11, posz11);
	    glVertex3f(-3.01, posy11, posz12);
	    glVertex3f(-3.01, posy12, posz12);
	    glVertex3f(-3.01, posy12, posz11);
    	glEnd();
    	posy11=posy11 +0.5;
    	posy12=posy12 +0.5;
    	posz11=posz11 +0.4;
    	posz12=posz12 +0.4;
    
	}
    */
    //Quinto escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 104.25, 3.40);
	    glVertex3f(-3.01, 104.25, 3.00);
	    glVertex3f(-3.01, 103.75, 3.00);
	    glVertex3f(-3.01, 103.75, 3.40);
    glEnd();
    
    //Quinto escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 104.25, 3.40);
	    glVertex3f(116.99, 104.25, 3.00);
	    glVertex3f(116.99, 103.75, 3.00);
	    glVertex3f(116.99, 103.75, 3.40);
    glEnd();
    
    //Sexto escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 104.75, 3.80);
	    glVertex3f(-3.01, 104.75, 3.40);
	    glVertex3f(-3.01, 104.25, 3.40);
	    glVertex3f(-3.01, 104.25, 3.80);
    glEnd();
    
    //Sexto escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 104.75, 3.80);
	    glVertex3f(116.99, 104.75, 3.40);
	    glVertex3f(116.99, 104.25, 3.40);
	    glVertex3f(116.99, 104.25, 3.80);
    glEnd();
    
    //Septimo escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 105.25, 4.20);
	    glVertex3f(-3.01, 105.25, 3.80);
	    glVertex3f(-3.01, 104.75, 3.80);
	    glVertex3f(-3.01, 104.75, 4.20);
    glEnd();
    
    //Septimo escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 105.25, 4.20);
	    glVertex3f(116.99, 105.25, 3.80);
	    glVertex3f(116.99, 104.75, 3.80);
	    glVertex3f(116.99, 104.75, 4.20);
    glEnd();
    
    //Octavo escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 105.75, 4.60);
	    glVertex3f(-3.01, 105.75, 4.20);
	    glVertex3f(-3.01, 105.25, 4.20);
	    glVertex3f(-3.01, 105.25, 4.60);
    glEnd();
    
    //Octavo escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 105.75, 4.60);
	    glVertex3f(116.99, 105.75, 4.20);
	    glVertex3f(116.99, 105.25, 4.20);
	    glVertex3f(116.99, 105.25, 4.60);
    glEnd();
    
    //Noveno escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 106.25, 5.00);
	    glVertex3f(-3.01, 106.25, 4.60);
	    glVertex3f(-3.01, 105.75, 4.60);
	    glVertex3f(-3.01, 105.75, 5.00);
    glEnd();
    
    //Noveno escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 106.25, 5.00);
	    glVertex3f(116.99, 106.25, 4.60);
	    glVertex3f(116.99, 105.75, 4.60);
	    glVertex3f(116.99, 105.75, 5.00);
    glEnd();
    
    //Decimo escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 106.75, 5.40);
	    glVertex3f(-3.01, 106.75, 5.00);
	    glVertex3f(-3.01, 106.25, 5.00);
	    glVertex3f(-3.01, 106.25, 5.40);
    glEnd();
    
    //Decimo escalon 2  cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 106.75, 5.40);
	    glVertex3f(116.99, 106.75, 5.00);
	    glVertex3f(116.99, 106.25, 5.00);
	    glVertex3f(116.99, 106.25, 5.40);
    glEnd();
    
    
    //11 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 107.25, 5.80);
	    glVertex3f(-3.01, 107.25, 5.40);
	    glVertex3f(-3.01, 106.75, 5.40);
	    glVertex3f(-3.01, 106.75, 5.80);
    glEnd();
    
    //11 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 107.25, 5.80);
	    glVertex3f(116.99, 107.25, 5.40);
	    glVertex3f(116.99, 106.75, 5.40);
	    glVertex3f(116.99, 106.75, 5.80);
    glEnd();
    
    //12 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 107.75, 6.20);
	    glVertex3f(-3.01, 107.75, 5.80);
	    glVertex3f(-3.01, 107.25, 5.80);
	    glVertex3f(-3.01, 107.25, 6.20);
    glEnd();
    
    //12 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 107.75, 6.20);
	    glVertex3f(116.99, 107.75, 5.80);
	    glVertex3f(116.99, 107.25, 5.80);
	    glVertex3f(116.99, 107.25, 6.20);
    glEnd();
    
    //13 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 108.25, 6.60);
	    glVertex3f(-3.01, 108.25, 6.20);
	    glVertex3f(-3.01, 107.75, 6.20);
	    glVertex3f(-3.01, 107.75, 6.60);
    glEnd();
    
    //13 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 108.25, 6.60);
	    glVertex3f(116.99, 108.25, 6.20);
	    glVertex3f(116.99, 107.75, 6.20);
	    glVertex3f(116.99, 107.75, 6.60);
    glEnd();
    
    //14 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 108.75, 7.00);
	    glVertex3f(-3.01, 108.75, 6.60);
	    glVertex3f(-3.01, 108.25, 6.60);
	    glVertex3f(-3.01, 108.25, 7.00);
    glEnd();
    
    //14 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 108.75, 7.00);
	    glVertex3f(116.99, 108.75, 6.60);
	    glVertex3f(116.99, 108.25, 6.60);
	    glVertex3f(116.99, 108.25, 7.00);
    glEnd();
    
    //15 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 109.25, 7.40);
	    glVertex3f(-3.01, 109.25, 7.00);
	    glVertex3f(-3.01, 108.75, 7.00);
	    glVertex3f(-3.01, 108.75, 7.40);
    glEnd();
    
    //15 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 109.25, 7.40);
	    glVertex3f(116.99, 109.25, 7.00);
	    glVertex3f(116.99, 108.75, 7.00);
	    glVertex3f(116.99, 108.75, 7.40);
    glEnd();
    
    //16 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 109.75, 7.80);
	    glVertex3f(-3.01, 109.75, 7.40);
	    glVertex3f(-3.01, 109.25, 7.40);
	    glVertex3f(-3.01, 109.25, 7.80);
    glEnd();
    
    //16 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 109.75, 7.80);
	    glVertex3f(116.99, 109.75, 7.40);
	    glVertex3f(116.99, 109.25, 7.40);
	    glVertex3f(116.99, 109.25, 7.80);
    glEnd();
    
    //17 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 110.25, 8.20);
	    glVertex3f(-3.01, 110.25, 7.80);
	    glVertex3f(-3.01, 109.75, 7.80);
	    glVertex3f(-3.01, 109.75, 8.20);
    glEnd();
    
    //17 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 110.25, 8.20);
	    glVertex3f(116.99, 110.25, 7.80);
	    glVertex3f(116.99, 109.75, 7.80);
	    glVertex3f(116.99, 109.75, 8.20);
    glEnd();
    
    //18 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 110.75, 8.60);
	    glVertex3f(-3.01, 110.75, 8.20);
	    glVertex3f(-3.01, 110.25, 8.20);
	    glVertex3f(-3.01, 110.25, 8.60);
    glEnd();
    
    //18 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 110.75, 8.60);
	    glVertex3f(116.99, 110.75, 8.20);
	    glVertex3f(116.99, 110.25, 8.20);
	    glVertex3f(116.99, 110.25, 8.60);
    glEnd();
    
    //19 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 111.25, 9.00);
	    glVertex3f(-3.01, 111.25, 8.60);
	    glVertex3f(-3.01, 110.75, 8.60);
	    glVertex3f(-3.01, 110.75, 9.00);
    glEnd();
    
    //19 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 111.25, 9.00);
	    glVertex3f(116.99, 111.25, 8.60);
	    glVertex3f(116.99, 110.75, 8.60);
	    glVertex3f(116.99, 110.75, 9.00);
    glEnd();
    
    //20 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 111.75, 9.40);
	    glVertex3f(-3.01, 111.75, 9.00);
	    glVertex3f(-3.01, 111.25, 9.00);
	    glVertex3f(-3.01, 111.25, 9.40);
    glEnd();
    
    //20 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 111.75, 9.40);
	    glVertex3f(116.99, 111.75, 9.00);
	    glVertex3f(116.99, 111.25, 9.00);
	    glVertex3f(116.99, 111.25, 9.40);
    glEnd();
    
    //Decimo escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 112.25, 9.80);
	    glVertex3f(-3.01, 112.25, 9.40);
	    glVertex3f(-3.01, 111.75, 9.40);
	    glVertex3f(-3.01, 111.75, 9.80);
    glEnd();
    
    //Decimo escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 112.25, 9.80);
	    glVertex3f(116.99, 112.25, 9.40);
	    glVertex3f(116.99, 111.75, 9.40);
	    glVertex3f(116.99, 111.75, 9.80);
    glEnd();
    
    //21 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 112.75, 10.20);
	    glVertex3f(-3.01, 112.75, 9.80);
	    glVertex3f(-3.01, 112.25, 9.80);
	    glVertex3f(-3.01, 112.25, 10.20);
    glEnd();
    
    //21 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 112.75, 10.20);
	    glVertex3f(116.99, 112.75, 9.80);
	    glVertex3f(116.99, 112.25, 9.80);
	    glVertex3f(116.99, 112.25, 10.20);
    glEnd();
    
    //22 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 113.25, 10.60);
	    glVertex3f(-3.01, 113.25, 10.20);
	    glVertex3f(-3.01, 112.75, 10.20);
	    glVertex3f(-3.01, 112.75, 10.60);
    glEnd();
    
    //22 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 113.25, 10.60);
	    glVertex3f(116.99, 113.25, 10.20);
	    glVertex3f(116.99, 112.75, 10.20);
	    glVertex3f(116.99, 112.75, 10.60);
    glEnd();
    
    //23 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 113.75, 11.00);
	    glVertex3f(-3.01, 113.75, 10.60);
	    glVertex3f(-3.01, 113.25, 10.60);
	    glVertex3f(-3.01, 113.25, 11.00);
    glEnd();
    
    //23 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 113.75, 11.00);
	    glVertex3f(116.99, 113.75, 10.60);
	    glVertex3f(116.99, 113.25, 10.60);
	    glVertex3f(116.99, 113.25, 11.00);
    glEnd();
    
    //24 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 114.25, 11.40);
	    glVertex3f(-3.01, 114.25, 11.00);
	    glVertex3f(-3.01, 113.75, 11.00);
	    glVertex3f(-3.01, 113.75, 11.40);
    glEnd();
    
    //24 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 114.25, 11.40);
	    glVertex3f(116.99, 114.25, 11.00);
	    glVertex3f(116.99, 113.75, 11.00);
	    glVertex3f(116.99, 113.75, 11.40);
    glEnd();
    
    //25 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 114.75, 11.80);
	    glVertex3f(-3.01, 114.75, 11.40);
	    glVertex3f(-3.01, 114.25, 11.40);
	    glVertex3f(-3.01, 114.25, 11.80);
    glEnd();
    
    //25 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 114.75, 11.80);
	    glVertex3f(116.99, 114.75, 11.40);
	    glVertex3f(116.99, 114.25, 11.40);
	    glVertex3f(116.99, 114.25, 11.80);
    glEnd();
    
    //26 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 115.25, 12.20);
	    glVertex3f(-3.01, 115.25, 11.80);
	    glVertex3f(-3.01, 114.75, 11.80);
	    glVertex3f(-3.01, 114.75, 12.20);
    glEnd();
    
    //26 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 115.25, 12.20);
	    glVertex3f(116.99, 115.25, 11.80);
	    glVertex3f(116.99, 114.75, 11.80);
	    glVertex3f(116.99, 114.75, 12.20);
    glEnd();
    
    //27 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 115.75, 12.60);
	    glVertex3f(-3.01, 115.75, 12.20);
	    glVertex3f(-3.01, 115.25, 12.20);
	    glVertex3f(-3.01, 115.25, 12.60);
    glEnd();
    
    //27 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 115.75, 12.60);
	    glVertex3f(116.99, 115.75, 12.20);
	    glVertex3f(116.99, 115.25, 12.20);
	    glVertex3f(116.99, 115.25, 12.60);
    glEnd();
    
    //28 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 116.25, 13.00);
	    glVertex3f(-3.01, 116.25, 12.60);
	    glVertex3f(-3.01, 115.75, 12.60);
	    glVertex3f(-3.01, 115.75, 13.00);
    glEnd();
    
    //28 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 116.25, 13.00);
	    glVertex3f(116.99, 116.25, 12.60);
	    glVertex3f(116.99, 115.75, 12.60);
	    glVertex3f(116.99, 115.75, 13.00);
    glEnd();
    
    //29 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 116.75, 13.40);
	    glVertex3f(-3.01, 116.75, 13.00);
	    glVertex3f(-3.01, 116.25, 13.00);
	    glVertex3f(-3.01, 116.25, 13.40);
    glEnd();
    
    //29 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 116.75, 13.40);
	    glVertex3f(116.99, 116.75, 13.00);
	    glVertex3f(116.99, 116.25, 13.00);
	    glVertex3f(116.99, 116.25, 13.40);
    glEnd();
    
    //30 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 117.25, 13.80);
	    glVertex3f(-3.01, 117.25, 13.40);
	    glVertex3f(-3.01, 116.75, 13.40);
	    glVertex3f(-3.01, 116.75, 13.80);
    glEnd();
    
    //30 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 117.25, 13.80);
	    glVertex3f(116.99, 117.25, 13.40);
	    glVertex3f(116.99, 116.75, 13.40);
	    glVertex3f(116.99, 116.75, 13.80);
    glEnd();
    
    //31 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 117.75, 14.20);
	    glVertex3f(-3.01, 117.75, 13.80);
	    glVertex3f(-3.01, 117.25, 13.80);
	    glVertex3f(-3.01, 117.25, 14.20);
    glEnd();
    
    //31 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 117.75, 14.20);
	    glVertex3f(116.99, 117.75, 13.80);
	    glVertex3f(116.99, 117.25, 13.80);
	    glVertex3f(116.99, 117.25, 14.20);
    glEnd();
    
    //32 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 118.25, 14.60);
	    glVertex3f(-3.01, 118.25, 14.20);
	    glVertex3f(-3.01, 117.75, 14.20);
	    glVertex3f(-3.01, 117.75, 14.60);
    glEnd();
    
    //32 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 118.25, 14.60);
	    glVertex3f(116.99, 118.25, 14.20);
	    glVertex3f(116.99, 117.75, 14.20);
	    glVertex3f(116.99, 117.75, 14.60);
    glEnd();
    
    //33 escalon cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 118.75, 15.00);
	    glVertex3f(-3.01, 118.75, 14.60);
	    glVertex3f(-3.01, 118.25, 14.60);
	    glVertex3f(-3.01, 118.25, 15.00);
    glEnd();
    
    //33 escalon 2 cara lateral
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_QUADS);
	    glVertex3f(116.99, 118.75, 15.00);
	    glVertex3f(116.99, 118.75, 14.60);
	    glVertex3f(116.99, 118.25, 14.60);
	    glVertex3f(116.99, 118.25, 15.00);
    glEnd();
 	
 	//CARAS FRONTALES
 	
 	//1 lado izq
 	glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 100.75, 1.40);
	    glVertex3f(-3.01, 101.75, 1.40);
	    glVertex3f(50.99, 101.75, 1.40);
	    glVertex3f(50.99, 100.75, 1.40);
    glEnd();
    
    //1 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 100.75, 1.80);
	    glVertex3f(62.99, 102.25, 1.80);
	    glVertex3f(116.99, 102.25, 1.80);
	    glVertex3f(116.99, 100.75, 1.80);
    glEnd();
    
    //2 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 101.75, 1.80);
	    glVertex3f(-3.01, 102.25, 1.80);
	    glVertex3f(50.99, 102.25, 1.80);
	    glVertex3f(50.99, 101.75, 1.80);
    glEnd();
   
    //2 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 102.25, 2.20);
	    glVertex3f(62.99, 102.75, 2.20);
	    glVertex3f(116.99, 102.75, 2.20);
	    glVertex3f(116.99, 102.25, 2.20);
    glEnd();
    
    //3 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.25, 2.20);
	    glVertex3f(-3.01, 102.75, 2.20);
	    glVertex3f(50.99, 102.75, 2.20);
	    glVertex3f(50.99, 102.25, 2.20);
    glEnd();
    
    //3 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 102.75, 2.20);
	    glVertex3f(62.99, 103.25, 2.20);
	    glVertex3f(116.99, 103.25, 2.20);
	    glVertex3f(116.99, 102.75, 2.20);
    glEnd();
    
    
    //4 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.75, 2.60);
	    glVertex3f(-3.01, 103.25, 2.60);
	    glVertex3f(50.99, 103.25, 2.60);
	    glVertex3f(50.99, 102.75, 2.60);
    glEnd();
    
    //4 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 102.75, 2.60);
	    glVertex3f(62.99, 103.25, 2.60);
	    glVertex3f(116.99, 103.25, 2.60);
	    glVertex3f(116.99, 102.75, 2.60);
    glEnd();
    
    //5 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 103.25, 3.00);
	    glVertex3f(-3.01, 103.75, 3.00);
	    glVertex3f(50.99, 103.75, 3.00);
	    glVertex3f(50.99, 103.25, 3.00);
    glEnd();
    
    //5 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 103.25, 3.00);
	    glVertex3f(62.99, 103.75, 3.00);
	    glVertex3f(116.99, 103.75, 3.00);
	    glVertex3f(116.99, 103.25, 3.00);
    glEnd();
    
    //6 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 103.75, 3.40);
	    glVertex3f(-3.01, 104.25, 3.40);
	    glVertex3f(50.99, 104.25, 3.40);
	    glVertex3f(50.99, 103.75, 3.40);
    glEnd();
    
    //6 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 103.75, 3.40);
	    glVertex3f(62.99, 104.25, 3.40);
	    glVertex3f(116.99, 104.25, 3.40);
	    glVertex3f(116.99, 103.75, 3.40);
    glEnd();
    
    //7 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 104.25, 3.80);
	    glVertex3f(-3.01, 104.75, 3.80);
	    glVertex3f(50.99, 104.75, 3.80);
	    glVertex3f(50.99, 104.25, 3.80);
    glEnd();
    
    //7 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 104.25, 3.80);
	    glVertex3f(62.99, 104.75, 3.80);
	    glVertex3f(116.99, 104.75, 3.80);
	    glVertex3f(116.99, 104.25, 3.80);
    glEnd();
    
    //8 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 104.75, 4.20);
	    glVertex3f(-3.01, 105.25, 4.20);
	    glVertex3f(50.99, 105.25, 4.20);
	    glVertex3f(50.99, 104.75, 4.20);
    glEnd();
    
    //8 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 104.75, 4.20);
	    glVertex3f(62.99, 105.25, 4.20);
	    glVertex3f(116.99, 105.25, 4.20);
	    glVertex3f(116.99, 104.75, 4.20);
    glEnd();
    
    //9 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 105.25, 4.60);
	    glVertex3f(-3.01, 105.75, 4.60);
	    glVertex3f(50.99, 105.75, 4.60);
	    glVertex3f(50.99, 105.25, 4.60);
    glEnd();
    
    //9 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 105.25, 4.60);
	    glVertex3f(62.99, 105.75, 4.60);
	    glVertex3f(116.99, 105.75, 4.60);
	    glVertex3f(116.99, 105.25, 4.60);
    glEnd();
    
    //10 lado izq
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 105.75, 5.00);
	    glVertex3f(-3.01, 106.25, 5.00);
	    glVertex3f(50.99, 106.25, 5.00);
	    glVertex3f(50.99, 105.75, 5.00);
    glEnd();
    
    //10 lado derecho
    glColor3f(0.67,0.69,0.80);
	glBegin(GL_QUADS);
	    glVertex3f(62.99, 105.75, 5.00);
	    glVertex3f(62.99, 106.25, 5.00);
	    glVertex3f(116.99, 106.25, 5.00);
	    glVertex3f(116.99, 105.75, 5.00);
    glEnd();
    
    float posy1=105.75;
    float posy2=106.25;
    float posz=5.00;
    float posy11=posy1 +0.5;
    float posy12=posy2 +0.5;
    float posz1=posz +0.4;

    for(int i=0;i<23;i++)
    {
    	glColor3f(0.67,0.69,0.80);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, posy11, posz1);
	    glVertex3f(-3.01, posy12, posz1);
	    glVertex3f(116.99, posy12, posz1);
	    glVertex3f(116.99, posy11, posz1);
    	glEnd();
    	posy11=posy11 +0.5;
    	posy12=posy12 +0.5;
    	posz1=posz1 +0.4;
	}
    
    //Pared bancas
    //1 IZQUIERDO
  	glColor3f(0.87,0.90,1.00);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 100.75, 0.00);
	    glVertex3f(-2.51, 100.75, 0.00);
	    glVertex3f(-2.51, 100.75, 1.40);
	    glVertex3f(-3.01, 100.75, 1.40);
    glEnd();
    glColor3f(0.87,0.90,1.00);
	glBegin(GL_QUADS);
	    glVertex3f(-2.51, 100.75, 1.00);
	    glVertex3f(50.99, 100.75, 1.00);
	    glVertex3f(50.99, 100.75, 1.40);
	    glVertex3f(-2.51, 100.75, 1.40);
    glEnd();
    
    //1 DERECHO
  	glColor3f(0.87,0.90,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(62.99, 100.75, 1.40);
	    glVertex3f(62.99, 100.75, 1.80);
	    glVertex3f(116.49, 100.75, 1.80);
	    glVertex3f(116.49, 100.75, 1.40);
    glEnd();
    glColor3f(0.87,0.90,1.00);
	glBegin(GL_QUADS);
	    glVertex3f(116.49, 100.75, 1.80);
	    glVertex3f(116.99, 100.75, 1.80);
	    glVertex3f(116.99, 100.75, 0.00);
	    glVertex3f(116.49, 100.75, 0.00);
    glEnd();
    //2
    glColor3f(0.87,0.90,1.00);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 101.75, 1.40);
	    glVertex3f(-3.01, 101.75, 1.80);
	    glVertex3f(50.99, 101.75, 1.80);
	    glVertex3f(50.99, 101.75, 1.40);
    glEnd();
    
    //3
    glColor3f(0.87,0.90,1.00);
	glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.25, 1.80);
	    glVertex3f(-3.01, 102.25, 2.20);
	    glVertex3f(50.99, 102.25, 2.20);
	    glVertex3f(50.99, 102.25, 1.80);
    glEnd();
    
    float posy_2=102.25;
    float posz_1=1.80;
    float posz_2=2.20;
    posz_1=posz_1 +0.4;
    posz_2=posz_2 +0.4;
    posy_2=posy_2 +0.5;

    for(int i=0;i<7;i++)
    {
    	glColor3f(0.87,0.90,1.00);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, posy_2, posz_1);
	    glVertex3f(-3.01, posy_2, posz_2);
	    glVertex3f(50.99, posy_2, posz_2);
	    glVertex3f(50.99, posy_2, posz_1);
    	glEnd();
    	posz_1=posz_1 +0.4;
    	posz_2=posz_2 +0.4;
    	posy_2=posy_2 +0.5;
	}
	
	float posy_3=105.75;
    float posz_3=4.60;
    float posz_4=5.00;
    posz_3=posz_3 +0.4;
    posz_4=posz_4 +0.4;
    posy_3=posy_3 +0.5;

    for(int i=0;i<25;i++)
    {
    	glColor3f(0.87,0.90,1.00);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, posy_3, posz_3);
	    glVertex3f(-3.01, posy_3, posz_4);
	    glVertex3f(116.99, posy_3, posz_4);
	    glVertex3f(116.99, posy_3, posz_3);
    	glEnd();
    	posz_3=posz_3 +0.4;
    	posz_4=posz_4 +0.4;
    	posy_3=posy_3 +0.5;
	}
	
	float posy_4=102.25;
    float posz_5=1.80;
    float posz_6=2.20;
    posz_3=posz_3 +0.4;
    posz_4=posz_4 +0.4;
    posy_3=posy_3 +0.5;

    for(int i=0;i<8;i++)
    {
    	glColor3f(0.87,0.90,1.00);
		glBegin(GL_QUADS);
	    glVertex3f(62.99, posy_4, posz_5);
	    glVertex3f(62.99, posy_4, posz_6);
	    glVertex3f(116.99, posy_4, posz_6);
	    glVertex3f(116.99, posy_4, posz_5);
    	glEnd();
    	posz_5=posz_5 +0.4;
    	posz_6=posz_6 +0.4;
    	posy_4=posy_4 +0.5;
	}
	
	//caras de atras
   /* glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.25, 1.00);
	    glVertex3f(-3.01, 102.25, 2.20);
	    glVertex3f(50.99, 102.25, 2.20);
	    glVertex3f(50.99, 102.25, 1.00);
    	glEnd();
    	
    glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, 102.75, 2.20);
	    glVertex3f(-3.01, 102.75, 2.60);
	    glVertex3f(50.99, 102.75, 2.60);
	    glVertex3f(50.99, 102.75, 2.20);
    	glEnd();*/
    
    float posz_7=1.70;
    float posz_8=2.20;
    posz_3=posz_3 +0.4;
    posz_4=posz_4 +0.4;
    posy_3=posy_3 +0.5;
    
    for(int i=0;i<8;i++)
    {
    	glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, posy_4, posz_7);
	    glVertex3f(-3.01, posy_4, posz_8);
	    glVertex3f(50.99, posy_4, posz_8);
	    glVertex3f(50.99, posy_4, posz_7);
    	glEnd();
    	
    	glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
	    glVertex3f(62.99, posy_4, posz_7);
	    glVertex3f(62.99, posy_4, posz_8);
	    glVertex3f(116.99, posy_4, posz_8);
	    glVertex3f(116.99, posy_4, posz_7);
    	glEnd();
    	posz_7=posz_7 +0.4;
    	posz_8=posz_8 +0.4;
    	posy_4=posy_4 +0.5;
	}
	
	float posy_5=106.75;
    float posz_9=5.00;
    float posz_10=5.40;
    posy_5=posy_5 +0.5;
    posz_9=posz_9 +0.4;
    posz_10=posz_10 +0.4;
    
    for(int i=0;i<22;i++)
    {
    	glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, posy_5, posz_9);
	    glVertex3f(-3.01, posy_5, posz_10);
	    glVertex3f(116.99, posy_5, posz_10);
	    glVertex3f(116.99, posy_5, posz_9);
    	glEnd();
    	posy_5=posy_5 +0.5;
    	posz_9=posz_9 +0.4;
    	posz_10=posz_10 +0.4;
    	
	}
	glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
	    glVertex3f(-3.01, 117.75, 15.00);
	    glVertex3f(-3.01, 119.25, 15.00);
	    glVertex3f(116.99, 119.25, 15.00);
	    glVertex3f(116.99, 117.75, 15.00);
    	glEnd();
	
	// pata cara lateral
	glColor3f(0.65,0.65,0.65);
		glBegin(GL_POLYGON);
		glVertex3f(-3.01, 119.25, 0.00);
	    glVertex3f(-3.01, 118.75, 0.00);
	    glVertex3f(-3.01, 118.75, 14.60);
	    glVertex3f(-3.01, 118.05, 14.60);
	    glVertex3f(-3.01, 117.05, 15.00);
	    glVertex3f(-3.01, 119.25, 15.00);
    	glEnd();
    // pata cara frontal
	glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
		glVertex3f(-2.51, 119.25, 0.00);
	    glVertex3f(-3.01, 119.25, 0.00);
	    glVertex3f(-3.01, 119.25, 15.00);
	    glVertex3f(-2.51, 119.25, 15.00);
    	glEnd();
    	
    glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
		glVertex3f(-2.51, 119.25, 14.60);
	    glVertex3f(-2.51, 119.25, 15.00);
	    glVertex3f(116.99, 119.25, 15.00);
	    glVertex3f(116.99, 119.25, 14.60);
    	glEnd();
    
    // pata cara lateral
	glColor3f(0.65,0.65,0.65);
		glBegin(GL_POLYGON);
		glVertex3f(116.99, 118.75, 0.00);
	    glVertex3f(116.99, 119.25, 0.00);
	    glVertex3f(116.99, 119.25, 15.00);
	    glVertex3f(116.99, 118.05, 15.00);
	    glVertex3f(116.99, 118.05, 14.60);
	    glVertex3f(116.99, 118.75, 14.60);
    	glEnd();
    // pata cara frontal
	glColor3f(0.65,0.65,0.65);
		glBegin(GL_QUADS);
		glVertex3f(116.99, 119.25, 0.00);
	    glVertex3f(116.49, 119.25, 0.00);
	    glVertex3f(116.49, 119.25, 15.00);
	    glVertex3f(116.99, 119.25, 15.00);
    	glEnd();
}

void Casa(){
	//triangulo derecha
	 glColor3f(10.93,0.93,0.93);
    glBegin(GL_POLYGON);
	    glVertex3f(64.64, 114.85, 18.2);
	    glVertex3f(64.64, 117.25, 19.2);
	    glVertex3f(64.64, 119.65, 18.2);
	    glVertex3f(64.64, 119.65, 18.10);
	    glVertex3f(64.64, 114.85, 18.10);
    glEnd();
    
    //techo frente
    
    glColor3f(1.00,1.00,1.00);
      glBegin(GL_QUADS);
	    glVertex3f(49.34, 117.25, 19.2);
	    glVertex3f(49.34, 114.85, 18.2);
	    glVertex3f(64.64, 114.85, 18.2);
	    glVertex3f(64.64, 117.25, 19.2);
    glEnd();
    
    //techo atras
     glColor3f(0.72,0.72,0.72);
      glBegin(GL_QUADS);
	    glVertex3f(64.64, 119.65, 18.2);
	    glVertex3f(64.64, 117.25, 19.2);
	    glVertex3f(49.34, 117.25, 19.2);
	    glVertex3f(49.34, 119.65, 18.2);
    glEnd();
    
    //triangulo izquierda
    
     glColor3f(10.93,0.93,0.93);
    glBegin(GL_POLYGON);
	    glVertex3f(49.34,119.65,18.10);
	    glVertex3f(49.34,119.65,18.20);
	    glVertex3f(49.34,117.25,19.20);
	    glVertex3f(49.34,114.85,18.20);
	    glVertex3f(49.34,114.85,18.10);
    glEnd();
    
    //pata izq
    
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,115.25,12.2);
	    glVertex3f(49.99,115.25,18.10);
	    glVertex3f(49.74,115.25,18.10);
	    glVertex3f(49.74,115.25,12.20);
    glEnd();
    
    //pata izq sobra der
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,115.25,12.60);
	    glVertex3f(49.99,115.50,12.60);
	    glVertex3f(49.99,115.50,15.00);
	    glVertex3f(49.99,115.25,15.00);
    glEnd();
   
    //pata der     
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,115.25,12.2);
	    glVertex3f(63.99,115.25,12.20);
	    glVertex3f(63.99,115.25,18.10);
	    glVertex3f(64.24,115.25,18.10);
    glEnd();
    
    //pata der sobra der
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,115.25,12.60);
	    glVertex3f(64.24,115.50,12.60);
	    glVertex3f(64.24,115.50,15.00);
	    glVertex3f(64.24,115.25,15.00);
    glEnd();
    
    
    //base inferior
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,115.25,15.00);
	    glVertex3f(63.99,115.25,15.00);
	    glVertex3f(64.24,117.75,15.00);
	    glVertex3f(49.74,117.75,15.00);
    glEnd();
    
    
    //borde inferior
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,115.25,15.0);
	    glVertex3f(49.99,115.25,16.10);
	    glVertex3f(63.99,115.25,16.10);
	    glVertex3f(63.99,115.25,15.00);
    glEnd();
    //borde superior
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,115.25,17.60);
	    glVertex3f(49.99,115.25,18.10);
	    glVertex3f(63.99,115.25,17.60);
	    glVertex3f(63.99,115.25,18.10);
    glEnd();
    
    //borde techo
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.34,114.85,18.20);
	    glVertex3f(49.34,114.85,18.10);
	    glVertex3f(64.64,114.85,18.20);
	    glVertex3f(64.64,114.85,18.10);
    glEnd();
    
    //borde techo atras
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.34,119.65,18.20);
	    glVertex3f(49.34,119.65,18.10);
	    glVertex3f(64.64,119.65,18.20);
	    glVertex3f(64.64,119.65,18.10);
    glEnd();
    
    //techo plano
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.34,114.85,18.10);
	    glVertex3f(49.34,119.65,18.10);
	    glVertex3f(64.64,114.85,18.10);
	    glVertex3f(49.34,114.85,18.10);
    glEnd();
    
    //barra izq
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(51.99,115.25,16.10);
	    glVertex3f(51.99,115.25,17.60);
	    glVertex3f(52.29,115.25,17.60);
	    glVertex3f(52.29,115.25,16.10);
    glEnd();
    //barra media
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(56.09,115.25,16.10);
	    glVertex3f(56.09,115.25,17.60);
	    glVertex3f(57.89,115.25,17.60);
	    glVertex3f(57.89,115.25,16.10);
    glEnd();
    
     //barra der
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(61.69,115.25,16.10);
	   glVertex3f(61.69,115.25,17.60);
	    glVertex3f(61.99,115.25,17.60);
	    glVertex3f(61.99,115.25,16.10);
    glEnd();
    
    //izq
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,115.25,16.10);
	   glVertex3f(49.99,115.35,16.10);
	    glVertex3f(49.99,115.35,17.60);
	    glVertex3f(49.99,115.25,17.60);
    glEnd();
    
    //izq
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,115.25,16.10);
	   glVertex3f(49.99,115.35,16.10);
	    glVertex3f(51.99,115.35,16.10);
	    glVertex3f(51.99,115.25,16.10);
    glEnd();
    
    //izq
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(51.99,115.35,16.10);
	    glVertex3f(51.99,115.25,16.10);
	    glVertex3f(51.99,115.25,17.60);
	   glVertex3f(51.99,115.35,17.60);
    glEnd();
    
    //izq
     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    
	    glVertex3f(51.99,115.25,17.60);
	   glVertex3f(51.99,115.35,17.60);
	   glVertex3f(49.99,115.35,17.60);
	    glVertex3f(49.99,115.25,17.60);
    glEnd();
    
    //med

     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(52.29,115.25,16.10);
	   glVertex3f(52.29,115.25,17.60);
	    glVertex3f(52.29,115.35,17.60);
	    glVertex3f(52.29,115.35,16.10);
    glEnd();
    
    //med
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(52.29,115.25,17.60);
	   glVertex3f(56.09,115.25,17.60);
	    glVertex3f(56.09,115.35,17.60);
	    glVertex3f(52.29,115.35,17.60);
    glEnd();
    
    //med
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(56.09,115.35,17.60);
	   glVertex3f(56.09,115.35,16.10);
	    glVertex3f(56.09,115.25,16.10);
	    glVertex3f(56.09,115.25,17.60);
    glEnd();
    
    //med
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(56.09,115.35,16.10);
	   glVertex3f(56.09,115.25,16.10);
	    glVertex3f(52.29,115.25,16.10);
	    glVertex3f(52.29,115.35,16.10);
    glEnd();
    
    //med2

     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(57.89,115.25,16.10);
	   glVertex3f(57.89,115.25,17.60);
	    glVertex3f(57.89,115.35,17.60);
	    glVertex3f(57.89,115.35,16.10);
    glEnd();
    
       //med2
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(57.89,115.25,17.60);
	   glVertex3f(57.89,115.35,17.60);
	    glVertex3f(61.69,115.35,17.60);
	    glVertex3f(61.69,115.25,17.60);
    glEnd();
    
       //med2
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(61.69,115.35,17.60);
	   glVertex3f(61.69,115.35,16.10);
	    glVertex3f(61.69,115.25,16.10);
	    glVertex3f(61.69,115.25,17.60);
    glEnd();
    
     //med2
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(61.69,115.35,16.10);
	   glVertex3f(61.69,115.25,16.10);
	    glVertex3f(57.89,115.25,16.10);
	    glVertex3f(57.89,115.35,16.10);
    glEnd();
    
    //med3

     glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(61.69,115.25,16.10);
	   glVertex3f(61.69,115.25,17.60);
	    glVertex3f(61.69,115.35,17.60);
	    glVertex3f(61.69,115.35,16.10);
    glEnd();
    //med3
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(61.69,115.25,17.60);
	   glVertex3f(61.69,115.35,17.60);
	    glVertex3f(63.99,115.35,17.60);
	    glVertex3f(63.99,115.25,17.60);
    glEnd();
    
    //med3
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(63.99,115.35,17.60);
	   glVertex3f(63.99,115.35,16.10);
	    glVertex3f(63.99,115.25,16.10);
	    glVertex3f(63.99,115.25,17.60);
    glEnd();
    
     //med3
       glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(63.99,115.35,16.10);
	   glVertex3f(63.99,115.25,16.10);
	    glVertex3f(61.99,115.25,16.10);
	    glVertex3f(61.99,115.35,16.10);
    glEnd();
    //pared izquierda
    glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,119.25,18.10);
	   glVertex3f(49.74,115.25,18.10);
	    glVertex3f(49.74,115.25,17.10);
	    glVertex3f(49.74,119.25,17.10);
    glEnd();
     //pared izquierda
      glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,118.05,17.10);
	   glVertex3f(49.74,115.25,17.10);
	    glVertex3f(49.74,115.25,15.00);
	    glVertex3f(49.74,118.05,15.00);
    glEnd();
    //pared izquierda
      glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,119.05,15.10);
	   glVertex3f(49.74,119.05,15.00);
	    glVertex3f(49.74,118.05,15.00);
	    glVertex3f(49.74,118.05,15.10);
    glEnd();
    
      //pared izquierda
      glColor3f(0.93,0.93,0.93);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,119.25,15.00);
	   glVertex3f(49.74,119.25,17.10);
	  glVertex3f(49.74,119.05,17.10);
	    glVertex3f(49.74,119.05,15.00);
    glEnd();
    
    //bordes pared izquierda
    
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,119.05,15.10);
	  glVertex3f(49.74,119.05,17.10);
	  glVertex3f(49.84,119.05,17.10);
	    glVertex3f(49.84,119.05,15.10);
    glEnd();
    
    //bordes pared izquierda
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,119.05,15.10);
	    glVertex3f(49.84,119.05,15.10);
	  glVertex3f(49.84,118.05,15.10);
	  glVertex3f(49.74,118.05,15.10);
    glEnd();
     //bordes pared izquierda
    
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
    	  glVertex3f(49.84,118.05,15.10);
	  glVertex3f(49.74,118.05,15.10);
	    glVertex3f(49.74,118.05,17.10);
	    glVertex3f(49.84,118.05,17.10);
    glEnd();
       //bordes pared izquierda
    
    glColor3f(1.00,1.00,1.00);
    
    glBegin(GL_QUADS);
    	    glVertex3f(49.74,118.05,17.10);
	    glVertex3f(49.84,118.05,17.10);
    	  glVertex3f(49.84,119.05,17.10);
	  glVertex3f(49.74,119.05,17.10);

    glEnd();
    
    /////////////////
      //bordes pared derecha
      
    
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(64.14,119.05,15.10);
	  glVertex3f(64.14,119.05,17.10);
	  glVertex3f(64.24,119.05,17.10);
	    glVertex3f(64.24,119.05,15.10);
    glEnd();
    
    //bordes pared derecha
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
	    glVertex3f(64.14,119.05,15.10);
	    glVertex3f(64.24,119.05,15.10);
	  glVertex3f(64.24,118.05,15.10);
	  glVertex3f(64.14,118.05,15.10);
    glEnd();
     //bordes pared derecha
    
    glColor3f(1.00,1.00,1.00);
    glBegin(GL_QUADS);
    	  glVertex3f(64.24,118.05,15.10);
	  glVertex3f(64.14,118.05,15.10);
	    glVertex3f(64.14,118.05,17.10);
	    glVertex3f(64.24,118.05,17.10);
    glEnd();
       //bordes pared derecha
    
    glColor3f(1.00,1.00,1.00);
    
    glBegin(GL_QUADS);
    	    glVertex3f(64.14,118.05,17.10);
	    glVertex3f(64.24,118.05,17.10);
    	  glVertex3f(64.24,119.05,17.10);
	  glVertex3f(64.14,119.05,17.10);

    glEnd();
    
    
    
    
    //pared de atras
    
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,119.25,18.10);
	   glVertex3f(64.24,119.25,15.00);
	  glVertex3f(49.74,119.25,15.00);
	    glVertex3f(49.74,119.25,18.10);
    glEnd();
    
    //pared derecha
       glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,119.25,18.10);
	   glVertex3f(64.24,115.25,18.10);
	    glVertex3f(64.24,115.25,17.10);
	    glVertex3f(64.24,119.25,17.10);
    glEnd();
    
     //pared derecha
       glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,118.15,17.10);
	   glVertex3f(64.24,118.15,15.10);
	    glVertex3f(64.24,115.25,15.10);
	    glVertex3f(64.24,115.25,17.10);
    glEnd();
   
    //pared derecha
       glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,115.25,15.00);
	    glVertex3f(64.24,119.25,15.00);
	     glVertex3f(64.24,119.25,15.10);
	     glVertex3f(64.24,115.25,15.10);
    glEnd();
  
      //pared derecha
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,119.15,15.10);
	   glVertex3f(64.24,119.15,17.10);
	  glVertex3f(64.24,119.25,17.10);
	    glVertex3f(64.24,119.25,15.10);
    glEnd();
    
    //interior1
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(61.89,115.35,18.10);
	   glVertex3f(61.89,119.15,18.10);
	  glVertex3f(61.89,119.15,17.10);
	    glVertex3f(61.89,115.35,17.10);
    glEnd();
    
      //interior1
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(61.89,118.05,15.10);
	   glVertex3f(61.89,118.05,17.10);
	  glVertex3f(61.89,115.35,17.10);
	    glVertex3f(61.89,115.35,15.10);
    glEnd();
    
    //interior1
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(61.89,119.05,15.10);
	   glVertex3f(61.89,119.15,15.10);
	  glVertex3f(61.89,119.15,17.10);
	    glVertex3f(61.89,119.05,17.10);
    glEnd();
    
    ////////////////
    //interior2
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(57.69,115.35,18.10);
	   glVertex3f(57.69,119.15,18.10);
	  glVertex3f(57.69,119.15,17.10);
	    glVertex3f(57.69,115.35,17.10);
    glEnd();
    
      //interior2
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(57.69,118.05,15.10);
	   glVertex3f(57.69,118.05,17.10);
	  glVertex3f(57.69,115.35,17.10);
	    glVertex3f(57.69,115.35,15.10);
    glEnd();
    
    //interior2
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(57.69,119.05,15.10);
	   glVertex3f(57.69,119.15,15.10);
	  glVertex3f(57.69,119.15,17.10);
	    glVertex3f(57.69,119.05,17.10);
    glEnd();
    
    //////
       //interior3
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(56.19,115.35,18.10);
	   glVertex3f(56.19,119.15,18.10);
	  glVertex3f(56.19,119.15,17.10);
	    glVertex3f(56.19,115.35,17.10);
    glEnd();
    
      //interior3
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(56.19,118.05,15.10);
	   glVertex3f(56.19,118.05,17.10);
	  glVertex3f(56.19,115.35,17.10);
	    glVertex3f(56.19,115.35,15.10);
    glEnd();
    
    //interior3
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(56.19,119.05,15.10);
	   glVertex3f(56.19,119.15,15.10);
	  glVertex3f(56.19,119.15,17.10);
	    glVertex3f(56.19,119.05,17.10);
    glEnd();
    
    
    /////////
        //interior4
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(52.19,115.35,18.10);
	   glVertex3f(52.19,119.15,18.10);
	  glVertex3f(52.19,119.15,17.10);
	    glVertex3f(52.19,115.35,17.10);
    glEnd();
    
      //interior4
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(52.19,118.05,15.10);
	   glVertex3f(52.19,118.05,17.10);
	  glVertex3f(52.19,115.35,17.10);
	    glVertex3f(52.19,115.35,15.10);
    glEnd();
    
    //interior4
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(52.19,119.05,15.10);
	   glVertex3f(52.19,119.15,15.10);
	  glVertex3f(52.19,119.15,17.10);
	    glVertex3f(52.19,119.05,17.10);
    glEnd();
    
     /////////
        //interior5
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(49.84,115.35,18.10);
	   glVertex3f(49.84,119.15,18.10);
	  glVertex3f(49.84,119.15,17.10);
	    glVertex3f(49.84,115.35,17.10);
    glEnd();
    
      //interior5
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(49.84,118.05,15.10);
	   glVertex3f(49.84,118.05,17.10);
	  glVertex3f(49.84,115.35,17.10);
	    glVertex3f(49.84,115.35,15.10);
    glEnd();
    
    //interior5
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
	    glVertex3f(49.84,119.05,15.10);
	   glVertex3f(49.84,119.15,15.10);
	  glVertex3f(49.84,119.15,17.10);
	    glVertex3f(49.84,119.05,17.10);
    glEnd();
    
    //piso negro casa superior
    
    glColor3f(0.00,0.00,0.00);
    glBegin(GL_QUADS);
	    glVertex3f(49.84,119.15,15.10);
	   glVertex3f(49.84,115.35,15.10);
	  glVertex3f(64.14,115.35,15.10);
	    glVertex3f(64.14,119.15,15.10);
    glEnd();
    
    //piso negro casa inferior
    
    glColor3f(0.39,0.19,0.00);
    glBegin(GL_QUADS);
	    glVertex3f(62.99,119.10,0.00);
	   glVertex3f(62.99,113.40,0.00);
	  glVertex3f(70.84,113.40,0.00);
	    glVertex3f(70.84,119.10,0.00);
    glEnd();
    
    //piso negro casa inferior
    
    glColor3f(0.49,0.49,0.51);
    glBegin(GL_QUADS);
	    glVertex3f(116.99,119.25,0.00);
	   glVertex3f(116.99,101.25,0.00);
	  glVertex3f(-3.01,101.25,0.00);
	    glVertex3f(-3.01,119.25,0.00);
    glEnd();
    
	//columnas der
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,119.25,15.00);
	   glVertex3f(63.99,119.25,15.00);
	  glVertex3f(63.99,119.25,3.05);
	    glVertex3f(64.24,119.25,3.05);
    glEnd();
    
    //columnas der
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(63.99,119.25,3.05);
	   glVertex3f(63.99,119.25,14.60);
	  glVertex3f(63.99,119.00,15.00);
	    glVertex3f(63.99,119.00,3.23);
    glEnd();
    
    //columnas der
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,119.00,3.23);
	   glVertex3f(63.99,119.00,3.23);
	  glVertex3f(63.99,119.00,15.00);
	    glVertex3f(64.24,119.00,15.00);
    glEnd();
    
    //columnas der
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(64.24,119.00,15.00);
	   glVertex3f(64.24,119.25,15.00);
	  glVertex3f(64.24,119.25,3.15);
	    glVertex3f(64.24,119.00,3.23);
    glEnd();
    //////////////////
    
    //columnas medias 
    	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(62.74,119.25,5.00);
	   glVertex3f(62.74,119.25,14.60);
	  glVertex3f(62.99,119.25,14.60);
	    glVertex3f(62.99,119.25,5.00);
    glEnd();
     //columnas medias 
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(62.74,119.25,14.60);
	   glVertex3f(62.74,119.00,14.60);
	  glVertex3f(62.74,119.00,5.00);
	    glVertex3f(62.74,119.25,5.00);
    glEnd();
    //columnas medias 
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(62.74,119.00,14.60);
	    glVertex3f(62.99,119.00,14.60);
	  glVertex3f(62.99,119.00,5.00);
	    glVertex3f(62.74,119.00,5.00);
    glEnd();
    //columnas medias 
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(62.99,119.00,14.60);
	    glVertex3f(62.99,119.25,14.60);
	  glVertex3f(62.99,119.25,5.00);
	    glVertex3f(62.99,119.00,5.00);
    glEnd();
      //////////////////
    
    //columnas medias 
    	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(50.99,119.25,5.00);
	   glVertex3f(50.99,119.25,14.60);
	  glVertex3f(51.24,119.25,14.60);
	    glVertex3f(51.24,119.25,5.00);
    glEnd();
     //columnas medias 
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(50.99,119.25,14.60);
	   glVertex3f(50.99,119.00,14.60);
	  glVertex3f(50.99,119.00,5.00);
	    glVertex3f(50.99,119.25,5.00);
    glEnd();
    //columnas medias 
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(50.99,119.00,14.60);
	    glVertex3f(51.24,119.00,14.60);
	  glVertex3f(51.24,119.00,5.00);
	    glVertex3f(50.99,119.00,5.00);
    glEnd();
    //columnas medias 
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(51.24,119.00,14.60);
	    glVertex3f(51.24,119.25,14.60);
	  glVertex3f(51.24,119.25,5.00);
	    glVertex3f(51.24,119.00,5.00);
    glEnd();
    
    ////////////////////////////
    //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(64.24,115.50,12.20);
	    glVertex3f(63.99,115.50,12.20);
	  glVertex3f(63.99,115.50,3.82);
	    glVertex3f(64.4,115.50,3.82);
    glEnd();
    
     //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(63.99,115.50,12.20);
	    glVertex3f(63.99,115.25,12.20);
	  glVertex3f(63.99,115.25,3.75);
	    glVertex3f(63.99,115.50,3.82);
    glEnd();
    
      //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(63.99,115.25,11.80);
	    glVertex3f(64.24,115.25,11.80);
	  glVertex3f(64.24,115.25,3.75);
	    glVertex3f(63.99,115.25,3.75);
    glEnd();
    
     //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(64.24,115.25,12.20);
	    glVertex3f(64.24,115.50,12.20);
	  glVertex3f(64.24,115.50,3.82);
	    glVertex3f(64.24,115.25,3.75);
    glEnd();
    ////////////////////////////GA
    
       //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(49.74,115.50,12.20);
	    glVertex3f(49.99,115.50,12.20);
	  glVertex3f(49.99,115.50,3.82);
	    glVertex3f(49.74,115.50,3.82);
    glEnd();
    
     //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(49.99,115.50,12.20);
	    glVertex3f(49.99,115.25,12.20);
	  glVertex3f(49.99,115.25,3.75);
	    glVertex3f(49.99,115.50,3.82);
    glEnd();
    
      //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(49.99,115.25,11.80);
	    glVertex3f(49.74,115.25,11.80);
	  glVertex3f(49.74,115.25,3.75);
	    glVertex3f(49.99,115.25,3.75);
    glEnd();
    
     //columnas blancas
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
     glVertex3f(49.74,115.25,12.20);
	    glVertex3f(49.74,115.50,12.20);
	  glVertex3f(49.74,115.50,3.82);
	    glVertex3f(49.74,115.25,3.75);
    glEnd();
    

    //////////////////////
    	//columnas izq
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,119.25,15.00);
	   glVertex3f(49.74,119.25,15.00);
	  glVertex3f(49.74,119.25,5.00);
	    glVertex3f(49.99,119.25,5.00);
    glEnd();
    
    //columnas izq
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(49.74,119.25,3.05);
	   glVertex3f(49.74,119.25,14.60);
	  glVertex3f(49.74,119.00,15.00);
	    glVertex3f(49.74,119.00,3.23);
    glEnd();
    
    //columnas izq
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,119.00,3.23);
	   glVertex3f(49.74,119.00,3.23);
	  glVertex3f(49.74,119.00,15.00);
	    glVertex3f(49.99,119.00,15.00);
    glEnd();
    
    //columnas izq
	glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	    glVertex3f(49.99,119.00,15.00);
	   glVertex3f(49.99,119.25,15.00);
	  glVertex3f(49.99,119.25,3.15);
	    glVertex3f(49.99,119.00,3.23);
    glEnd();
    
    
 	//techada.
 	glColor3f(0.89,0.89,0.89);
    glBegin(GL_QUADS);
	    glVertex3f(62.99,106.75,5.00);
	   glVertex3f(50.99,106.75,5.00);
	  glVertex3f(50.99,119.25,5.00);
	    glVertex3f(62.99,119.25,5.00);
    glEnd();
 	
	
	
    
    
    
    
    
    //////////////////////////////////////////
    
    //hueco pata izquierda
    glColor3f(0.87,0.90,1.00);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,100.75,0.00);
	  glVertex3f(51.24,100.75,4.75);
	  glVertex3f(50.99,100.75,4.75);
	  glVertex3f(50.99,100.75,0.00);
    glEnd();
    
    //hueco pata derecha
    
    glColor3f(0.87,0.90,1.00);
    glBegin(GL_QUADS);
	 glVertex3f(62.74,100.75,0.00);
	  glVertex3f(62.74,100.75,4.75);
	  glVertex3f(62.99,100.75,4.75);
	  glVertex3f(62.99,100.75,0.00);
    glEnd();
    
    //hueco pata superior
     glColor3f(0.87,0.90,1.00);
    glBegin(GL_QUADS);
	 glVertex3f(50.99,100.75,4.75);
	  glVertex3f(62.99,100.75,4.75);
	  glVertex3f(62.99,100.75,5.00);
	glVertex3f(50.99,100.75,5.00);
    glEnd();
    
    //hueco pared izquierda
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,100.75,0.00);
	  glVertex3f(51.24,100.75,4.75);
	  glVertex3f(51.24,117.75,4.75);
	  glVertex3f(51.24,117.75,0.00);
    glEnd();
    //hueco pared izquierda
     glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,117.75,2.00);
	 glVertex3f(51.24,117.75,4.75);
	  glVertex3f(51.24,119.00,4.75);
	   glVertex3f(51.24,119.00,2.00);
    glEnd();
       //hueco pared izquierda
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,118.75,0.00);
	 glVertex3f(51.24,118.75,2.00);
	  glVertex3f(51.24,119.00,2.00);
	   glVertex3f(51.24,119.00,0.00);
    glEnd();
    
    //hueco pared derecha
  glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	  glVertex3f(62.74,100.75,0.00);
	  glVertex3f(62.74,100.75,4.75);
	  glVertex3f(62.74,117.75,4.75);
	  glVertex3f(62.74,117.75,0.00);
    glEnd();
    //hueco pared derecha
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(62.74,117.75,2.00);
	 glVertex3f(62.74,117.75,4.75);
	  glVertex3f(62.74,119.00,4.75);
	   glVertex3f(62.74,119.00,2.00);
    glEnd();
       //hueco pared derecha
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(62.74,118.75,0.00);
	 glVertex3f(62.74,118.75,2.00);
	  glVertex3f(62.74,119.00,2.00);
	   glVertex3f(62.74,119.00,0.00);
    glEnd();
    
    //hueco pared fondo
     glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,119.00,0.00);
	glVertex3f(51.24,119.00,4.75);
	  glVertex3f(62.74,119.00,4.75);
	   glVertex3f(62.74,119.00,0.00);
    glEnd();
    
    //hueco pared techo
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,100.75,4.75);
	glVertex3f(51.24,119.00,4.75);
	  glVertex3f(62.74,119.00,4.75);
	   glVertex3f(62.74,100.75,4.75);
    glEnd();
    
    //hueco pared techo alto
    
     glColor3f(0.67,0.69,0.80);
    glBegin(GL_QUADS);
	 glVertex3f(50.99,100.75,5.00);
	glVertex3f(50.99,106.25,5.00);
	  glVertex3f(62.99,106.25,5.00);
	   glVertex3f(62.99,100.75,5.00);
    glEnd();
    
    //pared hueco marco
     glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(51.24,117.75,0.00);
	glVertex3f(50.99,117.75,0.00);
	  glVertex3f(50.99,118.75,0.00);
	   glVertex3f(51.24,118.75,0.00);
    glEnd();
    
    //pared hueco marco
     glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
	 glVertex3f(50.99,118.75,0.00);
	   glVertex3f(51.24,118.75,0.00);
	  glVertex3f(51.24,118.75,2.00);
	   glVertex3f(50.99,118.75,2.00);
    glEnd();
    
     //pared hueco marco
     glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(51.24,118.75,2.00);
	   glVertex3f(50.99,118.75,2.00);
	 glVertex3f(50.99,117.75,2.00);
	   glVertex3f(51.24,117.75,2.00);
    glEnd();
    
    //pared hueco marco
     glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
    glVertex3f(50.99,117.75,2.00);
	   glVertex3f(51.24,117.75,2.00);
     glVertex3f(51.24,117.75,0.00);
	   glVertex3f(50.99,117.75,0.00);
    glEnd();
    
    //pared hueco marco derecha
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
    glVertex3f(62.74,118.75,0.00);
	glVertex3f(62.99,118.75,0.00);
    glVertex3f(62.99,118.75,2.00);
	glVertex3f(62.74,118.75,2.00);
    glEnd();
    
        //pared hueco marco derecha
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
    glVertex3f(62.99,118.75,2.00);
	glVertex3f(62.74,118.75,2.00);
    glVertex3f(62.74,117.75,2.00);
	glVertex3f(62.99,117.75,2.00);
  
    glEnd();
    //pared hueco marco derecha
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(62.74,117.75,2.00);
	glVertex3f(62.99,117.75,2.00);
    glVertex3f(62.99,117.75,0.00);
	glVertex3f(62.74,117.75,0.00);
    glEnd();
    
    //pared hueco marco derecha
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(62.74,117.75,0.00);
	glVertex3f(62.99,117.75,0.00);
    glVertex3f(62.99,118.75,0.00);
	glVertex3f(62.74,118.75,0.00);
    glEnd();
    
    //casa derecha abajo der front
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(62.99,113.25,0.00);
	glVertex3f(70.99,113.25,0.00);
    glVertex3f(70.99,113.25,3.00);
	glVertex3f(62.99,113.25,3.00);
    glEnd();
    
    //casa derecha abajo izq front
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(42.99,113.25,0.00);
	glVertex3f(50.99,113.25,0.00);
    glVertex3f(50.99,113.25,3.00);
	glVertex3f(42.99,113.25,3.00);
    glEnd();
    
    //parte trasera casas de abajo
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(42.99,119.25,0.00);
	glVertex3f(42.99,119.25,3.00);
    glVertex3f(70.99,119.25,3.00);
	glVertex3f(70.99,119.25,0.00);
	
	//parte trasera casas de abajo
    
    glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);
     glVertex3f(62.99,119.25,3.00);
	glVertex3f(62.99,119.25,5.00);
    glVertex3f(50.99,119.25,5.00);
	glVertex3f(50.99,119.25,3.00);

	
    glEnd();
    
	//TECHOSSS    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_QUADS);
     glVertex3f(50.99,119.60,3.05);
	glVertex3f(50.99,116.25,4.05);
    glVertex3f(42.64,116.25,4.05);
	glVertex3f(42.64,119.60,3.05);
    glEnd();
    
   glColor3f(0.84,0.54,0.35);
    glBegin(GL_QUADS);
    glVertex3f(42.64,112.90,3.05);
     glVertex3f(50.99,112.90,3.05);
	glVertex3f(50.99,116.25,4.05);
    glVertex3f(42.64,116.25,4.05);
	
    glEnd();
    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_QUADS);
     glVertex3f(71.34,119.60,3.05);
	glVertex3f(71.34,116.25,4.05);
    glVertex3f(62.99,116.25,4.05);
	glVertex3f(62.99,119.60,3.05);
    glEnd();
    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_QUADS);
    glVertex3f(62.99,112.90,3.05);
     glVertex3f(71.34,112.90,3.05);
	glVertex3f(71.34,116.25,4.05);
    glVertex3f(62.99,116.25,4.05);
    glEnd();
    //techo triangulo der
    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_TRIANGLES);
    glVertex3f(71.34,116.25,3.05);
     glVertex3f(71.34,116.25,4.05);
	glVertex3f(71.34,119.60,3.05);
    glEnd();
    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_TRIANGLES);
    glVertex3f(71.34,116.25,4.05);
    glVertex3f(71.34,116.25,3.05);
	glVertex3f(71.34,112.90,3.05);
    glEnd();
    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_QUADS);
    glVertex3f(71.34,112.90,3.00);
     glVertex3f(71.34,112.90,3.05);
	glVertex3f(71.34,119.60,3.05);
    glVertex3f(71.34,119.60,3.00);
    glEnd();
    
    
      //techo triangulo izq
        
   glColor3f(0.84,0.54,0.35);
    glBegin(GL_TRIANGLES);
    glVertex3f(42.64,116.25,3.05);
     glVertex3f(42.64,116.25,4.05);
	glVertex3f(42.64,119.60,3.05);
    glEnd();
    
    glColor3f(0.84,0.54,0.35);
    glBegin(GL_TRIANGLES);
    glVertex3f(42.64,116.25,4.05);
    glVertex3f(42.64,116.25,3.05);
	glVertex3f(42.64,112.90,3.05);
    glEnd();
    
     glColor3f(0.84,0.54,0.35);
    glBegin(GL_QUADS);
    glVertex3f(42.64,112.90,3.00);
     glVertex3f(42.64,112.90,3.05);
	glVertex3f(42.64,119.60,3.05);
    glVertex3f(42.64,119.60,3.00);
    glEnd();
    
    
    //casa inferior der pared con puerta
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(70.99,113.25,3.00);
     glVertex3f(70.99,119.25,3.00);
	glVertex3f(70.99,119.25,2.00);
    glVertex3f(70.99,113.25,2.00);
    glEnd();
    
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(70.99,113.25,0.00);
     glVertex3f(70.99,113.25,2.00);
	glVertex3f(70.99,117.95,2.00);
    glVertex3f(70.99,117.95,0.00);
    glEnd();
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(70.99,118.95,0.00);
     glVertex3f(70.99,118.95,2.00);
	glVertex3f(70.99,119.25,2.00);
    glVertex3f(70.99,119.25,0.00);
    glEnd();
    
       //casa inferior puerta med
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(62.99,113.25,3.00);
     glVertex3f(62.99,119.25,3.00);
	glVertex3f(62.99,119.25,2.00);
    glVertex3f(62.99,113.25,2.00);
    glEnd();
    
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(62.99,113.25,0.00);
     glVertex3f(62.99,113.25,2.00);
	glVertex3f(62.99,117.95,2.00);
    glVertex3f(62.99,117.95,0.00);
    glEnd();
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(62.99,118.95,0.00);
     glVertex3f(62.99,118.95,2.00);
	glVertex3f(62.99,119.25,2.00);
    glVertex3f(62.99,119.25,0.00);
    glEnd();
    
    //casa inferior puerta med
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(51.24,113.25,3.00);
     glVertex3f(51.24,119.25,3.00);
	glVertex3f(51.24,119.25,2.00);
    glVertex3f(51.24,113.25,2.00);
    glEnd();
    
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(51.24,113.25,0.00);
     glVertex3f(51.24,113.25,2.00);
	glVertex3f(51.24,117.95,2.00);
    glVertex3f(51.24,117.95,0.00);
    glEnd();
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(51.24,118.95,0.00);
     glVertex3f(51.24,118.95,2.00);
	glVertex3f(51.24,119.25,2.00);
    glVertex3f(51.24,119.25,0.00);
    glEnd();
    
       //casa inferior puerta med
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(43.14,113.25,3.00);
     glVertex3f(43.14,119.25,3.00);
	glVertex3f(43.14,119.25,2.00);
    glVertex3f(43.14,113.25,2.00);
    glEnd();
    
     glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(43.14,113.25,0.00);
     glVertex3f(43.14,113.25,2.00);
	glVertex3f(43.14,117.95,2.00);
    glVertex3f(43.14,117.95,0.00);
    glEnd();
    
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(43.14,118.95,0.00);
     glVertex3f(43.14,118.95,2.00);
	glVertex3f(43.14,119.25,2.00);
    glVertex3f(43.14,119.25,0.00);
    glEnd();
    
    //piso casa inferior
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(50.99,119.10,0.00);
     glVertex3f(50.99,113.40,0.00);
	glVertex3f(43.14,113.40,0.00);
    glVertex3f(43.14,119.10,0.00);
    glEnd();
    
     //piso casa inferior
    glColor3f(0.65,0.65,0.65);
    glBegin(GL_QUADS);
    glVertex3f(70.84,119.10,0.00);
     glVertex3f(70.84,113.40,0.00);
	glVertex3f(62.99,113.40,0.00);
    glVertex3f(62.99,119.10,0.00);
    glEnd();
    

}

void Torreta_de_Luz2(){
   
 glColor3f(0.94,0.97,1.00);
    glBegin(GL_QUADS);//pizarrafrontal
	    glVertex3f(113.88,102.71, 30.0);
	    glVertex3f(113.88,102.71, 25.0);
	    glVertex3f(120.46,96.14, 25.0);
        glVertex3f(120.46,96.14, 30.0);
    glEnd();

    glColor3f(0.64,0.64,0.64);//darkgray
      glBegin(GL_QUADS);//abjo1 pizarra
	    glVertex3f(113.88,102.71, 25.0);
	    glVertex3f(113.95,102.79, 25.0);
	    glVertex3f(116.99,99.75, 25.0);
	    glVertex3f(116.99,99.61, 25.0);
    glEnd();
    
    glBegin(GL_QUADS);//abjo2 pizarra
	    glVertex3f(117.35,99.25, 25.0);
	    glVertex3f(117.49,99.25, 25.0);
	    glVertex3f(120.53,96.21, 25.0);
	    glVertex3f(120.46,96.14, 25.0);
    glEnd();
	 glColor3f(0.94,0.97,1.00);
	glBegin(GL_QUADS);//costado pizarra
	    glVertex3f(120.46,96.14,25.0);
	    glVertex3f(120.53,96.21,25.0);
	    glVertex3f(120.46,96.14,30.0);
	    glVertex3f(120.53,96.21,30.0);
    glEnd();
     glColor3f(0.91,0.91,0.91);//blanco
    	glBegin(GL_QUADS);//costado2 pizarra
	    glVertex3f(113.95,102.79,25.0);
	    glVertex3f(113.88,102.71,25.0);
	   	glVertex3f(113.88,102.71,30.0);
	    glVertex3f(113.95,102.79,30.0);
    glEnd();
  
      	glBegin(GL_QUADS);//superiorpizarra
	    glVertex3f(113.88,102.71,30.0);
	    glVertex3f(113.95,102.79,30.0);
	    glVertex3f(120.53,96.21,30.0);
	    glVertex3f(120.46,96.14,30.0);
    glEnd();

glColor3f(0.42,0.43,0.42);//darkgray
	glBegin(GL_QUADS);//atraspizarra1
	    glVertex3f(120.53,96.21,25.0);
	    glVertex3f(113.95,102.79,25.0);
	    glVertex3f(113.95,102.79,30.0);
	    glVertex3f(120.53,96.21,30.0);
    glEnd();
    
  
    
      glColor3f(0.91,0.91,0.91);//blanco
    
    	glBegin(GL_TRIANGLES);//TRIANGULO SUpizarra
	    glVertex3f(116.99,99.75,30.0);
		glVertex3f(117.49,99.75,30.0);
	    glVertex3f(117.49,99.25,30.0);
	
	  
    glEnd();
    
    glColor3f(0.91,0.91,0.91);//blanco
    
    	glBegin(GL_QUADS);//costado1
	    glVertex3f(117.49,99.75,30.0);
	    glVertex3f(117.49,99.25,30.0);
	      glVertex3f(117.49,99.25,0.0);
	    glVertex3f(117.49,99.75,0.0);
	  
	    
	  
    glEnd();
      
    	glColor3f(0.65,0.67,0.68);//cuadrbajo
    	glBegin(GL_QUADS);//costado2
	    glVertex3f(116.99,99.75,30.0);
		glVertex3f(117.49,99.75,30.0);
		glVertex3f(117.49,99.75,00.0);
	    glVertex3f(116.99,99.75,00.0);
	
	    
	  
    glEnd();
    glColor3f(0.91,0.91,0.91);//blanco
    	glBegin(GL_QUADS);//costado2mm
	    glVertex3f(116.99,99.75,30.0);
		glVertex3f(117.49,99.25,30.0);
		glVertex3f(117.49,99.25,0.0);
	   glVertex3f(116.99,99.75,0.0);
	
	  
    glEnd();
	
    	 glColor3f(0.67,0.69,0.80);//blanco
    
    	glBegin(GL_TRIANGLES);//TRIANGULO SUpizarra
	    glVertex3f(116.99,99.75,25.0);
	    glVertex3f(117.49,99.25,25.0);
	    glVertex3f(116.99,99.25,25.0);
	    
	  
    glEnd();
    
    
    glColor3f(0.91,0.91,0.91);//blanco
    
    	glBegin(GL_QUADS);//
	    glVertex3f(117.49,99.25,25.0);
	    glVertex3f(116.99,99.25,25.0);
	    glVertex3f(116.99,99.25,0.0);
	   glVertex3f(117.49,99.25,0.0);
	
    glEnd();
  
  glColor3f(0.94,0.93,0.93);
	glBegin(GL_QUADS);//
	     glVertex3f(116.99,99.75,25.0);
	    glVertex3f(116.99,99.25,25.0);
	    glVertex3f(116.99,99.25,0.0);
	    glVertex3f(116.99,99.75,0.0);
    glEnd();
    

    
    
}

void Torreta_de_Luz(){
   
 glColor3f(0.64,0.64,0.64);//darkgray
    glBegin(GL_QUADS);//pizarrafrontal
	    glVertex3f(120.95,-5.64, 30.0);
	    glVertex3f(113.38,-13.21, 30.0);
	    glVertex3f(113.38,-13.21, 25.0);
	    glVertex3f(120.95,-5.64, 25.0);
    glEnd();
    
      glBegin(GL_QUADS);//abjo1 pizarra
	    glVertex3f(121.03,-5.71, 25.0);
	    glVertex3f(120.95,-5.64, 25.0);
	    glVertex3f(117.35,-9.25, 25.0);
	    glVertex3f(117.49,-9.25, 25.0);
    glEnd();
    
    glBegin(GL_QUADS);//abjo2 pizarra
	    glVertex3f(116.99,-9.75, 25.0);
	    glVertex3f(116.99,-9.61, 25.0);
	    glVertex3f(113.38,-13.21, 25.0);
	    glVertex3f(113.45,-13.29, 25.0);
    glEnd();
	 glColor3f(0.0,0.0,0.0);//blanco
	glBegin(GL_QUADS);//costado pizarra
	    glVertex3f(113.45,-13.29,30.0);
	    glVertex3f(113.38,-13.21,30.0);
	    glVertex3f(113.38,-13.21, 25.0);
	    glVertex3f(113.45,-13.29, 25.0);
    glEnd();
     glColor3f(0.91,0.91,0.91);//blanco
    	glBegin(GL_QUADS);//costado2 pizarra
	    glVertex3f(121.03,-5.71,30.0);
	    glVertex3f(120.95,-5.64,30.0);
	    glVertex3f(120.95,-5.64, 25.0);
	    glVertex3f(121.03,-5.71, 25.0);
    glEnd();
  
      	glBegin(GL_QUADS);//superiorpizarra
	    glVertex3f(113.45,-13.29,30.0);
	    glVertex3f(113.38,-13.21,30.0);
	    glVertex3f(120.95,-5.64, 30.0);
	    glVertex3f(121.03,-5.71, 30.0);
    glEnd();


	glBegin(GL_QUADS);//atraspizarra1
	    glVertex3f(121.03,-5.71,30.0);
	    glVertex3f(121.03,-5.71,25.0);
	    glVertex3f(113.45,-13.29, 25.0);
	    glVertex3f(113.45,-13.29, 30.0);
    glEnd();
    
  
    
    	glColor3f(0.66,0.66,0.64);//triangulo
    
    	glBegin(GL_TRIANGLES);//TRIANGULO SUpizarra
	    glVertex3f(117.49,-9.25,30.0);
	    glVertex3f(116.99,-9.75,30.0);
	    glVertex3f(117.49,-9.75, 30.0);
	  
    glEnd();
    
     glColor3f(0.42,0.43,0.42);//darkgray
    
    	glBegin(GL_QUADS);//costado1
	    glVertex3f(116.99,-9.75,1.85);
	    glVertex3f(117.49,-9.75,1.85);
	    glVertex3f(117.49,-9.75,00.0);
	    glVertex3f(116.99,-9.75,00.0);
	    
	  
    glEnd();
      glColor3f(0.66,0.66,0.64);//darkgray
    
    	glBegin(GL_QUADS);//costado2
	    glVertex3f(116.99,-9.75,1.85);
	    glVertex3f(117.49,-9.75,1.85);
	    glVertex3f(117.49,-9.75,30.0);
	    glVertex3f(116.99,-9.75,30.0);
	    
	  
    glEnd();
    
    
     glColor3f(0.44,0.43,0.39);//darkgray
        glLineWidth(3);
    	glBegin(GL_LINES);//lineas
	    glVertex3f(117.05,-9.75,30.00);
	    glVertex3f(117.05,-9.69,30.00);
	  
	  glVertex3f(117.05,-9.75,30.00);
	  glVertex3f(117.05,-9.75,00.00);
	  
	  
	  glVertex3f(116.99,-9.75,1.85);
	  glVertex3f(117.49,-9.75,1.85);
	    
	    
	  glVertex3f(116.99,-9.75,2.44);
	  glVertex3f(117.49,-9.75,2.44);
	  
	  
	   glVertex3f(116.99,-9.75,4.87);
	  glVertex3f(117.49,-9.75,4.87);
	  
	   glVertex3f(116.99,-9.75,7.31);
	  glVertex3f(117.49,-9.75,7.31);
	  
	   glVertex3f(116.99,-9.75,12.19);
	  glVertex3f(117.49,-9.75,12.19);
	  
	   glVertex3f(116.99,-9.75,14.62);
	  glVertex3f(117.49,-9.75,14.62);
	  
	   glVertex3f(116.99,-9.75,17.05);
	  glVertex3f(117.49,-9.75,17.05);
	  
	  
	   glVertex3f(116.99,-9.75,19.49);
	  glVertex3f(117.49,-9.75,19.49);
	  
	  
	   glVertex3f(116.99,-9.75,21.95);
	  glVertex3f(117.49,-9.75,21.95);
	  
	  
	   glVertex3f(116.99,-9.75,24.38);
	  glVertex3f(117.49,-9.75,24.38);
	  
	  
	
	   glVertex3f(116.99,-9.75,26.82);
	  glVertex3f(117.49,-9.75,26.82);
	  
	  
	  
	   glVertex3f(116.99,-9.75,29.25);
	  glVertex3f(117.49,-9.75,29.25);
	  
    glEnd();
  
  
       
     glColor3f(0.44,0.43,0.39);//puntos
    glPointSize(3);
    	glBegin(GL_POINTS);//costado2
    	
	    glVertex3f(117.27,-9.60,30.00);
	    glVertex3f(117.29,-9.75,29.42);
	    glVertex3f(117.29,-9.75,29.04);
	    glVertex3f(117.29,-9.75,28.38);    
	    glVertex3f(117.29,-9.75,27.65);
		glVertex3f(117.29,-9.75,27.00);    
		glVertex3f(117.29,-9.75,26.65); 
		glVertex3f(117.29,-9.75,25.94);
		glVertex3f(117.29,-9.75,25.18);
		glVertex3f(117.29,-9.75,24.57);
		glVertex3f(117.29,-9.75,24.17);
		glVertex3f(117.29,-9.75,23.46);
		glVertex3f(117.29,-9.75,23.46);
		glVertex3f(117.29,-9.75,22.81);
		glVertex3f(117.29,-9.75,22.11);
		
		glVertex3f(117.29,-9.75,22.73);
		glVertex3f(117.29,-9.75,22.07);
		glVertex3f(117.29,-9.75,20.34);
		glVertex3f(117.29,-9.75,19.70);
		glVertex3f(117.29,-9.75,19.26);
		glVertex3f(117.29,-9.75,18.63);
		glVertex3f(117.29,-9.75,17.90);
		glVertex3f(117.29,-9.75,17.23);
		glVertex3f(117.29,-9.75,16.85);
		glVertex3f(117.29,-9.75,15.45);
		glVertex3f(117.29,-9.75,14.78);
		glVertex3f(117.29,-9.75,14.40);
		glVertex3f(117.29,-9.75,13.74);
		glVertex3f(117.29,-9.75,13.01);
		glVertex3f(117.29,-9.75,12.35);
		glVertex3f(117.29,-9.75,11.97);
		glVertex3f(117.29,-9.75,11.32);
		glVertex3f(117.29,-9.75,10.55);
		glVertex3f(117.29,-9.75,9.90);
		glVertex3f(117.29,-9.75,9.52);
		glVertex3f(117.29,-9.75,8.86);
		glVertex3f(117.29,-9.75,8.13);
		glVertex3f(117.29,-9.75,7.46);
		glVertex3f(117.29,-9.75,7.09);
		glVertex3f(117.29,-9.75,6.44);
		glVertex3f(117.29,-9.75,5.68);
		glVertex3f(117.29,-9.75,5.02);
		glVertex3f(117.29,-9.75,4.64);
		glVertex3f(117.29,-9.75,3.99);
		glVertex3f(117.29,-9.75,3.25);
		glVertex3f(117.29,-9.75,2.60);
		glVertex3f(117.29,-9.75,1.54);
		glVertex3f(117.29,-9.75,0.82);
		glVertex3f(117.29,-9.75,0.15); 
									              
	  
    glEnd();
    
    
     glColor3f(0.44,0.45,0.52);//darkgray
    
    	glBegin(GL_QUADS);//costado2mm
	    glVertex3f(117.49,-9.25,0.0);
	    glVertex3f(117.49,-9.75,0.0);
	    glVertex3f(117.49,-9.75,30.0);
	    glVertex3f(117.49,-9.25,30.0);
	    
	  
    glEnd();
	
	
	 
	    	glColor3f(0.66,0.66,0.64);//triangulo
    
    	glBegin(GL_QUADS);//
	    glVertex3f(117.49,-9.25,30.0);
	    glVertex3f(116.99,-9.75,30.0);
	    glVertex3f(116.99,-9.75,00.0);
	     glVertex3f(117.49,-9.25,0.0);
	  
    glEnd();
    	glColor3f(0.43,0.45,0.44);//triangulo
    
    	glBegin(GL_TRIANGLES);//TRIANGULO SUpizarra
	    glVertex3f(116.99,-9.75,25.0);
	    glVertex3f(116.99,-9.25,25.0);
	    glVertex3f(117.49,-9.25,25.0);
	  
    glEnd();
    
    
    	glColor3f(0.44,0.45,0.52);//cuadrbajo
    
    	glBegin(GL_QUADS);//
	    glVertex3f(116.99,-9.25,25.0);
	    glVertex3f(117.49,-9.25,25.0);
	    glVertex3f(117.49,-9.25,00.0);
	   glVertex3f(116.99,-9.25,00.0);
    glEnd();
  
  
  	glColor3f(0.44,0.45,0.52);//cuadrbajo
    
    	glBegin(GL_QUADS);//
	    glVertex3f(116.99,-9.75,25.0);
	    glVertex3f(117.49,-9.25,25.0);
	    glVertex3f(117.49,-9.25,00.0);
	   glVertex3f(116.99,-9.75,00.0);
    glEnd();
    
    	glColor3f(0.65,0.67,0.68);//cuadrbajo
    
    	glBegin(GL_QUADS);//
	    glVertex3f(116.99,-9.75,25.0);
	    glVertex3f(116.99,-9.25,25.0);
	    glVertex3f(116.99,-9.25,00.0);
	   glVertex3f(116.99,-9.75,00.0);
    glEnd();
  
  
  	glColor3f(0.65,0.67,0.68);//trama
    
    	glBegin(GL_QUADS);//
	    glVertex3f(117.49,-9.25,1.5);
	    glVertex3f(116.99,-9.25,1.5);
	    glVertex3f(116.99,-9.25,00.0);
	   glVertex3f(117.49,-9.25,00.0);
    glEnd();
    
    
    glColor3f(0.44,0.45,0.44);//trama2
    
    	glBegin(GL_QUADS);//
	    glVertex3f(116.99,-9.75,1.84);
	    glVertex3f(116.99,-9.25,1.57);
	    glVertex3f(116.99,-9.25,00.0);
	   glVertex3f(116.99,-9.75,00.0);
    glEnd();
    
      glColor3f(0.44,0.45,0.44);//cerrar
    
    	glBegin(GL_QUADS);//
	    glVertex3f(116.99,-9.75,0.00);
	    glVertex3f(116.99,-9.25,0.00);
	    glVertex3f(117.49,-9.75,00.0);
	   glVertex3f(117.49,-9.25,00.0);
    glEnd();
    
    
    
    ////////////////////////torreta 4
      
 glColor3f(0.44,0.45,0.52);
    glBegin(GL_QUADS);//pizarrafrontal
	    glVertex3f(6.62,-13.21, 30.0);
	     glVertex3f(-0.95,-5.64, 30.0);
		 glVertex3f(-0.95,-5.64, 25.0);
	    glVertex3f(6.62,-13.21, 25.0);

    glEnd();

    glColor3f(0.64,0.64,0.64);//darkgray
      glBegin(GL_QUADS);//abjo1 pizarra
	    glVertex3f(-0.95,-5.64, 25.0);
	    glVertex3f(-1.03,-5.71, 25.0);
	    glVertex3f(2.51,-9.25, 25.0);
	    glVertex3f(2.65,-9.25, 25.0);
    glEnd();
    
    glBegin(GL_QUADS);//abjo2 pizarra
	    glVertex3f(3.01,-9.61,25.0);
	    glVertex3f(3.01,-9.75,25.0);
	    glVertex3f(6.62,-13.21,25.0);
	    glVertex3f(6.55,-13.29,25.0);
    glEnd();
    
	 glColor3f(0.94,0.97,1.00);
	 
	glBegin(GL_QUADS);//costado pizarra
	    glVertex3f(6.62,-13.21,25.0);
	    glVertex3f(6.55,-13.29,25.0);
	    glVertex3f(6.55,-13.29,30.0);
	    glVertex3f(6.62,-13.21,30.0);
	    
    glEnd();
    
    
     glColor3f(0.91,0.91,0.91);//blanco
    	glBegin(GL_QUADS);//costado2 pizarra
	    glVertex3f(-1.03,-5.71,25.0);
	    glVertex3f(-0.95,-5.64,25.0);
	   	  glVertex3f(-0.95,-5.64,30.0);
	     glVertex3f(-1.03,-5.71,30.0);
    glEnd();
    
  	glBegin(GL_QUADS);//superiorpizarra
	    glVertex3f(-0.95,-5.64,30.0);
	     glVertex3f(-1.03,-5.71,30.0);
	    glVertex3f(6.55,-13.29,30.0);
	    glVertex3f(6.62,-13.21,30.0);
	  
    glEnd();
      

glColor3f(1.00,1.00,1.00);//darkgray
	glBegin(GL_QUADS);//atraspizarra1
	    glVertex3f(-1.03,-5.71,30.0);
	    glVertex3f(6.55,-13.29,30.0);
	    glVertex3f(6.55,-13.29,25.0);
	    glVertex3f(-1.03,-5.71,25.0);
    glEnd();
   
    
  //aca
      glColor3f(0.64,0.65,0.64);
    
    	glBegin(GL_QUADS);//TRIANGULO SUpizarra
	    glVertex3f(2.51,-9.25,30.0);
		glVertex3f(3.01,-9.75,30.0);
	    glVertex3f(2.51,-9.75,30.0);
	    glVertex3f(2.51,-9.25,30.0);
	  
    glEnd();//
     //aca
  
    	glColor3f(0.65,0.67,0.68);//cuadrbajo
    
    	glBegin(GL_QUADS);//costado1
	     glVertex3f(2.51,-9.75,30.0);
	    glVertex3f(2.51,-9.25,30.0);
	    glVertex3f(2.51,-9.25,00.0);
	    glVertex3f(2.51,-9.75,00.0);
	 
	    
	  
    glEnd();
    //tramas aca---
      //otro
     glColor3f(0.63,0.64,0.75);//cuadrbajo
    	glBegin(GL_QUADS);//costado2
	    glVertex3f(3.01,-9.75,30.0);
		glVertex3f(2.51,-9.75,30.0);
		glVertex3f(2.51,-9.75,00.0);
	    glVertex3f(3.01,-9.75,00.0);
	//trama
	    
	
	
    	  glColor3f(0.44,0.45,0.52);
    
    	glBegin(GL_QUADS);//TRIANGULO bajo
    	
	    glVertex3f(3.01,-9.25,25.0);
	    glVertex3f(2.51,-9.25,25.0);
	    glVertex3f(3.01,-9.75,25.0);
	    glVertex3f(3.01,-9.25,25.0);
        glEnd();
    
    
    glColor3f(0.44,0.45,0.52);
    
    	glBegin(GL_QUADS);//trama
	      glVertex3f(3.01,-9.25,25.0);
	    glVertex3f(2.51,-9.25,25.0);
	    glVertex3f(2.51,-9.25,0.0);
	     glVertex3f(3.01,-9.25,0.0);
	
    glEnd();
  ///trama
  glColor3f(0.67,0.71,0.67);
	glBegin(GL_QUADS);//
	     glVertex3f(3.01,-9.25,25.0);
	    glVertex3f(3.01,-9.75,25.0);
	    glVertex3f(3.01,-9.75,00.0);
	      glVertex3f(3.01,-9.25,00.0);
    glEnd();
     glColor3f(0.44,0.43,0.39);//darkgray
        glLineWidth(3);
    	glBegin(GL_LINES);//lineas
    	glVertex3f(	2.51	,	-9.75	,	29.26	);
glVertex3f(	3.01	,	-9.75	,	29.26	);
glVertex3f(	2.51	,	-9.75	,	26.83	);
glVertex3f(	3.01	,	-9.75	,	26.83	);
glVertex3f(	2.51	,	-9.75	,	24.4	);
glVertex3f(	3.01	,	-9.75	,	24.4	);
glVertex3f(	2.51	,	-9.75	,	21.93	);
glVertex3f(	3.01	,	-9.75	,	21.93	);
glVertex3f(	2.51	,	-9.75	,	19.54	);
glVertex3f(	3.01	,	-9.75	,	19.54	);
glVertex3f(	2.51	,	-9.75	,	17.08	);
glVertex3f(	3.01	,	-9.75	,	17.08	);
glVertex3f(	2.51	,	-9.75	,	14.63	);
glVertex3f(	3.01	,	-9.75	,	14.63	);
glVertex3f(	2.51	,	-9.75	,	12.18	);
glVertex3f(	3.01	,	-9.75	,	12.18	);
glVertex3f(	2.51	,	-9.75	,	9.72	);
glVertex3f(	3.01	,	-9.75	,	9.72	);
glVertex3f(	2.51	,	-9.75	,	7.36	);
glVertex3f(	3.01	,	-9.75	,	7.36	);
glVertex3f(	2.51	,	-9.75	,	4.9	);
glVertex3f(	3.01	,	-9.75	,	4.9	);
glVertex3f(	2.51	,	-9.75	,	2.45	);
glVertex3f(	3.01	,	-9.75	,	2.45	);

    	    glEnd();
    	    
    	        glColor3f(0.44,0.43,0.39);//darkgray
        glLineWidth(3);
    	glBegin(GL_LINES);//lineas
    	glVertex3f(	3.01	,	-9.25	,	24.4	);
glVertex3f(	3.01	,	-9.75	,	24.4	);
glVertex3f(	3.01	,	-9.25	,	21.93	);
glVertex3f(	3.01	,	-9.75	,	21.93	);
glVertex3f(	3.01	,	-9.25	,	19.54	);
glVertex3f(	3.01	,	-9.75	,	19.54	);
glVertex3f(	3.01	,	-9.25	,	17.08	);
glVertex3f(	3.01	,	-9.75	,	17.08	);
glVertex3f(	3.01	,	-9.25	,	14.63	);
glVertex3f(	3.01	,	-9.75	,	14.63	);
glVertex3f(	3.01	,	-9.25	,	12.18	);
glVertex3f(	3.01	,	-9.75	,	12.18	);
glVertex3f(	3.01	,	-9.25	,	9.72	);
glVertex3f(	3.01	,	-9.75	,	9.72	);
glVertex3f(	3.01	,	-9.25	,	7.36	);
glVertex3f(	3.01	,	-9.75	,	7.36	);
glVertex3f(	3.01	,	-9.25	,	4.9	);
glVertex3f(	3.01	,	-9.75	,	4.9	);
glVertex3f(	3.01	,	-9.25	,	2.45	);
glVertex3f(	3.01	,	-9.75	,	2.45	);

    	glEnd();
    	
    glColor3f(0.44,0.44,0.43);//darkgray
    		glBegin(GL_QUADS);//trama
	  glVertex3f(3.01,-9.75,1.85);
     glVertex3f(2.51,-9.75,1.85);
       glVertex3f(2.51,-9.75,0);
      glVertex3f(3.01,-9.75,0);
      
       glVertex3f(2.51,-9.25,1.85);
     glVertex3f(2.51,-9.75,1.85);
       glVertex3f(2.51,-9.75,0);
      glVertex3f(2.51,-9.25,0);
   
    glEnd();
    
     
}

void Torretas(){
	
	Torreta_de_Luz();
	Torreta_de_Luz2();
	
	
//////////TORRETA 3
   
 glColor3f(0.91,0.91,0.91);
    glBegin(GL_QUADS);//pizarrafrontal
	    glVertex3f(6.62,103.21, 30.0);
	    glVertex3f(6.62,103.21, 25.0);
	    glVertex3f(-0.95,95.64, 25.0);
	     glVertex3f(-0.95,95.64, 30.0);

    glEnd();

    glColor3f(0.64,0.64,0.64);//darkgray
      glBegin(GL_QUADS);//abjo1 pizarra
	    glVertex3f(-0.95,95.64, 25.0);
	    glVertex3f(-1.03,95.71, 25.0);
	    glVertex3f(2.51,99.25, 25.0);
	    glVertex3f(2.65,99.25, 25.0);
    glEnd();
    
glColor3f(0.42,0.43,0.42);//darkgray
    glBegin(GL_QUADS);//abjo2 pizarra
	    glVertex3f(3.01,99.61, 25.0);
	    glVertex3f(3.01,99.75, 25.0);
	    glVertex3f(6.62,103.21,25.0);
	    glVertex3f(6.55,103.29,25.0);
    glEnd();
    
glColor3f(0.42,0.43,0.42);//darkgray
	glBegin(GL_QUADS);//costado pizarra
	    glVertex3f(6.62,103.21,25.0);
	    glVertex3f(6.55,103.29,25.0);
	    glVertex3f(6.55,103.29,30.0);
	    glVertex3f(6.62,103.21,30.0);
	    
    glEnd();
     glColor3f(0.91,0.91,0.91);//blanco
    	glBegin(GL_QUADS);//costado2 pizarra
	    glVertex3f(-1.03,95.71,25.0);
	    glVertex3f(-0.95,95.64,25.0);
	   	  glVertex3f(-0.95,95.64,30.0);
	     glVertex3f(-1.03,95.71,30.0);
    glEnd();
   glColor3f(0.91,0.91,0.91);//blanco
      	glBegin(GL_QUADS);//superiorpizarra
	    glVertex3f(-0.95,95.64,30.0);
	     glVertex3f(-1.03,95.71,30.0);
	    glVertex3f(6.55,103.29,30.0);
	    glVertex3f(6.62,103.21,30.0);
	  
    glEnd();

glColor3f(0.42,0.43,0.42);//darkgray
	glBegin(GL_QUADS);//atraspizarra1
	    glVertex3f(-1.03,95.71,30.0);
	    glVertex3f(6.55,103.29,30.0);
	    glVertex3f(6.55,103.29,25.0);
	    glVertex3f(-1.03,95.71,25.0);
    glEnd();
   
    
       glColor3f(0.69,0.71,0.69);//darkgray
    
    	glBegin(GL_QUADS);//TRIANGULO SUpizarra
	    glVertex3f(2.51,99.75,30.0);
		glVertex3f(3.01,99.75,30.0);
	    glVertex3f(2.51,99.25,30.0);
	    glVertex3f(2.51,99.75,30.0);
	  
    glEnd();
     //aca
    glColor3f(0.67,0.69,0.80);//darkgray
    	glBegin(GL_QUADS);//costado1  
	     glVertex3f(2.51,99.25,30.0);
	    glVertex3f(2.51,99.75,30.0);
	  glVertex3f(2.51,99.75,00.0);
	   glVertex3f(2.51,99.25,00.0);
    glEnd();
    
    	glBegin(GL_QUADS);//costado1  
	     glVertex3f(3.01,99.75,30.0);
	    glVertex3f(2.51,99.25,30.0);
	  glVertex3f(2.51,99.25,00.0);
	   glVertex3f(3.01,99.75,00.0);
    glEnd();
    //tramas aca---
      //otro
	    
	  
    glEnd();
     glColor3f(0.69,0.71,0.69);//darkgray
    	glBegin(GL_QUADS);//costado2mm
	    glVertex3f(2.51,99.75,30.0);
		glVertex3f(3.01,99.75,30.0);
		glVertex3f(3.01,99.75,00.0);
	    glVertex3f(2.51,99.75,00.0);
	
    glEnd();
    ///falta trama
	
    	    glColor3f(0.69,0.71,0.69);//darkgray
    
    	glBegin(GL_TRIANGLES);//TRIANGULO SUpizarra
	    glVertex3f(3.01,99.25,25.0);
	    glVertex3f(2.51,99.25,25.0);
	    glVertex3f(3.01,99.75,25.0);
	    
	  
    glEnd();
    
     glColor3f(0.67,0.69,0.80);//blanco
    
    	glBegin(GL_QUADS);//trama
	      glVertex3f(3.01,99.25,25.0);
	    glVertex3f(2.51,99.25,25.0);
	    glVertex3f(2.51,99.25,0.0);
	     glVertex3f(3.01,99.25,0.0);
	
    glEnd();
  ///trama
  glColor3f(0.43,0.44,0.44);
	glBegin(GL_QUADS);//
	     glVertex3f(3.01,99.25,25.0);
	    glVertex3f(3.01,99.75,25.0);
	    glVertex3f(3.01,99.75,00.0);
	      glVertex3f(3.01,99.25,00.0);
    glEnd();
}

void Sombras_Torretas(){

	 glColor3f(0.34,0.41,0.31);//darkgray
    glBegin(GL_QUADS);//pizarrafrontal
	    glVertex3f(23.27,151.03, 0.0);
	    glVertex3f(30.98,158.69, 0.0);
	    glVertex3f(26.87,149.30, 0.0);
	    glVertex3f(19.29,141.87, 0.0);
    glEnd();
    
     glBegin(GL_QUADS);//triangulo
	    glVertex3f(27.39,155.16, 0.0);
	    glVertex3f(26.87,155.16, 0.0);
	    glVertex3f(26.46,154.22, 0.0);
	    glVertex3f(27.39,155.16, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(23.27,145.74, 0.0);
	    glVertex3f(22.27,144.71, 0.0);
	    glVertex3f(2.51,99.75, 0.0);
	    glVertex3f(3.01,99.75, 0.0);
	    glVertex3f(3.01,99.25, 0.0);
	    glVertex3f(23.27,145.34, 0.0);
    glEnd();
    	 glColor3f(0.39,0.42,0.24);
    	 
    	  glBegin(GL_QUADS);//pizarrafrontal
	    glVertex3f(144.90,151.61, 0.0);
	    glVertex3f(138.29,158.18, 0.0);
	    glVertex3f(134.20,148.87, 0.0);
	    glVertex3f(140.76,142.25, 0.0);
    glEnd();
    
     glBegin(GL_QUADS);//triangulo
	    glVertex3f(141.86,155.19, 0.0);
	    glVertex3f(141.33,155.19, 0.0);
	    glVertex3f(141.86,154.59, 0.0);
	    glVertex3f(141.86,155.19, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(137.26,145.78, 0.0);
	    glVertex3f(137.81,145.39, 0.0);
	    glVertex3f(116.99,99.75, 0.0);
	    glVertex3f(117.49,99.75, 0.0);
	    glVertex3f(117,99.25, 0.0);
	   
    glEnd();
    

}

void Cerco_Campo(){
	glColor3f(0.3,1.0,0.8);
	
    glBegin(GL_POLYGON);
	    glVertex3f(-13.12, 91.64, 1.50);
	    glVertex3f(-3.09, 99.19, 1.50);
	    glVertex3f(-3.09, 99.19, 0.0);
	    glVertex3f(-13.12, 91.64, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-20.34, 84.02, 1.5);
	    glVertex3f(-13.26, 91.51, 1.5);
	    glVertex3f(-13.26, 91.51, 0.0);
	    glVertex3f(-20.34, 84.02, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-26.18, 75.3, 1.5);
	    glVertex3f(-20.46, 83.86, 1.5);
	    glVertex3f(-20.46, 83.86, 0.0);
	    glVertex3f(-26.18, 75.3, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-30.49, 65.72, 1.5);
	    glVertex3f(-26.28, 75.13, 1.5);
	    glVertex3f(-26.28, 75.13, 0.0);
	    glVertex3f(-30.49, 65.72, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-33.12, 55.56, 1.5);
	    glVertex3f(-30.55, 65.53, 1.5);
	    glVertex3f(-30.55, 65.53, 0.0);
	    glVertex3f(-33.12, 55.56, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-34.02, 45.10, 1.5);
	    glVertex3f(-33.15, 55.36, 1.5);
	    glVertex3f(-33.15, 55.36, 0.0);
	    glVertex3f(-34.02, 45.10, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-33.16, 34.64, 1.5);
	    glVertex3f(-34.02, 44.90, 1.5);
	    glVertex3f(-34.02, 44.90, 0.0);
	    glVertex3f(-33.16, 34.64, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-30.55, 24.47, 1.5);
	    glVertex3f(-33.12, 34.44, 1.5);
	    glVertex3f(-33.12, 34.44, 0.0);
	    glVertex3f(-30.55, 24.47, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-26.27, 14.88, 1.5);
	    glVertex3f(-30.49, 24.28, 1.5);
	    glVertex3f(-30.49, 24.28, 0.0);
	    glVertex3f(-26.27, 14.88, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(-20.46, 6.13, 1.5);
	    glVertex3f(-26.18, 14.70, 1.50);
	    glVertex3f(-26.18, 14.70, 0.0);
	    glVertex3f(-20.46, 6.13, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(-13.27, -1.51, 1.5);
	    glVertex3f(-20.34, 5.98, 1.5);
	    glVertex3f(-20.34, 5.98, 0.0);
	    glVertex3f(-13.27, -1.51, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(-3.09, -9.19, 1.5);
	    glVertex3f(-13.12, -1.64, 1.5);
	    glVertex3f(-13.12, -1.64, 0.0);
	    glVertex3f(-3.09, -9.19, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(-2.91, -9.25, 1.5);
	    glVertex3f(122.91, -9.25, 1.5);
	    glVertex3f(122.91, -9.25, 0.0);
	    glVertex3f(-2.91, -9.25, 0.0);
    glEnd();

	glBegin(GL_POLYGON);
	    glVertex3f(-2.91, 99.25, 1.5);
	    glVertex3f(122.91, 99.25, 1.5);
	    glVertex3f(122.91, 99.25, 0.0);
	    glVertex3f(-2.91, 99.25, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.09, 99.19, 1.5);
	    glVertex3f(133.12, 91.64, 1.5);
	    glVertex3f(133.12, 91.64, 0.0);
	    glVertex3f(123.09, 99.19, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(133.26, 91.51, 1.5);
	    glVertex3f(140.34, 84.02, 1.5);
	    glVertex3f(140.34, 84.02, 0.0);
	    glVertex3f(133.26, 91.51, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(140.46, 83.87, 1.5);
	    glVertex3f(146.18, 75.30, 1.5);
	    glVertex3f(146.18, 75.30, 0.0);
	    glVertex3f(140.46, 83.87, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(146.28, 75.13, 1.5);
	    glVertex3f(150.49, 65.72, 1.5);
	    glVertex3f(150.49, 65.72, 0.0);
	    glVertex3f(146.28, 75.13, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(150.55, 65.53, 1.5);
	    glVertex3f(153.12, 55.56, 1.5);
	    glVertex3f(153.12, 55.56, 0.0);
	    glVertex3f(150.55, 65.53, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(153.16, 55.36, 1.5);
	    glVertex3f(154.02, 45.10, 1.5);
	    glVertex3f(154.02, 45.10, 0.0);
	    glVertex3f(153.16, 55.36, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(154.02, 44.90, 1.5);
	    glVertex3f(153.16, 34.64, 1.5);
	    glVertex3f(153.16, 34.64, 0.0);
	    glVertex3f(154.02, 44.90, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(153.12, 34.44, 1.5);
	    glVertex3f(150.55, 24.47, 1.5);
	    glVertex3f(150.55, 24.47, 0.0);
	    glVertex3f(153.12, 34.44, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(150.49, 24.28, 1.5);
	    glVertex3f(146.28, 14.87, 1.5);
	    glVertex3f(146.28, 14.87, 0.0);
	    glVertex3f(150.49, 24.28, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(146.18, 14.70, 1.5);
	    glVertex3f(140.46, 6.13, 1.5);
	    glVertex3f(140.46, 6.13, 0.0);
	    glVertex3f(146.18, 14.70, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(140.34, 5.98, 1.5);
	    glVertex3f(133.27, -1.51, 1.5);
	    glVertex3f(133.27, -1.51, 0.0);
	    glVertex3f(140.34, 5.98, 0.0);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(133.12, -1.64, 1.5);
	    glVertex3f(123.09, -9.19, 1.5);
	    glVertex3f(123.09, -9.19, 0.0);
	    glVertex3f(133.12, -1.64, 0.0);
    glEnd();
	
}

void Arcos(){
	glColor3f(1.0,1.0,1.0);
	
	//Izquierda
	glBegin(GL_POLYGON);
	    glVertex3f(0.0, 41.26, 2.52);
	    glVertex3f(0.08, 41.26, 2.52);
	    glVertex3f(0.08, 41.26, 0.0);
	    glVertex3f(0.0, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 48.74, 2.52);
	    glVertex3f(0.08, 48.74, 2.52);
	    glVertex3f(0.08, 41.26, 2.52);
	    glVertex3f(0.0, 41.26, 2.52);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.08, 48.74, 2.52);
	    glVertex3f(0.0, 48.74, 2.52);
	    glVertex3f(0.0, 48.74, 0.0);
	    glVertex3f(0.08, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.08, 41.34, 2.44);
	    glVertex3f(0.0, 41.34, 2.44);
	    glVertex3f(0.0, 41.34, 0.0);
	    glVertex3f(0.08, 41.34, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.08, 41.34, 2.44);
	    glVertex3f(0.0, 41.34, 2.44);
	    glVertex3f(0.0, 48.66, 2.44);
	    glVertex3f(0.08, 48.66, 2.44);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 48.66, 2.44);
	    glVertex3f(0.08, 48.66, 2.44);
	    glVertex3f(0.08, 48.66, 0.0);
	    glVertex3f(0.0, 48.66, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.08, 41.26, 2.52);
	    glVertex3f(0.08, 41.34, 2.52);
	    glVertex3f(0.08, 41.34, 0.0);
	    glVertex3f(0.08, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.08, 41.34, 2.44);
	    glVertex3f(0.08, 41.34, 2.52);
	    glVertex3f(0.08, 48.66, 2.52);
	    glVertex3f(0.08, 48.66, 2.44);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.08, 48.66, 2.52);
	    glVertex3f(0.08, 48.74, 2.52);
	    glVertex3f(0.08, 48.74, 0.0);
	    glVertex3f(0.08, 48.66, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 41.26, 2.52);
	    glVertex3f(0.0, 41.34, 2.52);
	    glVertex3f(0.0, 41.34, 0.0);
	    glVertex3f(0.0, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 41.34, 2.44);
	    glVertex3f(0.0, 41.34, 2.52);
	    glVertex3f(0.0, 48.66, 2.52);
	    glVertex3f(0.0, 48.66, 2.44);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(0.0, 48.66, 2.52);
	    glVertex3f(0.0, 48.74, 2.52);
	    glVertex3f(0.0, 48.74, 0.0);
	    glVertex3f(0.0, 48.66, 0.0);
    glEnd();
    
    //Derecha
    glBegin(GL_POLYGON);
	    glVertex3f(119.92, 41.26, 2.52);
	    glVertex3f(120.00, 41.26, 2.52);
	    glVertex3f(120.00, 41.26, 0.0);
	    glVertex3f(119.92, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(119.92, 48.74, 2.52);
	    glVertex3f(120.00, 48.74, 2.52);
	    glVertex3f(120.00, 41.26, 2.52);
	    glVertex3f(119.92, 41.26, 2.52);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.00, 48.74, 2.52);
	    glVertex3f(119.92, 48.74, 2.52);
	    glVertex3f(119.92, 48.74, 0.0);
	    glVertex3f(120.00, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.00, 41.34, 2.44);
	    glVertex3f(119.92, 41.34, 2.44);
	    glVertex3f(119.92, 41.34, 0.0);
	    glVertex3f(120.00, 41.34, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.00, 41.34, 2.44);
	    glVertex3f(119.92, 41.34, 2.44);
	    glVertex3f(119.92, 48.66, 2.44);
	    glVertex3f(120.00, 48.66, 2.44);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(119.92, 48.66, 2.44);
	    glVertex3f(120.00, 48.66, 2.44);
	    glVertex3f(120.00, 48.66, 0.0);
	    glVertex3f(119.92, 48.66, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(119.92, 48.74, 2.52);
	    glVertex3f(119.92, 48.66, 2.52);
	    glVertex3f(119.92, 48.66, 0.0);
	    glVertex3f(119.92, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(119.92, 48.66, 2.44);
	    glVertex3f(119.92, 48.66, 2.52);
	    glVertex3f(119.92, 41.34, 2.52);
	    glVertex3f(119.92, 41.34, 2.44);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(119.92, 41.34, 2.52);
	    glVertex3f(119.92, 41.26, 2.52);
	    glVertex3f(119.92, 41.26, 0.0);
	    glVertex3f(119.92, 41.34, 0.0);
    glEnd();  
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.00, 48.74, 2.52);
	    glVertex3f(120.00, 48.66, 2.52);
	    glVertex3f(120.00, 48.66, 0.0);
	    glVertex3f(120.00, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.00, 48.66, 2.44);
	    glVertex3f(120.00, 48.66, 2.52);
	    glVertex3f(120.00, 41.34, 2.52);
	    glVertex3f(120.00, 41.34, 2.44);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(120.00, 41.34, 2.52);
	    glVertex3f(120.00, 41.26, 2.52);
	    glVertex3f(120.00, 41.26, 0.0);
	    glVertex3f(120.00, 41.34, 0.0);
    glEnd();

}

void Corners(){
	glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    Crear_CilindrosV1();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0.0, 0.0, 1.05);
    Crear_CilindrosV2();
	glPopMatrix();
	
    glBegin(GL_POLYGON);
   		glVertex3f(0.0, 0.0, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(0.0 + sin((float)count) * 0.025, 0.0 + cos((float)count) * 0.025, 1.5);	
		}
	glEnd();
	glBegin(GL_POLYGON);
   		glVertex3f(0.0, 0.0, 1.5);
   		glVertex3f(0.55, 0.0, 1.5);
   		glVertex3f(0.55, 0.0, 1.05);
   		glVertex3f(0.0, 0.0, 1.05);
	glEnd();
	
	
	glPushMatrix();
    glTranslatef(0.0, 90.0, 0.0);
    Crear_CilindrosV1();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(0.0, 90.0, 1.05);
    Crear_CilindrosV2();
	glPopMatrix();
	
    glBegin(GL_POLYGON);
   		glVertex3f(0.0, 90.0, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(0.0 + sin((float)count) * 0.025, 90.0 + cos((float)count) * 0.025, 1.5);	
		}
	glEnd();
	glBegin(GL_POLYGON);
   		glVertex3f(0.0, 90.0, 1.5);
   		glVertex3f(0.55, 90.0, 1.5);
   		glVertex3f(0.55, 90.0, 1.05);
   		glVertex3f(0.0, 90.0, 1.05);
	glEnd();
	
	
	glPushMatrix();
    glTranslatef(120.0, 90.0, 0.0);
    Crear_CilindrosV1();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(120.0, 90.0, 1.05);
    Crear_CilindrosV2();
	glPopMatrix();
	
    glBegin(GL_POLYGON);
   		glVertex3f(120.0, 90.0, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(120.0 + sin((float)count) * 0.025, 90.0 + cos((float)count) * 0.025, 1.5);	
		}
	glEnd();
	glBegin(GL_POLYGON);
   		glVertex3f(120.0, 90.0, 1.5);
   		glVertex3f(120.55, 90.0, 1.5);
   		glVertex3f(120.55, 90.0, 1.05);
   		glVertex3f(120.0, 90.0, 1.05);
	glEnd();
	
	
	glPushMatrix();
    glTranslatef(120.0, 0.0, 0.0);
    Crear_CilindrosV1();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(120.0, 0.0, 1.05);
    Crear_CilindrosV2();
	glPopMatrix();
	
    glBegin(GL_POLYGON);
   		glVertex3f(120.0, 0.0, 1.5);
   		for(int count=0; count<=360; count++){
   			glVertex3f(120.0 + sin((float)count) * 0.025, 0.0 + cos((float)count) * 0.025, 1.5);	
		}
	glEnd();
	glBegin(GL_POLYGON);
   		glVertex3f(120.0, 0.0, 1.5);
   		glVertex3f(120.55, 0.0, 1.5);
   		glVertex3f(120.55, 0.0, 1.05);
   		glVertex3f(120.0, 0.0, 1.05);
	glEnd();
	
	
	
}

void Tribuna_Secundaria(){
	//Piso
	glColor3f(0.55,0.51,0.49);
	glBegin(GL_POLYGON);
	    glVertex3f(123.01, -21.25, 0.0);
	    glVertex3f(123.01, -9.25, 0.0);
	    glVertex3f(128.01, -5.48, 0.0);
	    glVertex3f(128.01, -21.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -21.25, 0.0);
	    glVertex3f(-3.01, -11.87, 0.0);
	    glVertex3f(123.01, -11.87, 0.0);
	    glVertex3f(123.01, -21.25, 0.0);
    glEnd();
    
    glColor3f(0.67,0.68,0.68);
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -11.87, 0.0);
	    glVertex3f(-3.01, -9.25, 0.0);
	    glVertex3f(123.01, -9.25, 0.0);
	    glVertex3f(123.01, -11.87, 0.0);
    glEnd();
    
    glColor3f(0.65,0.65,0.65);
    //Laterales
    for(int i=0; i<=16; i++){
    	glBegin(GL_POLYGON);
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.37-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.37-(i*0.50), 0.80+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 0.80+(i*0.40));
    	glEnd();
    	
    	glBegin(GL_POLYGON);
	    	glVertex3f(-3.01-(i*0.0), -12.37-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(-3.01-(i*0.0), -12.87-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(-3.01-(i*0.0), -12.87-(i*0.50), 0.80+(i*0.40));
	    	glVertex3f(-3.01-(i*0.0), -12.37-(i*0.50), 0.80+(i*0.40));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -11.87, 1.20);
	    glVertex3f(-3.01, -12.37, 1.20);
	    glVertex3f(-3.01, -12.37, 0.0);
	    glVertex3f(-3.01, -11.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -20.87, 7.60);
	    glVertex3f(-3.01, -21.25, 7.60);
	    glVertex3f(-3.01, -21.25, 0.0);
	    glVertex3f(-3.01, -20.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -12.37, 1.20);
	    glVertex3f(123.01, -11.87, 1.20);
	    glVertex3f(123.01, -11.87, 0.0);
	    glVertex3f(123.01, -12.37, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -21.25, 7.60);
	    glVertex3f(123.01, -20.87, 7.60);
	    glVertex3f(123.01, -20.87, 0.0);
	    glVertex3f(123.01, -21.25, 0.0);
    glEnd();

	//Parado
	//Delantero
	glColor3f(0.87,0.90,1.00);
	for(int i=0; i<=15; i++){
    	glBegin(GL_POLYGON);
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 1.60+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.87-(i*0.50), 1.60+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
    	glEnd();
	}
	
	//Trasero
	for(int i=0; i<=16; i++){
    	glBegin(GL_POLYGON);
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 0.80+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.87-(i*0.50), 0.80+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -12.37, 0.80);
	    glVertex3f(-2.51, -12.37, 0.80);
	    glVertex3f(-2.51, -12.37, 0.0);
	    glVertex3f(-3.01, -12.37, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.51, -12.37, 0.80);
	    glVertex3f(123.01, -12.37, 0.80);
	    glVertex3f(123.01, -12.37, 0.0);
	    glVertex3f(122.51, -12.37, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.63, -21.25, 7.20);
	    glVertex3f(123.01, -21.25, 7.20);
	    glVertex3f(123.01, -21.25, 0.0);
	    glVertex3f(122.63, -21.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -21.25, 7.60);
	    glVertex3f(123.01, -21.25, 7.20);
	    glVertex3f(-3.01, -21.25, 7.20);
	    glVertex3f(-3.01, -21.25, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -21.25, 7.20);
	    glVertex3f(-2.63, -21.25, 7.20);
	    glVertex3f(-2.63, -21.25, 0.0);
	    glVertex3f(-3.01, -21.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-2.63, -20.87, 7.20);
	    glVertex3f(-3.01, -20.87, 7.20);
	    glVertex3f(-3.01, -20.87, 0.0);
	    glVertex3f(-2.63, -20.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -20.87, 7.20);
	    glVertex3f(122.63, -20.87, 7.20);
	    glVertex3f(122.63, -20.87, 0.0);
	    glVertex3f(123.01, -20.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-2.51, -11.87, 0.80);
	    glVertex3f(-3.01, -11.87, 0.80);
	    glVertex3f(-3.01, -11.87, 0.0);
	    glVertex3f(-2.51, -11.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -11.87, 1.20);
	    glVertex3f(-3.01, -11.87, 0.80);
	    glVertex3f(123.01, -11.87, 0.80);
	    glVertex3f(123.01, -11.87, 1.20);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -11.87, 0.80);
	    glVertex3f(122.51, -11.87, 0.80);
	    glVertex3f(122.51, -11.87, 0.0);
	    glVertex3f(123.01, -11.87, 0.0);
    glEnd();
    
    //Echado
    //Arriba
    glColor3f(0.67,0.69,0.80);
    for(int i=0; i<=16; i++){
    	glBegin(GL_POLYGON);
	    	glVertex3f(123.01-(i*0), -12.37-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.87-(i*0.50), 1.20+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.37-(i*0.50), 1.20+(i*0.40));
    	glEnd();
	}
	
	//Abajo
    for(int i=0; i<=16; i++){
    	glBegin(GL_POLYGON);
	    	glVertex3f(123.01-(i*0), -12.37-(i*0.50), 0.8+(i*0.40));
	    	glVertex3f(123.01-(i*0), -12.87-(i*0.50), 0.8+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.87-(i*0.50), 0.8+(i*0.40));
	    	glVertex3f(-3.01-(i*0), -12.37-(i*0.50), 0.8+(i*0.40));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -12.37, 1.20);
	    glVertex3f(-3.01, -11.87, 1.20);
	    glVertex3f(123.01, -11.87, 1.20);
	    glVertex3f(123.01, -12.37, 1.20);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-3.01, -21.25, 7.60);
	    glVertex3f(-3.01, -20.87, 7.60);
	    glVertex3f(123.01, -20.87, 7.60);
	    glVertex3f(123.01, -21.25, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.51, -11.87, 0.80);
	    glVertex3f(122.51, -12.37, 0.80);
	    glVertex3f(-2.51, -12.37, 0.80);
	    glVertex3f(-2.51, -11.87, 0.80);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-2.63, -21.25, 7.20);
	    glVertex3f(-2.63, -20.87, 7.20);
	    glVertex3f(122.63, -20.87, 7.20);
	    glVertex3f(122.63, -21.25, 7.20);
    glEnd();
	
    glBegin(GL_POLYGON);
	    glVertex3f(122.63, -20.87, 7.20);
	    glVertex3f(122.63, -21.25, 7.20);
	    glVertex3f(122.63, -21.25, 0.0);
	    glVertex3f(122.63, -20.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-2.63, -21.25, 7.20);
	    glVertex3f(-2.63, -20.87, 7.20);
	    glVertex3f(-2.63, -20.87, 0.0);
	    glVertex3f(-2.63, -21.25, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(-2.51, -12.37, 0.80);
	    glVertex3f(-2.51, -11.87, 0.80);
	    glVertex3f(-2.51, -11.87, 0.0);
	    glVertex3f(-2.51, -12.37, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.51, -11.87, 0.80);
	    glVertex3f(122.51, -12.37, 0.80);
	    glVertex3f(122.51, -12.37, 0.0);
	    glVertex3f(122.51, -11.87, 0.0);
    glEnd();
}

void Escalera(){
	
	//Laterales
	glColor3f(0.65,0.65,0.65);
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.91, -12.87, 0.20);
	    glVertex3f(124.21, -12.87, 0.20);
	    glVertex3f(124.21, -12.87, 0.0);
	    glVertex3f(123.91, -12.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(124.21, -11.87, 0.20);
	    glVertex3f(123.91, -11.87, 0.20);
	    glVertex3f(123.91, -11.87, 0.0);
	    glVertex3f(124.21, -11.87, 0.0);
    glEnd();
	
	for(int i=0; i<3; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(123.61-(i*0.30), -12.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -12.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(123.61-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.01, -12.87, 0.70);
	    glVertex3f(123.11, -12.87, 0.70);
	    glVertex3f(123.11, -12.87, 0.0);
	    glVertex3f(123.01, -12.87, 0.0);
    glEnd();
    
    for(int i=0; i<3; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(123.91-(i*0.30), -11.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.61-(i*0.30), -11.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.61-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.11, -12.77, 0.70);
	    glVertex3f(123.01, -12.77, 0.70);
	    glVertex3f(123.01, -12.77, 0.0);
	    glVertex3f(123.11, -12.77, 0.0);
    glEnd();
    
    for(int i=0; i<5; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(124.21-(i*0.30), -11.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
    	
    	glBegin(GL_POLYGON);
	    	glVertex3f(124.21-(i*0.30), -12.82-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.82-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.82-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.82-(i*0.0), 0.20+(i*0.25));
    	glEnd();
    	
    	glBegin(GL_POLYGON);	
	    	glVertex3f(124.16-(i*0.30), -11.92-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.92-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.92-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.92-(i*0.0), 0.20+(i*0.25));	
    	glEnd();
    	
    	glBegin(GL_POLYGON);	
	    	glVertex3f(124.16-(i*0.30), -12.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));	
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.01, -12.87, 2.60);
	    glVertex3f(122.96, -12.87, 2.60);
	    glVertex3f(122.96, -12.87, 2.20);
	    glVertex3f(123.01, -12.87, 2.20);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.96, -12.92, 2.60);
	    glVertex3f(123.01, -12.92, 2.60);
	    glVertex3f(123.01, -12.92, 1.60);
	    glVertex3f(122.96, -12.92, 1.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.26, -11.87, 1.95);
	    glVertex3f(123.01, -11.87, 2.20);
	    glVertex3f(123.01, -11.87, 2.15);
	    glVertex3f(123.26, -11.87, 1.90);
    glEnd();
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.01, -11.92, 2.20);
	    glVertex3f(123.26, -11.92, 1.95);
	    glVertex3f(123.26, -11.92, 1.90);
	    glVertex3f(123.01, -11.92, 2.15);
    glEnd();
    
    //Echado
    glColor3f(0.67,0.69,0.80);
    for(int i=0; i<3; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(123.61-(i*0.30), -12.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.61-(i*0.30), -11.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -11.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -12.87-(i*0.0), 0.45+(i*0.25));
    	glEnd();
	}
	
	for(int i=0; i<3; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(123.61-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(123.61-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.91, -12.87, 0.20);
	    glVertex3f(123.91, -11.87, 0.20);
	    glVertex3f(124.21, -11.87, 0.20);
	    glVertex3f(124.21, -12.87, 0.20);
    glEnd();
    
    for(int i=0; i<5; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(124.16-(i*0.30), -11.92-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.92-(i*0.0), 1.20+(i*0.25));
    	glEnd();
    	
    	glBegin(GL_POLYGON);
	    	glVertex3f(124.16-(i*0.30), -12.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.82-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.82-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.87-(i*0.0), 1.20+(i*0.25));
    	glEnd();
	}
	
	glBegin(GL_POLYGON);
	    glVertex3f(122.96, -12.92, 2.60);
	    glVertex3f(122.96, -12.87, 2.60);
	    glVertex3f(123.01, -12.87, 2.60);
	    glVertex3f(123.01, -12.92, 2.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -11.92, 2.20);
	    glVertex3f(123.01, -11.87, 2.20);
	    glVertex3f(123.26, -11.87, 1.95);
	    glVertex3f(123.26, -11.92, 1.95);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.26, -11.87, 1.90);
	    glVertex3f(123.26, -11.92, 1.90);
	    glVertex3f(123.01, -11.92, 2.15);
	    glVertex3f(123.01, -11.87, 2.15);
    glEnd();
    
	//Parados
	glColor3f(0.87,0.90,1.00);
	
	glBegin(GL_POLYGON);
	    glVertex3f(124.21, -12.87, 0.20);
	    glVertex3f(124.21, -11.87, 0.20);
	    glVertex3f(124.21, -11.87, 0.0);
	    glVertex3f(124.21, -12.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.91, -11.87, 0.20);
	    glVertex3f(123.91, -12.87, 0.20);
	    glVertex3f(123.91, -12.87, 0.0);
	    glVertex3f(123.91, -11.87, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.31, -11.87, 0.70);
	    glVertex3f(123.31, -12.87, 0.70);
	    glVertex3f(123.31, -12.87, 0.45);
	    glVertex3f(123.31, -11.87, 0.45);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.61, -11.87, 0.45);
	    glVertex3f(123.61, -12.87, 0.45);
	    glVertex3f(123.61, -12.87, 0.20);
	    glVertex3f(123.61, -11.87, 0.20);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -12.37, 0.95);
	    glVertex3f(123.01, -12.87, 0.95);
	    glVertex3f(123.01, -12.87, 0.70);
	    glVertex3f(123.01, -12.37, 0.70);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -12.77, 0.70);
	    glVertex3f(123.01, -12.87, 0.70);
	    glVertex3f(123.01, -12.87, 0.0);
	    glVertex3f(123.01, -12.77, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.11, -12.87, 0.70);
	    glVertex3f(123.11, -12.77, 0.70);
	    glVertex3f(123.11, -12.77, 0.0);
	    glVertex3f(123.11, -12.87, 0.0);
    glEnd();
    
    for(int i=0; i<3; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(123.91-(i*0.30), -12.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -11.87-(i*0.0), 0.45+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(123.91-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
	}
	
	for(int i=0; i<5; i++){
		glBegin(GL_POLYGON);
	    	glVertex3f(124.21-(i*0.30), -11.92-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -11.92-(i*0.0), 0.20+(i*0.25));
    	glEnd();
    	
    	glBegin(GL_POLYGON);
	    	glVertex3f(124.21-(i*0.30), -12.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.82-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.82-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.21-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
    	
    	glBegin(GL_POLYGON);
	    	glVertex3f(124.16-(i*0.30), -11.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.92-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.92-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -11.87-(i*0.0), 0.20+(i*0.25));
    	glEnd();
    	
    	glBegin(GL_POLYGON);
	    	glVertex3f(124.16-(i*0.30), -12.82-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.87-(i*0.0), 1.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.87-(i*0.0), 0.20+(i*0.25));
	    	glVertex3f(124.16-(i*0.30), -12.82-(i*0.0), 0.20+(i*0.25));
    	glEnd();
	}
	
    glBegin(GL_POLYGON);
	    glVertex3f(122.96, -12.87, 2.60);
	    glVertex3f(122.96, -12.92, 2.60);
	    glVertex3f(122.96, -12.92, 1.60);
	    glVertex3f(122.96, -12.87, 1.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -12.92, 2.60);
	    glVertex3f(123.01, -12.87, 2.60);
	    glVertex3f(123.01, -12.87, 1.60);
	    glVertex3f(123.01, -12.92, 1.60);
    glEnd();
    
}

void Otros(){
	//Laterales
	glColor3f(0.65,0.65,0.65);
	
	glBegin(GL_POLYGON);
	    glVertex3f(123.01, -20.42, 8.60);
	    glVertex3f(123.01, -20.37, 8.60);
	    glVertex3f(123.01, -20.37, 7.60);
	    glVertex3f(123.01, -20.42, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -21.25, 8.60);
	    glVertex3f(123.01, -21.20, 8.60);
	    glVertex3f(123.01, -21.20, 7.60);
	    glVertex3f(123.01, -21.25, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.96, -20.37, 8.60);
	    glVertex3f(122.96, -20.42, 8.60);
	    glVertex3f(122.96, -20.42, 7.60);
	    glVertex3f(122.96, -20.37, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.96, -21.20, 8.60);
	    glVertex3f(122.96, -21.25, 8.60);
	    glVertex3f(122.96, -21.25, 7.60);
	    glVertex3f(122.96, -21.20, 7.60);
    glEnd();
    
    //Paradas
    glColor3f(0.87,0.90,1.00);
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.96, -20.42, 8.60);
	    glVertex3f(123.01, -20.42, 8.60);
	    glVertex3f(123.01, -20.42, 7.60);
	    glVertex3f(122.96, -20.42, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(122.96, -21.25, 8.60);
	    glVertex3f(123.01, -21.25, 8.60);
	    glVertex3f(123.01, -21.25, 7.60);
	    glVertex3f(122.96, -21.25, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -21.20, 8.60);
	    glVertex3f(122.96, -21.20, 8.60);
	    glVertex3f(122.96, -21.20, 7.60);
	    glVertex3f(123.01, -21.20, 7.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -20.37, 8.60);
	    glVertex3f(122.96, -20.37, 8.60);
	    glVertex3f(122.96, -20.37, 7.60);
	    glVertex3f(123.01, -20.37, 7.60);
    glEnd();
    
    //Echado
    glColor3f(0.67,0.69,0.80);
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -21.25, 8.60);
	    glVertex3f(122.96, -21.25, 8.60);
	    glVertex3f(122.96, -21.20, 8.60);
	    glVertex3f(123.01, -21.20, 8.60);
    glEnd();
    
    glBegin(GL_POLYGON);
	    glVertex3f(123.01, -20.42, 8.60);
	    glVertex3f(122.96, -20.42, 8.60);
	    glVertex3f(122.96, -20.37, 8.60);
	    glVertex3f(123.01, -20.37, 8.60);
    glEnd();
}

void Red(){
	glColor3f(1.0,1.0,1.0);
    glLineWidth(0.5);
	
	//Derecha
	glBegin(GL_LINE_LOOP);
		glVertex3f(-3.00, 41.26, 2.52);
		glVertex3f(0.0, 41.26, 2.52);
		glVertex3f(0.0, 41.26, 0.0);
		glVertex3f(-3.00, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
		glVertex3f(-3.00, 48.74, 2.52);
		glVertex3f(0.0, 48.74, 2.52);
		glVertex3f(0.0, 48.74, 0.0);
		glVertex3f(-3.00, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
		glVertex3f(-3.00, 48.74, 2.52);
		glVertex3f(-3.00, 41.26, 2.52);
		glVertex3f(-3.00, 41.26, 0.0);
		glVertex3f(-3.00, 48.74, 0.0);
    glEnd();
    
    //Izquierda
    glBegin(GL_LINE_LOOP);
		glVertex3f(120.00, 41.26, 2.52);
		glVertex3f(123.00, 41.26, 2.52);
		glVertex3f(123.00, 41.26, 0.0);
		glVertex3f(120.00, 41.26, 0.0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
		glVertex3f(123.00, 48.74, 2.52);
		glVertex3f(120.00, 48.74, 2.52);
		glVertex3f(120.00, 48.74, 0.0);
		glVertex3f(123.00, 48.74, 0.0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
		glVertex3f(123.00, 41.26, 2.52);
		glVertex3f(123.00, 48.74, 2.52);
		glVertex3f(123.00, 48.74, 0.0);
		glVertex3f(123.00, 41.26, 0.0);
    glEnd();
    
    for(float i=0; i>=-3.00; i=i-0.2){
    	glBegin(GL_LINES);
			glVertex3f(0.0+i, 41.26, 2.52);
			glVertex3f(0.0+i, 41.26, 0.0);
    	glEnd();
	}
	
	for(float j=0; j<=2.52; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(-3.00, 41.26, 0.0+j);
			glVertex3f(0.0, 41.26, 0.0+j);
    	glEnd();
	}
    
    for(float i=0; i>=-3.00; i=i-0.2){
    	glBegin(GL_LINES);
			glVertex3f(0.0+i, 48.74, 2.52);
			glVertex3f(0.0+i, 48.74, 0.0);
    	glEnd();
	}
	
	for(float j=0; j<=2.52; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(-3.00, 48.74, 0.0+j);
			glVertex3f(0.0, 48.74, 0.0+j);
    	glEnd();
	}
	
	
	for(float i=0.0; i<=3.0; i=i+0.2){
    	glBegin(GL_LINES);
			glVertex3f(120.0+i, 41.26, 2.52);
			glVertex3f(120.0+i, 41.26, 0.0);
    	glEnd();
	}
	
	for(float j=0; j<=2.52; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(120.0, 41.26, 0.0+j);
			glVertex3f(123.0, 41.26, 0.0+j);
    	glEnd();
	}
	
	for(float i=0.0; i<=3.0; i=i+0.2){
    	glBegin(GL_LINES);
			glVertex3f(120.0+i, 48.74, 2.52);
			glVertex3f(120.0+i, 48.74, 0.0);
    	glEnd();
	}
	
	for(float j=0; j<=2.52; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(120.0, 48.74, 0.0+j);
			glVertex3f(123.0, 48.74, 0.0+j);
    	glEnd();
	}
	
	
	for(float i=0.0; i<=7.48; i=i+0.2){
    	glBegin(GL_LINES);
			glVertex3f(-3.00, 41.26+i, 2.52);
			glVertex3f(-3.00, 41.26+i, 0.0);
    	glEnd();
	}
	
	for(float j=0; j<=2.52; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(-3.00, 48.74, 0.0+j);
			glVertex3f(-3.00, 41.26, 0.0+j);
    	glEnd();
	}
	
	for(float i=0.0; i<=7.48; i=i+0.2){
    	glBegin(GL_LINES);
			glVertex3f(123.00, 41.26+i, 2.52);
			glVertex3f(123.00, 41.26+i, 0.0);
    	glEnd();
	}
	
	for(float j=0; j<=2.52; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(123.00, 48.74, 0.0+j);
			glVertex3f(123.00, 41.26, 0.0+j);
    	glEnd();
	}
	
	for(float i=0.0; i<=7.48; i=i+0.2){
    	glBegin(GL_LINES);
			glVertex3f(0.00, 41.26+i, 2.52);
			glVertex3f(-3.00, 41.26+i, 2.52);
    	glEnd();
	}
	
	for(float j=0; j>=-3.00; j=j-0.2){
    	glBegin(GL_LINES);
			glVertex3f(0.0+j, 48.74, 2.52);
			glVertex3f(0.0+j, 41.26, 2.52);
    	glEnd();
	}
	
	for(float i=0.0; i<=7.48; i=i+0.2){
    	glBegin(GL_LINES);
			glVertex3f(120.00, 41.26+i, 2.52);
			glVertex3f(123.00, 41.26+i, 2.52);
    	glEnd();
	}
	
	for(float j=0; j<=3.00; j=j+0.2){
    	glBegin(GL_LINES);
			glVertex3f(120.0+j, 48.74, 2.52);
			glVertex3f(120.0+j, 41.26, 2.52);
    	glEnd();
	}
	
}

void Balon(){
	glColor3f(1.0,0.0,0.0);
	
	glPushMatrix();
    glTranslatef(60.0, 45.0, 0.3);
    glutSolidSphere(0.3,20,16);
	glPopMatrix();
	
}

// Funcion de dibujo
void display(){	// Creamos la funcion donde se dibuja
	//Limpia buffer de profundidad
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_PROJECTION);   ---------------------------------   
    glLoadIdentity();
    glTranslatef(posX, posY, posZ);
    //glTranslatef(pos_camX, pos_camY, pos_camZ);
    glRotatef(eye_camX, 1.0, 0.0, 0.0);
    glRotatef(eye_camY, 0.0, 1.0, 0.0);
    glRotatef(eye_camZ, 0.0, 0.0, 1.0);
         
    glPushMatrix();
	Campo_Futbol();
	Pasto_Extra();
	Pista_Atletica();
	Lineas_de_Campo();
	Lineas_de_Pista_Atletica();
	Cerco_Campo();
	Cercado_Cilindros();
	Banca_Grande();
	Casa();
	Torretas();
	Sombras_Torretas();
	Arcos();
	Corners();
	Letrero();
	Piso();
	Tribuna_Secundaria();
	Escalera();
	Otros();
	Red();
	Balon();
	glPopMatrix();	
	glFlush();
    glutSwapBuffers();
}

// Funcion de cambio de tamaño
void reshape(int w, int h){   
    glViewport(0, 0, w, h);    
	glMatrixMode(GL_PROJECTION);  // Seleccionamos Projection Matrix
	glLoadIdentity();
	gluPerspective(50.0, (GLfloat)w/(GLfloat)h, 1.0, 10000.0);
	//gluPerspective(300.0, (GLfloat)w/(GLfloat)h, 1.0, 10000.0);  
    // Perspectiva: glFrustum(left, right, bottom, top, near, far) 
    //glFrustum(-1, 1, -1, 1, 0.2, 100);
    //glOrtho(-20, 140, -20, 140, -300, 300);
    glMatrixMode(GL_MODELVIEW);   // Seleccionamos Modelview Matrix
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
 
//POSICION DE LA CAMARA keyboard()
//ZOOM: Lejos-Cerca TECLAS: W Y S
//MOVIMIENTO: izquierda-derecha TECLAS: A Y D
void keyboard(unsigned char key, int x, int y){
    switch (key){
    	case '+':
    		posZ += 0.5;
    		break;

    	case '-':
    		posZ -= 0.5;
    		break;
    		
        case 'w':   //Movimientos de camara
        case 'W':
            posY += 0.5;
            break;
                         
        case 's':
        case 'S':
            posY -= 0.5;
            break;
                         
        case 'a':
        case 'A':
            posX -= 0.5;
            break;
                        
    	case 'd':
        case 'D':
            posX += 0.5;
            break;
                         
        case 27:
            exit(0);   // Salimos del programa
            break;
                        
        default:               
        	break;
        }
        
        glutPostRedisplay();  //Indica a OpenGL Redibujar
 }

void arrow_keys(int a_keys, int x, int y){  // Funcion para manejo de teclas especiales (arrow keys)
 
    switch (a_keys) {
        case GLUT_KEY_PAGE_UP:
            pos_camY -= 0.5;
            break;
                        
        case GLUT_KEY_PAGE_DOWN:
            pos_camY += 0.5;
            break;
                         
        case GLUT_KEY_UP:     //Tecla arriba
            eye_camX = (eye_camX-5)%360;
            break;
                        
        case GLUT_KEY_DOWN:   //Tecla abajo
            eye_camX = (eye_camX+5)%360;
            break;
                        
        case GLUT_KEY_LEFT:  //Tecla izquierda
            eye_camY = (eye_camY-5)%360;
            break;
                        
        case GLUT_KEY_RIGHT:  //Tecla derecha
            eye_camY = (eye_camY+5)%360;
            break;
            
		default:
            break;
        }
        glutPostRedisplay();   //Indica a OpenGL Redibujar
}

 int main ( int argc, char** argv ){
    glutInit(&argc, argv);                       // Inicializamos OpenGL
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Display Mode (Clores RGB y alpha | Buffer Doble )
    glutInitWindowPosition(350, 25);    // Posicion de la Ventana
	glutInitWindowSize(1200, 950);   // Tamaño de la Ventana
    glutCreateWindow("Estadio T2"); // Nombre de la Ventana
    InitGL();                                  // Parametros iniciales de la aplicación
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);       // Funcion en caso de cambio de tamaño
    glutDisplayFunc(display);              // Funcion de dibujo
    glutKeyboardFunc(keyboard);     // Funcion de manejo de teclado
    glutSpecialFunc(arrow_keys);    // Otras funciones
    glutMainLoop();                             // Loop infinito, dibuja cuantas veces sea necesario
    return 0;                                       // Necesario para ANSI C
}

