#include "../../FrameWork/KeyInput/KeyInput.h"
#include "PlayScene.h"


/*-------------------------------------
�R���X�g���N�^

����	�F Game�N���X�̃|�C���^
-------------------------------------*/
PlayScene::PlayScene(Game* g)
{
	game = g;
}

/*-------------------------------------
�f�X�g���N�^
-------------------------------------*/
PlayScene::~PlayScene()
{

}

/*-------------------------------------
������
����	�F
�߂�l	�F
-------------------------------------*/
void PlayScene::Initialize(void)
{
	// �^�C�}�[
	playSceneTimer = PLAY_SCENE_FADE_TIME;

	// ��Ԃ̕ۑ�
	PlaySceneState = eSCENE_STATE_FADE_IN;

	// �L�[���͍Ñ������̓_�ŗp�^�C�}�[
	playInfoTimer = 0;

	// �L�[���͍Ñ������̕\���t���O
	playInfoFlag = TRUE;

}

/*-------------------------------------
�X�V
����	�F
�߂�l	�F
-------------------------------------*/
void PlayScene::Update(void)
{
	switch (PlaySceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// �^�C�}�[��i�߂�
			playSceneTimer--;

			// ���̃X�e�[�g�Ɉڂ�
			if (playSceneTimer <= 0)
			{
				PlaySceneState = eSCENE_STATE_WAIT_KEY;
				playSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// �^�C�}�[��i�߂�
			playInfoTimer++;

			// �L�[�������ꂽ�玟�̏�Ԃ�
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				PlaySceneState = eSCENE_STATE_FADE_OUT;
			}

			// �t���O�̐؂�ւ�
			if (playInfoTimer > PLAYSCENE_INFO_BINK_INTERVAL)
			{
				playInfoFlag = !playInfoFlag;

				playInfoTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// �^�C�}�[��i�߂�
			playSceneTimer++;

			// ���̃X�e�[�g�Ɉڂ�
			if (playSceneTimer >= PLAY_SCENE_FADE_TIME)
			{
				// �v���C�V�[����
				game->RequestScene(SCENE_RESULT);
			}

			break;
		}
	}
}

/*-------------------------------------
�`��
����	�F
�߂�l	�F
-------------------------------------*/
void PlayScene::Render(void)
{
	// �L�[���͍Ñ��̕\��
	if (playInfoFlag == TRUE)
	{
		DrawFormatString(
			PLAYSCENE_INFO_POS_X,
			PLAYSCENE_INFO_POS_Y,
			COLOR_WHITE,
			"Please Space Key"
		);
	}

	DrawFormatString(100, 100, COLOR_WHITE,	"�v���C�V�[��");

	// ���t�B���^�̕\��
	float fa = (float)playSceneTimer / (float)PLAY_SCENE_FADE_TIME;		// �^�C�}�[�̏�������0.0�`1.0�̕��Ɏ��߂�
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
�I��
����	�F
�߂�l	�F
-------------------------------------*/
void PlayScene::Finalize(void)
{

}
