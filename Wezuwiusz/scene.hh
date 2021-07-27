#ifndef SCENE_H
#define SCENE_H

#include <QGLViewer/qglviewer.h>
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QTimer>
#include <QtGlobal>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPointer>
#include <labyrinth.hh>

#define GRID_SIZE 1.1

/*!
 * \brief The Volcano class
 *
 * Klasa odpowiedzialna za animację wulkanu oraz zmianę położenia cząsteczek.
 */
class Volcano
{
public:
    /*!
     * \brief Volcano
     *
     * Konstruktor klasy \link Volcano \endlink wywołuję funkcję Volcano::init co pozwala na inicjację aplikacji.
     */
    Volcano();

    ~Volcano();
    /*!
     * \brief init
     *
     * Funkcja inicjalizująca podstawowe parametry wulkanu, takie jak długośc życia, pozycja, prędkość.
     */
    void init();
    /*!
     * \brief draw
     *
     * Funkcja rysująca obiekt wylkanu w odpowiedniej kolorystyce o zdefiniowanej w Volcano::init pozycji.
     */
    void draw();
    /*!
     * \brief animate
     *
     * Funkcja opdowiedzialna za przebieg animacji wulkanu.
     */
    void animate();

private:
    /*!
       * \brief speed_
       *
       * Prędkość porusznaia cząsteczek lawy.
       */
      qglviewer::Vec speed_, pos_;
      /*!
       * \brief age_
       *
       * Paramerty określającje starzenie cząsteczek oraz długość cyklu życia.
       */
      int age_, ageMax_;
      /*!
       * \brief counter
       *
       * Licznik pozwalający określić cyklu danych animacji i w zależności od niego dostosować odpowiednie paramtery wyświetlania animacji.
       */
      int counter = 0;
};


/*!
 * \brief The Viewer class
 *
 * Klasa odpowiedzialna za wyświetlanie sceny oraz elementów, które się na niej znajdują.
 */
class Viewer : public QGLViewer
{
    Q_OBJECT

public:
    /*!
         * \brief Viewer Konstruktor klasy Viewer.
         *
         * \param[in] parent- wskaźnik rodzica ustawiony na NULL pointer.
         */
        explicit Viewer(QWidget *parent = nullptr);
        ~Viewer();
    /*!
         * \brief volcano_
         *
         * Wskaźnik na obiekt klasy \link Volcano \endlink.
         */
        Volcano *volcano_;
        /*!
         * \brief mouse_
         *
         * Wskaźnik na obiekt klasy \link Mouse \endlink.
         */
        Mouse *mouse_;
        /*!
         * \brief labyrinth_
         *
         * Wskaźnik na obiekt klasy \link Labyrinth \endlink.
         */
        Labyrinth *labyrinth_;
public slots:
     /*!
     * \brief pause
     *
     * Slot umożliwaijący pauzowanie animacji za pomocją sygnału \link screen_sim::Stop_Animation \endlink.
     *
     */
    virtual void pause();
     /*!
     * \brief start
     *
     * Slot umożliwiający start animacji po jej zapauzowaniu jak i pierwszym uruchomieniu, całośc odbywa się za pomocą sygnału \link screen_sim::Start_Animation() \endlink.
     */
    virtual void start();
     /*!
     * \brief reset
     *
     * Slot umożliwiający zrestartowanie animacji za pomocą sygnału \link screen_sim::Reset_Animation() \endlink.
     */
    virtual void reset();

protected:
      /*!
       * \brief draw
       *
       * Metoda rysująca scenę animacji.
       */
      virtual void draw();
      /*!
       * \brief init
       *
       * Metoda inicjalizująca scenę animacji.
       */
      virtual void init();
      /*!
       * \brief animate
       *
       * Metoda odpowiedzialna za animację na scenie. Pozwala na rozpoczęcie animacji i synchronizację wszykich elementów.
       */
      virtual void animate();

private:
      /*!
       * \brief nbPart_
       *
       * Zmienna odpowiedzialna za ilość cząsteczek wulkanu.
       */
      int nbPart_;
      /*!
       * \brief animationSpeed
       *
       * Zmienna określająca wartość przyśpieszenia animacji.
       */
      int animationSpeed = 0;

private slots:
      /*!
       * \brief addXYZ
       *
       * Slot odpowiedzialny za przypisanie parametrów akcelerometru, które są wykorzystywane rzez inne funkcję w celu oddziaływania aplikacji.
       *
       * \param x - prędkośc wychylenia w osi współrzędnej x
       *
       * \param y - prędkośc wychylenie w osi współrzędnej y
       *
       * \param z - prędkość wychylenia w osi współrzędnej z
       */
      void addXYZ(float x, float y, float z);
      /*!
       * \brief SetSpeed
       *
       * Metoda pozwalająca ustalić prędkość symulacji.
       *
       * \param setspeed - akutalna wartośc prędkości
       */
      void SetSpeed(int setspeed);
};

#endif // SCENE_H
