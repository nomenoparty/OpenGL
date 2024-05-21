#include <GL/glut.h>
#include <cmath>
#include <iostream>

float angle = 0.0f;

struct Vector3 {
    float x, y, z;

    Vector3 operator+(const Vector3& v) const { return {x + v.x, y + v.y, z + v.z}; }
    Vector3 operator-(const Vector3& v) const { return {x - v.x, y - v.y, z - v.z}; }
    Vector3 operator*(float scalar) const { return {x * scalar, y * scalar, z * scalar}; }
    Vector3 operator/(float scalar) const { return {x / scalar, y / scalar, z / scalar}; }
    float dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vector3 cross(const Vector3& v) const { return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x}; }
    float magnitude() const { return std::sqrt(x * x + y * y + z * z); }
    Vector3 normalize() const { return *this / magnitude(); }
};

Vector3 symmetricOverLine(Vector3 A, Vector3 P, Vector3 Q) {
    Vector3 d = Q - P;
    float t = (A - P).dot(d) / d.dot(d);
    Vector3 H = P + d * t;
    return H * 2 - A;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(2.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angle, 1.0, 1.0, 0.0);

    Vector3 P = {0.0f, 0.0f, 0.0f};
    Vector3 Q = {1.0f, 1.0f, 0.5f};
    Vector3 A = {0.0f, 1.0f, 0.0f};
    Vector3 A_symmetric = symmetricOverLine(A, P, Q);

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(P.x, P.y, P.z); // P
        glVertex3f(Q.x, Q.y, Q.z); // Q
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(A.x, A.y, A.z); // A
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(A_symmetric.x, A_symmetric.y, A_symmetric.z); // A'
    glEnd();

    // Draw line PQ
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(P.x, P.y, P.z);
        glVertex3f(Q.x, Q.y, Q.z);
    glEnd();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        angle -= 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        angle += 5.0f;
        break;
    }
    glutPostRedisplay(); // Yêu cầu vẽ lại màn hình
}

void initOpenGL() {
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Doi xung qua duong thang");
    initOpenGL();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}