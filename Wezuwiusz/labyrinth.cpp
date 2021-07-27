#include "labyrinth.hh"
#include <time.h>

using namespace qglviewer;

Mouse::Mouse()
{

}

TopR = Vec(MousePos.x - HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
TopL = Vec(MousePos.x + HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
BotR = Vec(MousePos.x - HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
BotL = Vec(MousePos.x + HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
Nose = Vec(MousePos.x, MousePos.y + (HalfLength * 3), MOUSE_HIGHT / 2);
break;

int srand(time(NULL));

int way = rand() % 4 + 1;

void Algo(char** maze, int way, ) {
    //wrzuæ tutaj X i Y myszy
    int x, y;
    float step = 0.2;
    switch (way)
    {
    case 1:
        if (maze[y + 1][x] == 'O') {
            TopR = Vec(MousePos.x - HalfDiagonal.x, (MousePos.y - HalfDiagonal.y)+step, 0.0);
            TopL = Vec(MousePos.x + HalfDiagonal.x, (MousePos.y - HalfDiagonal.y)+step, 0.0);
            BotR = Vec(MousePos.x - HalfDiagonal.x, (MousePos.y + HalfDiagonal.y)+step, 0.0);
            BotL = Vec(MousePos.x + HalfDiagonal.x, (MousePos.y + HalfDiagonal.y)+step, 0.0);
            Nose = Vec(MousePos.x, MousePos.y + (HalfLength * 3), MOUSE_HIGHT / 2);
            break;

        }
        else {
            int way = rand() % 4 + 1;
            Algo(**maze, way);
        }
    case 2:
        if (maze[y][x - 1] == 'O') {
            TopR = Vec((MousePos.x - HalfDiagonal.x)-step, MousePos.y - HalfDiagonal.y, 0.0);
            TopL = Vec((MousePos.x - HalfDiagonal.x) - step, MousePos.y + HalfDiagonal.y, 0.0);
            BotR = Vec((MousePos.x + HalfDiagonal.x) - step, MousePos.y - HalfDiagonal.y, 0.0);
            BotL = Vec((MousePos.x + HalfDiagonal.x) - step, MousePos.y + HalfDiagonal.y, 0.0);
            Nose = Vec(MousePos.x - (HalfLength * 3), MousePos.y, MOUSE_HIGHT / 2);
            break;
        }
        else {
            int way = rand() % 4 + 1;
            Algo(**maze, way);
        }
    case 3:
        if (maze[y - 1][x] == 'O') {
            TopR = Vec(MousePos.x + HalfDiagonal.x,( MousePos.y + HalfDiagonal.y) - step, 0.0);
            TopL = Vec(MousePos.x - HalfDiagonal.x, (MousePos.y + HalfDiagonal.y) - step, 0.0);
            BotR = Vec(MousePos.x + HalfDiagonal.x, (MousePos.y - HalfDiagonal.y) - step, 0.0);
            BotL = Vec(MousePos.x - HalfDiagonal.x, (MousePos.y - HalfDiagonal.y) - step, 0.0);
            Nose = Vec(MousePos.x, MousePos.y - (HalfLength * 3), MOUSE_HIGHT / 2);
            break;
        }
        else {
            int way = rand() % 4 + 1;
            Algo(**maze, way);
        }
    case 4:
        if (maze[y][x + 1] == 'O') {
            TopR = Vec((MousePos.x + HalfDiagonal.x)+step, MousePos.y + HalfDiagonal.y, 0.0);
            TopL = Vec((MousePos.x + HalfDiagonal.x)+step, MousePos.y - HalfDiagonal.y, 0.0);
            BotR = Vec((MousePos.x - HalfDiagonal.x)+step, MousePos.y + HalfDiagonal.y, 0.0);
            BotL = Vec(MousePos.x - HalfDiagonal.x)+step, MousePos.y - HalfDiagonal.y, 0.0);
            Nose = Vec(MousePos.x + (HalfLength * 3), MousePos.y, MOUSE_HIGHT / 2);
            break;
        }
        else {
            int way = rand() % 4 + 1;
            Algo(**maze, way);
        }


    default:
        break;
    }

}
void Mouse::draw(char way)
{
    Vec TopR, TopL, BotR, BotL, Nose;
      float HalfLength = HalfDiagonal.y / sqrt(2);

      switch (way)
      {
      case 'N':
          TopR = Vec(MousePos.x - HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          TopL = Vec(MousePos.x + HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          BotR = Vec(MousePos.x - HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          BotL = Vec(MousePos.x + HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          Nose = Vec(MousePos.x, MousePos.y + (HalfLength * 3), MOUSE_HIGHT / 2);
          break;

      case 'S':
          TopR = Vec(MousePos.x + HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          TopL = Vec(MousePos.x - HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          BotR = Vec(MousePos.x + HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          BotL = Vec(MousePos.x - HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          Nose = Vec(MousePos.x, MousePos.y - (HalfLength * 3), MOUSE_HIGHT / 2);
          break;

      case 'E':
          TopR = Vec(MousePos.x + HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          TopL = Vec(MousePos.x + HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          BotR = Vec(MousePos.x - HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          BotL = Vec(MousePos.x - HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          Nose = Vec(MousePos.x + (HalfLength * 3), MousePos.y , MOUSE_HIGHT / 2);
          break;

      case 'W':
          TopR = Vec(MousePos.x - HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          TopL = Vec(MousePos.x - HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          BotR = Vec(MousePos.x + HalfDiagonal.x, MousePos.y - HalfDiagonal.y, 0.0);
          BotL = Vec(MousePos.x + HalfDiagonal.x, MousePos.y + HalfDiagonal.y, 0.0);
          Nose = Vec(MousePos.x - (HalfLength * 3), MousePos.y, MOUSE_HIGHT / 2);
          break;

      default:
          break;
      }

    glBegin(GL_POLYGON);
    glColor3f(0.753f, 0.753f, 0.753f);
    glVertex3f( TopR.x, TopR.y, TopR.z );
    glVertex3f( TopL.x, TopL.y, TopL.z );
    glVertex3f( BotL.x, BotL.y, BotL.z );
    glVertex3f( BotR.x, BotR.y, BotR.z );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.753f, 0.753f, 0.753f);
    glVertex3f( TopR.x, TopR.y, MOUSE_HIGHT );
    glVertex3f( TopL.x, TopL.y, MOUSE_HIGHT );
    glVertex3f( BotL.x, BotL.y, MOUSE_HIGHT );
    glVertex3f( BotR.x, BotR.y, MOUSE_HIGHT );

    glBegin(GL_POLYGON);
    glColor3f(0.753f, 0.753f, 0.753f);
    glVertex3f( TopR.x, TopR.y, MOUSE_HIGHT );
    glVertex3f( TopR.x, TopR.y, 0.00 );
    glVertex3f( BotR.x, BotR.y, 0.00 );
    glVertex3f( BotR.x, BotR.y, MOUSE_HIGHT );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.753f, 0.753f, 0.753f);
    glVertex3f( TopL.x, TopL.y, MOUSE_HIGHT );
    glVertex3f( TopL.x, TopL.y, 0.00 );
    glVertex3f( BotL.x, BotL.y, 0.00 );
    glVertex3f( BotL.x, BotL.y, MOUSE_HIGHT );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.753f, 0.753f, 0.753f);
    glVertex3f( TopR.x, TopR.y, MOUSE_HIGHT );
    glVertex3f( TopR.x, TopR.y, 0.00 );
    glVertex3f( TopL.x, TopL.y, 0.00 );
    glVertex3f( TopL.x, TopL.y, MOUSE_HIGHT );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f( BotR.x, BotR.y, MOUSE_HIGHT );
    glVertex3f( BotL.x, BotL.y, MOUSE_HIGHT );
    glVertex3f( Nose.x, Nose.y, Nose.z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f( BotR.x, BotR.y, 0.0 );
    glVertex3f( BotL.x, BotL.y, 0.0 );
    glVertex3f( Nose.x, Nose.y, Nose.z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f( BotR.x, BotR.y, MOUSE_HIGHT );
    glVertex3f( BotR.x, BotR.y, 0.0 );
    glVertex3f( Nose.x, Nose.y, Nose.z);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f( BotL.x, BotL.y, MOUSE_HIGHT );
    glVertex3f( BotL.x, BotL.y, 0.0 );
    glVertex3f( Nose.x, Nose.y, Nose.z);
    glEnd();


}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Labyrinth::Labyrinth()
{


}





void Labyrinth::WallsDraw()
{
       float y = 1;
       for (int i = 0; i < 10; i++) {
           float x = -1;
           for (int j = 0; j < 10; j++) {
               if (Maze[i][j] == 'S') {

                   glBegin(GL_POLYGON);
                   glColor3f(86/255.0, 64/255.0, 50/255.0);
                   glVertex3f(x, y, WALL_HIGHT);
                   glVertex3f(x, y, 0);
                   glVertex3f(x, y - 0.2, 0);
                   glVertex3f(x, y - 0.2, WALL_HIGHT);
                   glEnd();


                   glBegin(GL_POLYGON);
                  glColor3f(86/255.0, 64/255.0, 50/255.0);
                   glVertex3f(x, y, WALL_HIGHT);
                   glVertex3f(x, y - 0.2, WALL_HIGHT);
                   glVertex3f(x + 0.2, y - 0.2, WALL_HIGHT);
                   glVertex3f(x + 0.2, y, WALL_HIGHT);
                   glEnd();


                   glBegin(GL_POLYGON);
                   glColor3f(86/255.0, 64/255.0, 50/255.0);
                   glVertex3f(x + 0.2, y - 0.2, WALL_HIGHT);
                   glVertex3f(x + 0.2, y - 0.2, 0);
                   glVertex3f(x + 0.2, y, 0);
                   glVertex3f(x + 0.2, y, WALL_HIGHT);
                   glEnd();


                   glBegin(GL_POLYGON);
                   glColor3f(86/255.0, 64/255.0, 50/255.0);
                   glVertex3f(x, y, WALL_HIGHT);
                   glVertex3f(x, y, 0);
                   glVertex3f(x + 0.2, y, 0);
                   glVertex3f(x + 0.2, y, WALL_HIGHT);
                   glEnd();


                   glBegin(GL_POLYGON);
                   glColor3f(86/255.0, 64/255.0, 50/255.0);
                   glVertex3f(x, y - 0.2, WALL_HIGHT);
                   glVertex3f(x, y - 0.2, 0);
                   glVertex3f(x + 0.2, y - 0.2, 0);
                   glVertex3f(x + 0.2, y, WALL_HIGHT);
                   glEnd();

               }
               x += 0.2f;
           }
           y -= 0.2f;
       }

}


