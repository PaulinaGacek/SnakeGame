//
// Created by pauli on 03.06.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_St_Window.h" resolved

#include "st_window.h"
#include "ui_St_Window.h"
#include <iostream>
#include <QPainter>

St_Window::St_Window(QWidget *parent) :
        QDialog(parent), ui(new Ui::St_Window) {
    ui->setupUi(this);
    //display_welcome();
    QPixmap pix(R"(C:\Users\pauli\CLionProjects\Snake2QT\cmake-build-debug\WelcomeIMG.png)");
    ui->piq->setPixmap(pix);
}

St_Window::~St_Window() {
    delete ui;
}

void St_Window::on_pushButton_clicked()
{
    this->close();
}

void St_Window::display_welcome() {

    QPainter qp(this);
    QString message = "Game over";
    QFont font("Courier", 20, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}
