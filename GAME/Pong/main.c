#include "raylib.h"
#include "Circle.h"
#include "Paddle.h"

int main() {

	const int ScreenWidth = 800;
	const int ScreenHeight = 450;

	InitWindow(ScreenWidth, ScreenHeight, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);


	Ball ball;
	InitCircle(&ball);
	Paddle LeftPaddle;
	InitLeftPaddle(&LeftPaddle);
	Paddle RigthPaddle;
	InitRigthPaddle(&RigthPaddle);
	
	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(ScreenWidth / 2 - 50, 0);
		BallMove(&ball);
		MoveLeftPaddle(&LeftPaddle);
		MoveRigthPaddle(&RigthPaddle);
		DrawBall(&ball);
		DrawLeftPaddle(&LeftPaddle);
		DrawRigthPaddle(&RigthPaddle);
		EndDrawing();

	}

	return 0;
}