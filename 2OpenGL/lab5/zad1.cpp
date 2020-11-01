#include <GL/glut.h>
#include <cstdlib>

static int window;
static int menu_id;
static int submenu_id;
static int rotate_submenu_id;
static int value = 0;

void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    } else {
        value = num;
    }
    glutPostRedisplay();
}

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

GLfloat colors[][3] = {{1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0}};


void polygon(int a, int b, int c, int d) {
/* rysowanie wielościanu na podstawie listy wierzchołków */
    glBegin(GL_POLYGON);
//    glBegin(GL_LINE_STRIP);
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

void triangle(int a, int b, int c) {
/* rysowanie wielościanu na podstawie listy wierzchołków */
    int t[] = {a, b, c};
    glBegin(GL_TRIANGLES);
//    glBegin(GL_LINE_STRIP);

    for (int i : t) {
        glColor3fv(colors[i]);
        glNormal3fv(normals[i]);
        glVertex3fv(vertices2[i]);
    }
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

void display() { /* funkcja wyświetlania, czyści bufor okna i bufor głębi, braca sześcian, rysuje i podmienia bufory */
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


void spinCube() {
/* funkcja Idle, realizowana w czasie bezczynności obraca sześcian o 2 stopnie wokół zadanej osi */
    theta[axis] += 2.0;
    if (theta[axis] > 360.0) theta[axis] -= 360.0;
/* display(); */
    glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {
/* obsługa myszki, wybiera oś rotacji sześcianu */
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
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

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddSubMenu("Rotate", rotate_submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
/* przyjmujemy podwójne buforowanie oraz bufor głębokości */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sześcian");

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);

    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}