#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include <vector>

/// <summary>
/// 天球
/// </summary>
class Skydome {

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	private:
		// ワールド変換データ
	    KamataEngine::WorldTransform worldTransform_;
		// モデル
	    KamataEngine::Model* model_ = nullptr;

		 // テクスチャハンドル
	    uint32_t textureHandle_ = 0u;

	    KamataEngine::Camera* camera_ = nullptr;
	    
};
