#include <GL/freeglut.h>

void dibujar()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    
    glutSwapBuffers();
}

void inicializar()
{
    glClearColor(1.0f, 0.75f, 0.8f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 400, 0, 400, -200, 200);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("MODELO CUARTO 2D");

    inicializar();

    glutDisplayFunc(dibujar);

    glutMainLoop();
    return 0;
}


