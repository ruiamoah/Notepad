#ifndef TST_NOTEPADTESTCASE_H
#define TST_NOTEPADTESTCASE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QApplication>
#include <notepad.h>
#include "ui_notepad.h"
#include <QPlainTextEdit>
#include <QSignalSpy>
#include <QDebug>
#include <QtUiTools>
#include <QTest>

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &qString, ::std::ostream *os)
{
    *os << qUtf8Printable(qString);
}
QT_END_NAMESPACE


using namespace ::testing;

class NotepadTest:  public testing::Test {
public:
    NotepadTest( ) {
        // initialization code here

    }

    void SetUp( ) {
        // code here will execute just before the test ensues


    }

    void TearDown( ) {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be

    }

    ~NotepadTest( )  {
        // cleanup any pending stuff, but no exceptions allowed

    }

    Notepad notepad;
    QPlainTextEdit* plainTextEdit = notepad.ui->plainTextEdit;

    int blockCount() const
    {
        int blocks = 0;
        for (QTextBlock block = plainTextEdit->document()->begin(); block.isValid(); block = block.next())
            ++blocks;
        return blocks;
    }

    // put in any custom data members that you need


};



TEST_F (NotepadTest, TestingTrue) {

    EXPECT_EQ(1, 1);
}
TEST_F (NotepadTest, testingStatusLabelLnCol) {
    notepad.ui->plainTextEdit->moveCursor (QTextCursor::End);
    notepad.ui->plainTextEdit->insertPlainText("1234567");
    notepad.ui->plainTextEdit->moveCursor (QTextCursor::End);
    QString strLnCol = " Ln: " + QString::number(1) + ", Col: " + QString::number(8);
    ASSERT_EQ(QString(notepad.statusLabelLnCol->text()),  QString(strLnCol.leftJustified(30, ' ')));
}

TEST_F (NotepadTest, testingStatusLabelZoom) {
    notepad.ui->plainTextEdit->insertPlainText("1234567");

    notepad.on_actionZoom_In_triggered();
    notepad.on_actionZoom_In_triggered();
    notepad.on_actionZoom_In_triggered();

    QString strZoom = " " + QString::number(130) + "%";
    notepad.statusLabelZoom->setText(strZoom.leftJustified(10, ' '));
    ASSERT_EQ(QString(notepad.statusLabelZoom->text()),  QString(strZoom.leftJustified(10, ' ')));

    notepad.on_actionZoom_Out_triggered();
    notepad.on_actionZoom_Out_triggered();
    notepad.on_actionZoom_Out_triggered();
    notepad.on_actionZoom_Out_triggered();
    notepad.on_actionZoom_Out_triggered();

    strZoom = " " + QString::number(70) + "%";
    notepad.statusLabelZoom->setText(strZoom.leftJustified(10, ' '));
    ASSERT_EQ(QString(notepad.statusLabelZoom->text()),  QString(strZoom.leftJustified(10, ' ')));

    notepad.on_actionRestore_Default_Zoom_triggered();

    strZoom = " " + QString::number(100) + "%";
    notepad.statusLabelZoom->setText(strZoom.leftJustified(10, ' '));
    ASSERT_EQ(QString(notepad.statusLabelZoom->text()),  QString(strZoom.leftJustified(10, ' ')));

}

TEST_F (NotepadTest, testingWritingBasicText) {
    plainTextEdit->setPlainText("hello");
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("hello"));

    plainTextEdit->setPlainText("<b>bold   bold</b>");
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("<b>bold   bold</b>"));

    plainTextEdit->setPlainText("with   space");
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("with   space"));

}

TEST_F (NotepadTest, testingSelectionChanged) {
    plainTextEdit->setPlainText("Hello World");
    plainTextEdit->moveCursor(QTextCursor::Start);
    QSignalSpy selectionChangedSpy(plainTextEdit, SIGNAL(selectionChanged()));


    QTest::keyClick(plainTextEdit, Qt::Key_Right);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 1);
    ASSERT_EQ(selectionChangedSpy.count(), 0);

    QTest::keyClick(plainTextEdit, Qt::Key_Right, Qt::ShiftModifier);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 2);
    ASSERT_EQ(selectionChangedSpy.count(), 1);

    QTest::keyClick(plainTextEdit, Qt::Key_Right, Qt::ShiftModifier);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 3);
    ASSERT_EQ(selectionChangedSpy.count(), 2);

    QTest::keyClick(plainTextEdit, Qt::Key_Right, Qt::ShiftModifier);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 4);
    ASSERT_EQ(selectionChangedSpy.count(), 3);

    QTest::keyClick(plainTextEdit, Qt::Key_Right);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 4);
    ASSERT_EQ(selectionChangedSpy.count(), 4);

    QTest::keyClick(plainTextEdit, Qt::Key_Right);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 5);
    ASSERT_EQ(selectionChangedSpy.count(), 4);

}

TEST_F (NotepadTest, testingCursorRect) {
    plainTextEdit->setPlainText("Hello Test World");

    plainTextEdit->setCursorWidth(1);
    ASSERT_EQ(plainTextEdit->cursorRect().width(), 1);

    plainTextEdit->setCursorWidth(2);
    ASSERT_EQ(plainTextEdit->cursorRect().width(), 2);

    plainTextEdit->setCursorWidth(4);
    ASSERT_EQ(plainTextEdit->cursorRect().width(), 4);

    plainTextEdit->setCursorWidth(10);
    ASSERT_EQ(plainTextEdit->cursorRect().width(), 10);
}
class PublicTextEdit : public QPlainTextEdit
{
public:
    void publicInsertFromMimeData(const QMimeData *source)
    { insertFromMimeData(source); }
};

