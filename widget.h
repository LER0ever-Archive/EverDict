#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void LoadUI();
    void LoadBar();
private slots:
    void sear();
private:
    Ui::Widget *ui;
    QGridLayout *glMainLay;
    QPushButton *pbSearch;
    QLineEdit *leSearchBox;
    QTextEdit *teResult;
};

#endif // WIDGET_H
