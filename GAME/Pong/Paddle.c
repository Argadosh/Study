#include "raylib.h"
#include "Paddle.h"

#define INDENT 15
#define WIDTH_PADDLE 10
#define HEIGRH_PADDLE 100
#define SPEED_PADDLE 500

void InitLeftPaddle(Paddle* paddle) {
	paddle->x = INDENT;
	paddle->y = GetScreenHeight() / 2.0f;
	paddle->width = WIDTH_PADDLE;
	paddle->height = HEIGRH_PADDLE;
	paddle->speed = SPEED_PADDLE;
}

void InitRightPaddle(Paddle* paddle) {
	paddle->x = GetScreenWidth() - INDENT;
	paddle->y = GetScreenHeight() / 2.0f;
	paddle->width = WIDTH_PADDLE;
	paddle->height = HEIGRH_PADDLE;
	paddle->speed = SPEED_PADDLE;
}

void DrawPaddle(Paddle* paddle) {
	DrawRectangle(paddle->x - paddle->width / 2.0f, paddle->y - paddle->height / 2.0f, paddle->width, paddle->height, RAYWHITE);
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
