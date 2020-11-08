// OpengGL3d.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define FREEGLUT_STATIC
#include <GL/glut.h>
const size_t arraySize = 512;
const size_t checkSize = 1;
GLubyte Checker[arraySize][arraySize][3];
const GLubyte GLubyte_MAX = 255;

constexpr GLubyte getColor(unsigned bytecolor,unsigned checkSize, unsigned x, unsigned y) {
    switch (bytecolor)
    {
        case 0: return (x / checkSize + y / checkSize) % 2 == 0 ? GLubyte_MAX : 0;
        case 2: return (x / checkSize + y / checkSize) % 2 == 1 ? GLubyte_MAX : 0;
        default: return 0;
    }
}
void fillChecker(GLubyte arr[arraySize][arraySize][3], unsigned checkSize) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; j++) {
            for (int byteColor = 0; byteColor < 3; ++byteColor) {
                arr[i][j][byteColor] = getColor(byteColor, checkSize, i, j);
            }
        }
    }
}

GLuint glInitTexture()
{
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
               float angle)
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);

    glBindTexture(GL_TEXTURE_2D, file);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(x, y, 0.0f);
    glTexCoord2f(0.0, 6.0 / arraySize); glVertex3f(x, y + h, 0.0f);
    glTexCoord2f(6.0/ arraySize, 6.0 / arraySize); glVertex3f(x + w, y + h, 0.0f);
    glTexCoord2f(6.0 / arraySize, 0.0); glVertex3f(x + w, y, 0.0f);
    glEnd();

    glPopMatrix();
}

GLuint texture;
void render()
{
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

    drawImage(texture, 0.0f, 0.0f, 4.0f, 4.0f, 0.0);

    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    fillChecker(Checker, checkSize);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Applying Textures");
    glutDisplayFunc(render);

    texture = glInitTexture();

    glutMainLoop();
    return 0;
}