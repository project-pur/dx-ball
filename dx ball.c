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

for (int i = 0; i < HEIGHT / 2; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Create rows of bricks with gaps
            if (i % 2 == 0 && j % 4 != 0) {
                bricks[i][j] = '#';
            } else {
                bricks[i][j] = ' ';
            }
        }
    }
}

// Function to draw the game board
void draw() {
    system("cls");

    // Draw bricks
    for (int i = 0; i < HEIGHT / 2; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", bricks[i][j]);
        }
        printf("\n");
    }

