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

void AnswerWindow::preShow(int rightIndex, int checkId, City* city)
{
    if(rightIndex == checkId){
        QPixmap pix;
        pix.load(":/galochka.png");
        ui->image->resize(pix.size());
        ui->image->setPixmap(pix);
        ui->label->setText("Ты ответил на вопрос правильно");
        city->rightAnswers++;
    }
    else {
        QPixmap pix;
        pix.load(":/krest.PNG");
        QImage image(":/krest.PNG");
        ui->image->resize(pix.size());
        ui->image->setPixmap(pix);
        ui->label->setText("Ты ответил на вопрос неправильно");
    }
    show();
}
