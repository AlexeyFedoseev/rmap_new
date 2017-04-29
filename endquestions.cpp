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
