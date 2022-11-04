#include "Game.h"
//#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Title.h"
#include "Map.h"
#include "UI.h"
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

	//プレイヤーの生成
	//Base::Add(new Player(CVector2D(100,580)));
	Base::Add(new Player(CVector2D(930, 940)));
	//敵の生成
	Base::Add(new Enemy(CVector2D(500, 500)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	//
	Base::Add(new Boss(CVector2D(600, 600)));
	Base::Add(new Boss(CVector2D(900, 300)));
	Base::Add(new Boss(CVector2D(1600, 500)));

	//マップの生成
	Base::Add(new Map());

	Base::Add(new UI());

}
Game::~Game()
{
	

		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
	
}

void Game::Update()
{
	
	//プレイヤー死亡　ボタン１でゲームシーン終了
	
	/*
if (!Base::FindObject(eType_Player))
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ボタン１でタイトル破棄
		if (PUSH(CInput::eButton5)) {
			m_kill = true;
			


		}
*/
//プレイヤー死亡　ボタン5でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton5)) {
		SetKill();
	}

}

