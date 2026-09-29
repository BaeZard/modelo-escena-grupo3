#include <math.h>
#include <stdlib.h>
#include <GL/freeglut.h>

// ============================================================
// PLAYA 3D - OPENGL + FREEGLUT
// Compatible con Dev-C++
// ============================================================

// ------------------------------------------------------------
// VARIABLES DE CAMARA
// ------------------------------------------------------------

float posX = -32.0f;
float posY = -18.0f;
float posZ = -55.0f;

int eye_camX = 15;
int eye_camY = 0;
int eye_camZ = 0;

float aspect = 1.0f;

// ------------------------------------------------------------
// LUZ
// ------------------------------------------------------------

GLfloat Diffuse[]  = {1.0f, 0.95f, 0.75f, 1.0f};
GLfloat Specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat Position[] = {20.0f, 40.0f, 30.0f, 1.0f};

// ============================================================
// FUNCIONES AUXILIARES
// ============================================================

void esfera(float radio)
{
    GLUquadric *obj = gluNewQuadric();
    gluSphere(obj, radio, 30, 30);
    gluDeleteQuadric(obj);
}

void cilindro(float radio, float altura)
{
    GLUquadric *obj = gluNewQuadric();

    gluCylinder(obj, radio, radio, altura, 25, 10);

    gluDisk(obj, 0.0, radio, 25, 1);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, altura);
    gluDisk(obj, 0.0, radio, 25, 1);
    glPopMatrix();

    gluDeleteQuadric(obj);
}

void caja(float sx, float sy, float sz)
{
    glPushMatrix();

    glScalef(sx, sy, sz);
    glutSolidCube(1.0);

    glPopMatrix();
}

// ============================================================
// INICIALIZACION
// ============================================================

void InitGL()
{
    glClearColor(0.52f, 0.80f, 0.95f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
    glLightfv(GL_LIGHT0, GL_POSITION, Position);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// ============================================================
// CIELO
// ============================================================

void Cielo()
{
    // Fondo azul mediante un plano grande

    glDisable(GL_LIGHTING);

    glColor3f(0.45f, 0.78f, 0.95f);

    glBegin(GL_QUADS);

        glVertex3f(-150.0f, -5.0f, 50.0f);
        glVertex3f(150.0f, -5.0f, 50.0f);
        glVertex3f(150.0f, 100.0f, 50.0f);
        glVertex3f(-150.0f, 100.0f, 50.0f);

    glEnd();

    glEnable(GL_LIGHTING);
}

// ============================================================
// ARENA
// ============================================================

void Arena()
{
    glColor3f(0.86f, 0.68f, 0.38f);

    glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, 1.0f);

        glVertex3f(-70.0f, -35.0f, 0.0f);
        glVertex3f(70.0f, -35.0f, 0.0f);
        glVertex3f(70.0f, 30.0f, 0.0f);
        glVertex3f(-70.0f, 30.0f, 0.0f);

    glEnd();
}

// ============================================================
// MAR
// ============================================================

void Mar()
{
    glColor3f(0.05f, 0.48f, 0.72f);

    glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, 1.0f);

        glVertex3f(-70.0f, 30.0f, -0.05f);
        glVertex3f(70.0f, 30.0f, -0.05f);
        glVertex3f(70.0f, 75.0f, -0.05f);
        glVertex3f(-70.0f, 75.0f, -0.05f);

    glEnd();
}

// ============================================================
// OLAS
// ============================================================

void Olas()
{
    glDisable(GL_LIGHTING);

    glColor3f(0.90f, 0.97f, 1.0f);

    glLineWidth(3.0f);

    for(float y = 31.0f; y <= 70.0f; y += 7.0f)
    {
        glBegin(GL_LINE_STRIP);

        for(float x = -70.0f; x <= 70.0f; x += 2.0f)
        {
            float z = 0.10f + sin(x * 0.25f) * 0.18f;

            glVertex3f(x, y + sin(x * 0.15f) * 0.5f, z);
        }

        glEnd();
    }

    glEnable(GL_LIGHTING);
}

