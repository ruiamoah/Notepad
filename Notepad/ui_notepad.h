/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPage_Setup;
    QAction *actionNew_Window;
    QAction *actionABout_Notepad;
    QAction *actionView_Help;
    QAction *actionSend_Feedback;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionRestore_Default_Zoom;
    QAction *actionStatus_Bar;
    QAction *actionWord_Wrap;
    QAction *actionFont;
    QAction *actionDelete;
    QAction *actionFind;
    QAction *actionFind_Next;
    QAction *actionFind_Previous;
    QAction *actionReplace;
    QAction *actionGo_To;
    QAction *actionSearch_with_Google;
    QAction *actionSelect_All;
    QAction *actionTime_Date;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QMenu *menuView;
    QMenu *menuZoom;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QString::fromUtf8("Notepad"));
        Notepad->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Icons/notepad.png"), QSize(), QIcon::Normal, QIcon::Off);
        Notepad->setWindowIcon(icon);
        actionNew = new QAction(Notepad);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(Notepad);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionPrint = new QAction(Notepad);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Icons/print.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPrint->setIcon(icon3);
        actionExit = new QAction(Notepad);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionCopy = new QAction(Notepad);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionCopy->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Icons/copy.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(Notepad);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionPaste->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPaste->setIcon(icon6);
        actionCut = new QAction(Notepad);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCut->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Icons/cut.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCut->setIcon(icon7);
        actionUndo = new QAction(Notepad);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionUndo->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/Icons/undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(Notepad);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionRedo->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/Icons/redo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRedo->setIcon(icon9);
        actionSave = new QAction(Notepad);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon10);
        actionSave_As = new QAction(Notepad);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/Icons/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon11);
        actionPage_Setup = new QAction(Notepad);
        actionPage_Setup->setObjectName(QString::fromUtf8("actionPage_Setup"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/Icons/pagesetup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPage_Setup->setIcon(icon12);
        actionNew_Window = new QAction(Notepad);
        actionNew_Window->setObjectName(QString::fromUtf8("actionNew_Window"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/Icons/new-window.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Window->setIcon(icon13);
        actionABout_Notepad = new QAction(Notepad);
        actionABout_Notepad->setObjectName(QString::fromUtf8("actionABout_Notepad"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/Icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionABout_Notepad->setIcon(icon14);
        actionView_Help = new QAction(Notepad);
        actionView_Help->setObjectName(QString::fromUtf8("actionView_Help"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_Help->setIcon(icon15);
        actionSend_Feedback = new QAction(Notepad);
        actionSend_Feedback->setObjectName(QString::fromUtf8("actionSend_Feedback"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/Icons/feedback.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSend_Feedback->setIcon(icon16);
        actionZoom_In = new QAction(Notepad);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/Icons/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon17);
        actionZoom_Out = new QAction(Notepad);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/Icons/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon18);
        actionRestore_Default_Zoom = new QAction(Notepad);
        actionRestore_Default_Zoom->setObjectName(QString::fromUtf8("actionRestore_Default_Zoom"));
        actionStatus_Bar = new QAction(Notepad);
        actionStatus_Bar->setObjectName(QString::fromUtf8("actionStatus_Bar"));
        actionStatus_Bar->setCheckable(true);
        actionStatus_Bar->setChecked(true);
        actionWord_Wrap = new QAction(Notepad);
        actionWord_Wrap->setObjectName(QString::fromUtf8("actionWord_Wrap"));
        actionWord_Wrap->setCheckable(true);
        actionWord_Wrap->setChecked(true);
        actionFont = new QAction(Notepad);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/Icons/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFont->setIcon(icon19);
        actionDelete = new QAction(Notepad);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionDelete->setEnabled(false);
        actionFind = new QAction(Notepad);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/Icons/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon20);
        actionFind_Next = new QAction(Notepad);
        actionFind_Next->setObjectName(QString::fromUtf8("actionFind_Next"));
        actionFind_Previous = new QAction(Notepad);
        actionFind_Previous->setObjectName(QString::fromUtf8("actionFind_Previous"));
        actionReplace = new QAction(Notepad);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/Icons/replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon21);
        actionGo_To = new QAction(Notepad);
        actionGo_To->setObjectName(QString::fromUtf8("actionGo_To"));
        actionSearch_with_Google = new QAction(Notepad);
        actionSearch_with_Google->setObjectName(QString::fromUtf8("actionSearch_with_Google"));
        actionSearch_with_Google->setEnabled(false);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/Icons/google.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch_with_Google->setIcon(icon22);
        actionSelect_All = new QAction(Notepad);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/Icons/select-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon23);
        actionTime_Date = new QAction(Notepad);
        actionTime_Date->setObjectName(QString::fromUtf8("actionTime_Date"));
        centralwidget = new QWidget(Notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 771, 531));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        plainTextEdit->setFont(font);

        verticalLayout->addWidget(plainTextEdit);

        Notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Notepad);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuZoom = new QMenu(menuView);
        menuZoom->setObjectName(QString::fromUtf8("menuZoom"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(Notepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(Notepad);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        Notepad->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionNew_Window);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPage_Setup);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSearch_with_Google);
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionFind_Next);
        menuEdit->addAction(actionFind_Previous);
        menuEdit->addAction(actionReplace);
        menuEdit->addAction(actionGo_To);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionTime_Date);
        menuFormat->addAction(actionWord_Wrap);
        menuFormat->addAction(actionFont);
        menuView->addAction(menuZoom->menuAction());
        menuView->addAction(actionStatus_Bar);
        menuZoom->addAction(actionZoom_In);
        menuZoom->addAction(actionZoom_Out);
        menuZoom->addAction(actionRestore_Default_Zoom);
        menuHelp->addAction(actionView_Help);
        menuHelp->addAction(actionSend_Feedback);
        menuHelp->addSeparator();
        menuHelp->addAction(actionABout_Notepad);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionNew_Window);
        toolBar->addSeparator();
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_As);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint);
        toolBar->addAction(actionPage_Setup);
        toolBar->addSeparator();
        toolBar->addAction(actionFont);
        toolBar->addSeparator();
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionSelect_All);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionSearch_with_Google);
        toolBar->addSeparator();
        toolBar->addAction(actionFind);
        toolBar->addAction(actionReplace);
        toolBar->addSeparator();
        toolBar->addAction(actionZoom_In);
        toolBar->addAction(actionZoom_Out);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);
        toolBar->addSeparator();

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QCoreApplication::translate("Notepad", "Notepad", nullptr));
        actionNew->setText(QCoreApplication::translate("Notepad", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("Notepad", "Open...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("Notepad", "Print...", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("Notepad", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Notepad", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("Notepad", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("Notepad", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("Notepad", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("Notepad", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("Notepad", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("Notepad", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("Notepad", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPage_Setup->setText(QCoreApplication::translate("Notepad", "Page Setup...", nullptr));
        actionNew_Window->setText(QCoreApplication::translate("Notepad", "New Window", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Window->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionABout_Notepad->setText(QCoreApplication::translate("Notepad", "About Notepad", nullptr));
        actionView_Help->setText(QCoreApplication::translate("Notepad", "View Help", nullptr));
        actionSend_Feedback->setText(QCoreApplication::translate("Notepad", "Send Feedback", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("Notepad", "Zoom In", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_In->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Out->setText(QCoreApplication::translate("Notepad", "Zoom Out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Out->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRestore_Default_Zoom->setText(QCoreApplication::translate("Notepad", "Restore Default Zoom", nullptr));
#if QT_CONFIG(shortcut)
        actionRestore_Default_Zoom->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+0", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStatus_Bar->setText(QCoreApplication::translate("Notepad", "Status Bar", nullptr));
        actionWord_Wrap->setText(QCoreApplication::translate("Notepad", "Word Wrap", nullptr));
        actionFont->setText(QCoreApplication::translate("Notepad", "Font...", nullptr));
        actionDelete->setText(QCoreApplication::translate("Notepad", "Delete", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete->setShortcut(QCoreApplication::translate("Notepad", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("Notepad", "Find...", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind_Next->setText(QCoreApplication::translate("Notepad", "Find Next", nullptr));
#if QT_CONFIG(shortcut)
        actionFind_Next->setShortcut(QCoreApplication::translate("Notepad", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind_Previous->setText(QCoreApplication::translate("Notepad", "Find Previous", nullptr));
#if QT_CONFIG(shortcut)
        actionFind_Previous->setShortcut(QCoreApplication::translate("Notepad", "Shift+F3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("Notepad", "Replace...", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGo_To->setText(QCoreApplication::translate("Notepad", "Go To...", nullptr));
#if QT_CONFIG(shortcut)
        actionGo_To->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSearch_with_Google->setText(QCoreApplication::translate("Notepad", "Search with Google...", nullptr));
#if QT_CONFIG(shortcut)
        actionSearch_with_Google->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_All->setText(QCoreApplication::translate("Notepad", "Select All", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_All->setShortcut(QCoreApplication::translate("Notepad", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTime_Date->setText(QCoreApplication::translate("Notepad", "Time/Date", nullptr));
#if QT_CONFIG(shortcut)
        actionTime_Date->setShortcut(QCoreApplication::translate("Notepad", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("Notepad", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Notepad", "Edit", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("Notepad", "Format", nullptr));
        menuView->setTitle(QCoreApplication::translate("Notepad", "View", nullptr));
        menuZoom->setTitle(QCoreApplication::translate("Notepad", "Zoom", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Notepad", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Notepad", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
