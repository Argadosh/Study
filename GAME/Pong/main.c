#include "raylib.h"
#include "Circle.h"
#include "Paddle.h"

int main() {

	const int ScreenWidth = 1000;
	const int ScreenHeight = 600;

	InitWindow(ScreenWidth, ScreenHeight, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	Ball ball;
	InitCircle(&ball);
	Paddle LeftPaddle;
	InitLeftPaddle(&LeftPaddle);
	Paddle RightPaddle;
	InitRightPaddle(&RightPaddle);
	const char* WinnerText = NULL;
	
	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);
		EndGame(&ball, WinnerText);
		if (IsKeyPressed(KEY_SPACE)) {
			InitCircle(&ball);
			InitLeftPaddle(&LeftPaddle);
			InitRightPaddle(&RightPaddle);
		}
		DrawFPS(ScreenWidth / 2 - 50, 0);
		BallMove(&ball, &LeftPaddle, &RightPaddle);
		MoveLeftPaddle(&LeftPaddle);
		MoveRigthPaddle(&RightPaddle);
		DrawBall(&ball);
		DrawPaddle(&LeftPaddle);
		DrawPaddle(&RightPaddle);
		EndDrawing();

	}

	return 0;
}