//
//  main.cpp
//  Brazo
//
//  Created by Maria  Roque on 02/10/12.
//  Copyright (c) 2012 Tecnol�gico de Monterrey. All rights reserved.
//

/*
 *
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  pressing the s and e keys (shoulder and elbow)
 * alters the rotation of the robot arm.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


static int shoulder = 0, elbow = 0, hand = 0;

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef (-1.0, 0.0, 0.0);
        glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef (2.0, 0.4, 1.0);
            glutWireCube (1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslatef (1.0, 0.0, 0.0);
            glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
            glTranslatef (1.0, 0.0, 0.0);

            glPushMatrix();
                glScalef (2.0, 0.4, 1.0);
                glutWireCube (1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef (1.0, 0.0, 0.0);
                glRotatef ((GLfloat) hand, 0.0, 0.0, 1.0);
                glTranslatef (0.5, 0.0, 0.0);

                glPushMatrix();
                    glScalef (1.0, 0.4, 1.0);
                    glutWireCube (1.0);
                glPopMatrix();

                glPushMatrix();
                //dedos y asi
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 's':   /*  s key rotates at shoulder  */
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':  /*  e key rotates at elbow  */
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case 'x':
            hand = (hand + 5) % 360;
            glutPostRedisplay();
            break;
        case 'c':
            hand = (hand - 5) % 360;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
