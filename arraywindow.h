#ifndef ARRAYWINDOW_H
#define ARRAYWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCloseEvent>
namespace Ui {
class arrayWindow;
}

class Pole
{
private:

public:

    char *c;
    int *i;
    float *f;
    int type; // 1 = char, 2 = int, 3 = float
    int size;
    QString meno;
    QString data;
    Pole(char *c, int s, QString m)
    {
        this->c = c;
        type = 1;
        size = s;
        meno = m;
        data = "char";

    }
    Pole(int *i, int s, QString m)
    {
        this->i = i;
        type = 2;
        size = s;
        meno = m;
        data = "int";
    }
    Pole(float *f, int s,  QString m)
    {
        this->f = f;
        type = 3;
        size = s;
        meno = m;
        data = "float";
    }


};

class Input
{
private:

public:
    char *c;
    int *i;
    float *f;
    int position;
    int type; // 1 = char, 2 = int, 3 = float
    Input(char *c, int pos)
    {
        this->c = c;
        type = 1;
        position = pos;
    }
    Input(int *i, int pos)
    {
        this->i = i;
        type = 2;
        position = pos;
    }
    Input(float *f, int pos)
    {
        this->f = f;
        type = 3;
        position = pos;
    }
};

class arrayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit arrayWindow(QWidget *parent = 0);
    ~arrayWindow();
    void foundArray(Pole *pole);
    void inputValue(Input *input);
    void vystupEnd();
private slots:

    void on_continueButton_clicked();

    void on_startButton_clicked();




private:
    Ui::arrayWindow *ui;

};
int mainProgram(arrayWindow* wnd);


#endif // ARRAYWINDOW_H


