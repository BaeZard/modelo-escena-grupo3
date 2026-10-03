#include <GL/freeglut.h>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
// ============================================================
// DORMITORIO 3D 
//
// CONTROLES:
// Flecha izquierda/derecha = girar la cámara
// Flecha arriba/abajo      = subir/bajar la cámara
// W / S                    = acercar / alejar
// A / D                    = mover la vista
// R                        = restaurar cámara
// Espacio                  = girar silla
// ESC                      = salir
// ============================================================

//Posición de la cámara en el espacio 3D
float camX = 18.0f, camY = 14.0f, camZ = 20.0f;
float targetX = 0.0f, targetY = 2.0f, targetZ = -1.0f;

//Ángulo de rotación horizontal de la cámara
float angleY = 0.0f;
//Control de zoom
float zoom = 1.0f;

//JHON SIESQUEN (Variables de animacion)
float anguloAspas = 0.0f;
float giroCabeza = 0.0f;
float faseCabeza = 0.0f;
float robotT = 0.0f;
float discoAng = 0.0f;
int fase = 0;
int ventiladorOn = 1;
int robotOn = 1;
int musicaOn = 0;

//Ventana - Yessica
int winW = 1200, winH = 750;

//Recursos globales
GLUquadric* quad = NULL;   // un solo quadric para todo el programa
GLuint listaPiso = 0;      // display list del piso

void setColor(float r, float g, float b){
    glColor3f(r, g, b);
}


//Rotación del gato mediante el mouse
float rotGato = 0.0f;

//Posición anterior del mouse
int mouseX, mouseY;
int botonMouse = -1;

float rotSilla = 0.0f;

//CARLOS (VARIABLES DE ANIMACIÓN: Controlan el giro del ventilador de techo y el pulso luminoso del PC)
float rotVentilador = 0.0f;
float luzPC = 0.0f;
bool luzAumenta = true;

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

	gluCylinder(quad, radius, radius, height, slices, 1);
    gluDisk(quad, 0, radius, slices, 1);

    glTranslatef(0, 0, height);
    gluDisk(quad, 0, radius, slices, 1);


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

    // Reflejo en diagonal (dos líneas)
    glPushMatrix();
        glTranslatef(-9.50f, 4.9f, 1.2f);
        glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

        box(0.0f, 0.0f, -0.12f, 0.03f, 1.7f, 0.18f,
            0.95f, 0.98f, 1.0f);

        box(0.0f, -0.1f, 0.22f, 0.03f, 1.1f, 0.09f,
            0.95f, 0.98f, 1.0f);
    glPopMatrix();

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
// ALMOHADA (mullida, compacta) - MIGUEL ROA
void almohada(float x, float z, float r, float g, float b){
    glPushMatrix();
    glTranslatef(x, 1.72f, z);

    // Cuerpo (tono oscuro) y tapa abombada (tono claro)
    for(int i = 0; i < 2; i++){
        glPushMatrix();
        glTranslatef(0, i * 0.10f, 0);
        glScalef(1.00f - i * 0.22f, 0.28f + i * 0.02f, 0.60f - i * 0.18f);
        if(i == 0) setColor(r * 0.78f, g * 0.78f, b * 0.78f);
        else       setColor(r + (1 - r) * 0.3f, g + (1 - g) * 0.3f, b + (1 - b) * 0.3f);
        glutSolidSphere(1.0, 24, 16);
        glPopMatrix();
    }

    // Botón central
    sphere(0, 0.40f, 0, 0.07f, 0.98f, 0.92f, 0.70f);

    glPopMatrix();
}

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

   	almohada(3.2f, -6.15f, 0.62f, 0.50f, 0.85f);   // lavanda
    almohada(7.2f, -6.15f, 0.95f, 0.78f, 0.30f); 

    cabecera();
}

// ------------------------------------------------------------
// MESA DE NOCHE Y LÁMPARA - JHON SIESQUEN / YESSICA BERNAOLA
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

