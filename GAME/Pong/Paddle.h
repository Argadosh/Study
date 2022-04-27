#pragma once

typedef struct Paddle {

	float x, y;
	float width, height;
	float speed;

} Paddle;

void InitLeftPaddle(Paddle*);

void InitRightPaddle(Paddle*);

void DrawPaddle(Paddle*);

void MoveLeftPaddle(Paddle*);

void MoveRigthPaddle(Paddle*);
