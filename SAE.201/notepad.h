#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QProgressBar>
#include "ui_notepad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionFont_triggered();

    void on_actionItalic_triggered(bool italic);

    void on_actionBold_triggered(bool bold);

    void on_actionmessageBox_triggered();

    void on_actionColor_triggered();

    //void on_actionProgress_Bar_triggered(int value);

    //void on_pushButton_clicked(int value);

    //void on_pushButton_clicked();

    //void on_pushButton_clicked(bool checked);

    void on_pushButton_toggled(bool checked);

private:
    Ui::Notepad *ui;
    QString currentFile;
};
#endif // NOTEPAD_H
