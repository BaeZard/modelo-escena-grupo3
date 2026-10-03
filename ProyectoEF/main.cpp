#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>

// ============================================================
// DORMITORIO 3D 
//
// CONTROLES:
// Flecha izquierda/derecha = girar la cámara
// Flecha arriba/abajo      = subir/bajar la cámara
// W / S                    = acercar / alejar
// A / D                    = mover la vista
// R                        = restaurar cámara
// ESC                      = salir
// ============================================================

//Posición de la cámara en el espacio 3D
float camX = 18.0f, camY = 14.0f, camZ = 20.0f;
float targetX = 0.0f, targetY = 2.0f, targetZ = -1.0f;
//Ángulo de rotación horizontal de la cámara
float angleY = 0.0f;
//Control de zoom
float zoom = 1.0f;

//Rotación del gato mediante el mouse
float rotGato = 0.0f;
//Posición anterior del mouse
int mouseX, mouseY;

//Rotación de la silla con la tecla espacio
float rotSilla = 0.0f;

void setColor(float r, float g, float b){ 
    glColor3f(r, g, b); 
}

// ============================================================
// FUNCIÓN PARA CREAR CAJAS 3D
// Se utiliza para paredes, muebles, cama, puerta, etc.
// ============================================================
void box(float x, float y, float z, float sx, float sy, float sz,
         float r, float g, float b){
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    setColor(r, g, b);
    glutSolidCube(1.0);
    glPopMatrix();
}


// ============================================================
// FUNCIÓN PARA CREAR ESFERAS
// Se utiliza para pelotas, adornos y detalles decorativos.
// ============================================================
void cylinder(float x, float y, float z, float radius, float height,
              float r, float g, float b, int slices = 24){
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-90, 1, 0, 0);
    setColor(r, g, b);

    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, radius, radius, height, slices, 1);
    gluDisk(q, 0, radius, slices, 1);

    glTranslatef(0, 0, height);
    gluDisk(q, 0, radius, slices, 1);
    gluDeleteQuadric(q);

    glPopMatrix();
}

// ============================================================
// FUNCIÓN PARA CREAR ESFERAS
// Se utiliza para pelotas, adornos y detalles decorativos.
// ============================================================
void sphere(float x, float y, float z, float radius,
            float r, float g, float b){
    glPushMatrix();
    glTranslatef(x, y, z);
    setColor(r, g, b);
    glutSolidSphere(radius, 24, 16);
    glPopMatrix();
}

// ------------------------------------------------------------
// PISO - BELEN CHAVEZ
void piso(){
    box(0, -0.25f, 0, 20.0f, 0.5f, 18.0f,
        0.45f, 0.25f, 0.12f);

    // Listones de madera
    for(int z = -8; z <= 8; z++){
        for(int x = -9; x <= 9; x++){
            if((x + z) % 2 == 0)
                box(x, -0.01f, z, 0.98f, 0.04f, 0.96f,
                    0.58f, 0.33f, 0.16f);
            else
                box(x, -0.01f, z, 0.98f, 0.04f, 0.96f,
                    0.50f, 0.27f, 0.12f);
        }
    }
}

// ------------------------------------------------------------
// PAREDES - BELEN CHAVEZ
void paredes(){
    // Pared posterior
    box(0, 4.5f, -9.0f, 20.0f, 9.0f, 0.25f,
        0.84f, 0.84f, 0.72f);

    // Pared izquierda (extendida a 18 unidades de profundidad)
    box(-10.0f, 4.5f, 0, 0.25f, 9.0f, 18.0f,
        0.80f, 0.80f, 0.68f);

    // Zócalos
    box(0, 0.20f, -8.82f, 20.0f, 0.40f, 0.15f,
        0.30f, 0.18f, 0.10f);

    box(-9.82f, 0.20f, 0, 0.15f, 0.40f, 18.0f,
        0.30f, 0.18f, 0.10f);
}

// ------------------------------------------------------------
// PUERTA - BELEN CHAVEZ
void puerta(){
    box(-9.80f, 3.6f, -3.5f, 0.12f, 6.5f, 3.2f,
        0.33f, 0.18f, 0.08f);

    box(-9.72f, 3.6f, -3.5f, 0.10f, 6.0f, 2.8f,
        0.65f, 0.43f, 0.20f);

    sphere(-9.55f, 3.4f, -2.4f, 0.10f,
           0.85f, 0.70f, 0.20f);
}

// ------------------------------------------------------------
// ESPEJO - YESSICA BERNALOA
void espejo(){
    box(-9.68f, 4.0f, 1.2f, 0.10f, 4.4f, 2.5f,
        0.30f, 0.16f, 0.07f);

    box(-9.57f, 4.0f, 1.2f, 0.08f, 3.9f, 2.1f,
        0.70f, 0.85f, 0.90f);

    // Reflejo
    box(-9.47f, 4.9f, 1.2f, 0.03f, 1.7f, 0.18f,
        0.95f, 0.98f, 1.0f);
}

