#include "notepad.h"
#include "ui_notepad.h"
Notepad::Notepad(QWidget *parent) :
    QmainWindow(parent), ui(new Ui::Notepad)
{
    ui->setupUi(this);
}
Notepad::~Notepad()
{
    delete ui;
}
