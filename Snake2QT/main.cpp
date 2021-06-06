#include <QApplication>
#include "Board.h"
#include "StartWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    //StartWindow start_window;
    //start_window.setWindowTitle("Snake");
    //start_window.setModal(true);
    //start_window.show();

    Board window;
    window.setWindowTitle("Snake");
    window.show();
    return QApplication::exec();
}