// ============================================================
// ESPUMA EN LA ORILLA
// ============================================================

void Espuma()
{
    glDisable(GL_LIGHTING);

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(4.0f);

    glBegin(GL_LINE_STRIP);

    for(float x = -70.0f; x <= 70.0f; x += 1.5f)
    {
        float y = 29.5f + sin(x * 0.18f) * 0.8f;

        glVertex3f(x, y, 0.15f);
    }

    glEnd();

    glEnable(GL_LIGHTING);
}

// ============================================================
// SOL
// ============================================================

void Sol()
{
    glDisable(GL_LIGHTING);

    glColor3f(1.0f, 0.78f, 0.05f);

    glPushMatrix();

        glTranslatef(40.0f, 45.0f, 25.0f);

        esfera(6.0f);

    glPopMatrix();

    // Rayos

    glColor3f(1.0f, 0.88f, 0.15f);

    glLineWidth(3.0f);

    glBegin(GL_LINES);

        glVertex3f(40, 45, 25);
        glVertex3f(40, 45, 35);

        glVertex3f(40, 45, 25);
        glVertex3f(40, 45, 15);

        glVertex3f(40, 45, 25);
        glVertex3f(50, 45, 25);

        glVertex3f(40, 45, 25);
        glVertex3f(30, 45, 25);

        glVertex3f(40, 45, 25);
        glVertex3f(47, 52, 25);

        glVertex3f(40, 45, 25);
        glVertex3f(33, 52, 25);

        glVertex3f(40, 45, 25);
        glVertex3f(47, 38, 25);

        glVertex3f(40, 45, 25);
        glVertex3f(33, 38, 25);

    glEnd();

    glEnable(GL_LIGHTING);
}

// ============================================================
// NUBE
// ============================================================

void Nube(float x, float y, float z, float escala)
{
    glColor3f(0.96f, 0.98f, 1.0f);

    glPushMatrix();

        glTranslatef(x, y, z);
        glScalef(escala, escala, escala);

        glPushMatrix();
        glTranslatef(-3.0f, 0.0f, 0.0f);
        esfera(2.5f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, 1.0f, 0.0f);
        esfera(3.5f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3.5f, 0.0f, 0.0f);
        esfera(2.5f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(6.0f, -0.5f, 0.0f);
        esfera(2.0f);
        glPopMatrix();

    glPopMatrix();
}

// ============================================================
// PALMERA
// ============================================================

void Palmera(float x, float y, float z, float escala)
{
    glPushMatrix();

        glTranslatef(x, y, z);

        glScalef(escala, escala, escala);

        // TRONCO

        glColor3f(0.48f, 0.27f, 0.10f);

        glPushMatrix();

            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

            cilindro(0.65f, 8.0f);

        glPopMatrix();

        // HOJAS

        glTranslatef(0.0f, 0.0f, 8.0f);

        glColor3f(0.08f, 0.45f, 0.10f);

        for(int i = 0; i < 8; i++)
        {
            glPushMatrix();

                glRotatef(i * 45.0f, 0.0f, 0.0f, 1.0f);

                glRotatef(-25.0f, 0.0f, 1.0f, 0.0f);

                glBegin(GL_TRIANGLES);

                    glVertex3f(0.0f, 0.0f, 0.0f);
                    glVertex3f(7.0f, 1.2f, 0.0f);
                    glVertex3f(7.0f, -1.2f, 0.0f);

                glEnd();

            glPopMatrix();
        }

    glPopMatrix();
}

// ============================================================
// SOMBRILLA
// ============================================================

void Sombrilla(float x, float y, float z, float escala)
{
    glPushMatrix();

        glTranslatef(x, y, z);

        glScalef(escala, escala, escala);

        // POSTE

        glColor3f(0.65f, 0.42f, 0.20f);

        glPushMatrix();

            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

            cilindro(0.15f, 4.0f);

        glPopMatrix();

        // PARTE SUPERIOR

        glColor3f(0.90f, 0.08f, 0.08f);

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 4.0f);

            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

            glutSolidCone(3.5f, 1.5f, 30, 10);

        glPopMatrix();

    glPopMatrix();
}

