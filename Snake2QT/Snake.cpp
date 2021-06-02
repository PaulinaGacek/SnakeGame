//
// Created by pauli on 02.06.2021.
//

#include "Snake.h"

void Snake::set_tail_X(size_t index, int position) {
    //if(index >= length)
        //throw std::invalid_argument("Invalid index");
    x[index] = position;
}

void Snake::set_tail_Y(size_t index, int position) {
    //if(index >= length)
        //throw std::invalid_argument("Invalid index");
    y[index] = position;
}

int Snake::get_tail_X(size_t index) {
    //if(index >= length)
        //throw std::invalid_argument("Invalid index");
    return x[index];
}

int Snake::get_tail_Y(size_t index) {
    //if(index >= length)
        //throw std::invalid_argument("Invalid index");
    return y[index];
}