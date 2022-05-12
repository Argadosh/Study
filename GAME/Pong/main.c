#include "raylib.h"
#include "Circle.h"
#include "Paddle.h"

int main() {

	const int ScreenWidth = 1000;
	const int ScreenHeight = 600;

	InitAudioDevice();
	InitWindow(ScreenWidth, ScreenHeight, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	Sound sound_collision_up_down = LoadSound("C:/Users/ARGADOSH/source/repos/GAME/lovi-myach.wav");
	SetSoundVolume(sound_collision_up_down, 0.2f);
	Sound sound_collision_rectangle = LoadSound("C:/Users/ARGADOSH/source/repos/GAME/otbivanie-myacha.wav");
	SetSoundVolume(sound_collision_rectangle, 0.1f);

	Ball ball;
	InitCircle(&ball);
	Paddle LeftPaddle;
	InitLeftPaddle(&LeftPaddle);
	Paddle RightPaddle;
	InitRightPaddle(&RightPaddle);
	char* WinnerText = NULL;
	
	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);
		EndGame(&ball, &WinnerText);
		if (IsKeyPressed(KEY_SPACE)) {
			InitCircle(&ball);
			InitLeftPaddle(&LeftPaddle);
			InitRightPaddle(&RightPaddle);
		}
		DrawFPS(ScreenWidth / 2 - 50, 0);
		BallMove(&ball, &LeftPaddle, &RightPaddle, sound_collision_up_down, sound_collision_rectangle);
		MoveLeftPaddle(&LeftPaddle);
		MoveRigthPaddle(&RightPaddle);
		DrawBall(&ball);
		DrawPaddle(&LeftPaddle);
		DrawPaddle(&RightPaddle);
		EndDrawing();

	}
	
	return 0;
}