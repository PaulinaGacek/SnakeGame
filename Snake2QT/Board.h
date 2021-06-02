#ifndef SNAKE2QT_BOARD_H
#define SNAKE2QT_BOARD_H
#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Snake.h"

class Board : public QWidget {

public:
    explicit Board(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

private:
    Snake snake;
    QImage body;
    QImage head;
    QImage coin;
    QImage brick;

    static constexpr int WIDTH = 300;
    static constexpr int HEIGHT = 300;
    static constexpr int PIXEL_SIZE = 10;

    static constexpr int PIXELS_X = 28;
    static constexpr int PIXELS_Y = 24;
    static const int DELAY = 120;

    int timerId;
    unsigned int score = 0;

    unsigned int fruit_x_pos;
    unsigned int fruit_y_pos;

    bool inGame = true;

    void loadImages();
    void initGame();
    void set_new_fruit_position();
    void check_score();
    void checkCollision();
    void move();
    void display_board();
    void gameOver(QPainter &);
    static void play_game_over_music();
};
#endif //SNAKE2QT_BOARD_H
