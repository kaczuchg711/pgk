#include <GL/glut.h>
#include <cstdlib>
#include "windows.h"
#include "pom.h"

static int window;
static int menu_id;
static int submenu_id;
static int rotate_submenu_id;
static int typeSubmenuId;
static int value = 21;
static float previousRotateSpeed = 1;
static float rotateSpeed = 1;
static bool isStrip = false;
static float circleRadius = 0;
static bool isMultipleColor = true;
GLuint texture;

class Cor {
    GLfloat CorTab[3]{};
public:
    Cor(GLfloat x, GLfloat y, GLfloat z) {
        CorTab[0] = x;
        CorTab[1] = y;
        CorTab[2] = z;
    }

    GLfloat *operator()() {
        return CorTab;
    }
};

class Rgb_to_float {
    GLfloat tab[3]{};
public:
    Rgb_to_float(int r, int g, int b) {
        tab[0] = 3.92 * r / 1000;
        tab[1] = 3.92 * g / 1000;
        tab[2] = 3.92 * b / 1000;
    }

    GLfloat *operator()() {
        return tab;
    }

};


void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    } else {
        value = num;
    }
    glutPostRedisplay();
}

static GLfloat theta[] = {0.0,
                          0.0,
                          0.0};
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


void draw_polygon(Cor a, Cor b, Cor c, Cor d, Rgb_to_float color) {

    if (isStrip)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_STRIP);

    if (isMultipleColor)
        glColor3fv(color());
    else
        glColor3fv(Rgb_to_float(0, 255, 255)());

    glVertex3fv(a());
    glVertex3fv(b());
    glVertex3fv(c());
    glVertex3fv(d());
    glVertex3fv(a());


    glEnd();

}

void draw_triangle(Cor a, Cor b, Cor c, Rgb_to_float color) {
    if (isStrip)
        glBegin(GL_TRIANGLES);
    else
        glBegin(GL_LINE_STRIP);

    if (isMultipleColor)
        glColor3fv(color());
    else
        glColor3fv(Rgb_to_float(0, 255, 255)());

    glVertex3fv(a());
    glVertex3fv(b());
    glVertex3fv(c());


    glEnd();

}

void draw_octahedron() {
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    glTranslatef(circleRadius, 0.f, 0.f);


    draw_triangle(Cor(-0.3, 0, -0.3),
                  Cor(0, 0.6, 0),
                  Cor(-0.3, 0, 0.3),
                  Rgb_to_float(255, 0, 0));
    draw_triangle(Cor(-0.3, 0, 0.3),
                  Cor(0, 0.6, 0),
                  Cor(0.3, 0, 0.3),
                  Rgb_to_float(0, 255, 0));
    draw_triangle(Cor(0.3, 0, 0.3),
                  Cor(0, 0.6, 0),
                  Cor(0.3, 0, -0.3),
                  Rgb_to_float(0, 0, 255));
    draw_triangle(Cor(0.3, 0, -0.3),
                  Cor(0, 0.6, 0),
                  Cor(-0.3, 0, -0.3),
                  Rgb_to_float(255, 0, 255));

    draw_triangle(Cor(-0.3, 0, -0.3),
                  Cor(0, -0.6, 0),
                  Cor(-0.3, 0, 0.3),
                  Rgb_to_float(255, 0, 0));
    draw_triangle(Cor(-0.3, 0, 0.3),
                  Cor(0, -0.6, 0),
                  Cor(0.3, 0, 0.3),
                  Rgb_to_float(0, 255, 0));
    draw_triangle(Cor(0.3, 0, 0.3),
                  Cor(0, -0.6, 0),
                  Cor(0.3, 0, -0.3),
                  Rgb_to_float(0, 0, 255));
    draw_triangle(Cor(0.3, 0, -0.3),
                  Cor(0, -0.6, 0),
                  Cor(-0.3, 0, -0.3),
                  Rgb_to_float(255, 0, 255));

    draw_polygon(Cor(-0.3, 0, -0.3),
                 Cor(-0.3, 0, 0.3),
                 Cor(0.3, 0, 0.3),
                 Cor(0.3, 0, -0.3),
                 Rgb_to_float(255, 255, 255));


    auxiliaryLines();
    glFlush();
    glutSwapBuffers();
}

