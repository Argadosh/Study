#pragma once

typedef struct Ball {

	float x, y;
	float speedX, speedY;
	float radius;

} Ball;

void InitCircle(Ball* );

void BallMove(Ball* );

void DrawBall(Ball* );