// ------------------------------------------------------------
// VENTANA Y CORTINAS - CARLOS ZAMORA
void ventana(){
    box(5.2f, 4.4f, -8.82f, 5.8f, 4.5f, 0.18f,
        0.30f, 0.18f, 0.08f);

    box(5.2f, 4.4f, -8.68f, 5.2f, 3.9f, 0.12f,
        0.70f, 0.86f, 0.96f);

    // Divisiones
    box(5.2f, 4.4f, -8.55f, 0.10f, 3.8f, 0.10f,
        0.30f, 0.18f, 0.08f);

    box(5.2f, 4.4f, -8.54f, 5.0f, 0.10f, 0.10f,
        0.30f, 0.18f, 0.08f);

    // Cortinas
    box(2.55f, 4.5f, -8.45f, 0.75f, 4.5f, 0.28f,
        0.65f, 0.05f, 0.08f);

    box(7.85f, 4.5f, -8.45f, 0.75f, 4.5f, 0.28f,
        0.65f, 0.05f, 0.08f);

    // Barra
    glPushMatrix();
    glTranslatef(2.1f, 6.75f, -8.38f);
    glRotatef(90, 0, 1, 0);
    setColor(0.25f, 0.16f, 0.08f);

    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, 0.07f, 0.07f, 5.7f, 16, 1);
    gluDeleteQuadric(q);

    glPopMatrix();
}

// ------------------------------------------------------------
// CAMA - BELEN CHAVEZ
void cabecera(){
    box(5.2f, 2.1f, -7.0f, 6.8f, 3.0f, 0.45f,
        0.38f, 0.16f, 0.09f);
}

// ALMOHADA - MIGUEL ROA
void almohada(float x, float z, float r, float g, float b){
    float y = 1.58f;
    box(x, y + 0.10f, z, 1.60f, 0.20f, 1.20f, r * 0.7f, g * 0.7f, b * 0.7f);   // BASE
    box(x, y + 0.25f, z, 1.48f, 0.14f, 1.08f, r, g, b);                        // CUERPO
    box(x, y + 0.34f, z, 1.25f, 0.06f, 0.85f,
        r + (1 - r) * 0.35f, g + (1 - g) * 0.35f, b + (1 - b) * 0.35f);        // TAPA CLARA
}

// ------------------------------------------------------------
// CAMA - MIGUEL ROA
void cama(){
    // Base
    box(5.2f, 0.45f, -3.8f, 7.2f, 0.9f, 8.8f,
        0.34f, 0.16f, 0.08f);

    // Colchón
    box(5.2f, 1.05f, -3.8f, 6.9f, 0.75f, 8.5f,
        0.95f, 0.38f, 0.42f);

    // Sábana
    box(5.2f, 1.48f, -3.0f, 6.5f, 0.18f, 5.8f,
        0.94f, 0.45f, 0.48f);

    // Cobija azul
    box(5.2f, 1.62f, -0.35f, 5.9f, 0.20f, 2.0f,
        0.20f, 0.38f, 0.62f);

	almohada(3.2f, -6.15f, 0.62f, 0.50f, 0.85f);  
	almohada(7.2f, -6.15f, 0.95f, 0.78f, 0.30f); 
	
    cabecera();
}

// ------------------------------------------------------------
// MESA DE NOCHE Y LÁMPARA - JHON SIESQUEN
void mesaNoche(){
    box(0.15f, 1.25f, -6.65f, 2.2f, 2.5f, 2.0f,
        0.34f, 0.15f, 0.07f);

    box(0.15f, 2.58f, -6.65f, 2.35f, 0.18f, 2.12f,
        0.50f, 0.24f, 0.10f);

    for(int i = 0; i < 2; i++){
        box(0.15f, 1.15f + i * 0.65f, -5.60f,
            1.75f, 0.50f, 0.08f,
            0.46f, 0.22f, 0.09f);

        sphere(0.15f, 1.15f + i * 0.65f, -5.50f,
               0.08f, 0.85f, 0.65f, 0.25f);
    }
}

