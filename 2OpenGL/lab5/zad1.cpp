#include <GL/glut.h>
#include <cstdlib>
#include <chrono>
#include "windows.h"

static int window;
static int menu_id;
static int submenu_id;
static int rotate_submenu_id;
static int value = 1;
static float previousRotateSpeed = 1;
static float rotateSpeed = 1;
static bool isStrip = false;
GLfloat vertices[][3] = {{-1.0, -1.0, -1.0},
                         {1.0,  -1.0, -1.0},
                         {1.0,  1.0,  -1.0},
                         {-1.0, 1.0,  -1.0},
                         {-1.0, -1.0, 1.0},
                         {1.0,  -1.0, 1.0},
                         {1.0,  1.0,  1.0},
                         {-1.0, 1.0,  1.0},
                         {-1.5, 1.5,  0.5}};

GLfloat vertices2[][3] = {{1.0,  1.0, 1.0},
                          {0,    2.0, 0},
                          {1.0,  1.0, -1.0},
                          {-1.0, 1.0, 1.0},
                          {-1.0, 1.0, -1.0}};

GLfloat normals[][3] = {{-1.0, -1.0, -1.0},
                        {1.0,  -1.0, -1.0},
                        {1.0,  1.0,  -1.0},
                        {-1.0, 1.0,  -1.0},
                        {-1.0, -1.0, 1.0},
                        {1.0,  -1.0, 1.0},
                        {1.0,  1.0,  1.0},
                        {-1.0, 1.0,  1.0}};

GLfloat colors[][3] = {{1, 0.196, 0.196},
                       {1, 0.196, 0.196},
                       {1, 0.196, 0.196},
                       {1, 0.196, 0.196},
                       {1, 0.196, 0.196},
                       {1, 0.196, 0.196},
                       {1, 0.196, 0.196},
                       {1, 0.196, 0.196},};

GLfloat colorst[][3] = {{0.301, 0.062, 0},
                        {0.301, 0.062, 0},
                        {0.301, 0.062, 0},
                        {0.301, 0.062, 0},
                        {0.301, 0.062, 0},
                        {0.301, 0.062, 0},
                        {0.301, 0.062, 0},
                        {0.301, 0.062, 0},};

void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    } else {
        value = num;
    }
    glutPostRedisplay();
}

static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;

void auxiliaryLines() {
    glBegin(GL_LINES);
    glColor3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(2.f, 0.f, 0.f);

    glColor3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 2.0f, 0.f);

    glColor3f(0.0f, 0.0f, 2.0f);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 0.f, 2.f);


    glEnd();
}

void triangle(int a, int b, int c) {
/* rysowanie wielościanu na podstawie listy wierzchołków */
    int t[] = {a, b, c};
    if (isStrip)
        glBegin(GL_TRIANGLES);
    else
        glBegin(GL_LINE_STRIP);


    for (int i : t) {
        glColor3fv(colorst[i]);
        glNormal3fv(normals[i]);
        glVertex3fv(vertices2[i]);
    }
    glEnd();
}


void polygon(int a, int b, int c, int d) {
/* rysowanie wielościanu na podstawie listy wierzchołków */

    if (isStrip)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_STRIP);
    glColor3fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);

    glColor3fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);

    glColor3fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);

    glColor3fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void colorcube() {
/* odwzorowanie wierzchołków na ściany sześcianu */
    polygon(0, 3, 2, 1);
    polygon(2, 3, 7, 6);
    polygon(0, 4, 7, 3);
    polygon(1, 2, 6, 5);
    polygon(4, 5, 6, 7);
    polygon(0, 1, 5, 4);

    triangle(0, 1, 2);
    triangle(2, 4, 1);
    triangle(4, 3, 1);
    triangle(3, 0, 1);
}

void drawHome() {
    glFlush();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    colorcube();
    auxiliaryLines();
    glFlush();
    glutSwapBuffers();
}

