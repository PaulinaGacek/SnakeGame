#ifndef SNAKE2QT_BOARD_H
#define SNAKE2QT_BOARD_H

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

    [[maybe_unused]] explicit Board(int h, int w,QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

private:
    Snake snake;
    QImage body, coin, brick, apple;
    QImage head_UP, head_DOWN, head_RIGHT, head_LEFT;
    QImage head_UP_BR, head_DOWN_BR, head_RIGHT_BR, head_LEFT_BR;

    static constexpr int WIDTH = 300;
    static constexpr int HEIGHT = 300;
    static constexpr int PIXEL_SIZE = 10;

    static constexpr int PIXELS_X = 28;
    static constexpr int PIXELS_Y = 24;
    static const int DELAY = 120;

    int timerId = 0;
    unsigned int score = 0;
    unsigned int high_score = 0;

    unsigned int fruit_x_pos = 3;
    unsigned int fruit_y_pos = 3;

    bool game_on = true;

    void load_images();
    void play_game();
    void set_new_fruit_position();
    void check_score();
    void check_collision();
    void animate_snake();
    void display_board();
    void display_welcome();
    void game_over(QPainter &qp);
    static void play_game_over_music();
    void save_score();
    unsigned int get_high_score_from_file() const;
};

#endif //SNAKE2QT_BOARD_H
