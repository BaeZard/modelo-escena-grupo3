#include <GL/freeglut.h>
#include <math.h>

const float PI = 3.14159265f;

// mundo = tamano de la referencia
const float ANCHO = 368.0f;
const float ALTO  = 466.0f;

// perspectiva
const float FUGA_X = 180.0f;
const float FUGA_Y = 201.0f;
const float BASE_PARED = 89.0f;
const float TOPE_PARED = 373.0f;

// piso: 0 oscuro, 1 medio, 2 claro, 3 blanco
int piso[8][9] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 1, 0, 0},
    {1, 1, 2, 3, 0, 3, 2, 2, 2},
    {1, 1, 1, 2, 2, 2, 1, 1, 1},
    {0, 0, 0, 1, 3, 1, 0, 0, 0},
    {2, 2, 2, 3, 2, 3, 2, 2, 2},
    {2, 2, 2, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 1, 3, 1, 2, 2, 2}
};
float filasPiso[9] = {89.0f, 78.0f, 62.0f, 54.0f, 45.0f, 34.0f, 22.0f, 5.0f, 0.0f};


// ============================ figuras basicas ============================

void rgb(int r, int g, int b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
}

void rgba(int r, int g, int b, float a) {
    glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void rect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void quad(float ax, float ay, float bx, float by,
          float cx, float cy, float dx, float dy) {
    glBegin(GL_QUADS);
        glVertex2f(ax, ay);
        glVertex2f(bx, by);
        glVertex2f(cx, cy);
        glVertex2f(dx, dy);
    glEnd();
}

void triangulo(float ax, float ay, float bx, float by, float cx, float cy) {
    glBegin(GL_TRIANGLES);
        glVertex2f(ax, ay);
        glVertex2f(bx, by);
        glVertex2f(cx, cy);
    glEnd();
}

void linea(float x1, float y1, float x2, float y2, float grosor) {
    glLineWidth(grosor);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void elipse(float cx, float cy, float rx, float ry) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 40; i++) {
            float a = 2.0f * PI * i / 40;
            glVertex2f(cx + rx * cos(a), cy + ry * sin(a));
        }
    glEnd();
}

void circulo(float cx, float cy, float r) {
    elipse(cx, cy, r, r);
}

// recta al punto de fuga
float fugaX(float xPared, float yPared, float y) {
    return FUGA_X + (xPared - FUGA_X) * (y - FUGA_Y) / (yPared - FUGA_Y);
}


// ============================ habitacion ============================

void colorPiso(int tipo) {
    if (tipo == 0) rgb(70, 105, 150);
    if (tipo == 1) rgb(100, 138, 180);
    if (tipo == 2) rgb(140, 188, 222);
    if (tipo == 3) rgb(198, 218, 238);
}

void dibujarPiso() {
    // baldosas
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 9; i++) {
            float x1 = -38.0f + 48.5f * i;
            float x2 = x1 + 48.5f;
            float yA = filasPiso[j];
            float yB = filasPiso[j + 1];

            colorPiso(piso[j][i]);
            quad(fugaX(x1, BASE_PARED, yA), yA,
                 fugaX(x2, BASE_PARED, yA), yA,
                 fugaX(x2, BASE_PARED, yB), yB,
                 fugaX(x1, BASE_PARED, yB), yB);
        }
    }

    // juntas
    rgb(20, 40, 80);
    for (int i = 1; i < 9; i++) {
        float x = -38.0f + 48.5f * i;
        linea(x, BASE_PARED, fugaX(x, BASE_PARED, 0.0f), 0.0f, 1.5f);
    }
    rgb(70, 115, 150);
    linea(0.0f, 22.0f, ANCHO, 22.0f, 1.0f);

    // sombras
    rgb(20, 35, 70);
    quad(70.0f, 88.0f, 132.0f, 88.0f, 128.0f, 82.0f, 74.0f, 82.0f);
    quad(237.0f, 88.0f, 299.0f, 88.0f, 295.0f, 82.0f, 241.0f, 82.0f);
    rgba(20, 35, 70, 0.35f);
    elipse(185.0f, 81.0f, 40.0f, 6.0f);
}

