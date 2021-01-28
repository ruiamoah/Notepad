/********************************************************************************
** Form generated from reading UI file 'findreplaceform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDREPLACEFORM_H
#define UI_FINDREPLACEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindReplaceForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *textToFind;
    QLabel *replaceLabel;
    QLineEdit *textToReplace;
    QLabel *errorLabel;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *downRadioButton;
    QRadioButton *upRadioButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *caseCheckBox;
    QCheckBox *wholeCheckBox;
    QCheckBox *regexCheckBox;
    QVBoxLayout *verticalLayout;
    QPushButton *findButton;
    QPushButton *closeButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FindReplaceForm)
    {
        if (FindReplaceForm->objectName().isEmpty())
            FindReplaceForm->setObjectName(QString::fromUtf8("FindReplaceForm"));
        FindReplaceForm->resize(483, 288);
        gridLayout = new QGridLayout(FindReplaceForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(FindReplaceForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        textToFind = new QLineEdit(FindReplaceForm);
        textToFind->setObjectName(QString::fromUtf8("textToFind"));

        gridLayout_3->addWidget(textToFind, 0, 1, 1, 1);

        replaceLabel = new QLabel(FindReplaceForm);
        replaceLabel->setObjectName(QString::fromUtf8("replaceLabel"));

        gridLayout_3->addWidget(replaceLabel, 1, 0, 1, 1);

        textToReplace = new QLineEdit(FindReplaceForm);
        textToReplace->setObjectName(QString::fromUtf8("textToReplace"));

        gridLayout_3->addWidget(textToReplace, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        verticalLayout_5->addLayout(verticalLayout_2);

        errorLabel = new QLabel(FindReplaceForm);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));

        verticalLayout_5->addWidget(errorLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(FindReplaceForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        downRadioButton = new QRadioButton(groupBox);
        downRadioButton->setObjectName(QString::fromUtf8("downRadioButton"));
        downRadioButton->setChecked(true);

        verticalLayout_3->addWidget(downRadioButton);

        upRadioButton = new QRadioButton(groupBox);
        upRadioButton->setObjectName(QString::fromUtf8("upRadioButton"));

        verticalLayout_3->addWidget(upRadioButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(FindReplaceForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        caseCheckBox = new QCheckBox(groupBox_2);
        caseCheckBox->setObjectName(QString::fromUtf8("caseCheckBox"));

        verticalLayout_4->addWidget(caseCheckBox);

        wholeCheckBox = new QCheckBox(groupBox_2);
        wholeCheckBox->setObjectName(QString::fromUtf8("wholeCheckBox"));

        verticalLayout_4->addWidget(wholeCheckBox);

        regexCheckBox = new QCheckBox(groupBox_2);
        regexCheckBox->setObjectName(QString::fromUtf8("regexCheckBox"));

        verticalLayout_4->addWidget(regexCheckBox);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, -1, -1, -1);
        findButton = new QPushButton(FindReplaceForm);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        //findButton->setEnabled(false);

        verticalLayout->addWidget(findButton);

        closeButton = new QPushButton(FindReplaceForm);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);

        replaceButton = new QPushButton(FindReplaceForm);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));
        //replaceButton->setEnabled(false);

        verticalLayout->addWidget(replaceButton);

        replaceAllButton = new QPushButton(FindReplaceForm);
        replaceAllButton->setObjectName(QString::fromUtf8("replaceAllButton"));
        //replaceAllButton->setEnabled(false);

        verticalLayout->addWidget(replaceAllButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

#if QT_CONFIG(shortcut)
        label->setBuddy(textToFind);
        replaceLabel->setBuddy(textToReplace);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(textToFind, textToReplace);
        QWidget::setTabOrder(textToReplace, downRadioButton);
        QWidget::setTabOrder(downRadioButton, upRadioButton);
        QWidget::setTabOrder(upRadioButton, caseCheckBox);
        QWidget::setTabOrder(caseCheckBox, wholeCheckBox);
        QWidget::setTabOrder(wholeCheckBox, regexCheckBox);
        QWidget::setTabOrder(regexCheckBox, findButton);
        QWidget::setTabOrder(findButton, closeButton);

        retranslateUi(FindReplaceForm);

        QMetaObject::connectSlotsByName(FindReplaceForm);
    } // setupUi

    void retranslateUi(QWidget *FindReplaceForm)
    {
        FindReplaceForm->setWindowTitle(QCoreApplication::translate("FindReplaceForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("FindReplaceForm", "Fi&nd:", nullptr));
        replaceLabel->setText(QCoreApplication::translate("FindReplaceForm", "R&eplace with:", nullptr));
        errorLabel->setText(QCoreApplication::translate("FindReplaceForm", "errorLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FindReplaceForm", "D&irection", nullptr));
        downRadioButton->setText(QCoreApplication::translate("FindReplaceForm", "&Down", nullptr));
        upRadioButton->setText(QCoreApplication::translate("FindReplaceForm", "&Up", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FindReplaceForm", "&Options", nullptr));
        caseCheckBox->setText(QCoreApplication::translate("FindReplaceForm", "Case &sensitive", nullptr));
        wholeCheckBox->setText(QCoreApplication::translate("FindReplaceForm", "&Whole words only", nullptr));
#if QT_CONFIG(tooltip)
        regexCheckBox->setToolTip(QCoreApplication::translate("FindReplaceForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">whether the text to search should be interpreted as a regular expression.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You may want to take a look at the syntax of regular expressions:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://do"
                        "c.trolltech.com/qregexp.html\"><span style=\" text-decoration: underline; color:#0000ff;\">http://doc.trolltech.com/qregexp.html</span></a></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        regexCheckBox->setText(QCoreApplication::translate("FindReplaceForm", "Regular E&xpression", nullptr));
        findButton->setText(QCoreApplication::translate("FindReplaceForm", "&Find", nullptr));
        closeButton->setText(QCoreApplication::translate("FindReplaceForm", "&Close", nullptr));
        replaceButton->setText(QCoreApplication::translate("FindReplaceForm", "&Replace", nullptr));
        replaceAllButton->setText(QCoreApplication::translate("FindReplaceForm", "Replace &All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindReplaceForm: public Ui_FindReplaceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDREPLACEFORM_H