// ------------------------------------------------------------
// lAMPARA - MIGUEL ROA
void lampara(){
    cylinder(0.15f, 2.75f, -6.65f, 0.08f, 1.4f,
             0.30f, 0.18f, 0.08f);

    glPushMatrix();
    glTranslatef(0.15f, 4.0f, -6.65f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	setColor(0.95f, 0.75f, 0.30f);
    glutSolidCone(0.55, 0.75, 24, 12);
    glPopMatrix();

    // Foco de la lámpara
    sphere(0.15f, 4.02f, -6.65f, 0.18f,
           1.0f, 0.85f, 0.35f);
}

// ------------------------------------------------------------
// ESCRITORIO Y COMPUTADORA - JHON SIESQUEN
void escritorio(){
    box(-3.8f, 2.15f, -6.7f, 5.0f, 0.35f, 2.0f,
        0.45f, 0.20f, 0.09f);

    box(-5.7f, 0.95f, -6.7f, 0.35f, 2.4f, 1.5f,
        0.30f, 0.15f, 0.07f);

    box(-1.9f, 0.95f, -6.7f, 0.35f, 2.4f, 1.5f,
        0.30f, 0.15f, 0.07f);

    // Monitor
    box(-3.8f, 3.55f, -6.55f, 3.0f, 1.9f, 0.18f,
        0.08f, 0.10f, 0.12f);

    box(-3.8f, 3.55f, -6.35f, 2.7f, 1.55f, 0.08f,
        0.08f, 0.20f, 0.30f);

    box(-3.8f, 2.65f, -6.5f, 0.35f, 0.9f, 0.30f,
        0.18f, 0.18f, 0.18f);

    box(-3.8f, 2.25f, -6.5f, 1.5f, 0.18f, 0.8f,
        0.20f, 0.20f, 0.20f);

    // Teclado
    box(-3.8f, 2.40f, -5.75f, 2.0f, 0.12f, 0.65f,
        0.70f, 0.70f, 0.68f);
}

// ------------------------------------------------------------
// SILLA - MIGUEL ROA
void silla(){
    glPushMatrix();
    glTranslatef(-3.8f, 0, -3.8f);
    glRotatef(rotSilla, 0, 1, 0);  

    // Base de 5 patas con ruedas
    for(int i = 0; i < 5; i++){
        glPushMatrix();
        glRotatef(i * 72.0f, 0, 1, 0);
        box(0.25f, 0.20f, 0, 0.5f, 0.07f, 0.12f, 0.15f, 0.15f, 0.17f);
        sphere(0.5f, 0.10f, 0, 0.10f, 0.05f, 0.05f, 0.05f);
        glPopMatrix();
    }

    // Pistón y mecanismo
    cylinder(0, 0.20f, 0, 0.07f, 1.0f, 0.55f, 0.55f, 0.58f);
    cylinder(0, 1.20f, 0, 0.11f, 0.32f, 0.12f, 0.12f, 0.14f);
    box(0, 1.55f, 0, 0.5f, 0.10f, 0.5f, 0.12f, 0.12f, 0.14f);

    // Asiento
    box(0, 1.70f, 0, 2.0f, 0.25f, 2.0f, 0.07f, 0.08f, 0.11f);
    box(0, 1.88f, 0, 1.9f, 0.12f, 1.9f, 0.12f, 0.14f, 0.20f);
    box(0, 1.945f, 0, 1.2f, 0.01f, 1.5f, 0.18f, 0.20f, 0.28f);

    // Respaldo
    box(0, 2.30f, 0.95f, 0.3f, 0.9f, 0.12f, 0.15f, 0.15f, 0.17f);
    box(0, 3.30f, 1.05f, 1.9f, 1.9f, 0.22f, 0.12f, 0.14f, 0.20f);
    box(0, 3.30f, 0.93f, 1.5f, 1.5f, 0.04f, 0.15f, 0.35f, 0.60f);

    // Reposabrazos
    for(int s = -1; s <= 1; s += 2){
        box(s * 1.05f, 2.20f, 0.30f, 0.12f, 0.80f, 0.12f, 0.15f, 0.15f, 0.17f);
        box(s * 1.05f, 2.65f, -0.10f, 0.22f, 0.10f, 1.2f, 0.07f, 0.08f, 0.11f);
    }

    glPopMatrix();
}

// ------------------------------------------------------------
// REPISA Y DECORACION - CARLOS ZAMORA
void repisa(){
    box(-3.8f, 6.6f, -8.55f, 6.5f, 0.35f, 1.0f,
        0.38f, 0.18f, 0.08f);

    box(-3.8f, 6.15f, -8.55f, 6.2f, 0.20f, 0.8f,
        0.45f, 0.22f, 0.10f);

    float colors[5][3]={
        {0.12f, 0.35f, 0.75f},
        {0.85f, 0.15f, 0.20f},
        {0.20f, 0.65f, 0.30f},
        {0.90f, 0.60f, 0.10f},
        {0.55f, 0.25f, 0.65f}
    };

    // --- LIBROS CENTRADOS EN LA REPISA ---
    for(int i = 0; i < 5; i++) {
        float xPos = -4.64f + i * 0.42f; 
        box(xPos, 7.15f, -8.45f,
            0.32f, 1.0f, 0.65f,
            colors[i][0], colors[i][1], colors[i][2]);
    }

    // Florero 
    cylinder(-6.3f, 7.0f, -8.45f, 0.30f, 0.9f,
             0.10f, 0.55f, 0.55f);

    for(int i = 0; i < 4; i++)
        sphere(-6.3f + (i - 1.5f) * 0.22f,
                8.05f, -8.45f,
                0.25f, 0.10f, 0.55f, 0.20f);

    // Osito 
    sphere(-1.5f, 7.15f, -8.45f, 0.35f,
            0.65f, 0.40f, 0.20f);

    sphere(-1.5f, 7.65f, -8.45f, 0.30f,
            0.65f, 0.40f, 0.20f);

    sphere(-1.70f, 7.88f, -8.45f, 0.12f,
            0.65f, 0.40f, 0.20f);

    sphere(-1.30f, 7.88f, -8.45f, 0.12f,
            0.65f, 0.40f, 0.20f);
}

// ------------------------------------------------------------
// RELOJ - YESSICA BERNALOA
void reloj(){
    glPushMatrix();
    glTranslatef(-8.2f, 6.0f, -8.65f);

    setColor(0.95f, 0.88f, 0.65f);
    glutSolidTorus(0.10, 0.65, 16, 24);

    setColor(0.98f, 0.96f, 0.82f);
    glutSolidSphere(0.57f, 24, 16);

    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0.60f);
        glVertex3f(0, 0, 0.38f);

        glVertex3f(0, 0, 0.60f);
        glVertex3f(0.35f, 0, 0.52f);
    glEnd();

    glPopMatrix();
}

