#include "../../FrameWork/KeyInput/KeyInput.h"
#include "TitleScene.h"


/*-------------------------------------
�R���X�g���N�^

����	�F Game�N���X�̃|�C���^
-------------------------------------*/
TitleScene::TitleScene(Game* g)
{
	game = g;
}

/*-------------------------------------
�f�X�g���N�^
-------------------------------------*/
TitleScene::~TitleScene()
{

}

/*-------------------------------------
������
����	�F
�߂�l	�F
-------------------------------------*/
void TitleScene::Initialize(void)
{
	// �^�C�g���e�N�X�`���̓ǂݍ���
	titleTexture.handle = LoadGraph("Resources/Textures/Xevious_UI_title.png");

	// ���W�̐ݒ�
	titleTexture.pos.x = TITLE_SCENE_TITLE_POS_X;
	titleTexture.pos.y = TITLE_SCENE_TITLE_POS_Y;

	// �؂���ʒu�̐ݒ�
	titleTexture.rectSt.x = 0.0f;
	titleTexture.rectSt.y = 0.0f;
	titleTexture.rectEd.x = TITLE_SCENE_TITLE_SIZE_X;
	titleTexture.rectEd.y = TITLE_SCENE_TITLE_SIZE_Y;

	// �X�P�[���ݒ�
	titleTexture.scale = 2.0;

	// �p�x�̐ݒ�
	titleTexture.rot = 0.0;

	// �����x�̐ݒ�
	titleTexture.alpha = 1.0f;

	// �^�C�}�[
	titleSceneTimer = TITLE_SCENE_FADE_TIME;

	// ��Ԃ̕ۑ�
	TitleSceneState = eSCENE_STATE_FADE_IN;

	// �L�[���͍Ñ������̓_�ŗp�^�C�}�[
	titleInfoTimer = 0;

	// �L�[���͍Ñ������̕\���t���O
	titleInfoFlag = TRUE;


}

/*-------------------------------------
�X�V
����	�F
�߂�l	�F
-------------------------------------*/
void TitleScene::Update(void)
{
	switch (TitleSceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// �^�C�}�[��i�߂�
			titleSceneTimer--;

			// ���̃X�e�[�g�Ɉڂ�
			if (titleSceneTimer <= 0)
			{
				TitleSceneState = eSCENE_STATE_WAIT_KEY;
				titleSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// �^�C�}�[��i�߂�
			titleInfoTimer++;

			// �L�[�������ꂽ�玟�̏�Ԃ�
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				TitleSceneState = eSCENE_STATE_FADE_OUT;
			}

			// �t���O�̐؂�ւ�
			if (titleInfoTimer > TITLESCENE_INFO_BINK_INTERVAL)
			{
				titleInfoFlag = !titleInfoFlag;

				titleInfoTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// �^�C�}�[��i�߂�
			titleSceneTimer++;

			// ���̃X�e�[�g�Ɉڂ�
			if (titleSceneTimer >= TITLE_SCENE_FADE_TIME)
			{
				// �v���C�V�[����
				game->RequestScene(SCENE_PLAY);
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
void TitleScene::Render(void)
{
	// �^�C�g���̕\��
	DrawSprite(titleTexture);

	// �L�[���͍Ñ��̕\��
	if (titleInfoFlag == TRUE)
	{
		DrawFormatString(
			TITLESCENE_INFO_POS_X,
			TITLESCENE_INFO_POS_Y,
			GetColor(255, 255, 255),
			"Please Space Key"
		);
	}

	// ���t�B���^�̕\��
	float fa = (float)titleSceneTimer / (float)TITLE_SCENE_FADE_TIME;		// �^�C�}�[�̏�������0.0�`1.0�̕��Ɏ��߂�
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
�I��
����	�F
�߂�l	�F
-------------------------------------*/
void TitleScene::Finalize(void)
{
	DeleteGraph(titleTexture.handle);
}
