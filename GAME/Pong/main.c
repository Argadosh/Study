#include "raylib.h"

int main() {

	const int ScreenWidth = 800;
	const int ScreenHeight = 450;

	InitWindow(ScreenWidth, ScreenHeight, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(ScreenWidth / 2 - 50, 0);
		EndDrawing();

	}

	return 0;
}