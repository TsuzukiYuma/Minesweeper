#include "Graph.h"

/*-------------------------------------
画像の表示
引数	：テクスチャの情報(TextureData txData)
戻り値	：
-------------------------------------*/
void DrawSprite(TextureData txData)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(txData.alpha * 255));
	DrawRectRotaGraphF(
		txData.pos.x,			// 座標
		txData.pos.y,
		(int)txData.rectSt.x,	// 切り取り開始位置
		(int)txData.rectSt.y,
		(int)(txData.rectEd.x - txData.rectSt.x),	// 切り取りサイズ
		(int)(txData.rectEd.y - txData.rectSt.y),
		txData.scale,			// 画像の拡大率
		txData.rot * PI / 180,	// 角度（radian弧度法）
		txData.handle,			// ハンドル
		TRUE					// 透明度の有効化
	);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/*-------------------------------------
四角形の描画(アルファ付き)
引数	：float x1, float y1, float x2, float y2, unsigned int cl, float a
戻り値	：
-------------------------------------*/
void DrawBoxAAa(float x1, float y1, float x2, float y2, unsigned int cl, float a)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(a * 255));
	DrawBoxAA(x1, y1, x2, y2, cl, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}