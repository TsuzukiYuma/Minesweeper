//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include <assert.h>
#include "FrameWork\KeyInput\KeyInput.h"
#include "Scene\Logo\LogoScene.h"
#include "Scene\Title\TitleScene.h"
#include "Scene\PLay\PlayScene.h"
#include "Scene\Result\ResultScene.h"


// �萔�̒�` ==============================================================
#define START_SCENE (SCENE_LOGO)



// �O���[�o���ϐ��̒�` ====================================================


// �֐��̐錾 ==============================================================





// �֐��̒�` ==============================================================
// �����o�֐��̒�` ========================================================
//------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//------------------------------------------------------------------
Game::Game()
{

}



//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
Game::~Game()
{
	delete base;
}



/*-------------------------------------
�Q�[���̏���������
����	�F
�߂�l	�F
-------------------------------------*/
void Game::Initialize(void)
{

	activeScene = SCENE_NONE;
	nextScene = START_SCENE;


}



/*-------------------------------------
�Q�[���̍X�V����
����	�F
�߂�l	�F
-------------------------------------*/
void Game::Update(void)
{
	// �L�[�����̍X�V
	KeyInputUpdate();

	// �V�[���ύX���K�v���ǂ������`�F�b�N
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

	// �������̃V�[�����X�V
	base->Update();
}



/*-------------------------------------
�Q�[���̕`�揈��
����	�F
�߂�l	�F
-------------------------------------*/
void Game::Render(void)
{
	// �������̃V�[����`��
	base->Render();
}



/*-------------------------------------
�Q�[���̏I������
����	�F
�߂�l	�F
-------------------------------------*/
void Game::Finalize(void)
{
	// �������̃V�[���̏I������
	base->Finalize();

}

/*-------------------------------------
�V�[���ύX�̗v��
        �����ۂɂ�Update���ɕύX�����
����	�Fscene_id �ύX�������V�[����ID
�߂�l	�F
-------------------------------------*/
void Game::RequestScene(SceneID scene_id)
{
	nextScene = scene_id;
}