// lAMPARA - YESSICA BERNAOLA
void lampara(){
    // Poste
    cylinder(0.15f, 2.75f, -6.65f, 0.08f, 1.4f,
             0.30f, 0.18f, 0.08f);

    // Pantalla cónica
    glPushMatrix();
        glTranslatef(0.15f, 4.0f, -6.65f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        setColor(0.95f, 0.75f, 0.30f);
        glutSolidCone(0.55, 0.75, 24, 12);
    glPopMatrix();

    // Foco 
    glDisable(GL_LIGHTING);
    sphere(0.15f, 4.05f, -6.65f, 0.18f,
           1.0f, 0.90f, 0.50f);
    glEnable(GL_LIGHTING);

}

// Haz de luz translúcido: se dibuja AL FINAL de la escena - yessica
void hazLampara(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);      // no tapa lo que está detrás
    glDisable(GL_LIGHTING);

    glPushMatrix();
        glTranslatef(0.15f, 2.70f, -6.65f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glColor4f(1.0f, 0.95f, 0.70f, 0.20f);
        glutSolidCone(1.00, 1.35, 20, 10);
    glPopMatrix();

    glEnable(GL_LIGHTING);
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
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

// SILLA - MIGUEL ROA
void silla(){
    glPushMatrix();
    glTranslatef(-3.8f, 0, -3.8f);
    glRotatef(rotSilla, 0, 1, 0);  

    for(int i = 0; i < 5; i++){
        glPushMatrix();
        glRotatef(i * 72.0f, 0, 1, 0);
        box(0.25f, 0.20f, 0, 0.5f, 0.07f, 0.12f, 0.15f, 0.15f, 0.17f);
        sphere(0.5f, 0.10f, 0, 0.10f, 0.05f, 0.05f, 0.05f);
        glPopMatrix();
    }
    cylinder(0, 0.20f, 0, 0.07f, 1.0f, 0.55f, 0.55f, 0.58f);
    cylinder(0, 1.20f, 0, 0.11f, 0.32f, 0.12f, 0.12f, 0.14f);
    box(0, 1.55f, 0, 0.5f, 0.10f, 0.5f, 0.12f, 0.12f, 0.14f);
    box(0, 1.70f, 0, 2.0f, 0.25f, 2.0f, 0.07f, 0.08f, 0.11f);
    box(0, 1.88f, 0, 1.9f, 0.12f, 1.9f, 0.12f, 0.14f, 0.20f);
    box(0, 1.945f, 0, 1.2f, 0.01f, 1.5f, 0.18f, 0.20f, 0.28f);
    box(0, 2.30f, 0.95f, 0.3f, 0.9f, 0.12f, 0.15f, 0.15f, 0.17f);
    box(0, 3.30f, 1.05f, 1.9f, 1.9f, 0.22f, 0.12f, 0.14f, 0.20f);
    box(0, 3.30f, 0.93f, 1.5f, 1.5f, 0.04f, 0.15f, 0.35f, 0.60f);

    for(int s = -1; s <= 1; s += 2){
        box(s * 1.05f, 2.20f, 0.30f, 0.12f, 0.80f, 0.12f, 0.15f, 0.15f, 0.17f);
        box(s * 1.05f, 2.65f, -0.10f, 0.22f, 0.10f, 1.2f, 0.07f, 0.08f, 0.11f);
    }
    glPopMatrix();
}

// ------------------------------------------------------------
// REPISA Y DECORACION - CARLOS ZAMORA / YESSICA BERNAOLA
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

   // Florero -- YESSICA BERNAOLA
    cylinder(-6.3f, 6.9f, -8.45f, 0.30f, 0.9f,
             0.10f, 0.55f, 0.60f);

    float angulosFlor[3] = { 20.0f, 0.0f, -20.0f };
    float alturasFlor[3] = { 0.53f, 0.63f, 0.53f };

    for(int f = 0; f < 3; f++){
        glPushMatrix();
            glTranslatef(-6.30f, 7.80f, -8.45f);
            glRotatef(angulosFlor[f], 0.0f, 0.0f, 1.0f);

            // Tallo
            cylinder(0.0f, 0.0f, 0.0f, 0.03f, alturasFlor[f],
                     0.15f, 0.60f, 0.15f);

            // Centro
            float fy = alturasFlor[f];
            sphere(0.0f, fy, 0.05f, 0.08f,
                   0.95f, 0.85f, 0.10f);

            // Pétalos
            for(int p = 0; p < 5; p++){
                float ang = p * (2.0f * 3.14159f / 5.0f);
                float px = 0.12f * cosf(ang);
                float py = fy + 0.12f * sinf(ang);

                sphere(px, py, 0.02f, 0.06f,
                       0.90f, 0.20f, 0.40f);
            }
        glPopMatrix();
	}

    // Osito  --- YESSICA BERNAOLA
    sphere(-1.5f, 7.15f, -8.45f, 0.35f, 0.65f, 0.40f, 0.20f);   // cuerpo
    sphere(-1.5f, 7.65f, -8.45f, 0.30f, 0.65f, 0.40f, 0.20f);   // cabeza
    sphere(-1.70f, 7.88f, -8.45f, 0.12f, 0.65f, 0.40f, 0.20f); // oreja izq
    sphere(-1.30f, 7.88f, -8.45f, 0.12f, 0.65f, 0.40f, 0.20f); // oreja der
    sphere(-1.60f, 7.72f, -8.18f, 0.052f, 0.25f, 0.15f, 0.05f); // ojo izq
    sphere(-1.40f, 7.72f, -8.18f, 0.052f, 0.25f, 0.15f, 0.05f); // ojo der
    sphere(-1.50f, 7.55f, -8.18f, 0.058f, 0.25f, 0.15f, 0.05f); // nariz
    sphere(-1.72f, 6.90f, -8.30f, 0.14f, 0.65f, 0.40f, 0.20f); // pata izq
    sphere(-1.28f, 6.90f, -8.30f, 0.14f, 0.65f, 0.40f, 0.20f); // pata der

}

// ------------------------------------------------------------
// RELOJ - YESSICA BERNALOA
void reloj(){
    glPushMatrix();
    glTranslatef(-8.2f, 6.0f, -8.65f);

    // Marco
    setColor(0.95f, 0.75f, 0.30f);
    glutSolidTorus(0.08, 0.65, 16, 24);

    // Carátula plana
    setColor(0.98f, 0.96f, 0.82f);
    glPushMatrix();
        glScalef(1.0f, 1.0f, 0.05f);
        glutSolidSphere(0.60f, 24, 16);
    glPopMatrix();

    // Marcas de las 12 horas
    setColor(0.0f, 0.0f, 0.0f);
    for(int i = 0; i < 12; i++){
        float angulo = i * (2.0f * 3.14159f / 12.0f);
        float x = 0.45f * sinf(angulo);
        float y = 0.45f * cosf(angulo);

        glPushMatrix();
            glTranslatef(x, y, 0.05f);
            glutSolidSphere(0.052f, 10, 10);
        glPopMatrix();
    }

    // Manecillas (líneas: sin iluminación porque no tienen normales)
    glDisable(GL_LIGHTING);
    setColor(0.0f, 0.0f, 0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.08f);
        glVertex3f(0.0f, 0.38f, 0.08f);

        glVertex3f(0.0f, 0.0f, 0.08f);
        glVertex3f(0.26f, 0.0f, 0.08f);
    glEnd();
    glEnable(GL_LIGHTING);

    glPopMatrix();

}

// ------------------------------------------------------------
// ALFOMBRA - BELEN CHAVEZ (ahora con borde y franjas)
void alfombra(){
    box(-1.8f, 0.08f, -1.2f, 5.5f, 0.10f, 4.0f,
        0.75f, 0.30f, 0.20f);

    box(-1.8f, 0.14f, -1.2f, 4.8f, 0.06f, 3.3f,
        0.90f, 0.55f, 0.32f);

    // Franjas decorativas
    box(-1.8f, 0.175f, -1.2f, 4.2f, 0.02f, 0.18f,
        0.65f, 0.20f, 0.15f);
    box(-1.8f, 0.175f, -0.2f, 4.2f, 0.02f, 0.18f,
        0.65f, 0.20f, 0.15f);
    box(-1.8f, 0.175f, -2.2f, 4.2f, 0.02f, 0.18f,
        0.65f, 0.20f, 0.15f);
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

    // Aro 1
    glPushMatrix();
    glTranslatef(0.5f, 0.65f, -0.1f);
    setColor(0.05f, 0.05f, 0.05f);
    glutSolidTorus(0.04, 0.585, 10, 28);
    glPopMatrix();

    // Aro 2 (girado 90 grados)
    glPushMatrix();
    glTranslatef(0.5f, 0.65f, -0.1f);
    glRotatef(90.0f, 0, 1, 0);
    setColor(0.05f, 0.05f, 0.05f);
    glutSolidTorus(0.04, 0.585, 10, 28);
    glPopMatrix();

    // Aro 3 (horizontal)
    glPushMatrix();
    glTranslatef(0.5f, 0.65f, -0.1f);
    glRotatef(90.0f, 1, 0, 0);
    setColor(0.05f, 0.05f, 0.05f);
    glutSolidTorus(0.04, 0.585, 10, 28);
    glPopMatrix();

}

// ------------------------------------------------------------
// SKATEBOARD - JHON SIESQUEN (4 ruedas y puntas levantadas)
void skateboard(){
    // Tabla central
    box(1.0f, 0.55f, 2.2f, 2.4f, 0.12f, 0.55f,
        0.35f, 0.08f, 0.18f);

    // Puntas levantadas
    glPushMatrix();
        glTranslatef(-0.35f, 0.62f, 2.2f);
        glRotatef(20.0f, 0, 0, 1);
        box(0, 0, 0, 0.55f, 0.12f, 0.55f, 0.35f, 0.08f, 0.18f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.35f, 0.62f, 2.2f);
        glRotatef(-20.0f, 0, 0, 1);
        box(0, 0, 0, 0.55f, 0.12f, 0.55f, 0.35f, 0.08f, 0.18f);
    glPopMatrix();

    // Ejes
    box(0.20f, 0.42f, 2.2f, 0.10f, 0.10f, 0.80f, 0.5f, 0.5f, 0.5f);
    box(1.80f, 0.42f, 2.2f, 0.10f, 0.10f, 0.80f, 0.5f, 0.5f, 0.5f);

    // 4 ruedas (cilindros acostados sobre el eje Z)
    float ruedasX[2] = { 0.20f, 1.80f };
    float ruedasZ[2] = { 1.85f, 2.55f };
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            glPushMatrix();
                glTranslatef(ruedasX[i], 0.20f, ruedasZ[j] - 0.07f);
                setColor(0.95f, 0.90f, 0.30f);
                gluCylinder(quad, 0.20f, 0.20f, 0.14f, 16, 1);
                gluDisk(quad, 0, 0.20f, 16, 1);
                glTranslatef(0, 0, 0.14f);
                gluDisk(quad, 0, 0.20f, 16, 1);
            glPopMatrix();
        }
    }
}


