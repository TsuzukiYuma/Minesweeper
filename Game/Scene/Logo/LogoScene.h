#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// �萔----------------------------------------------

// ���S�摜�T�C�Y
const int LOGO_SCENE_LOGO_SIZE_X = 256;
const int LOGO_SCENE_LOGO_SIZE_Y = 256;

// �t�F�[�h����
const int LOGO_SCENE_FADE_TIME = 60;
// �\������
const int LOGO_SCENE_VIEW_TIME = 120;

class LogoScene:public GameBase
{
	// �f�[�^�����o�̐錾
	Game* game;

	// �摜���
	TextureData logTexture;

	// �^�C�}�[
	int logoSceneTimer;
	// �\���^�C�}�[
	int logoViewTimer;

	// ��Ԃ̕ۑ�
	eSCENE_STATE LogoSceneState;


	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	LogoScene(Game* g);

	// �f�X�g���N�^
	~LogoScene();

public:
	// ����
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};

