#include "../../FrameWork/KeyInput/KeyInput.h"
#include "LogoScene.h"

/*-------------------------------------
コンストラクタ

引数	： Gameクラスのポインタ
-------------------------------------*/
LogoScene::LogoScene(Game* g)
{
	game = g;
}

/*-------------------------------------
デストラクタ
-------------------------------------*/
LogoScene::~LogoScene()
{

}

/*-------------------------------------
初期化
引数	：
戻り値	：
-------------------------------------*/
void LogoScene::Initialize(void)
{

	// ロゴテクスチャの読み込み
	logTexture.handle = LoadGraph("Resources/Textures/TridentLogo.png");

	// 座標の設定
	logTexture.pos.x = SCREEN_CENTER_X;
	logTexture.pos.y = SCREEN_CENTER_Y;

	// 切り取り位置の設定
	logTexture.rectSt.x = 0.0f;
	logTexture.rectSt.y = 0.0f;
	logTexture.rectEd.x = LOGO_SCENE_LOGO_SIZE_X;
	logTexture.rectEd.y = LOGO_SCENE_LOGO_SIZE_Y;

	// スケール設定
	logTexture.scale = 1.0;

	// 角度の設定
	logTexture.rot = 0.0;

	// 透明度の設定
	logTexture.alpha = 1.0f;

	// タイマー
	logoSceneTimer = LOGO_SCENE_FADE_TIME;
	// 表示タイマー
	logoViewTimer = LOGO_SCENE_VIEW_TIME;

	// 状態の保存
	LogoSceneState = eSCENE_STATE_FADE_IN;


}

/*-------------------------------------
更新
引数	：
戻り値	：
-------------------------------------*/
void LogoScene::Update(void)
{
	switch (LogoSceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// タイマーを進める
			logoSceneTimer--;

			// 次のステートに移る
			if (logoSceneTimer <= 0)
			{
				LogoSceneState = eSCENE_STATE_WAIT_KEY;
				logoSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// キーが押されたら次の状態へ
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				LogoSceneState = eSCENE_STATE_FADE_OUT;
			}

			// タイマーでもシーンを進める
			logoViewTimer--;

			// 次のステートに移る
			if (logoViewTimer <= 0)
			{
				LogoSceneState = eSCENE_STATE_FADE_OUT;
			}


			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// タイマーを進める
			logoSceneTimer++;

			// 次のステートに移る
			if (logoSceneTimer >= LOGO_SCENE_FADE_TIME)
			{
				// タイトルシーンへ
				game->RequestScene(SCENE_TITLE);
			}

			break;
		}
	}
}

/*-------------------------------------
描画
引数	：
戻り値	：
-------------------------------------*/
void LogoScene::Render(void)
{
	// ロゴの表示
	DrawSprite(logTexture);

	// 黒フィルタの表示
	float fa = (float)logoSceneTimer / (float)LOGO_SCENE_FADE_TIME;		// タイマーの情報を元に0.0～1.0の幅に収める
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
終了
引数	：
戻り値	：
-------------------------------------*/
void LogoScene::Finalize(void)
{
	DeleteGraph(logTexture.handle);
}

