#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <GL/glut.h>
#include <iostream>
#include <Windows.h>
#include <math.h>

void DrawScene(void);

/* Funkcja do inicjacji OpenGLa */
void InitOpenGL(void);

/* Funkcja wywo�ywana w momentach zmiany rozmiar�w okna */
void ReshapeWindow(int width, int height);

/* Deklaracja globalnych zmiennych */

/* Globalny identyfikator g��wnego okna programu */
int mainWindow;

void drawQUADS(float a, float corx, float cory);

float myrand();


/* Funkcja main */
int main(int argc, char **argv) {
    srand(time(NULL));
    glutInit(&argc, argv);                                // Inicjujemy bibliotek� GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);          // Inicjujemy: format koloru, jeden bufor ramki
    glutInitWindowSize(800, 800);                       // Ustawiamy pocz�tkowe wymiary okna
    glutInitWindowPosition(100, 100);                      // Ustawiamy pozycj� okna - lewy g�rny naroznik
    mainWindow = glutCreateWindow("Dywan Sierpi�skiego"); // Tworzymy g��wne okno program

    if (mainWindow == 0)                                   // Sprawdzamy powodzenie operacji
    {
        puts("Nie mozna stworzyc okna!!!\nWyjscie z programu.\n");
        exit(-1);
    }

    glutSetWindow(mainWindow);                            // Czynimy aktywnym okno g��wne programu

    glutDisplayFunc(DrawScene);

    glutReshapeFunc(ReshapeWindow);

    InitOpenGL();                                         // ustawienia pocz�tkowe
    glutMainLoop();                                       // Wej�cie do p�tli programu

    return (0);
}

void DrawScene(void) {
    float a = 180, b;
    // Czy�cimy okno aktualnym (domy�lnym) kolorem
    glClear(GL_COLOR_BUFFER_BIT);
    // Ustawiamy grubo�� linii
    glLineWidth(5.0f);

    float tabx[9] = {0, 0, a / 3, a / 3, a / 3, 0, -a / 3, -a / 3, -a / 3};
    float taby[9] = {0, a / 3, a / 3, 0, -a / 3, -a / 3, -a / 3, 0, a / 3};
    //Poczatkowy
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawQUADS(a, 0, 0);
    glFlush();
    //Sleep(1000);

//1
    {
        for (int i = 0; i < 9; i++) {
            glColor3f(myrand() / 100, myrand() / 100, myrand() / 100);
            drawQUADS(a / pow(3, 1), tabx[i], taby[i]);
        }
        glFlush();
        Sleep(1000);
        //czyszczenie
        glColor3f(1.0f, 1.0f, 1.0f);
        drawQUADS(a / pow(3, 1), 0, 0);

        glFlush();
        //Sleep(1000);
    }
    //2
    {
        for (int j = 1; j < 9; j++) {
            for (int i = 1; i < 9; i++) {
                glColor3f(myrand() / 100, myrand() / 100, myrand() / 100);
                drawQUADS(a / pow(3, 2), tabx[i] + tabx[j] / 3, taby[i] + taby[j] / 3);
            }
        }
        glFlush();
        Sleep(1000);
        //czyszczenie
        for (int j = 1; j < 9; j++) {
            glColor3f(1.0f, 1.0f, 1.0f);
            drawQUADS(a / pow(3, 2), tabx[j], taby[j]);
        }
        glFlush();
        Sleep(1000);
    }
    //3
    {
        for (int k = 1; k < 9; k++) {
            for (int j = 1; j < 9; j++) {
                for (int i = 1; i < 9; i++) {
                    glColor3f(myrand() / 100, myrand() / 100, myrand() / 100);
                    drawQUADS(a / pow(3, 3), tabx[i] + tabx[j] / 3 + tabx[k] / 3 / 3,
                              taby[i] + taby[j] / 3 + taby[k] / 3 / 3);
                }
            }
        }
        glFlush();
        Sleep(1000);
        //czyszczenie
        for (int j = 1; j < 9; j++) {
            for (int i = 1; i < 9; i++) {
                glColor3f(1.f, 1.f, 1.f);
                drawQUADS(a / pow(3, 3), tabx[i] + tabx[j] / 3, taby[i] + taby[j] / 3);
            }
        }
        glFlush();
        //Sleep(1000);
    }
    //4
    {
        for (int l = 1; l < 9; l++) {
            for (int k = 1; k < 9; k++) {
                for (int j = 1; j < 9; j++) {
                    for (int i = 1; i < 9; i++) {
                        glColor3f(myrand() / 100, myrand() / 100, myrand() / 100);
                        drawQUADS(a / pow(3, 4), tabx[i] + tabx[j] / 3 + tabx[k] / 3 / 3 + tabx[l] / 3 / 3 / 3,
                                  taby[i] + taby[j] / 3 + taby[k] / 3 / 3 + taby[l] / 3 / 3 / 3);
                    }
                }
            }
        }
        glFlush();
        Sleep(1000);
        //czyszczenie
        for (int k = 1; k < 9; k++) {
            for (int j = 1; j < 9; j++) {
                for (int i = 1; i < 9; i++) {
                    glColor3f(1.f, 1.f, 1.f);
                    drawQUADS(a / pow(3, 4), tabx[i] + tabx[j] / 3 + tabx[k] / 3 / 3,
                              taby[i] + taby[j] / 3 + taby[k] / 3 / 3);
                }
            }
        }
        glFlush();
        Sleep(1000);
    }
    //5
    for (int m = 1; m < 9; m++) {
        for (int l = 1; l < 9; l++) {
            for (int k = 1; k < 9; k++) {
                for (int j = 1; j < 9; j++) {
                    for (int i = 1; i < 9; i++) {
                        glColor3f(myrand() / 100, myrand() / 100, myrand() / 100);
                        drawQUADS(a / pow(3, 5), tabx[i] + tabx[j] / 3 + tabx[k] / 3 / 3 + tabx[l] / 3 / 3 / 3 +
                                                 tabx[m] / 3 / 3 / 3 / 3,
                                  taby[i] + taby[j] / 3 + taby[k] / 3 / 3 + taby[l] / 3 / 3 / 3 +
                                  taby[m] / 3 / 3 / 3 / 3);
                    }
                }
            }
        }
    }
    glFlush();
    Sleep(1000);
    //czyszczenie
    for (int l = 1; l < 9; l++) {
        for (int k = 1; k < 9; k++) {
            for (int j = 1; j < 9; j++) {
                for (int i = 1; i < 9; i++) {
                    glColor3f(1.f, 1.f, 1.f);
                    drawQUADS(a / pow(3, 5), tabx[i] + tabx[j] / 3 + tabx[k] / 3 / 3 + tabx[l] / 3 / 3 / 3,
                              taby[i] + taby[j] / 3 + taby[k] / 3 / 3 + taby[l] / 3 / 3 / 3);
                }
            }
        }
    }
    glFlush();
    Sleep(1000);

}


