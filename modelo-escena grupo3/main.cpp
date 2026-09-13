#include <windows.h>
#include <GL/freeglut.h>
#include <Math.h>
//Declaracion de Funciones
//EJES
void ejes(void);
//PARED FRONTAL
void piso(void);
void cama(void);
void puerta(void);
void paredIzquierda(void);
void paredDerecha(void);
void mesita(void);
void escritorio(void);
void patasEscritorio(void);
void ventana (void);
void sombra_triangular_ventana(void);

void inicializar()
{
	//fondo verde
    glClearColor(0.82f, 0.88f, 0.60f, 1.0f);
    //glColor3f(0.82f, 0.88f, 0.60f);
    //glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	gluOrtho2D(-100,100,-100,100);

    glMatrixMode(GL_MODELVIEW);
}

void dibujar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    
    //piso();
    glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	piso();
	glPopMatrix();
	
	//Pared Izquierda
	glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	paredIzquierda();
	glPopMatrix();
	
	//Pared Derecha
	glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	paredDerecha();
	glPopMatrix();

	// PUERTA
    glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	puerta();
	glPopMatrix();

	// Mesita
	glPushMatrix();
	glTranslatef(25.0f, -10.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	mesita();
	glPopMatrix();
	
	
	//Pata de escritorio izquierdo bajo
	glPushMatrix();
	glTranslatef(3.0f, 30.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//Pata de escritorio izquierdo alto
	glPushMatrix();
	glTranslatef(-8.0f, 37.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//Pata de escritorio derecho bajo
	glPushMatrix();
	glTranslatef(20.0f, 46.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//Pata de escritorio derecho alto
	glPushMatrix();
	glTranslatef(8.0f, 50.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	
	//Escritorio
	glPushMatrix();
	glTranslatef(-7.0f, 18.0f, 1.0f);
	escritorio();
	glPopMatrix();
	
	//Ventana
	glPushMatrix();
	ventana();
	glPopMatrix();
	

	// Cama
	glPushMatrix();
	glTranslatef(23.0f, -37.0f, 0.0f);
	glScalef(1.8f, 1.8f, 1.0f);
	cama();	
	glPopMatrix();
	

	
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("MODELO CUARTO 2D");

    inicializar();

    glutDisplayFunc(dibujar);

    glutMainLoop();
    return 0;
}

void piso()
{
    glColor3f(0.75f,0.45f,0.30f);

    glBegin(GL_POLYGON);
        glVertex2f(10,-125);
        glVertex2f(95,-15);
        glVertex2f(20,40);
        glVertex2f(-80,-40);
    glEnd();
    
    // Líneas horizontales
	glColor3f(0.55f, 0.30f, 0.18f);
	glBegin(GL_LINES);
	
	//Superiores
	glVertex2f(-75,-44);
	glVertex2f(25,40);
	
	glVertex2f(-71,-48);
	glVertex2f(29,37);
	
	glVertex2f(-67,-52);
	glVertex2f(33,34);
	
	glVertex2f(-63,-56);
	glVertex2f(37,30);
	
	glVertex2f(-58,-60);
	glVertex2f(41,26);
	
	//Medias
	glVertex2f(-53,-65);
	glVertex2f(45,23);
	
	glVertex2f(-48,-70);
	glVertex2f(49,20);
	
	glVertex2f(-42,-75);
	glVertex2f(53,17);
	
	glVertex2f(-37,-80);
	glVertex2f(57,14);
	
	glVertex2f(-32,-85);
	glVertex2f(61,11);
	
	glVertex2f(-27,-90);
	glVertex2f(65,8);
	
	//Bajos
	
	glVertex2f(-20,-96);
	glVertex2f(69,5);

	glVertex2f(-15,-101);
	glVertex2f(73,2);
	
	glVertex2f(-10,-106);
	glVertex2f(77,-1);	
	
	glVertex2f(-5,-111);
	glVertex2f(81,-4);
	
	glVertex2f(1,-116);
	glVertex2f(85,-8);
	
	glVertex2f(6,-121);
	glVertex2f(89,-11);
	
	glVertex2f(9,-127);
	glVertex2f(95,-15);
	
	glEnd();
	
	// Líneas verticales
	glBegin(GL_LINES);
	
	glVertex2f(-69,-39.5);
	glVertex2f(-65,-43);
	
	glVertex2f(-56.5,-50.5);
	glVertex2f(-61,-47);
	
	glVertex2f(-20,-82);
	glVertex2f(-13,-88);
	
	glVertex2f(-20,-82);
	glVertex2f(-13,-88);
	
	glVertex2f(-3,-97);
	glVertex2f(-9,-92);
	
	glVertex2f(-20,-82);
	glVertex2f(-13,-88);
	
	glVertex2f(-20,-82);
	glVertex2f(-13,-88);
	
	glEnd();
}


void paredIzquierda()
{
	glColor3f(0.85f, 0.82f, 0.75f);

    glBegin(GL_POLYGON);

        glVertex2f(-80,-40);   // vertice izq bajo
        glVertex2f(20,40);    // vertice erecho bajo
        glVertex2f(20,127);    // vertice derecho alto
        glVertex2f(-100,77);   // vertice izq alto

    glEnd();
}


void paredDerecha()
{
    glColor3f(0.95f, 0.92f, 0.85f);

    glBegin(GL_POLYGON);

        glVertex2f(20,40);
        glVertex2f(95,-15);
        glVertex2f(110,80);
        glVertex2f(20,127);

    glEnd();
}

void puerta()
{
    glColor3f(0.82f,0.65f,0.42f);

    glBegin(GL_POLYGON);

        glVertex2f(-61,-25);  // inferior izquierda
        glVertex2f(-40,-8);   // inferior derecha
        glVertex2f(-45,63);   // superior derecha
        glVertex2f(-70,50);   // superior izquierda

    glEnd();

	// Divisiones
	glColor3f(0.70f,0.55f,0.35f);
	glLineWidth(2);
	glBegin(GL_LINES);
	
	    // línea vertical central
	    glVertex2f(-51,-17);
	    glVertex2f(-58,56);
	
	    // línea horizontal superior
	    glVertex2f(-68,36);
	    glVertex2f(-44,49);
	
	    // línea horizontal inferior
	    glVertex2f(-64,5);
	    glVertex2f(-42,20);
	
	glEnd();

    // Perilla
    glPointSize(5);
	glColor3f(1,1,1);
	
	glBegin(GL_POINTS);
	    glVertex2f(-62,12);
	glEnd();
}

void mesita()
{
    // TAPA SUPERIOR
    glColor3f(0.65f,0.35f,0.22f);

    glBegin(GL_POLYGON);

        glVertex2f(-87,-37);
        glVertex2f(-70,-22);
        glVertex2f(-47,-40);
        glVertex2f(-65,-55);

    glEnd();

    // CARA FRONTAL
    glColor3f(0.55f,0.25f,0.15f);

    glBegin(GL_POLYGON);

        glVertex2f(-65,-55);//
        glVertex2f(-47,-40);//
        glVertex2f(-46,-55);
        glVertex2f(-64,-70);

    glEnd();

    // CARA LATERAL IZQUIERDA
    glColor3f(0.45f,0.18f,0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(-87,-37);//
        glVertex2f(-65,-55);//
        glVertex2f(-64,-70);
        glVertex2f(-85,-50);

    glEnd();

    // Hojas encima
    glColor3f(1,1,1);

    glBegin(GL_POLYGON);

        glVertex2f(-61,-48);
        glVertex2f(-56,-45);
        glVertex2f(-53,-49);
        glVertex2f(-58,-52);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(-57,-51);
        glVertex2f(-52,-48);
        glVertex2f(-49,-52);
        glVertex2f(-54,-55);

    glEnd();
}

void ventana()
{
    // Marco
    glColor3f(0.95f,0.95f,0.98f);

    glBegin(GL_POLYGON);

        glVertex2f(30,40);
        glVertex2f(58,20);
        glVertex2f(61,61);
        glVertex2f(30,76);

    glEnd();

    // Vidrio
    glColor3f(0.80f,0.85f,1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(39,37);
        glVertex2f(56.5,25);
        glVertex2f(59,58);
        glVertex2f(40,68);

    glEnd();
    
    // Parte externa
	glColor3f(0.82f, 0.88f, 0.60f);

    glBegin(GL_POLYGON);

        glVertex2f(32,42);
        glVertex2f(39,37);
        glVertex2f(40,68);
        glVertex2f(32,72);

    glEnd();

    // División central
    glColor3f(1,1,1);
    glLineWidth(4);

    glBegin(GL_LINES);

        glVertex2f(43,31);
        glVertex2f(44,67);

    glEnd();
    
    // División de lado
    glColor3f(1,1,1);
    glLineWidth(4);

    glBegin(GL_LINES);

        glVertex2f(43,31);
        glVertex2f(44,67);

    glEnd();
}

// Escritorio
void escritorio()
{

    // TAPA SUPERIOR
    glColor3f(0.70f,0.35f,0.22f);

    glBegin(GL_POLYGON);

        glVertex2f(-8,11); //vertice izq. alto
        glVertex2f(15,28); //vertice derecho alto
        glVertex2f(29,19); //vertice derecho bajo
        glVertex2f(6,1); // vertice izquierdo bajo

    glEnd();

    // CARA FRONTAL
    glColor3f(0.58f,0.25f,0.15f);

    glBegin(GL_POLYGON);

        glVertex2f(6,1);
        glVertex2f(29,19);
        glVertex2f(29,14);
        glVertex2f(6,-5);

    glEnd();

    // LATERAL IZQUIERDO
    glColor3f(0.50f,0.20f,0.12f);

    glBegin(GL_POLYGON);

        glVertex2f(-8,11);
        glVertex2f(6,1);
        glVertex2f(6,-5);
        glVertex2f(-8,5);

    glEnd();

    
    /*MONITOR
    glColor3f(0.15f,0.15f,0.15f);

    glBegin(GL_POLYGON);

        glVertex2f(3,25);
        glVertex2f(18,33);
        glVertex2f(18,15);
        glVertex2f(3,8);

    glEnd();
*/
    //PANTALLA
    glColor3f(0.85f,0.90f,1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(5,24);
        glVertex2f(16,30);
        glVertex2f(16,16);
        glVertex2f(5,10);

    glEnd();
/*
    // BASE DEL MONITOR
    glColor3f(0.10f,0.10f,0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(9,8);
        glVertex2f(12,10);
        glVertex2f(12,0);
        glVertex2f(9,-2);

    glEnd();*/
}


//Patas de escritorio
void patasEscritorio(){
	
    glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_POLYGON);

        glVertex2f(-2,-18);
        glVertex2f(0,-16);
        glVertex2f(0,-40);
        glVertex2f(-2,-42);

    glEnd();
    
    //pata con sombra
    glColor3f(0.35f, 0.35f, 0.35f);

    glBegin(GL_POLYGON);

        glVertex2f(-5,-18);
        glVertex2f(-2,-18);
        glVertex2f(-2,-42);
        glVertex2f(-5,-40);

    glEnd();
    

}

//CAMA
void cama(){
	
	// TAPA SUPERIOR
    glColor3f(0.45f, 0.20f, 0.12f);

    glBegin(GL_POLYGON);

        glVertex2f(-9,3); //vertice izq. alto
        glVertex2f(15,28); //vertice derecho alto
        glVertex2f(29,17); //vertice derecho bajo
        glVertex2f(6,-10); // vertice izquierdo bajo

    glEnd();

    // CARA FRONTAL
    glColor3f(0.40f, 0.15f, 0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(6,-10);
        glVertex2f(29,17);
        glVertex2f(29,14);
        glVertex2f(6,-15);

    glEnd();

    // LATERAL IZQUIERDO
    glColor3f(0.40f, 0.15f, 0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(-9,3);
        glVertex2f(6,-10);
        glVertex2f(6,-15);
        glVertex2f(-9,-2);

    glEnd();
	
}
