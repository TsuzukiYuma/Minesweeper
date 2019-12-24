#include "Graph.h"

/*-------------------------------------
�摜�̕\��
����	�F�e�N�X�`���̏��(TextureData txData)
�߂�l	�F
-------------------------------------*/
void DrawSprite(TextureData txData)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(txData.alpha * 255));
	DrawRectRotaGraphF(
		txData.pos.x,			// ���W
		txData.pos.y,
		(int)txData.rectSt.x,	// �؂���J�n�ʒu
		(int)txData.rectSt.y,
		(int)(txData.rectEd.x - txData.rectSt.x),	// �؂���T�C�Y
		(int)(txData.rectEd.y - txData.rectSt.y),
		txData.scale,			// �摜�̊g�嗦
		txData.rot * PI / 180,	// �p�x�iradian�ʓx�@�j
		txData.handle,			// �n���h��
		TRUE					// �����x�̗L����
	);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/*-------------------------------------
�l�p�`�̕`��(�A���t�@�t��)
����	�Ffloat x1, float y1, float x2, float y2, unsigned int cl, float a
�߂�l	�F
-------------------------------------*/
void DrawBoxAAa(float x1, float y1, float x2, float y2, unsigned int cl, float a)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(a * 255));
	DrawBoxAA(x1, y1, x2, y2, cl, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}