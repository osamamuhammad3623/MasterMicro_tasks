#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
using namespace std;


/********************************
    Function Definitions
********************************/
/*
Description: A function to check that user-input equation is valid
            a user-input equation is valid if:
            - consists of numbers.
            - digits [0:9]
            - operators [+,-,*,/]
            - dot (for decimal, i.e. 0.4)
            - x, any other variable is invalid
*/
bool valid_equation(string &eq);



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*
    Description: A function to initiate the graph
                - Create an instance of a graph
                - set x-axis & y-axis labels
                - give initial range for the graph [-1:1]
    */
    void graph_init();

    /*
    Description: A function to to plot the equation on the graph
                - rescale the axis to fit data/points
                - plot.
    */
    void plot(QVector<double> &x_values, QVector<double> &y_values);

private slots:
    void on_plot_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
