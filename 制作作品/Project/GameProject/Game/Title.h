#pragma once
#include "../Base/Base.h"

class Title : public Base
{
	//画像オブジェクト
	CImage m_img;
	CImage m_img2;
	CImage m_img3;
	CImage m_img4;
	//文字表示オブジェクト
	CFont m_title_text;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};


