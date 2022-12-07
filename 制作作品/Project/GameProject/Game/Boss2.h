#pragma once
#include "../Base/Base.h"

class Boss2 : public Base
{
private:
	CImage m_img;
	int m_cnt;
public:
	Boss2(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};