// VENTILADOR DE PIE - JHON SIESQUEN
void ventilador(){
    float x = -6.5f, z = 1.5f;

    cylinder(x, 0.05f, z, 0.95f, 0.25f, 0.22f, 0.22f, 0.25f);
    cylinder(x, 0.30f, z, 0.16f, 3.10f, 0.72f, 0.72f, 0.75f);

    glPushMatrix();
    glTranslatef(x, 3.55f, z);
    glRotatef(giroCabeza, 0, 1, 0);

    setColor(0.30f, 0.32f, 0.38f);
    glutSolidCylinder(0.38, 0.55, 20, 1);

    glTranslatef(0, 0, 0.55f);

    glPushMatrix();
    glRotatef(anguloAspas, 0, 0, 1);
    setColor(0.85f, 0.87f, 0.92f);

    for(int i = 0; i < 4; i++){
        glPushMatrix();
        glRotatef(90.0f * i, 0, 0, 1);
        glTranslatef(0.55f, 0, 0);
        glScalef(1.1f, 0.45f, 0.06f);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    setColor(0.35f, 0.37f, 0.42f);
    glutSolidSphere(0.16, 14, 10);
    glPopMatrix();

    setColor(0.55f, 0.57f, 0.62f);
    glutSolidTorus(0.05, 1.20, 10, 24);

    glPopMatrix();
}

//ROBOT ASPIRADORA - JHON SIESQUEN
void robot(){
    float cx = 1.0f, cz = 5.5f, radio = 2.5f;

    float px = cx + radio * cos(robotT);
    float pz = cz + radio * sin(robotT);
    float giro = -robotT * 180.0f / 3.14159265f;

    glPushMatrix();
    glTranslatef(px, 0, pz);
    glRotatef(giro, 0, 1, 0);

    setColor(0.18f, 0.18f, 0.22f);
    cylinder(0, 0.05f, 0, 0.85f, 0.30f, 0.18f, 0.18f, 0.22f);

    setColor(0.55f, 0.12f, 0.15f);
    cylinder(0, 0.35f, 0, 0.78f, 0.12f, 0.55f, 0.12f, 0.15f);

    box(0, 0.50f, 0, 0.55f, 0.16f, 0.35f, 0.25f, 0.25f, 0.30f);

    box(0.80f, 0.20f, 0, 0.10f, 0.22f, 1.10f, 0.35f, 0.35f, 0.40f);

    if(robotOn)
        sphere(0.45f, 0.46f, 0.30f, 0.09f, 0.20f, 0.95f, 0.30f);
    else
        sphere(0.45f, 0.46f, 0.30f, 0.09f, 0.45f, 0.45f, 0.45f);

    glPopMatrix();
}

//EQUIPO DE MUSICA - JHON SIESQUEN
void equipoMusica(){
    float x = -4.6f, z = 6.0f;

    box(x, 1.05f, z, 2.6f, 2.10f, 1.60f, 0.16f, 0.16f, 0.20f);
    box(x, 2.15f, z, 2.70f, 0.14f, 1.70f, 0.28f, 0.28f, 0.34f);

    glPushMatrix();
    glTranslatef(x, 1.20f, z + 0.81f);

    setColor(0.10f, 0.10f, 0.12f);
    glutSolidCylinder(0.45, 0.06, 20, 1);

    glTranslatef(-0.80f, 0.55f, 0);
    setColor(0.10f, 0.10f, 0.12f);
    glutSolidCylinder(0.26, 0.06, 16, 1);

    glTranslatef(1.60f, 0, 0);
    glutSolidCylinder(0.26, 0.06, 16, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x, 2.24f, z);
    glRotatef(discoAng, 0, 1, 0);

    setColor(0.08f, 0.08f, 0.10f);
    cylinder(0, 0, 0, 0.62f, 0.06f, 0.08f, 0.08f, 0.10f);

    setColor(0.85f, 0.20f, 0.20f);
    cylinder(0, 0.06f, 0, 0.18f, 0.03f, 0.85f, 0.20f, 0.20f);

    box(0.40f, 0.09f, 0, 0.30f, 0.03f, 0.06f, 0.95f, 0.95f, 0.95f);
    glPopMatrix();

    if(musicaOn){
        for(int i = 0; i < 3; i++){
            float br = ((fase / 5 + i) % 3 == 0) ? 1.0f : 0.25f;
            sphere(x - 0.6f + i * 0.6f, 1.95f, z + 0.85f, 0.10f,
                   br, br * 0.45f, 0.10f);
        }
    }
    else{
        for(int i = 0; i < 3; i++)
            sphere(x - 0.6f + i * 0.6f, 1.95f, z + 0.85f, 0.10f,
                   0.30f, 0.30f, 0.32f);
    }
}

//ANIMACION DE OBJETOS - JHON SIESQUEN
void animar(int valor){
    if(ventiladorOn){
        anguloAspas += 20.0f;
        if(anguloAspas > 360.0f) anguloAspas -= 360.0f;

        faseCabeza += 0.02f;
        giroCabeza = 40.0f * sin(faseCabeza);
    }

    if(robotOn)
        robotT += 0.012f;

    if(musicaOn){
        discoAng += 6.0f;
        if(discoAng > 360.0f) discoAng -= 360.0f;
        fase++;
    }

    glutPostRedisplay();
    glutTimerFunc(30, animar, 0);
}


// ------------------------------------------------------------
// PLANTA - YESSICA BERNAOLA
void hoja3D(float x, float y, float z,
            float largo, float ancho, float grosor,
            float angulo,
            float r, float g, float b){

    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angulo, 0.0f, 1.0f, 0.0f);
    glColor3f(r, g, b);

    glPushMatrix();
        glScalef(largo, grosor, ancho);
        glutSolidSphere(1.0, 20, 16);
    glPopMatrix();

    glPopMatrix();
}

