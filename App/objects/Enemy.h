#pragma once
#include "Object3d.h"

// TRACKモデルのサイズ
#define TRACK_RADIUS_X 1.3f
#define TRACK_RADIUS_Z 6.1f
// CARモデルのサイズ
#define CAR_RADIUS_X 1.3f
#define CAR_RADIUS_Z 3.0f
// RandTimerの最大数
#define RANDTIMER_MAX 200
// RandTimerの最小数
#define RANDTIMER_MINI 50
// ラインの中心座標
#define CENTERLINER 1.8f
#define SIDELINE 5.3f
// スピード
#define TopSpeed 0.7f
#define MiddleSpeed 0.6f
#define BottonSpeed 0.5f
// 配置座標
#define BASEPOS 310.0f
enum ModelNumber
{
	car,
	track,
};

enum LineNumber
{
	left_Second,
	left_First, 
	right_First,
	right_Second,
};

enum SpeedNumber
{
	First,
	Second,
};

class Enemy
{
private: // エイリアス
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public:// 定数
	static const int maxModel = 2;// モデルの最大数
	static const int maxTimer = 4;// タイマーの最大数
	static const int maxSpeedPattern = 3;// スピードパターンの最大数


public: // 静的メンバ関数

	/// <summary>
	/// インスタンス
	/// </summary>
	static Enemy* Create();

public: // メンバ関数

	// デストラクタ
	~Enemy();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(const XMFLOAT3& playerPos, const float& playerSpeed, bool hitFlag);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

#pragma region getter
	// 生成タイマー取得
	const int& GetCreateTimer() { return createTimer[0]; }
	// データ数を取得
	size_t GetDataSize() { return objects.size(); }
	// 座標取得
	XMFLOAT3 GetPos(const int& number);
	// モデルフラッグ取得
	bool GetModelFlag(const int& number);
#pragma endregion


private:
	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 自動移動
	/// </summary>
	/// <param name="i">配列のカウント</param>
	void AutoSprint(int number);

	/// <summary>
	/// ランダムに座標を決定する
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 RandPos(int number);

	/// <summary>
	/// ランダムにモデルを設定する
	/// </summary>
	/// <returns></returns>
	short RandModel();

	/// <summary>
	/// ランダムにスピードを設定する
	/// </summary>
	/// <returns></returns>
	float RandSpeed();

private:

	// 車モデル
	Model* model[maxModel] = { nullptr };
	// オブジェクト
	std::vector<Object3d*>objects;
	// 速度
	std::vector<float>speeds;
	// モデルフラッグ
	std::vector<bool>modelFlags;
	// 生成時間
	int createTimer[maxTimer] = {};
	// 存在フラッグ
	bool existenceFlag = false;

	// プレイヤー座標
	XMFLOAT3 player_Pos{};
	// プレイヤースピード
	float player_Speed = 0.0f;
	

};