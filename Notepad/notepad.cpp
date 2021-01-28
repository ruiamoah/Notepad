#include "notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    // Set ui
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);

    connect(ui->plainTextEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->plainTextEdit, SIGNAL(copyAvailable(bool)), ui->actionSearch_with_Google, SLOT(setEnabled(bool)));
    connect(QApplication::clipboard(), SIGNAL(dataChanged()),  this, SLOT(processPaste()));
    connect(ui->plainTextEdit, SIGNAL(selectionChanged()), this, SLOT(processDelete()));
    // Set up printer margins
    QMarginsF margins(0.250000, 0.250000, 0.250000, 0.250000);
    printer.setPageMargins(margins,QPageLayout::Inch);

    // front separator
    QLabel* separator = new QLabel(this);
    ui->statusbar->addPermanentWidget(separator);

    // Ln and Col statusbar
    statusLabelLnCol = new QLabel(this);
    ui->statusbar->addPermanentWidget(statusLabelLnCol);
    QString strLnCol = " Ln: " + QString::number(1) + ", Col: " + QString::number(1);
    statusLabelLnCol->setText(strLnCol.leftJustified(30, ' '));

    // Zoom statusbar
    statusLabelZoom = new QLabel(this);
    ui->statusbar->addPermanentWidget(statusLabelZoom);
    QString strZoom = " " + QString::number(zoom) + "%";
    statusLabelZoom->setText(strZoom.leftJustified(10, ' '));

    // CRLF statusbar
    statusLabelCRLF = new QLabel(this);
    ui->statusbar->addPermanentWidget(statusLabelCRLF);
    QString product = QSysInfo::productType();
    product = product.at(0).toUpper()+product.mid(1);
    statusLabelCRLF->setText(product + " (CRLF)     ");

    // UTF8 statusbar
    statusLabelUTF8 = new QLabel(this);
    ui->statusbar->addPermanentWidget(statusLabelUTF8);
    statusLabelUTF8->setText(" UTF-8                    ");

    // Setup goto widget
    m_goto = new GoTo(this);
    m_goto->setPlainTextEdit(ui->plainTextEdit);
    m_goto->setTextCursor(ui->plainTextEdit->textCursor());

    // Setup find widget
    m_findDialog = new FindDialog(this);
    m_findDialog->setModal(false);
    m_findDialog->setPlainTextEdit(ui->plainTextEdit);

    // Setup replace widget
    m_findReplaceDialog = new FindReplaceDialog(this);
    m_findReplaceDialog->setModal(false);
    m_findReplaceDialog->setPlainTextEdit(ui->plainTextEdit);

    // set Title
    setWindowTitle("Untitled - Notepad");

    Notepad::processPaste();

    // set out of focus text to be the same as unfocused text
    QPalette p = palette();
    p.setColor(QPalette::Inactive, QPalette::Highlight, p.color(QPalette::Active, QPalette::Highlight));
    p.setColor(QPalette::Inactive, QPalette::HighlightedText, p.color(QPalette::Active, QPalette::HighlightedText));
    setPalette(p);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::closeEvent(QCloseEvent *event)
{
    Notepad::on_actionNew_triggered();
    QWidget::closeEvent(event);
}
void Notepad::processPaste()
{
    if (QApplication::clipboard()->text().isEmpty())
        ui->actionPaste->setEnabled(false);
    else
        ui->actionPaste->setEnabled(true);
}

void Notepad::on_actionNew_triggered()
{
    if (windowTitle() == "Untitled - Notepad") {
        return;
    }
    if (windowTitle().at(0) != '*')
    {
        currentFile.clear();
        ui->plainTextEdit->setPlainText(QString());
        setWindowTitle("Untitled - Notepad");
        newOpen = true;
        return;
    }
    QMessageBox msgBox;
    QFileInfo info(currentFile);
    QString name = info.baseName();
    if (name == "") {
        name = "Untitled";
    }
    msgBox.setText("Do you want to save changes to " + name);
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        Notepad::on_actionSave_triggered();
        newOpen = true;
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        currentFile.clear();
        ui->plainTextEdit->setPlainText(QString());
        setWindowTitle( "Untitled - Notepad");
        newOpen = true;
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        return;
        break;
    default:
        // should never be reached
        break;
    }

}