// ------------------------------------------------------------
// ALFOMBRA - YESSICA BERNALOA
void alfombra(){
    box(-1.8f, 0.08f, -1.2f, 5.5f, 0.10f, 4.0f,
        0.75f, 0.30f, 0.20f);

    box(-1.8f, 0.14f, -1.2f, 4.8f, 0.06f, 3.3f,
        0.90f, 0.55f, 0.32f);
}

// ------------------------------------------------------------
// CÓMODA (AHORA ENTRA PERFECTAMENTE EN LA PARED AMPLIADA) - BELEN CHAVEZ
void comoda(){
    box(-8.60f, 1.35f, 5.2f, 2.4f, 2.7f, 4.0f,
        0.48f, 0.22f, 0.10f);

    for(int i = 0; i < 3; i++){
        box(-7.35f, 0.65f + i * 0.72f, 5.2f,
            0.10f, 0.55f, 3.2f,
            0.62f, 0.32f, 0.12f);

        sphere(-7.20f, 0.65f + i * 0.72f, 5.2f,
               0.08f, 0.95f, 0.78f, 0.10f);
    }
}

// ------------------------------------------------------------
// PELOTA - JHON SIESQUEN
void pelota(){
    sphere(0.5f, 0.65f, -0.1f, 0.60f,
           0.95f, 0.95f, 0.95f);

    glPushMatrix();
    glTranslatef(0.5f, 0.65f, -0.1f);
    setColor(0.05f, 0.05f, 0.05f);
    glutSolidTorus(0.07, 0.43, 10, 20);
    glPopMatrix();
}

// ------------------------------------------------------------
// SKATEBOARD - JHON SIESQUEN
void skateboard(){
    box(1.0f, 0.60f, 2.2f, 3.0f, 0.15f, 0.55f,
        0.35f, 0.08f, 0.18f);

    cylinder(0.0f, 0.10f, 2.0f, 0.18f, 0.15f,
             0.08f, 0.08f, 0.08f);

    cylinder(2.0f, 0.10f, 2.0f, 0.18f, 0.15f,
             0.08f, 0.08f, 0.08f);
}

// ------------------------------------------------------------
// PLANTA - YESSICA BERNALOA
void planta(){
    cylinder(7.8f, 0.35f, 3.0f, 0.55f, 0.8f,
             0.60f, 0.25f, 0.12f);

    for(int i = 0; i < 6; i++){
        float a = i * 60.0f * 3.14159f / 180.0f;

        sphere(7.8f + 0.55f * cos(a),
               1.45f,
               3.0f + 0.55f * sin(a),
               0.35f,
               0.10f, 0.50f, 0.18f);
    }
}

// ------------------------------------------------------------
// CUADRO DECORATIVO - CARLOS ZAMORA
void cuadro(){
    box(1.0f, 6.0f, -8.65f, 2.0f, 1.5f, 0.12f,
        0.30f, 0.18f, 0.08f);

    box(1.0f, 6.0f, -8.52f, 1.65f, 1.15f, 0.08f,
        0.75f, 0.85f, 0.55f);
}

// GATO SOBRE CAMA - BELEN
void gato()
{
    // Cuerpo
    setColor(1.0f, 0.70f, 0.35f);
    glPushMatrix();
    glScalef(1.0f, 0.8f, 1.5f);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Cabeza
    setColor(1.0f, 0.70f, 0.35f);// naranja suave
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.8f);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    // Oreja izquierda
    setColor(0.80f, 0.65f, 0.15f);
    glPushMatrix();
    glTranslatef(-0.15f, 0.55f, 0.8f);
    glutSolidCone(0.08, 0.2, 10, 10);
    glPopMatrix();

    // Oreja derecha
    glPushMatrix();
    glTranslatef(0.15f, 0.55f, 0.8f);
    glutSolidCone(0.08, 0.2, 10, 10);
    glPopMatrix();
    
	// Ojos verdes
	setColor(0.3f, 1.0f, 0.2f);
	
	// Ojo izquierdo
	glPushMatrix();
	glTranslatef(-0.10f, 0.38f, 1.12f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();
	
	// Ojo derecho
	glPushMatrix();
	glTranslatef(0.10f, 0.38f, 1.12f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();
	
    // Cola
    setColor(0.95f, 0.50f, 0.10f);
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, -0.75f);
    glRotatef(-45, 1, 0, 0);

    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, 0.05, 0.03, 0.5, 12, 12);
    gluDeleteQuadric(q);

    glPopMatrix();
}

