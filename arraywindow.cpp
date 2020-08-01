#include "arraywindow.h"
#include "ui_arraywindow.h"
#include <QString>
#include <QDebug>
#include <QCoreApplication>
#include <QInputDialog>
#include <QMessageBox>



int redRow;
int redColumn;
int id = 0;
bool continuePressed = false;
bool isValidInput = false;
bool ok;
QStringList arrayList;
QMap <QString, int> arrayMap;
QString text;
void arrayWindow::foundArray(Pole *pole)
{
    if(!arrayList.contains(pole->meno))
    {
        arrayList.append(pole->meno);
        arrayMap[pole->meno] = id;
        ui->tableWidget->insertRow(id);
        ui->tableWidget->setVerticalHeaderItem(id, new QTableWidgetItem(pole->data + " " + pole->meno + "[" + QString::number(pole->size) + "]"));
        id++;
        for (int i = 0; i < pole->size; i++)
        {
            if (!ui->tableWidget->horizontalHeaderItem(i))
            {
                ui->tableWidget->insertColumn(i);
            }

        }
    }
    for (int i = 0; i < pole->size; i++)
    {
        ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        if (pole->type == 1)
        {
            if (ui->tableWidget->item(arrayMap[pole->meno], i) != NULL)
            {
                if (ui->tableWidget->item(arrayMap[pole->meno], i)->text() != QString(*(pole->c + i)))
                {
                    ui->nameLabel->setText("Zmena na " + pole->meno +
                    "[" + QString::number(pole->size) + "]" + " v " + QString::number(i) + " stlpci");
                    ui->tableWidget->item(arrayMap[pole->meno], i)->setBackground(Qt::red);
                    ui->tableWidget->item(arrayMap[pole->meno], i)->setText(QString(*(pole->c + i)));
                    redRow = arrayMap[pole->meno];
                    redColumn = i;
                }
            }
            else
            {
                ui->tableWidget->setItem(arrayMap[pole->meno], i, new QTableWidgetItem(QString(*(pole->c + i))));
            }

        }
        else if (pole->type == 2)
        {
            if (ui->tableWidget->item(arrayMap[pole->meno], i) != NULL)
            {
                if (ui->tableWidget->item(arrayMap[pole->meno], i)->text() != QString::number(*(pole->i + i)))
                {
                    ui->nameLabel->setText("Zmena na " + pole->meno + "[" + QString::number(pole->size) + "]" + " v " + QString::number(i) + " stlpci");
                    ui->tableWidget->item(arrayMap[pole->meno], i)->setBackground(Qt::red);
                    ui->tableWidget->item(arrayMap[pole->meno], i)->setText(QString::number(*(pole->i + i)));
                    redRow = arrayMap[pole->meno];
                    redColumn = i;
                }
            }
            else
            {
                ui->tableWidget->setItem(arrayMap[pole->meno], i, new QTableWidgetItem(QString::number(*(pole->i + i))));
            }
        }
        else if (pole->type == 3)
        {
            if (ui->tableWidget->item(arrayMap[pole->meno], i) != NULL)
            {
                if (ui->tableWidget->item(arrayMap[pole->meno], i)->text() != QString::number(*(pole->f + i)))
                {
                    ui->nameLabel->setText("Zmena na " + pole->meno + "[" + QString::number(pole->size) + "]" + " v " + QString::number(i) + " stlpci");
                    ui->tableWidget->item(arrayMap[pole->meno], i)->setBackground(Qt::red);
                    ui->tableWidget->item(arrayMap[pole->meno], i)->setText(QString::number(*(pole->f + i)));
                    redRow = arrayMap[pole->meno];
                    redColumn = i;
                }
            }
            else
            {
                ui->tableWidget->setItem(arrayMap[pole->meno], i, new QTableWidgetItem(QString::number(*(pole->f + i))));
            }

        }


    }

    continuePressed = false;
    while (continuePressed == false && !this->isHidden())
    {
        QCoreApplication::processEvents();
    }

}

void arrayWindow::inputValue(Input *input)
{
    isValidInput = false;
    if (!this->isHidden())
    {

        if(input->type == 1)
        {
            while (isValidInput == false)
            {
                text = QInputDialog::getText(this, tr("Scanf"), tr("Zadaj znak!"), QLineEdit::Normal);
                if (text.length() > 1)
                {
                    QMessageBox::critical(this, tr("Interpreter"), tr("Zadaj len 1 pismeno!"), QMessageBox::Ok);
                }
                if (text.length() <= 1)
                {
                    isValidInput = true;
                }

            }

            *(input->c + input->position) = text.toStdString().c_str()[0];
        }
        if(input->type == 2)
        {
            *(input->i + input->position) = QInputDialog::getInt(this, tr("Scanf"), tr("Zadaj cele cislo!"), QLineEdit::Normal);
        }
        if(input->type == 3)
        {
           *(input->f + input->position) = QInputDialog::getDouble(this, tr("Scanf"), tr("Zadaj desatinnu hodnotu!"), QLineEdit::Normal);
        }
    }

}

void arrayWindow::vystupEnd()
{
    ui->startButton->setEnabled(true);
    ui->continueButton->setEnabled(false);
    ui->nameLabel->setText("");
    ui->tableWidget->model()->removeRows(0, ui->tableWidget->model()->rowCount());
    ui->tableWidget->model()->removeColumns(0, ui->tableWidget->model()->columnCount());
    redRow = 0;
    redColumn = 0;
    continuePressed = true;
}

arrayWindow::arrayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::arrayWindow)
{
    ui->setupUi(this);
    ui->continueButton->setDisabled(true);
    ui->nameLabel->setText("");

}

arrayWindow::~arrayWindow()
{
    delete ui;
}

void arrayWindow::on_continueButton_clicked()
{
    continuePressed = true;
    ui->nameLabel->setText("");
    ui->tableWidget->item(redRow, redColumn)->setBackground(Qt::white);
    redRow = 0;
    redColumn = 0;

}

void arrayWindow::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->continueButton->setEnabled(true);
    arrayMap.clear();
    for (int i = arrayList.length(); i > 0; i--)
    {
        arrayList.removeLast();
    }
    id = 0;
    mainProgram(this);


}


