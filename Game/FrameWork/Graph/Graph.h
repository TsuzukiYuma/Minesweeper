#pragma once

#include "../Math/Math.h"

// 画像の描画データ
struct TextureData
{
	// 座標
	Vec2D pos;

	// 切り取りの開始位置
	Vec2D rectSt;

	// 切り取りの終了位置
	Vec2D rectEd;

	// 拡大率
	double scale;

	// 角度（radian）
	double rot;
	
	// 透明度
	float alpha;

	// 画像ハンドル
	int handle;
};

typedef struct TextureData TextureData;


// 画像の表示
void DrawSprite(TextureData txData);

// 四角形の描画(アルファ付き)
void DrawBoxAAa(float x1, float y1, float x2, float y2, unsigned int cl, float a);