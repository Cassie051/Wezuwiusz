#include "screen_welcome.hh"
#include "ui_screen_welcome.h"

Screen_Welcome::Screen_Welcome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Screen_Welcome)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &ScrRob);
    ui->stackedWidget->insertWidget(2, &ScrSim);
    connect(&ScrRob, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&ScrSim, SIGNAL(HomeClicked()), this, SLOT(moveHome()));


}

Screen_Welcome::~Screen_Welcome()
{
    delete ui;
}


void Screen_Welcome::on_butt_Rob_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
//    ui->stackedWidget->resize(ui->stackedWidget->size());
}

void Screen_Welcome::on_butt_Sym_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
//    ui->stackedWidget->resize(ui->stackedWidget->size());
}

void Screen_Welcome::on_butt_Exit_clicked()
{
    this->close();
}

void Screen_Welcome::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}



