#include <GL/glut.h>


double rotate_y=0;
double rotate_x=0;
double sizeCell = 0.5/10;
double  stepCell = 0.1; //шаг при определении
double quantityCell = 0.8; //количестве кубиков
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    for (float i = 0; i < quantityCell; i+=stepCell)
    {
        for (float j = 0; j < quantityCell; j+=stepCell)
        {
            for (float y = 0; y < quantityCell; y+=stepCell)
            {
                glBegin(GL_POLYGON);
                glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( sizeCell + i, -sizeCell + j, sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  -sizeCell + i, -sizeCell + j, sizeCell + y);
                glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  -sizeCell + i,  sizeCell + j, sizeCell + y);
                glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  sizeCell + i, sizeCell + j, sizeCell + y);
                glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i,  sizeCell + j, -sizeCell + y);
                glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i, sizeCell + j, sizeCell + y);
                glEnd();

                glBegin(GL_POLYGON);
                glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  sizeCell + i, -sizeCell + j, -sizeCell + y);
                glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  sizeCell + i,  -sizeCell + j, sizeCell + y);
                glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i,  -sizeCell + j, sizeCell + y);
                glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -sizeCell + i, -sizeCell + j, -sizeCell + y);
                glEnd();
            }
        }
    }


    glFlush();
    glutSwapBuffers();
}

void specialKeys( int key, int x, int y) {

    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;

        //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    //  Request display update
    glutPostRedisplay();

}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Awesome Cube");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;

}