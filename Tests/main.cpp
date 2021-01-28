#include "tst_notepadtestcase.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    Notepad w;
    w.setAttribute(Qt::WA_QuitOnClose, true );
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