TEST_F (NotepadTest, testingPasteFromQtString) {

    QMimeData mimeData;
    mimeData.setText("Testing with googletest framework, This is String");
    static_cast<PublicTextEdit *>(plainTextEdit)->publicInsertFromMimeData(&mimeData);

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString("Testing with googletest framework, This is String"));

    plainTextEdit->clear();

    mimeData.setText("Testing again with googletest framework, This is String");
    static_cast<PublicTextEdit *>(plainTextEdit)->publicInsertFromMimeData(&mimeData);

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString("Testing again with googletest framework, This is String"));
}

TEST_F (NotepadTest, testingSelectAllCopyPaste) {

    QString qString = "Qt is a free and open-source widget toolkit for creating graphical user"
        " interfaces as well as cross-platform applications that run on various software and hardware ";

    plainTextEdit->insertPlainText(qString);
    notepad.on_actionSelect_All_triggered();
    notepad.on_actionCopy_triggered();
    notepad.on_actionPaste_triggered();

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString(qString));

    notepad.on_actionPaste_triggered();

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString(qString + qString));

    notepad.on_actionPaste_triggered();

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString(qString + qString + qString));

    notepad.on_actionSelect_All_triggered();
    notepad.on_actionCut_triggered();

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString());

    notepad.on_actionPaste_triggered();

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString(qString + qString + qString));

    notepad.on_actionPaste_triggered();

    ASSERT_EQ(QString(plainTextEdit->toPlainText()), QString(qString + qString + qString + qString + qString + qString));

}

TEST_F (NotepadTest, testingGetSetCheck) {


    // QTextDocument * QPlainTextEdit::document()
    // void QPlainTextEdit::setDocument(QTextDocument *)
    QTextDocument *var1 = new QTextDocument;
    plainTextEdit->setDocument(var1);
    //ASSERT_EQ(QTextDocument(var1), QTextDocument(plainTextEdit.document()));
    plainTextEdit->setDocument((QTextDocument *)0);
    ASSERT_TRUE(var1 != plainTextEdit->document()); // QPlainTextEdit creates a new document when setting 0
    ASSERT_TRUE((QTextDocument *)0 != plainTextEdit->document());
    delete var1;


    // bool QPlainTextEdit::tabChangesFocus()
    // void QPlainTextEdit::setTabChangesFocus(bool)
    plainTextEdit->setTabChangesFocus(false);
    ASSERT_EQ(false, plainTextEdit->tabChangesFocus());
    plainTextEdit->setTabChangesFocus(true);
    ASSERT_EQ(true, plainTextEdit->tabChangesFocus());

    // LineWrapMode QPlainTextEdit::lineWrapMode()
    // void QPlainTextEdit::setLineWrapMode(LineWrapMode)
    plainTextEdit->setLineWrapMode(QPlainTextEdit::LineWrapMode(QPlainTextEdit::NoWrap));
    ASSERT_EQ(QPlainTextEdit::LineWrapMode(QPlainTextEdit::NoWrap), plainTextEdit->lineWrapMode());
    plainTextEdit->setLineWrapMode(QPlainTextEdit::LineWrapMode(QPlainTextEdit::WidgetWidth));
    ASSERT_EQ(QPlainTextEdit::LineWrapMode(QPlainTextEdit::WidgetWidth), plainTextEdit->lineWrapMode());

    // bool QPlainTextEdit::overwriteMode()
    // void QPlainTextEdit::setOverwriteMode(bool)
    plainTextEdit->setOverwriteMode(false);
    ASSERT_EQ(false, plainTextEdit->overwriteMode());
    plainTextEdit->setOverwriteMode(true);
    ASSERT_EQ(true, plainTextEdit->overwriteMode());

    // int QPlainTextEdit::tabStopWidth()
    // void QPlainTextEdit::setTabStopWidth(int)
    plainTextEdit->setTabStopWidth(0);
    ASSERT_EQ(0, plainTextEdit->tabStopWidth());
    plainTextEdit->setTabStopWidth(INT_MIN);
    ASSERT_EQ(0, plainTextEdit->tabStopWidth()); // Makes no sense to set a negative tabstop value
#if defined(QT_ARCH_WINDOWSCE)
    // due to rounding error in qRound when qreal==float
    // we cannot use INT_MAX for this check
    plainTextEdit.setTabStopWidth(SHRT_MAX*2);
    ASSERT_EQ(SHRT_MAX*2, plainTextEdit.tabStopWidth());
#else
    plainTextEdit->setTabStopWidth(INT_MAX);
    ASSERT_EQ(INT_MAX, plainTextEdit->tabStopWidth());
#endif


}

TEST_F (NotepadTest, testingCreateSelection) {
    QTest::keyClicks(plainTextEdit, "Hello World");
    /* go to start */
#ifndef Q_WS_MAC
    QTest::keyClick(plainTextEdit, Qt::Key_Home, Qt::ControlModifier);
#else
    QTest::keyClick(plainTextEdit, Qt::Key_Home);
#endif
    ASSERT_EQ(plainTextEdit->textCursor().position(), 0);
    /* select until end of text */
#ifndef Q_WS_MAC
    QTest::keyClick(plainTextEdit, Qt::Key_End, Qt::ControlModifier | Qt::ShiftModifier);
#else
    QTest::keyClick(plainTextEdit, Qt::Key_End, Qt::ShiftModifier);
#endif
    ASSERT_EQ(plainTextEdit->textCursor().position(), 11);
}

