#include <GL/glut.h>
#include <cstdlib>
#include <iostream>

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    switch (value) {
        case 1: {
            glClear(GL_COLOR_BUFFER_BIT);
        }
            break;
        case 2: {
            glPushMatrix();
            glColor3d(1.0, 0.0, 0.0);
            glutWireSphere(0.5, 50, 50);
            glPopMatrix();
        }
            break;
        case 3: {
            glPushMatrix();
            glColor3d(0.0, 1.0, 0.0);
            glRotated(65, -1.0, 0.0, 0.0);
            glutWireCone(0.5, 1.0, 50, 50);
            glPopMatrix();
        }
            break;
        case 4: {
            glPushMatrix();
            glColor3d(0.0, 0.0, 1.0);
            glutWireTorus(0.3, 0.6, 100, 100);
            glPopMatrix();
        }
            break;
        case 5: {
            glPushMatrix();
            glColor3d(1.0, 0.0, 1.0);
            glutSolidTeapot(0.5);
            glPopMatrix();
        }
            break;
        case 6: {
//            glutReshapeFunc(myReshape);
//            glutDisplayFunc(display);
        }
            break;
        case 10: {
            exit(0);
        }
            break;
        case 11: {
            exit(0);
        }
            break;
        case 12: {
            exit(0);
        }
            break;
        case 13: {
            exit(0);
        }
            break;

    }
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("Menus and Submenus - Programming Techniques");

    createMenu();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 1;
}