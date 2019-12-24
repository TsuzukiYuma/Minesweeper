#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// 定数----------------------------------------------

// キー入力催促の文字位置
const int RESULTSCENE_INFO_POS_X = (SCREEN_CENTER_X - 75);
const int RESULTSCENE_INFO_POS_Y = (SCREEN_CENTER_Y + 100);

// キー入力催促の文字点滅間隔
const int RESULTSCENE_INFO_BINK_INTERVAL = 40;

// フェード時間
const int RESULT_SCENE_FADE_TIME = 30;


class ResultScene:public GameBase
{
	// データメンバの宣言
	Game* game;

	// タイマー
	int resultSceneTimer;

	// 状態の保存
	eSCENE_STATE ResultSceneState;

	// キー入力催促文字の点滅用タイマー
	int resultInfoTimer;

	// キー入力催促文字の表示フラグ
	int resultInfoFlag;


	// メンバ関数の宣言
public:
	// コンストラクタ
	ResultScene(Game* g);

	// デストラクタ
	~ResultScene();

public:
	// 操作
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
