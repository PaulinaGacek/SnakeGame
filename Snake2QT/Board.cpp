#include <QPainter>
#include <QTime>
#include "Board.h"
#include "st_window.h"

#include <random>
#include <thread>
#include <ctime>

Board::Board(QWidget *parent) : QWidget(parent) {
    St_Window startWindow;
    startWindow.setModal(true);
    startWindow.exec();
    setStyleSheet("background-color: rgb(216, 216, 209)");
    setFixedSize(WIDTH, HEIGHT);
    load_images();
    high_score = get_high_score_from_file();
    play_game();
}

[[maybe_unused]] Board::Board(int h, int w, QWidget *parent) {
    setStyleSheet("background-color: rgb(216, 216, 209)");
    setFixedSize(w,h);
    load_images();
}

void Board::load_images() {

    body.load("body.png");
    coin.load("coin.png");
    brick.load("brick.png");
    apple.load("apple.png");

    head_UP.load("head_UP.png");
    head_DOWN.load("head_DOWN.png");
    head_RIGHT.load("head_RIGHT.png");
    head_LEFT.load("head_LEFT.png");

    head_UP_BR.load("head_UP_BR.png");
    head_DOWN_BR.load("head_DOWN_BR.png");
    head_RIGHT_BR.load("head_RIGHT_BR.png");
    head_LEFT_BR.load("head_LEFT_BR.png");
}

void Board::play_game() {

    for (int i = 0; i < snake.get_length(); ++i) {
        snake.set_tail_X(i,50-i*11);
        snake.set_tail_Y(i,50);
    }
    set_new_fruit_position();
    timerId = startTimer(DELAY/snake.get_speed());
    display_welcome();
}

void Board::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    display_board();
}

