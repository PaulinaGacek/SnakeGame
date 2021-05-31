#include "GameRound.h"

bool GameRound::game_over= {false};
GameRound* GameRound::game_instance = {nullptr};
unsigned int GameRound::score = {0};
GameRound *GameRound::get_instance() {
    if (game_instance== nullptr)
    {
        game_instance = new GameRound();
    }
    return game_instance;
}
void GameRound::set_current_state(bool if_loosed) {
    game_over = if_loosed;
}
bool GameRound::get_current_state(){
    return game_over;
};
void GameRound::check_if_game_is_over(const Snake &snake, const Board &board) {
    if( snake.get_current_row() == board.get_width()-1 )
    {
        set_current_state(true);
        return;
    }
    if(snake.get_current_row() == 0 )
    {
        set_current_state(true);
        return;
    }
    if(snake.get_current_col() == 0 )
    {
        set_current_state(true);
        return;
    }
    if(snake.get_current_col() == board.get_height()-1 )
    {
        set_current_state(true);
        return;
    }
}
void GameRound::check_score(Snake& snake, Board &board)
{
    if(snake.get_current_row()==board.get_fruit_row() && snake.get_current_col()==board.get_fruit_col())
    {
        //Board::play_score_music();
        //printf("\a");
        //sound(2000); //to activate the sound
        //nosound(); //to deactivate the sound

        GameRound::score++;
        board.increment_score_to_display();
        snake.increment_length();
        board.set_new_fruit_position(snake);
    }
    for(int i=0; i< snake.get_length();++i)
    {
        if(snake.get_tail_position_row(i)==snake.get_current_row() && snake.get_tail_position_col(i)==snake.get_current_col())
        {
            GameRound::set_current_state(true);
            break;
        }
    }
};
unsigned int GameRound::get_score()
{
    return score;
}

void GameRound::play_game(Board &board) {
    Snake snake;

    board.set_new_fruit_position(snake);

    set_current_state(false);
    while(!get_current_state())
    {
        check_if_game_is_over(snake, board);
        check_score(snake, board);
        board.display_board(snake);
        snake.set_direction();
        snake.calculate_tail_position();
        snake.animate();
        //GameRound::check_score(snake, board);
        std::cout << "\nScore: "<< get_score();
        std::cout << "\nLength: " << snake.get_length() << std::endl;
        std::cout << "\nFruit: "<< std::endl;
    }
    board.display_game_over();
}

