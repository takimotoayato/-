#include "Boss.h"
#include "Bullet.h"
Boss::Boss(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(100, 100);
	//半径
	m_rad = 100;

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