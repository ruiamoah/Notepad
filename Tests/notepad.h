#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

#include <QFile>
#include <QToolBar>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPageSetupDialog>
#include <QTextEdit>
#include <QLabel>
#include <QFont>
#include <QFontDialog>
#include <QPainter>
#include <QMarginsF>
#include <QPageLayout>
#include <QTextDocument>
#include <QClipboard>
#include <QMimeData>
#include <QDesktopServices>
#include <QTextCursor>
#include <QSysInfo>
#include <QKeyEvent>
#include <QShortcut>
#include <QDateTime>
#include <QPlainTextEdit>
#include <QTextBlock>


QT_BEGIN_NAMESPACE
namespace Ui {
    class Notepad;
}
QT_END_NAMESPACE

class FindDialog;
class FindReplaceDialog;
class GoTo;

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

public slots:
    void helperOpen();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void closeEvent(QCloseEvent *event) override;

    void on_actionPrint_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionPage_Setup_triggered();

    void on_actionNew_Window_triggered();

    void on_actionFont_triggered();

    void on_actionWord_Wrap_toggled(bool arg1);

    void on_actionDelete_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void processDelete();

    void processPaste();

    void on_actionSearch_with_Google_triggered();

    void on_actionFind_triggered();

    void on_actionABout_Notepad_triggered();

    void on_actionView_Help_triggered();

    void on_actionSend_Feedback_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionRestore_Default_Zoom_triggered();

    void on_actionGo_To_triggered();

    void on_actionTime_Date_triggered();

    void wheelEvent(QWheelEvent *event) override;

    void on_actionStatus_Bar_toggled(bool arg1);

    void on_actionReplace_triggered();

    void on_actionFind_Next_triggered();

    void on_actionFind_Previous_triggered();

    void on_actionSelect_All_triggered();

    void on_plainTextEdit_cursorPositionChanged();

    void on_plainTextEdit_textChanged();

    void insertFromMimeData(const QMimeData * source);



public:
    Ui::Notepad *ui;
    bool newOpen = true;
    QLabel *statusLabelLnCol;
    QLabel *statusLabelZoom;
    QLabel *statusLabelCRLF;
    QLabel *statusLabelUTF8;
    QString currentFile = "";
    QPrinter printer;
    int zoom = 100;
    FindDialog *m_findDialog;
    FindReplaceDialog *m_findReplaceDialog;
    GoTo *m_goto;

};
#endif // NOTEPAD_H