void Board::display_board() {

    QPainter qp(this);

    if (game_on) {
        qp.drawImage((int)fruit_x_pos, (int)fruit_y_pos, apple);
        for(int i = 0; i < WIDTH/PIXEL_SIZE; ++i)
        {
            qp.drawImage(i*PIXEL_SIZE-1,-1,brick);
            qp.drawImage(i*PIXEL_SIZE-1,HEIGHT-3*PIXEL_SIZE+1,brick);
            qp.drawImage(i*PIXEL_SIZE-1,HEIGHT-PIXEL_SIZE+1,brick);
            for(int j = 1; j < HEIGHT/PIXEL_SIZE-1; ++j)
            {
                qp.drawImage(-1,j*PIXEL_SIZE,brick);
                qp.drawImage(WIDTH-PIXEL_SIZE,j*PIXEL_SIZE,brick);
            }
        }
        switch (snake.get_direction()) {
            case Direction::STOP:
                qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_RIGHT);
                break;
            case Direction::LEFT:
                if(snake.get_tail_X(0) < PIXEL_SIZE )
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_LEFT_BR);
                else
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_LEFT);
                break;
            case Direction::RIGHT:
                if (snake.get_tail_X(0) >= WIDTH-PIXEL_SIZE)
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_RIGHT_BR);
                else
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_RIGHT);
                break;
            case Direction::UP:
                if (snake.get_tail_Y(0)< PIXEL_SIZE)
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_UP_BR);
                else
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_UP);
                break;
            case Direction::DOWN:
                if (snake.get_tail_Y(0) >= HEIGHT-3*PIXEL_SIZE)
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_DOWN_BR);
                else
                    qp.drawImage(snake.get_tail_X(0), snake.get_tail_Y(0), head_DOWN);
                break;
        }
        for (int i = 1; i < snake.get_length(); ++i) {
                qp.drawImage(snake.get_tail_X(i), snake.get_tail_Y(i), body);
        }
        QString message = "Score: ";
        QString message2 = "   High Score: ";
        QString s = QString::number(score);
        QString hs = QString::number(high_score);
        QFont font("Courier", 9, QFont::DemiBold);
        QFontMetrics fm(font);
        qp.setFont(font);
        qp.drawText(2* PIXEL_SIZE, HEIGHT-PIXEL_SIZE, message+s+message2+hs);
    }
    else {
        game_over(qp);
    }
}
void Board::display_welcome() {
    QPainter qp(this);
    for(int i = 0; i < WIDTH/PIXEL_SIZE; ++i)
    {
        qp.drawImage(i*PIXEL_SIZE-1,-1,brick);
        qp.drawImage(i*PIXEL_SIZE-1,HEIGHT-3*PIXEL_SIZE+1,brick);
        qp.drawImage(i*PIXEL_SIZE-1,HEIGHT-PIXEL_SIZE+1,brick);
        for(int j = 1; j < HEIGHT/PIXEL_SIZE-1; ++j)
        {
            qp.drawImage(-1,j*PIXEL_SIZE,brick);
            qp.drawImage(WIDTH-PIXEL_SIZE,j*PIXEL_SIZE,brick);
        }
    }
    QString message = "Welcome to SNAKE";
    QFont font("Courier", 20, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    repaint();
}


void Board::game_over(QPainter &qp) {

    QString message = "Game over";
    QFont font("Courier", 20, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    save_score();
    if(score > high_score) high_score = score;

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
    play_game_over_music();
}

void Board::check_score() {

    if ((snake.get_tail_X(0) == fruit_x_pos) && (snake.get_tail_Y(0) == fruit_y_pos)) {
        snake.increment_length();
        set_new_fruit_position();
        score++;
    }
}

void Board::animate_snake() {

    for (unsigned int i = snake.get_length(); i > 0; --i) {
        snake.set_tail_X(i,snake.get_tail_X(i-1));
        snake.set_tail_Y(i,snake.get_tail_Y(i-1));
    }

    if (snake.get_direction()==Direction::LEFT) {
        snake.set_tail_X(0, snake.get_tail_X(0) - PIXEL_SIZE);
    }

    if (snake.get_direction()==Direction::RIGHT) {
        snake.set_tail_X(0, snake.get_tail_X(0) + PIXEL_SIZE);
    }

    if (snake.get_direction()==Direction::UP) {
        snake.set_tail_Y(0, snake.get_tail_Y(0) - PIXEL_SIZE);
    }

    if (snake.get_direction()==Direction::DOWN) {
        snake.set_tail_Y(0, snake.get_tail_Y(0) + PIXEL_SIZE);
    }
}

void Board::check_collision() {

    for (unsigned int i = snake.get_length(); i > 0; --i) {

        if ((i > 4) && (snake.get_tail_X(0) == snake.get_tail_X(i))
        && (snake.get_tail_Y(0) == snake.get_tail_Y(i))) {
            game_on = false;
        }
    }

    if (snake.get_tail_Y(0) >= HEIGHT-3*PIXEL_SIZE) {
        game_on = false;
    }

    if (snake.get_tail_Y(0)< PIXEL_SIZE) {
        game_on = false;
    }

    if (snake.get_tail_X(0) >= WIDTH-PIXEL_SIZE) {
        game_on = false;
    }

    if (snake.get_tail_X(0) < PIXEL_SIZE) {
        game_on = false;
    }

    if(!game_on) {
        killTimer(timerId);
    }
}

void Board::set_new_fruit_position() {

    //fruit_x_pos = fruit_y_pos = 0;
    bool is_on_tail = true;
    int random = 7;
    while(is_on_tail)
    {
        fruit_x_pos = ((std::_Random_device()+random) % PIXELS_X + 1) * PIXEL_SIZE;
        fruit_y_pos = ((std::_Random_device()+random-2) % PIXELS_Y + 1) * PIXEL_SIZE;
        is_on_tail = false;
        for(int i = 0; i < snake.get_length(); ++i)
        {
            if(snake.get_tail_X(i)==fruit_x_pos && snake.get_tail_Y(i)==fruit_y_pos)
            {
                is_on_tail = true;
                random--;
                break;
            }
        }
    }
}

void Board::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    if (game_on) {
        check_score();
        check_collision();
        animate_snake();
    }
    repaint();
}

void Board::keyPressEvent(QKeyEvent *e) {

    int key = e->key();

    if ((key == Qt::Key_Left) && (snake.get_direction()!=Direction::RIGHT))
        snake.set_direction(Direction::LEFT);

    if ((key == Qt::Key_Right) && (snake.get_direction()!=Direction::LEFT))
        snake.set_direction(Direction::RIGHT);

    if ((key == Qt::Key_Up) && (snake.get_direction()!=Direction::DOWN))
        snake.set_direction(Direction::UP);

    if ((key == Qt::Key_Down) && (snake.get_direction()!=Direction::UP))
        snake.set_direction(Direction::DOWN);

    QWidget::keyPressEvent(e);
}

void Board::play_game_over_music() {
    std::fstream game_over_music_file;
    game_over_music_file.open("GameOver.wav", std::ios::in);
    if(game_over_music_file.is_open())
    {
        PlaySound(TEXT("GameOver.wav"), nullptr,SND_SYNC);
    }
    else
    {
        std::cout<<"\nAudio file couldn't run..!!";
        std::cout<<"\nCheck the following things: \n 1. Your file is an original .wav audio file. \n 2. You have mentioned '.wav' extension in the name of file. \n 3. It is present in the folder where your program is saved.";
    }
    game_over_music_file.close();
}

void Board::save_score() {
    std::fstream log_file;
    log_file.open("high_score.txt", std::ios_base::app);
    time_t now = time(nullptr);
    char buffer[100] = {};
    strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S", gmtime(&now));

    log_file << score << " : " << buffer<< "\n";
    log_file.close();
}

unsigned int Board::get_high_score_from_file() const {
    unsigned int hs = 0;
    std::fstream log_file;
    log_file.open("high_score.txt");
    while(!log_file.eof())
    {
        unsigned int temp_score;
        log_file >> temp_score;
        if( temp_score > hs )
        {
            hs = temp_score;
        }
        char buffer[40] = {};
        log_file.getline(buffer,39);
    }
    log_file.close();
    return hs;
}



