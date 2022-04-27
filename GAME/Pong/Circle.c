#include "Circle.h"
#include "Paddle.h"
#include "raylib.h"
#include "stdlib.h"

#define LEFT_WINNER_TEXT "LEFT PLAYER WIN"
#define RIGHT_WINNER_TEXT "RIGHT PLAYER WIN"

void InitCircle(Ball* ball) {
	int RandomValueX = 0;
	while (RandomValueX == 0) {
		RandomValueX = GetRandomValue(-1, 1);
	}
	int RandomValueY = 0;
	while (RandomValueY == 0) {
		RandomValueY = GetRandomValue(-1, 1);
	}
	ball->x = GetScreenWidth() / 2.0f;
	ball->y = GetScreenHeight() / 2.0f;
	ball->radius = 5;
	ball->speedX = GetRandomValue(250, 400) * RandomValueX;
	ball->speedY = GetRandomValue(250, 400) * RandomValueY;
}

void BallMove(Ball* ball, Paddle* Leftpaddle, Paddle* Rightpaddle) {
	ball->x += ball->speedX * GetFrameTime();
	ball->y += ball->speedY * GetFrameTime();

	if (ball->y - ball->radius < 0) {
		ball->speedY *= -1;
	}
	if (ball->y + ball->radius > GetScreenHeight()) {
		ball->speedY *= -1;
	}
	if (CheckCollisionCircleRec((Vector2){ball->x, ball->y}, ball->radius, (Rectangle){Leftpaddle->x - Leftpaddle->width / 2, Leftpaddle->y - Leftpaddle->height / 2, Leftpaddle->width, Leftpaddle->height})) {
		ball->speedX *= -1.1;
		Leftpaddle->speed *= 1.1;
	}
	if (CheckCollisionCircleRec((Vector2){ball->x, ball->y}, ball->radius, (Rectangle){Rightpaddle->x - Rightpaddle->width / 2, Rightpaddle->y - Rightpaddle->height / 2, Rightpaddle->width, Rightpaddle->height})) {
		ball->speedX *= -1.1;
		Rightpaddle->speed *= 1.1;
	}
	
}

void EndGame(Ball* ball, const char* WinnerText) {

	if (ball->x < 0) {
		WinnerText = RIGHT_WINNER_TEXT;
	}

	if (ball->x > GetScreenWidth()) {
		WinnerText = LEFT_WINNER_TEXT;
	}

	if (WinnerText) {
		int textwidth = MeasureText(WinnerText, 60);
		DrawText(WinnerText, GetScreenWidth() / 2 - textwidth / 2, GetScreenHeight() / 2 - 30, 60, WHITE);
		WinnerText = NULL;
	}
}

void DrawBall(Ball* ball) {
	DrawCircle((int)ball->x, (int)ball->y, ball->radius, RAYWHITE);
}