#include "extrawhitespaceeliminator.h"
#include "ui_extrawhitespaceeliminator.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

ExtraWhiteSpaceEliminator::ExtraWhiteSpaceEliminator(QWidget *parent): QWidget(parent), ui(new Ui::ExtraWhiteSpaceEliminator)
{
    ui->setupUi(this);
    loadTextFile();
}

ExtraWhiteSpaceEliminator::~ExtraWhiteSpaceEliminator()
{
    delete ui;
}


void ExtraWhiteSpaceEliminator::on_removeButton_clicked()
{
    QString searchString = ui->fileSelect->text();

    //QString completeInputFileName = ":/" + searchString + ".txt";
    QString completeInputFileName = searchString;
    QFile inputFile(completeInputFileName);
    inputFile.open(QIODevice::ReadOnly);
    QString output;

    while(!inputFile.atEnd())
    {
        QString line = inputFile.readLine();

        int loop;
        for(loop = 0; loop < (line.size() - 1); loop++)
        {
            if(!(line.at(loop) == ' ' && line.at(loop + 1) == ' '))
            {
                output += line.at(loop);
            }
        }
            output += line.at(loop);
    }

    //output.remove(output.back());

    int dotLoc = searchString.lastIndexOf(QChar('.'));

    QString outputFileName = searchString.left(dotLoc) + "Converted" + ".txt";
    QFile outputFile(outputFileName);
    outputFile.open(QIODevice::WriteOnly);

    QTextStream outputText(&outputFile);
    outputText << output;



    inputFile.close();

    //outputFile.flush();
    outputFile.close();

}

void ExtraWhiteSpaceEliminator::loadTextFile()
{
    QFile instructions(":/instructions.txt");
    instructions.open(QIODevice::ReadOnly);

    QTextStream in(&instructions);
    QString line = in.readAll();
    instructions.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}


void ExtraWhiteSpaceEliminator::on_selectFile_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, "Choose File");
        if (filename.isEmpty())
            return;
        ui->fileSelect->setText(filename);

        QFile fileToPreview(filename);
        fileToPreview.open(QIODevice::ReadOnly);
        QString line = fileToPreview.readAll();
        fileToPreview.close();

        ui->preview->setPlainText(line);
        QTextCursor cursor = ui->preview->textCursor();
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