TEST_F (NotepadTest, testingClearMustNotChangeClipboard) {
    plainTextEdit->textCursor().insertText("Hello World");
    QString txt("This is different text");
    QApplication::clipboard()->setText(txt);
    plainTextEdit->clear();
    ASSERT_EQ(QApplication::clipboard()->text(), txt);
}

TEST_F (NotepadTest, testingclearMustNotResetRootFrameMarginToDefault) {
    ASSERT_EQ(plainTextEdit->document()->rootFrame()->frameFormat().margin(), plainTextEdit->document()->documentMargin());
    plainTextEdit->clear();
    ASSERT_EQ(plainTextEdit->document()->rootFrame()->frameFormat().margin(), plainTextEdit->document()->documentMargin());
}

TEST_F (NotepadTest, testingParagSeparatorOnPlaintextAppend) {
    plainTextEdit->appendPlainText("Hello\nWorld");
    int cnt = 0;
    QTextBlock blk = plainTextEdit->document()->begin();
    while (blk.isValid()) {
        ++cnt;
        blk = blk.next();
    }
    ASSERT_EQ(cnt, 2);
}


TEST_F(NotepadTest, testingAsciiTab){
    QPlainTextEdit edit;
    edit.setPlainText("\t");
    edit.show();
    qApp->processEvents();
    ASSERT_EQ(edit.toPlainText().at(0), QChar('\t'));
}



TEST_F(NotepadTest, testingMergeCurrentCharFormat) {
    plainTextEdit->setPlainText("Hello Test World");
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.setPosition(7);
    plainTextEdit->setTextCursor(cursor);

    QTextCharFormat mod;
    mod.setFontItalic(true);
    mod.setForeground(Qt::red);
    plainTextEdit->mergeCurrentCharFormat(mod);

    cursor.movePosition(QTextCursor::Right);
    cursor.movePosition(QTextCursor::Right);
    // do NOT select the current word under the cursor, /JUST/
    // call mergeCharFormat on the cursor
    ASSERT_TRUE(!cursor.charFormat().fontItalic());
    ASSERT_TRUE(cursor.charFormat().foreground().color() != Qt::red);
}

TEST_F(NotepadTest, testingMergeCurrentBlockCharFormat) {
    plainTextEdit->setPlainText("FirstLine\n\nThirdLine");
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::Down);

    // make sure we're in the empty second line
    ASSERT_TRUE(cursor.atBlockStart());
    ASSERT_TRUE(cursor.atBlockEnd());

    plainTextEdit->setTextCursor(cursor);

    QTextCharFormat mod;
    mod.setForeground(Qt::red);
    plainTextEdit->mergeCurrentCharFormat(mod);

    ASSERT_TRUE(cursor.blockCharFormat().foreground().color() != Qt::red);
    cursor.movePosition(QTextCursor::Up);
    ASSERT_TRUE(cursor.blockCharFormat().foreground().color() != Qt::red);
    cursor.movePosition(QTextCursor::Down);
    cursor.movePosition(QTextCursor::Down);
    ASSERT_TRUE(cursor.blockCharFormat().foreground().color() != Qt::red);
}



// Supporter issue #56783
TEST_F(NotepadTest, testingEmptyAppend) {
    plainTextEdit->appendPlainText("Blah");
    ASSERT_EQ(blockCount(), 1);
    plainTextEdit->appendPlainText(QString());
    ASSERT_EQ(blockCount(), 2);
    plainTextEdit->appendPlainText(QString("   "));
    ASSERT_EQ(blockCount(), 3);
}

TEST_F(NotepadTest, testingAppendOnEmptyDocumentShouldReuseInitialParagraph)
{
    ASSERT_EQ(blockCount(), 1);
    plainTextEdit->appendPlainText("Blah");
    ASSERT_EQ(blockCount(), 1);
}



TEST_F(NotepadTest, testingMouseSelection)
{
    plainTextEdit->show();
    plainTextEdit->setPlainText(("Hello World"));
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.setPosition(1);
    QPoint p1 = plainTextEdit->cursorRect(cursor).center();
    cursor.setPosition(10);
    QPoint p2 = plainTextEdit->cursorRect(cursor).center();
    QTest::mousePress(plainTextEdit->viewport(), Qt::LeftButton, 0, p1);
    {   QMouseEvent ev(QEvent::MouseMove, p2, Qt::LeftButton, Qt::LeftButton, 0);
        QCoreApplication::sendEvent(plainTextEdit->viewport(), &ev); }
    QTest::mouseRelease(plainTextEdit->viewport(), Qt::LeftButton, 0, p2);
    ASSERT_TRUE(plainTextEdit->textCursor().hasSelection());
    ASSERT_EQ(plainTextEdit->textCursor().selectedText(), QString("ello Worl"));

}

