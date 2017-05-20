#include "endquestions.h"
#include "ui_endquestions.h"
#include <QWidget>

EndQuestions::EndQuestions(City* city, MainWindow *mw) : ui(new Ui::EndQuestions)
{
    ui->setupUi(this);
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->exitButton, SIGNAL(clicked()), mw, SLOT(show()));
    connect(ui->restartButton, SIGNAL(clicked()), city, SLOT(restartQuestions()));
}

EndQuestions::~EndQuestions()
{

}

void EndQuestions::preShow(City* city)
{
    QString result = "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Вы ответили правильно на ";
    result += QString::number(city->rightAnswers);
    result += " из ";
    result += QString::number(city->questions.size());
    result += " вопросов</span></p></body></html>";
    ui->result->setText(result);
    show();
}
