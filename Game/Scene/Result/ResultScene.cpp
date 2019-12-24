#include "../../FrameWork/KeyInput/KeyInput.h"
#include "ResultScene.h"


/*-------------------------------------
�R���X�g���N�^

����	�F Game�N���X�̃|�C���^
-------------------------------------*/
ResultScene::ResultScene(Game* g)
{
	game = g;
}

/*-------------------------------------
�f�X�g���N�^
-------------------------------------*/
ResultScene::~ResultScene()
{

}

/*-------------------------------------
������
����	�F
�߂�l	�F
-------------------------------------*/
void ResultScene::Initialize(void)
{
	// �^�C�}�[
	resultSceneTimer = RESULT_SCENE_FADE_TIME;

	// ��Ԃ̕ۑ�
	ResultSceneState = eSCENE_STATE_FADE_IN;

	// �L�[���͍Ñ������̓_�ŗp�^�C�}�[
	resultInfoTimer = 0;

	// �L�[���͍Ñ������̕\���t���O
	resultInfoFlag = TRUE;

}

/*-------------------------------------
�X�V
����	�F
�߂�l	�F
-------------------------------------*/
void ResultScene::Update(void)
{
	switch (ResultSceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// �^�C�}�[��i�߂�
			resultSceneTimer--;

			// ���̃X�e�[�g�Ɉڂ�
			if (resultSceneTimer <= 0)
			{
				ResultSceneState = eSCENE_STATE_WAIT_KEY;
				resultSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// �^�C�}�[��i�߂�
			resultInfoTimer++;

			// �L�[�������ꂽ�玟�̏�Ԃ�
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				ResultSceneState = eSCENE_STATE_FADE_OUT;
			}

			// �t���O�̐؂�ւ�
			if (resultInfoTimer > RESULTSCENE_INFO_BINK_INTERVAL)
			{
				resultInfoFlag = !resultInfoFlag;

				resultInfoTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// �^�C�}�[��i�߂�
			resultSceneTimer++;

			// ���̃X�e�[�g�Ɉڂ�
			if (resultSceneTimer >= RESULT_SCENE_FADE_TIME)
			{
				// �v���C�V�[����
				game->RequestScene(SCENE_TITLE);
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
void ResultScene::Render(void)
{

	// �L�[���͍Ñ��̕\��
	if (resultInfoFlag == TRUE)
	{
		DrawFormatString(
			RESULTSCENE_INFO_POS_X,
			RESULTSCENE_INFO_POS_Y,
			GetColor(255, 255, 255),
			"Please Space Key"
		);
	}

	DrawFormatString(100, 100, COLOR_WHITE, "���U���g�V�[��");

	// ���t�B���^�̕\��
	float fa = (float)resultSceneTimer / (float)RESULT_SCENE_FADE_TIME;		// �^�C�}�[�̏�������0.0�`1.0�̕��Ɏ��߂�
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
�I��
����	�F
�߂�l	�F
-------------------------------------*/
void ResultScene::Finalize(void)
{

}
