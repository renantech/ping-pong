#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PADDLE_WIDTH = 10;
const int PADDLE_HEIGHT = 60;
const int BALL_RADIUS = 5;
const float PADDLE_SPEED = 5.0f;
const float BALL_SPEED = 3.0f;
const float GAME_START_DELAY = 2.0f;
const int WINNING_SCORE = 10;

struct Paddle {
    float x, y;
    float dy;
    ALLEGRO_COLOR color; // Nova adição
};

struct Ball {
    float x, y;
    float dx, dy;
};

bool checkCollision(float x1, float y1, int width1, int height1, float x2, float y2, int width2, int height2) {
    if (x1 + width1 < x2 || x1 > x2 + width2 || y1 + height1 < y2 || y1 > y2 + height2) {
        return false;
    }
    return true;
}

void showWinner(ALLEGRO_FONT* font, const char* winnerText) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, winnerText);
    al_flip_display();
    al_rest(2.0);
}

int main() {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_FONT* font = NULL;

    bool redraw = true;
    bool quit = false;
    bool gameStarted = false;
    float gameStartTimer = 0.0f;
    int score1 = 0;
    int score2 = 0;

    Paddle player1 = { 10, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, 0, al_map_rgb(255, 0, 0) }; // Nova adição
    Paddle player2 = { SCREEN_WIDTH - PADDLE_WIDTH - 10, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, 0, al_map_rgb(0, 0, 255) }; // Nova adição
    Ball ball = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, -BALL_SPEED, BALL_SPEED };

    bool showMenu = true;
    bool startGame = false;

    if (!al_init()) {
        std::cerr << "Failed to initialize Allegro." << std::endl;
        return -1;
    }

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        std::cerr << "Failed to create display." << std::endl;
        return -1;
    }

    al_install_keyboard();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    font = al_load_font("arial.ttf", 24, 0);
    if (!font) {
        std::cerr << "Failed to load font." << std::endl;
        return -1;
    }

    event_queue = al_create_event_queue();
    if (!event_queue) {
        std::cerr << "Failed to create event queue." << std::endl;
        return -1;
    }

    timer = al_create_timer(1.0 / 60);
    if (!timer) {
        std::cerr << "Failed to create timer." << std::endl;
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    al_start_timer(timer);

    while (!quit) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (showMenu) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100, ALLEGRO_ALIGN_CENTER, "PING PONG!");
            al_draw_text(font, al_map_rgb(0, 255, 0), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "Press Enter to Start");
            al_draw_text(font, al_map_rgb(255, 0, 0), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50, ALLEGRO_ALIGN_CENTER, "Press Esc to Quit");
            al_flip_display();

            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_ENTER:
                    showMenu = false;
                    startGame = true;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    quit = true;
                    break;
                }
            }
        }
        else if (startGame) {
            if (ev.type == ALLEGRO_EVENT_TIMER) {
                redraw = true;

                if (gameStarted) {
                    player1.y += player1.dy;
                    player2.y += player2.dy;

                    if (player1.y < 0) {
                        player1.y = 0;
                    }
                    else if (player1.y + PADDLE_HEIGHT > SCREEN_HEIGHT) {
                        player1.y = SCREEN_HEIGHT - PADDLE_HEIGHT;
                    }

                    if (player2.y < 0) {
                        player2.y = 0;
                    }
                    else if (player2.y + PADDLE_HEIGHT > SCREEN_HEIGHT) {
                        player2.y = SCREEN_HEIGHT - PADDLE_HEIGHT;
                    }

                    ball.x += ball.dx;
                    ball.y += ball.dy;

                    if (ball.y - BALL_RADIUS < 0 || ball.y + BALL_RADIUS > SCREEN_HEIGHT) {
                        ball.dy = -ball.dy;
                    }

                    if (checkCollision(ball.x - BALL_RADIUS, ball.y - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2,
                        player1.x, player1.y, PADDLE_WIDTH, PADDLE_HEIGHT)) {
                        ball.dx = -ball.dx;
                    }

                    if (checkCollision(ball.x - BALL_RADIUS, ball.y - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2,
                        player2.x, player2.y, PADDLE_WIDTH, PADDLE_HEIGHT)) {
                        ball.dx = -ball.dx;
                    }

                    if (ball.x - BALL_RADIUS < 0) {
                        score2++;
                        ball.x = SCREEN_WIDTH / 2;
                        ball.y = SCREEN_HEIGHT / 2;
                        ball.dx = BALL_SPEED;
                        ball.dy = BALL_SPEED;
                    }
                    else if (ball.x + BALL_RADIUS > SCREEN_WIDTH) {
                        score1++;
                        ball.x = SCREEN_WIDTH / 2;
                        ball.y = SCREEN_HEIGHT / 2;
                        ball.dx = -BALL_SPEED;
                        ball.dy = BALL_SPEED;
                    }

                    if (score1 == WINNING_SCORE) {
                        showWinner(font, "Player 1 Wins!");
                        score1 = 0;
                        score2 = 0;
                        gameStarted = false;
                        showMenu = true;
                        startGame = false;
                        
                    }
                    else if (score2 == WINNING_SCORE) {
                        showWinner(font, "Player 2 Wins!");
                        score1 = 0;
                        score2 = 0;
                        gameStarted = false;
                        showMenu = true;
                        startGame = false;
                    }
                }
                else {
                    gameStartTimer += 1.0f / 60;
                    if (gameStartTimer >= GAME_START_DELAY) {
                        gameStarted = true;
                    }
                }
            }
            else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    player2.dy = -PADDLE_SPEED;
                    break;
                case ALLEGRO_KEY_DOWN:
                    player2.dy = PADDLE_SPEED;
                    break;
                case ALLEGRO_KEY_W:
                    player1.dy = -PADDLE_SPEED;
                    break;
                case ALLEGRO_KEY_S:
                    player1.dy = PADDLE_SPEED;
                    break;
                }
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    player2.dy = 0;
                    break;
                case ALLEGRO_KEY_DOWN:
                    player2.dy = 0;
                    break;
                case ALLEGRO_KEY_W:
                    player1.dy = 0;
                    break;
                case ALLEGRO_KEY_S:
                    player1.dy = 0;
                    break;
                }
            }

            if (redraw && al_is_event_queue_empty(event_queue)) {
                redraw = false;

                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_filled_rectangle(player1.x, player1.y, player1.x + PADDLE_WIDTH, player1.y + PADDLE_HEIGHT, player1.color);
                al_draw_filled_rectangle(player2.x, player2.y, player2.x + PADDLE_WIDTH, player2.y + PADDLE_HEIGHT, player2.color);
                al_draw_filled_circle(ball.x, ball.y, BALL_RADIUS, al_map_rgb(255, 255, 255));
                al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 10, ALLEGRO_ALIGN_CENTER, "%d - %d", score1, score2);

                al_flip_display();
            }
        }
    }

    al_destroy_font(font);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}