void lamparaTecho(float x1, float x2, float y1, float y2) {
    rgb(250, 253, 255);
    quad(fugaX(x1, TOPE_PARED, y1), y1,
         fugaX(x2, TOPE_PARED, y1), y1,
         fugaX(x2, TOPE_PARED, y2), y2,
         fugaX(x1, TOPE_PARED, y2), y2);
}

void dibujarTecho() {
    rgb(117, 176, 216);
    rect(0.0f, TOPE_PARED, ANCHO, ALTO);
    rgb(100, 165, 205);
    rect(0.0f, 448.0f, ANCHO, ALTO);

    // lineas
    rgb(135, 190, 225);
    linea(0.0f, 424.0f, ANCHO, 424.0f, 1.0f);
    linea(0.0f, 395.0f, ANCHO, 395.0f, 1.0f);

    rgb(45, 95, 145);
    linea(0.0f, 448.0f, ANCHO, 448.0f, 2.0f);
    float lineas[4] = {68.0f, 137.0f, 222.0f, 285.0f};
    for (int i = 0; i < 4; i++) {
        linea(lineas[i], TOPE_PARED, fugaX(lineas[i], TOPE_PARED, ALTO), ALTO, 2.0f);
    }

    // lamparas
    lamparaTecho(71.0f, 134.0f, 424.0f, 446.0f);
    lamparaTecho(225.0f, 282.0f, 424.0f, 446.0f);
    lamparaTecho(71.0f, 134.0f, 376.0f, 394.0f);
    lamparaTecho(225.0f, 282.0f, 376.0f, 394.0f);

    // resplandor
    rgba(255, 255, 255, 0.25f);
    elipse(90.0f, 420.0f, 16.0f, 4.0f);
    elipse(90.0f, 398.0f, 16.0f, 4.0f);
    elipse(265.0f, 420.0f, 16.0f, 4.0f);
    elipse(265.0f, 398.0f, 16.0f, 4.0f);
}

void dibujarParedes() {
    // pared del fondo
    rgb(92, 167, 207);
    rect(6.0f, BASE_PARED, 344.0f, TOPE_PARED);

    // haces de luz
    rgb(138, 204, 236);
    quad(80.0f, TOPE_PARED, 137.0f, TOPE_PARED, 202.0f, 252.0f, 184.0f, 252.0f);
    quad(221.0f, TOPE_PARED, 272.0f, TOPE_PARED, 182.0f, 252.0f, 156.0f, 252.0f);

    // zonas de sombra
    rgb(50, 107, 153);
    triangulo(6.0f, TOPE_PARED, 86.0f, TOPE_PARED, 6.0f, 304.0f);
    triangulo(286.0f, TOPE_PARED, 344.0f, TOPE_PARED, 344.0f, 313.0f);
    rgb(83, 148, 192);
    quad(46.0f, 337.0f, 170.0f, 168.0f, 6.0f, 168.0f, 6.0f, 304.0f);

    // paredes laterales
    rgb(107, 180, 221);
    quad(0.0f, 80.0f, 6.0f, BASE_PARED, 6.0f, TOPE_PARED, 0.0f, 378.0f);
    rgb(54, 118, 170);
    quad(0.0f, 294.0f, 6.0f, 296.0f, 6.0f, TOPE_PARED, 0.0f, 378.0f);
    rgb(88, 160, 203);
    quad(344.0f, BASE_PARED, 368.0f, 72.0f, 368.0f, 398.0f, 344.0f, TOPE_PARED);

    // borde del techo
    rgb(150, 205, 235);
    rect(6.0f, 371.0f, 344.0f, 374.0f);

    // zocalo
    rgb(120, 170, 212);
    rect(6.0f, BASE_PARED, 344.0f, 97.0f);
    rgb(180, 208, 231);
    rect(0.0f, BASE_PARED, 76.0f, 98.0f);
}

