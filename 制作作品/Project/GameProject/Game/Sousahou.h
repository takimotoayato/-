#pragma once
#pragma once
#include "../Base/Base.h"

class Sousahou : public Base
{
	//�摜�I�u�W�F�N�g
	CImage m_img;
	CImage m_img2;
	CImage m_img3;
	CImage m_img4;
	CImage m_img5;
	CImage m_img6;

	//�����\���I�u�W�F�N�g
	CFont m_title_text;
public:
	Sousahou();
	~Sousahou();
	void Update();
	void Draw();
};