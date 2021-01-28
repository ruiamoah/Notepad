#include "goto.h"
#include "ui_goto.h"
#include <QTextEdit>
#include <QTextCursor>
#include <QMessageBox>
#include <QDebug>
GoTo::GoTo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GoTo), plainTextEdit(0), textCursor()
{
    ui->setupUi(this);
    auto input = ui->lineNumber;
    input->setValidator( new QIntValidator(0 , INT_MAX, this) );
}

GoTo::~GoTo()
{
    delete ui;
}

void GoTo::setPlainTextEdit(QPlainTextEdit* plainTextEdit_) {
    plainTextEdit = plainTextEdit_;
}

void GoTo::setTextCursor(QTextCursor textCursor_) {
    textCursor = textCursor_;
}

void GoTo::on_gotoButton_clicked()
{
    QString lineNumber = ui->lineNumber->text();
    int input = lineNumber.toInt();
    int maxLn = plainTextEdit->document()->blockCount();
    if (input <= 0 || input > maxLn) {
        QMessageBox msgBox;
        msgBox.setText("The line number is beyond the total number of lines");
        msgBox.setWindowIconText("Notepad - Goto Line");
        msgBox.exec();
        lineNumber.setNum(1);
        return;
    }

    textCursor.movePosition(QTextCursor::Start);
    textCursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, input - 1);
    textCursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 0);

    plainTextEdit->setTextCursor(textCursor);

    qDebug() << input;
    this->close();
}


void GoTo::on_cancelButton_clicked()
{
    this->close();
}


void GoTo::on_lineNumber_returnPressed()
{
    GoTo::on_gotoButton_clicked();
}