void dibujarCamara() {
    rgb(120, 150, 185);
    circulo(189.0f, 413.0f, 4.0f);
    rgb(64, 65, 113);
    elipse(180.0f, 412.0f, 7.0f, 5.0f);
    rgb(40, 40, 80);
    elipse(180.0f, 410.0f, 5.0f, 2.5f);
}


// ============================ pared ============================

void dibujarReloj() {
    glPushMatrix();
        glTranslatef(307.0f, 340.0f, 0.0f);

        rgba(20, 60, 110, 0.4f);
        circulo(2.0f, -2.0f, 10.5f);
        rgb(60, 80, 120);
        circulo(0.0f, 0.0f, 10.0f);
        rgb(245, 245, 250);
        circulo(0.0f, 0.0f, 8.0f);

        // marcas
        rgb(150, 150, 175);
        for (int i = 0; i < 8; i++) {
            glPushMatrix();
                glRotatef(45.0f * i, 0.0f, 0.0f, 1.0f);
                circulo(0.0f, 5.5f, 0.9f);
            glPopMatrix();
        }

        // agujas
        rgb(40, 40, 60);
        glPushMatrix();
            glRotatef(-60.0f, 0.0f, 0.0f, 1.0f);
            linea(0.0f, 0.0f, 0.0f, 4.0f, 1.5f);
        glPopMatrix();
        glPushMatrix();
            glRotatef(150.0f, 0.0f, 0.0f, 1.0f);
            linea(0.0f, 0.0f, 0.0f, 6.0f, 1.2f);
        glPopMatrix();
        circulo(0.0f, 0.0f, 1.5f);
    glPopMatrix();
}

void dibujarMonitorECG() {
    rgb(45, 60, 95);
    rect(133.0f, 244.0f, 227.0f, 313.0f);
    rgb(245, 252, 255);
    rect(137.0f, 247.0f, 224.0f, 310.0f);

    // pantalla
    rgb(175, 228, 246);
    rect(143.0f, 252.0f, 217.0f, 305.0f);
    rgba(255, 255, 255, 0.25f);
    rect(143.0f, 252.0f, 160.0f, 305.0f);

    // cuadricula
    rgba(255, 255, 255, 0.2f);
    for (int i = 1; i < 8; i++) {
        linea(143.0f + 9.25f * i, 252.0f, 143.0f + 9.25f * i, 305.0f, 1.0f);
    }
    for (int i = 1; i < 6; i++) {
        linea(143.0f, 252.0f + 8.8f * i, 217.0f, 252.0f + 8.8f * i, 1.0f);
    }

    // latido
    rgb(255, 255, 255);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(146.0f, 273.0f);
        glVertex2f(165.0f, 273.0f);
        glVertex2f(167.0f, 288.0f);
        glVertex2f(170.0f, 276.0f);
        glVertex2f(172.0f, 286.0f);
        glVertex2f(175.0f, 276.0f);
        glVertex2f(178.0f, 281.0f);
        glVertex2f(182.0f, 274.0f);
        glVertex2f(185.0f, 286.0f);
        glVertex2f(188.0f, 276.0f);
        glVertex2f(192.0f, 279.0f);
        glVertex2f(195.0f, 288.0f);
        glVertex2f(200.0f, 263.0f);
        glVertex2f(203.0f, 273.0f);
        glVertex2f(214.0f, 273.0f);
    glEnd();
}

