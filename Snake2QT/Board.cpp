#include <QPainter>
#include <QTime>
#include "Board.h"
#include <random>

Board::Board(QWidget *parent) : QWidget(parent) {

    setStyleSheet("background-color: rgb(216, 216, 209)");

    setFixedSize(WIDTH, HEIGHT);
    loadImages();
    initGame();
}

void Board::loadImages() {

    body.load("body.png");
    head.load("head.png");
    coin.load("coin.png");
    brick.load("brick.png");
}

void Board::initGame() {

    for (int i = 0; i < snake.get_length(); ++i) {
        snake.set_tail_X(i,50-i*10);
        snake.set_tail_Y(i,50);
    }
    set_new_fruit_position();
    timerId = startTimer(DELAY/snake.get_speed());
}

void Board::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    display_board();
}

void Board::display_board() {

    QPainter qp(this);

    if (inGame) {
        qp.drawImage((int)fruit_x_pos, (int)fruit_y_pos, coin);
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

        for (int i = 0; i < snake.get_length(); ++i) {
            if (i == 0) {
                qp.drawImage(snake.get_tail_X(i), snake.get_tail_Y(i), head);
            } else {
                qp.drawImage(snake.get_tail_X(i), snake.get_tail_Y(i), body);
            }
        }
        QString message = "Score: ";
        QString s = QString::number(score);
        QFont font("Courier", 9, QFont::DemiBold);
        QFontMetrics fm(font);
        qp.setFont(font);
        qp.drawText(2* PIXEL_SIZE, HEIGHT-PIXEL_SIZE, message+s);
    }
    else {
        gameOver(qp);
    }
}

void Board::gameOver(QPainter &qp) {

    QString message = "Game over";
    QFont font("Courier", 17, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int h = height();
    int w = width();

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

void Board::move() {

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

void Board::checkCollision() {

    for (unsigned int i = snake.get_length(); i > 0; --i) {

        if ((i > 4) && (snake.get_tail_X(0) == snake.get_tail_X(i))
        && (snake.get_tail_Y(0) == snake.get_tail_Y(i))) {
            inGame = false;
        }
    }

    if (snake.get_tail_Y(0) >= HEIGHT-3*PIXEL_SIZE) {
        inGame = false;
    }

    if (snake.get_tail_Y(0)< PIXEL_SIZE) {
        inGame = false;
    }

    if (snake.get_tail_X(0) >= WIDTH-PIXEL_SIZE) {
        inGame = false;
    }

    if (snake.get_tail_X(0) < PIXEL_SIZE) {
        inGame = false;
    }

    if(!inGame) {
        killTimer(timerId);
    }
}

void Board::set_new_fruit_position() {

    fruit_x_pos = fruit_y_pos = 0;
    fruit_x_pos = (std::_Random_device() % PIXELS_X + 1) * PIXEL_SIZE;
    fruit_y_pos = (std::_Random_device() % PIXELS_Y + 1) * PIXEL_SIZE;
}

void Board::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    if (inGame) {
        check_score();
        checkCollision();
        move();
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
