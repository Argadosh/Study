#pragma once

typedef struct Paddle {

	float x, y;
	float width, height;
	float speed;

} Paddle;

void InitLeftPaddle(Paddle*);

void InitRigthPaddle(Paddle*);

void DrawLeftPaddle(Paddle*);

void DrawRigthPaddle(Paddle*);

void MoveLeftPaddle(Paddle*);

void MoveRigthPaddle(Paddle*);