// ------------------------------------------------------------
// LIBRO CERRADO - MIGUEL ROA
void libro(float x, float y, float z, float rot,
           float w, float d, float r, float g, float b){
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rot, 0, 1, 0);

    // Tapa inferior y superior
    box(0, 0.015f, 0, w, 0.03f, d, r, g, b);
    box(0, 0.155f, 0, w, 0.03f, d, r, g, b);

    // Lomo
    box(-w / 2 + 0.03f, 0.085f, 0, 0.06f, 0.17f, d,
        r * 0.7f, g * 0.7f, b * 0.7f);

    // Hojas
    box(0.02f, 0.085f, 0, w - 0.08f, 0.14f, d - 0.06f,
        0.96f, 0.94f, 0.85f);

    glPopMatrix();
}

// ------------------------------------------------------------
// PELUCHE (OSO) - MIGUEL ROA
void peluche(float x, float z, float rot){
    float y0 = 1.57f;   // altura de la sábana

    glPushMatrix();
    glTranslatef(x, 0, z);
    glRotatef(rot, 0, 1, 0);

    // Cuerpo y barriga
    sphere(0, y0 + 0.45f, 0, 0.45f, 0.72f, 0.46f, 0.25f);
    sphere(0, y0 + 0.42f, 0.28f, 0.28f, 0.90f, 0.75f, 0.55f);

    // Piernas
    sphere(-0.28f, y0 + 0.22f, 0.35f, 0.22f, 0.60f, 0.36f, 0.18f);
    sphere( 0.28f, y0 + 0.22f, 0.35f, 0.22f, 0.60f, 0.36f, 0.18f);

    // Brazos
    sphere(-0.50f, y0 + 0.58f, 0.12f, 0.16f, 0.60f, 0.36f, 0.18f);
    sphere( 0.50f, y0 + 0.58f, 0.12f, 0.16f, 0.60f, 0.36f, 0.18f);

    // Cabeza
    sphere(0, y0 + 1.12f, 0, 0.33f, 0.78f, 0.52f, 0.30f);

    // Orejas
    sphere(-0.24f, y0 + 1.42f, 0, 0.12f, 0.60f, 0.36f, 0.18f);
    sphere( 0.24f, y0 + 1.42f, 0, 0.12f, 0.60f, 0.36f, 0.18f);

    // Hocico y nariz
    sphere(0, y0 + 1.05f, 0.30f, 0.13f, 0.92f, 0.80f, 0.62f);
    sphere(0, y0 + 1.10f, 0.41f, 0.05f, 0.08f, 0.05f, 0.05f);

    // Ojos
    sphere(-0.12f, y0 + 1.19f, 0.29f, 0.04f, 0.05f, 0.05f, 0.05f);
    sphere( 0.12f, y0 + 1.19f, 0.29f, 0.04f, 0.05f, 0.05f, 0.05f);

    // Moño
    box(-0.12f, y0 + 0.80f, 0.30f, 0.16f, 0.12f, 0.06f, 0.85f, 0.15f, 0.20f);
    box( 0.12f, y0 + 0.80f, 0.30f, 0.16f, 0.12f, 0.06f, 0.85f, 0.15f, 0.20f);
    sphere(0, y0 + 0.80f, 0.31f, 0.06f, 0.65f, 0.08f, 0.12f);

    glPopMatrix();
}

// ------------------------------------------------------------
// MANTA DOBLADA CON RAYAS - MIGUEL ROA
void manta(float x, float z, float rot){
    glPushMatrix();
    glTranslatef(x, 1.72f, z);     // 1.72 = parte de arriba de la cobija
    glRotatef(rot, 0, 1, 0);

    // Tres capas dobladas (se ven en el borde)
    box(0.00f, 0.045f, 0, 2.00f, 0.09f, 1.20f, 0.88f, 0.40f, 0.38f);  // coral
    box(0.03f, 0.135f, 0, 1.98f, 0.09f, 1.18f, 0.96f, 0.92f, 0.80f);  // crema
    box(0.00f, 0.225f, 0, 2.00f, 0.09f, 1.20f, 0.93f, 0.72f, 0.25f);  // mostaza

    // Rayas sobre la capa de arriba
    for(int i = 0; i < 5; i++){
        if(i % 2 == 0)
            box(-0.8f + i * 0.4f, 0.275f, 0, 0.20f, 0.01f, 1.18f,
                0.88f, 0.40f, 0.38f);   // coral
        else
            box(-0.8f + i * 0.4f, 0.275f, 0, 0.20f, 0.01f, 1.18f,
                0.96f, 0.92f, 0.80f);   // crema
    }

    glPopMatrix();
}


