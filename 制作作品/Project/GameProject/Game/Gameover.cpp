#include "Gameover.h"
#include "Game.h"
#include "Game2.h"
#include "Title.h"

Gameover::Gameover() :Base(eType_Gameclear), m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("�Q�[���I�[�o�[", CImage);
	m_img2 = COPY_RESOURCE("�E�C���X", CImage);
}

Gameover::~Gameover()
{

}

void Gameover::Update()
{
	//��]
	m_ang += 0.02f;

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
	//�E�C���X�o��
	m_img2.Draw();
	//�傫���ݒ�
	m_img2.SetSize(100, 100);
	//���W�ݒ�
	m_img2.SetPos(1000, 300);
	//��]
	m_img2.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img2.SetCenter(50, 50);


	//�E�C���X�o��
	m_img2.Draw();
	//�傫���ݒ�
	m_img2.SetSize(100, 100);
	//���W�ݒ�
	m_img2.SetPos(200, 800);
	//��]
	m_img2.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img2.SetCenter(50, 50);

}