#pragma once

#include "../Math/Math.h"

// �摜�̕`��f�[�^
struct TextureData
{
	// ���W
	Vec2D pos;

	// �؂���̊J�n�ʒu
	Vec2D rectSt;

	// �؂���̏I���ʒu
	Vec2D rectEd;

	// �g�嗦
	double scale;

	// �p�x�iradian�j
	double rot;
	
	// �����x
	float alpha;

	// �摜�n���h��
	int handle;
};

typedef struct TextureData TextureData;


// �摜�̕\��
void DrawSprite(TextureData txData);

// �l�p�`�̕`��(�A���t�@�t��)
void DrawBoxAAa(float x1, float y1, float x2, float y2, unsigned int cl, float a);