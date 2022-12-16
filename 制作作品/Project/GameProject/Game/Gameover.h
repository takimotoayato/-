#pragma once
#include "../Base/Base.h"

class Gameover :public Base 
{
	//画像オブジェクト
	CImage m_img;
	CImage m_img2;
	CImage m_img3;
	CImage m_img4;
	CImage m_img5;
	CImage m_img6;
	//文字表示オブジェクト
	CFont m_Gameover_text;
public:
	Gameover();
	~Gameover();
	void Update();
	void Draw();
};