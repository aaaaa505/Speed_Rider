#pragma once
#include <DirectXMath.h>

#include "Input.h"
#include <memory>

class Camera
{
private: // �G�C���A�X
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public: // �����o�֐�
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="window_width"></param>
	/// <param name="window_height"></param>
	Camera(int window_width, int window_height);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Camera();

	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �r���[�s����X�V
	/// </summary>
	void UpdateViewMatrix();

	/// <summary>
	/// �ˉe�s����X�V
	/// </summary>
	void UpdateProjectionMatrix();

	/// <summary>
	/// �r���[�s��̎擾
	/// </summary>
	/// <returns>�r���[�s��</returns>
	inline const XMMATRIX& GetViewMatrix() {
		return matView;
	}

	/// <summary>
	/// �ˉe�s��̎擾
	/// </summary>
	/// <returns>�ˉe�s��</returns>
	inline const XMMATRIX& GetProjectionMatrix() {
		return matProjection;
	}

	/// <summary>
	/// �r���[�ˉe�s��̎擾
	/// </summary>
	/// <returns>�r���[�ˉe�s��</returns>
	inline const XMMATRIX& GetViewProjectionMatrix() {
		return matViewProjection;
	}

	/// <summary>
	/// �r���{�[�h�s��̎擾
	/// </summary>
	/// <returns>�r���{�[�h�s��</returns>
	inline const XMMATRIX& GetBillboardMatrix() {
		return matBillboard;
	}

	/// <summary>
	/// ���_���W�̎擾
	/// </summary>
	/// <returns>���W</returns>
	inline const XMFLOAT3& GetEye() {
		return eye;
	}

	/// <summary>
	/// ���_���W�̐ݒ�
	/// </summary>
	/// <param name="eye">���W</param>
	inline void SetEye(XMFLOAT3 eye) {
		this->eye = eye; viewDirty = true;
	}

	/// <summary>
	/// �����_���W�̎擾
	/// </summary>
	/// <returns>���W</returns>
	inline const XMFLOAT3& GetTarget() {
		return target;
	}

	/// <summary>
	/// �����_���W�̐ݒ�
	/// </summary>
	/// <param name="target">���W</param>
	inline void SetTarget(XMFLOAT3 target) {
		this->target = target; viewDirty = true;
	}

	/// <summary>
	/// ������x�N�g���̎擾
	/// </summary>
	/// <returns>������x�N�g��</returns>
	inline const XMFLOAT3& GetUp() {
		return up;
	}

	/// <summary>
	/// ������x�N�g���̐ݒ�
	/// </summary>
	/// <param name="up">������x�N�g��</param>
	inline void SetUp(XMFLOAT3 up) {
		this->up = up; viewDirty = true;
	}

	/// <summary>
	/// �x�N�g���ɂ�鎋�_�ړ�
	/// </summary>
	/// <param name="move">�ړ���</param>
	void MoveEyeVector(const XMFLOAT3& move);
	void MoveEyeVector(const XMVECTOR& move);

	/// <summary>
	/// �x�N�g���ɂ��ړ�
	/// </summary>
	/// <param name="move">�ړ���</param>
	void MoveVector(const XMFLOAT3& move);
	void MoveVector(const XMVECTOR& move);

	/// <summary>
	/// �J�����V�F�C�N
	/// </summary>
	void ShakeCamera(XMFLOAT3 cameraPos);

	/// <summary>
	/// �U������setter
	/// </summary>
	/// <param name="shakeTimer"></param>
	void SetShakeTimer(float shakeTimer) { this->shakeTimer = shakeTimer; }

	/// <summary>
	/// ��Ԋm�F�p�J��������
	/// </summary>
	void MoveCamera(Input* input, const float movePower);

private:
	// �r���[�s��
	XMMATRIX matView = DirectX::XMMatrixIdentity();
	// �r���{�[�h�s��
	XMMATRIX matBillboard = DirectX::XMMatrixIdentity();
	// Y�����r���{�[�h�s��
	XMMATRIX matBillboardY = DirectX::XMMatrixIdentity();
	// �ˉe�s��
	XMMATRIX matProjection = DirectX::XMMatrixIdentity();
	// �r���[�ˉe�s��
	XMMATRIX matViewProjection = DirectX::XMMatrixIdentity();
	// �r���[�s��_�[�e�B�t���O
	bool viewDirty = false;
	// �ˉe�s��_�[�e�B�t���O
	bool projectionDirty = false;
	// ���_���W
	XMFLOAT3 eye = { 0, 0, 1 };
	// �����_���W
	XMFLOAT3 target = { 0, 0, 0 };
	// ������x�N�g��
	XMFLOAT3 up = { 0, 1, 0 };
	// �A�X�y�N�g��
	float aspectRatio = 1.0f;
	// �J���������_�܂ł̋���
	float distance = 20;
	// �X�P�[�����O
	float scaleX = 1.0f;
	float scaleY = 1.0f;
	//�U������
	float shakeTimer = 0.0f;
	//�U�����W
	XMFLOAT2 shake = { 0.0f, 0.0f };
};
