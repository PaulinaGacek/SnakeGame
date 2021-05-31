#include <conio.h>
#include <thread>
#include "Snake.h"
#include "GameRound.h"
unsigned int Snake::get_tail_position_row(size_t place)
{
    if(place>length)
    {
        printf("Error: too big number given as length");
        exit(2);
    }
    return tail_row[place];
};
unsigned int Snake::get_tail_position_col(size_t place)
{
    if(place>length)
    {
        printf("Error: too big number given as length");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        exit(2);
    }
    return tail_col[place];
};
void Snake::set_tail_position_row(size_t place, unsigned int value)
{
    if(place>length)
    {
        printf("Error: too big number given as length - row");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        exit(2);
    }
    tail_row[place]=value;
}
void Snake::set_tail_position_col(size_t place, unsigned int value)
{
    if(place>=length)
    {
        printf("Error: too big number given as length - column");
        exit(2);
    }
    tail_col[place]=value;
}
void Snake::set_direction() {
    if(_kbhit()) {
        switch (_getch()) {
            case 'a':
                this->current_direction = LEFT;

                break;
            case 'd':
                this->current_direction = RIGHT;
                break;
            case 'w':
                this->current_direction = UP;
                break;
            case 's':
                this->current_direction = DOWN;
                break;
            case 'x':
                GameRound::set_current_state(true);
                break;
        }
    }
}
void Snake::calculate_tail_position() {
    unsigned int previous_position_row = tail_row[0];
    unsigned int previous_position_col = tail_col[0];
    unsigned int pre_previous_position_row = tail_row[0];
    unsigned int pre_previous_position_col = tail_col[0];
    tail_row[0]=get_current_row();
    tail_col[0]=get_current_col();

    for(int i = 1; i< length; ++i)
    {
        pre_previous_position_row = tail_row[i];
        pre_previous_position_col = tail_col[i];

        tail_row[i]= previous_position_row;
        tail_col[i]=previous_position_col;

        previous_position_row = pre_previous_position_row;
        previous_position_col = pre_previous_position_col;
    }
}
void Snake::animate() {
    switch (current_direction)
    {
        case LEFT:
            current_position_row--;
            break;
        case RIGHT:
            current_position_row++;
            break;
        case UP:
            current_position_col--;
            break;
        case DOWN:
            current_position_col++;
            break;
        default:
            break;
    }
}