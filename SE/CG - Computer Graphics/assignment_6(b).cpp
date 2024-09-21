/*Write C++ program to draw 3-D
cube and perform following
transformations on it using OpenGL
a) Scaling b) Translation c)Rotation
about an axis (x/y/z)*/
#define GLUT_DISABLE_ATEXIT_HACK
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>
#include<windows.h>
#endif

#include <stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
typedef float Matrix4[4][4];

Matrix4 theMatrix;
static GLfloat input[8][3]=
{
        {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},{30,30,0},{80,30,0},{80,80,0},{30,80,0}
};

float output[8][3];
float tx,ty,tz;
float sx,sy,sz;
float angle;
int ch,rotch;

void setIdentityM(Matrix4 m)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            m[i][j] = (i==j);
        }
    }
}
void translate(float tx,float ty, float tz)
{
    for (int i = 0;i<8;i++)
    {
        output[i][0] = input[i][0] + tx;
        output[i][1] = input[i][1] + ty;
        output[i][2] = input[i][2] + tz;
    }
}
void scale(float sx,float sy, float sz)
{
    theMatrix[0][0] = sx;
    theMatrix[1][1] = sy;
    theMatrix[2][2] = sz;
}
void RotateX(float angle)
{
    angle = (angle*3.14 )/ 180;
    theMatrix[1][1] = cos(angle);
    theMatrix[1][2] = sin(angle);
    theMatrix[2][1] = -sin(angle);
    theMatrix[2][2] = cos(angle);
}
void RotateY(float angle)
{
    angle = (angle*3.14 )/ 180;
    theMatrix[0][0] = cos(angle);
    theMatrix[0][2] = -sin(angle);
    theMatrix[2][0] = sin(angle);
    theMatrix[2][2] = cos(angle);
}
void RotateZ(float angle)
{
    angle = (angle*3.14 )/ 180;
    theMatrix[0][0] = cos(angle);
    theMatrix[0][1] = -sin(angle);
    theMatrix[1][0] = sin(angle);
    theMatrix[1][1] = cos(angle);
}
void MultiplyM()
{
    for(int i = 0;i<8;i++)
    {
        for(int j = 0;j<3;j++)
        {
            output[i][j] = 0;
            for(int k = 0;k<3;k++)
            {
                output[i][j] = output[i][j] + input[i][k]*theMatrix[k][j];
            }
        }
    }
}
void Axes(void)
{
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2i(1000,0);
    glVertex2i(1000,0);
    glEnd();
    glVertex2i(0,1000);
    glVertex2i(0,1000);
    glEnd();
}
void draw(float a[8][3])
{
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3fv(a[0]);//behind
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3fv(a[0]);//bottom
    glVertex3fv(a[1]);
    glVertex3fv(a[4]);
    glVertex3fv(a[5]);


    glColor3f(0.0f,0.0f,1.0f);
    glVertex3fv(a[0]);//left
    glVertex3fv(a[4]);
    glVertex3fv(a[3]);
    glVertex3fv(a[7]);

    glColor3f(1.0f,1.0f,0.0f);
    glVertex3fv(a[1]);//right
    glVertex3fv(a[5]);
    glVertex3fv(a[6]);
    glVertex3fv(a[2]);


    glColor3f(1.0f,0.0f,1.0f);
    glVertex3fv(a[2]);//top
    glVertex3fv(a[3]);
    glVertex3fv(a[7]);
    glVertex3fv(a[6]);


    glColor3f(0.0f,1.0f,1.0f);
    glVertex3fv(a[4]);//front
    glVertex3fv(a[5]);
    glVertex3fv(a[6]);
    glVertex3fv(a[7]);
    glEnd();
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    Axes();
    glColor3f(1.0,1.0,1.0);
    draw(input);
    setIdentityM(theMatrix);
    switch(ch)
    {
    case 1:
        translate(tx,ty,tz);
        break;
    case 2:
        scale(sx,sy,sz);
        MultiplyM();
        break;
    case 3:
        switch(rotch)
        {
        case 1:
            RotateX(angle);
            break;
        case 2:
            RotateY(angle);
            break;
        case 3:
            RotateZ(angle);
            break;
        default:
            break;
        }
        MultiplyM();
        break;
    }
    draw(output);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1000,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("3-D TRANSFORMATIONS");
    init();
    cout<<"-------Menu------"<<endl;
    cout<<"1. Translation."<<endl;
    cout<<"2. Scaling."<<endl;
    cout<<"3. Rotation."<<endl;
    cout<<"4. Exit."<<endl;
    cout<<"Enter Your Choice:"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter Tx, Ty, Tz: "<<endl;
        cin>>tx;
        cin>>ty;
        cin>>tz;
        break;
    case 2:
        cout<<"Enter Sx ,Sy ,Sz"<<endl;
        cin>>sx;
        cin>>sy;
        cin>>sz;
        break;
    case 3:
        cout<<"1. Parallel to X - axis (y-z plane)"<<endl;
        cout<<"2. Parallel to Y - axis (x-z plane)"<<endl;
        cout<<"3. Parallel to Z - axis (x-y plane)"<<endl;
        cout<<"Enter Choice:"<<endl;
        cin>>rotch;
        switch(rotch)
        {
        case 1:
            cout<<"Enter Rotation Angle: "<<endl;
            cin>>angle;
            break;
        case 2:
            cout<<"Enter Rotation Angle: "<<endl;
            cin>>angle;
            break;
        case 3:
            cout<<"Enter Rotation Angle: "<<endl;
            cin>>angle;
            break;
        default:
            break;
        }
        break;
        case 4:
            exit(0);
        default:
            break;
    }
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
