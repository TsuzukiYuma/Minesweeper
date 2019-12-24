#include <memory.h>

// �L�[�o�b�t�@�̐�
//#define KEY_INPUT_BUFFER		256 

// �L�[�������ꂽ���̏���ۑ�
//char g_isPressKeys[KEY_INPUT_BUFFER] = {};
int g_isPressKeys = 0;

// �O�̃t���[���ŃL�[�������ꂽ���̏���ۑ�
//char g_isPrevPressKeys[KEY_INPUT_BUFFER] = {};
int g_isPrevPressKeys;

/*-------------------------------
�L�[�����̍X�V
����	�F�Ȃ�
�߂�l	�F�_��
-------------------------------*/
void KeyInputUpdate(void)
{
	// �O�̃t���[���ɉ����ꂽ�L�[��ۑ�
	//memcpy(g_isPrevPressKeys, g_isPressKeys, sizeof(char) * KEY_INPUT_BUFFER);
	g_isPrevPressKeys = g_isPressKeys;

	// �L�[�̉�����Ԃ�ۑ�
	//GetHitKeyStateAll(g_isPressKeys);
	g_isPressKeys = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

/*-------------------------------
�L�[���������܂ꂽ�u�Ԃ��ǂ���
����	�F�Ȃ�
�߂�l	�F�^�U�l
-------------------------------*/
int  IsKeyDown(int key)
{
	//if (g_isPrevPressKeys[key] == FALSE && g_isPressKeys[key] == TRUE)
	if ((g_isPressKeys & key) &&  !(g_isPrevPressKeys & key))
	{
		return TRUE;
	}

	return FALSE;
}

/*-------------------------------
�L�[�������ꑱ���Ă��邩�ǂ���
����	�F�Ȃ�
�߂�l	�F�^�U�l
-------------------------------*/
int  IsKeyPress(int key)
{
	//if (g_isPressKeys[key] == TRUE)
	if ((g_isPressKeys & key))
	{
		return TRUE;
	}

	return FALSE;
}

/*-------------------------------
�L�[�������ꂽ���ǂ���
����	�F�Ȃ�
�߂�l	�F�^�U�l
-------------------------------*/
int  IsKeyUp(int key)
{
	//if (g_isPrevPressKeys[key] == TRUE && g_isPressKeys[key] == FALSE)
	if (!(g_isPressKeys & key) && (g_isPrevPressKeys & key))
	{
		return TRUE;
	}

	return FALSE;
}