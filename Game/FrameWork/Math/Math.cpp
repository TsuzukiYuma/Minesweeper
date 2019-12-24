#include <math.h>
#include "Math.h"

/*-------------------------------------
�x�N�g���̑����Z
����	�F�����x�N�g��(Vec2D* pa, Vec2D b)
�߂�l	�F
-------------------------------------*/
void SumVec2D(Vec2D* pa, Vec2D b)
{
	pa->x += b.x;
	pa->y += b.y;
}

/*-------------------------------------
�x�N�g���̈����Z
����	�F�����x�N�g��(Vec2D* pa, Vec2D b)
�߂�l	�F
-------------------------------------*/
void SubVec2D(Vec2D* pa, Vec2D b)
{
	pa->x -= b.x;
	pa->y -= b.y;
}

/*-------------------------------------
�x�N�g����L�΂�
����	�F�x�N�g���Ɣ{��(Vec2D* pv, float s)
�߂�l	�F
-------------------------------------*/
void ScaleVec2D(Vec2D* pv, float s)
{
	pv->x *= s;
	pv->y *= s;
}

/*-------------------------------------
�x�N�g���̒���
����	�F�������擾�������x�N�g��(Vec2D* pv)
�߂�l	�F����
-------------------------------------*/
float LengthVec2D(Vec2D pv)
{
	return sqrtf((pv.x * pv.x) + (pv.y * pv.y));
}

/*-------------------------------------
�x�N�g���̐��K��
����	�F���K���������x�N�g��(Vec2D* pv)
�߂�l	�F
-------------------------------------*/
void NormalizeVec2D(Vec2D* pv)
{
	float len = LengthVec2D(*pv);

	if (len == 0.0f)
	{
		return;
	}

	pv->x /= len;
	pv->y /= len;
}