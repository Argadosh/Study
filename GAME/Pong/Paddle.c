#include "raylib.h"
#include "Paddle.h"

#define INDENT 10
#define WIDTH_PADDLE 10
#define HEIGRH_PADDLE 100
#define SPEED_PADDLE 500

void InitLeftPaddle(Paddle* paddle) {
	paddle->x = INDENT;
	paddle->y = GetScreenHeight() / 2;
	paddle->width = WIDTH_PADDLE;
	paddle->height = HEIGRH_PADDLE;
	paddle->speed = SPEED_PADDLE;
}

void InitRigthPaddle(Paddle* paddle) {
	paddle->x = GetScreenWidth() - INDENT;
	paddle->y = GetScreenHeight() / 2;
	paddle->width = WIDTH_PADDLE;
	paddle->height = HEIGRH_PADDLE;
	paddle->speed = SPEED_PADDLE;
}

void DrawLeftPaddle(Paddle* paddle) {
	DrawRectangle(paddle->x - paddle->width / 2, paddle->y - paddle->height / 2, paddle->width, paddle->height, RAYWHITE);
}

void DrawRigthPaddle(Paddle* paddle) {
	DrawRectangle(paddle->x - paddle->width / 2, paddle->y - paddle->height / 2, paddle->width, paddle->height, RAYWHITE);
}

void MoveLeftPaddle(Paddle* paddle) {
	if (IsKeyDown(KEY_S)) {
		paddle->y += paddle->speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_W)) {
		paddle->y -= paddle->speed * GetFrameTime();
	}
}

void MoveRigthPaddle(Paddle* paddle) {
	if (IsKeyDown(KEY_DOWN)) {
		paddle->y += paddle->speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_UP)) {
		paddle->y -= paddle->speed * GetFrameTime();
	}
}