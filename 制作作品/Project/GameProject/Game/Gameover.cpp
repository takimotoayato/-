#include "Gameover.h"
#include "Game.h"
#include "Game2.h"
#include "Title.h"

Gameover::Gameover() :Base(eType_Gameclear), m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("�Q�[���I�[�o�[", CImage);

}

Gameover::~Gameover()
{

}

void Gameover::Update()
{
	//�{�^��5�ŉ�ʂ�j��
	if (PUSH(CInput::eButton5)) 
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[��
		Base::Add(new Title());
	}
}

void Gameover::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	m_Gameover_text.Draw(64, 950, 0, 0, 0, "�X�y�[�X�L�[�Ń^�C�g���ɖ߂�");
}