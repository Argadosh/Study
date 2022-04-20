#include "Circle.h"
#include "raylib.h"

void InitCircle(Ball* ball) {
	ball->x = GetScreenWidth() / 2.0f;
	ball->y = GetScreenHeight() / 2.0f;
	ball->radius = 5;
	ball->speedX = 300;
	ball->speedY = 300;
}

void BallMove(Ball* ball) {
	ball->x += ball->speedX * GetFrameTime();
	ball->y += ball->speedY * GetFrameTime();

	if (ball->y < 0) {
		ball->y = 0;
		ball->speedY *= -1;
	}
	if (ball->y > GetScreenHeight()) {
		ball->y = GetScreenHeight();
		ball->speedY *= -1;
	}

}

void DrawBall(Ball* ball) {
	DrawCircle((int)ball->x, (int)ball->y, ball->radius, RAYWHITE);
}