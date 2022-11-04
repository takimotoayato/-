#include "Game.h"
//#include "Field.h"
//#include "Player.h"
#include "Title.h"
#include "Map.h"
Game::Game() :Base(eType_Scene)
{
	//Base::Add(new Field());
	//Base::Add(new Player(CVector2D(0, 540), false));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 1, 540), true));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 2, 540), true));
	//Base::Add(new Enemy(CVector2D(280 + 256 * 3, 440), true));
	//Base::Add(new trap(CVector2D(222 + 256 * 3, 440), true));
	//Base::Add(new trap(CVector2D(300 + 256 * 3, 440), true));
	//Base::Add(new Goal(CVector2D(300, 4000)));
	

}
Game::~Game()
{
	//全てのオブジェクトを破棄
	//Base::KillAll();
	//タイトルシーンへ
	//Base::Add(new Title());

	int game_state = 0;
	switch (game_state) {
	case 0:
		//ポーズ中の更新処理
		if (PUSH(CInput::eButton1))
			game_state = 1;
		break;
	case 1:
		//ゲーム中の更新処理
		break;

		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
	}
}

void Game::Update()
{
	if (!Base::FindObject(eType_Goal)) {
		Base::Add(new Title());
		if (PUSH(CInput::eButton1))
		SetKill();
	}

	
	//プレイヤー死亡　ボタン１でゲームシーン終了
	
	/*
if (!Base::FindObject(eType_Player))
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームオーバーシーンへ
		Base::Add(new Gameover());
		//ボタン１でタイトル破棄
		if (PUSH(CInput::eButton1)) {
			m_kill = true;
			


		}
*/



	
	

	if (!Base::FindObject(eType_Goal)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
		
	}
	
}

