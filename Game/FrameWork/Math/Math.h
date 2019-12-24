#pragma once

// PI
#define PI		3.14159265358979323846

// 2D�x�N�g���̍\����
struct Vec2D
{
	float x;
	float y;
};

typedef struct Vec2D Vec2D;


// �x�N�g���̑����Z
void SumVec2D(Vec2D* a, Vec2D b);

// �x�N�g���̈����Z
void SubVec2D(Vec2D* a, Vec2D b);

// �x�N�g����L�΂�
void ScaleVec2D(Vec2D* pv, float s);

// �x�N�g���̒���
float LengthVec2D(Vec2D pv);

// �x�N�g���̐��K��
void NormalizeVec2D(Vec2D* pv);