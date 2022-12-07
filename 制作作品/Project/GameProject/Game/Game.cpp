#include "Game.h"
#include "Game2.h"
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
Game::Game() :Base(eType_Scene)
{
	
	//�w�i����
	Base::Add(new Wall());
	//�v���C���[�̐���
	//Base::Add(new Player(CVector2D(100,580)));
	Base::Add(new Player(CVector2D(930, 940)));
	//���^�̓G�̐���
	/*
	Base::Add(new Enemy(CVector2D(200, 200)));
	Base::Add(new Enemy(CVector2D(500, 500)));
	Base::Add(new Enemy(CVector2D(700, 700)));
	Base::Add(new Enemy(CVector2D(1400, 200)));
	Base::Add(new Enemy(CVector2D(1700, 200)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));*/
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	//��^�̓G�̐���
	/*
	Base::Add(new Boss(CVector2D(600, 600)));
	Base::Add(new Boss(CVector2D(100, 100)));
	Base::Add(new Boss(CVector2D(1800, 100)));
	Base::Add(new Boss(CVector2D(900, 300)));
	Base::Add(new Boss(CVector2D(1600, 500)));*/
	Base::Add(new Boss(CVector2D(900, 100)));


	//�}�b�v�̐���
	Base::Add(new Map());

	Base::Add(new UI());

}

Game::~Game()
{
	

		//�S�ẴI�u�W�F�N�g��j��
		//Base::KillAll();
		//�^�C�g���V�[����
		//Base::Add(new Title());
	
}

void Game::Update()
{
	/*
	if (!Base::FindObject(eType_Enemy)) 
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Gameclear());

	}
	*/
	/*
	if (PUSH(CInput::eButton3))
	{
		m_kill = true;
		Base::Add(new Title());
	}
	*/
	if (!Base::FindObject(eType_Enemy))
	{
		//�S�ẴI�u�W�F�N�g��j��
		//Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Game2());
		
	}
	if (!Base::FindObject(eType_Player))
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new Gameover());

	}


}
 
