#include "Sousahou.h"
#include "Title.h"
#include "Game.h"
Sousahou::Sousahou() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{

	m_img = COPY_RESOURCE("haikei1", CImage);

}

Sousahou::~Sousahou()
{
	////�S�ẴI�u�W�F�N�g��j��
	//Base::KillAll();
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	//Base::Add(new Game());
	Base::Add(new Title());


}

void Sousahou::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton3)) {
		m_kill = true;
	}

	//m_ang += 0.02f;


}

void Sousahou::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//�����\��
	m_title_text.Draw(680, 120, 0, 0, 0, "     ������@");
	m_title_text.Draw(64, 320, 0, 0, 0, "�X�y�[�X�L�[�ōU��");
	m_title_text.Draw(64, 520, 0, 0, 0, "Z�{�^���Ńg���b�v�ݒu");
	m_title_text.Draw(64, 920, 0, 0, 0, "C�{�^���Ń^�C�g����ʂ֖߂�");

}