void Notepad::helperOpen() {
    QString filter = "Text Files (*.txt) ;; All File (*.*)";
    QString fileName = QFileDialog::getOpenFileName(this, "Open", currentFile, filter);
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        return;
    }
    QFileInfo info(fileName);
    QTextStream input(&file);
    QString text = input.readAll();
    ui->plainTextEdit->setPlainText(text);
    ui->plainTextEdit->lineWidth();
    file.close();
    setWindowTitle(info.baseName() + " - Notepad");
    newOpen = true;
}

void Notepad::on_actionOpen_triggered()
{
    if (windowTitle().at(0) == '*'){
        QMessageBox msgBox;
        QFileInfo info(currentFile);
        QString name = info.baseName();
        if (name == ""){
            name = "Untitled";
        }
        msgBox.setText("Do you want to save changes to " + name);
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            Notepad::on_actionSave_triggered();
            helperOpen();
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            helperOpen();
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            return;
            break;
        default:
            // should never be reached
            break;
        }
        return;
    }
    helperOpen();
}

void Notepad::on_actionSave_As_triggered()
{
    QString filter = "Text Files (*.txt) ;; All File (*.*)";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), currentFile , filter);
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    QFileInfo info(fileName);
    currentFile = fileName;
    setWindowTitle(info.baseName() + " - Notepad");
    QTextStream output(&file);
    QString text = ui->plainTextEdit->toPlainText();
    output << text;
    file.close();
    newOpen = true;
}

void Notepad::on_actionPrint_triggered()
{
    QPrintDialog pDialog(&printer, this);
    if (pDialog.exec() == QDialog::Rejected) {
        return;
    }
    ui->plainTextEdit->print(&printer);
}

void Notepad::on_actionSave_triggered()
{
    QString fileName = currentFile;
    if (fileName == "") {
        Notepad::on_actionSave_As_triggered();
        return;
    }
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    QFileInfo info(fileName);
    currentFile = fileName;
    setWindowTitle(info.baseName() + " - Notepad");
    QTextStream output(&file);
    QString text = ui->plainTextEdit->toPlainText();
    output << text;
    file.close();
    newOpen = true;
}

void Notepad::on_actionExit_triggered()
{
    if (windowTitle() == "Untitled - Notepad")
    {
        this->close();
        return;
    }
    if (windowTitle().at(0) != '*')
    {
        this->close();
        return;
    }
    QMessageBox msgBox;
    QFileInfo info(currentFile);
    QString name = info.baseName();
    if (name == ""){
        name = "Untitled";
    }
    msgBox.setText("Do you want to save changes to " + name);
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        Notepad::on_actionSave_triggered();
        this->close();
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        currentFile.clear();
        ui->plainTextEdit->setPlainText(QString());

        setWindowTitle( "Untitled - Notepad");
        this->close();
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        return;
        break;
    default:
        // should never be reached
        break;
    }
}

void Notepad::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void Notepad::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void Notepad::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void Notepad::on_actionPage_Setup_triggered()
{
    QPageSetupDialog pSetupDialog(&printer, this);
    if (pSetupDialog.exec() == QPageSetupDialog::Rejected) {
        QMessageBox::warning(this, "Warning" , "Cannot access printer");
        return;
    }
}

void Notepad::on_actionNew_Window_triggered()
{
    Notepad* notepad = new Notepad();
    notepad->setAttribute(Qt::WA_QuitOnClose, true );
    notepad->show();
}

void Notepad::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        ui->plainTextEdit->setFont(font);
    }
}

void Notepad::on_actionWord_Wrap_toggled(bool arg1)
{
    if (arg1) {
        ui->plainTextEdit->setWordWrapMode(QTextOption::WrapAnywhere);
    }
    else {
        ui->plainTextEdit->setWordWrapMode(QTextOption::NoWrap);
    }
}

void Notepad::processDelete()
{
    ui->actionDelete->setEnabled(!ui->plainTextEdit->textCursor().selectedText().isEmpty());
}

void Notepad::on_actionDelete_triggered()
{
    ui->plainTextEdit->textCursor().deleteChar();
}

