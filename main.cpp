#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PADDLE_WIDTH = 10;
const int PADDLE_HEIGHT = 80;
const int BALL_SIZE = 10;
const float PADDLE_SPEED = 4.0;
const float BALL_SPEED = 4.0;

struct Paddle {
    float x, y;
    float dy;
};

struct Ball {
    float x, y;
    float dx, dy;
};

void movePaddle(Paddle& paddle, bool up, bool down) {
    paddle.dy = 0;

    if (up) {
        paddle.dy = -PADDLE_SPEED;
    }

    if (down) {
        paddle.dy = PADDLE_SPEED;
    }

    paddle.y += paddle.dy;

    if (paddle.y < 0) {
        paddle.y = 0;
    }

    if (paddle.y + PADDLE_HEIGHT > SCREEN_HEIGHT) {
        paddle.y = SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

void moveBall(Ball& ball) {
    ball.x += ball.dx;
    ball.y += ball.dy;

    if (ball.y < 0 || ball.y + BALL_SIZE > SCREEN_HEIGHT) {
        ball.dy = -ball.dy;
    }
}

void drawPaddle(const Paddle& paddle) {
    al_draw_filled_rectangle(paddle.x, paddle.y, paddle.x + PADDLE_WIDTH, paddle.y + PADDLE_HEIGHT, al_map_rgb(255, 255, 255));
}

void drawBall(const Ball& ball) {
    al_draw_filled_circle(ball.x, ball.y, BALL_SIZE / 2, al_map_rgb(255, 255, 255));
}

int main() {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* eventQueue = NULL;
    ALLEGRO_TIMER* timer = NULL;

    if (!al_init()) {
        return -1;
    }

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        return -1;
    }

    al_init_primitives_addon();
    al_install_keyboard();

    eventQueue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);

    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());

    Paddle paddle1 = { 20, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, 0 };
    Paddle paddle2 = { SCREEN_WIDTH - PADDLE_WIDTH - 20, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, 0 };
    Ball ball = { SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2, BALL_SPEED, BALL_SPEED };

    bool running = true;
    bool keys[ALLEGRO_KEY_MAX] = { false };

    al_start_timer(timer);

    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(eventQueue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        } else if (ev.type == ALLEGRO_EVENT_TIMER) {
            movePaddle(paddle1, keys[ALLEGRO_KEY_W], keys[ALLEGRO_KEY_S]);
            movePaddle(paddle2, keys[ALLEGRO_KEY_UP], keys[ALLEGRO_KEY_DOWN]);
            moveBall(ball);

            // Collision with paddles
            if (ball.x <= paddle1.x + PADDLE_WIDTH && ball.y + BALL_SIZE >= paddle1.y && ball.y <= paddle1.y + PADDLE_HEIGHT) {
                ball.dx = BALL_SPEED;
            } else if (ball.x + BALL_SIZE >= paddle2.x && ball.y + BALL_SIZE >= paddle2.y && ball.y <= paddle2.y + PADDLE_HEIGHT) {
                ball.dx = -BALL_SPEED;
            }

            // Collision with walls
            if (ball.x < 0 || ball.x + BALL_SIZE > SCREEN_WIDTH) {
                ball.dx = -ball.dx;
            }

            al_clear_to_color(al_map_rgb(0, 0, 0));
            drawPaddle(paddle1);
            drawPaddle(paddle2);
            drawBall(ball);
            al_flip_display();
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            keys[ev.keyboard.keycode] = true;
        } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            keys[ev.keyboard.keycode] = false;
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    al_destroy_timer(timer);

    return 0;
}
