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

	//�v���C���[�̐���
	//Base::Add(new Player(CVector2D(100,580)));
	Base::Add(new Player(CVector2D(930, 940)));
	//�G�̐���
	Base::Add(new Enemy(CVector2D(500, 500)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	//
	Base::Add(new Boss(CVector2D(600, 600)));
	Base::Add(new Boss(CVector2D(900, 300)));
	Base::Add(new Boss(CVector2D(1600, 500)));

	//�}�b�v�̐���
	Base::Add(new Map());

	Base::Add(new UI());

}
Game::~Game()
{
	

		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());
	
}

void Game::Update()
{
	
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	
	/*
if (!Base::FindObject(eType_Player))
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�{�^���P�Ń^�C�g���j��
		if (PUSH(CInput::eButton5)) {
			m_kill = true;
			


		}
*/
//�v���C���[���S�@�{�^��5�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton5)) {
		SetKill();
	}

}

