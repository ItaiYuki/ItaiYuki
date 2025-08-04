#pragma once
#include "KamataEngine.h"
;

class Player {

public:
	// 初期化
	/*void Initialize() {};*/
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, KamataEngine::Vector3& position);

	// 更新
	void Update();

	// 描画
	void Draw();

	KamataEngine::Vector3 velocity_ = {};

	enum class LRDirection {
		kRight,
		kLeft,
	};

	// 接地状態フラグ
	bool onGround_ = true;

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	// 加速度
	static inline float kAcceleration = 0.1f;
	// 減速
	static inline const float kAttenuation = 1.0f;
	// 最大速度
	static inline const float kLimitRunSpeed = 1.0f;

	// 旋回開始の角度
	float turnFirstRotationY_ = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;
	// 旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	// 重力加速度（下方向）
	static inline const float kGravityAcceleration = 0.1f;
	// 最大落下速度（下方向）
	static inline const float kLimitFallSpeed = 1.0f;
	// ジャンプ初速（上方向）
	static inline const float kJumpAcceleration = 1.0f;

	LRDirection lrDirection_ = LRDirection::kRight;
};
