#include "notepad.h"

int value = 0;

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Notepad){
        ui->setupUi(this);

        ui->progressBar->setValue(0);
        ui->progressBar->setMaximum(100);
        ui->progressBar->setMinimum(0);
        ui->progressBar->show();
    }
Notepad::~Notepad(){
        delete ui;
}

void Notepad::on_actionNew_triggered()
{
    ui->progressBar->reset();
    value = 0;
    ui->progressBar->setValue(value);
    ui->textEdit->setText(QString());
}


void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if (fileName.isEmpty())
    return;
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot open file: " +
    file.errorString());
    return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void Notepad::on_actionSave_triggered()
{
    QString fileName;
        // If we don't have a filename from before, get one.
        if (currentFile.isEmpty()) {
            fileName = QFileDialog::getSaveFileName(this, "Save");
            currentFile = fileName;
        } else {
            fileName = currentFile;
        }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
}


void Notepad::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
        QFile file(fileName);

        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }
        currentFile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
}


void Notepad::on_actionExit_triggered()
{
    QCoreApplication::quit();
}


void Notepad::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
    ui->textEdit->setCurrentFont(font);
}


void Notepad::on_actionItalic_triggered(bool italic)
{
    ui->textEdit->setFontItalic(italic);
}


void Notepad::on_actionBold_triggered(bool bold)
{
    if(!bold){
        ui->textEdit->setFontWeight(QFont::Normal);
    } else {
        ui->textEdit->setFontWeight(QFont::Bold);
    }
}

void Notepad::on_actionUnderline_triggered(bool underline)
{
    ui->textEdit->setFontUnderline(underline);
}

void Notepad::on_actionmessageBox_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
}


void Notepad::on_actionColor_triggered()
{
    QColorDialog color;
    ui->textEdit->setTextColor(color.getColor(Qt::blue, this));
}


void Notepad::on_pushButton_clicked(bool checked)
{

    ui->progressBar->setValue(value);
    if(checked == false){
        value = value + 5;
        ui->progressBar->setValue(value);
    }
    currentFile.clear();
}

void Notepad::on_pushButton_2_clicked(bool checked)
{
    ui->progressBar->setValue(value);
    if(checked == false){
        value = value - 5;
        ui->progressBar->setValue(value);
    }
    currentFile.clear();
}




