#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

class Snake {
private:
    unsigned int current_position_row = {1};
    unsigned int current_position_col = {1};
    int length = {0};
    constexpr static unsigned int max_length = 25;
    unsigned int tail_row[25]={0}, tail_col[25]={0};
    //movement
    int speed[6]={5,10,20,50,80,100};
    size_t current_speed = {2};
    enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
    direction current_direction = {STOP};

public:
    void increment_length(){ if(length<max_length)length++;}
    int get_length(){return length;}
    //movement
    void set_direction();
    void calculate_tail_position();
    void animate();
    unsigned int get_current_row() const {return current_position_row;}
    unsigned int get_current_col() const {return current_position_col;}
    int get_speed_value(){return speed[current_speed];}

    unsigned int get_tail_position_row(size_t place);
    unsigned int get_tail_position_col(size_t place);
    void set_tail_position_row(size_t place, unsigned int value);
    void set_tail_position_col(size_t place, unsigned int value);
};


#endif //SNAKE_SNAKE_H
