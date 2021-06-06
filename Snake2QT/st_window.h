//
// Created by pauli on 03.06.2021.
//

#ifndef SNAKE2QT_ST_WINDOW_H
#define SNAKE2QT_ST_WINDOW_H

#include <QDialog>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class St_Window; }
QT_END_NAMESPACE

class St_Window : public QDialog {
Q_OBJECT

public:
    explicit St_Window(QWidget *parent = nullptr);

    ~St_Window() override;
private slots:
    void on_pushButton_clicked();
    void display_welcome();
private:
    Ui::St_Window *ui;
};

#endif //SNAKE2QT_ST_WINDOW_H
