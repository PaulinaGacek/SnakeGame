/******Usprawnienia jakie trzeba dolozyc:
1. Interejs
2. Zapisywanie rekordu do pliku
3. Wybor kolorkow
4. Dzwiek przy zjadaniu
5. Interfejs Game Over z muzyczka
6. High score przy kolejnych grach
*******/
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

#include "Board.h"
#include "GameRound.h"
int main() {
    char signal = 'a';
    Board board;
    //board.display_welcome();
    while(signal == 'a')
    {
        GameRound::play_game(board);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        if(_kbhit()) {
            switch (_getch()) {
                case 'a':
                    signal = 'a';
                    break;
                case 'x':
                    signal = 'x';
                    break;
                default:
                    signal = 'x';
            }
        }
        else
            signal = 'x';
    }
    return 0;
}