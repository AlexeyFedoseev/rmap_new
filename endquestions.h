#ifndef ENDQUESTIONS_H
#define ENDQUESTIONS_H

#include <QWidget>
#include <QString>
#include "city.h"

namespace Ui {
class EndQuestions;
}

class City;
class MainWindow;


class EndQuestions : public QWidget
{
    Q_OBJECT
    Ui::EndQuestions *ui;
public:
    EndQuestions(City* city, MainWindow* mw);
    ~EndQuestions();
};

#endif // ENDQUESTIONS_H