void Notepad::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void Notepad::on_actionSearch_with_Google_triggered()
{
    QString link = "https://www.google.com/search?q=";
    QTextCursor textCursor = ui->plainTextEdit->textCursor();
    QString search = textCursor.selectedText();
    QDesktopServices::openUrl(QUrl(link+search));
}

void Notepad::on_actionFind_triggered()
{
    m_findDialog->show();
    m_findDialog->setTextToFind(ui->plainTextEdit->textCursor().selectedText());
}

void Notepad::on_actionABout_Notepad_triggered()
{
    QApplication::aboutQt();
}

void Notepad::on_actionView_Help_triggered()
{
    QString link = "https://www.google.com/search?q=";
    QString version = QSysInfo::productVersion();
    QString product = QSysInfo::productType();
    QString space = " ";
    QString description = "get help with notepad in ";
    QDesktopServices::openUrl(QUrl(link + description + product + space + version));
}

void Notepad::on_actionSend_Feedback_triggered()
{
    QDesktopServices::openUrl(QUrl("mailto:rui_amoah@hotmail.com?subject=Notepad%20Feedback"));
}

void Notepad::on_actionZoom_In_triggered()
{
    if (zoom >= 500)
        return;
    ui->plainTextEdit->zoomIn(1);
    zoom += 10;
    QString strZoom = " " + QString::number(zoom) + "%";
    statusLabelZoom->setText(strZoom.leftJustified(10, ' '));
}

void Notepad::on_actionZoom_Out_triggered()
{
    if (zoom <= 10)
        return;
    ui->plainTextEdit->zoomOut(1);
    zoom -= 10;
    QString strZoom = " " + QString::number(zoom) + "%";
    statusLabelZoom->setText(strZoom.leftJustified(10, ' '));
}

void Notepad::wheelEvent(QWheelEvent *event)
{
    if ( QApplication::keyboardModifiers () == Qt::ControlModifier)
    {
        if (event->angleDelta().y() > 0) {
            Notepad::on_actionZoom_In_triggered();
        } else {
            Notepad::on_actionZoom_Out_triggered();
        }
    }
}

void Notepad::on_actionRestore_Default_Zoom_triggered()
{
    if (zoom > 100) {
        ui->plainTextEdit->zoomOut((zoom - 100) / 10);
    } else if (zoom < 100) {
        ui->plainTextEdit->zoomIn(abs((zoom - 100) / 10));
    }
    zoom = 100;
    QString strZoom = " " + QString::number(zoom) + "%";
    statusLabelZoom->setText(strZoom.leftJustified(10, ' '));
}

void Notepad::on_actionGo_To_triggered()
{
    m_goto->show();
}

void Notepad::on_actionTime_Date_triggered()
{
    QDateTime time =  QDateTime::currentDateTime();
    ui->plainTextEdit->textCursor().insertText(time.toString("h:m ap yyyy-MM-dd"));
}

void Notepad::on_actionStatus_Bar_toggled(bool arg1)
{
    ui->statusbar->setHidden(arg1);
}

void Notepad::on_actionReplace_triggered()
{
    m_findReplaceDialog->show();
    m_findReplaceDialog->setTextToFind(ui->plainTextEdit->textCursor().selectedText());
}

void Notepad::on_actionFind_Next_triggered()
{
    m_findDialog->findNext();
}

void Notepad::on_actionFind_Previous_triggered()
{
    m_findDialog->findPrev();
}

void Notepad::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}

void Notepad::on_plainTextEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int col = cursor.position() - cursor.block().position() + 1;
    int ln = cursor.blockNumber() + 1;
    QString strLnCol = " Ln: " + QString::number(ln) + ", Col: " + QString::number(col);
    statusLabelLnCol->setText(strLnCol.leftJustified(30, ' '));
}

void Notepad::on_plainTextEdit_textChanged()
{
    if (windowTitle().at(0) != '*'){
        newOpen = false;
        QFileInfo info(currentFile);
        QString name = info.baseName();
        if (name == ""){
            name = "Untitled";
        }
        QString output = "*" + name + "- Notepad";
        setWindowTitle(output);
    }
    if (currentFile == "" && ui->plainTextEdit->toPlainText() == "") {
        setWindowTitle( "Untitled - Notepad");
    }
    newOpen = false;
    Notepad::on_plainTextEdit_cursorPositionChanged();
}
