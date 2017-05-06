#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QString>
#include <QVector>

class Question
{

public:
    QString questionText;
    QString imagePath;
    QVector<QString> answers;
    int rightIndex;

    Question();
    Question(QString text, QString img);
    ~Question();
    void addAnswer(QString text, bool correct);
};

#endif // QUESTION_H