// ------------------------------------------------------------
// CELULAR - MIGUEL ROA
void celular(float x, float z, float rot){
    float y0 = 1.57f; 

    glPushMatrix();
    glTranslatef(x, y0, z);
    glRotatef(rot, 0, 1, 0);

    // Cuerpo 
    box(0, 0.02f, 0, 0.46f, 0.04f, 0.86f,
        0.12f, 0.12f, 0.15f);

    // Pantalla encendida
    box(0, 0.045f, 0, 0.40f, 0.01f, 0.78f,
        0.25f, 0.55f, 0.85f);

    // Cámara frontal
    box(0, 0.052f, -0.35f, 0.14f, 0.01f, 0.02f,
        0.05f, 0.05f, 0.07f);

    // Reloj en la pantalla
    box(0, 0.052f, -0.18f, 0.22f, 0.01f, 0.07f,
        0.95f, 0.97f, 1.00f);

    // Notificaciones
    box(0, 0.052f, 0.02f, 0.30f, 0.01f, 0.05f,
        0.75f, 0.88f, 0.98f);
    box(0, 0.052f, 0.12f, 0.30f, 0.01f, 0.05f,
        0.75f, 0.88f, 0.98f);

    // Iconos de aplicaciones
    for(int i = 0; i < 3; i++){
        box(-0.12f + i * 0.12f, 0.052f, 0.28f, 0.08f, 0.01f, 0.08f,
            0.95f - i * 0.30f, 0.45f + i * 0.20f, 0.30f + i * 0.25f);
    }

    // Barra inferior
    box(0, 0.052f, 0.36f, 0.12f, 0.01f, 0.015f,
        1.00f, 1.00f, 1.00f);

    glPopMatrix();
}

// ------------------------------------------------------------
// OBJETOS SOBRE LA CAMA - MIGUEL ROA
void decoracionCama(){
    // Peluche junto a la almohada derecha
    peluche(7.4f, -4.9f, 25.0f);

    // Pila de libros en el lado izquierdo
    libro(3.1f, 1.57f, -4.0f,  0.0f, 1.10f, 0.80f, 0.15f, 0.30f, 0.65f);
    libro(3.1f, 1.74f, -4.0f, 15.0f, 0.95f, 0.70f, 0.75f, 0.20f, 0.20f);

    manta(3.8f, -0.3f, 15.0f); 
    celular(7.0f, -2.8f, -20.0f);
}


// ------------------------------------------------------------
// LIBROS TIRADOS EN EL PISO - MIGUEL ROA
void librosPiso(){
    float yPiso = 0.02f;   // altura del piso

    // Pila de dos libros
    libro(5.2f, yPiso,         3.2f,  20.0f, 1.30f, 0.95f, 0.20f, 0.50f, 0.30f);
    libro(5.2f, yPiso + 0.17f, 3.2f, -15.0f, 1.00f, 0.75f, 0.85f, 0.65f, 0.20f);

    // Libro suelto
    libro(6.3f, yPiso, 4.8f, -40.0f, 1.20f, 0.90f, 0.70f, 0.20f, 0.25f);
}



// LENTES - MIGUEL ROA
void lentes(){
    float yMesa = 2.67f;   // altura de la tapa de la mesa de noche

    glPushMatrix();
    glTranslatef(0.65f, yMesa + 0.135f, -5.95f);
    glRotatef(25, 0, 1, 0);      // girados hacia la cámara
    glRotatef(-22.5f, 1, 0, 0);  // cristales inclinados hacia atrás
    glScalef(0.6f, 0.6f, 0.6f);  // tamaño de los lentes

    for(int s = -1; s <= 1; s += 2){
        float cx = s * 0.28f;   // centro de cada luna

        // Marco cuadrado (4 barras)
        box(cx,         0.20f, 0, 0.45f, 0.05f, 0.06f, 0.08f, 0.08f, 0.10f);  // arriba
        box(cx,        -0.20f, 0, 0.45f, 0.05f, 0.06f, 0.08f, 0.08f, 0.10f);  // abajo
        box(cx - 0.20f, 0,     0, 0.05f, 0.35f, 0.06f, 0.08f, 0.08f, 0.10f);  // izquierda
        box(cx + 0.20f, 0,     0, 0.05f, 0.35f, 0.06f, 0.08f, 0.08f, 0.10f);  // derecha

        box(cx, 0, 0, 0.36f, 0.36f, 0.02f, 0.70f, 0.88f, 0.98f);                       // luna cuadrada
        sphere(s * 0.52f, 0.12f, -0.01f, 0.04f, 0.90f, 0.72f, 0.20f);                  // bisagra dorada
        box(s * 0.52f, 0.12f, -0.38f, 0.03f, 0.03f, 0.76f, 0.08f, 0.08f, 0.10f);       // patilla
        box(s * 0.52f, 0.12f, -0.70f, 0.04f, 0.04f, 0.16f, 0.55f, 0.20f, 0.12f);       // punta de la patilla
        sphere(s * 0.11f, -0.10f, 0.04f, 0.03f, 0.85f, 0.85f, 0.88f);                  // plaquita de la nariz
    }

    box(0, 0.12f, 0, 0.16f, 0.04f, 0.05f, 0.08f, 0.08f, 0.10f);                        // puente
    glPopMatrix();
}

