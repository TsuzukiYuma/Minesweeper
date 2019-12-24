#pragma once


// シーン ---------------------------------------------------
// 状態の列挙
enum eSCENE_STATE
{
	eSCENE_STATE_FADE_IN,			// フェードイン
	eSCENE_STATE_WAIT_KEY,			// キーの入力待ち
	eSCENE_STATE_FADE_OUT,			// フェードアウト
};
typedef enum eSCENE_STATE eSCENE_STATE;


class GameBase
{
public:
	virtual ~GameBase() {};
	//純粋仮想関数
	// 継承先で必ず中身を書く
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Finalize() = 0;
};