void planta(){
    // Maceta
    cylinder(7.8f, 0.35f, 3.0f, 0.55f, 0.8f,
             0.65f, 0.27f, 0.12f);

    // Borde
    cylinder(7.8f, 0.90f, 3.0f, 0.58f, 0.12f,
             0.78f, 0.36f, 0.18f);

    // Tierra
    cylinder(7.8f, 0.97f, 3.0f, 0.48f, 0.035f,
             0.20f, 0.10f, 0.04f);

    // Tallo
    cylinder(7.8f, 0.98f, 3.0f, 0.055f, 1.10f,
             0.25f, 0.14f, 0.06f);

    // Hojas inferiores
    hoja3D(7.35f, 1.40f, 2.85f, 0.48f, 0.24f, 0.09f, -30, 0.05f, 0.32f, 0.08f);
    hoja3D(8.20f, 1.42f, 2.90f, 0.48f, 0.24f, 0.09f,  30, 0.08f, 0.40f, 0.10f);
    hoja3D(7.80f, 1.45f, 3.42f, 0.46f, 0.23f, 0.09f,  90, 0.12f, 0.46f, 0.12f);
    hoja3D(7.80f, 1.40f, 2.58f, 0.46f, 0.23f, 0.09f,  90, 0.10f, 0.42f, 0.11f);

    // Hojas intermedias
    hoja3D(7.18f, 1.75f, 3.05f, 0.50f, 0.25f, 0.10f, -20, 0.04f, 0.38f, 0.09f);
    hoja3D(8.40f, 1.78f, 3.10f, 0.52f, 0.25f, 0.10f,  25, 0.08f, 0.45f, 0.12f);
    hoja3D(7.45f, 1.92f, 3.40f, 0.45f, 0.23f, 0.09f, -45, 0.12f, 0.50f, 0.14f);
    hoja3D(8.15f, 1.90f, 2.70f, 0.42f, 0.22f, 0.09f,  50, 0.10f, 0.48f, 0.13f);

    // Hojas superiores
    hoja3D(7.45f, 2.10f, 2.95f, 0.43f, 0.22f, 0.08f, -35, 0.08f, 0.48f, 0.12f);
    hoja3D(8.12f, 2.12f, 2.98f, 0.43f, 0.22f, 0.08f,  35, 0.15f, 0.55f, 0.16f);
    hoja3D(7.78f, 2.28f, 3.20f, 0.42f, 0.22f, 0.08f,  90, 0.18f, 0.58f, 0.18f);
    hoja3D(7.80f, 2.40f, 2.95f, 0.30f, 0.16f, 0.07f,   0, 0.20f, 0.62f, 0.20f);
}


// ------------------------------------------------------------
// CUADRO DECORATIVO - CARLOS ZAMORA
void cuadro(){
    box(1.0f, 6.0f, -8.65f, 2.0f, 1.5f, 0.12f,
        0.30f, 0.18f, 0.08f);

    box(1.0f, 6.0f, -8.52f, 1.65f, 1.15f, 0.08f,
        0.75f, 0.85f, 0.55f);
}

