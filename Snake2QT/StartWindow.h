#ifndef SNAKE2QT_STARTWINDOW_H
#define SNAKE2QT_STARTWINDOW_H
#include <QWidget>
#include <QDialog>
#include <QKeyEvent>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
namespace Ui{
    class StartWindow;
}
class StartWindow: public QDialog {
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = nullptr);

private:
    Ui::StartWindow *ui{};
};

#endif //SNAKE2QT_STARTWINDOW_H
