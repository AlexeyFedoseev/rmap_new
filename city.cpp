#include "city.h"
#include "ui_city.h"
#include "question.h"
#include "answerwindow.h"
#include "endquestions.h"
#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QTime>

City::City(int x, int y, QString name, QString imagePath, const QVector<Question> &questions, MainWindow* m, QWidget *parent) :
    QDialog(parent), questions(questions), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QImage image(imagePath);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);;
    rect = QRect(x-10, y-10, 20, 20);

    ui->cityName->setText(name);
    changeText();

    eq = new EndQuestions(this, m);
    aw = new AnswerWindow(this, m);
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(showAnswer()));

    for (int i = 0; i<questions.size(); i++){
        qDebug() << questions[i].answers;
    }
}



City::~City()
{
    delete aw;
}

bool City::checkPoint(QPoint p)
{
    return rect.contains(p);
}

void City::showAnswer()
{
    int checkId = 5;
    if(ui->var1->isChecked()){
        checkId = 0;
    }
    if(ui->var2->isChecked()){
        checkId = 1;
    }
    if(ui->var3->isChecked()){
        checkId = 2;
    }
    if(ui->var4->isChecked()){
        checkId = 3;
    }
    aw->preShow(rIndex, checkId);
    hide();
}

void City::nextQuestion()
{
    show();
    uncheckButtons();
    aw->hide();
    questionNumber++;
    if(questionNumber < questions.size()){
        changeText();
    }
    else{
        complete = true;
        eq->show();
        hide();
    }
}

void City::exitToMap()
{
    questionNumber++;
    uncheckButtons();
    hide();
    if(questionNumber < questions.size()){
        changeText();
    }
    else{
        complete = true;
    }
}

void City::restartQuestions()
{
    eq->hide();
    complete = false;
    questionNumber = 0;
    changeText();
    show();
}

void City::uncheckButtons()
{
    ui->var1->setAutoExclusive(false);
    ui->var1->setChecked(false);
    ui->var1->setAutoExclusive(true);

    ui->var2->setAutoExclusive(false);
    ui->var2->setChecked(false);
    ui->var2->setAutoExclusive(true);

    ui->var3->setAutoExclusive(false);
    ui->var3->setChecked(false);
    ui->var3->setAutoExclusive(true);

    ui->var4->setAutoExclusive(false);
    ui->var4->setChecked(false);
    ui->var4->setAutoExclusive(true);
}

void City::changeText()
{
    int temp[4];
    QTime t = QTime::currentTime();
    srand(t.msecsTo(t));

    ui->quest->setText(questions[questionNumber].questionText);

    temp[0] = rand() % 4;
    ui->var1->setText(questions[questionNumber].answers[temp[0]]);
    if(questions[questionNumber].rightIndex == temp[0]){
        rIndex = 0;
    }

    temp[1] = rand() % 4;
    while(temp[1] == temp[0])
    {
        temp[1] = rand() % 4;
    }
    ui->var2->setText(questions[questionNumber].answers[temp[1]]);
    if(questions[questionNumber].rightIndex == temp[1]){
        rIndex = 1;
    }

    temp[2] = rand() % 4;
    while(temp[2] == temp[0] || temp[2] == temp[1])
    {
        temp[2] = rand() % 4;
    }
    ui->var3->setText(questions[questionNumber].answers[temp[2]]);
    if(questions[questionNumber].rightIndex == temp[2]){
        rIndex = 2;
    }

    temp[3] = rand() % 4;
    while(temp[3] == temp[0] || temp[3] == temp[1] || temp[3] == temp[2])
    {
        temp[3] = rand() % 4;
    }
    ui->var4->setText(questions[questionNumber].answers[temp[3]]);
    if(questions[questionNumber].rightIndex == temp[3]){
        rIndex = 3;
    }
}