void dibujarCuadroCruz() {
    rgba(20, 60, 110, 0.35f);
    rect(258.0f, 261.0f, 303.0f, 310.0f);

    rgb(58, 77, 119);
    rect(255.0f, 264.0f, 300.0f, 313.0f);
    rgb(248, 255, 255);
    rect(258.0f, 267.0f, 297.0f, 310.0f);
    rgb(138, 198, 224);
    rect(262.0f, 271.0f, 293.0f, 306.0f);
    rgb(175, 220, 238);
    rect(266.0f, 275.0f, 289.0f, 302.0f);

    // cruz
    rgb(250, 255, 255);
    rect(268.5f, 285.5f, 286.5f, 291.5f);
    rect(274.5f, 279.5f, 280.5f, 297.5f);
}

void dibujarMonitorPared() {
    rgb(49, 39, 89);
    quad(350.0f, 294.0f, 368.0f, 289.0f, 368.0f, 357.0f, 350.0f, 352.0f);
    rgb(225, 248, 252);
    quad(354.0f, 297.0f, 368.0f, 293.0f, 368.0f, 352.0f, 354.0f, 348.0f);

    rgb(110, 170, 210);
    linea(357.0f, 322.0f, 366.0f, 325.0f, 1.0f);
    linea(357.0f, 330.0f, 366.0f, 333.0f, 1.0f);

    // gancho
    rgb(170, 190, 210);
    rect(359.0f, 276.0f, 361.0f, 290.0f);
}

void dibujarPortapapeles() {
    glPushMatrix();
        glTranslatef(336.0f, 250.0f, 0.0f);
        glRotatef(5.0f, 0.0f, 0.0f, 1.0f);

        rgb(245, 250, 255);
        rect(-7.0f, -24.0f, 7.0f, 22.0f);

        // renglones
        rgb(60, 70, 100);
        for (int i = 0; i < 7; i++) {
            rect(-5.0f, 14.0f - 5.5f * i, -3.5f, 15.5f - 5.5f * i);
            linea(-2.0f, 14.75f - 5.5f * i, 5.0f, 14.75f - 5.5f * i, 1.0f);
        }

        // clip
        rgb(40, 45, 80);
        rect(-4.0f, 20.0f, 4.0f, 25.0f);
    glPopMatrix();
}

void dibujarArmario() {
    rgb(126, 200, 239);
    rect(70.0f, 169.0f, 75.0f, 294.0f);
    rgb(190, 226, 248);
    rect(16.0f, 169.0f, 70.0f, 294.0f);
    rgb(215, 238, 252);
    rect(52.0f, 169.0f, 70.0f, 294.0f);

    // puertas
    rgb(150, 190, 220);
    linea(43.0f, 169.0f, 43.0f, 294.0f, 1.5f);
    linea(16.0f, 233.0f, 70.0f, 233.0f, 1.5f);

    // manijas
    rgb(40, 50, 80);
    circulo(39.0f, 239.0f, 1.3f);
    circulo(47.0f, 239.0f, 1.3f);
    circulo(39.0f, 226.0f, 1.3f);
    circulo(47.0f, 226.0f, 1.3f);
}

void dibujarDispensador() {
    rgba(20, 60, 100, 0.45f);
    rect(88.0f, 248.0f, 113.0f, 287.0f);

    rgb(230, 248, 255);
    rect(91.0f, 256.0f, 116.0f, 291.0f);
    rect(93.0f, 254.0f, 114.0f, 293.0f);

    // pantalla
    rgb(45, 65, 100);
    rect(96.0f, 279.0f, 104.0f, 289.0f);
    rgb(230, 130, 70);
    circulo(109.0f, 285.0f, 1.5f);

    // botones
    rgb(225, 170, 140);
    rect(95.0f, 275.0f, 108.0f, 277.0f);
    rgb(114, 188, 215);
    rect(95.0f, 266.0f, 112.0f, 271.0f);
    rect(95.0f, 259.0f, 112.0f, 263.0f);
}

