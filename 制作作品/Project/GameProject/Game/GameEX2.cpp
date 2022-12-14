#include "GameEX.h"
#include "GameEX2.h"
#include "GameEX3.h"
#include "Game.h"
#include "Game2.h"
#include "Game3.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Title.h"
#include "Map.h"
#include "UI.h"
#include "Wall.h"
#include"GameData.h"
#include "Gameclear.h"
#include "Gameover.h"
GameEX2::GameEX2() :Base(eType_Scene)
{

	//背景生成
	Base::Add(new Wall());
	//プレイヤーの生成
	//Base::Add(new Player(CVector2D(100,580)));
	//Base::Add(new Player(CVector2D(930, 940)));
	//小型の敵の生成
	/*
	Base::Add(new Enemy(CVector2D(200, 200)));
	Base::Add(new Enemy(CVector2D(500, 500)));
	Base::Add(new Enemy(CVector2D(700, 700)));
	Base::Add(new Enemy(CVector2D(1400, 200)));
	Base::Add(new Enemy(CVector2D(1700, 200)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));*/
	//大型の敵の生成
	/*
	Base::Add(new Boss(CVector2D(600, 600)));
	Base::Add(new Boss(CVector2D(100, 100)));
	Base::Add(new Boss(CVector2D(1800, 100)));
	Base::Add(new Boss(CVector2D(900, 300)));
	Base::Add(new Boss(CVector2D(1600, 500)));*/
	Base::Add(new Boss(CVector2D(900, 100)));


	//マップの生成
	//Base::Add(new Map());

	//Base::Add(new UI());

}
GameEX2::~GameEX2()
{


	//全てのオブジェクトを破棄
	//Base::KillAll();
	//タイトルシーンへ
	//Base::Add(new Title());

}

void GameEX2::Update()
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
		Base::Add(new GameEX3());

	}
	if (!Base::FindObject(eType_Player))
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーン
		Base::Add(new Gameover());

	}

}