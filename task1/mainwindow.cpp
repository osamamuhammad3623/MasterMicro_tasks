#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tinyexpr.h"
#include "QDebug"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool valid_equation(string &eq){
    for (char c : eq){
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c=='.' || c == ' '){
            /* check if char is a valid operator, or a dot for decimals */
        }else if (c >= '0' && c <= '9'){
            /* check if char is a valid digit */
        }else if (c == 'x'){
            /* check if char is the variable x */
        }else{
            return false;
        }
    }
    return true;

}

void MainWindow::graph_init(){

    /* create graph instance */
    ui->graph->addGraph();
    /* give the axes some labels */
    ui->graph->xAxis->setLabel("x");
    ui->graph->yAxis->setLabel("y");
    ui->graph->xAxis->setRange(-1, 1);
    ui->graph->yAxis->setRange(-1, 1);

}

void MainWindow::plot(QVector<double> &x_values, QVector<double> &y_values){
    /* set the plot data and plot! */
    ui->graph->graph(0)->setData(x_values, y_values);
    ui->graph->graph(0)->rescaleAxes();
    ui->graph->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->graph->replot();
}

void MainWindow::on_plot_clicked()
{
    /* validate min value x is less than max value of x  */
    double  minx = ui->min_x->value();
    double maxx = ui->max_x->value();
    if (minx >= maxx){
        ui->err_msg->setText("Error: Minimum value of x is greater than the maximum value.");
        return;
    }else{
        ui->err_msg->setText("");
    }

    int full_range = (maxx-minx)*10;
    QVector<double> x_values(full_range),y_values(full_range);

    /* fill x values from minimum to maximum range */
    for (int i=0; i< full_range;i++){
        x_values[i] = minx + 0.1*i;
    }

    /* define x variable */
    double x;
    te_variable x_var = {"x", &x};

    /* get the equation from user */
    string eq = ui->equation->text().toStdString();

    /* validate string */
    if (valid_equation(eq)){
        ui->err_msg->setText("");

        te_expr *valid_eq = te_compile(eq.c_str(), &x_var, 1, 0);

        if (valid_eq){
            for (int i=0; i< full_range; i++){
                x = x_values[i];
                y_values[i] = te_eval(valid_eq);
            }

            te_free(valid_eq);
        }

        plot(x_values, y_values);


    }else{
        ui->err_msg->setText("Error: Unvalid equation, equation has invalid digits/operators.");
        return;
    }
}

