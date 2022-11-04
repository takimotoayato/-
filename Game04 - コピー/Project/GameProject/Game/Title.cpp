#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("Title", CImage); 
	
}

Title::~Title()
{
	////�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	




	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Game());
	//Base::Add(new Title());


}

void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton5)) {
		m_kill = true;
	}

	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//�����\��
	m_title_text.Draw(64, 820, 0, 0, 0, "�X�y�[�X�L�[�ōU��");


}