void drawSphere() {
    glFlush();
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);


    glColor3d(1.0, 0.0, 0.0);
    glutWireSphere(0.5, 50, 50);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
//Todo po okręgu obrot
void drawCone() {

    glFlush();
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glRotated(65, -1.0, 0.0, 0.0);
    glutWireCone(0.5, 1.0, 50, 50);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();

}

void drawTorus() {
    glFlush();
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3d(0.0, 0.0, 1.0);
    glutWireTorus(0.3, 0.6, 100, 100);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void drawTeapot() {
    glFlush();
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3d(1.0, 0.0, 1.0);
    glutSolidTeapot(0.5);
    glPopMatrix();


    glFlush();
    glutSwapBuffers();

}

int previousValue;

void display() { /* funkcja wyświetlania, czyści bufor okna i bufor głębi, braca sześcian, rysuje i podmienia bufory */
    switch (value) {
        case 0: {
            exit(0);
        }
        case 1: {
            glFlush();
            glPushMatrix();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


            glFlush();
            glutSwapBuffers();

        }
            break;
        case 2: {
            drawSphere();

            previousValue = 2;
        }
            break;
        case 3: {
            drawCone();
            previousValue = 3;
        }
            break;
        case 4: {
            drawTorus();
            previousValue = 4;
        }
            break;
        case 5: {
            drawTeapot();
            previousValue = 5;
        }
            break;
        case 6: {
            drawHome();
            previousValue = 6;
        }
            break;
        case 10: {
//            ox
            axis = 0;
            value = previousValue;
            Sleep(20);

        }
            break;
        case 11: {
//            oy
            axis = 1;
            value = previousValue;
            Sleep(20);
        }
            break;
        case 12: {
//            oz
            axis = 2;
            value = previousValue;
            Sleep(20);

        }
            break;
        case 13: {
//            start/stop

            if (rotateSpeed != 0) {
                previousRotateSpeed = rotateSpeed;
                rotateSpeed = 0;
            } else
                rotateSpeed = previousRotateSpeed;

            value = previousValue;
        }
            break;
        case 14: {
//            slower
            if (rotateSpeed > 0.5f)
                rotateSpeed = rotateSpeed - 0.5f;
            value = previousValue;

        }
            break;
        case 15: {
//            faster
            rotateSpeed = rotateSpeed + 0.5f;
            value = previousValue;
        }
        case 16: {
//            faster
            for (int i = 0; i <= 3; i++)
                theta[i] = 0;
            value = previousValue;
        }
            break;
        case 17: {
            if (isStrip)
                isStrip = false;
            else
                isStrip = true;
            value = previousValue;
        }
        case 18: {
//                po okręgu

        }
            break;
        default: {
            0;
        }
    }
}

void spinCube() {
/* funkcja Idle, realizowana w czasie bezczynności obraca sześcian o 2 stopnie wokół zadanej osi */
    theta[axis] += rotateSpeed;
    if (theta[axis] > 360.0) theta[axis] -= 360.0;
    display();
    glutPostRedisplay();
}

void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
                2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
                2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void createMenu() {
//
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Sphere", 2);
    glutAddMenuEntry("Cone", 3);
    glutAddMenuEntry("Torus", 4);
    glutAddMenuEntry("Teapot", 5);
    glutAddMenuEntry("MOJE!!!", 6);

    rotate_submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("OX", 10);
    glutAddMenuEntry("OY", 11);
    glutAddMenuEntry("OZ", 12);
    glutAddMenuEntry("Start/Stop", 13);
    glutAddMenuEntry("slower", 14);
    glutAddMenuEntry("faster", 15);
    glutAddMenuEntry("reset", 16);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddSubMenu("Rotate", rotate_submenu_id);
    glutAddMenuEntry("Type", 17);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
/* przyjmujemy podwójne buforowanie oraz bufor głębokości */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Szescian");


    createMenu();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);


    glutIdleFunc(spinCube);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}