// ============================================================
// SILLA DE PLAYA
// ============================================================

void SillaPlaya(float x, float y, float z)
{
    glPushMatrix();

        glTranslatef(x, y, z);

        glColor3f(0.85f, 0.15f, 0.12f);

        // ASIENTO

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 1.0f);

            glScalef(3.0f, 2.0f, 0.25f);

            glutSolidCube(1.0);

        glPopMatrix();

        // RESPALDO

        glPushMatrix();

            glTranslatef(0.0f, 1.0f, 2.4f);

            glRotatef(-20.0f, 1.0f, 0.0f, 0.0f);

            glScalef(3.0f, 0.3f, 3.0f);

            glutSolidCube(1.0);

        glPopMatrix();

        // PATAS

        glColor3f(0.30f, 0.30f, 0.30f);

        for(int i = -1; i <= 1; i += 2)
        {
            glPushMatrix();

                glTranslatef(i * 1.1f, -0.6f, 0.5f);

                glRotatef(-75.0f, 1.0f, 0.0f, 0.0f);

                cilindro(0.12f, 1.5f);

            glPopMatrix();
        }

    glPopMatrix();
}

// ============================================================
// TABLA DE SURF
// ============================================================

void TablaSurf(float x, float y, float z)
{
    glPushMatrix();

        glTranslatef(x, y, z);

        glRotatef(15.0f, 0.0f, 0.0f, 1.0f);

        glColor3f(0.95f, 0.15f, 0.05f);

        glBegin(GL_TRIANGLE_FAN);

            glVertex3f(0.0f, 0.0f, 0.5f);

            glVertex3f(-5.0f, 0.0f, 0.5f);
            glVertex3f(-3.5f, 0.8f, 0.5f);
            glVertex3f(0.0f, 1.0f, 0.5f);
            glVertex3f(3.5f, 0.8f, 0.5f);
            glVertex3f(5.0f, 0.0f, 0.5f);
            glVertex3f(3.5f, -0.8f, 0.5f);
            glVertex3f(0.0f, -1.0f, 0.5f);
            glVertex3f(-3.5f, -0.8f, 0.5f);
            glVertex3f(-5.0f, 0.0f, 0.5f);

        glEnd();

        // FRANJA

        glColor3f(1.0f, 0.85f, 0.1f);

        glLineWidth(3.0f);

        glBegin(GL_LINES);

            glVertex3f(-3.5f, 0.0f, 0.52f);
            glVertex3f(3.5f, 0.0f, 0.52f);

        glEnd();

    glPopMatrix();
}

// ============================================================
// SALVAVIDAS
// ============================================================

void Salvavidas(float x, float y, float z)
{
    glPushMatrix();

        glTranslatef(x, y, z);

        glColor3f(0.95f, 0.08f, 0.04f);

        glutSolidTorus(0.45, 1.3, 20, 30);

        glColor3f(1.0f, 1.0f, 1.0f);

        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

        glBegin(GL_LINES);

            glVertex3f(-1.2f, 0.0f, 0.0f);
            glVertex3f(1.2f, 0.0f, 0.0f);

        glEnd();

    glPopMatrix();
}

// ============================================================
// CASETA DE PLAYA
// ============================================================