// ------------------------------------------------------------
// GATO - BELEN (con patas, cola hacia atrás y nariz)
void gato(){
    // Cuerpo
    setColor(1.0f, 0.70f, 0.35f);
    glPushMatrix();
    glScalef(1.0f, 0.8f, 1.5f);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Cabeza
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.8f);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    // Orejas
    setColor(0.80f, 0.55f, 0.15f);
    glPushMatrix();
    glTranslatef(-0.15f, 0.50f, 0.8f);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.08, 0.2, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15f, 0.50f, 0.8f);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.08, 0.2, 10, 10);
    glPopMatrix();

    // Patas (4 esferas aplastadas)
    setColor(1.0f, 0.62f, 0.28f);
    float patasX[2] = { -0.22f, 0.22f };
    float patasZ[2] = { 0.45f, -0.45f };
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            glPushMatrix();
            glTranslatef(patasX[i], -0.32f, patasZ[j]);
            glScalef(1.0f, 1.3f, 1.2f);
            glutSolidSphere(0.12, 12, 12);
            glPopMatrix();
        }
    }

    // Ojos verdes
    setColor(0.3f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(-0.10f, 0.38f, 1.07f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.10f, 0.38f, 1.07f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();

    // Nariz
    setColor(0.95f, 0.45f, 0.55f);
    glPushMatrix();
    glTranslatef(0.0f, 0.30f, 1.10f);
    glutSolidSphere(0.035f, 8, 8);
    glPopMatrix();

    // Cola (sube hacia atrás)
    setColor(0.95f, 0.50f, 0.10f);
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, -0.70f);
    glRotatef(-135, 1, 0, 0);
    gluCylinder(quad, 0.05, 0.03, 0.6, 12, 4);
    glPopMatrix();
}

// ------------------------------------------------------------
//LIBRO ENCIMA DE CAMA - MIGUEL ROA
void libro(float x, float y, float z, float rot, float w, float d, float r, float g, float b){
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rot, 0, 1, 0);
    box(0, 0.015f, 0, w, 0.03f, d, r, g, b);
    box(0, 0.155f, 0, w, 0.03f, d, r, g, b);
    box(-w / 2 + 0.03f, 0.085f, 0, 0.06f, 0.17f, d, r * 0.7f, g * 0.7f, b * 0.7f);
    box(0.02f, 0.085f, 0, w - 0.08f, 0.14f, d - 0.06f, 0.96f, 0.94f, 0.85f);
    glPopMatrix();
}

// ------------------------------------------------------------
//PELUCHE OSO - MIGUEL ROA
void peluche(float x, float z, float rot){
    float y0 = 1.57f; 
    glPushMatrix();
    glTranslatef(x, 0, z);
    glRotatef(rot, 0, 1, 0);
    sphere(0, y0 + 0.45f, 0, 0.45f, 0.72f, 0.46f, 0.25f);
    sphere(0, y0 + 0.42f, 0.28f, 0.28f, 0.90f, 0.75f, 0.55f);
    sphere(-0.28f, y0 + 0.22f, 0.35f, 0.22f, 0.60f, 0.36f, 0.18f);
    sphere( 0.28f, y0 + 0.22f, 0.35f, 0.22f, 0.60f, 0.36f, 0.18f);
    sphere(-0.50f, y0 + 0.58f, 0.12f, 0.16f, 0.60f, 0.36f, 0.18f);
    sphere( 0.50f, y0 + 0.58f, 0.12f, 0.16f, 0.60f, 0.36f, 0.18f);
    sphere(0, y0 + 1.12f, 0, 0.33f, 0.78f, 0.52f, 0.30f);
    sphere(-0.24f, y0 + 1.42f, 0, 0.12f, 0.60f, 0.36f, 0.18f);
    sphere( 0.24f, y0 + 1.42f, 0, 0.12f, 0.60f, 0.36f, 0.18f);
    sphere(0, y0 + 1.05f, 0.30f, 0.13f, 0.92f, 0.80f, 0.62f);
    sphere(0, y0 + 1.10f, 0.41f, 0.05f, 0.08f, 0.05f, 0.05f);
    sphere(-0.12f, y0 + 1.19f, 0.29f, 0.04f, 0.05f, 0.05f, 0.05f);
    sphere( 0.12f, y0 + 1.19f, 0.29f, 0.04f, 0.05f, 0.05f, 0.05f);
    box(-0.12f, y0 + 0.80f, 0.30f, 0.16f, 0.12f, 0.06f, 0.85f, 0.15f, 0.20f);
    box( 0.12f, y0 + 0.80f, 0.30f, 0.16f, 0.12f, 0.06f, 0.85f, 0.15f, 0.20f);
    sphere(0, y0 + 0.80f, 0.31f, 0.06f, 0.65f, 0.08f, 0.12f);
    glPopMatrix();
}

//MANTA - MIGUEL ROA
void manta(float x, float z, float rot){
    glPushMatrix();
    glTranslatef(x, 1.72f, z);     
    glRotatef(rot, 0, 1, 0);
    box(0.00f, 0.045f, 0, 2.00f, 0.09f, 1.20f, 0.88f, 0.40f, 0.38f);  
    box(0.03f, 0.135f, 0, 1.98f, 0.09f, 1.18f, 0.96f, 0.92f, 0.80f);  
    box(0.00f, 0.225f, 0, 2.00f, 0.09f, 1.20f, 0.93f, 0.72f, 0.25f);  
    for(int i = 0; i < 5; i++){
        if(i % 2 == 0)
            box(-0.8f + i * 0.4f, 0.275f, 0, 0.20f, 0.01f, 1.18f, 0.88f, 0.40f, 0.38f);   
        else
            box(-0.8f + i * 0.4f, 0.275f, 0, 0.20f, 0.01f, 1.18f, 0.96f, 0.92f, 0.80f);   
    }
    glPopMatrix();
}

