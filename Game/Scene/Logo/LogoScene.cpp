#include "../../FrameWork/KeyInput/KeyInput.h"
#include "LogoScene.h"

/*-------------------------------------
�R���X�g���N�^

����	�F Game�N���X�̃|�C���^
-------------------------------------*/
LogoScene::LogoScene(Game* g)
{
	game = g;
}

/*-------------------------------------
�f�X�g���N�^
-------------------------------------*/
LogoScene::~LogoScene()
{

}

/*-------------------------------------
������
����	�F
�߂�l	�F
-------------------------------------*/
void LogoScene::Initialize(void)
{

	// ���S�e�N�X�`���̓ǂݍ���
	logTexture.handle = LoadGraph("Resources/Textures/TridentLogo.png");

	// ���W�̐ݒ�
	logTexture.pos.x = SCREEN_CENTER_X;
	logTexture.pos.y = SCREEN_CENTER_Y;

	// �؂���ʒu�̐ݒ�
	logTexture.rectSt.x = 0.0f;
	logTexture.rectSt.y = 0.0f;
	logTexture.rectEd.x = LOGO_SCENE_LOGO_SIZE_X;
	logTexture.rectEd.y = LOGO_SCENE_LOGO_SIZE_Y;

	// �X�P�[���ݒ�
	logTexture.scale = 1.0;

	// �p�x�̐ݒ�
	logTexture.rot = 0.0;

	// �����x�̐ݒ�
	logTexture.alpha = 1.0f;

	// �^�C�}�[
	logoSceneTimer = LOGO_SCENE_FADE_TIME;
	// �\���^�C�}�[
	logoViewTimer = LOGO_SCENE_VIEW_TIME;

	// ��Ԃ̕ۑ�
	LogoSceneState = eSCENE_STATE_FADE_IN;


}

/*-------------------------------------
�X�V
����	�F
�߂�l	�F
-------------------------------------*/
void LogoScene::Update(void)
{
	switch (LogoSceneState)
	{
		case eSCENE_STATE_FADE_IN:
		{
			// �^�C�}�[��i�߂�
			logoSceneTimer--;

			// ���̃X�e�[�g�Ɉڂ�
			if (logoSceneTimer <= 0)
			{
				LogoSceneState = eSCENE_STATE_WAIT_KEY;
				logoSceneTimer = 0;
			}

			break;
		}
		case eSCENE_STATE_WAIT_KEY:
		{
			// �L�[�������ꂽ�玟�̏�Ԃ�
			if (IsKeyDown(PAD_INPUT_10) == TRUE)
			{
				LogoSceneState = eSCENE_STATE_FADE_OUT;
			}

			// �^�C�}�[�ł��V�[����i�߂�
			logoViewTimer--;

			// ���̃X�e�[�g�Ɉڂ�
			if (logoViewTimer <= 0)
			{
				LogoSceneState = eSCENE_STATE_FADE_OUT;
			}


			break;
		}
		case eSCENE_STATE_FADE_OUT:
		{
			// �^�C�}�[��i�߂�
			logoSceneTimer++;

			// ���̃X�e�[�g�Ɉڂ�
			if (logoSceneTimer >= LOGO_SCENE_FADE_TIME)
			{
				// �^�C�g���V�[����
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
void LogoScene::Render(void)
{
	// ���S�̕\��
	DrawSprite(logTexture);

	// ���t�B���^�̕\��
	float fa = (float)logoSceneTimer / (float)LOGO_SCENE_FADE_TIME;		// �^�C�}�[�̏�������0.0�`1.0�̕��Ɏ��߂�
	DrawBoxAAa(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, fa);
}

/*-------------------------------------
�I��
����	�F
�߂�l	�F
-------------------------------------*/
void LogoScene::Finalize(void)
{
	DeleteGraph(logTexture.handle);
}

