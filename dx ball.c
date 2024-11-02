#include <stdio.h>
#include <conio.h>   // For getch()
#include <windows.h> // For Sleep()

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 6
#define MAX_LIVES 3

int ball_x, ball_y;
int ball_dx = 1, ball_dy = 1;
int paddle_x = WIDTH / 2 - PADDLE_WIDTH / 2;
int score = 0;
int lives = MAX_LIVES;
char bricks[HEIGHT / 2][WIDTH];

// Function to initialize bricks in structured rows
void init_bricks() {
    for (int i = 0; i < HEIGHT / 2; i++)
    {

    }
}
