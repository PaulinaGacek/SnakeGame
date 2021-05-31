#include "Board.h"
#include <random>
#include <thread>
void Board::set_new_fruit_position(Snake& snake) {
    bool is_fruit_on_tail = true;
    while(is_fruit_on_tail)
    {
        is_fruit_on_tail = false;
        for(int i = 0; i < snake.get_length(); ++i)
        {
            if(fruit_position_row == snake.get_tail_position_row(i) && fruit_position_col == snake.get_tail_position_col(i))
            {
                is_fruit_on_tail = true;
                break;
            }
        }
        this->fruit_position_row = std::_Random_device() % (gaming_board_width - 6) + 3;
        this->fruit_position_col = std::_Random_device() % (height - 6) + 3;
    }
}
void Board::display_welcome() const {
    system("cls");
    std::ifstream welcome_file;

    welcome_file.open(R"(C:\Users\pauli\CLionProjects\Snake\welcome.txt)");
    char wiersz[41] = {0};
    for (int i = 0; i < 13; ++i) {
        welcome_file.getline(wiersz, 41);
        std::cout << wiersz << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    welcome_file.close();

    welcome_file.open(R"(C:\Users\pauli\CLionProjects\Snake\welcome.txt)");
    if(welcome_file.is_open())
    {
        for(int j = 0; j<17; ++j) {
            system("cls");
            char row[41] = {0};
            for (int i = 0; i < 13; ++i) {
                welcome_file.getline(row, 41);
                std::cout << row << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    welcome_file.close();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Board::display_game_over() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("cls");
    std::fstream game_over_file;
    game_over_file.open(R"(C:\Users\pauli\CLionProjects\Snake\game_over.txt)");
    system("cls");
    char row[41] = {0};
    for (int i = 0; i < 15; ++i) {
        game_over_file.getline(row, 41);
        std::cout << row << std::endl;
    }
    play_game_over_music();
    //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    if(game_over_file.is_open())
    {
        for(int j = 0; j<18; ++j) {
            system("cls");
            char row[41] = {0};
            for (int i = 0; i < 15; ++i) {
                game_over_file.getline(row, 41);
                std::cout << row << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    game_over_file.close();
}
void Board::display_board(Snake& snake) const {

    std::this_thread::sleep_for(std::chrono::milliseconds(2000 / snake.get_speed_value()));
    system("cls");
    for(int i = 0; i < whole_board_width; ++i) printf("#");
    printf("\n");
    char score_sign[6] = {'S','C','O','R','E',':'};
    for(int i = 1; i< height-1; ++i)
    {
        for(int j = 0; j < whole_board_width; ++j) {
            if ((j == 0) || (j == gaming_board_width - 1 || j== whole_board_width-1)) {
                printf("#");
            }
            else if( i ==2 && j >=gaming_board_width+1 && j< gaming_board_width+7)
            {
                printf("%c", score_sign[j-gaming_board_width-1]);
            }
            else if ( i == 2 && (j == gaming_board_width+7 || j ==gaming_board_width+8) )
            {
                unsigned int second_digit = score % 10;
                if(j==gaming_board_width+7)
                {
                    if( score < 10 )
                        printf("0");
                    else
                        printf("%u",(score-score%10)/10);
                }
                if(j==gaming_board_width+8)
                {
                    printf("%u",score%10);
                }
            }
            else if (j == fruit_position_row && i == fruit_position_col)
            {
                printf("F");
            }
            else if( j==snake.get_current_row() && i == snake.get_current_col())
            {
                printf("O");
            }
            else
            {
                bool print = false;
                for(int k = 0; k<snake.get_length(); ++k)
                {
                    if(snake.get_tail_position_row(k)==j && snake.get_tail_position_col(k) == i)
                    {
                        printf("o");
                        print = true;
                    }
                }
                if(!print)
                    printf(" ");
            }
        }
        printf("\n");

    }
    for(int i = 0; i < whole_board_width; ++i) printf("#");
    printf("\n");
}

void Board::play_game_over_music() {
    std::fstream game_over_music_file;
    game_over_music_file.open(R"(C:\Users\pauli\CLionProjects\Snake\BombCut2.wav)", std::ios::in);
    if(game_over_music_file.is_open())
    {
        PlaySound(TEXT("C:\\Users\\pauli\\CLionProjects\\Snake\\GameOver.wav"), nullptr,SND_SYNC);
    }
    else
    {
        std::cout<<"\nAudio file couldn't run..!!";
        std::cout<<"\nCheck the following things: \n 1. Your file is an original .wav audio file. \n 2. You have mentioned '.wav' extension in the name of file. \n 3. It is present in the folder where your program is saved.";
    }
    game_over_music_file.close();
}

void Board::play_score_music() {
    std::fstream game_over_music_file;
    game_over_music_file.open(R"(C:\Users\pauli\CLionProjects\Snake\BombCut2.wav)", std::ios::in);
    if(game_over_music_file.is_open())
    {
        PlaySound(TEXT("C:\\Users\\pauli\\CLionProjects\\Snake\\Score.wav"), nullptr,SND_SYNC);
    }
    else
    {
        std::cout<<"\nAudio file couldn't run..!!";
        std::cout<<"\nCheck the following things: \n 1. Your file is an original .wav audio file. \n 2. You have mentioned '.wav' extension in the name of file. \n 3. It is present in the folder where your program is saved.";
    }
    game_over_music_file.close();
}
