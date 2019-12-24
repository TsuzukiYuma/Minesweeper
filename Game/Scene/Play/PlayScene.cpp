#include "../../FrameWork/KeyInput/KeyInput.h"
#include "PlayScene.h"


/*-------------------------------------
コンストラクタ

引数	： Gameクラスのポインタ
-------------------------------------*/
PlayScene::PlayScene(Game* g)
{
	game = g;
}

/*-------------------------------------
デストラクタ
-------------------------------------*/
PlayScene::~PlayScene()
{

}

/*-------------------------------------
初期化
引数	：
戻り値	：
-------------------------------------*/
void PlayScene::Initialize(void)
{
	// タイマー
	playSceneTimer = PLAY_SCENE_FADE_TIME;

	// 状態の保存
	PlaySceneState = eSCENE_STATE_FADE_IN;

	// キー入力催促文字の点滅用タイマー
	playInfoTimer = 0;

	// キー入力催促文字の表示フラグ
	playInfoFlag = TRUE;

}

/*-------------------------------------
更新
引数	：
戻り値	：
-------------------------------------*/
void PlayScene::Update(void)
{
	switch (PlaySceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// タイマーを進める
			playSceneTimer--;

			// 次のステートに移る
			if (playSceneTimer <= 0)
			{
				PlaySceneState = eSCENE_STATE_WAIT_KEY;
				playSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// タイマーを進める
			playInfoTimer++;

			// キーが押されたら次の状態へ
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				PlaySceneState = eSCENE_STATE_FADE_OUT;
			}

			// フラグの切り替え
			if (playInfoTimer > PLAYSCENE_INFO_BINK_INTERVAL)
			{
				playInfoFlag = !playInfoFlag;

				playInfoTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// タイマーを進める
			playSceneTimer++;

			// 次のステートに移る
			if (playSceneTimer >= PLAY_SCENE_FADE_TIME)
			{
				// プレイシーンへ
				game->RequestScene(SCENE_RESULT);
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
void PlayScene::Render(void)
{
	// キー入力催促の表示
	if (playInfoFlag == TRUE)
	{
		DrawFormatString(
			PLAYSCENE_INFO_POS_X,
			PLAYSCENE_INFO_POS_Y,
			COLOR_WHITE,
			"Please Space Key"
		);
	}

	DrawFormatString(100, 100, COLOR_WHITE,	"プレイシーン");

	// 黒フィルタの表示
	float fa = (float)playSceneTimer / (float)PLAY_SCENE_FADE_TIME;		// タイマーの情報を元に0.0～1.0の幅に収める
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
終了
引数	：
戻り値	：
-------------------------------------*/
void PlayScene::Finalize(void)
{

}
