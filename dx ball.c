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

// Draw empty space above paddle and ball
    for (int i = HEIGHT / 2; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == ball_y && j == ball_x) {
                printf("O"); // Ball
            } else if (i == HEIGHT - 1 && j >= paddle_x && j < paddle_x + PADDLE_WIDTH) {
                printf("="); // Paddle
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Display score and lives
    printf("Score: %d    Lives: %d\n", score, lives);
}

// Function to update the game state
void update() {
    // Update ball position
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Check for collision with walls
    if (ball_x <= 0 || ball_x >= WIDTH - 1)
        ball_dx *= -1;

    if (ball_y <= 0)
        ball_dy *= -1;

    // Check for collision with paddle
    if (ball_y == HEIGHT - 2 && ball_x >= paddle_x && ball_x < paddle_x + PADDLE_WIDTH) {
        ball_dy *= -1;
    }
    // Check for collision with bricks
    if (ball_y < HEIGHT / 2 && bricks[ball_y][ball_x] == '#') {
        bricks[ball_y][ball_x] = ' ';
        score += 10;
        ball_dy *= -1;
    }
    // Check if ball falls below paddle (lose a life)
    if (ball_y >= HEIGHT - 1) {
        lives--;
        if (lives > 0) {
            // Reset ball and paddle positions
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            paddle_x = WIDTH / 2 - PADDLE_WIDTH / 2;
            ball_dx = 1;
            ball_dy = 1;
        } else {
            printf("Game Over! Your final score is: %d\n", score);
            printf("Press any key to exit...\n");
            _getch(); // Wait for user input before exiting
            exit(0);
        }
    }
}
// Function to control the paddle
void input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'a' && paddle_x > 0)
            paddle_x--;
        else if (ch == 'd' && paddle_x + PADDLE_WIDTH < WIDTH)
            paddle_x++;
    }
}



