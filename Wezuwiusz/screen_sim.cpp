#include "screen_sim.hh"
#include "ui_screen_sim.h"
#include "scene.hh"

screen_sim::screen_sim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screen_sim)
{
    ui->setupUi(this);
    timer_lava = new QTimer(this);
    timer_mice = new QTimer(this);

    connect(timer_lava, SIGNAL(timeout()), this, SLOT(lava_stoper_bar()));
    connect(timer_mice, SIGNAL(timeout()), this, SLOT(mice_stoper()));
    ui->butt_Stop->setVisible(true);

   viewer = new Viewer((ui->SimWin));
   connect(this, SIGNAL(Stop_Animation()), viewer, SLOT(pause()));
   connect(this, SIGNAL(Start_Animation()), viewer, SLOT(start()));
   connect(this, SIGNAL(Reset_Animation()), viewer, SLOT(reset()));
   connect(this, SIGNAL(ChangeSpeed(int)), viewer, SLOT(SetSpeed(int)));

   client = new Udpconect;
   Thread CollectData(client);

   connect(client, SIGNAL(dataRecived(float, float, float)), viewer, SLOT(addXYZ(float, float, float)));

}

screen_sim::~screen_sim()
{
    delete ui;
    delete viewer;
    delete client;
}

void screen_sim::mice_stoper()
{
    int a;
    a = ui->LCD_Stoper->value();
    a++;
    ui->LCD_Stoper->display(a);
}

void screen_sim::lava_stoper_bar()
{
    int a;
    a = ui->bar_Lava->value();
    a++;
    ui->bar_Lava->setValue(a);
    if(a==10){
        ui->label_LavaBar->setText("RUN");
        ui->SimWin->show();
        emit Start_Animation();
    }
}

void screen_sim::on_chB_Izom_stateChanged(int arg1)
{
    if(arg1==2)
        ui->label->setText("Izometric camera");
    else if(arg1==0) ui->label->setText("Camera reset");
}

void screen_sim::on_chB_Road_stateChanged(int arg1)
{
    if(arg1==2)
        ui->label->setText("Road camera");
    else if(arg1==0) ui->label->setText("Camera reset");
}

void screen_sim::on_chB_Follow_stateChanged(int arg1)
{
    if(arg1==2)
        ui->label->setText("Follow camera");
    else if(arg1==0) ui->label->setText("Camera reset");
}

void screen_sim::on_butt_Reset_clicked()
{
    ui->label->setText("Reset clicked");
    timer_lava->stop();
    timer_mice->stop();
    if(ui->butt_Start->text() == "Continue")
    {
        emit Reset_Animation();
    }
    else
    {
        emit Stop_Animation();
        emit Reset_Animation();
    }
    ui->butt_Start->setText("Start");
    ui->LCD_Stoper->display(0);
    ui->bar_Lava->setValue(0);
}

void screen_sim::on_butt_Start_clicked()
{
    ui->label->setText("Start clicked");
    timer_lava->start(1000);
    timer_mice->start(1000);
    if(ui->butt_Start->text() == "Continue")
    {
        emit Start_Animation();
    }
}

void screen_sim::on_butt_Stop_clicked()
{
    ui->label->setText("Stop was clicked");
    timer_lava->stop();
    timer_mice->stop();
    ui->butt_Start->setText("Continue");
    emit Stop_Animation();
}

void screen_sim::on_spin_SimSpeed_valueChanged(int arg1)
{
    ui->spin_SimSpeed->setRange(0,10);
    if(arg1>1)
        ui->label->setText("Simulation accelerated");
    else if(arg1<1)
        ui->label->setText("Simulation slowed");
    emit ChangeSpeed(ui->spin_SimSpeed->value());
}

void screen_sim::on_butt_ChangeMode_clicked()
{
    emit HomeClicked();
}