// CILINDRO (GUITARRA Y MOCHILA) - MIGUEL ROA
void cilindroZ(float x, float y, float z, float radius, float depth,
            float r, float g, float b){
    glPushMatrix();
    glTranslatef(x, y, z - depth / 2);
    setColor(r, g, b);

    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, radius, radius, depth, 32, 1);
    gluDisk(q, 0, radius, 32, 1);

    glTranslatef(0, 0, depth);
    gluDisk(q, 0, radius, 32, 1);
    gluDeleteQuadric(q);

    glPopMatrix();
}
// GUITARRA - MIGUEL ROA
void guitarra(float x, float z, float yaw){
    glPushMatrix();
    glTranslatef(x, 0.06f, z);
    glRotatef(yaw, 0, 1, 0);       
    glRotatef(-10, 1, 0, 0);       
	glScalef(0.8f, 0.8f, 0.8f);

    // ---------- CUERPO ----------
    cilindroZ(0, 0.95f, 0, 0.95f, 0.50f, 0.40f, 0.12f, 0.06f); 
    cilindroZ(0, 2.00f, 0, 0.70f, 0.50f, 0.40f, 0.12f, 0.06f);  

    // ---------- TAPA----------
    cilindroZ(0, 0.95f, 0.26f, 0.89f, 0.02f, 0.93f, 0.62f, 0.22f);
    cilindroZ(0, 2.00f, 0.26f, 0.64f, 0.02f, 0.93f, 0.62f, 0.22f);

    // ---------- BOCA ----------
    cilindroZ(0, 1.95f, 0.275f, 0.28f, 0.01f, 0.05f, 0.03f, 0.02f);
    glPushMatrix();
    glTranslatef(0, 1.95f, 0.28f);
    setColor(0.30f, 0.14f, 0.05f);
    glutSolidTorus(0.025, 0.31, 8, 32);
    glPopMatrix();

    // ---------- PUENTE ----------
    box(0, 0.55f, 0.30f, 0.70f, 0.14f, 0.06f,
        0.15f, 0.08f, 0.04f);

    // ---------- MÁSTIL ----------
    box(0, 3.15f, 0.0f, 0.26f, 1.70f, 0.18f,
        0.55f, 0.30f, 0.12f);

    // Diapasón
    box(0, 3.22f, 0.11f, 0.24f, 1.45f, 0.04f,
        0.10f, 0.06f, 0.04f);

    // Trastes
    float trastes[5] = {2.95f, 3.20f, 3.42f, 3.62f, 3.80f};
    for(int i = 0; i < 5; i++){
        box(0, trastes[i], 0.135f, 0.25f, 0.015f, 0.015f,
            0.80f, 0.80f, 0.75f);
    }

    // Cejuela
    box(0, 3.96f, 0.13f, 0.26f, 0.04f, 0.05f,
        0.92f, 0.90f, 0.82f);

    // ---------- CLAVIJERO ----------
    box(0, 4.20f, 0.0f, 0.36f, 0.50f, 0.12f,
        0.20f, 0.10f, 0.05f);

    box(0, 4.25f, 0.065f, 0.14f, 0.14f, 0.01f,
        0.90f, 0.80f, 0.50f);

    // Clavijas
    for(int i = 0; i < 3; i++){
        sphere(-0.23f, 4.07f + i * 0.13f, 0, 0.045f, 0.85f, 0.78f, 0.40f);
        sphere( 0.23f, 4.07f + i * 0.13f, 0, 0.045f, 0.85f, 0.78f, 0.40f);
    }

    // ---------- CUERDAS ----------
     glLineWidth(1.5f);
    setColor(0.92f, 0.92f, 0.88f);
    glBegin(GL_LINES);
    for(int i = 0; i < 4; i++){
        float xb = -0.09f + i * 0.06f;   // en el puente
        float xn = -0.06f + i * 0.04f;   // en la cejuela
        float xm = xb + (xn - xb) * (2.15f / 3.41f);

        glVertex3f(xb, 0.55f, 0.34f);
        glVertex3f(xm, 2.70f, 0.30f);

        glVertex3f(xm, 2.70f, 0.30f);
        glVertex3f(xn, 3.96f, 0.15f);
    }
    glEnd();
    glLineWidth(1.0f);
    glPopMatrix();
}

// MOCHILA - MIGUEL ROA
void mochila(float x, float z, float yaw){
    glPushMatrix();
    glTranslatef(x, 0.05f, z);
    glRotatef(yaw, 0, 1, 0);      
    glRotatef(-5, 1, 0, 0);   

    // ---------- CUERPO ----------
    box(0, 0.675f, 0, 1.30f, 1.35f, 0.75f,
        0.45f, 0.28f, 0.65f);

    // Parte superior redondeada
   cilindroZ(0, 1.30f, 0, 0.65f, 0.75f, 0.45f, 0.28f, 0.65f);

    // Base reforzada (más oscura)
    box(0, 0.11f, 0, 1.32f, 0.22f, 0.77f,
        0.25f, 0.15f, 0.40f);

    // ---------- BOLSILLO FRONTAL ----------
    box(0, 0.55f, 0.485f, 1.00f, 0.80f, 0.22f,
        0.58f, 0.40f, 0.80f);

    // Cierre del bolsillo
    box(0, 0.92f, 0.60f, 0.90f, 0.04f, 0.02f,
        0.95f, 0.80f, 0.25f);
    sphere(0.38f, 0.90f, 0.61f, 0.05f, 0.95f, 0.80f, 0.25f);

    // ---------- CIERRE PRINCIPAL ----------
    box(0, 1.45f, 0.385f, 1.00f, 0.03f, 0.02f,
        0.95f, 0.80f, 0.25f);
    sphere(0.45f, 1.45f, 0.395f, 0.05f, 0.95f, 0.80f, 0.25f);

    // ---------- ASA SUPERIOR ----------
   glPushMatrix();
    glTranslatef(0, 1.95f, 0);
    setColor(0.25f, 0.15f, 0.40f);
    glutSolidTorus(0.035, 0.18, 8, 16);
    glPopMatrix();

    // ---------- BOLSILLO LATERAL CON BOTELLA ----------
  box(0.69f, 0.32f, 0.05f, 0.10f, 0.55f, 0.50f,
    0.58f, 0.40f, 0.80f);

   cylinder(0.80f, 0.10f, 0.05f, 0.16f, 0.70f,
           0.30f, 0.75f, 0.90f);

   cylinder(0.80f, 0.80f, 0.05f, 0.10f, 0.12f,
          0.10f, 0.10f, 0.12f);

   glPopMatrix();
}

