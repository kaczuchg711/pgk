#include <GL/glut.h>

void drawRectangle() {
    glBegin(GL_POLYGON);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.9, -0.8);
    glVertex2f(0.7, -0.8);
    glEnd();
}

void drawLines() {
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.75f, 0.75f);
    glVertex2f(0.75f, 0.75f);

    glVertex2f(-0.6f, 0.6f);
    glVertex2f(0.6f, 0.8f);

    glVertex2f(-0.6f, 0.6f);
    glVertex2f(0.6f, 0.8f);

    glVertex2f(-0.6f, 0.5f);
    glVertex2f(-0.4f, 0.7f);
    glEnd();
}

void drawLinesStrip() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.75f, 0.45f);
    glVertex2f(0.75f, 0.45f);

    glVertex2f(-0.6f, 0.4f);
    glVertex2f(0.6f, 0.6f);
    glEnd();
}


void drawPoint() {
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);

    for (int i = 0; i <= 150; ++i)
        glVertex2f(-0.75f + i / 100., 0.85f);

    glEnd();

}

void drawLineLoop() {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    float x = 0.1;
    glVertex2f(-0.75f, 0.20f + x);
    glVertex2f(-0.70f, 0.25f + x);
    glVertex2f(-0.30f, 0.25f + x);
    glVertex2f(0.5f, 0.20f + x);
    glVertex2f(-0.30f, 0.10f + x);
    glEnd();
}

void drawTriangles() {
    float dy = 0.2;
    float dx = 0.0;
    glColor3f(1.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.7f + dx, 0.1 - dy);
    glVertex2f(-0.7f + dx, 0.2 - dy);
    glVertex2f(-0.5f + dx, 0.1 - dy);

    glVertex2f(-0.4f + dx, 0.2 - dy);
    glVertex2f(-0.6f + dx, 0.0 - dy);
    glVertex2f(-0.2f + dx, 0.0 - dy);


    glEnd();
}

void drawTrianglesStrip() {
    float dy = -0.25;
    float dx = 0.0;
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLE_STRIP);

    glVertex2f(0.0f + dx, 0.2 + dy);
    glVertex2f(0.0f + dx, 0.0 + dy);
    glVertex2f(0.25f + dx, 0.2 + dy);
    glVertex2f(0.25f + dx, 0.0 + dy);
    glVertex2f(0.1f + dx, 0.3 + dy);
    glVertex2f(0.1f + dx, -0.1 + dy);


    glEnd();
}


void drawTriangFan() {
    float dy = -0.2;
    float dx = 0.7;
    glColor3f(0.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLE_STRIP);

    glVertex2f(0.0f + dx, 0.0 + dy);
    glVertex2f(0.0f + dx, 0.2 + dy);
    glVertex2f(0.2f + dx, 0.18 + dy);
    glVertex2f(0.3f + dx, 0.02 + dy);
    glVertex2f(0.25f + dx, -0.15 + dy);

    glEnd();
}

void drawQuads() {
    float dy = -0.6f;
    float dx = -1.f;
    glColor3f(0.5f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    glVertex2f(0.0f + dx, 0.0 + dy);
    glVertex2f(0.1f + dx, 0.1 + dy);
    glVertex2f(0.3f + dx, 0.11 + dy);
    glVertex2f(0.31f + dx, -0.11 + dy);

    glVertex2f(0.4f + dx, -0.3 + dy);
    glVertex2f(0.5f + dx, 0.1 + dy);
    glVertex2f(0.6f + dx, 0.11 + dy);
    glVertex2f(0.63f + dx, -0.11 + dy);


    glEnd();
}

void drawQuadsStrip() {
    float dy = -0.5f;
    float dx = -0.3f;
    glColor3f(0.5f, 0.2f, 1.0f);

    glBegin(GL_QUAD_STRIP);

    glVertex2f(0.0f + dx, 0.0 + dy);
    glVertex2f(0.1f + dx, 0.1 + dy);
    glVertex2f(0.3f + dx, 0.11 + dy);
    glVertex2f(0.31f + dx, -0.11 + dy);

    glVertex2f(0.4f + dx, -0.3 + dy);
    glVertex2f(0.5f + dx, 0.1 + dy);
    glVertex2f(0.6f + dx, 0.11 + dy);
    glVertex2f(0.63f + dx, -0.11 + dy);


    glEnd();
}


void drawObjects() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRectangle();
    drawLines();
    drawPoint();
    drawLinesStrip();
    drawLineLoop();
    drawTriangles();
    drawTrianglesStrip();
    drawTriangFan();
    drawQuads();
    drawQuadsStrip();

    glFlush(); //wyświetlenie bufora obrazu
}


int main(int argc, char **argv) {
    glutInitWindowSize(800, 800);

    glutCreateWindow("Okno OpenGL"); //tworzenie okna aplikacji
    glutDisplayFunc(drawObjects);

    glutMainLoop(); //główna pętla aplikacji
}

