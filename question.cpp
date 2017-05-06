#include "question.h"

Question::Question(QString text, QString img): questionText(text), imagePath(img)
{

}

Question::Question()
{

}

Question::~Question()
{

}

void Question::addAnswer(QString text, bool correct)
{
    answers.push_back(text);
    if (correct){
        rightIndex = answers.size() - 1;
    }
}