//CELULAR - MIGUEL ROA
void celular(float x, float z, float rot){
    float y0 = 1.57f; 
    glPushMatrix();
    glTranslatef(x, y0, z);
    glRotatef(rot, 0, 1, 0);
    box(0, 0.02f, 0, 0.46f, 0.04f, 0.86f, 0.12f, 0.12f, 0.15f);
    box(0, 0.045f, 0, 0.40f, 0.01f, 0.78f, 0.25f, 0.55f, 0.85f);
    box(0, 0.052f, -0.35f, 0.14f, 0.01f, 0.02f, 0.05f, 0.05f, 0.07f);
    box(0, 0.052f, -0.18f, 0.22f, 0.01f, 0.07f, 0.95f, 0.97f, 1.00f);
    box(0, 0.052f, 0.02f, 0.30f, 0.01f, 0.05f, 0.75f, 0.88f, 0.98f);
    box(0, 0.052f, 0.12f, 0.30f, 0.01f, 0.05f, 0.75f, 0.88f, 0.98f);
    for(int i = 0; i < 3; i++){
        box(-0.12f + i * 0.12f, 0.052f, 0.28f, 0.08f, 0.01f, 0.08f, 0.95f - i * 0.30f, 0.45f + i * 0.20f, 0.30f + i * 0.25f);
    }
    box(0, 0.052f, 0.36f, 0.12f, 0.01f, 0.015f, 1.00f, 1.00f, 1.00f);
    glPopMatrix();
}

//Decoracion Cama - MIGUEL ROA
void decoracionCama(){
    peluche(7.4f, -4.9f, 25.0f);
    libro(3.1f, 1.57f, -4.0f,  0.0f, 1.10f, 0.80f, 0.15f, 0.30f, 0.65f);
    libro(3.1f, 1.74f, -4.0f, 15.0f, 0.95f, 0.70f, 0.75f, 0.20f, 0.20f);
    manta(3.8f, -0.3f, 15.0f); 
    celular(7.0f, -2.8f, -20.0f);
}

//lIBROS DEL PISO - MIGUEL ROA
void librosPiso(){
    float yPiso = 0.02f;   
    libro(5.2f, yPiso,         3.2f,  20.0f, 1.30f, 0.95f, 0.20f, 0.50f, 0.30f);
    libro(5.2f, yPiso + 0.17f, 3.2f, -15.0f, 1.00f, 0.75f, 0.85f, 0.65f, 0.20f);
    libro(6.3f, yPiso, 4.8f, -40.0f, 1.20f, 0.90f, 0.70f, 0.20f, 0.25f);
}

//LENTES - MIGUEL ROA
void lentes(){
    float yMesa = 2.67f;   
    glPushMatrix();
    glTranslatef(0.65f, yMesa + 0.135f, -5.95f);
    glRotatef(25, 0, 1, 0);      
    glRotatef(-22.5f, 1, 0, 0);  
    glScalef(0.6f, 0.6f, 0.6f);  
    for(int s = -1; s <= 1; s += 2){
        float cx = s * 0.28f;   
        box(cx,          0.20f, 0, 0.45f, 0.05f, 0.06f, 0.08f, 0.08f, 0.10f);  
        box(cx,         -0.20f, 0, 0.45f, 0.05f, 0.06f, 0.08f, 0.08f, 0.10f);  
        box(cx - 0.20f, 0,      0, 0.05f, 0.35f, 0.06f, 0.08f, 0.08f, 0.10f);  
        box(cx + 0.20f, 0,      0, 0.05f, 0.35f, 0.06f, 0.08f, 0.08f, 0.10f);  
        box(cx, 0, 0, 0.36f, 0.36f, 0.02f, 0.70f, 0.88f, 0.98f);                       
        sphere(s * 0.52f, 0.12f, -0.01f, 0.04f, 0.90f, 0.72f, 0.20f);                  
        box(s * 0.52f, 0.12f, -0.38f, 0.03f, 0.03f, 0.76f, 0.08f, 0.08f, 0.10f);       
        box(s * 0.52f, 0.12f, -0.70f, 0.04f, 0.04f, 0.16f, 0.55f, 0.20f, 0.12f);       
        sphere(s * 0.11f, -0.10f, 0.04f, 0.03f, 0.85f, 0.85f, 0.88f);                  
    }
    box(0, 0.12f, 0, 0.16f, 0.04f, 0.05f, 0.08f, 0.08f, 0.10f);                        
    glPopMatrix();
}


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