TEST_F(NotepadTest, testingMouseSelectionDClick)
{
    plainTextEdit->show();
    plainTextEdit->setPlainText(("Hello World"));
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.setPosition(1);
    QPoint p1 = plainTextEdit->cursorRect(cursor).center();
    cursor.setPosition(10);
    QPoint p2 = plainTextEdit->cursorRect(cursor).center();
    QTest::mousePress(plainTextEdit->viewport(), Qt::LeftButton, 0, p1);
    QTest::mouseRelease(plainTextEdit->viewport(), Qt::LeftButton, 0, p1);
    QTest::mouseDClick(plainTextEdit->viewport(), Qt::LeftButton, 0, p1);
    ASSERT_TRUE(plainTextEdit->textCursor().hasSelection());
    ASSERT_EQ(plainTextEdit->textCursor().selectedText(), QString("Hello"));
    {   QMouseEvent ev(QEvent::MouseMove, p2, Qt::LeftButton, Qt::LeftButton, 0);
        QCoreApplication::sendEvent(plainTextEdit->viewport(), &ev); }
    QTest::mouseRelease(plainTextEdit->viewport(), Qt::LeftButton, 0, p2);
    ASSERT_TRUE(plainTextEdit->textCursor().hasSelection());
    ASSERT_EQ(plainTextEdit->textCursor().selectedText(), QString("Hello World"));
}

TEST_F(NotepadTest, testingSetTextCursor)
{
    QSignalSpy spy(plainTextEdit, SIGNAL(cursorPositionChanged()));

    plainTextEdit->setPlainText("Test");
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::NextCharacter);

    spy.clear();

    plainTextEdit->setTextCursor(cursor);
    ASSERT_EQ(spy.count(), 1);
}

#ifndef QT_NO_CLIPBOARD
TEST_F(NotepadTest, testingUndoAvailableAfterPaste)
{

    QSignalSpy spy(plainTextEdit->document(), SIGNAL(undoAvailable(bool)));

    const QString txt("Test");
    QApplication::clipboard()->setText(txt);
    plainTextEdit->paste();
    ASSERT_TRUE(spy.count() >= 1);
    ASSERT_EQ(plainTextEdit->toPlainText(), txt);
}
#endif




TEST_F(NotepadTest, testingAppendShouldUseCurrentFormat)
{
    plainTextEdit->textCursor().insertText("A");
    QTextCharFormat fmt;
    fmt.setForeground(Qt::blue);
    fmt.setFontItalic(true);
    plainTextEdit->setCurrentCharFormat(fmt);
    plainTextEdit->appendPlainText("Hello");

    QTextCursor cursor(plainTextEdit->document());

    ASSERT_TRUE(cursor.movePosition(QTextCursor::NextCharacter));
    ASSERT_TRUE(cursor.charFormat().foreground().color() != Qt::blue);
    ASSERT_TRUE(!cursor.charFormat().fontItalic());

    ASSERT_TRUE(cursor.movePosition(QTextCursor::NextBlock));

    {
        QTextCursor tmp = cursor;
        tmp.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        ASSERT_EQ(tmp.selectedText(), QString::fromLatin1("Hello"));
    }

    ASSERT_TRUE(cursor.movePosition(QTextCursor::NextCharacter));
    ASSERT_TRUE(cursor.charFormat().foreground().color() == Qt::blue);
    ASSERT_TRUE(cursor.charFormat().fontItalic());
}

TEST_F(NotepadTest, testingAppendShouldNotTouchTheSelection)
{
    QTextCursor cursor(plainTextEdit->document());
    QTextCharFormat fmt;
    fmt.setForeground(Qt::blue);
    cursor.insertText("H", fmt);
    fmt.setForeground(Qt::red);
    cursor.insertText("ey", fmt);

    cursor.insertText("some random text inbetween");

    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    ASSERT_EQ(cursor.charFormat().foreground().color(), QColor(Qt::blue));
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    ASSERT_EQ(cursor.charFormat().foreground().color(), QColor(Qt::red));
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    ASSERT_EQ(cursor.charFormat().foreground().color(), QColor(Qt::red));
    ASSERT_EQ(cursor.selectedText(), QString("Hey"));

    plainTextEdit->setTextCursor(cursor);
    ASSERT_TRUE(plainTextEdit->textCursor().hasSelection());

    plainTextEdit->appendPlainText("<b>Some Bold Text</b>");
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::NextCharacter);
    ASSERT_EQ(cursor.charFormat().foreground().color(), QColor(Qt::blue));
}

TEST_F(NotepadTest, testingBackspace)
{
    QTextCursor cursor = plainTextEdit->textCursor();

    QTextListFormat listFmt;
    listFmt.setStyle(QTextListFormat::ListDisc);
    listFmt.setIndent(1);
    cursor.insertList(listFmt);
    cursor.insertText("A");

    plainTextEdit->setTextCursor(cursor);

    // delete 'A'
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace);
    ASSERT_TRUE(plainTextEdit->textCursor().currentList());
    // delete list
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace);
    ASSERT_TRUE(!plainTextEdit->textCursor().currentList());
    ASSERT_EQ(plainTextEdit->textCursor().blockFormat().indent(), 1);
    // outdent paragraph
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace);
    ASSERT_EQ(plainTextEdit->textCursor().blockFormat().indent(), 0);
}

