#include "../../FrameWork/KeyInput/KeyInput.h"
#include "TitleScene.h"


/*-------------------------------------
コンストラクタ

引数	： Gameクラスのポインタ
-------------------------------------*/
TitleScene::TitleScene(Game* g)
{
	game = g;
}

/*-------------------------------------
デストラクタ
-------------------------------------*/
TitleScene::~TitleScene()
{

}

/*-------------------------------------
初期化
引数	：
戻り値	：
-------------------------------------*/
void TitleScene::Initialize(void)
{
	// タイトルテクスチャの読み込み
	titleTexture.handle = LoadGraph("Resources/Textures/Xevious_UI_title.png");

	// 座標の設定
	titleTexture.pos.x = TITLE_SCENE_TITLE_POS_X;
	titleTexture.pos.y = TITLE_SCENE_TITLE_POS_Y;

	// 切り取り位置の設定
	titleTexture.rectSt.x = 0.0f;
	titleTexture.rectSt.y = 0.0f;
	titleTexture.rectEd.x = TITLE_SCENE_TITLE_SIZE_X;
	titleTexture.rectEd.y = TITLE_SCENE_TITLE_SIZE_Y;

	// スケール設定
	titleTexture.scale = 2.0;

	// 角度の設定
	titleTexture.rot = 0.0;

	// 透明度の設定
	titleTexture.alpha = 1.0f;

	// タイマー
	titleSceneTimer = TITLE_SCENE_FADE_TIME;

	// 状態の保存
	TitleSceneState = eSCENE_STATE_FADE_IN;

	// キー入力催促文字の点滅用タイマー
	titleInfoTimer = 0;

	// キー入力催促文字の表示フラグ
	titleInfoFlag = TRUE;


}

/*-------------------------------------
更新
引数	：
戻り値	：
-------------------------------------*/
void TitleScene::Update(void)
{
	switch (TitleSceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// タイマーを進める
			titleSceneTimer--;

			// 次のステートに移る
			if (titleSceneTimer <= 0)
			{
				TitleSceneState = eSCENE_STATE_WAIT_KEY;
				titleSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// タイマーを進める
			titleInfoTimer++;

			// キーが押されたら次の状態へ
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				TitleSceneState = eSCENE_STATE_FADE_OUT;
			}

			// フラグの切り替え
			if (titleInfoTimer > TITLESCENE_INFO_BINK_INTERVAL)
			{
				titleInfoFlag = !titleInfoFlag;

				titleInfoTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// タイマーを進める
			titleSceneTimer++;

			// 次のステートに移る
			if (titleSceneTimer >= TITLE_SCENE_FADE_TIME)
			{
				// プレイシーンへ
				game->RequestScene(SCENE_PLAY);
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
void TitleScene::Render(void)
{
	// タイトルの表示
	DrawSprite(titleTexture);

	// キー入力催促の表示
	if (titleInfoFlag == TRUE)
	{
		DrawFormatString(
			TITLESCENE_INFO_POS_X,
			TITLESCENE_INFO_POS_Y,
			GetColor(255, 255, 255),
			"Please Space Key"
		);
	}

	// 黒フィルタの表示
	float fa = (float)titleSceneTimer / (float)TITLE_SCENE_FADE_TIME;		// タイマーの情報を元に0.0～1.0の幅に収める
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
終了
引数	：
戻り値	：
-------------------------------------*/
void TitleScene::Finalize(void)
{
	DeleteGraph(titleTexture.handle);
}
