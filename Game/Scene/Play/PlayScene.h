#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// 定数----------------------------------------------

// キー入力催促の文字位置
const int PLAYSCENE_INFO_POS_X = (SCREEN_CENTER_X - 75);
const int PLAYSCENE_INFO_POS_Y = (SCREEN_CENTER_Y + 100);

// キー入力催促の文字点滅間隔
const int PLAYSCENE_INFO_BINK_INTERVAL = 40;

// フェード時間
const int PLAY_SCENE_FADE_TIME = 30;


class PlayScene:public GameBase
{
	// データメンバの宣言
	Game* game;

	// タイマー
	int playSceneTimer;

	// 状態の保存
	eSCENE_STATE PlaySceneState;

	// キー入力催促文字の点滅用タイマー
	int playInfoTimer;

	// キー入力催促文字の表示フラグ
	int playInfoFlag;


	// メンバ関数の宣言
public:
	// コンストラクタ
	PlayScene(Game* g);

	// デストラクタ
	~PlayScene();

public:
	// 操作
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
