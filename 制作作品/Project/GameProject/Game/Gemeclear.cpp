#include "Gameclear.h"
#include "Game.h"
#include "Title.h"

Gameclear::Gameclear() :Base(eType_Gameclear), m_Gameclear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) 
{
	m_img = COPY_RESOURCE("�Q�[���N���A", CImage);
	
}

Gameclear::~Gameclear() {

}

void Gameclear::Update() {
	//�{�^���P�ŃN���A��ʂ�j��
	if (PUSH(CInput::eButton1)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[��
		Base::Add(new Title());
	}
}

void Gameclear::Draw()
{
	m_img.Draw();
	

}