#pragma once
#include "../../GameMain.h"
#include "../../GameBase.h"
#include "../../FrameWork/Graph/Graph.h"

// �萔----------------------------------------------

// �L�[���͍Ñ��̕����ʒu
const int RESULTSCENE_INFO_POS_X = (SCREEN_CENTER_X - 75);
const int RESULTSCENE_INFO_POS_Y = (SCREEN_CENTER_Y + 100);

// �L�[���͍Ñ��̕����_�ŊԊu
const int RESULTSCENE_INFO_BINK_INTERVAL = 40;

// �t�F�[�h����
const int RESULT_SCENE_FADE_TIME = 30;


class ResultScene:public GameBase
{
	// �f�[�^�����o�̐錾
	Game* game;

	// �^�C�}�[
	int resultSceneTimer;

	// ��Ԃ̕ۑ�
	eSCENE_STATE ResultSceneState;

	// �L�[���͍Ñ������̓_�ŗp�^�C�}�[
	int resultInfoTimer;

	// �L�[���͍Ñ������̕\���t���O
	int resultInfoFlag;


	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	ResultScene(Game* g);

	// �f�X�g���N�^
	~ResultScene();

public:
	// ����
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