/* Ta funkcja s�u�y do wst�pnej konfiguracji OpenGLa.
 * Zanim co� narysujemy musimy wywo�a� t� funkcj�.
 */
void InitOpenGL(void) {
    // Usawiamy domy�lny, czarny kolor t�a okna - bufor ramki malujemy na czarno
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/* T� funkcj� wywo�uje system w momencie gdy uytkownik zmieni mysz�
 * rozmiar g�ownego okna. jej zadaniem jest zachowanie propocji wymiar�w
 * rysowanych obiekt�w niezale�nie od wymiar�w okna.
 */
void ReshapeWindow(int width, int height) {
    int aspectRatio; // = width / height

    // Na wypadek dzielenia przez 0
    if (height == 0) height = 1;

    // Wyliczamy wsp�czynnik proporcji
    aspectRatio = width / height;

    // Ustawiamy wielko�ci okna okna urz�dzenia w zakresie
    // od 0,0 do wysoko��, szeroko��
    glViewport(0, 0, width, height);

    // Ustawiamy uk�ad wsp�rz�dnych obserwatora
    glMatrixMode(GL_PROJECTION);

    // Resetujemy macierz projkecji
    glLoadIdentity();

    // Korekta
    if (width <= height)
        glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
    else
        glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

    // Ustawiamy macierz modelu
    glMatrixMode(GL_MODELVIEW);

    // Resetujemy macierz modelu
    glLoadIdentity();

}

void drawQUADS(float a, float corx, float cory) {
    glBegin(GL_QUADS);
    glVertex2f(-a / 2 + corx, -a / 2 + cory);
    glVertex2f(a / 2 + corx, -a / 2 + cory);
    //itd
    glVertex2f(a / 2 + corx, -a / 2 + cory);
    glVertex2f(a / 2 + corx, a / 2 + cory);

    glVertex2f(a / 2 + corx, a / 2 + cory);
    glVertex2f(-a / 2 + corx, a / 2 + cory);

    glVertex2f(-a / 2 + corx, a / 2 + cory);
    glVertex2f(-a / 2 + corx, -a / 2 + cory);
    glEnd();
}

float myrand() {
    return rand() / 255;
}


