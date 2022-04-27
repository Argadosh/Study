#pragma once
#include "Paddle.h"

typedef struct Ball {

	float x, y;
	float speedX, speedY;
	float radius;

} Ball;

void InitCircle(Ball*);

void BallMove(Ball*, Paddle*, Paddle*);

void DrawBall(Ball*);

void EndGame(Ball*, const char*);