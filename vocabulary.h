#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class vocabulary; }
QT_END_NAMESPACE

class vocabulary : public QMainWindow
{
    Q_OBJECT

public:
    vocabulary(QWidget *parent = nullptr);
    ~vocabulary();


private slots:
    void on_okbutton_clicked();
    void on_inputbar_returnPressed();
    void readfile();
    void scorehandler();

    void on_retrybutton_clicked();

private:
    Ui::vocabulary *ui;
};
#endif // VOCABULARY_H
