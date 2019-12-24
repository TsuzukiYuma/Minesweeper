//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include <assert.h>
#include "FrameWork\KeyInput\KeyInput.h"
#include "Scene\Logo\LogoScene.h"
#include "Scene\Title\TitleScene.h"
#include "Scene\PLay\PlayScene.h"
#include "Scene\Result\ResultScene.h"


// 定数の定義 ==============================================================
#define START_SCENE (SCENE_LOGO)



// グローバル変数の定義 ====================================================


// 関数の宣言 ==============================================================





// 関数の定義 ==============================================================
// メンバ関数の定義 ========================================================
//------------------------------------------------------------------
//! @brief デフォルトコンストラクタ
//!
//! @param[in] なし
//------------------------------------------------------------------
Game::Game()
{

}



//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
Game::~Game()
{
	delete base;
}



/*-------------------------------------
ゲームの初期化処理
引数	：
戻り値	：
-------------------------------------*/
void Game::Initialize(void)
{

	activeScene = SCENE_NONE;
	nextScene = START_SCENE;


}



/*-------------------------------------
ゲームの更新処理
引数	：
戻り値	：
-------------------------------------*/
void Game::Update(void)
{
	// キー処理の更新
	KeyInputUpdate();

	// シーン変更が必要かどうかをチェック
	if (nextScene != SCENE_NONE)
	{
		if (activeScene != SCENE_NONE)
		{
			base->Finalize();
			delete base;
		}
		switch (nextScene)
		{
		case SCENE_LOGO:
			base = new LogoScene(this);
			break;
		case SCENE_TITLE:
			base = new TitleScene(this);
			break;
		case SCENE_PLAY:
			base = new PlayScene(this);
			break;
		case SCENE_RESULT:
			base = new ResultScene(this);
			break;
		default:
			assert(FALSE);
			break;
		}
		base->Initialize();
		activeScene = nextScene;
		nextScene = SCENE_NONE;
	}

	// 活動中のシーンを更新
	base->Update();
}



/*-------------------------------------
ゲームの描画処理
引数	：
戻り値	：
-------------------------------------*/
void Game::Render(void)
{
	// 活動中のシーンを描画
	base->Render();
}



/*-------------------------------------
ゲームの終了処理
引数	：
戻り値	：
-------------------------------------*/
void Game::Finalize(void)
{
	// 活動中のシーンの終了処理
	base->Finalize();

}

/*-------------------------------------
シーン変更の要求
        ※実際にはUpdate時に変更される
引数	：scene_id 変更したいシーンのID
戻り値	：
-------------------------------------*/
void Game::RequestScene(SceneID scene_id)
{
	nextScene = scene_id;
}




