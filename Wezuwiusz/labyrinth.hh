#ifndef LABYRINTH_H
#define LABYRINTH_H
#define MOUSE_HDIAGONAL 0.025
#define MOUSE_HIGHT 0.03
#define WALL_HIGHT 0.05

#include <math.h>
#include <QObject>
#include <QGLViewer/qglviewer.h>

/*!
 * \brief The Mouse class
 *
 * Klasa obiektu myszy, odpowiedająca za rysownie myszy.
 */
class Mouse
{
public:
    /*!
     * \brief Mouse
     *
     * Konstruktor klasy Mouse.
     */
    Mouse();
    /*!
     * \brief draw
     *
     * Funkcja odpowiadjąca za rysowanie myszy w odpowiednim kieruunku.
     *
     * \param way
     *
     * Parametr określający kierunken rysowania myszy, możliwe kiesunki to N,W, S, E.
     */
    void draw(char way);
    /*!
     * \brief MousePos
     *
     * Wektor określający położenie myszy na planszy.
     */
    qglviewer::Vec MousePos = qglviewer::Vec(-0.90, 0.90, 0.0);
    /*!
     * \brief HalfDiagonal
     *
     * Wektor określający połowę długości przekątnej myszy.
     */
    qglviewer::Vec HalfDiagonal = qglviewer::Vec(MOUSE_HDIAGONAL, MOUSE_HDIAGONAL, 0.0);
};


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/*!
 * \brief The Labyrinth class
 *
 * Klasa obiektu laritynt, odpowiadająca za rysowanie labriryntu.
 */
class Labyrinth
{
public:
    /*!
     * \brief Labyrinth
     *
     * Konstruktor klasy Labyrinth.
     */
    Labyrinth();
    /*!
     * \brief WallsDraw
     *
     * Metoda realizująca rysowanie labiynmtu o zadanej struktourze.
     */
    void WallsDraw();
    /*!
    * \brief Maze
    *
    * Tablica zawierająca mapę labiryntu, za pomoca znaków "S" zostało określone miejsce występowania ściany.
    */
    char Maze[10][11] =
    {
        "OSSSOOOOOS",
        "OSOSSSSOOS",
        "OSOSOOSOOS",
        "OSSSOOSOOS",
        "OOOOOOSOOS",
        "SOSSOOSOOS",
        "SOSSSSSOOS",
        "SOOOOOOOOS",
        "SSSOOSSOOS",
        "SSSSSSSSOS",
    };

};




#endif // LABYRINTH_H
