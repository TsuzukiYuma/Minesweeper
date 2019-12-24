#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// �萔----------------------------------------------

// �^�C�g���摜�T�C�Y
const int TITLE_SCENE_TITLE_SIZE_X = 160;
const int TITLE_SCENE_TITLE_SIZE_Y = 56;

// �^�C�g���̕\���ʒu
const int TITLE_SCENE_TITLE_POS_X = SCREEN_CENTER_X;
const int TITLE_SCENE_TITLE_POS_Y = (SCREEN_CENTER_Y - 50);

// �L�[���͍Ñ��̕����ʒu
const int TITLESCENE_INFO_POS_X = (SCREEN_CENTER_X - 75);
const int TITLESCENE_INFO_POS_Y = (SCREEN_CENTER_Y + 100);

// �L�[���͍Ñ��̕����_�ŊԊu
const int TITLESCENE_INFO_BINK_INTERVAL = 40;

// �t�F�[�h����
const int TITLE_SCENE_FADE_TIME = 30;

class TitleScene:public GameBase
{
	// �f�[�^�����o�̐錾
	Game* game;


	// �摜���
	TextureData titleTexture;

	// �^�C�}�[
	int titleSceneTimer;

	// ��Ԃ̕ۑ�
	eSCENE_STATE TitleSceneState;

	// �L�[���͍Ñ������̓_�ŗp�^�C�}�[
	int titleInfoTimer;

	// �L�[���͍Ñ������̕\���t���O
	int titleInfoFlag;


	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	TitleScene(Game* g);

	// �f�X�g���N�^
	~TitleScene();

public:
	// ����
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
