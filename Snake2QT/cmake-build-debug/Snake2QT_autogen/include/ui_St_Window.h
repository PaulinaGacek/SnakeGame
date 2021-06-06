/********************************************************************************
** Form generated from reading UI file 'st_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ST_WINDOW_H
#define UI_ST_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_St_Window
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *piq;

    void setupUi(QDialog *St_Window)
    {
        if (St_Window->objectName().isEmpty())
            St_Window->setObjectName(QString::fromUtf8("St_Window"));
        St_Window->resize(400, 350);
        St_Window->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 216, 209);"));
        centralwidget = new QWidget(St_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 260, 121, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(10);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(28, 25));
        pushButton->setAutoDefault(true);
        piq = new QLabel(centralwidget);
        piq->setObjectName(QString::fromUtf8("piq"));
        piq->setGeometry(QRect(50, 50, 301, 181));
        piq->setPixmap(QPixmap(QString::fromUtf8("../../CLionProjects/Snake2QT/cmake-build-debug/WelcomeIMG.png")));

        retranslateUi(St_Window);

        QMetaObject::connectSlotsByName(St_Window);
    } // setupUi

    void retranslateUi(QDialog *St_Window)
    {
        St_Window->setWindowTitle(QCoreApplication::translate("St_Window", "Welcome to Snake", nullptr));
        pushButton->setText(QCoreApplication::translate("St_Window", "PLAY", nullptr));
        piq->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class St_Window: public Ui_St_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ST_WINDOW_H
