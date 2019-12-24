#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// 定数----------------------------------------------

// ロゴ画像サイズ
const int LOGO_SCENE_LOGO_SIZE_X = 256;
const int LOGO_SCENE_LOGO_SIZE_Y = 256;

// フェード時間
const int LOGO_SCENE_FADE_TIME = 60;
// 表示時間
const int LOGO_SCENE_VIEW_TIME = 120;

class LogoScene:public GameBase
{
	// データメンバの宣言
	Game* game;

	// 画像情報
	TextureData logTexture;

	// タイマー
	int logoSceneTimer;
	// 表示タイマー
	int logoViewTimer;

	// 状態の保存
	eSCENE_STATE LogoSceneState;


	// メンバ関数の宣言
public:
	// コンストラクタ
	LogoScene(Game* g);

	// デストラクタ
	~LogoScene();

public:
	// 操作
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};

