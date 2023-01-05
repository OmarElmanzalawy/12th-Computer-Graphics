



#include <GL/glut.h>

#include <stdlib.h>

#include <math.h>




float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;


void init(){
    glClearColor(0.0 , 0.0 , 0.0 , 1.0);
    glEnable(GL_DEPTH_TEST);

}
//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------
float angle = 0.0;
float step=0; // change x
float step2=0; // change y
float step3 = 0; // change z
float zz = 0 ;
float xx=0 , yy=0 ;
float r = 1 , g = 1 , b = 1;


//sound function (doesn't work)
//using namespace irrklang;

//ISoundEngine *SoundEngine = createIrrKlangDevice();

//void sound::Init()
//{
    //[...]
    //SoundEngine->play2D("audio/engine.mp3", true);
//}




//UPPER CAR PART
void upperCar(){
    glBegin (GL_QUADS) ;
    //FRONT
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-1.0+step,2.0+step2,1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,1.0+step3);
    glVertex3f(1.5+step,1.0+step2,1.0+step3);
    glVertex3f(1.0+step,2.0+step2,1.0+step3);

    //BACK
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0+step,2.0+step2,-1.0+step3);
    glVertex3f(1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(-1.0+step,2.0+step2,-1.0+step3);
    //RIGHT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0+step,2.0+step2,1.0+step3);
    glVertex3f(1.5+step,1.0+step2,1.0+step3);
    glVertex3f(1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(1.0+step,2.0+step2,-1.0+step3);
    //LEFT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-1.0+step,2.0+step2,-1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,1.0+step3);
    glVertex3f(-1.0+step,2.0+step2,1.0+step3);
    //TOP
    glColor3f(0.0,1.0,1.0);
    glVertex3f (-1.0+step,2.0+step2,-1.0+step3);
    glVertex3f(-1.0+step,2.0+step2,1.0+step3);
    glVertex3f(1.0+step,2.0+step2,1.0+step3);
    glVertex3f(1.0+step,2.0+step2,-1.0+step3);

    glEnd();





}
//LOWER CAR PART
void lowerCar(){
    glBegin (GL_QUADS) ;
    //FRONT
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0+step,1.0+step2,1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,1.0+step2,1.0+step3);
    //BACK
    glColor3f(0.0,1.0,0.0);
    glVertex3f(3.0+step,1.0+step2,-1.0+step3);
    glVertex3f(3.0+step,0.0+step2,-1.0+step3);
    glVertex3f (-3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,1.0+step2,-1.0+step3);
    //RIGHT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(3.0+step,1.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(3.0+step,1.0+step2,-1.0+step3);
    //LEFT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-3.0+step,1.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,1.0+step3);
    glVertex3f(-3.0+step,1.0+step2,1.0+step3);
    //TOP
    glColor3f(0.0,1.0,1.0);
    glVertex3f (-3.0+step,1.0+step2,-1.0+step3);
    glVertex3f (-3.0+step,1.0+step2,1.0+step3);
    glVertex3f(3.0+step,1.0+step2,1.0+step3);
    glVertex3f(3.0+step,1.0+step2,-1.0+step3);
    //BOTTOM
    glColor3f(1.0,0.0,1.0);
    glVertex3f (-3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,-1.0+step3);

    glEnd();

}
void car()
{
    glTranslatef    (0 +xx , -4, -18);
    glRotatef(90 , 0.0  , 1.0  , 0.0 );
    glRotatef(70 , 0.0 , 0.0, 1.0 );
    lowerCar();
    upperCar();

}

//Function isn't used
void road(){
    glTranslatef(0,-4,-18);
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(-5  , -2 , 1.0 );
    glVertex3f(5 , 2.5 , 1.0 );
    glEnd();
    glColor3f(1, 1.0, 1.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(-5  , -4.5 , 1.0 );
    glVertex3f(5 , 0.5 , 1.0 );
    glEnd();


}

void planet1() {
    glPushMatrix();
    glTranslatef(0,4-yy,-18 );

    //glColor3f(1, 0.5, 0); // Red color used to draw.
    glColor3f(0.25, 0.25, 0.25);
    // changing in transformation matrix.
    // rotation about X axis

    glRotatef(yRotated, 0, 1, 0);
    glScalef(1,1,1); // scaling transfomation
    // NOTE: built-in (glut library) function , draw you a sphere.
    glutSolidSphere(2,20,19);



    glPopMatrix();

}


void cube(){
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(-6, 2-yy, -18);
    glRotatef(yRotated , 0.0  , 1.0  , 0.0 );
    glRotatef(xRotated , 1.0 , 0.0, 0.0 );
    glutSolidCube(1.3);
    glPopMatrix();

}

void cube2(){
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(-5, 9-yy, -15);
    glRotatef(yRotated , 0.0  , 1.0  , 0.0 );
    glRotatef(xRotated , 1.0 , 0.0, 0.0 );
    glutSolidCube(1.3);
    glPopMatrix();

}

void cube3(){
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(2, 9-yy, -15);
    glRotatef(yRotated , 0.0  , 1.0  , 0.0 );
    glRotatef(xRotated , 1.0 , 0.0, 0.0 );
    glutSolidCube(1.3);
    glPopMatrix();

}

void cube4(){
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(5, 18-yy, -15);
    glRotatef(yRotated , 0.0  , 1.0  , 0.0 );
    glRotatef(xRotated , 1.0 , 0.0, 0.0 );
    glutSolidCube(1.3);
    glPopMatrix();
}

void planet2() {
    glPushMatrix();
    glTranslatef(0,22-yy,-18 );

    glColor3f(0.25, 0.25, 0.25);
    // changing in transformation matrix.
    // rotation about X axis

    //glRotatef(yRotated,0.0,1,0.0);
    // rotation about Z axis
    //glRotatef(zRotated,0.0,0.0,1.0);
    glRotatef(yRotated, 0, 1, 0);
    glScalef(1,1,1); // scaling transfomation
    // NOTE: built-in (glut library) function , draw you a sphere.
    glutSolidSphere(2,20,19);



    glPopMatrix();

}

void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    //road();
    //glTranslatef(0, 0, 0);
    planet1();
    cube();
    cube2();
    cube3();
    cube4();
    planet2();
    car();
    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

void processNormalKeys(unsigned char key, int x, int y) {

    if (key == 27)
        exit(0);
}
void processSpecialKeys(int key, int x, int y) {

    switch(key) {
        case GLUT_KEY_UP: //up button pressed
            yy += 1;
            break;
        case GLUT_KEY_DOWN:
            yy -= 1;
                break;
        case GLUT_KEY_RIGHT:
            xx += 1;
                break;
        case GLUT_KEY_LEFT:
            xx -= 1;
                break;
    }
}




//----------------------------------  TIme  ------------------------------------


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/30,timer,0);
    xRotated += 5;
    yRotated += 5;




}
//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // buffer mode
    glutInitWindowSize     (1080, 1020);
    glutInitWindowPosition (0, 0);
    glutCreateWindow       ("Omar Elmanzalawy - 20100221");
    init();
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutTimerFunc(1000, timer, 0);

    glutIdleFunc    (idleFunc);

    glClearColor(0,0,0,1);
    texture(); // Lighting and textures function


    glutMainLoop();
}
