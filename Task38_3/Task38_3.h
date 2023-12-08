#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task38_3.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsBlurEffect>
#include<QGraphicsScene>
#include<QDir>
#include<QFuture>
#include<QPainter>
#include <QApplication>
#include<QFileDialog>
#include<QtConcurrent/QtConcurrent>


QImage blurImage(QImage sourse, int &b);

class Task38_3 : public QMainWindow
{
    Q_OBJECT
private:
    Ui::Task38_3Class ui;
    QString nameFile;
    int numBlure;
    QImage p;
public:
    Task38_3(QWidget *parent = nullptr);
    void workingPicture(QImage pix,int numBlure);
    ~Task38_3();

public slots:
    
    void openFile()
    {
        p.load(QFileDialog::getOpenFileName(nullptr, "Open file", "/C", "jpg files(*.jpg)"));
        workingPicture(p, numBlure);
        
    };
    void numChange() { 
        numBlure=ui.horizontalScrollBar->value(); 
        workingPicture(p, numBlure);
    };
};
