#ifndef EXTRAWHITESPACEELIMINATOR_H
#define EXTRAWHITESPACEELIMINATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ExtraWhiteSpaceEliminator; }
QT_END_NAMESPACE

class ExtraWhiteSpaceEliminator : public QWidget
{
    Q_OBJECT

public:
    ExtraWhiteSpaceEliminator(QWidget *parent = nullptr);
    ~ExtraWhiteSpaceEliminator();

private slots:
    void on_removeButton_clicked();

    void on_selectFile_clicked();

private:
    Ui::ExtraWhiteSpaceEliminator *ui;
    void loadTextFile();
};
#endif // EXTRAWHITESPACEELIMINATOR_H