TEST_F(NotepadTest, testingShiftBackspace)
{
    QTextCursor cursor = plainTextEdit->textCursor();

    QTextListFormat listFmt;
    listFmt.setStyle(QTextListFormat::ListDisc);
    listFmt.setIndent(1);
    cursor.insertList(listFmt);
    cursor.insertText("A");

    plainTextEdit->setTextCursor(cursor);

    // delete 'A'
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace, Qt::ShiftModifier);
    ASSERT_TRUE(plainTextEdit->textCursor().currentList());
    // delete list
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace, Qt::ShiftModifier);
    ASSERT_TRUE(!plainTextEdit->textCursor().currentList());
    ASSERT_EQ(plainTextEdit->textCursor().blockFormat().indent(), 1);
    // outdent paragraph
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace, Qt::ShiftModifier);
    ASSERT_EQ(plainTextEdit->textCursor().blockFormat().indent(), 0);
}

TEST_F(NotepadTest, testingUndoRedo)
{
    plainTextEdit->clear();
    QTest::keyClicks(plainTextEdit, "abc d");
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("abc d"));
    plainTextEdit->undo();
    ASSERT_EQ(plainTextEdit->toPlainText(), QString());
    plainTextEdit->redo();
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("abc d"));
#ifdef Q_WS_WIN
    // shortcut for undo
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace, Qt::AltModifier);
    ASSERT_EQ(plainTextEdit->toPlainText(), QString());
    // shortcut for redo
    QTest::keyClick(plainTextEdit, Qt::Key_Backspace, Qt::ShiftModifier|Qt::AltModifier);
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("abc d"));
#endif
}



#ifndef QT_NO_CLIPBOARD
TEST_F(NotepadTest, testingCopyAndSelectAllInReadonly)
{


    plainTextEdit->setReadOnly(true);
    plainTextEdit->setPlainText("Hello World");

    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.clearSelection();
    plainTextEdit->setTextCursor(cursor);
    ASSERT_TRUE(!plainTextEdit->textCursor().hasSelection());

    ASSERT_EQ(plainTextEdit->toPlainText(), QString("Hello World"));

    // shouldn't do anything
    QTest::keyClick(plainTextEdit, Qt::Key_A);

    ASSERT_EQ(plainTextEdit->toPlainText(), QString("Hello World"));

    QTest::keyClick(plainTextEdit, Qt::Key_A, Qt::ControlModifier);

    ASSERT_TRUE(plainTextEdit->textCursor().hasSelection());

    QApplication::clipboard()->setText(QString());
    ASSERT_TRUE(QApplication::clipboard()->text().isEmpty());

    QTest::keyClick(plainTextEdit, Qt::Key_C, Qt::ControlModifier);
    ASSERT_EQ(QApplication::clipboard()->text(), QString("Hello World"));
}
#endif

TEST_F(NotepadTest, testingCtrlAltInput)
{
    QTest::keyClick(plainTextEdit, Qt::Key_At, Qt::ControlModifier | Qt::AltModifier);
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("@"));
}

TEST_F(NotepadTest, testingNoPropertiesOnDefaultTextEditCharFormat)
{
    // there should be no properties set on the default/initial char format
    // on a text edit. Font properties instead should be taken from the
    // widget's font (in sync with defaultFont property in document) and the
    // foreground color should be taken from the palette.
    ASSERT_EQ(plainTextEdit->currentCharFormat().properties().count(), 0);
}



TEST_F(NotepadTest, testingSetPlainTextShouldEmitTextChangedOnce)
{
    QSignalSpy spy(plainTextEdit, SIGNAL(textChanged()));
    plainTextEdit->setPlainText("Yankee Doodle");
    ASSERT_EQ(spy.count(), 1);
    plainTextEdit->setPlainText("");
    ASSERT_EQ(spy.count(), 2);
}

TEST_F(NotepadTest, testingOverwriteMode)
{
    ASSERT_TRUE(!plainTextEdit->overwriteMode());
    QTest::keyClicks(plainTextEdit, "Some first text");

    ASSERT_EQ(plainTextEdit->toPlainText(), QString("Some first text"));

    plainTextEdit->setOverwriteMode(true);

    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.setPosition(5);
    plainTextEdit->setTextCursor(cursor);

    QTest::keyClicks(plainTextEdit, "shiny");
    ASSERT_EQ(plainTextEdit->toPlainText(), QString("Some shiny text"));

    cursor.movePosition(QTextCursor::End);
    plainTextEdit->setTextCursor(cursor);

    QTest::keyClick(plainTextEdit, Qt::Key_Enter);

    plainTextEdit->setOverwriteMode(false);
    QTest::keyClicks(plainTextEdit, "Second paragraph");

    ASSERT_EQ(blockCount(), 2);

    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::EndOfBlock);

    ASSERT_EQ(cursor.position(), 15);
    plainTextEdit->setTextCursor(cursor);

    plainTextEdit->setOverwriteMode(true);

    QTest::keyClicks(plainTextEdit, " blah");

    ASSERT_EQ(blockCount(), 2);

    QTextBlock block = plainTextEdit->document()->begin();
    ASSERT_EQ(block.text(), QString("Some shiny text blah"));
    block = block.next();
    ASSERT_EQ(block.text(), QString("Second paragraph"));
}


