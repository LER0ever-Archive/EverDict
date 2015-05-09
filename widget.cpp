#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
class dfile
{
public:
    vector<string> lines;
    void readfile(string fn);
};

void dfile::readfile(string fn)
{
    ifstream ifile(fn.c_str());
    string tmp;
    while(getline(ifile,tmp))
    {
        lines.push_back(tmp);
    }
    ifile.close();
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    LoadUI();
    connect(pbSearch,SIGNAL(clicked()),this,SLOT(sear()));
    connect(leSearchBox,SIGNAL(returnPressed()),this,SLOT(sear()));
}

void Widget::LoadUI()
{
    glMainLay = new QGridLayout();
    leSearchBox = new QLineEdit();
    pbSearch = new QPushButton();
    teResult = new QTextEdit();
    teResult->setReadOnly(1);
    glMainLay->addWidget(leSearchBox,5,5,5,35);
    glMainLay->addWidget(pbSearch,5,40,5,10);
    glMainLay->addWidget(teResult,15,5,40,45);
    setLayout(glMainLay);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sear()
{
    string w2s=leSearchBox->text().toStdString();
    teResult->clear();
    string strexec;
    strexec+="./dict ";
    strexec+=w2s;
    const char* cstrexec=(const char*)strexec.c_str();
    system(cstrexec);
    dfile F;
    F.readfile("result");
    QString tmp;
    for (unsigned int i=0;i<F.lines.size();i++)
    {
        //if (F.lines[i])
        tmp=QString::fromStdString(F.lines[i]);
        //QMessageBox::information(this,"test",tmp, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if (tmp.right(1)!="\n")
        teResult->append(tmp);
    }
}
