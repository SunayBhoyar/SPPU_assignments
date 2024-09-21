#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QImage>
#include <iostream>
#include<math.h>
using namespace std ;
QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
float points[6];
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(float x1 , float y1 , float x2 , float y2){
    float dx , dy ,steps ;
    dx = x2 - x1 ;
    dy = y2 - y1 ;
    if (abs(dx) > abs(dy)){
        steps = abs(dx) ;
    }
    else{
        steps = abs(dy) ;
    }
    dx = dx / steps ;
    dy = dy / steps ;
//    img.setPixel(x1 , x2,qRgb(255,255,255));
    for (int i = 0 ; i < steps ; i++){
        x1 += dx ;
        y1 += dy ;
        img.setPixel(x1 , y1 ,qRgb(255,255,255));
    }
    ui -> label -> setPixmap(QPixmap::fromImage(img));
}




void MainWindow::on_pushButton_clicked()
{
    DDA(250,0,250,500);
    DDA(0,250,500,250);
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1 , y1, x2 ,y2 ,x3 ,y3 ;
    x1 = ui->plainTextEdit->toPlainText().toFloat();
    x2 = ui->plainTextEdit_2->toPlainText().toFloat();
    x3 = ui->plainTextEdit_3->toPlainText().toFloat();
    y1 =-( ui->plainTextEdit_4->toPlainText().toFloat());
    y2 =-( ui->plainTextEdit_5->toPlainText().toFloat());
    y3 = -(ui->plainTextEdit_6->toPlainText().toFloat());
    points[0] = x1 ;
    points[1] = y1 ;
    points[2] = x2 ;
    points[3] = y2 ;
    points[4] = x3 ;
    points[5] = y3 ;
    DDA(250+points[0],points[1]+250,points[2]+250,points[3]+250);
    DDA(250+points[2],points[3]+250,points[4]+250,points[5]+250);
    DDA(points[0]+250,points[1]+250,250+points[4],points[5]+250);

}

void MainWindow::on_pushButton_3_clicked()
{
    float XT , YT ;
    XT = ui->plainTextEdit_7->toPlainText().toFloat();
    YT = ui->plainTextEdit_8->toPlainText().toFloat();
    points[0] = points[0] + XT ;
    points[1] = points[1] - YT ;
    points[2] = points[2] + XT ;
    points[3] = points[3] - YT ;
    points[4] = points[4] + XT ;
    points[5] = points[5] - YT ;
    DDA(250+points[0],points[1]+250,points[2]+250,points[3]+250);
    DDA(250+points[2],points[3]+250,points[4]+250,points[5]+250);
    DDA(points[0]+250,points[1]+250,250+points[4],points[5]+250);
}

void MainWindow::on_pushButton_4_clicked()
{
    float XS , YS ;
    XS = ui->plainTextEdit_9->toPlainText().toFloat();
    YS = ui->plainTextEdit_10->toPlainText().toFloat();
    points[0] = points[0] * XS ;
    points[1] = points[1] * YS ;
    points[2] = points[2] * XS ;
    points[3] = points[3] * YS ;
    points[4] = points[4] * XS ;
    points[5] = points[5] * YS ;
    DDA(250+points[0],points[1]+250,points[2]+250,points[3]+250);
    DDA(250+points[2],points[3]+250,points[4]+250,points[5]+250);
    DDA(points[0]+250,points[1]+250,250+points[4],points[5]+250);
}

void MainWindow::on_pushButton_5_clicked()
{
    float deg ,rad ;
    deg = ui->plainTextEdit_11->toPlainText().toFloat();
    rad = ((deg * M_PI ) / 180) ;
//    cout<<deg<<" "<<rad ;
    points[0] = points[0]*cos(rad) - points[1]*sin(rad);
    points[1] = points[0]*sin(rad) + points[1]*cos(rad);
    points[2] = points[2]*cos(rad) - points[3]*sin(rad);
    points[3] = points[2]*sin(rad) + points[3]*cos(rad);
    points[4] = points[4]*cos(rad) - points[5]*sin(rad);
    points[5] = points[4]*sin(rad) + points[5]*cos(rad);
    DDA(250+points[0],points[1]+250,points[2]+250,points[3]+250);
    DDA(250+points[2],points[3]+250,points[4]+250,points[5]+250);
    DDA(points[0]+250,points[1]+250,250+points[4],points[5]+250);
}

void MainWindow::on_pushButton_6_clicked()
{
    for(int i = 0 ;i < 500 ;i ++){
        for (int j = 0 ; j < 500 ; j++){
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui -> label -> setPixmap((QPixmap::fromImage(img)));
}
