#include "../../FrameWork/KeyInput/KeyInput.h"
#include "ResultScene.h"


/*-------------------------------------
コンストラクタ

引数	： Gameクラスのポインタ
-------------------------------------*/
ResultScene::ResultScene(Game* g)
{
	game = g;
}

/*-------------------------------------
デストラクタ
-------------------------------------*/
ResultScene::~ResultScene()
{

}

/*-------------------------------------
初期化
引数	：
戻り値	：
-------------------------------------*/
void ResultScene::Initialize(void)
{
	// タイマー
	resultSceneTimer = RESULT_SCENE_FADE_TIME;

	// 状態の保存
	ResultSceneState = eSCENE_STATE_FADE_IN;

	// キー入力催促文字の点滅用タイマー
	resultInfoTimer = 0;

	// キー入力催促文字の表示フラグ
	resultInfoFlag = TRUE;

}

/*-------------------------------------
更新
引数	：
戻り値	：
-------------------------------------*/
void ResultScene::Update(void)
{
	switch (ResultSceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// タイマーを進める
			resultSceneTimer--;

			// 次のステートに移る
			if (resultSceneTimer <= 0)
			{
				ResultSceneState = eSCENE_STATE_WAIT_KEY;
				resultSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// タイマーを進める
			resultInfoTimer++;

			// キーが押されたら次の状態へ
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				ResultSceneState = eSCENE_STATE_FADE_OUT;
			}

			// フラグの切り替え
			if (resultInfoTimer > RESULTSCENE_INFO_BINK_INTERVAL)
			{
				resultInfoFlag = !resultInfoFlag;

				resultInfoTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// タイマーを進める
			resultSceneTimer++;

			// 次のステートに移る
			if (resultSceneTimer >= RESULT_SCENE_FADE_TIME)
			{
				// プレイシーンへ
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
void ResultScene::Render(void)
{

	// キー入力催促の表示
	if (resultInfoFlag == TRUE)
	{
		DrawFormatString(
			RESULTSCENE_INFO_POS_X,
			RESULTSCENE_INFO_POS_Y,
			GetColor(255, 255, 255),
			"Please Space Key"
		);
	}

	DrawFormatString(100, 100, COLOR_WHITE, "リザルトシーン");

	// 黒フィルタの表示
	float fa = (float)resultSceneTimer / (float)RESULT_SCENE_FADE_TIME;		// タイマーの情報を元に0.0～1.0の幅に収める
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
終了
引数	：
戻り値	：
-------------------------------------*/
void ResultScene::Finalize(void)
{

}