// ------------------------------------------------------------
// ESCENA COMPLETA
// ------------------------------------------------------------
void room(){
    piso();
    paredes();
    puerta();
    espejo();
    ventana();
    cama();
    
    // Gato sobre la cama
	glPushMatrix();
	glTranslatef(5.2f, 2.0f, -2.5f);
	glRotatef(rotGato, 0.0f, 1.0f, 0.0f);
	glScalef(1.2f, 1.2f, 1.2f);
	gato();
	glPopMatrix();

	
    mesaNoche();
    decoracionCama();
    lampara();
    escritorio();
    silla();
    repisa();
    reloj();
    alfombra();
    comoda();
    pelota();
    skateboard();
    planta();
    cuadro();
    librosPiso();
    lentes();
    mochila(3.6f, 1.6f, 25.0f); 
    guitarra(-9.1f, 8.15f, 75.0f);
}


//============================================================
//RENDERIZADO DE LA ESCENA
//Configura la cámara y dibuja todos los objetos.
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float rad = angleY * 3.14159265f / 180.0f;

    float x = camX * cos(rad) - camZ * sin(rad);
    float z = camX * sin(rad) + camZ * cos(rad);

    gluLookAt(
        x * zoom, camY * zoom, z * zoom,
        targetX, targetY, targetZ,
        0, 1, 0
    );

    room();

    glutSwapBuffers();
}

//AJUSTE DE LA PERSPECTIVA AL CAMBIAR EL TAMAÑO DE LA VENTANA
void reshape(int w, int h){
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        55.0,
        (double)w / (double)h,
        0.1,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}

// CONTROL DEL TECLADO
// Permite zoom, desplazamiento y reinicio de cámara.
void keyboard(unsigned char key, int, int){
    if(key == 27)
        exit(0);
        
    if(key == ' '){
        rotSilla += 15.0f;
        if(rotSilla >= 360.0f) rotSilla -= 360.0f;
    }

    if(key == 'w' || key == 'W')
        zoom -= 0.05f;

    if(key == 's' || key == 'S')
        zoom += 0.05f;

    if(key == 'a' || key == 'A')
        targetX -= 0.5f;

    if(key == 'd' || key == 'D')
        targetX += 0.5f;

    if(key == 'r' || key == 'R'){
        camX = 18.0f;
        camY = 14.0f;
        camZ = 20.0f;

        targetX = 0.0f;
        targetY = 2.0f;
        targetZ = -1.0f;

        angleY = 0.0f;
        zoom = 1.0f;
    }

    if(zoom < 0.55f) zoom = 0.55f;
    if(zoom > 1.8f) zoom = 1.8f;

    glutPostRedisplay();
}

//CONTROL DE LAS FLECHAS DEL TECLADO
//Permite rotar y mover la cámara verticalmente.
void special(int key, int, int){
    if(key == GLUT_KEY_LEFT)
        angleY -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        angleY += 5.0f;

    if(key == GLUT_KEY_UP)
        camY += 0.5f;

    if(key == GLUT_KEY_DOWN)
        camY -= 0.5f;

    if(camY < 5.0f) camY = 5.0f;
    if(camY > 25.0f) camY = 25.0f;

    glutPostRedisplay();
}

//REGISTRA LA POSICIÓN INICIAL DEL MOUSE
void onMouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON &&
       state == GLUT_DOWN)
    {
        mouseX = x;
        mouseY = y;
    }
}

//ROTACIÓN DEL GATO CON EL MOVIMIENTO DEL MOUSE
void onMotion(int x, int y)
{
    rotGato += (x - mouseX);

    mouseX = x;
    mouseY = y;

    glutPostRedisplay();
}

//MAIN
int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(1200, 750);
    glutInitWindowPosition(80, 40);

    glutCreateWindow(
        "MODELO CUARTO 3D"
    );

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    glClearColor(
        0.74f, 0.84f, 0.58f, 1.0f
    );


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    //Funciones para movimiento con mouse
    glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);

    glutMainLoop();

    return 0;
}
