#pragma once


// �V�[�� ---------------------------------------------------
// ��Ԃ̗�
enum eSCENE_STATE
{
	eSCENE_STATE_FADE_IN,			// �t�F�[�h�C��
	eSCENE_STATE_WAIT_KEY,			// �L�[�̓��͑҂�
	eSCENE_STATE_FADE_OUT,			// �t�F�[�h�A�E�g
};
typedef enum eSCENE_STATE eSCENE_STATE;


class GameBase
{
public:
	virtual ~GameBase() {};
	//�������z�֐�
	// �p����ŕK�����g������
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finalize() = 0;
};
