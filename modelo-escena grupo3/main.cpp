#include <GL/freeglut.h>

void dibujarEscena() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0,  
              0.0, 0.0, 0.0,  
              0.0, 1.0, 0.0);

    // Pared del fondo
    glPushMatrix();
        glTranslatef(0.0, 0.0, -2.0);
        glScalef(6.0, 4.0, 0.1);
        glColor3f(0.55, 0.75, 0.90);
        glutSolidCube(1.0);
    glPopMatrix();

    // Suelo con baldosas
    glPushMatrix();
        glTranslatef(0.0, -1.8, -1.0);
        glScalef(6.0, 0.1, 3.0);
        glColor3f(0.35, 0.55, 0.75);
        glutSolidCube(1.0);
    glPopMatrix();

    // Luces de techo
    glPushMatrix();
        glTranslatef(-1.2, 1.8, -1.5);
        glScalef(1.2, 0.05, 0.6);
        glColor3f(0.9, 0.95, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.2, 1.8, -1.5);
        glScalef(1.2, 0.05, 0.6);
        glColor3f(0.9, 0.95, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    // Armario
    glPushMatrix();
        glTranslatef(-1.8, -0.2, -1.8);
        glScalef(0.7, 2.2, 0.3);
        glColor3f(0.95, 0.95, 0.98);
        glutSolidCube(1.0);
    glPopMatrix();

    // Estante con frascos
    glPushMatrix();
        glTranslatef(0.0, 0.1, -1.8);
        glScalef(2.0, 0.05, 0.3);
        glColor3f(0.95, 0.95, 0.98);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.4, 0.2, -1.8);
        glScalef(0.15, 0.15, 0.15);
        glColor3f(0.8, 0.9, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.7, 0.2, -1.8);
        glScalef(0.15, 0.15, 0.15);
        glColor3f(0.8, 0.9, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    // Escritorio y cajones
    glPushMatrix();
        glTranslatef(0.0, -0.6, -1.5);
        glScalef(2.8, 0.1, 0.8);
        glColor3f(0.95, 0.95, 0.98);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.9, -1.1, -1.5);
        glScalef(0.6, 0.9, 0.7);
        glColor3f(0.95, 0.95, 0.98);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.9, -1.1, -1.5);
        glScalef(0.6, 0.9, 0.7);
        glColor3f(0.95, 0.95, 0.98);
        glutSolidCube(1.0);
    glPopMatrix();

    // Silla de oficina
    glPushMatrix();
        glTranslatef(0.0, -0.7, -1.1);
        glScalef(0.5, 0.08, 0.5);
        glColor3f(0.08, 0.18, 0.36);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -0.3, -1.2);
        glScalef(0.45, 0.5, 0.08);
        glColor3f(0.08, 0.18, 0.36);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -1.2, -1.1);
        glScalef(0.08, 0.9, 0.08);
        glColor3f(0.40, 0.45, 0.50);
        glutSolidCube(1.0);
    glPopMatrix();

    // Monitores
    glPushMatrix();
        glTranslatef(0.0, 0.7, -1.9);
        glScalef(1.2, 0.8, 0.05);
        glColor3f(0.95, 0.95, 0.98);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.7, -1.88);
        glScalef(1.1, 0.7, 0.02);
        glColor3f(0.08, 0.18, 0.36);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -0.3, -1.4);
        glScalef(0.6, 0.4, 0.05);
        glColor3f(0.08, 0.18, 0.36);
        glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void inicializar() {
    glClearColor(0.05, 0.12, 0.25, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0 / 3.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Consultorio Medico - Escena Avanzada");

    inicializar();
    glutDisplayFunc(dibujarEscena);
    glutMainLoop();
    return 0;
}
