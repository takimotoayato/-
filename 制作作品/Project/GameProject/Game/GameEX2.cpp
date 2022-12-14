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

	//�w�i����
	Base::Add(new Wall());
	//��^�̓G�̐���
	/**/
	Base::Add(new Boss(CVector2D(600, 600)));
	Base::Add(new Boss(CVector2D(100, 100)));
	Base::Add(new Boss(CVector2D(1800, 100)));
	Base::Add(new Boss(CVector2D(900, 300)));
	Base::Add(new Boss(CVector2D(1600, 500)));
	Base::Add(new Boss(CVector2D(900, 100)));


	

}
GameEX2::~GameEX2()
{


	

}

void GameEX2::Update()
{

	//�{�^��3�Ń^�C�g���֖߂�
	if (PUSH(CInput::eButton3))
	{
		Base::KillAll();
		Base::Add(new Title());
	}
	if (!Base::FindObject(eType_Enemy))
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::SetKill();
		//�Q�[���V�[��
		Base::Add(new GameEX3());

	}
	if (!Base::FindObject(eType_Player))
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Gameover());

	}

}