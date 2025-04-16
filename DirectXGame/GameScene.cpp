#include"GameScene.h"

using namespace KamataEngine;



void GameScene::Initialize(){
	//メンバ変数への代入処理（省略）
	//ここにインゲームの初期化処理を書く

	//3Dモデルの生成
	model_ = Model::Create();

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//カメラの初期化
	camera_.Initialize();

	textureHandle_ = TextureManager::Load("mario.jpg");

	}

void GameScene::Update() {
	//ここにゲームの更新処理を書く


	}

void GameScene::Draw(){

	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera_, textureHandle_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	}

GameScene::~GameScene(){
delete model_;
	}


