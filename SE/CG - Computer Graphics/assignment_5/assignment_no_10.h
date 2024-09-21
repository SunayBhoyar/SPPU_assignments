#ifndef ASSIGNMENT_NO_10_H
#define ASSIGNMENT_NO_10_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Assignment_No_10; }
QT_END_NAMESPACE

class Assignment_No_10 : public QMainWindow
{
    Q_OBJECT

public:
    Assignment_No_10(QWidget *parent = nullptr);
    ~Assignment_No_10();
    void koch(float,float,float,float,float);
    void DDA_Line(float,float,float,float);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Assignment_No_10 *ui;
};
#endif // ASSIGNMENT_NO_10_H
