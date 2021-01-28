#ifndef GOTO_H
#define GOTO_H

#include <QMainWindow>
#include <QIntValidator>
#include <QTextCursor>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class GoTo; }
QT_END_NAMESPACE

class QPlainTextEdit;
class QTextEdit;
class QSettings;
class QEvent;
class QShowEvent;

class GoTo : public QMainWindow
{
    Q_OBJECT

public:
    GoTo(QWidget *parent = nullptr);
    ~GoTo();

private slots:
    void on_gotoButton_clicked();

    void on_cancelButton_clicked();

    void on_lineNumber_returnPressed();

public slots:
    void setPlainTextEdit(QPlainTextEdit* plainTextEdit_);

    void setTextCursor(QTextCursor textCursor_);
private:
    Ui::GoTo *ui;
    QPlainTextEdit* plainTextEdit;
    QTextCursor textCursor;

};
#endif // GOTO_H
