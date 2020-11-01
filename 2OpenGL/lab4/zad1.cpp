#include <GL/glut.h>

GLfloat vertices[][3] = {{-1.0, -1.0, -1.0},
                         {1.0,  -1.0, -1.0},
                         {1.0,  1.0,  -1.0},
                         {-1.0, 1.0,  -1.0},
                         {-1.0, -1.0, 1.0},
                         {1.0,  -1.0, 1.0},
                         {1.0,  1.0,  1.0},
                         {-1.0, 1.0,  1.0},
                         {-1.5, 1.5,  0.5}};

GLfloat vertices2[][3] = {
                            {-1.0, -1.0, -1.0},
                            {0, -2.0, 0},
                            {1.0,  -1.0, -1.0},
                            {-1.0, -1.0, 1.0},
                            {1.0,  -1.0, 1.0}
                         };

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
//               0      3      2      1
/* rysowanie wielościanu na podstawie listy wierzchołków */
//    glBegin(GL_POLYGON);
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

void polygon2(int a, int b, int c, int d) {
/* rysowanie wielościanu na podstawie listy wierzchołków */
    int t[] = {a, b, c, d};
//    glBegin(GL_POLYGON);
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i < 4; i++) {
//        glColor3fv(colors[t[i]]);
//        glNormal3fv(normals[t[i]]);
        glVertex3fv(vertices2[t[i]]);
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

    polygon2(0, 1, 2, 0);
    polygon2(1, 3, 3, 4);
    polygon2(1, 4, 4, 1);
}

static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;

void display() { /* funkcja wyświetlania, czyści bufor okna i
bufor głębi,
braca sześcian, rysuje i podmienia bufory */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    colorcube();
    glFlush();
    glutSwapBuffers();
}

void spinCube() {
/* funkcja Idle, realizowana w czasie bezczynności
obraca sześcian o 2 stopnie wokół zadanej osi */
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

int main(int argc, char **argv) {
    glutInit(&argc, argv);
/* przyjmujemy podwójne buforowanie oraz bufor głębokości */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sześcian");

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);


//    glutIdleFunc(spinCube);
//    glutMouseFunc(mouse);
//    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}