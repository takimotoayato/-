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
	//�S�ẴI�u�W�F�N�g��j��
	//Base::KillAll();
	//�^�C�g���V�[����
	//Base::Add(new Title());

	int game_state = 0;
	switch (game_state) {
	case 0:
		//�|�[�Y���̍X�V����
		if (PUSH(CInput::eButton1))
			game_state = 1;
		break;
	case 1:
		//�Q�[�����̍X�V����
		break;

		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
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

	
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	
	/*
if (!Base::FindObject(eType_Player))
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���I�[�o�[�V�[����
		Base::Add(new Gameover());
		//�{�^���P�Ń^�C�g���j��
		if (PUSH(CInput::eButton1)) {
			m_kill = true;
			


		}
*/



	
	

	if (!Base::FindObject(eType_Goal)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());
		
	}
	
}

