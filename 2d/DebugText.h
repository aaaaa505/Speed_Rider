#pragma once
#include <Windows.h>
#include <string>
#include "Sprite.h"

class DebugText
{
public: //�萔�̐錾    
	static const int maxCharCount = 256;//�ő啶����
	static const int fontWidth = 9;//�t�H���g�摜��1�������̉���
	static const int fontHeight = 18;//�t�H���g�摜��1�������̏c��
	static const int fontLineCount = 14;//�t�H���g�摜��1�s���̕�����

public: //�����o�֐�
	// �R���X�g���N�^
	DebugText();
	// �f�X�g���N�^
	~DebugText();
	// ����
	static DebugText* Create(SpriteCommon* spriteCommon, UINT texnumber);
	// ������
	void Initialize(SpriteCommon* spriteCommon, UINT texnumber);
	// 
	void Print(const std::string& text, float x, float y, float size);
	// �`��
	void DrawAll();

private: //�����o�ϐ�   
	//�X�v���C�g���ʕ���
	SpriteCommon* spriteCommon;
	//�X�v���C�g�f�[�^�̔z��
	Sprite* spriteDatas[maxCharCount] = {};
	//�X�v���C�g�f�[�^�z��̓Y�����ԍ�
	int spriteIndex = 0;
};