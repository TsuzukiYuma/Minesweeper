#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// 定数----------------------------------------------

// タイトル画像サイズ
const int TITLE_SCENE_TITLE_SIZE_X = 160;
const int TITLE_SCENE_TITLE_SIZE_Y = 56;

// タイトルの表示位置
const int TITLE_SCENE_TITLE_POS_X = SCREEN_CENTER_X;
const int TITLE_SCENE_TITLE_POS_Y = (SCREEN_CENTER_Y - 50);

// キー入力催促の文字位置
const int TITLESCENE_INFO_POS_X = (SCREEN_CENTER_X - 75);
const int TITLESCENE_INFO_POS_Y = (SCREEN_CENTER_Y + 100);

// キー入力催促の文字点滅間隔
const int TITLESCENE_INFO_BINK_INTERVAL = 40;

// フェード時間
const int TITLE_SCENE_FADE_TIME = 30;

class TitleScene:public GameBase
{
	// データメンバの宣言
	Game* game;


	// 画像情報
	TextureData titleTexture;

	// タイマー
	int titleSceneTimer;

	// 状態の保存
	eSCENE_STATE TitleSceneState;

	// キー入力催促文字の点滅用タイマー
	int titleInfoTimer;

	// キー入力催促文字の表示フラグ
	int titleInfoFlag;


	// メンバ関数の宣言
public:
	// コンストラクタ
	TitleScene(Game* g);

	// デストラクタ
	~TitleScene();

public:
	// 操作
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
