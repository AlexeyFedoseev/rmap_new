#ifndef CITY_H
#define CITY_H

#include "question.h"
#include <QDialog>
#include <QRect>
#include <QPoint>
#include "answerwindow.h"
#include "endquestions.h"
#include "mainwindow.h"

namespace Ui {
class City;
class Dialog;
}

class AnswerWindow;
class EndQuestions;
class MainWindow;


class City : public QDialog
{
    Q_OBJECT

public:
    City(int x, int y, QString name, const QVector<Question>& questions, MainWindow* m, QWidget *parent = 0);
    ~City();
    bool checkPoint(QPoint p);
    bool complete = false;
    EndQuestions* eq;

public slots:
    void showAnswer();
    void nextQuestion();
    void exitToMap();
    void restartQuestions();

private:
    void uncheckButtons();
    void changeText();
    int questionNumber = 0;
    Ui::Dialog *ui;
    QRect rect;
    QVector<Question> questions;
    AnswerWindow* aw;
};

#endif // CITY_H
