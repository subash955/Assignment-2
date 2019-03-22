#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mt1box->setMaximum(100);
    ui->mt1slide->setMaximum(100);
    ui->mt2box->setMaximum(100);
    ui->mt2slide->setMaximum(100);
    ui->finalbox->setMaximum(100);
    ui->finalslide->setMaximum(100);
    ui->hw1box->setMaximum(100);
    ui->hw1_s->setMaximum(100);
    ui->hw2box->setMaximum(100);
    ui->hw2_s->setMaximum(100);
    ui->hw3box->setMaximum(100);
    ui->hw3_s->setMaximum(100);
    ui->hw4box->setMaximum(100);
    ui->hw4_s->setMaximum(100);
    ui->hw5box->setMaximum(100);
    ui->hw5_s->setMaximum(100);
    ui->hw6box->setMaximum(100);
    ui->hw6_s->setMaximum(100);
    ui->hw7box->setMaximum(100);
    ui->hw7_s->setMaximum(100);
    ui->hw8box->setMaximum(100);
    ui->hw8_s->setMaximum(100);

    QObject::connect(ui->mt1box,SIGNAL(valueChanged(int)),ui->mt1slide,SLOT(setValue(int)));
    QObject::connect(ui->mt2box,SIGNAL(valueChanged(int)),ui->mt2slide,SLOT(setValue(int)));
    QObject::connect(ui->finalbox,SIGNAL(valueChanged(int)),ui->finalslide,SLOT(setValue(int)));
    QObject::connect(ui->hw1box,SIGNAL(valueChanged(int)),ui->hw1_s,SLOT(setValue(int)));
    QObject::connect(ui->hw2box,SIGNAL(valueChanged(int)),ui->hw2_s,SLOT(setValue(int)));
    QObject::connect(ui->hw3box,SIGNAL(valueChanged(int)),ui->hw3_s,SLOT(setValue(int)));
    QObject::connect(ui->hw4box,SIGNAL(valueChanged(int)),ui->hw4_s,SLOT(setValue(int)));
    QObject::connect(ui->hw5box,SIGNAL(valueChanged(int)),ui->hw5_s,SLOT(setValue(int)));
    QObject::connect(ui->hw6box,SIGNAL(valueChanged(int)),ui->hw6_s,SLOT(setValue(int)));
    QObject::connect(ui->hw7box,SIGNAL(valueChanged(int)),ui->hw7_s,SLOT(setValue(int)));
    QObject::connect(ui->hw8box,SIGNAL(valueChanged(int)),ui->hw8_s,SLOT(setValue(int)));



   QObject::connect(ui->mt1slide,SIGNAL(valueChanged(int)),ui->mt1box,SLOT(setValue(int)));
   QObject::connect(ui->mt2slide,SIGNAL(valueChanged(int)),ui->mt2box,SLOT(setValue(int)));
   QObject::connect(ui->finalslide,SIGNAL(valueChanged(int)),ui->finalbox,SLOT(setValue(int)));
   QObject::connect(ui->hw1_s,SIGNAL(valueChanged(int)),ui->hw1box,SLOT(setValue(int)));
   QObject::connect(ui->hw2_s,SIGNAL(valueChanged(int)),ui->hw2box,SLOT(setValue(int)));
   QObject::connect(ui->hw3_s,SIGNAL(valueChanged(int)),ui->hw3box,SLOT(setValue(int)));
   QObject::connect(ui->hw4_s,SIGNAL(valueChanged(int)),ui->hw4box,SLOT(setValue(int)));
   QObject::connect(ui->hw5_s,SIGNAL(valueChanged(int)),ui->hw5box,SLOT(setValue(int)));
   QObject::connect(ui->hw6_s,SIGNAL(valueChanged(int)),ui->hw6box,SLOT(setValue(int)));
   QObject::connect(ui->hw7_s,SIGNAL(valueChanged(int)),ui->hw7box,SLOT(setValue(int)));
   QObject::connect(ui->hw8_s,SIGNAL(valueChanged(int)),ui->hw8box,SLOT(setValue(int)));

   QObject::connect(ui->hw8_s,SIGNAL(valueChanged(int)),ui->hw8box,SLOT(setValue(int)));

    QObject::connect(ui->hw1box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw2box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw3box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw4box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw5box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw6box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw7box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->hw8box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->mt1box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->mt2box,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->finalbox,SIGNAL(valueChanged(int)),this,SLOT(compute()));
    QObject::connect(ui->sch_a,SIGNAL(released()),this,SLOT(compute()));
    QObject::connect(ui->sch_b,SIGNAL(released()),this,SLOT(compute()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compute()
{

    int hwscores[8] = {MainWindow::ui->hw1box->value(), MainWindow::ui->hw2box->value(), MainWindow::ui->hw3box->value(), MainWindow::ui->hw4box->value(), MainWindow::ui->hw5box->value(), MainWindow::ui->hw6box->value(), MainWindow::ui->hw7box->value(), MainWindow::ui->hw8box->value()};
    double min = hwscores[0];
    for (int i = 1; i < 8; i++)
    {
        if (hwscores[i] < min)
            min = hwscores[i];
    }


    double sum = -min;
    for (int i = 0; i < 8; i ++)
        sum += hwscores[i];
    double average = sum/7;
    double mtave = 0.2*(MainWindow::ui->mt1box->value() + MainWindow::ui->mt2box->value());
    double score = 0.25*average + mtave + 0.35 * MainWindow::ui->finalbox->value();

    double shc_bmt = 0.3*std::max(MainWindow::ui->mt1box->value(), MainWindow::ui->mt2box->value());
    double shc_fin = 0.44*MainWindow::ui->finalbox->value();
    double score_b = 0.25*average + shc_bmt + shc_fin;

    if (MainWindow::ui->sch_b->isChecked())
            MainWindow::ui->score_o->setNum(score_b);
    else MainWindow::ui->score_o->setNum(score);

}