//GUITARRA - MIGUEL ROA
void guitarra(float x, float z, float yaw){
    glPushMatrix();
    glTranslatef(x, 0.06f, z);
    glRotatef(yaw, 0, 1, 0);       
    glRotatef(-10, 1, 0, 0);       
    glScalef(0.8f, 0.8f, 0.8f);
    cilindroZ(0, 0.95f, 0, 0.95f, 0.50f, 0.40f, 0.12f, 0.06f); 
    cilindroZ(0, 2.00f, 0, 0.70f, 0.50f, 0.40f, 0.12f, 0.06f);  
    cilindroZ(0, 0.95f, 0.26f, 0.89f, 0.02f, 0.93f, 0.62f, 0.22f);
    cilindroZ(0, 2.00f, 0.26f, 0.64f, 0.02f, 0.93f, 0.62f, 0.22f);
    cilindroZ(0, 1.95f, 0.275f, 0.28f, 0.01f, 0.05f, 0.03f, 0.02f);
    glPushMatrix();
    glTranslatef(0, 1.95f, 0.28f);
    setColor(0.30f, 0.14f, 0.05f);
    glutSolidTorus(0.025, 0.31, 8, 32);
    glPopMatrix();
    box(0, 0.55f, 0.30f, 0.70f, 0.14f, 0.06f, 0.15f, 0.08f, 0.04f);
    box(0, 3.15f, 0.0f, 0.26f, 1.70f, 0.18f, 0.55f, 0.30f, 0.12f);
    box(0, 3.22f, 0.11f, 0.24f, 1.45f, 0.04f, 0.10f, 0.06f, 0.04f);
    float trastes[5] = {2.95f, 3.20f, 3.42f, 3.62f, 3.80f};
    for(int i = 0; i < 5; i++){
        box(0, trastes[i], 0.135f, 0.25f, 0.015f, 0.015f, 0.80f, 0.80f, 0.75f);
    }
    box(0, 3.96f, 0.13f, 0.26f, 0.04f, 0.05f, 0.92f, 0.90f, 0.82f);
    box(0, 4.20f, 0.0f, 0.36f, 0.50f, 0.12f, 0.20f, 0.10f, 0.05f);
    box(0, 4.25f, 0.065f, 0.14f, 0.14f, 0.01f, 0.90f, 0.80f, 0.50f);
    for(int i = 0; i < 3; i++){
        sphere(-0.23f, 4.07f + i * 0.13f, 0, 0.045f, 0.85f, 0.78f, 0.40f);
        sphere( 0.23f, 4.07f + i * 0.13f, 0, 0.045f, 0.85f, 0.78f, 0.40f);
    }
    glLineWidth(1.5f);
    setColor(0.92f, 0.92f, 0.88f);
    glBegin(GL_LINES);
    for(int i = 0; i < 4; i++){
        float xb = -0.09f + i * 0.06f;   
        float xn = -0.06f + i * 0.04f;   
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

//MOCHILA - MIGUEL ROA
void mochila(float x, float z, float yaw){
    glPushMatrix();
    glTranslatef(x, 0.05f, z);
    glRotatef(yaw, 0, 1, 0);      
    glRotatef(-5, 1, 0, 0);   
    box(0, 0.675f, 0, 1.30f, 1.35f, 0.75f, 0.45f, 0.28f, 0.65f);
    cilindroZ(0, 1.30f, 0, 0.65f, 0.75f, 0.45f, 0.28f, 0.65f);
    box(0, 0.11f, 0, 1.32f, 0.22f, 0.77f, 0.25f, 0.15f, 0.40f);
    box(0, 0.55f, 0.485f, 1.00f, 0.80f, 0.22f, 0.58f, 0.40f, 0.80f);
    box(0, 0.92f, 0.60f, 0.90f, 0.04f, 0.02f, 0.95f, 0.80f, 0.25f);
    sphere(0.38f, 0.90f, 0.61f, 0.05f, 0.95f, 0.80f, 0.25f);
    box(0, 1.45f, 0.385f, 1.00f, 0.03f, 0.02f, 0.95f, 0.80f, 0.25f);
    sphere(0.45f, 1.45f, 0.395f, 0.05f, 0.95f, 0.80f, 0.25f);
    glPushMatrix();
    glTranslatef(0, 1.95f, 0);
    setColor(0.25f, 0.15f, 0.40f);
    glutSolidTorus(0.035, 0.18, 8, 16);
    glPopMatrix();
    box(0.69f, 0.32f, 0.05f, 0.10f, 0.55f, 0.50f, 0.58f, 0.40f, 0.80f);
    cylinder(0.80f, 0.10f, 0.05f, 0.16f, 0.70f, 0.30f, 0.75f, 0.90f);
    cylinder(0.80f, 0.80f, 0.05f, 0.10f, 0.12f, 0.10f, 0.10f, 0.12f);
    glPopMatrix();
}

// ------------------------------------------------------------
// NUEVOS OBJETOS AÑADIDOS
// ------------------------------------------------------------

//CARLOS (VENTILADOR DE TECHO: Gira sobre su eje vertical constantemente usando rotVentilador para dar movimiento fluido a la habitación)
void ventiladorTecho() {
    glPushMatrix();
    glTranslatef(0.0f, 8.5f, -2.0f); 

    cylinder(0.0f, 0.0f, 0.0f, 0.3f, 0.2f, 0.35f, 0.35f, 0.35f);
    cylinder(0.0f, -0.8f, 0.0f, 0.05f, 0.8f, 0.20f, 0.20f, 0.20f);
    sphere(0.0f, -0.8f, 0.0f, 0.2f, 0.85f, 0.85f, 0.85f);

    glPushMatrix();
    glTranslatef(0.0f, -0.8f, 0.0f);
    glRotatef(rotVentilador, 0.0f, 1.0f, 0.0f); 

    for(int i = 0; i < 4; i++) {
        glPushMatrix();
        glRotatef(i * 90.0f, 0.0f, 1.0f, 0.0f);
        box(1.2f, 0.0f, 0.0f, 1.8f, 0.05f, 0.3f, 0.38f, 0.22f, 0.10f); 
        glPopMatrix();
    }
    glPopMatrix();
    glPopMatrix();
}

//CARLOS (PC TORRE: Gabinete bajo el escritorio con luz LED frontal que parpadea rítmicamente utilizando luzPC)
void pcTorre() {
    glPushMatrix();
    glTranslatef(-4.9f, 0.9f, -6.5f); 
    
    // Cuerpo metálico 
    box(0.0f, 0.0f, 0.0f, 1.2f, 1.8f, 2.4f, 0.1f, 0.1f, 0.1f);
    
    // Panel de vidrio lateral
    box(0.62f, 0.0f, 0.0f, 0.05f, 1.5f, 2.0f, 0.2f, 0.3f, 0.4f);
    
    // Barra LED oscilante (respiración)
    float rgbIntensity = 0.2f + (luzPC * 0.8f);
    box(0.0f, 0.0f, 1.22f, 0.8f, 1.4f, 0.05f, 0.0f, rgbIntensity, rgbIntensity * 0.8f);
    
    glPopMatrix();
}

//CARLOS (PUFF: Asiento cilíndrico bajo ubicado en la esquina derecha libre, aportando comodidad sin obstruir los libros del piso)
void puff() {
    glPushMatrix();
    glTranslatef(7.5f, 0.4f, 6.5f); 
    
    // Base 
    cylinder(0.0f, -0.4f, 0.0f, 1.0f, 0.8f, 0.65f, 0.25f, 0.25f);
    
    // Cojín esférico escalado
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glScalef(1.0f, 0.3f, 1.0f);
    setColor(0.9f, 0.8f, 0.2f);
    glutSolidSphere(1.0f, 24, 16);
    glPopMatrix();
    
    glPopMatrix();
}

//CARLOS (PLANTA COLGANTE: Maceta fijada en la pared izquierda sobre la cómoda, aprovechando el espacio vertical vacío con esferas decorativas)
void plantaColgante() {
    glPushMatrix();
    glTranslatef(-9.5f, 6.5f, 5.2f);
    
    // Maceta
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    setColor(0.7f, 0.4f, 0.2f);
    glutSolidCone(0.5f, 0.6f, 16, 16);
    glPopMatrix();
    
    // Hojas colgantes formadas por esferas asimétricas
    sphere( 0.0f,  0.1f,  0.0f, 0.45f, 0.2f, 0.6f, 0.2f); 
    sphere( 0.3f, -0.3f,  0.2f, 0.30f, 0.15f, 0.55f, 0.15f);
    sphere(-0.2f, -0.5f,  0.3f, 0.25f, 0.18f, 0.50f, 0.18f);
    sphere( 0.1f, -0.7f, -0.1f, 0.20f, 0.22f, 0.65f, 0.22f);
    glPopMatrix();
}

// ------------------------------------------------------------
// ESCENA COMPLETA
// ------------------------------------------------------------
void room(){
	glCallList(listaPiso);  // piso precompilado
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
    
    // Llamado a los 4 nuevos objetos
    ventiladorTecho();
    pcTorre();
    puff();
    plantaColgante();
    
    // Jhon - Ventilador de pie
    ventilador();
    // Jhon - Robot aspiradora
    robot();
    // Jhon - Equipo de musica
    equipoMusica();
    // Yessica - Lo translúcido siempre al final
    hazLampara();

}

//CARLOS (TIMER DE ANIMACIÓN: Actualiza las variables a ~60FPS antes de cada cuadro, necesario para la PC y el Ventilador)
void timer(int value) {
    rotVentilador += 1.8f;
    if(rotVentilador > 360.0f) rotVentilador -= 360.0f;
    
    if(luzAumenta) {
        luzPC += 0.02f;
        if(luzPC >= 1.0f) luzAumenta = false;
    } else {
        luzPC -= 0.02f;
        if(luzPC <= 0.0f) luzAumenta = true;
    }
    
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);

}

// ------------------------------------------------------------
// TEXTO EN PANTALLA (controles) - YESSICA
// ------------------------------------------------------------
void texto(float x, float y, const char* s){
    glRasterPos2f(x, y);
    for(; *s; s++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s);
}

void hud(){
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, winW, 0, winH);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(0.10f, 0.15f, 0.05f);
	texto(12, winH - 20, "Flechas: girar/subir camara     W/S: zoom     A/D: mover vista");
	texto(12, winH - 38, "Rueda: zoom     Clic izq: girar gato     Clic der: girar camara");
	texto(12, winH - 56, "Espacio: girar silla     V: ventilador     B: robot");
	texto(12, winH - 74, "M: musica ON/OFF     R: restaurar     ESC: salir");

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
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

    // Luces (después de gluLookAt: quedan fijas en el cuarto) - Yessica
    GLfloat posLuz0[] = { -5.0f, 15.0f, 10.0f, 1.0f };   // luz general
    glLightfv(GL_LIGHT0, GL_POSITION, posLuz0);

    GLfloat posLuz1[] = { 0.15f, 4.05f, -6.65f, 1.0f };  // foco de la lámpara
    glLightfv(GL_LIGHT1, GL_POSITION, posLuz1);

    room();
    hud();

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
    
        if(key == 'v' || key == 'V')
        ventiladorOn = !ventiladorOn;

    if(key == 'b' || key == 'B')
        robotOn = !robotOn;

    if(key == 'm' || key == 'M'){
        musicaOn = !musicaOn;

        if(musicaOn)
            PlaySound("musica.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        else
            PlaySound(NULL, NULL, 0);
    }

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
    if(state == GLUT_DOWN){
        botonMouse = button;
        mouseX = x;
        mouseY = y;
    }

    if(state == GLUT_UP){
        botonMouse = -1;
    }
}

//ROTACIÓN DEL GATO CON EL MOVIMIENTO DEL MOUSE
void onMotion(int x, int y)
{
    int dx = x - mouseX;
    int dy = y - mouseY;

    if(botonMouse == GLUT_LEFT_BUTTON){
        rotGato += dx;                       // gira el gato
    }
    else if(botonMouse == GLUT_RIGHT_BUTTON){
        angleY += dx * 0.4f;                 // gira la cámara
        camY += dy * 0.05f;
        if(camY < 5.0f)  camY = 5.0f;
        if(camY > 25.0f) camY = 25.0f;
    }

    mouseX = x;
    mouseY = y;
    glutPostRedisplay();

}


// Rueda del mouse = zoom
void onWheel(int, int dir, int, int){
    if(dir > 0) zoom -= 0.05f;
    else        zoom += 0.05f;

    if(zoom < 0.55f) zoom = 0.55f;
    if(zoom > 1.8f)  zoom = 1.8f;

    glutPostRedisplay();
}

// ------------------------------------------------------------
// INICIALIZACIÓN - YESSICA
// ------------------------------------------------------------
void init(){
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.74f, 0.84f, 0.58f, 1.0f);

    // Quadric único
    quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);

    // Iluminación
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_NORMALIZE);

    GLfloat ambienteGlobal[] = { 0.40f, 0.40f, 0.40f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambienteGlobal);

    // Luz 0: general (blanca)
    GLfloat difusa0[]  = { 0.75f, 0.75f, 0.70f, 1.0f };
    GLfloat ambiente0[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente0);

    // Luz 1: foco de la lámpara (cálida, con atenuación)
    GLfloat difusa1[] = { 0.90f, 0.70f, 0.35f, 1.0f };
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, difusa1);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.10f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.02f);

    // Piso en display list (se dibuja una sola vez y se reutiliza)
    listaPiso = glGenLists(1);
    glNewList(listaPiso, GL_COMPILE);
        piso();
    glEndList();
}

//MAIN
int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(winW, winH);
    glutInitWindowPosition(80, 40);
    glutCreateWindow("MODELO CUARTO 3D");

    init();


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
    
    //Funcion del Zoom
    glutMouseWheelFunc(onWheel);
    
    // Inicia el bucle de animación
    glutTimerFunc(16, timer, 0);
    glutTimerFunc(30, animar, 0);
    
    glutMainLoop();

    return 0;
}

