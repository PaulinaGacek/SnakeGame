#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include "Snake.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>


class Board {
    unsigned int gaming_board_width{28};
    unsigned int whole_board_width{40};
    unsigned int height{15};
    unsigned int score{0};

    unsigned int fruit_position_row = {3};
    unsigned int fruit_position_col = {3};
public:
    void set_new_fruit_position(Snake& snake);
    void display_welcome() const;
    void display_game_over()const;
    void display_board(Snake& snake) const;
    unsigned int get_width()const{return this->gaming_board_width;}
    unsigned int get_height()const{return this->height;}
    unsigned int get_fruit_row()const{return this->fruit_position_row;}
    unsigned int get_fruit_col()const{return this->fruit_position_col;}
    void increment_score_to_display(){score++;}
    static void play_game_over_music();
    static void play_score_music();
};


#endif //SNAKE_BOARD_H