//#include <GL/glut.h>
//#include <cmath>
//
//struct Vector3D {
//    float x, y, z;
//};
//
//Vector3D crossProduct(Vector3D v1, Vector3D v2) {
//    Vector3D cross;
//    cross.x = v1.y * v2.z - v1.z * v2.y;
//    cross.y = v1.z * v2.x - v1.x * v2.z;
//    cross.z = v1.x * v2.y - v1.y * v2.x;
//    return cross;
//}
//
//float angle1 = 0.0;
//float angle2 = 0.0;
//int width = 800, height = 600;
//
//void setupProjection() {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, (double)width / height, 1.0, 200.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void setupView() {
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 5.0,
//        0.0, 0.0, 0.0,
//        0.0, 1.0, 0.0);
//}
//
//void specialKeys(int key, int x, int y) {
//    switch (key) {
//    case GLUT_KEY_LEFT:
//        angle1 -= 5.0f;
//        break;
//    case GLUT_KEY_RIGHT:
//        angle1 += 5.0f;
//        break;
//    case GLUT_KEY_UP:
//        angle2 -= 5.0f;
//        break;
//    case GLUT_KEY_DOWN:
//        angle2 += 5.0f;
//        break;
//    }
//    glutPostRedisplay(); // Yêu cầu vẽ lại màn hình
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    setupView();
//    glRotatef(angle1, 1.0, 1.0, 1.0);
//    glRotatef(angle2, 1.0, 1.0, 0.0);
//
//    // Tọa độ các điểm P, Q, K và A
//    float x1 = 0.0f, y1 = 0.0f, z1 = 0.0f;
//    float x2 = -1.0f, y2 = 0.0f, z2 = 0.5f;
//    float x3 = 1.0f, y3 = 1.0f, z3 = 1.0f;
//    float x0 = 0.0f, y0 = 0.5f, z0 = 0.0f;
//    Vector3D PQ = { x2 - x1, y2 - y1, z2 - z1 };
//    Vector3D PK = { x3 - x1, y3 - y1, z3 - z1 };
//    Vector3D N = crossProduct(PQ, PK);
//    float A = N.x, B = N.y, C = N.z;
//    float D = -(A * x1 + B * y1 + C * z1);
//
//    float d = (A * x0 + B * y0 + C * z0 + D) / (A * A + B * B + C * C);
//    float x_sym = x0 - 2 * A * d;
//    float y_sym = y0 - 2 * B * d;
//    float z_sym = z0 - 2 * C * d;
//
//    // Vẽ điểm A
//    glPointSize(5.0);
//    glColor3f(1.0, 0.0, 0.0); // Màu đỏ
//    glBegin(GL_POINTS);
//    glVertex3f(x0, y0, z0);
//    glEnd();
//
//    // Vẽ điểm đối xứng của A
//    glColor3f(0.0, 1.0, 0.0); // Màu xanh
//    glBegin(GL_POINTS);
//    glVertex3f(x_sym, y_sym, z_sym);
//    glEnd();
//
//    // Vẽ mặt phẳng
//    glColor3f(0.0, 0.0, 1.0); // Màu xanh dương
//    glBegin(GL_TRIANGLES);
//    glVertex3f(x1, y1, z1);
//    glVertex3f(x2, y2, z2);
//    glVertex3f(x3, y3, z3);
//    glEnd();
//
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("3D Symmetry Visualization");
//
//    glEnable(GL_DEPTH_TEST);
//
//    glutDisplayFunc(display);
//    glutSpecialFunc(specialKeys);
//
//    setupProjection();
//
//    glutMainLoop();
//    return 0;
//}
