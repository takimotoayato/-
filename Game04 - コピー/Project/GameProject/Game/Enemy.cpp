#include "Enemy.h"
#include "Bullet.h"
Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(32, 32);
	//���a
	m_rad = 32;

}
void Enemy::Update()
{
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
		if (m_cnt >= 120)
		{
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 1));
			m_cnt = 0;
		}
	}

}
void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
		}
		break;


	}

}
/*
void Enemy::StateIdle()
{
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);

}
*/

void Enemy::Draw() 
{
	m_img.SetPos(m_pos);
	m_img.SetSize(32, 32);
	m_img.Draw();


	



}