void draw_polygons() {
/* odwzorowanie wierzchołków na ściany sześcianu */
    glTranslatef(circleRadius, 0.f, 0.f);

    draw_polygon(Cor(-0.3, -0.3, -0.3),
                 Cor(-0.3, 0.3, -0.3),
                 Cor(0.3, 0.3, -0.3),
                 Cor(0.3, -0.3, -0.3),
                 Rgb_to_float(255, 255, 0));

    draw_polygon(Cor(0.3, 0.3, -0.3),
                 Cor(-0.3, 0.3, -0.3),
                 Cor(-0.3, 0.3, 0.3),
                 Cor(0.3, 0.3, 0.3),
                 Rgb_to_float(255, 0, 255));

    draw_polygon(Cor(-0.3, -0.3, -0.3),
                 Cor(-0.3, -0.3, 0.3),
                 Cor(-0.3, 0.3, 0.3),
                 Cor(-0.3, 0.3, -0.3),
                 Rgb_to_float(0, 255, 0));

    draw_polygon(Cor(0.3, -0.3, -0.3),
                 Cor(0.3, 0.3, -0.3),
                 Cor(0.3, 0.3, 0.3),
                 Cor(0.3, -0.3, 0.3),
                 Rgb_to_float(0, 255, 255));

    draw_polygon(Cor(-0.3, -0.3, -0.3),
                 Cor(0.3, -0.3, -0.3),
                 Cor(0.3, -0.3, 0.3),
                 Cor(-0.3, -0.3, 0.3),
                 Rgb_to_float(180, 255, 0));

    draw_polygon(Cor(0.3, -0.3, 0.3),
                 Cor(-0.3, -0.3, 0.3),
                 Cor(-0.3, 0.3, 0.3),
                 Cor(0.3, 0.3, 0.3),
                 Rgb_to_float(255, 255, 255));


}

void draw_Cube() {
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    glTranslatef(circleRadius, 0.f, 0.f);
    draw_polygons();
    auxiliaryLines();
    glFlush();
    glutSwapBuffers();
}

void draw_Teapot() {
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    glTranslatef(circleRadius, 0.f, 0.f);

    glPushMatrix();
    glColor3d(1.0, 0.0, 1.0);
    glutSolidTeapot(0.5);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();

}

int previousValue;




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
    glutAddMenuEntry("Teapot", 5);
    glutAddMenuEntry("Cube", 6);
    glutAddMenuEntry("Octahedron", 7);

    rotate_submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("OX", 10);
    glutAddMenuEntry("OY", 11);
    glutAddMenuEntry("OZ", 12);
    glutAddMenuEntry("Start/Stop", 13);
    glutAddMenuEntry("slower", 14);
    glutAddMenuEntry("faster", 15);
    glutAddMenuEntry("reset", 16);
    glutAddMenuEntry("small circle", 18);
    glutAddMenuEntry("big circle", 19);

    typeSubmenuId = glutCreateMenu(menu);
    glutAddMenuEntry("Strip/Polygon", 17);
    glutAddMenuEntry("OneColor/MultipleColor", 20);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddSubMenu("Rotate", rotate_submenu_id);
    glutAddSubMenu("Type", typeSubmenuId);
    glutAddMenuEntry("Quit", 0);
    glutAddMenuEntry("TESTTTTTTTTT", 21);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// k
#define FREEGLUT_STATIC
const size_t arraySize = 512;
const size_t checkSize = 1;
GLubyte Checker[arraySize][arraySize][3];
const GLubyte GLubyte_MAX = 255;


constexpr GLubyte getColor(unsigned bytecolor, unsigned checkSize, unsigned x, unsigned y) {
    switch (bytecolor) {
        case 0:
            return (x / checkSize + y / checkSize) % 2 == 0 ? GLubyte_MAX : 0;
        case 2:
            return (x / checkSize + y / checkSize) % 2 == 1 ? GLubyte_MAX : 0;
        default:
            return 0;
    }
}

