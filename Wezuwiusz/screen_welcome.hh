#ifndef SCREEN_WELCOME_H
#define SCREEN_WELCOME_H

#include <QMainWindow>
#include <screen_rob.hh>
#include <screen_sim.hh>

QT_BEGIN_NAMESPACE
namespace Ui { class Screen_Welcome; }
QT_END_NAMESPACE

/*!
 * \brief The Screen_Welcome class
 *
 * Klasa wyświetlająca okno wyboru miedzy symulacją, a połączeniem robota.
 */
class Screen_Welcome : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Screen_Welcome
     *
     * Klasa odpowiadająca za wyświetlenie okna powitalnego.
     *
     * \param parametr
     *
     */
    Screen_Welcome(QWidget *parent = nullptr);
    ~Screen_Welcome();

private slots:
    /*!
    /*! * \brief on_butt_Rob_clicked
     *
     * Slot odopwiedający zaPrzejście do ekranu ruchu rubota
    /*! */
    void on_butt_Rob_clicked();


    /*!
     * \brief on_butt_Sym_clicked
     *
     * Slot odpowiadający za przejście do ekrqanu symulacji.
     */
    void on_butt_Sym_clicked();

    /*!
     * \brief on_butt_Exit_clicked
     *
     * Slot odpowiadającie za wujście z aplikacji
     */
    void on_butt_Exit_clicked();


    /*!
     * \brief moveHome
     *
     * Slot opodwiadający za przejście do ekranu startowego./
     */

    void moveHome();

private:
    /*!
     * \brief *ui
     *
     * Wskaźnika na obiekt ui.
     */
    Ui::Screen_Welcome *ui;
    /*!
      * \brief ScrRob
      *
      * Obiekt klasy screen_rob reprezentujący robota
      */
    screen_rob ScrRob;
    /*!
      * \brief ScrRob
      *
      * Obiekt klasy screen_sim reprezentujący okno symulacji
      */
    screen_sim ScrSim;
};
#endif // SCREEN_WELCOME_H
