#pragma once
#include<windows.h>
#include "wrl.h"
#include "WinApp.h"

#define DIRECTINPUT_VERSION 0x0800 //DirectInput�̃o�[�W�����w��
#include<dinput.h>

//����
class Input
{
public:
	//namespace�ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;


public://�����o�֐�
	//������
	void Initialize(WinApp* winApp);

	//�X�V
	void Updata();

	/// <summary>
	/// �L�[�̉������`�F�b�N
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// �L�[�̃g���K�[���`�F�b�N
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool Triggerkey(BYTE keyNumber);

private://�����o�ϐ�
	//�L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> devkeyboard;

	//DirectInput�̃C���X�^���X
	ComPtr<IDirectInput8> dinput;

	//�S�L�[�̏��
	BYTE key[256] = {};

	//�O��̑S�L�[�̏��
	BYTE keyPre[256] = {};

	//WindowsAPI
	WinApp* winApp = nullptr;

};
