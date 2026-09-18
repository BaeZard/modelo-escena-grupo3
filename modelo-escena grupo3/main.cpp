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
//ESPEJO EN PARED IZQUIERDA
void espejoPared(void);
//RELOJ DE PARED
void relojPared(void);
//REPISA
void repisa(void);
//FLORERO
void objFlorero(void);
//PELUCHE
void objPeluche(void);
//PILA DE LIBROS
void objPilaLibros(void);
//PORTARETRATOS
void objPortarretrato(void);
//MACETA
void objMaceta(void);
//LIBROS PARADOS
void objLibrosParados(void);
//LIBROS EXTRA
void librosExtra(void);
//REPISA
void objEnRepisa(void (*obj)(void), float bx, float by, float k, float dx, float dy);

//Utilidades de dibujo
void circuloRelleno(float cx, float cy, float r, int lados);
void quad2f(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);


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
	
    //YESSICA - Espejo al lado de la puerta
    glPushMatrix();
    glScalef(0.8f, 0.8f, 1.0f);
    glTranslatef(8.2f, -18.5f, 0.1f);
    espejoPared();
    glPopMatrix();

	//BELEN - PUERTA
    glPushMatrix();
	glScalef(0.8f, 0.8f, 1.0f);
	puerta();
	glPopMatrix();

	//YESSICA - Repisa en la pared (con objetos incorporados)
    glPushMatrix();
    glScalef(0.8f, 0.8f, 1.0f);
    repisa();
    glPopMatrix();

    //YESSICA - Reloj de pared
    glPushMatrix();
    glTranslatef(-76.0f, 20.0f, 0.0f);
    glTranslatef(56.0f * 0.5f, 68.0f * 0.5f, 0.0f);
    glRotatef(-20.0f, 0.0f, 0.0f, -12.0f);
    glTranslatef(-58.0f * 0.5f, -68.0f * 0.5f, 0.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    relojPared();
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
	
	//YESSICA - libros parados
    glPushMatrix();
	glTranslatef(30.0f, 50.0f, 2.0f);
 	librosExtra();
	glPopMatrix();
  
  	//YESSICA - LIBROS EXTRA EN LA REPISA
	glPushMatrix();
	glTranslatef(-10.0f, 32.0f, 1.0f);
 	librosExtra();
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


//UTILIDADES - Yessica
void circuloRelleno(float cx, float cy, float r, int lados)
{
    int i;
    glBegin(GL_POLYGON);
    for (i = 0; i < lados; i++)
    {
        float a = 2.0f * 3.1415926f * i / (float)lados;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

void quad2f(float x1, float y1, float x2, float y2,
            float x3, float y3, float x4, float y4)
{
    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
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
/*
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
}*/

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

//Espejo de Pared - Yessica
void espejoPared()
{
    // MARCO DEL ESPEJO
    glColor3f(0.50f, 0.32f, 0.18f);
    glBegin(GL_POLYGON);
        glVertex2f(-90, -10);
        glVertex2f(-75, -2);
        glVertex2f(-80, 58);
        glVertex2f(-95, 50);
    glEnd();

    // CRISTAL / REFLEJO DEL ESPEJO
    glColor3f(0.82f, 0.90f, 0.96f);
    glBegin(GL_POLYGON);
        glVertex2f(-88, -7);
        glVertex2f(-77, -1);
        glVertex2f(-82, 55);
        glVertex2f(-93, 48);
    glEnd();

    // DESTELLO / BRILLO REFLEJADO
    glColor3f(0.95f, 0.98f, 1.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-89, 15); glVertex2f(-84, 40);
        glVertex2f(-86, 10); glVertex2f(-82, 30);
    glEnd();
}


//REPISA + OBJETOS (tramo izquierdo, CENTRO y tramo derecho) - Yessica
void repisa()
{
    int i;

    // 1. SOMBRA PROYECTADA EN LA PARED
    glColor3f(0.68f, 0.67f, 0.58f);
    glBegin(GL_POLYGON);
        glVertex2f(-32, 63);
        glVertex2f(20, 84);
        glVertex2f(38, 78);
        glVertex2f(38, 82);
        glVertex2f(20, 89);
        glVertex2f(-32, 68);
    glEnd();

    // 2. SOPORTES / MENSULAS DE MADERA
    glColor3f(0.50f, 0.22f, 0.10f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-22, 72); glVertex2f(-17, 74.0f); glVertex2f(-22, 65);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(0, 81.8f); glVertex2f(5, 84.0f); glVertex2f(0, 75.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(28, 84); glVertex2f(34, 82.5f); glVertex2f(32, 78);
    glEnd();

    // 3. TABLA SUPERIOR
    glColor3f(0.82f, 0.52f, 0.32f);
    quad2f(-31, 76, 20, 97, 20, 91, -22, 72);   // tramo izquierdo
    quad2f(20, 97, 36, 88, 32, 80, 20, 91);     // tramo derecho

    // 3b. VETAS DE LA MADERA (realismo)
    glColor3f(0.72f, 0.44f, 0.26f);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(-28.0f, 76.6f); glVertex2f(20.0f, 96.0f);
        glVertex2f(-26.0f, 75.0f); glVertex2f(20.0f, 94.0f);
        glVertex2f(-24.0f, 73.6f); glVertex2f(20.0f, 92.4f);
        glVertex2f(20.0f, 95.5f);  glVertex2f(34.5f, 87.4f);
        glVertex2f(20.0f, 93.2f);  glVertex2f(33.0f, 85.6f);
    glEnd();

    // 4. CANTO FRONTAL Y GROSOR
    glColor3f(0.60f, 0.32f, 0.18f);
    quad2f(-22, 72, 20, 91, 20, 88, -22, 69);   // canto izquierdo
    quad2f(20, 91, 32, 83, 32, 80, 20, 88);     // canto derecho

    // ==========================================
    // OBJETOS SOBRE LA TABLA
    // Cada objeto se escala desde su punto de apoyo (bx,by) con factor k,
    // asi crece de tamano pero sigue "parado" sobre la repisa.
    // ==========================================
    objEnRepisa(objFlorero,       -24.0f, 75.2f, 1.25f,   1.5f,   1.6f);
    objEnRepisa(objPeluche,       -12.5f, 79.8f, 1.25f,   1.0f,   1.4f);
    objEnRepisa(objPilaLibros,     -2.5f, 82.9f, 1.30f,   0.6f,   1.2f);
    objEnRepisa(objPortarretrato,   5.9f, 86.6f, 1.25f,   1.6f,   1.2f);
    objEnRepisa(objMaceta,         16.5f, 91.1f, 1.28f,  -0.4f,   0.8f);
    objEnRepisa(objLibrosParados, 32.5f, 89.0f, 1.15f, 0.0f, 0.0f);

    (void)i;
}

// Aplica: traslacion de ajuste + escalado respecto del punto de apoyo
void objEnRepisa(void (*obj)(void), float bx, float by, float k, float dx, float dy)
{
    glPushMatrix();
        glTranslatef(dx, dy, 0.0f);
        glTranslatef(bx, by, 0.0f);
        glScalef(k, k, 1.0f);
        glTranslatef(-bx, -by, 0.0f);
        obj();
    glPopMatrix();
}

//FLORERO - Yessica
void objFlorero()
{
    int i;

    // sombra de contacto
    glColor3f(0.70f, 0.42f, 0.24f);
    quad2f(-25.5f, 74.6f, -21.5f, 76.8f, -20.2f, 75.6f, -25.2f, 73.4f);

    // CUERPO DEL FLORERO -- tres franjas de tono para dar volumen curvo
    glColor3f(0.14f, 0.50f, 0.46f);                 // cara oscura (izquierda)
    quad2f(-25.2f, 75.2f, -23.6f, 76.3f, -22.6f, 82.5f, -25.0f, 81.5f);

    glColor3f(0.20f, 0.62f, 0.57f);                  // cuerpo medio
    quad2f(-23.6f, 75.9f, -22.2f, 77.0f, -21.4f, 83.0f, -23.6f, 82.0f);

    glColor3f(0.32f, 0.74f, 0.68f);                  // brillo derecho
    quad2f(-22.8f, 76.6f, -21.4f, 77.2f, -20.8f, 82.6f, -22.0f, 82.2f);

    // CUELLO (mas angosto que el cuerpo)
    glColor3f(0.18f, 0.56f, 0.52f);
    quad2f(-23.6f, 82.0f, -21.8f, 82.8f, -21.4f, 85.6f, -24.0f, 85.0f);

    // BOCA / BORDE SUPERIOR (elipse aplastada con circuloRelleno escalado)
    glPushMatrix();
        glTranslatef(-22.7f, 85.3f, 0.0f);
        glScalef(1.0f, 0.42f, 1.0f);
        glColor3f(0.12f, 0.42f, 0.40f);
        circuloRelleno(0.0f, 0.0f, 1.1f, 18);
    glPopMatrix();

    // TALLO CASI VERTICAL
	glColor3f(0.20f, 0.60f, 0.20f);
	glLineWidth(2);
	
	glBegin(GL_LINES);
	    glVertex2f(-22.4f, 85.6f);
	    glVertex2f(-22.1f, 92.5f);
	glEnd();

    // HOJA IZQUIERDA
	glColor3f(0.12f, 0.48f, 0.18f);
	glBegin(GL_POLYGON);
	    glVertex2f(-22.0f, 89.0f);
	    glVertex2f(-19.0f, 91.0f);
	    glVertex2f(-21.5f, 87.5f);
	    glVertex2f(-23.0f, 86.8f);
	glEnd();

	// HOJA DERECHA
	glColor3f(0.16f, 0.58f, 0.24f);
	glBegin(GL_POLYGON);
	    glVertex2f(-22.0f, 90.5f);
	    glVertex2f(-24.0f, 92.0f);
	    glVertex2f(-22.4f, 88.0f);
	    glVertex2f(-21.0f, 88.2f);
	glEnd();

    // FLOR -- pétalos redondos alrededor de un centro naranja
    glColor3f(0.97f, 0.80f, 0.22f);
    for (i = 0; i < 6; i++)
    {
        float a = 2.0f * 3.1415926f * i / 6.0f;
        float px = -22.1f + 1.1f * cos(a);
		float py = 93.0f + 1.1f * sin(a);
        circuloRelleno(px, py, 0.55f, 10);
    }
    glColor3f(0.85f, 0.45f, 0.12f);
    circuloRelleno(-22.1f, 93.0f, 0.6f, 12);

    // BRILLO SOBRE EL CUERPO DEL FLORERO
    glColor3f(0.75f, 0.90f, 0.88f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glVertex2f(-24.7f, 77.0f); glVertex2f(-23.6f, 81.3f);
    glEnd();
}

//PELUCHE - Yessica
void objPeluche()
{
    // sombra de contacto
    glColor3f(0.70f, 0.42f, 0.24f);
    quad2f(-15.5f, 78.6f, -9.5f, 81.2f, -8.2f, 80.0f, -14.2f, 77.4f);

    // CUERPO
    glColor3f(0.68f, 0.42f, 0.23f);
    quad2f(-15, 79, -10, 81, -10, 87, -15, 85);

    // OREJAS -- redondas
    glColor3f(0.62f, 0.38f, 0.20f);
    circuloRelleno(-16.0f, 91.4f, 1.35f, 16);
    circuloRelleno(-10.2f, 93.6f, 1.35f, 16);
    glColor3f(0.82f, 0.55f, 0.34f);                 // interior de la oreja
    circuloRelleno(-16.0f, 91.4f, 0.75f, 14);
    circuloRelleno(-10.2f, 93.6f, 0.75f, 14);

    // CABEZA
    glColor3f(0.75f, 0.50f, 0.28f);
    quad2f(-16, 85, -9, 87.8f, -9, 93, -16, 90.2f);

    // PARCHE DEL HOCICO
    glColor3f(0.95f, 0.90f, 0.80f);
    quad2f(-14, 86.5f, -11, 87.7f, -11, 90, -14, 88.8f);

    // NARIZ
    glColor3f(0.20f, 0.14f, 0.10f);
    circuloRelleno(-12.5f, 88.6f, 0.42f, 10);

    // OJOS
    glColor3f(0.10f, 0.08f, 0.06f);
    circuloRelleno(-14.0f, 89.9f, 0.38f, 10);
    circuloRelleno(-10.8f, 90.9f, 0.38f, 10);
    // brillo en los ojos
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2f(-14.15f, 90.05f);
        glVertex2f(-10.95f, 91.05f);
    glEnd();

    // MOÑO ROJO
    glColor3f(0.85f, 0.20f, 0.25f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-12.5f, 84.5f); glVertex2f(-16.0f, 83.2f); glVertex2f(-13.5f, 86.0f);
        glVertex2f(-12.5f, 84.5f); glVertex2f(-9.2f, 84.8f); glVertex2f(-11.8f, 86.0f);
    glEnd();
    glColor3f(0.65f, 0.10f, 0.14f);                  // nudo central del moño
    circuloRelleno(-12.5f, 84.7f, 0.4f, 10);
}

//PILA DE LIBROS - Yessica
void objPilaLibros()
{
    glColor3f(0.70f, 0.42f, 0.24f);
    quad2f(-6.4f, 81.0f, 1.4f, 84.6f, 2.6f, 83.4f, -5.2f, 79.8f);

    glColor3f(0.18f, 0.28f, 0.52f);
    quad2f(-6.0f, 81.4f, 1.0f, 84.4f, 1.0f, 86.0f, -6.0f, 83.0f);
    glColor3f(0.26f, 0.38f, 0.66f);
    quad2f(-6.0f, 83.0f, 1.0f, 86.0f, 0.2f, 87.6f, -6.8f, 84.6f);

    glColor3f(0.80f, 0.62f, 0.20f);
    quad2f(-5.6f, 83.6f, 0.5f, 86.2f, 0.5f, 87.6f, -5.6f, 85.0f);
    glColor3f(0.90f, 0.74f, 0.30f);
    quad2f(-5.6f, 85.0f, 0.5f, 87.6f, -0.3f, 89.1f, -6.4f, 86.5f);

    glColor3f(0.16f, 0.42f, 0.28f);
    quad2f(-5.0f, 85.4f, 0.0f, 87.6f, 0.0f, 88.8f, -5.0f, 86.6f);
    glColor3f(0.24f, 0.56f, 0.36f);
    quad2f(-5.0f, 86.6f, 0.0f, 88.8f, -0.8f, 90.3f, -5.8f, 88.1f);

    glColor3f(0.94f, 0.92f, 0.84f);
    glLineWidth(1.4f);
    glBegin(GL_LINES);
        glVertex2f(-5.9f, 82.0f); glVertex2f(0.9f, 84.9f);
        glVertex2f(-5.5f, 84.1f); glVertex2f(0.4f, 86.7f);
        glVertex2f(-4.9f, 85.8f); glVertex2f(-0.1f, 88.0f);
    glEnd();

    // Despertador sobre los libros
    glColor3f(0.85f, 0.25f, 0.22f);
    circuloRelleno(-2.6f, 92.4f, 2.0f, 24);
    glColor3f(0.97f, 0.95f, 0.88f);
    circuloRelleno(-2.6f, 92.4f, 1.5f, 24);
    glColor3f(0.20f, 0.20f, 0.20f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glVertex2f(-2.6f, 92.4f); glVertex2f(-2.6f, 93.6f);
        glVertex2f(-2.6f, 92.4f); glVertex2f(-1.7f, 92.0f);
    glEnd();
    glColor3f(0.85f, 0.25f, 0.22f);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(-4.4f, 94.0f);
        glVertex2f(-1.0f, 94.0f);
    glEnd();
}

//PORTARRETRATO - Yessica
void objPortarretrato()
{
    glColor3f(0.70f, 0.42f, 0.24f);
    quad2f(2.6f, 85.0f, 9.0f, 87.9f, 10.2f, 86.7f, 3.8f, 83.8f);

    glColor3f(0.42f, 0.26f, 0.14f);
    quad2f(3.0f, 85.3f, 8.8f, 87.9f, 8.8f, 94.9f, 3.0f, 92.3f);
    glColor3f(0.55f, 0.36f, 0.20f);
    quad2f(3.0f, 92.3f, 8.8f, 94.9f, 8.0f, 96.1f, 2.2f, 93.5f);
    glColor3f(0.62f, 0.82f, 0.94f);
    quad2f(3.8f, 86.4f, 8.0f, 88.3f, 8.0f, 93.8f, 3.8f, 91.9f);
    glColor3f(0.98f, 0.88f, 0.35f);
    circuloRelleno(6.8f, 92.0f, 0.7f, 16);
    glColor3f(0.30f, 0.60f, 0.32f);
    glBegin(GL_TRIANGLES);
        glVertex2f(3.8f, 86.4f); glVertex2f(8.0f, 88.3f); glVertex2f(5.6f, 91.0f);
    glEnd();
    glColor3f(0.42f, 0.72f, 0.42f);
    glBegin(GL_TRIANGLES);
        glVertex2f(5.2f, 87.0f); glVertex2f(8.0f, 88.3f); glVertex2f(7.4f, 90.4f);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(1.2f);
    glBegin(GL_LINES);
        glVertex2f(4.2f, 87.4f); glVertex2f(6.4f, 92.8f);
        glVertex2f(5.2f, 87.0f); glVertex2f(6.9f, 91.2f);
    glEnd();
}

//MACETA CON SUCULENTA - Yessica
void objMaceta()
{
    glColor3f(0.70f, 0.42f, 0.24f);
    quad2f(14.9f, 90.4f, 18.4f, 92.0f, 19.6f, 90.8f, 16.1f, 89.2f);

    glColor3f(0.78f, 0.42f, 0.26f);
    quad2f(15.2f, 90.5f, 17.9f, 91.7f, 18.5f, 95.0f, 14.9f, 93.4f);
    glColor3f(0.64f, 0.32f, 0.18f);
    quad2f(17.2f, 91.4f, 17.9f, 91.7f, 18.5f, 95.0f, 17.7f, 94.6f);
    glColor3f(0.86f, 0.50f, 0.32f);
    quad2f(14.9f, 93.4f, 18.5f, 95.0f, 18.4f, 95.9f, 14.8f, 94.3f);
    glColor3f(0.30f, 0.22f, 0.16f);
    quad2f(15.3f, 94.4f, 18.0f, 95.6f, 17.9f, 96.0f, 15.2f, 94.8f);
    glColor3f(0.24f, 0.58f, 0.32f);
    glBegin(GL_TRIANGLES);
        glVertex2f(16.6f, 95.2f); glVertex2f(15.0f, 96.4f); glVertex2f(16.2f, 98.2f);
        glVertex2f(16.6f, 95.2f); glVertex2f(16.4f, 99.2f); glVertex2f(17.4f, 97.6f);
        glVertex2f(16.6f, 95.2f); glVertex2f(18.6f, 96.6f); glVertex2f(17.3f, 98.4f);
    glEnd();
    glColor3f(0.36f, 0.72f, 0.42f);
    glBegin(GL_TRIANGLES);
        glVertex2f(16.6f, 95.4f); glVertex2f(15.6f, 97.4f); glVertex2f(16.9f, 97.6f);
    glEnd();
}

//LIBROS PARADOS (tramo derecho) - Yessica
void objLibrosParados()
{
    glColor3f(0.20f, 0.40f, 0.75f);
    quad2f(23, 91.5f, 24.5f, 90.7f, 24.5f, 99.7f, 23, 100.5f);
    glColor3f(0.35f, 0.55f, 0.90f);
    quad2f(24.5f, 90.7f, 27.5f, 89.1f, 27.5f, 98.1f, 24.5f, 99.7f);

    glColor3f(0.18f, 0.55f, 0.30f);
    quad2f(25, 90.4f, 26.5f, 89.6f, 26.5f, 97.6f, 25, 98.4f);
    glColor3f(0.30f, 0.70f, 0.45f);
    quad2f(26.5f, 89.6f, 29.5f, 88.0f, 29.5f, 96.0f, 26.5f, 97.6f);

    glColor3f(0.75f, 0.25f, 0.25f);
    quad2f(27, 89.3f, 28.5f, 88.5f, 28.5f, 97.5f, 27, 98.3f);
    glColor3f(0.90f, 0.40f, 0.40f);
    quad2f(28.5f, 88.5f, 31.5f, 86.9f, 31.5f, 95.9f, 28.5f, 97.5f);

    glColor3f(0.92f, 0.92f, 0.86f);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(24.8f, 91.0f); glVertex2f(24.8f, 99.3f);
        glVertex2f(26.8f, 89.8f); glVertex2f(26.8f, 97.2f);
        glVertex2f(28.8f, 88.7f); glVertex2f(28.8f, 97.1f);
    glEnd();
}

//Reloj de Pared - Yessica
void relojPared()
{
    int i;

    /// Sombra del reloj: elipse suave desplazada abajo-izquierda,
    // como una sombra proyectada real (antes era un cuadrado alineado a ejes)
    glColor3f(0.65f, 0.64f, 0.58f);
    glPushMatrix();
        glTranslatef(58.0f - 3.0f, 68.0f - 3.0f, 0.0f);  // centro del reloj, corrido como sombra
        glScalef(1.0f, 0.82f, 1.0f);                      // aplasta verticalmente
        circuloRelleno(0.0f, 0.0f, 11.0f, 48);            // circulo dibujado en el origen local
    glPopMatrix();

    // Marco exterior circular
    glColor3f(0.28f, 0.18f, 0.10f);
    circuloRelleno(58.0f, 68.0f, 11.0f, 64);

    // Borde dorado
    glColor3f(0.85f, 0.68f, 0.25f);
    circuloRelleno(58.0f, 68.0f, 9.5f, 64);

    // Esfera del reloj
    glColor3f(0.96f, 0.94f, 0.84f);
    circuloRelleno(58.0f, 68.0f, 8.7f, 64);

    // Marcas horarias
    glColor3f(0.15f, 0.12f, 0.10f);
    glPointSize(3);
    glBegin(GL_POINTS);
    for (i = 0; i < 12; i++)
    {
        float a = 2.0f * 3.1415926f * i / 12.0f;
        glVertex2f(58.0f + 7.2f * cos(a), 68.0f + 7.2f * sin(a));
    }
    glEnd();

    // Manecillas: 10:10
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(58, 68); glVertex2f(53.0f, 72.2f);
        glVertex2f(58, 68); glVertex2f(64.2f, 70.8f);
    glEnd();

    // Centro
    glPointSize(4);
    glBegin(GL_POINTS);
        glVertex2f(58, 68);
    glEnd();

    // Brillo del cristal
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glVertex2f(52.5f, 73.5f); glVertex2f(55.0f, 75.5f);
    glEnd();
}

//LIBROS EXTRA - YESSICA
void librosExtra()
{
    // Sombra
    glColor3f(0.55f, 0.32f, 0.18f);

    quad2f(
        -4, 73,
        8, 78,
        9, 76,
        -3, 71
    );

    // Libro azul
    glColor3f(0.18f, 0.35f, 0.70f);

    quad2f(
        -4, 73,
        5, 77,
        5, 79,
        -4, 75
    );

    // Libro verde
    glColor3f(0.25f, 0.55f, 0.35f);

    quad2f(
        -3, 75,
        6, 79,
        6, 81,
        -3, 77
    );

    // Libro rojo
    glColor3f(0.72f, 0.25f, 0.25f);

    quad2f(
        -2, 77,
        7, 81,
        7, 83,
        -2, 79
    );

    // Líneas de páginas
    glColor3f(0.95f, 0.90f, 0.72f);
    glLineWidth(1);

    glBegin(GL_LINES);
        glVertex2f(-1, 78);
        glVertex2f(6, 81);

        glVertex2f(-2, 76);
        glVertex2f(5, 79);
    glEnd();
}


