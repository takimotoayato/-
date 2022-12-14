#include "Game.h"
#include "Game2.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Boss2.h"
#include "Title.h"
#include "Map.h"
#include "UI.h"
#include "Wall.h"
#include"GameData.h"
#include "Gameclear.h"
#include "Gameover.h"
Game::Game() :Base(eType_Scene)
{
	
	//背景生成
	Base::Add(new Wall());
	//プレイヤーの生成
	//Base::Add(new Player(CVector2D(100,580)));
	Base::Add(new Player(CVector2D(930, 940)));
	//小型の敵の生成
	/**/
	Base::Add(new Enemy(CVector2D(200, 200)));
	Base::Add(new Enemy(CVector2D(500, 500)));
	Base::Add(new Enemy(CVector2D(700, 700)));
	Base::Add(new Enemy(CVector2D(1400, 200)));
	Base::Add(new Enemy(CVector2D(1700, 200)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));

	
	//マップの生成
	Base::Add(new Map());
	Base::Add(new UI());

}

Game::~Game()
{
	

		
	
}

void Game::Update()
{
	
	//ボタン3でタイトルへ戻る
	if (PUSH(CInput::eButton3))
	{
		Base::KillAll();
		Base::Add(new Title());
	}

	if (!Base::FindObject(eType_Enemy))
	{
		//全てのオブジェクトを破棄
		Base::SetKill();
		//ゲームシーン
		Base::Add(new Game2());
		
	}

	if (!Base::FindObject(eType_Player))
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーン
		Base::Add(new Gameover());

	}


}
 
