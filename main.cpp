// bench_glut.cpp
// Compile with: -lglut -lGLU -lGL -lm

#include <GL/glut.h>

void drawBench() {
    // --- Bench seat ---
    glColor3f(0.55f, 0.27f, 0.07f); // brown wood
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, -0.1f);
        glVertex2f( 0.6f, -0.1f);
        glVertex2f( 0.6f,  0.05f);
        glVertex2f(-0.6f,  0.05f);
    glEnd();

    // --- Seat slats (lines to show wooden planks) ---
    glColor3f(0.4f, 0.2f, 0.05f);
    glLineWidth(2);
    glBegin(GL_LINES);
        for (float x = -0.55f; x <= 0.55f; x += 0.15f) {
            glVertex2f(x, -0.1f);
            glVertex2f(x, 0.05f);
        }
    glEnd();

    // --- Bench backrest ---
    glColor3f(0.5f, 0.25f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.05f);
        glVertex2f( 0.6f, 0.05f);
        glVertex2f( 0.6f, 0.3f);
        glVertex2f(-0.6f, 0.3f);
    glEnd();

    // --- Backrest slats ---
    glColor3f(0.35f, 0.18f, 0.05f);
    glLineWidth(2);
    glBegin(GL_LINES);
        for (float y = 0.08f; y <= 0.28f; y += 0.07f) {
            glVertex2f(-0.6f, y);
            glVertex2f( 0.6f, y);
        }
    glEnd();

    // --- Left leg ---
    glColor3f(0.3f, 0.15f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.1f);
        glVertex2f(-0.45f, -0.1f);
        glVertex2f(-0.45f, -0.4f);
        glVertex2f(-0.5f, -0.4f);
    glEnd();

    // --- Right leg ---
    glBegin(GL_QUADS);
        glVertex2f(0.45f, -0.1f);
        glVertex2f(0.5f, -0.1f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.45f, -0.4f);
    glEnd();

    // --- Middle support ---
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.1f);
        glVertex2f( 0.05f, -0.1f);
        glVertex2f( 0.05f, -0.35f);
        glVertex2f(-0.05f, -0.35f);
    glEnd();
}

void display() {
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // sky blue background
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Ground ---
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    // --- Bench ---
    drawBench();

    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bench (GLUT OpenGL)");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
