#include "Boss.h"
#include "Bullet.h"
Boss::Boss(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(50, 50);
	//半径
	m_rad = 50;

}

void Boss::Update()
{
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b)
	{
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 180)
		{
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 10));
			m_cnt = 0;
		}
	}

}

void Boss::Collision(Base* b)
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

void Boss::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetSize(100, 100);
	m_img.Draw();
}