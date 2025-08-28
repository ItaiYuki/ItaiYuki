#include "GameClear.h"
#include "Math.h"
#include <numbers>

void GameClear::Initialize() {
	// 3Dモデルの生成
	modelClear_ = Model::CreateFromOBJ("clearFont", true);
	modelPlayer_ = Model::CreateFromOBJ("player");

	// 画像読み込み
	textureHandle_ = TextureManager::Load("gameClear.png");

	// カメラの初期化
	camera_.Initialize();

	// ワールド変更の初期化
	worldTransformTitle_.Initialize();
	worldTransformTitle_.scale_ = {2, 2, 2};
	worldTransformTitle_.translation_ = {0, 8, 0};

	worldTransformPlayer_.Initialize();
	worldTransformPlayer_.scale_ = {10, 10, 10};
	worldTransformPlayer_.translation_ = {0, -8, 0};
	worldTransformPlayer_.rotation_.y = std::numbers::pi_v<float>;

	// フェード
	fade_ = new Fade();
	fade_->Initialize();
	fade_->Start(Fade::Status::FadeIn, 1.0f);

	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
}

void GameClear::Update() {

	switch (phase_) {

	case Phase::kMain:
		// タイトルシーンの終了条件
		if (Input::GetInstance()->PushKey(DIK_SPACE)) {
			// フェードアウト開始
			phase_ = Phase::kFadeOut;
			fade_->Start(Fade::Status::FadeOut, 1.0f);
		}
		break;
	case Phase::kFadeIn:
		// フェード
		fade_->Update();
		if (fade_->IsFinished()) {
			phase_ = Phase::kMain;
		}
		break;
	case Phase::kFadeOut:
		// フェード
		fade_->Update();
		if (fade_->IsFinished()) {
			finished_ = true;
		}
	}
}

void GameClear::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon_->GetCommandList());

	sprite_->Draw();

	Sprite::PostDraw();

	// ３Dモデル描画前処理
	Model::PreDraw(dxCommon_->GetCommandList());

	// ここに３Dモデルインスタンスの描画処理を記述する
	/*modelTitle_->Draw(worldTransformTitle_, camera_);*/
	modelPlayer_->Draw(worldTransformPlayer_, camera_);
	// ３Dモデル描画後処理
	Model::PostDraw();

	fade_->Draw();
}

GameClear::~GameClear() {
	// モデル
	delete modelClear_;
	delete modelPlayer_;

	delete sprite_;

	// フェード
	delete fade_;
}