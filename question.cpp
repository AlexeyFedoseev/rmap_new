#include "question.h"

Question::Question(QString text)
{
    if(text.size() >= 97){
        text.insert(97, "-\n");
    }
    if(text.size() >= 194){
        text.insert(194, "-\n");
    }
    questionText = text;
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