void Caseta()
{
    glPushMatrix();

        glTranslatef(-42.0f, 18.0f, 0.0f);

        // PISO

        glColor3f(0.35f, 0.22f, 0.10f);

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 0.3f);

            caja(10.0f, 7.0f, 0.6f);

        glPopMatrix();

        // PAREDES

        glColor3f(0.80f, 0.55f, 0.25f);

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 3.0f);

            caja(9.5f, 6.5f, 5.5f);

        glPopMatrix();

        // PUERTA

        glColor3f(0.30f, 0.15f, 0.07f);

        glPushMatrix();

            glTranslatef(0.0f, -3.3f, 2.5f);

            caja(2.2f, 0.25f, 4.0f);

        glPopMatrix();

        // TECHO

        glColor3f(0.75f, 0.08f, 0.05f);

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 6.3f);

            glRotatef(180.0f, 1.0f, 0.0f, 0.0f);

            glutSolidCone(8.0f, 3.0f, 4, 1);

        glPopMatrix();

        // LETRERO

        glColor3f(1.0f, 0.85f, 0.15f);

        glPushMatrix();

            glTranslatef(0.0f, -3.55f, 5.2f);

            caja(5.5f, 0.15f, 0.8f);

        glPopMatrix();

    glPopMatrix();
}

// ============================================================
// BOTE
// ============================================================

void Bote()
{
    glPushMatrix();

        glTranslatef(25.0f, 50.0f, 1.0f);
        glRotatef(-8.0f, 0.0f, 0.0f, 1.0f);

        // CUERPO

        glColor3f(0.75f, 0.15f, 0.08f);

        glBegin(GL_QUADS);

            glVertex3f(-6.0f, -2.0f, 0.0f);
            glVertex3f(6.0f, -2.0f, 0.0f);
            glVertex3f(4.5f, 2.0f, 0.0f);
            glVertex3f(-4.5f, 2.0f, 0.0f);

        glEnd();

        // BORDE

        glColor3f(0.95f, 0.85f, 0.20f);

        glLineWidth(4.0f);

        glBegin(GL_LINE_LOOP);

            glVertex3f(-6.0f, -2.0f, 0.2f);
            glVertex3f(6.0f, -2.0f, 0.2f);
            glVertex3f(4.5f, 2.0f, 0.2f);
            glVertex3f(-4.5f, 2.0f, 0.2f);

        glEnd();

        // MASTIL

        glColor3f(0.35f, 0.20f, 0.10f);

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, 0.2f);

            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

            cilindro(0.12f, 5.0f);

        glPopMatrix();

        // VELA

        glColor3f(1.0f, 1.0f, 0.90f);

        glBegin(GL_TRIANGLES);

            glVertex3f(0.0f, 0.0f, 5.0f);
            glVertex3f(0.0f, 0.0f, 0.7f);
            glVertex3f(4.0f, 0.0f, 0.7f);

        glEnd();

    glPopMatrix();
}

// ============================================================
// ROCAS
// ============================================================

void Roca(float x, float y, float z, float escala)
{
    glPushMatrix();

        glTranslatef(x, y, z);

        glScalef(escala, escala, escala);

        glColor3f(0.35f, 0.35f, 0.30f);

        esfera(2.0f);

    glPopMatrix();
}

// ============================================================
// CONCHAS
// ============================================================

void Conchas()
{
    glColor3f(0.95f, 0.75f, 0.55f);

    for(int i = 0; i < 12; i++)
    {
        float x = -35.0f + (i % 6) * 10.0f;
        float y = -25.0f + (i / 6) * 5.0f;

        glPushMatrix();

            glTranslatef(x, y, 0.3f);

            glutSolidSphere(0.35f, 12, 12);

        glPopMatrix();
    }
}

// ============================================================
// SOMBRILLAS Y SILLAS
// ============================================================

void ZonaPlaya()
{
    Sombrilla(-15.0f, -5.0f, 0.0f, 1.0f);
    SillaPlaya(-18.0f, -9.0f, 0.0f);
    SillaPlaya(-12.0f, -9.0f, 0.0f);

    Sombrilla(5.0f, 5.0f, 0.0f, 1.1f);
    SillaPlaya(1.0f, 0.0f, 0.0f);
    SillaPlaya(8.0f, 0.0f, 0.0f);

    Sombrilla(32.0f, -10.0f, 0.0f, 0.9f);
    SillaPlaya(28.0f, -14.0f, 0.0f);
    SillaPlaya(35.0f, -14.0f, 0.0f);
}

// ============================================================
// PALMERAS
// ============================================================

