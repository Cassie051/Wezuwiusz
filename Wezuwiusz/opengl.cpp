#include "opengl.h"

OpenGL::OpenGL(QWidget *parent)
    :QOpenGLWidget {parent}
{

}

void OpenGL::initializeGL(){
    float r, g, b, a = 1.0f;
    initializeOpenGLFunctions();
    qColorToRGB(Qt::black, r, g, b);
    glClearColor(r, g, b, a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}
void OpenGL::paintGL(){

    float r, g, b;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINES);
    qColorToRGB(Qt::red, r, g ,b);
    glColor3f(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    qColorToRGB(Qt::green, r, g ,b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    qColorToRGB(Qt::blue, r, g ,b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

}
void OpenGL::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void OpenGL::qColorToRGB(const QColor &C, float &r, float &g, float &b){

    r = normalize_0_1(C.red(),1.0f,255.0f);
    g = normalize_0_1(C.green(),1.0f,255.0f);
    b = normalize_0_1(C.blue(),1.0f,255.0f);
}

float OpenGL::normalize_0_1(float val, float min, float max) const
{
    return (val - min)/(max-min);
}
