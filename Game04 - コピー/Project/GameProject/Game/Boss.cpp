#include "Boss.h"
#include "Bullet.h"
Boss::Boss(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(100, 100);
	//���a
	m_rad = 100;

}
void Boss::Update()
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
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 8));
			m_cnt = 0;
		}
	}

}
void Boss::Collision(Base* b)
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
void Boss::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetSize(100, 100);
	m_img.Draw();
}