void ZonaPalmeras()
{
    Palmera(-55.0f, -8.0f, 0.0f, 1.4f);

    Palmera(-32.0f, 10.0f, 0.0f, 1.1f);

    Palmera(50.0f, -5.0f, 0.0f, 1.5f);

    Palmera(60.0f, 15.0f, 0.0f, 1.2f);

    Palmera(-55.0f, 20.0f, 0.0f, 1.0f);
}

// ============================================================
// DECORACION
// ============================================================

void Decoracion()
{
    TablaSurf(-25.0f, -20.0f, 0.0f);

    Salvavidas(15.0f, -20.0f, 1.5f);

    Roca(-60.0f, 25.0f, 1.5f, 1.2f);
    Roca(55.0f, 27.0f, 1.2f, 0.9f);
    Roca(62.0f, 23.0f, 1.0f, 0.7f);

    Conchas();
}

// ============================================================
// NUBES
// ============================================================

void Nubes()
{
    Nube(-35.0f, 45.0f, 35.0f, 1.5f);

    Nube(0.0f, 55.0f, 40.0f, 1.2f);

    Nube(45.0f, 60.0f, 35.0f, 1.4f);

    Nube(-55.0f, 65.0f, 30.0f, 1.0f);
}

// ============================================================
// DISPLAY
// ============================================================

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    // CAMARA

    glTranslatef(posX, posY, posZ);

    glRotatef(eye_camX, 1.0f, 0.0f, 0.0f);
    glRotatef(eye_camY, 0.0f, 1.0f, 0.0f);
    glRotatef(eye_camZ, 0.0f, 0.0f, 1.0f);

    // --------------------------------------------------------
    // ESCENA
    // --------------------------------------------------------

    glPushMatrix();

        Cielo();

        Arena();

        Mar();

        Olas();

        Espuma();

        Sol();

        Nubes();

        ZonaPalmeras();

        ZonaPlaya();

        Decoracion();

        Caseta();

        Bote();

    glPopMatrix();

    glFlush();

    glutSwapBuffers();
}

// ============================================================
// RESHAPE
// ============================================================

void reshape(int w, int h)
{
    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(
        55.0,
        (GLfloat)w / (GLfloat)h,
        1.0,
        1000.0
    );

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(
        0.0, 5.0, 10.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );
}

// ============================================================
// TECLADO
// ============================================================

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        // ZOOM

        case '+':
            posZ += 1.0f;
            break;

        case '-':
            posZ -= 1.0f;
            break;

        // ADELANTE / ATRAS

        case 'w':
        case 'W':
            posY += 1.0f;
            break;

        case 's':
        case 'S':
            posY -= 1.0f;
            break;

        // IZQUIERDA / DERECHA

        case 'a':
        case 'A':
            posX -= 1.0f;
            break;

        case 'd':
        case 'D':
            posX += 1.0f;
            break;

        // SALIR

        case 27:
            exit(0);
            break;

        default:
            break;
    }

    glutPostRedisplay();
}

// ============================================================
// TECLAS DE DIRECCION
// ============================================================

void arrow_keys(int a_keys, int x, int y)
{
    switch(a_keys)
    {
        case GLUT_KEY_UP:

            eye_camX -= 3;

            break;

        case GLUT_KEY_DOWN:

            eye_camX += 3;

            break;

        case GLUT_KEY_LEFT:

            eye_camY -= 3;

            break;

        case GLUT_KEY_RIGHT:

            eye_camY += 3;

            break;

        case GLUT_KEY_PAGE_UP:

            posY += 1.0f;

            break;

        case GLUT_KEY_PAGE_DOWN:

            posY -= 1.0f;

            break;

        default:

            break;
    }

    glutPostRedisplay();
}

// ============================================================
// MAIN
// ============================================================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowPosition(100, 50);

    glutInitWindowSize(1200, 800);

    glutCreateWindow("Playa 3D - OpenGL FreeGLUT");

    InitGL();

    glutReshapeFunc(reshape);

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutSpecialFunc(arrow_keys);

    glutMainLoop();

    return 0;
}
