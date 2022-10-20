#include "Player.h"
#include "Input.h"

Player* Player::Create()
{
	// インスタンス生成
	Player* instance = new Player();
	// インスタンス初期化
	instance->Initialize();

	return instance;
}

Player::~Player()
{
	// カメラ解放
	delete camera;
	// モデル解放
	delete model_Bike;
	// オブジェクト解放
	delete obj_Bike;
}

void Player::Initialize()
{
	// カメラ生成＆セット
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);

	// モデル読み込み
	model_Bike = Model::LoadFromOBJ("bike", true);
	// オブジェクト生成
	obj_Bike = Object3d::Create(model_Bike);
	// 初期座標
	pos = { 0.0f, 0.0f, 0.0f };
	// 初期回転
	rot = { 0.0f, 0.0f, 0.0f };
	// スケール
	obj_Bike->SetScale({ 0.5f, 0.5f, 0.5f });
	// 初速度
	speed = { 0.1f, 0.0f, 0.1f };

	// モデル読み込み
	model_Dome = Model::LoadFromOBJ("skydome");
	// オブジェクト生成
	obj_Dome = Object3d::Create(model_Dome);
}

void Player::BesideMove()
{
	// 左移動
	if (Input::GetInstacne()->PushKey(DIK_A))
	{
		pos.x -= speed.x;
	}

	// 右移動
	if (Input::GetInstacne()->PushKey(DIK_D))
	{
		pos.x += speed.x;
	}
}

float Player::Fluctuation()
{
	// 加速
	if (Input::GetInstacne()->PushKey(DIK_W) && speed.z <= 1.5f)
	{
		speed.z += 0.01f;
	}

	// 規定値より上なら
	if (speed.z >= 0.12f)
	{
		// 惰性走行
		if (Input::GetInstacne()->AwayKey(DIK_W))
		{
			speed.z -= 0.005f;
		}
		// ブレーキ
		if (Input::GetInstacne()->PushKey(DIK_S))
		{
			speed.z -= 0.01f;
		}
	}

	return speed.z;
}

void Player::AutoSprint()
{
	// 座標に速度を加算
	pos.z += Fluctuation();
	// 更新した座標をセット
	obj_Bike->SetPosition(pos);
}

void Player::DebugMove()
{
	if (Input::GetInstacne()->PushMoveKey())
	{
		if (Input::GetInstacne()->PushKey(DIK_W))
		{
			pos.z += 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_A))
		{
			pos.x -= 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_S))
		{
			pos.z -= 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_D))
		{
			pos.x += 0.1f;
		}

		obj_Bike->SetPosition(pos);
	}
}

void Player::Update()
{
	// 横移動
	BesideMove();
	// 自動移動
	AutoSprint();
	//DebugMove();
	// カメラ追従
	camera->SetEye({pos.x, pos.y + 1.7f, pos.z - 0.3f});
	camera->SetTarget({pos.x, pos.y + 1.7f, pos.z + 1.0f});

	// カメラ更新
	camera->Update();
	// バイク更新
	obj_Bike->Update();
	// スカイドーム更新
	obj_Dome->SetPosition({ pos.x, pos.y, pos.z + 20.0f });
	obj_Dome->Update();
}

void Player::Draw()
{
	// バイク更新
	obj_Bike->Draw();
	// スカイドーム更新
	obj_Dome->Draw();
}