TEST_F(NotepadTest, testingUndoRedoShouldRepositionTextEditCursor)
{
    plainTextEdit->setPlainText("five\nlines\nin\nthis\ntextedit");
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);

    plainTextEdit->setUndoRedoEnabled(false);
    plainTextEdit->setUndoRedoEnabled(true);

    ASSERT_TRUE(!plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(!plainTextEdit->document()->isRedoAvailable());

    cursor.insertText("Blah");

    ASSERT_TRUE(plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(!plainTextEdit->document()->isRedoAvailable());

    cursor.movePosition(QTextCursor::End);
    plainTextEdit->setTextCursor(cursor);

    ASSERT_TRUE(QMetaObject::invokeMethod(plainTextEdit, "undo"));

    ASSERT_TRUE(!plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(plainTextEdit->document()->isRedoAvailable());

    ASSERT_EQ(plainTextEdit->textCursor().position(), 0);

    cursor.movePosition(QTextCursor::End);
    plainTextEdit->setTextCursor(cursor);

    ASSERT_TRUE(QMetaObject::invokeMethod(plainTextEdit, "redo"));

    ASSERT_TRUE(plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(!plainTextEdit->document()->isRedoAvailable());

    ASSERT_EQ(plainTextEdit->textCursor().position(), 4);
}



TEST_F(NotepadTest, testingMouseCursorShape)
{
#ifndef QT_NO_CURSOR
    // always show an IBeamCursor, see change 170146
    ASSERT_TRUE(!plainTextEdit->isReadOnly());
    ASSERT_TRUE(plainTextEdit->viewport()->cursor().shape() == Qt::IBeamCursor);

    plainTextEdit->setReadOnly(true);
    ASSERT_TRUE(plainTextEdit->viewport()->cursor().shape() == Qt::IBeamCursor);

    plainTextEdit->setPlainText("Foo");
    ASSERT_TRUE(plainTextEdit->viewport()->cursor().shape() == Qt::IBeamCursor);
#endif
}

TEST_F(NotepadTest, testingImplicitClear)
{
    // test that QPlainTextEdit::setHtml, etc. avoid calling clear() but instead call
    // QTextDocument::setHtml/etc. instead, which also clear the contents and
    // cached resource but preserve manually added resources. setHtml on a textedit
    // should behave the same as on a document with respect to that.
    // see also clearResources() autotest in qtextdocument

    // regular resource for QTextDocument
    QUrl testUrl(":/foobar");
    QVariant testResource("hello world");

    plainTextEdit->document()->addResource(QTextDocument::ImageResource, testUrl, testResource);
    ASSERT_TRUE(plainTextEdit->document()->resource(QTextDocument::ImageResource, testUrl) == testResource);

    plainTextEdit->setPlainText("Blah");
    ASSERT_TRUE(plainTextEdit->document()->resource(QTextDocument::ImageResource, testUrl) == testResource);

    plainTextEdit->setPlainText("<b>Blah</b>");
    ASSERT_TRUE(plainTextEdit->document()->resource(QTextDocument::ImageResource, testUrl) == testResource);

    plainTextEdit->clear();
    ASSERT_TRUE(!plainTextEdit->document()->resource(QTextDocument::ImageResource, testUrl).isValid());
    ASSERT_TRUE(plainTextEdit->toPlainText().isEmpty());
}


TEST_F(NotepadTest, testingUndoRedoAfterSetContent)
{
    ASSERT_TRUE(!plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(!plainTextEdit->document()->isRedoAvailable());
    plainTextEdit->setPlainText("Foobar");
    ASSERT_TRUE(!plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(!plainTextEdit->document()->isRedoAvailable());

    ASSERT_TRUE(!plainTextEdit->document()->isUndoAvailable());
    ASSERT_TRUE(!plainTextEdit->document()->isRedoAvailable());
}

TEST_F(NotepadTest, testingNumPadKeyNavigation)
{
    plainTextEdit->setPlainText("Hello World");
    ASSERT_EQ(plainTextEdit->textCursor().position(), 0);
    QTest::keyClick(plainTextEdit, Qt::Key_Right, Qt::KeypadModifier);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 1);
}

TEST_F(NotepadTest, testingMoveCursor)
{
    plainTextEdit->setPlainText("Test");

    QSignalSpy cursorMovedSpy(plainTextEdit, SIGNAL(cursorPositionChanged()));

    ASSERT_EQ(plainTextEdit->textCursor().position(), 0);
    plainTextEdit->moveCursor(QTextCursor::NextCharacter);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 1);
    ASSERT_EQ(cursorMovedSpy.count(), 1);
    plainTextEdit->moveCursor(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 2);
    ASSERT_EQ(cursorMovedSpy.count(), 2);
    ASSERT_EQ(plainTextEdit->textCursor().selectedText(), QString("e"));
}

class MyTextEdit : public QPlainTextEdit
{
public:
    inline MyTextEdit()
        : createMimeDataCallCount(0),
          canInsertCallCount(0),
          insertCallCount(0)
    {}

    mutable int createMimeDataCallCount;
    mutable int canInsertCallCount;
    mutable int insertCallCount;

    virtual QMimeData *createMimeDataFromSelection() const {
        createMimeDataCallCount++;
        return QPlainTextEdit::createMimeDataFromSelection();
    }
    virtual bool canInsertFromMimeData(const QMimeData *source) const {
        canInsertCallCount++;
        return QPlainTextEdit::canInsertFromMimeData(source);
    }
    virtual void insertFromMimeData(const QMimeData *source) {
        insertCallCount++;
        QPlainTextEdit::insertFromMimeData(source);
    }

};

#ifndef QT_NO_CLIPBOARD
TEST_F(NotepadTest, testingMimeDataReimplementations)
{
    MyTextEdit plainTextEdit;
    plainTextEdit.setPlainText("Hello World");

    ASSERT_EQ(plainTextEdit.createMimeDataCallCount, 0);
    ASSERT_EQ(plainTextEdit.canInsertCallCount, 0);
    ASSERT_EQ(plainTextEdit.insertCallCount, 0);

    plainTextEdit.selectAll();

    ASSERT_EQ(plainTextEdit.createMimeDataCallCount, 0);
    ASSERT_EQ(plainTextEdit.canInsertCallCount, 0);
    ASSERT_EQ(plainTextEdit.insertCallCount, 0);

    plainTextEdit.copy();

    ASSERT_EQ(plainTextEdit.createMimeDataCallCount, 1);
    ASSERT_EQ(plainTextEdit.canInsertCallCount, 0);
    ASSERT_EQ(plainTextEdit.insertCallCount, 0);

#ifdef QT_BUILD_INTERNAL
    QTextControl *control = qFindChild<QTextControl *>(&plainTextEdit);
    ASSERT_TRUE(control);

    control->canInsertFromMimeData(QApplication::clipboard()->mimeData());

    ASSERT_EQ(plainTextEdit.createMimeDataCallCount, 1);
    ASSERT_EQ(plainTextEdit.canInsertCallCount, 1);
    ASSERT_EQ(plainTextEdit.insertCallCount, 0);

    plainTextEdit.paste();

    ASSERT_EQ(plainTextEdit.createMimeDataCallCount, 1);
    ASSERT_EQ(plainTextEdit.canInsertCallCount, 1);
    ASSERT_EQ(plainTextEdit.insertCallCount, 1);
#endif
}
#endif

TEST_F(NotepadTest, testingCtrlEnterShouldInsertLineSeparator_NOT)
{
    QTest::keyClick(plainTextEdit, Qt::Key_A);
    QTest::keyClick(plainTextEdit, Qt::Key_Enter, Qt::ControlModifier);
    QTest::keyClick(plainTextEdit, Qt::Key_B);
    QString expected;
    expected += 'a';
    //    expected += QChar::LineSeparator; // do NOT insert
    expected += 'b';
    ASSERT_EQ(plainTextEdit->textCursor().block().text(), expected);
}

TEST_F(NotepadTest, testingShiftEnterShouldInsertLineSeparator)
{
    QTest::keyClick(plainTextEdit, Qt::Key_A);
    QTest::keyClick(plainTextEdit, Qt::Key_Enter, Qt::ShiftModifier);
    QTest::keyClick(plainTextEdit, Qt::Key_B);
    QString expected;
    expected += 'a';
    expected += QChar::LineSeparator;
    expected += 'b';
    ASSERT_EQ(plainTextEdit->textCursor().block().text(), expected);
}




#ifndef QT_NO_CLIPBOARD
TEST_F(NotepadTest, testingCanPaste)
{

    QApplication::clipboard()->setText(QString());
    ASSERT_TRUE(!plainTextEdit->canPaste());
    QApplication::clipboard()->setText("Test");
    ASSERT_TRUE(plainTextEdit->canPaste());
    plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    ASSERT_TRUE(!plainTextEdit->canPaste());
}
#endif

TEST_F(NotepadTest, testingEnsureCursorVisibleOnInitialShow)
{
    QString manyPagesOfPlainText;
    for (int i = 0; i < 800; ++i)
        manyPagesOfPlainText += QLatin1String("Blah blah blah blah blah blah\n");

    plainTextEdit->setPlainText(manyPagesOfPlainText);
    ASSERT_EQ(plainTextEdit->textCursor().position(), 0);

    plainTextEdit->moveCursor(QTextCursor::End);
    plainTextEdit->show();
    ASSERT_TRUE(plainTextEdit->verticalScrollBar()->value() > 10);

    plainTextEdit->moveCursor(QTextCursor::Start);
    ASSERT_TRUE(plainTextEdit->verticalScrollBar()->value() < 10);
    plainTextEdit->hide();
    plainTextEdit->verticalScrollBar()->setValue(plainTextEdit->verticalScrollBar()->maximum());
    plainTextEdit->show();
    ASSERT_EQ(plainTextEdit->verticalScrollBar()->value(), plainTextEdit->verticalScrollBar()->maximum());
}


TEST_F(NotepadTest, testingColorfulAppend)
{
    QTextCharFormat fmt;
    fmt.setForeground(Qt::red);
    plainTextEdit->mergeCurrentCharFormat(fmt);
    plainTextEdit->appendPlainText("Red");

    fmt.setForeground(Qt::blue);
    plainTextEdit->mergeCurrentCharFormat(fmt);
    plainTextEdit->appendPlainText("Blue");

    fmt.setForeground(Qt::green);
    plainTextEdit->mergeCurrentCharFormat(fmt);
    plainTextEdit->appendPlainText("Green");

    ASSERT_EQ(plainTextEdit->document()->blockCount(), 3);
    QTextBlock block = plainTextEdit->document()->begin();
    ASSERT_EQ(block.begin().fragment().text(), QString("Red"));
    ASSERT_TRUE(block.begin().fragment().charFormat().foreground().color() == Qt::red);
    block = block.next();
    ASSERT_EQ(block.begin().fragment().text(), QString("Blue"));
    ASSERT_TRUE(block.begin().fragment().charFormat().foreground().color() == Qt::blue);
    block = block.next();
    ASSERT_EQ(block.begin().fragment().text(), QString("Green"));
    ASSERT_TRUE(block.begin().fragment().charFormat().foreground().color() == Qt::green);
}

TEST_F(NotepadTest, testingEnsureVisibleWithRtl)
{
    plainTextEdit->setLayoutDirection(Qt::RightToLeft);
    plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    QString txt(500, QChar(QLatin1Char('a')));
    ASSERT_EQ(txt.length(), 500);
    plainTextEdit->setPlainText(txt);
    plainTextEdit->resize(100, 100);
    plainTextEdit->show();

    qApp->processEvents();

    ASSERT_TRUE(plainTextEdit->horizontalScrollBar()->maximum() > 0);

    plainTextEdit->moveCursor(QTextCursor::Start);
    ASSERT_EQ(plainTextEdit->horizontalScrollBar()->value(), plainTextEdit->horizontalScrollBar()->maximum());
    plainTextEdit->moveCursor(QTextCursor::End);
    ASSERT_EQ(plainTextEdit->horizontalScrollBar()->value(), 0);
    plainTextEdit->moveCursor(QTextCursor::Start);
    ASSERT_EQ(plainTextEdit->horizontalScrollBar()->value(), plainTextEdit->horizontalScrollBar()->maximum());
    plainTextEdit->moveCursor(QTextCursor::End);
    ASSERT_EQ(plainTextEdit->horizontalScrollBar()->value(), 0);
}

TEST_F(NotepadTest, testingPreserveCharFormatAfterSetPlainText)
{
    QTextCharFormat fmt;
    fmt.setForeground(Qt::blue);
    plainTextEdit->mergeCurrentCharFormat(fmt);
    plainTextEdit->setPlainText("This is blue");
    plainTextEdit->appendPlainText("This should still be blue");
    QTextBlock block = plainTextEdit->document()->begin();
    block = block.next();
    ASSERT_EQ(block.text(), QString("This should still be blue"));
    ASSERT_TRUE(block.begin().fragment().charFormat().foreground().color() == QColor(Qt::blue));
}

TEST_F(NotepadTest, testingExtraSelections)
{
    plainTextEdit->setPlainText("Hello World");

    QTextCursor c = plainTextEdit->textCursor();
    c.movePosition(QTextCursor::Start);
    c.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    const int endPos = c.position();

    QTextEdit::ExtraSelection sel;
    sel.cursor = c;
    plainTextEdit->setExtraSelections( QList<QTextEdit::ExtraSelection>() << sel);

    c.movePosition(QTextCursor::Start);
    c.movePosition(QTextCursor::NextWord);
    const int wordPos = c.position();
    c.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    sel.cursor = c;
    plainTextEdit->setExtraSelections( QList<QTextEdit::ExtraSelection>() << sel);

    QList<QTextEdit::ExtraSelection> selections = plainTextEdit->extraSelections();
    ASSERT_EQ(selections.count(), 1);
    ASSERT_EQ(selections.at(0).cursor.position(), endPos);
    ASSERT_EQ(selections.at(0).cursor.anchor(), wordPos);
}

TEST_F(NotepadTest, testingAdjustScrollbars)
{
    // For some reason ff is defined to be << on Mac Panther / gcc 3.3
#undef ff
    QFont ff(plainTextEdit->font());
    ff.setFamily("Tahoma");
    ff.setPointSize(11);
    plainTextEdit->setFont(ff);
    plainTextEdit->setMinimumSize(140, 100);
    plainTextEdit->setMaximumSize(140, 100);
    plainTextEdit->show();
    QLatin1String txt("\nabc def ghi jkl mno pqr stu vwx");
    plainTextEdit->setPlainText(txt + txt + txt + txt);

    ASSERT_TRUE(plainTextEdit->verticalScrollBar()->maximum() > 0);

    plainTextEdit->moveCursor(QTextCursor::End);
    int oldMaximum = plainTextEdit->verticalScrollBar()->maximum();
    QTextCursor cursor = plainTextEdit->textCursor();
    cursor.insertText(QLatin1String("\n"));
    cursor.deletePreviousChar();
    ASSERT_EQ(plainTextEdit->verticalScrollBar()->maximum(), oldMaximum);
}



TEST_F(NotepadTest, testingSetTextPreservesUndoRedoEnabled)
{
    ASSERT_TRUE(plainTextEdit->isUndoRedoEnabled());

    plainTextEdit->setPlainText("Test");

    ASSERT_TRUE(plainTextEdit->isUndoRedoEnabled());

    plainTextEdit->setUndoRedoEnabled(false);
    ASSERT_TRUE(!plainTextEdit->isUndoRedoEnabled());
    plainTextEdit->setPlainText("Test2");
    ASSERT_TRUE(!plainTextEdit->isUndoRedoEnabled());


}



TEST_F(NotepadTest, testingLineWrapProperty)
{
    ASSERT_TRUE(plainTextEdit->wordWrapMode() == QTextOption::WrapAtWordBoundaryOrAnywhere);
    ASSERT_TRUE(plainTextEdit->lineWrapMode() == QPlainTextEdit::WidgetWidth);
    plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    ASSERT_TRUE(plainTextEdit->lineWrapMode() == QPlainTextEdit::NoWrap);
    ASSERT_TRUE(plainTextEdit->wordWrapMode() == QTextOption::WrapAtWordBoundaryOrAnywhere);
    ASSERT_TRUE(plainTextEdit->document()->defaultTextOption().wrapMode() == QTextOption::NoWrap);
}





#endif // TST_NOTEPADTESTCASE_H
