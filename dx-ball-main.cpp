#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 10
#define BALL_RADIUS 10
#define BRICK_WIDTH 50
#define BRICK_HEIGHT 20
#define MAX_BRICKS_X 12
#define MAX_BRICKS_Y 6

// Game state variables
int paddleX, paddleY;
int ballX, ballY, ballDX, ballDY;
int score, lives, level;
int bricks[MAX_BRICKS_Y][MAX_BRICKS_X];