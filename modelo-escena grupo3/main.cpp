#include <windows.h>
#include <GL/freeglut.h>
#include <Math.h>
//Declaracion de Funciones
//--------------------------------------
//FORMAS Y OBJETOS DE BELEN CHAVEZ
//PISO
void piso(void);
//CAMA
void cama(void);
//COLCHON
void colchon(void);
//PUERTA
void puerta(void);
//PARED IZQUIERDA
void paredIzquierda(void);
//PARED DERECHA
void paredDerecha(void);
//MESITA
void mesita(void);
//ESCRITORIO
void escritorio(void);
//PATAS ESCRITORIO
void patasEscritorio(void);
//VENTANA
void ventana(void);
//ALFOMBRA
void alfombra(void);
//TACHO
void tacho(void);
//PC ENCIMA DE ESCRITORIO
void pc(void);
//MESA DE NOCHE
void mesaNoche(void);
//LAMPARA
void lampara(void);

//--------------------------------------
//FORMAS Y OBJETOS DE YESSICA BERNALOA
//REPISA
void repisa(void);

//--------------------------------------
//FORMAS Y OBJETOS DE CARLOS ZAMORA
//FOCO PARED DERECHA
void apliquePared(void);
//CUADRO DE PARED
void cuadroPared(void);
//CARLOS
void cortina(void);
//CARLOS
void jardinera(void);

//--------------------------------------
//FORMAS Y OBJETOS SOBRE LA CAMA DE MIGUEL ROA
//MANTA SOBRE CAMA
void mantaCama(void);
//LIBRO SOBRE CAMA
void libroCama(void);
//PELUCHE
void peluche(void);
void circulo(float cx, float cy, float r);
//CELULAR SOBRE CAMA
void celular(void);
//LENTES SOBRE CAMA
void lentes(void);
//PORTARETRATO
void portarretrato(void);

void inicializar()
{
	//fondo verde
    glClearColor(0.82f, 0.88f, 0.60f, 1.0f);
    //glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	gluOrtho2D(-100,100,-100,100);

    glMatrixMode(GL_MODELVIEW);
}

//Función reshape() sirve para que la escena no se deforme cuando cambia el tamaño de la ventana.
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

