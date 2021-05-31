#ifndef SNAKE_GAMEROUND_H
#define SNAKE_GAMEROUND_H
#include "Snake.h"
#include "Board.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
//#include <dos.h>
class GameRound {
private:
    static unsigned int score;
    static bool game_over;
    static GameRound *game_instance;
    //static std::mutex mutex;
protected:
    GameRound(){}
    ~GameRound(){}
public:
    GameRound(GameRound &new_instance) = delete;
    void operator=(const GameRound&) = delete;
    static GameRound *get_instance();
    static void set_current_state(bool if_loosed);
    static bool get_current_state();
    static void check_if_game_is_over(const Snake& s, const Board &board);
    static void check_score(Snake& s, Board &board);
    static unsigned int get_score();
    static void play_game(Board &board);
};

#endif //SNAKE_GAMEROUND_H