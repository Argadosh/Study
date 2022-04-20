#include "raylib.h"
#include "Circle.h"

int main() {

	const int ScreenWidth = 800;
	const int ScreenHeight = 450;

	InitWindow(ScreenWidth, ScreenHeight, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);


	Ball ball;
	InitCircle(&ball);
	
	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(ScreenWidth / 2 - 50, 0);
		BallMove(&ball);
		DrawBall(&ball);
		DrawRectangle(10, GetScreenHeight() / 2 - 50, 10, 100, RAYWHITE);
		DrawRectangle(GetScreenWidth() - 10 - 10, GetScreenHeight() / 2 - 50, 10, 100, RAYWHITE);
		EndDrawing();

	}

	return 0;
}