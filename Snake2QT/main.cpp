#include <QApplication>
#include "Board.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    Board window;
    window.setWindowTitle("Snake");
    window.show();
    return QApplication::exec();
}