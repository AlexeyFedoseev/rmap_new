#include "answerwindow.h"
#include "city.h"
#include "ui_answerwindow.h"
#include "mainwindow.h"
#include <QWidget>

AnswerWindow::AnswerWindow(City* city, MainWindow* mw) : ui(new Ui::answerwindow)
{
    ui->setupUi(this);
    connect(ui->exitButton, SIGNAL(clicked()), city, SLOT(exitToMap()));
    connect(ui->exitButton, SIGNAL(clicked()), mw, SLOT(show()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->nextButton, SIGNAL(clicked()), city, SLOT(nextQuestion()));
}

AnswerWindow::~AnswerWindow()
{

}

void AnswerWindow::preShow(int rightIndex, int checkId)
{
    if(rightIndex == checkId){
        QImage image(":/galochka.png");
        QGraphicsScene* scene = new QGraphicsScene();
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        ui->graphicsView->setScene(scene);
        //ui->imageLabel->setPixmap(":/galochka.png");
        ui->label->setText("Ты ответил на вопрос правильно");

    }
    else {
        QImage image(":/krest.PNG");
        QGraphicsScene* scene = new QGraphicsScene();
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        ui->graphicsView->setScene(scene);
        //ui->imageLabel->setPixmap(":/krest.jpg");
        ui->label->setText("Ты ответил на вопрос неправильно");
    }
    show();
}
