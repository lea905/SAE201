#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QColorDialog>
#include <QtWidgets>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    // Ouvre une boîte de dialogue pour sélectionner un fichier à ouvrir
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    // Crée un objet QFile en utilisant le nom de fichier obtenu précédemment
    QFile file(fileName);

    // Attribue le nom de fichier actuel à la variable currentFile
    currentFile = fileName;

    // Vérifie si le fichier peut être ouvert en lecture seule
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        // Affiche une boîte de dialogue d'avertissement avec le message d'erreur
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return; // Quitte la fonction si l'ouverture échoue
    }

    // Définit le titre de la fenêtre principale avec le nom du fichier
    setWindowTitle(fileName);

    // Crée un objet QTextStream en utilisant le fichier ouvert
    QTextStream in(&file);

    // Lit tout le contenu du fichier et le stocke dans la variable text
    QString text = in.readAll();

    // Définit le texte dans un widget QTextEdit nommé textEdit (probablement présent dans l'interface utilisateur)
    // avec le contenu du fichier
    ui->textEdit->setText(text);

    // Ferme le fichier
    file.close();
}



void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionSave_triggered()
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


void MainWindow::on_actionSave_As_triggered()
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


void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->copy();
#endif
}


void MainWindow::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setCurrentFont(font);
}


void MainWindow::on_actionPaste_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->paste();
#endif
}


void MainWindow::on_actionCut_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->paste();
#endif
}


void MainWindow::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionItalic_triggered(bool italic)
{
    ui->textEdit->setFontItalic(italic);
}


void MainWindow::on_actionUnderline_triggered(bool underline)
{
    ui->textEdit->setFontUnderline(underline);
}


void MainWindow::on_actionBold_triggered(bool bold)
{
    if(!bold){
        ui->textEdit->setFontWeight(QFont::Normal);
    }else{
        ui->textEdit->setFontWeight(QFont::Bold);
    }
}


void MainWindow::on_actionabout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
}


void MainWindow::on_actionColor_triggered()
{
    QColorDialog color;
    ui->textEdit->setTextColor(color.getColor(Qt::blue,this));
}


void MainWindow::on_actionAd_Bouton_triggered()
{
    QPushButton *button = new QPushButton("", this);
    button->setGeometry(100,350,100,100);//positionH, positionV, tailleH, tailleV
    QPushButton *button2 = new QPushButton("", this);
    button2->setGeometry(600,350,100,100);
    button->show();
    button2->show();
}


void MainWindow::on_actionAd_Label_triggered()
{
    QLineEdit *m_lineEdit = new QLineEdit("",this);
    QLineEdit *m_lineEdit2 = new QLineEdit("",this);
    m_lineEdit->setGeometry(111,360,75,20);
    m_lineEdit2->setGeometry(611,360,75,20);
    m_lineEdit->show();
    m_lineEdit2->show();
}

