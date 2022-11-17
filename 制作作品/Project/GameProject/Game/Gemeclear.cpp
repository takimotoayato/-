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
	//�{�^��5�ŃN���A��ʂ�j��
	if (PUSH(CInput::eButton5)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[��
		Base::Add(new Title());
	}
}

void Gameclear::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

}