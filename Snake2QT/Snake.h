#ifndef SNAKE2QT_SNAKE_H
#define SNAKE2QT_SNAKE_H
#include <iostream>
enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
class Snake {
private:
    unsigned int length = {3};
    constexpr static unsigned int MAX_LENGTH = 50;
    int x[MAX_LENGTH]={};
    int y[MAX_LENGTH]={};
    //movement
    int speed[6]={1,2,3,5,6,10};
    size_t current_speed = {1};
    Direction current_direction = Direction::STOP;
public:
    [[nodiscard]] int get_speed() const{return current_speed;}
    [[nodiscard]] unsigned int get_length() const{return length;}
    void increment_length(){length++;}
    [[nodiscard]] Direction get_direction() const{ return current_direction;}
    void set_direction(Direction d){current_direction = d;}
    void animate();
    void set_tail_X(size_t index, int position);
    void set_tail_Y(size_t index, int position);
    int get_tail_X(size_t index);
    int get_tail_Y(size_t index);
};

#endif //SNAKE2QT_SNAKE_H
