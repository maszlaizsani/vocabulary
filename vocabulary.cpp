#include "vocabulary.h"
#include "ui_vocabulary.h"
#include "QLineEdit"
#include "QFile"
#include "QFileDialog"

QString beirtszo="";
QString kiirtszo="def";
int score=0;
int questnum=0;
QString lines[20];
int index=0;

vocabulary::vocabulary(QWidget *parent) //draws the window and the widgets
    : QMainWindow(parent)
    , ui(new Ui::vocabulary)
{
    ui->setupUi(this);
    readfile();
    ui->inputbar->hide();
    ui->questionlabel->hide();
    ui->scorelabel->hide();
    ui->retrybutton->hide();
}

vocabulary::~vocabulary()
{
    delete ui;
}


void vocabulary::on_okbutton_clicked()
{
    beirtszo=ui->inputbar->text(); //stores the inserted word

    if (beirtszo==lines[index].mid(lines[index].indexOf(";")+1, lines[index].length()) && questnum!=0)
    {
        score++;
        questnum++;
    }

    if (questnum>0 && beirtszo!=lines[index].mid(lines[index].indexOf(";")+1, lines[index].length()))
    {
        score--;
        questnum++;
    }

   //showing widgets on first click
    if (kiirtszo=="def")
    {

        ui->inputbar->show();
        ui->questionlabel->show();
        ui->scorelabel->show();

        questnum++;
    }


  //updates the widgets
    ui->scorelabel->setText("Score: " + QString::number(score));
    ui->questionlabel->setText("Question " + QString::number(questnum));
    ui->inputbar->setText("");


  //generates and outputs a new world on every click
    if (questnum<21)
    {
        index=rand()%20;
        kiirtszo=lines[index].mid(0,lines[index].indexOf(";"));
        ui->mainmessage->setText(kiirtszo);
    }

  //Handles scores after a round of 20 words
    if (questnum==21)
    {
        vocabulary::scorehandler();
    }

}


void vocabulary::on_inputbar_returnPressed() //does the same as the on_okbutton_clicked()
{
    vocabulary::on_okbutton_clicked();
}


void vocabulary::readfile() //opens the txt and stores the words in lines
{
    QFile file("source.txt");
    while (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream instream(&file);

    int i=0;
    while (!instream.atEnd())
    {
        lines[i]=instream.readLine();
        i++;
    }

}

void vocabulary::scorehandler()
{
   //restructures the window
    ui->inputbar->hide();
    ui->okbutton->hide();
    ui->scorelabel->hide();
    ui->questionlabel->hide();
    ui->retrybutton->show();

   //Outputs a message based on the score
    if ((score>=17) && (score<20)) ui->mainmessage->setText("Perfect round! Your score is " + QString::number(score));
    if ((score>=11) && (score<17)) ui->mainmessage->setText("Nice one! Your score is " + QString::number(score));
    if ((score>=7) && (score<11)) ui->mainmessage->setText("Do better! Your score is " + QString::number(score));
    if (score<7) ui->mainmessage->setText("Ouch! Your score is " + QString::number(score) + "...");
}

void vocabulary::on_retrybutton_clicked()
{
    score=0;
    questnum=0;
    ui->inputbar->show();
    ui->okbutton->show();
    ui->scorelabel->show();
    ui->questionlabel->show();
    ui->retrybutton->hide();
    vocabulary::on_okbutton_clicked();

}

