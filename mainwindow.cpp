#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "question.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image(":/karta_rossii.jpg");
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView(scene);
    graphicsItem = new GraphicsPixmapItem(QPixmap::fromImage(image));
    connect(graphicsItem, SIGNAL(pointClicked(QPoint)), this, SLOT(openCityWindow(QPoint)));
    scene->addItem(graphicsItem);
    ui->centralWidget->layout()->addWidget(view);



    QFile file("questions.txt");
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if (line.startsWith("N ")){
              QString cityName = line.right(line.length() - 2);
              line = in.readLine();
              int x = line.right(line.length() - 2).toInt();
              line = in.readLine();
              int y = line.right(line.length() - 2).toInt();
              QVector<Question> questions;
              line = in.readLine();
              while (line.startsWith("Q ")) {
                  QString questionString = line.right(line.length() - 2);
                  Question q(questionString);
                  line = in.readLine();
                  while (line.startsWith("A ") || line.startsWith("R ")) {
                      QString answer = line.right(line.length() - 2);
                      q.addAnswer(answer, line.startsWith("R "));
                      line = in.readLine();
                  }
                  questions.push_back(q);
              }
              City* c = new City(x, y, cityName, questions, this);
              cities.push_back(c);
          }
       }
       file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        delete *it;
    }
}


void MainWindow::openCityWindow(QPoint p)
{
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        if ((*it)->checkPoint(p)){
            if((*it)->complete != true){
                (*it)->show();
                hide();
                break;
            }
            else{
                (*it)->eq->show();
                hide();
                break;
            }
        }
    }
}

void MainWindow::restartAllQuestions()
{
    for (QVector<City*>::iterator it = cities.begin(); it!=cities.end(); it++) {
        (*it)->restartQuestions();
    }
}
