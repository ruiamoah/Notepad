/********************************************************************************
** Form generated from reading UI file 'goto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTO_H
#define UI_GOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoTo
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineNumber;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *gotoButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *GoTo)
    {
        if (GoTo->objectName().isEmpty())
            GoTo->setObjectName(QString::fromUtf8("GoTo"));
        GoTo->resize(260, 125);
        GoTo->setMaximumSize(QSize(260, 125));
        centralwidget = new QWidget(GoTo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(260, 16777215));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 260, 125));
        groupBox->setMaximumSize(QSize(260, 125));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 221, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineNumber = new QLineEdit(layoutWidget);
        lineNumber->setObjectName(QString::fromUtf8("lineNumber"));

        verticalLayout->addWidget(lineNumber);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 80, 158, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gotoButton = new QPushButton(layoutWidget1);
        gotoButton->setObjectName(QString::fromUtf8("gotoButton"));

        horizontalLayout->addWidget(gotoButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        GoTo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GoTo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 260, 21));
        GoTo->setMenuBar(menubar);

        retranslateUi(GoTo);

        QMetaObject::connectSlotsByName(GoTo);
    } // setupUi

    void retranslateUi(QMainWindow *GoTo)
    {
        GoTo->setWindowTitle(QCoreApplication::translate("GoTo", "GoTo", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("GoTo", "Line number:", nullptr));
        lineNumber->setText(QCoreApplication::translate("GoTo", "1", nullptr));
        gotoButton->setText(QCoreApplication::translate("GoTo", "Go To", nullptr));
        cancelButton->setText(QCoreApplication::translate("GoTo", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoTo: public Ui_GoTo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTO_H
