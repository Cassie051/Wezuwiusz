#include "screen_rob.hh"
#include "ui_screen_rob.h"

screen_rob::screen_rob(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screen_rob)
{
    ui->setupUi(this);
    timer_lava = new QTimer(this);
    timer_mice = new QTimer(this);
    connect(timer_lava,
            SIGNAL(timeout()),
            this,
            SLOT(lava_stoper_bar()));
    connect(timer_mice,
            SIGNAL(timeout()),
            this,
            SLOT(mice_stoper()));
}

screen_rob::~screen_rob()
{
    delete ui;
}

void screen_rob::mice_stoper()
{
    int a;
    a = ui->LCD_Stoper->value();
    a++;
    ui->LCD_Stoper->display(a);
}

void screen_rob::lava_stoper_bar()
{
    int a;
    a = ui->bar_Lava->value();
    a++;
    ui->bar_Lava->setValue(a);
    if(a==10){
        ui->label_LavaBar->setText("RUN");
    }

}


void screen_rob::on_chB_Izom_stateChanged(int arg1)
{
    if(arg1==2)
        ui->label->setText("Izometric camera");
    else if(arg1==0) ui->label->setText("Camera reset");
}

void screen_rob::on_chB_Road_stateChanged(int arg1)
{
    if(arg1==2)
        ui->label->setText("Road camera");
    else if(arg1==0) ui->label->setText("Camera reset");
}

void screen_rob::on_chB_Follow_stateChanged(int arg1)
{
    if(arg1==2)
        ui->label->setText("Follow camera");
    else if(arg1==0) ui->label->setText("Camera reset");
}

void screen_rob::on_butt_Reset_clicked()
{
    ui->label->setText("Reset clicked");
    timer_lava->stop();
    timer_mice->stop();
    ui->LCD_Stoper->display(0);
    ui->bar_Lava->setValue(0);
}

void screen_rob::on_butt_Start_clicked()
{
    ui->label->setText("Start clicked");
    timer_lava->start(1000);
    timer_mice->start(1000);
}

void screen_rob::on_butt_Stop_clicked()
{
    ui->label->setText("Stop was clicked");
    timer_lava->stop();
    timer_mice->stop();
    ui->butt_Start->setText("Continue");
}

void screen_rob::on_butt_ChangeMode_clicked()
{
    emit HomeClicked();
}
