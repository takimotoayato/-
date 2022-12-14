#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("�E�C���X", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//���a
	m_rad = 16;
	//��`��ݒ�
	m_rect = CRect(-16, -16, 16, 16);

}

void Enemy::Update()
{

	//�G�����ɓ�����
	const int move_speed = 12;
	//�J�E���g�A�b�v
	m_cnt++;
	//60�J�E���g(1�b)�ȏ�Ȃ�
	/*if (m_cnt >= 60)
	{
		
	}*/

	//�J�E���g�A�b�v
	m_cnt++;
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�v���C���[�������
	if (b) 
	{
		//�^�[�Q�b�g�ւ̃x�N�g��
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 100)
		{
		//�ړ�
		//m_pos.x += move_speed;
		m_pos.y += move_speed;
		//m_pos.x -= move_speed;
		//m_pos.y -= move_speed;
		//�J�E���^�[���Z�b�g
		m_cnt = 0;

			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 1));
			m_cnt = 0;
		}
	}

}

void Enemy::Collision(Base* b)
{
	switch (b->m_type) 
	{
	
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
		}
		break;
	


	}
	

}

void Enemy::Draw() 
{
	m_img.SetPos(m_pos);
	m_img.SetSize(32, 32);
	m_img.Draw();


	



}