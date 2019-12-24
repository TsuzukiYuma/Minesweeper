#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// �萔----------------------------------------------

// �L�[���͍Ñ��̕����ʒu
const int PLAYSCENE_INFO_POS_X = (SCREEN_CENTER_X - 75);
const int PLAYSCENE_INFO_POS_Y = (SCREEN_CENTER_Y + 100);

// �L�[���͍Ñ��̕����_�ŊԊu
const int PLAYSCENE_INFO_BINK_INTERVAL = 40;

// �t�F�[�h����
const int PLAY_SCENE_FADE_TIME = 30;


class PlayScene:public GameBase
{
	// �f�[�^�����o�̐錾
	Game* game;

	// �^�C�}�[
	int playSceneTimer;

	// ��Ԃ̕ۑ�
	eSCENE_STATE PlaySceneState;

	// �L�[���͍Ñ������̓_�ŗp�^�C�}�[
	int playInfoTimer;

	// �L�[���͍Ñ������̕\���t���O
	int playInfoFlag;


	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	PlayScene(Game* g);

	// �f�X�g���N�^
	~PlayScene();

public:
	// ����
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