void frasco() {
    rgb(235, 245, 250);
    rect(0.0f, 0.0f, 15.0f, 19.0f);
    rgb(185, 212, 230);
    rect(0.0f, 13.0f, 15.0f, 19.0f);
    rgb(250, 253, 255);
    rect(4.0f, 15.0f, 11.0f, 17.0f);
    rgb(215, 150, 90);
    rect(5.0f, 2.0f, 10.0f, 7.0f);
}

void dibujarEstante() {
    rgba(20, 60, 110, 0.3f);
    rect(122.0f, 225.0f, 314.0f, 229.0f);
    rgb(90, 150, 190);
    rect(120.0f, 229.0f, 312.0f, 231.0f);
    rgb(148, 212, 240);
    rect(120.0f, 231.0f, 312.0f, 237.0f);

    // frascos
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
            glTranslatef(245.0f + 18.5f * i, 237.0f, 0.0f);
            frasco();
        glPopMatrix();
    }
}


// ============================ escritorio ============================

void dibujarRiel() {
    rgb(55, 105, 150);
    rect(75.0f, 168.0f, 300.0f, 199.0f);

    rgb(195, 228, 245);
    rect(100.0f, 191.0f, 270.0f, 209.0f);
    rgb(60, 100, 150);
    rect(100.0f, 196.0f, 270.0f, 204.0f);

    rgb(225, 248, 255);
    for (int i = 0; i < 8; i++) {
        rect(108.0f + 20.0f * i, 197.5f, 116.0f + 20.0f * i, 202.5f);
    }
}

void cajonera() {
    rgb(206, 232, 249);
    rect(0.0f, 0.0f, 45.0f, 67.0f);
    rgb(170, 205, 230);
    rect(45.0f, 0.0f, 50.0f, 67.0f);

    // cajones
    for (int i = 0; i < 5; i++) {
        float y = 13.4f * i;

        rgb(160, 195, 222);
        linea(0.0f, y, 45.0f, y, 1.0f);

        if (i == 3)      rgb(190, 90, 95);
        else if (i == 0) rgb(30, 30, 50);
        else             rgb(95, 105, 125);
        rect(18.0f, y + 8.0f, 28.0f, y + 9.5f);
    }

    // base
    rgb(120, 128, 165);
    rect(2.0f, -8.0f, 46.0f, 0.0f);
}

void dibujarEscritorio() {
    // bajo el escritorio
    rgb(40, 90, 135);
    rect(6.0f, 97.0f, 76.0f, 169.0f);
    rgb(52, 107, 153);
    rect(76.0f, 97.0f, 243.0f, 161.0f);
    rgb(33, 77, 120);
    rect(243.0f, 97.0f, 333.0f, 161.0f);

    // tablero
    rgb(150, 190, 220);
    rect(53.0f, 160.0f, 322.0f, 163.0f);
    rgb(204, 237, 252);
    rect(53.0f, 163.0f, 322.0f, 168.0f);

    // cajoneras
    glPushMatrix();
        glTranslatef(76.0f, 96.0f, 0.0f);
        cajonera();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(243.0f, 96.0f, 0.0f);
        cajonera();
    glPopMatrix();

    // hoja de papel
    rgb(240, 248, 255);
    quad(212.0f, 168.0f, 253.0f, 168.0f, 248.0f, 174.0f, 218.0f, 174.0f);
}

void dibujarLampara() {
    rgb(30, 35, 60);
    rect(84.0f, 168.0f, 98.0f, 171.0f);
    rgb(150, 170, 195);
    rect(90.5f, 171.0f, 95.5f, 187.0f);
    rgb(230, 240, 250);
    rect(90.5f, 176.0f, 95.5f, 179.0f);

    // cabeza
    rgb(90, 100, 150);
    quad(98.0f, 214.0f, 103.0f, 212.0f, 108.0f, 188.0f, 104.0f, 186.0f);
    rgb(66, 76, 125);
    quad(83.0f, 210.0f, 98.0f, 214.0f, 104.0f, 186.0f, 89.0f, 184.0f);
}