void fillChecker(GLubyte arr[arraySize][arraySize][3], unsigned checkSize) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; j++) {
            for (int byteColor = 0; byteColor < 3; ++byteColor) {
                arr[i][j][byteColor] = getColor(2, checkSize, i, j);
            }
        }
    }
}

GLuint glInitTexture() {
    GLuint t = 0;

    glGenTextures(1, &t);
    glBindTexture(GL_TEXTURE_2D, t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  // (Actually, this one is the default)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, arraySize, arraySize, 0, GL_RGB, GL_UNSIGNED_BYTE, Checker);
    return t;
}

void drawImage(GLuint file,
               float x,
               float y,
               float w,
               float h,
               float angle) {
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);

    glBindTexture(GL_TEXTURE_2D, file);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x, y, 0.0f);
    glTexCoord2f(0.0, 6.0 / arraySize);
    glVertex3f(x, y + h, 0.0f);
    glTexCoord2f(6.0 / arraySize, 6.0 / arraySize);
    glVertex3f(x + w, y + h, 0.0f);
    glTexCoord2f(6.0 / arraySize, 0.0);
    glVertex3f(x + w, y, 0.0f);
    glEnd();

    glPopMatrix();
}


void render() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    const double w = glutGet(GLUT_WINDOW_WIDTH);
    const double h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(45.0, w / h, 0.1, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -15);

    drawImage(texture, 0.0f, 0.0f, 5.0f, 5.0f, 0.0);

    glutSwapBuffers();
}

void display() { /* funkcja wyświetlania, czyści bufor okna i bufor głębi, braca sześcian, rysuje i podmienia bufory */
    glFlush();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // NOLINT(hicpp-signed-bitwise)
    glPushMatrix();
    glLoadIdentity();

    switch (value) {
        case 0: {
            exit(0);
        }
        case 1: {
            glFlush();
            glPushMatrix();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // NOLINT(hicpp-signed-bitwise)
            glFlush();
            glutSwapBuffers();
        }
            break;
        case 5: {
            draw_Teapot();
            previousValue = 5;
        }
            break;
        case 6: {
            draw_Cube();
            previousValue = 6;
        }
            break;
        case 7: {
            draw_octahedron();
            previousValue = 7;
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
//            reset
            for (int i = 0; i <= 3; i++)
                theta[i] = 0;
            circleRadius = 0.f;
            value = previousValue;
        }
            break;
        case 17: {
            if (isStrip) isStrip = false;
            else isStrip = true;
            value = previousValue;
        }
            break;
        case 18: {
            circleRadius = 0.4f;
            value = previousValue;
        }
            break;
        case 19: {
            circleRadius = 0.8f;
            value = previousValue;
        }
            break;
        case 20: {
            if (isMultipleColor) isMultipleColor = false;
            else isMultipleColor = true;
            value = previousValue;
        }
            break;
        case 21: {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glEnable(GL_DEPTH_TEST);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            const double w = glutGet(GLUT_WINDOW_WIDTH);
            const double h = glutGet(GLUT_WINDOW_HEIGHT);
            gluPerspective(45.0, w / h, 0.1, 1000.0);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(0, 0, -15);

            drawImage(texture, 0.0f, 0.0f, 5.0f, 5.0f, 0.0);

            glutSwapBuffers();
            previousValue = value;

        }
            break;
        default: {
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

int main(int argc, char **argv) {
    fillChecker(Checker, checkSize);
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // NOLINT(hicpp-signed-bitwise)
    glutInitWindowSize(600, 600);
    glutCreateWindow("Szescian");
    texture = glInitTexture();

    createMenu();
    glutReshapeFunc(myReshape);

    glutDisplayFunc(render);
//    glutDisplayFunc(display);


    glutIdleFunc(spinCube);

    glEnable(GL_DEPTH_TEST);
    tak();
    glutMainLoop();
    return 0;
}