#ifndef SCREEN_SIM_H
#define SCREEN_SIM_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QTimer>
#include <QtGlobal>
#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <scene.hh>
#include <QPointer>
#include <thread.hh>

namespace Ui {
class screen_sim;
}

/*!
 * \brief The screen_sim class
 *
 * Klasa definiująca okno symulacji oraz obsługująca funkcjonalność związane z użytecznością aplikacji.
 */
class screen_sim : public QWidget
{
    Q_OBJECT

public:
    explicit screen_sim(QWidget *parent = nullptr);
    ~screen_sim();
    QPointer<Viewer> viewer;
    QPointer<Udpconect> client;

public slots:
    void mice_stoper();

    void lava_stoper_bar();

private slots:
    void on_chB_Izom_stateChanged(int arg1);

    void on_chB_Road_stateChanged(int arg1);

    void on_chB_Follow_stateChanged(int arg1);

    void on_butt_Reset_clicked();

    void on_butt_Start_clicked();

    void on_butt_Stop_clicked();

    void on_spin_SimSpeed_valueChanged(int arg1);

    void on_butt_ChangeMode_clicked();



private:
    Ui::screen_sim *ui;
    QTimer *timer_lava;
    QTimer *timer_mice;
    QObject SimWin;


signals:
    void HomeClicked();
    void Stop_Animation();
    void Start_Animation();
    void Reset_Animation();
    void ChangeSpeed(int speedvalue);
};

#endif // SCREEN_SIM_H