void dibujar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    //BELEN - Piso;
    glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	piso();
	glPopMatrix();
	
	//BELEN - Pared Izquierda
	glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	paredIzquierda();
	glPopMatrix();
	
	//BELEN - Pared Derecha
	glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	paredDerecha();
	glPopMatrix();

	//BELEN - PUERTA
    glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	puerta();
	glPopMatrix();

	//YESSICA - Repisa en la pared
    glPushMatrix();
    glScalef(0.8f, 0.8f, 1.0f);
    repisa();
    glPopMatrix();
    
	//BELEN - Mesita
	glPushMatrix();
	glTranslatef(25.0f, -10.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	mesita();
	glPopMatrix();
	
	//BELEN - Alfombra
	glPushMatrix();
	glTranslatef(-13.0f, -22.0f, 0.0f);
	glScalef(1.8f, 1.8f, 1.0f);
	alfombra();
	glPopMatrix();
	
	//BELEN - Pata de escritorio izquierdo bajo
	glPushMatrix();
	glTranslatef(3.0f, 30.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//BELEN - Pata de escritorio izquierdo alto
	glPushMatrix();
	glTranslatef(-8.0f, 37.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//BELEN - Pata de escritorio derecho bajo
	glPushMatrix();
	glTranslatef(20.0f, 46.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//BELEN - Pata de escritorio derecho alto
	glPushMatrix();
	glTranslatef(8.0f, 50.0f, 0.0f);
	glScalef(0.8f, 0.8f, 1.0f);
	patasEscritorio();
	glPopMatrix();
	
	//BELEN - Escritorio
	glPushMatrix();
	glTranslatef(-7.0f, 18.0f, 1.0f);
	escritorio();
	glPopMatrix();
	
	//BELEN - Tacho
	glPushMatrix();
	glTranslatef(-20.0f, 7.0f, 0.0f);
	glScalef(0.7f, 0.8f, 1.0f);
	tacho();
	glPopMatrix();

	//BELEN - PC de Escritorio
	glPushMatrix();
	glTranslatef(-10.0f, 33.0f, 1.0f);
	glScalef(0.9f, 0.9f, 1.0f);
	pc();
	glPopMatrix();

	//BELEN - Ventana
	glPushMatrix();
	ventana();
	glPopMatrix();
	
	//CARLOS: "Foco encima de la ventana (reubicado: ya no se encima con el cuadro blanco)"
	glPushMatrix();
	glTranslatef(-5.0f, 3.0f, 1.0f);
	apliquePared();
	glPopMatrix();
	
	//CARLOS: "Jardinera colgante debajo de la ventana (reubicada y reducida: ya no queda tapada por la mesa de noche)"
	glPushMatrix();
	glTranslatef(4.0f, -4.0f, 1.0f);
	jardinera();
	glPopMatrix();
	
	//CARLOS: "Cortina a la izquierda de la ventana"
	glPushMatrix();
	glTranslatef(25.0f, -15.0f, 1.0f);
	cortina();
	glPopMatrix();
	
	//CARLOS: "Cuadro pequeño"
	glPushMatrix();
	glTranslatef(32.0f, -19.0f, 1.0f);
	cuadroPared();
	glPopMatrix();
	
	//BELEN - Mesa de Noche
	glPushMatrix();
	glTranslatef(31.0f, 19.0f, 1.0f);
	glScalef(1.0f, 0.9f, 1.0f);
	mesaNoche();
	glPopMatrix();

	//BELEN - Cama
	glPushMatrix();
	glTranslatef(23.0f, -37.0f, 0.0f);
	glScalef(1.8f, 1.8f, 1.0f);
	cama();	
	glPopMatrix();
	
	//BELEN - Colchon de Cama
	glPushMatrix();
	glTranslatef(26.0f, -28.0f, 0.0f);
	glScalef(1.6f, 1.5f, 1.0f);
	colchon();
	glPopMatrix();

	//BELEN - Lámpara
	glPushMatrix();
	glTranslatef(35.0f, 21.0f,0.0f);
	glScalef(0.8f,0.8f,1.0f);
	lampara();
	glPopMatrix();
	
	//MIGUEL - Portarretrato sobre mesita de noche
    glPushMatrix();
    glTranslatef(29.0f, 19.0f, 1.0f);
    glScalef(1.0f, 0.9f, 1.0f);
    portarretrato();
    glPopMatrix();
    
    //MIGUEL - Manta doblada sobre cama
    glPushMatrix();
    glTranslatef(26.0f, -28.0f, 0.0f);
    glScalef(1.6f, 1.5f, 1.0f);
    mantaCama();
    glPopMatrix();
    
    //MIGUEL - Libro abierto sobre cama
    glPushMatrix();
    glTranslatef(26.0f, -28.0f, 0.0f);
    glScalef(1.6f, 1.5f, 1.0f);
    libroCama();
    glPopMatrix();

    //MIGUEL ROA - Peluche sobre cama
	glPushMatrix();
	glTranslatef(48.0f, -10.0f, 0.0f); 
	glScalef(1.2f, 1.2f, 1.0f);
	peluche();
	glPopMatrix();
	
	//MIGUEL - Celular
	glPushMatrix();
	glTranslatef(38.0f, -22.0f, 0.0f);
	glScalef(1.2f, 1.2f, 1.0f);
	celular();
	glPopMatrix();
	
	//MIGUEL - lentes
	glPushMatrix();
	glTranslatef(40.0f, -2.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	lentes();
	glPopMatrix();
	
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
	//Inicializar el gestor de ventanas GLUT y crear la ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("MODELO CUARTO 2D");
    inicializar();

	//initGL ();
	glutReshapeFunc (reshape);
    glutDisplayFunc(dibujar);

    glutMainLoop();
    return 0;
}

//PISO - Belen
void piso()
{
    glColor3f(0.75f,0.45f,0.30f);

    glBegin(GL_POLYGON);
        glVertex2f(10,-125);
        glVertex2f(95,-15);
        glVertex2f(20,40);
        glVertex2f(-80,-40);
    glEnd();
    
    //Líneas horizontales
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
	
	//Líneas verticales
	glBegin(GL_LINES);
	
	glVertex2f(-69,-39.5);
	glVertex2f(-65,-43);
	
	glVertex2f(-56.5,-50.5);
	glVertex2f(-61,-47);
	
	glVertex2f(-20,-82);
	glVertex2f(-13,-88);
	
	glVertex2f(-3,-97);
	glVertex2f(-8,-93);
	
	glVertex2f(7,-109);
	glVertex2f(1,-104);
	
	glVertex2f(15,-117.5);
	glVertex2f(11,-114);
	
	glEnd();
}

//Pared Izquierda- Belen
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

//Pared Derecha - Belen
void paredDerecha()
{
    glColor3f(0.95f, 0.92f, 0.85f);

    glBegin(GL_POLYGON);

        glVertex2f(20,40);
        glVertex2f(95,-15);
        glVertex2f(110,80);
        glVertex2f(20,127);

    glEnd();
    
	//CUADRO BLANCO
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(77,29);   // inferior izq.
        glVertex2f(95,18);   // inferior der.
        glVertex2f(101,64);   // superior der.
        glVertex2f(80,74);   // superior izq.

    glEnd();

}

//Puerta - Belen
void puerta()
{
    glColor3f(0.82f,0.65f,0.42f);

    glBegin(GL_POLYGON);

        glVertex2f(-61,-25);  // inferior izquierda
        glVertex2f(-40,-8);   // inferior derecha
        glVertex2f(-45,63);   // superior derecha
        glVertex2f(-70,50);   // superior izquierda

    glEnd();

	//Divisiones
	glColor3f(0.70f,0.55f,0.35f);
	glLineWidth(2);
	glBegin(GL_LINES);
	
	    //línea vertical central
	    glVertex2f(-51,-17);
	    glVertex2f(-58,56);
	
	    //línea horizontal superior
	    glVertex2f(-68,36);
	    glVertex2f(-44,49);
	
	    //línea horizontal inferior
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

//Baul- Belen
void mesita()
{
    //TAPA SUPERIOR
    glColor3f(0.65f,0.35f,0.22f);

    glBegin(GL_POLYGON);

        glVertex2f(-87,-37);
        glVertex2f(-70,-22);
        glVertex2f(-47,-40);
        glVertex2f(-65,-55);

    glEnd();

    //CARA FRONTAL
    glColor3f(0.55f,0.25f,0.15f);

    glBegin(GL_POLYGON);

        glVertex2f(-65,-55);//
        glVertex2f(-47,-40);//
        glVertex2f(-46,-55);
        glVertex2f(-64,-70);

    glEnd();

    //CARA LATERAL IZQUIERDA
    glColor3f(0.45f,0.18f,0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(-87,-37);//
        glVertex2f(-65,-55);//
        glVertex2f(-64,-70);
        glVertex2f(-85,-50);

    glEnd();

    //Hojas encima
    glColor3f(1,1,1);

    glBegin(GL_POLYGON);

         glVertex2f(-72,-35);
	    glVertex2f(-66,-30);
	    glVertex2f(-62,-34);
	    glVertex2f(-68,-39);
    
    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(-65,-37);
	    glVertex2f(-59,-32);
	    glVertex2f(-55,-36);
	    glVertex2f(-61,-41);

    glEnd();
    
}

//Ventana - Belen
void ventana()
{
    //Marco
    glColor3f(0.95f,0.95f,0.98f);

    glBegin(GL_POLYGON);

        glVertex2f(30,40);
        glVertex2f(58,22);
        glVertex2f(61,61);
        glVertex2f(31,77);

    glEnd();

    //Vidrio
    glColor3f(0.79f,0.85f,1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(39,38);
        glVertex2f(56.5,27);
        glVertex2f(59,58);
        glVertex2f(40,68);

    glEnd();
    
    //Parte externa
	glColor3f(0.82f, 0.88f, 0.60f);

    glBegin(GL_POLYGON);

        glVertex2f(31.5,43.5);
        glVertex2f(39,39);
        glVertex2f(40,69);
        glVertex2f(32,73);

    glEnd();

    //División central
    glColor3f(0.95f,0.95f,0.98f);
    glLineWidth(6);

    glBegin(GL_LINES);

        glVertex2f(45,34);
        glVertex2f(46.5,67);

    glEnd();
    
    //División de lado
    glColor3f(0.95f,0.95f,0.98f);
    glLineWidth(5);

    glBegin(GL_LINES);

        glVertex2f(38.5,37);
        glVertex2f(40,69);

    glEnd();
}

//Escritorio - Belenv
void escritorio()
{

    // TAPA SUPERIOR
    glColor3f(0.70f,0.35f,0.22f);

    glBegin(GL_POLYGON);

        glVertex2f(-8,11); //vertice izq. alto
        glVertex2f(16,27); //vertice derecho alto
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

}

//PC de Escritorio - Belen
void pc(){
	 //MONITOR
    glColor3f(0.85f,0.90f,1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(3,25);
        glVertex2f(18,33);
        glVertex2f(18,15);
        glVertex2f(3,6);

    glEnd();

    //PANTALLA
    glColor3f(0.15f,0.15f,0.15f);
    glBegin(GL_POLYGON);

        glVertex2f(4,24);
        glVertex2f(17,31);
        glVertex2f(17,17);
        glVertex2f(4,9);

    glEnd();

    //BASE DEL MONITOR
    glColor3f(0.85f,0.90f,1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(9,10);
        glVertex2f(12,12);
        glVertex2f(12,5);
        glVertex2f(9,3);

    glEnd();
    
    glBegin(GL_POLYGON);

        glVertex2f(5,3);
        glVertex2f(13,8);
        glVertex2f(19,4);
        glVertex2f(11,-1);

    glEnd();
    
    //Teclado
    glColor3f(0.65f, 0.67f, 0.72f);
    
    glBegin(GL_POLYGON);

        glVertex2f(9,-5);
        glVertex2f(22,4);
        glVertex2f(28,0);
        glVertex2f(15,-9);

    glEnd();
    
}

//PATAS DE ESCRITORIO - Belen
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

//CAMA - Belen
void cama(){
	
	// TAPA SUPERIOR
    glColor3f(0.45f, 0.20f, 0.12f);

    glBegin(GL_POLYGON);

        glVertex2f(-9,2.5); //vertice izq. alto
        glVertex2f(14,26); //vertice derecho alto
        glVertex2f(29,16); //vertice derecho bajo
        glVertex2f(6,-10); // vertice izquierdo bajo

    glEnd();

    // CARA FRONTAL
    glColor3f(0.40f, 0.15f, 0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(6,-10);
        glVertex2f(29,16);
        glVertex2f(29,14);
        glVertex2f(6,-15);

    glEnd();

    // LATERAL IZQUIERDO
    glColor3f(0.40f, 0.15f, 0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(-9,2.5);
        glVertex2f(6,-10);
        glVertex2f(6,-15);
        glVertex2f(-9,-2);

    glEnd();
    
	// Cabecera
	glColor3f(0.45f, 0.18f, 0.10f);
    glBegin(GL_POLYGON);

        glVertex2f(14,26);
        glVertex2f(29,16);
        glVertex2f(30,25);
        glVertex2f(14,35);

    glEnd();
	
}

//COLCHON de Cama - Belen
void colchon(){
	// parte SUPERIOR
    glColor3f(0.94f, 0.47f, 0.42f);

    glBegin(GL_POLYGON);

        glVertex2f(-9,2.5); //vertice izq. alto
        glVertex2f(14,26); //vertice derecho alto
        glVertex2f(29,16); //vertice derecho bajo
        glVertex2f(6,-10); // vertice izquierdo bajo

    glEnd();

    // CARA FRONTAL
    glColor3f(0.85f, 0.35f, 0.35f);

    glBegin(GL_POLYGON);

        glVertex2f(6,-10);
        glVertex2f(29,16);
        glVertex2f(29,13);
        glVertex2f(6,-15);

    glEnd();

    // LATERAL IZQUIERDO
    glColor3f(0.96f, 0.55f, 0.50f);

    glBegin(GL_POLYGON);

        glVertex2f(-9,2.5);
        glVertex2f(6,-10);
        glVertex2f(6,-15);
        glVertex2f(-9,-2);

    glEnd();
    
    // ALMOHADA GRANDE
	glColor3f(0.68f, 0.72f, 0.80f);
	
	glBegin(GL_POLYGON);
	
	    glVertex2f(14,23);
	    glVertex2f(16,27); //ddereccho alto
	    glVertex2f(27,20); // derecho baajo
	    glVertex2f(25,16); // izq. baajo
	
	glEnd();
    
	// ALMOHADA CHICA
	glColor3f(0.83f, 0.85f, 0.90f);
	glBegin(GL_POLYGON);
	
	    glVertex2f(15,20);
	    glVertex2f(17,23.5);
	    glVertex2f(23,19.5);
	    glVertex2f(21,16);
	
	glEnd();
	
}

//ALFOMBRA - Belen
void alfombra(){
	glColor3f(0.88f, 0.45f, 0.32f);

    glBegin(GL_POLYGON);

        glVertex2f(-8,11); //vertice izq. alto
        glVertex2f(15,29); //vertice derecho alto
        glVertex2f(29,19); //vertice derecho bajo
        glVertex2f(7.5,-2); // vertice izquierdo bajo

    glEnd();
}

//TACHO - Belen
void tacho()
{
    // Cara superior
    glColor3f(0.35f, 0.35f, 0.35f);

    glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(5,4);
        glVertex2f(10,0);
        glVertex2f(5,-4);

    glEnd();

    // Cara frontal
    glColor3f(0.20f, 0.20f, 0.20f);

    glBegin(GL_POLYGON);

        glVertex2f(5,-4);
        glVertex2f(10,0);
        glVertex2f(10,-12);
        glVertex2f(5,-16);

    glEnd();

    // Cara lateral
    glColor3f(0.12f, 0.12f, 0.12f);

    glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(5,-4);
        glVertex2f(5,-16);
        glVertex2f(0,-12);

    glEnd();

    // Papeles
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(3,1);
        glVertex2f(4,3);
        glVertex2f(6,2);
        glVertex2f(5,0);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(5,2);
        glVertex2f(6,4);
        glVertex2f(7,3);
        glVertex2f(6,1);

    glEnd();
}

//LAMPARA - Belen
void lampara()
{
    //BASE
    glColor3f(0.85f,0.85f,0.85f);

    glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(3,2);
        glVertex2f(6,0);
        glVertex2f(3,-2);

    glEnd();

    //POSTE
    glColor3f(0.70f,0.70f,0.70f);

    glBegin(GL_POLYGON);

        glVertex2f(2.5f,0);
        glVertex2f(3.5f,0);
        glVertex2f(3.5f,10);
        glVertex2f(2.5f,10);

    glEnd();

    // PANTALLA
	glColor3f(0.95f,0.85f,0.60f);
	glBegin(GL_POLYGON);
	
	    glVertex2f(-2,10);
	    glVertex2f(8,10);
	    glVertex2f(6,16);
	    glVertex2f(0,16);
	
	glEnd();

    //SOMBRA DE LA PANTALLA
	glColor3f(0.80f,0.70f,0.50f);
	glBegin(GL_POLYGON);
	
	    glVertex2f(8,10);
	    glVertex2f(6,16);
	    glVertex2f(5,15);
	    glVertex2f(7,10);
	
	glEnd();

}

//MESA DE NOCHE - Belen
void mesaNoche()
{
    // TAPA SUPERIOR
    glColor3f(0.40f, 0.15f, 0.10f);

    glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(7,6);
        glVertex2f(16,0);
        glVertex2f(9,-6);

    glEnd();

    // CARA LATERAL
	glColor3f(0.22f, 0.07f, 0.04f);
	
    glBegin(GL_POLYGON);

        glVertex2f(9,-6);
        glVertex2f(16,0);
        glVertex2f(16,-15);
        glVertex2f(9,-20);

    glEnd();

    // CARA FRONTAL
    glColor3f(0.30f, 0.10f, 0.06f);

    glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(9,-6);
        glVertex2f(9,-24);
        glVertex2f(0,-18);

    glEnd();

	//Linea divisora cajon
	glColor3f(0.22f, 0.07f, 0.04f);

	glBegin(GL_LINES);
	
	    glVertex2f(1,-9);
	    glVertex2f(8,-14);
	
	glEnd();
	
	//Pestillo superior
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2);
	
	glBegin(GL_LINES);
	
	    glVertex2f(4,-7);
	    glVertex2f(6,-8);
	
	glEnd();

	// Pestillo inferior
	glBegin(GL_LINES);
	
	    glVertex2f(4,-16);
	    glVertex2f(6,-17);
	
	glEnd();
    
}

//Repisa - Yessica
void repisa()
{
    //SOMBRA PROYECTADA EN LA PARED
    glColor3f(0.68f, 0.67f, 0.58f);
    glBegin(GL_POLYGON);
        glVertex2f(-32, 63);
        glVertex2f(20, 84);
        glVertex2f(38, 78);
        glVertex2f(38, 82);
        glVertex2f(20, 89);
        glVertex2f(-32, 68);
    glEnd();

    //SOPORTES DE MADERA
    glColor3f(0.50f, 0.22f, 0.10f);

    //Soporte Izquierdo
    glBegin(GL_TRIANGLES);
        glVertex2f(-22, 72);
        glVertex2f(-17, 74.0f);
        glVertex2f(-22, 65);
    glEnd();

    //Soporte Derecho
    glBegin(GL_TRIANGLES);
        glVertex2f(28, 84);
        glVertex2f(34, 82.5f);
        glVertex2f(32, 78);
    glEnd();

    //TABLA SUPERIOR
    glColor3f(0.82f, 0.52f, 0.32f);

    //Tramo Pared Izquierda
    glBegin(GL_POLYGON);
        glVertex2f(-31, 76);
        glVertex2f(20, 97);
        glVertex2f(20, 91);
        glVertex2f(-22, 72);
    glEnd();

    //Tramo Pared Derecha
    glBegin(GL_POLYGON);
        glVertex2f(20, 97);
        glVertex2f(36, 88);
        glVertex2f(32, 80);
        glVertex2f(20, 91);
    glEnd();

    //CANTO FRONTAL Y GROSOR
    glColor3f(0.60f, 0.32f, 0.18f);

    // Canto tramo izquierdo
    glBegin(GL_POLYGON);
        glVertex2f(-22, 72);
        glVertex2f(20, 91);
        glVertex2f(20, 88);
        glVertex2f(-22, 69);
    glEnd();

    //Canto tramo derecho
    glBegin(GL_POLYGON);
        glVertex2f(20, 91);
        glVertex2f(32, 83);
        glVertex2f(32, 80);
        glVertex2f(20, 88);
    glEnd();
}

//JARDINERA - CARLOS
void jardinera()
{
    // Caja
    glColor3f(0.40f, 0.22f, 0.12f);
    glBegin(GL_POLYGON);
        glVertex2f(41,37);
        glVertex2f(53,29.5);
        glVertex2f(53,26.5);
        glVertex2f(41,34);
    glEnd();

    // Tierra
    glColor3f(0.28f, 0.16f, 0.09f);
    glBegin(GL_POLYGON);
        glVertex2f(41,37);
        glVertex2f(53,29.5);
        glVertex2f(52.3,31.3);
        glVertex2f(41.7,38.6);
    glEnd();

    // Florcitas
    glPointSize(6);
    glColor3f(0.95f, 0.40f, 0.55f);
    glBegin(GL_POINTS); glVertex2f(44,36.2); glEnd();
    glColor3f(0.95f, 0.85f, 0.30f);
    glBegin(GL_POINTS); glVertex2f(47.5,34.2); glEnd();
    glColor3f(0.85f, 0.40f, 0.90f);
    glBegin(GL_POINTS); glVertex2f(51,32); glEnd();
    
    // Tallos de las flores
    glColor3f(0.45f, 0.70f, 0.30f);
    glLineWidth(2);
    glBegin(GL_LINES);
        // Tallo rosa
        glVertex2f(44, 33); glVertex2f(44, 36.2);
        // Tallo amarillo
        glVertex2f(47.5, 31); glVertex2f(47.5, 34.2);
        // Tallo morado
        glVertex2f(51, 29); glVertex2f(51, 32);
    glEnd();
}


//Cuadro de Pared - CARLOS
void cuadroPared()
{

    glColor3f(0.30f, 0.20f, 0.12f);

    glBegin(GL_POLYGON);
        glVertex2f(35, 78);   // inferior izquierdo
        glVertex2f(47, 71);   // inferior derecho
        glVertex2f(46, 84);   // superior derecho
        glVertex2f(34, 91);   // superior izquierdo
    glEnd();

    glColor3f(0.95f, 0.92f, 0.85f);

    glBegin(GL_POLYGON);
        glVertex2f(36.5f, 79.0f);
        glVertex2f(45.2f, 73.8f);
        glVertex2f(44.4f, 82.2f);
        glVertex2f(35.7f, 87.5f);
    glEnd();

    glColor3f(0.55f, 0.60f, 0.45f);

    glBegin(GL_TRIANGLES);
        glVertex2f(37.2f, 80.0f);
        glVertex2f(40.2f, 78.5f);
        glVertex2f(38.5f, 82.7f);
    glEnd();


    glColor3f(0.45f, 0.50f, 0.38f);

    glBegin(GL_TRIANGLES);
        glVertex2f(39.0f, 79.0f);
        glVertex2f(42.5f, 76.8f);
        glVertex2f(41.0f, 81.5f);
    glEnd();


    glColor3f(0.90f, 0.75f, 0.30f);

    glPointSize(5);

    glBegin(GL_POINTS);
        glVertex2f(42.8f, 81.0f);
    glEnd();
}


//Foco encima de ventana - CARLOS
void apliquePared()
{
    // Base metálica
    glColor3f(0.30f, 0.30f, 0.32f);
    glBegin(GL_POLYGON);
        glVertex2f(49,73);
        glVertex2f(51,74);
        glVertex2f(51,78);
        glVertex2f(49,77);
    glEnd();

    // Pantalla de luz
    glColor3f(0.95f, 0.90f, 0.70f);
    glBegin(GL_POLYGON);
        glVertex2f(52,72);
        glVertex2f(54,73.5);
        glVertex2f(55,76);
        glVertex2f(54,78.5);
        glVertex2f(52,80);
        glVertex2f(50.5,78.5);
        glVertex2f(50,76);
        glVertex2f(50.5,73.5);
    glEnd();

    // Brillo central
    glColor3f(1.0f,1.0f,0.85f);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex2f(52.5,76);
    glEnd();
}

//CORTINA - CARLOS
void cortina()
{
	//Cortina
	glColor3f(0.75f, 0.20f, 0.25f);

	glBegin(GL_POLYGON);
	
	    // Inferior más cerrada
	    glVertex2f(29,36);
	    glVertex2f(35,32);
	
	    // Superior más abierta
	    glVertex2f(37,78);
	    glVertex2f(24,86);
	
	glEnd();
	
	glColor3f(0.58f, 0.13f, 0.16f);
	
	glBegin(GL_POLYGON);
	
	    glVertex2f(31,34);
	    glVertex2f(33,33);
	
	    glVertex2f(32,81);
	    glVertex2f(29,82);
	
	glEnd();

	//Palo que sostiene cortina
    glColor3f(0.35f, 0.25f, 0.15f);

    glBegin(GL_POLYGON);
    
    glVertex2f(4, 94);
    glVertex2f(38, 77);

    glVertex2f(38, 81);
    glVertex2f(4, 99);

    glEnd();
}

//MANTA - MIGUEL ROA
void mantaCama()
{
    //CARA SUPERIOR
    glColor3f(0.35f, 0.45f, 0.62f);

    glBegin(GL_POLYGON);

        glVertex2f(-5.04f, 4.32f);
        glVertex2f(2.55f, 12.07f);
        glVertex2f(15.15f, 1.57f);
        glVertex2f(7.56f, -6.18f);

    glEnd();

    //FRONTAL DERECHO
    glColor3f(0.26f, 0.34f, 0.50f);

    glBegin(GL_POLYGON);

        glVertex2f(7.56f, -6.18f);
        glVertex2f(15.15f, 1.57f);
        glVertex2f(15.15f, -0.43f);
        glVertex2f(7.56f, -8.18f);

    glEnd();

    //FRONTAL IZQUIERDO
    glColor3f(0.30f, 0.39f, 0.56f);

    glBegin(GL_POLYGON);

        glVertex2f(-5.04f, 4.32f);
        glVertex2f(7.56f, -6.18f);
        glVertex2f(7.56f, -8.18f);
        glVertex2f(-5.04f, 2.32f);

    glEnd();

    //PLIEGUES
    glColor3f(0.28f, 0.37f, 0.54f);
    glLineWidth(2);

    glBegin(GL_LINES);

        glVertex2f(-1.74f, 1.57f);
        glVertex2f(5.85f, 9.32f);

        glVertex2f(2.01f, -1.55f);
        glVertex2f(9.60f, 6.20f);

        glVertex2f(5.76f, -4.68f);
        glVertex2f(13.35f, 3.07f);

    glEnd();
}


//LIBRO - MIGUEL ROA
void libroCama()
{
    //TAPA
    glColor3f(0.55f, 0.18f, 0.20f);

    glBegin(GL_POLYGON);

        glVertex2f(2.11f, 13.29f);
        glVertex2f(6.25f, 17.52f);
        glVertex2f(10.45f, 14.02f);
        glVertex2f(6.31f, 9.79f);

    glEnd();

    //HOJA IZQUIERDA
    glColor3f(0.98f, 0.97f, 0.92f);

    glBegin(GL_POLYGON);

        glVertex2f(3.25f, 13.62f);
        glVertex2f(6.01f, 16.44f);
        glVertex2f(7.66f, 15.07f);
        glVertex2f(4.90f, 12.25f);

    glEnd();

    //HOJA DERECHA
    glColor3f(0.94f, 0.93f, 0.87f);

    glBegin(GL_POLYGON);

        glVertex2f(4.90f, 12.25f);
        glVertex2f(7.66f, 15.07f);
        glVertex2f(9.31f, 13.69f);
        glVertex2f(6.55f, 10.87f);

    glEnd();

    //DOBLEZ CENTRAL
    glColor3f(0.70f, 0.68f, 0.62f);
    glLineWidth(2);

    glBegin(GL_LINES);

        glVertex2f(4.90f, 12.25f);
        glVertex2f(7.66f, 15.07f);

    glEnd();

    //RENGLONES
    glColor3f(0.55f, 0.55f, 0.55f);
    glLineWidth(1);

    glBegin(GL_LINES);

        //hoja izquierda
        glVertex2f(4.24f, 14.08f);
        glVertex2f(5.29f, 13.20f);

        glVertex2f(4.93f, 14.78f);
        glVertex2f(5.98f, 13.91f);

        glVertex2f(5.62f, 15.49f);
        glVertex2f(6.67f, 14.61f);

        //hoja derecha
        glVertex2f(5.89f, 12.70f);
        glVertex2f(6.94f, 11.83f);

        glVertex2f(6.58f, 13.41f);
        glVertex2f(7.63f, 12.53f);

        glVertex2f(7.27f, 14.11f);
        glVertex2f(8.32f, 13.24f);

    glEnd();
}

//CIRCULO(PELUCHE) - MIGUEL ROA
void circulo(float cx, float cy, float r)
{
    int i;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (i = 0; i <= 30; i++)
        {
            float a = i * 2.0f * 3.14159265f / 30.0f;
            glVertex2f(cx + r * cos(a), cy + r * sin(a));
        }
    glEnd();
}


//PELUCHE -  MIGUEL ROA
void peluche()
{
    //PIERNAS
    glColor3f(0.68f, 0.45f, 0.26f);
    circulo(9.6f, 1.2f, 1.3f);
    circulo(12.5f, 1.2f, 1.3f);

    //BRAZOS
    circulo(8.4f, 4.2f, 1.2f);
    circulo(13.7f, 4.2f, 1.2f);

    //CUERPO
    glColor3f(0.78f, 0.55f, 0.35f);
    circulo(11.05f, 3.7f, 3.0f);

    //PANZA
    glColor3f(0.92f, 0.80f, 0.62f);
    circulo(11.05f, 3.3f, 1.8f);

    //OREJAS
    glColor3f(0.68f, 0.45f, 0.26f);
    circulo(9.50f, 10.1f, 0.9f);
    circulo(12.60f, 10.1f, 0.9f);

    glColor3f(0.93f, 0.72f, 0.70f);
    circulo(9.50f, 10.1f, 0.45f);
    circulo(12.60f, 10.1f, 0.45f);

    //CABEZA
    glColor3f(0.78f, 0.55f, 0.35f);
    circulo(11.05f, 8.4f, 2.2f);

    //HOCICO
    glColor3f(0.92f, 0.80f, 0.62f);
    circulo(11.05f, 7.5f, 1.0f);

    //OJOS
    glColor3f(0.10f, 0.08f, 0.06f);
    glPointSize(3);

    glBegin(GL_POINTS);
        glVertex2f(10.20f, 9.00f);
        glVertex2f(11.90f, 9.00f);
    glEnd();

    //NARIZ
    glPointSize(5);

    glBegin(GL_POINTS);
        glVertex2f(11.05f, 7.90f);
    glEnd();
}

// CELULAR - MIGUEL ROA
void celular() {
    // Pantalla
    glColor3f(0.05f, 0.05f, 0.05f); 
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(4,0);
        glVertex2f(4,-8);
        glVertex2f(0,-8);
    glEnd();

    // Borde
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(4,0);
        glVertex2f(4,-8);
        glVertex2f(0,-8);
    glEnd();

    // Botón inferior
    glColor3f(0.8f, 0.8f, 0.8f);
    circulo(2.0f, -7.5f, 0.3f);
}

//PORTARETRATO - MIGUEL ROA
void portarretrato()
{
    //BASE / SOPORTE SOBRE LA MESA
    glColor3f(0.30f, 0.30f, 0.32f);

    glBegin(GL_POLYGON);

        glVertex2f(13.71f, 0.28f);
        glVertex2f(14.25f, 0.74f);
        glVertex2f(15.42f, -0.04f);
        glVertex2f(14.88f, -0.50f);

    glEnd();

    //MARCO EXTERIOR (madera)
    glColor3f(0.55f, 0.42f, 0.25f);

    glBegin(GL_POLYGON);

        glVertex2f(11.90f, 0.90f);
        glVertex2f(16.06f, 0.12f);
        glVertex2f(16.71f, 4.80f);
        glVertex2f(12.55f, 5.58f);

    glEnd();

    //CANTO LATERAL (grosor del marco)
    glColor3f(0.35f, 0.25f, 0.14f);

    glBegin(GL_POLYGON);

        glVertex2f(16.06f, 0.12f);
        glVertex2f(16.71f, 4.80f);
        glVertex2f(17.36f, 4.48f);
        glVertex2f(16.71f, -0.21f);

    glEnd();

    //PASPARTU (borde interno crema)
    glColor3f(0.92f, 0.88f, 0.78f);

    glBegin(GL_POLYGON);

        glVertex2f(12.07f, 1.04f);
        glVertex2f(15.94f, 0.32f);
        glVertex2f(16.54f, 4.67f);
        glVertex2f(12.67f, 5.39f);

    glEnd();

    //FOTO - CIELO
    glColor3f(0.65f, 0.82f, 0.95f);

    glBegin(GL_POLYGON);

        glVertex2f(12.26f, 1.20f);
        glVertex2f(15.80f, 0.54f);
        glVertex2f(16.35f, 4.51f);
        glVertex2f(12.81f, 5.18f);

    glEnd();

    //FOTO - SOL
    glColor3f(0.95f, 0.80f, 0.35f);
    circulo(15.38f, 4.09f, 0.46f);

    //FOTO - MONTANA LEJANA
    glColor3f(0.55f, 0.60f, 0.55f);

    glBegin(GL_TRIANGLES);

        glVertex2f(13.79f, 1.73f);
        glVertex2f(15.38f, 1.43f);
        glVertex2f(14.97f, 2.94f);

    glEnd();

    //FOTO - MONTANA CERCANA
    glColor3f(0.45f, 0.50f, 0.45f);

    glBegin(GL_TRIANGLES);

        glVertex2f(12.55f, 1.97f);
        glVertex2f(13.97f, 1.69f);
        glVertex2f(13.54f, 3.90f);

    glEnd();

    //FOTO - SUELO / PASTO
    glColor3f(0.35f, 0.55f, 0.30f);

    glBegin(GL_POLYGON);

        glVertex2f(12.26f, 1.20f);
        glVertex2f(15.80f, 0.54f);
        glVertex2f(15.92f, 1.41f);
        glVertex2f(12.38f, 2.07f);

    glEnd();
}
//LENTES - MIGUEL ROA
void lentes() {
    // Lente izquierdo
    glColor3f(0.85f, 0.85f, 0.85f); 
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(3,0);
        glVertex2f(3,-2);
        glVertex2f(0,-2);
    glEnd();

    // Contorno negro lente izquierdo
    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(3,0);
        glVertex2f(3,-2);
        glVertex2f(0,-2);
    glEnd();

    // Efecto reflejo lente izquierdo
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(0.5f,-0.2f);
        glVertex2f(2.5f,-1.5f);
    glEnd();

    // Lente derecho
    glColor3f(0.85f, 0.85f, 0.85f); 
    glBegin(GL_POLYGON);
        glVertex2f(4,0);
        glVertex2f(7,0);
        glVertex2f(7,-2);
        glVertex2f(4,-2);
    glEnd();

    // Contorno negro lente derecho
    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(4,0);
        glVertex2f(7,0);
        glVertex2f(7,-2);
        glVertex2f(4,-2);
    glEnd();

    // Efecto reflejo lente derecho
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(4.5f,-0.2f);
        glVertex2f(6.5f,-1.5f);
    glEnd();

    // Puente superior
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(3,0);
        glVertex2f(4,0);
    glEnd();

    // Patilla izquierda
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(-2,1);
    glEnd();

    // Patilla derecha
    glBegin(GL_LINES);
        glVertex2f(7,0);
        glVertex2f(9,1);
    glEnd();
}

