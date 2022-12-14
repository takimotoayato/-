#include "Game.h"
#include "Game2.h"
#include "Game3.h"
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
Game3::Game3() :Base(eType_Scene)
{

	
	//���^�̓G�̐���
	/**/
	Base::Add(new Enemy(CVector2D(200, 200)));
	Base::Add(new Enemy(CVector2D(500, 500)));
	Base::Add(new Enemy(CVector2D(700, 700)));
	Base::Add(new Enemy(CVector2D(1400, 200)));
	Base::Add(new Enemy(CVector2D(1700, 200)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	//��^�̓G�̐���
	/**/
	Base::Add(new Boss(CVector2D(600, 600)));
	Base::Add(new Boss(CVector2D(100, 100)));
	Base::Add(new Boss(CVector2D(1800, 100)));
	Base::Add(new Boss2(CVector2D(900, 300)));
	Base::Add(new Boss(CVector2D(1600, 500)));
	Base::Add(new Boss(CVector2D(900, 100)));


	

}

Game3::~Game3()
{


	

}

void Game3::Update()
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
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Gameclear());

	}
	if (!Base::FindObject(eType_Player)) 
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Gameover());

	}


}
