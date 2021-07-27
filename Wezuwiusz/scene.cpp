#include "scene.hh"
#include <math.h>
#include <stdlib.h> // RAND_MAX

using namespace qglviewer;
using namespace std;


float v_x = 0;
float v_y = 0;
float v_z = 0;


Viewer::Viewer(QWidget *parent) :
    QGLViewer(parent)
{

}

void Viewer::init() {
  restoreStateFromFile();
  glDisable(GL_LIGHTING);
  nbPart_ = 20000;
  volcano_ = new Volcano[nbPart_];
  mouse_ = new Mouse();
  labyrinth_ = new Labyrinth();
  glPointSize(3.0);

  setGridIsDrawn();
  setBackgroundColor(QColor(241,236,226));
}

Viewer::~Viewer()
{
    delete volcano_;
    delete mouse_;
    delete labyrinth_;
}

void Viewer::addXYZ(float x, float y, float z)
{
    v_x = x;
    v_y = y;
    v_z = z;
}

void Viewer::SetSpeed(int setspeed)
{
    animationSpeed = setspeed;
}

void Viewer::draw()
{
  glBegin(GL_POINTS);

  for (int i = 0; i < nbPart_; i++)
  volcano_[i].draw();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // glTranslatef(s_x,s_y,0.0);

 // glRotatef(alpha*180.0f/M_PI,1.0,0.0,0.0);
 // glRotatef(beta*180.0f/M_PI,0.0,1.0,0.0);


 /* **** Draw scene ***** */
  glBegin(GL_QUADS);
  // glColor3f(0.333f, 0.42f, 0.184f);     // Dark Green
  glColor3f(103/255.0, 116/255.0, 35/255.0);
  glVertex3f(GRID_SIZE, GRID_SIZE, 0.0f);
  glVertex3f(-GRID_SIZE, GRID_SIZE, 0.0f);
  glVertex3f(-GRID_SIZE, -GRID_SIZE, 0.0f);
  glVertex3f(GRID_SIZE, -GRID_SIZE, 0.0f);
  glEnd();

/* **** Draw mouse ***** */

  mouse_->draw('E');

  labyrinth_->WallsDraw();

  glFlush();

}

void Viewer::animate()
{
  for (int i = 0; i < nbPart_; i++)
    volcano_[i].animate();
}

void Viewer::start()
{
    startAnimation();
}

void Viewer::reset()
{
    delete volcano_;
    init();
}

void Viewer::pause()
{
  stopAnimation();
}


/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */


Volcano::Volcano()
{
    init();
}

Volcano::~Volcano()
{
}

void Volcano::init()
{
    pos_ = Vec(0.8+v_x, 0.8+v_y, 0);
    float angle = 2.0 * M_PI * rand() / RAND_MAX;
    float norm = 0.08 * rand() / RAND_MAX;
    speed_ = Vec(norm * cos(angle), norm * sin(angle),
                    rand() / static_cast<float>(RAND_MAX));
    age_ = 1;
    ageMax_ = 100 + 0.1*(static_cast<int>(100.0 * rand() / RAND_MAX));
}

void Volcano::draw()
{
    glColor3f(1.0, age_ / (float)ageMax_, 0.0 / (float)ageMax_);
    glVertex3fv(pos_);
}

void Volcano::animate()
{
//    speed_.z -= 0.07f;
//    pos_ += 0.03f * speed_;

//    if (pos_.z < 0.0) {
//      speed_.z = -0.8 * speed_.z;
//      pos_.z = 0.0;
//    }

//    if (++age_ == ageMax_)
//        init();
        speed_.z -= 0.07f;
        pos_ += 0.03f * speed_;

        if (pos_.z < 0.0) {
          speed_.z = -0.8 * speed_.z;
          pos_.z = 0.0;
        }

    if (pos_.z > 0.25 && ( (( pos_.x * pos_.x ) + ( pos_.y * pos_.y )) > 0.01 )){
        speed_.x *= (-1);
        speed_.y *= (-1);}

    if (++age_ == ageMax_)
      init();


}