void dibujarAparato() {
    rgb(40, 45, 75);
    rect(100.0f, 168.0f, 145.0f, 178.0f);
    rgb(235, 245, 255);
    rect(105.0f, 170.0f, 111.0f, 175.0f);
    rect(135.0f, 170.0f, 141.0f, 175.0f);
}

void dibujarMonitor() {
    // soporte
    rgb(170, 185, 205);
    rect(180.5f, 172.0f, 185.5f, 187.0f);
    rgb(40, 45, 80);
    rect(176.0f, 168.0f, 190.0f, 172.0f);

    // marco y pantalla
    rgb(38, 35, 64);
    rect(154.0f, 187.0f, 212.0f, 227.0f);
    rgb(196, 238, 252);
    rect(157.0f, 190.0f, 209.0f, 224.0f);
    rgba(255, 255, 255, 0.5f);
    triangulo(181.0f, 224.0f, 209.0f, 224.0f, 209.0f, 194.0f);

    // grafico
    rgb(140, 195, 225);
    glLineWidth(1.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(161.0f, 200.0f);
        glVertex2f(170.0f, 206.0f);
        glVertex2f(178.0f, 201.0f);
        glVertex2f(188.0f, 210.0f);
        glVertex2f(196.0f, 205.0f);
        glVertex2f(205.0f, 213.0f);
    glEnd();
}

void dibujarGotero() {
    rgb(40, 45, 80);
    linea(260.0f, 190.0f, 253.0f, 168.0f, 1.2f);
    linea(260.0f, 190.0f, 267.0f, 168.0f, 1.2f);
    rgb(110, 60, 70);
    rect(257.0f, 189.0f, 263.0f, 199.0f);
}

void dibujarEquipo() {
    // base
    rgb(170, 212, 235);
    rect(268.0f, 168.0f, 306.0f, 186.0f);

    // cuerpo
    rgb(137, 195, 235);
    rect(268.0f, 186.0f, 317.0f, 211.0f);
    rgb(215, 235, 248);
    rect(270.0f, 188.0f, 315.0f, 209.0f);

    // teclado
    rgb(30, 30, 60);
    rect(272.0f, 191.0f, 281.0f, 208.0f);
    rgb(200, 220, 240);
    for (int i = 0; i < 4; i++) {
        rect(274.0f, 193.0f + 3.5f * i, 276.0f, 195.0f + 3.5f * i);
        rect(277.5f, 193.0f + 3.5f * i, 279.5f, 195.0f + 3.5f * i);
    }

    // lineas
    rgb(120, 180, 220);
    for (int i = 0; i < 3; i++) {
        rect(284.0f, 194.0f + 5.0f * i, 313.0f, 196.0f + 5.0f * i);
    }

    // impresora
    rgb(230, 240, 250);
    rect(300.0f, 210.0f, 318.0f, 223.0f);
    rgb(38, 35, 64);
    rect(302.0f, 217.0f, 316.0f, 219.0f);
}

void dibujarMostrador() {
    // poste de equipo
    rgb(30, 40, 70);
    rect(355.0f, 186.0f, 362.0f, 241.0f);
    rgb(110, 55, 65);
    rect(355.0f, 223.0f, 362.0f, 236.0f);
    rgb(30, 35, 60);
    rect(347.0f, 238.0f, 368.0f, 252.0f);
    rgb(200, 225, 240);
    rect(350.0f, 242.0f, 356.0f, 248.0f);

    // zocalo y ruedas
    rgb(35, 55, 95);
    quad(333.0f, 66.0f, 368.0f, 66.0f, 368.0f, 30.0f, 337.0f, 60.0f);
    rgb(150, 170, 195);
    rect(338.0f, 46.0f, 344.0f, 64.0f);
    rgb(30, 35, 60);
    circulo(341.0f, 44.0f, 4.0f);
    circulo(360.0f, 40.0f, 4.0f);

    // cuerpo
    rgb(191, 234, 253);
    rect(333.0f, 64.0f, 368.0f, 159.0f);
    rgb(100, 150, 190);
    rect(333.0f, 64.0f, 336.0f, 159.0f);
    linea(336.0f, 136.0f, 368.0f, 136.0f, 1.0f);

    // tapa
    rgb(205, 235, 250);
    rect(322.0f, 155.0f, 368.0f, 160.0f);
    rgb(150, 205, 232);
    quad(322.0f, 160.0f, 368.0f, 160.0f, 368.0f, 168.0f, 330.0f, 168.0f);

    // manija
    rgb(40, 50, 80);
    rect(344.0f, 113.0f, 348.0f, 123.0f);

    // cajita
    rgb(225, 240, 250);
    rect(340.0f, 168.0f, 358.0f, 186.0f);
    rgb(58, 77, 119);
    linea(340.0f, 177.0f, 358.0f, 177.0f, 1.0f);
    rect(346.0f, 180.0f, 352.0f, 182.0f);
    rect(346.0f, 171.0f, 352.0f, 173.0f);
}

void dibujarSilla() {
    // base
    rgb(200, 215, 230);
    linea(183.0f, 91.0f, 157.0f, 84.0f, 3.5f);
    linea(183.0f, 91.0f, 213.0f, 84.0f, 3.5f);
    linea(183.0f, 91.0f, 183.0f, 79.0f, 3.5f);

    // ruedas
    rgb(210, 222, 235);
    circulo(157.0f, 83.0f, 5.0f);
    circulo(213.0f, 83.0f, 5.0f);
    rgb(40, 45, 80);
    circulo(157.0f, 83.0f, 2.5f);
    circulo(213.0f, 83.0f, 2.5f);

    // piston
    rgb(180, 200, 220);
    rect(180.0f, 91.0f, 186.0f, 122.0f);

    // brazos
    rgb(200, 215, 230);
    rect(152.0f, 126.0f, 155.0f, 154.0f);
    rect(210.0f, 126.0f, 213.0f, 154.0f);
    rgb(46, 51, 106);
    rect(146.0f, 154.0f, 159.0f, 158.0f);
    rect(206.0f, 154.0f, 220.0f, 158.0f);

    // respaldo
    rgb(46, 51, 106);
    quad(170.0f, 136.0f, 197.0f, 136.0f, 202.0f, 170.0f, 165.0f, 170.0f);
    elipse(183.5f, 170.0f, 18.5f, 3.5f);

    // asiento
    rgb(45, 40, 85);
    elipse(183.0f, 126.0f, 28.0f, 7.0f);
    rgb(75, 72, 125);
    elipse(183.0f, 128.0f, 26.0f, 5.0f);
}


// ============================ glut ============================

// del fondo hacia el frente
void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    dibujarPiso();
    dibujarTecho();
    dibujarParedes();
    dibujarCamara();

    dibujarReloj();
    dibujarMonitorECG();
    dibujarCuadroCruz();
    dibujarMonitorPared();
    dibujarPortapapeles();
    dibujarArmario();
    dibujarDispensador();
    dibujarEstante();

    dibujarRiel();
    dibujarEscritorio();
    dibujarLampara();
    dibujarAparato();
    dibujarMonitor();
    dibujarGotero();
    dibujarEquipo();
    dibujarMostrador();
    dibujarSilla();

    glutSwapBuffers();
}

void inicializar() {
    glClearColor(0.05f, 0.12f, 0.25f, 1.0f);

    // transparencias
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, ANCHO, 0.0, ALTO, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(552, 699);
    glutInitWindowPosition(100, 20);
    glutCreateWindow("Consultorio Medico 2D - Grupo 3");

    inicializar();
    glutDisplayFunc(dibujar);

    glutMainLoop();
    return 0;
}
