#ifndef ANSWERWINDOW_H
#define ANSWERWINDOW_H

#include <QWidget>
#include <QString>
#include "city.h"
#include "mainwindow.h"

namespace Ui {
class answerwindow;
}

class City;
class MainWindow;

class AnswerWindow : public QWidget
{
    Q_OBJECT
    Ui::answerwindow *ui;
public:
    AnswerWindow(City *city, MainWindow* mw);
    ~AnswerWindow();
    void preShow(int rightIndex, int checkId);
};

#endif // ANSWERWINDOW_H
