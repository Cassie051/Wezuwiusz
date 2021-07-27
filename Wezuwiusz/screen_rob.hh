#ifndef SCREEN_ROB_H
#define SCREEN_ROB_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QTimer>
#include <QtGlobal>
#include <QGLViewer/qglviewer.h>


namespace Ui {
class screen_rob;
}

class screen_rob : public QWidget
{
    Q_OBJECT

public:
    explicit screen_rob(QWidget *parent = nullptr);
    ~screen_rob();

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

    void on_butt_ChangeMode_clicked();

private:
    Ui::screen_rob *ui;
    QTimer *timer_lava;
    QTimer *timer_mice;

signals:
    void HomeClicked();
};

#endif // SCREEN_ROB_H
