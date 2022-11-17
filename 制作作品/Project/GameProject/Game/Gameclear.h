#pragma once
#include "../Base/Base.h"

class Gameclear :public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_Gameclear_text;
public:
	Gameclear();
	~Gameclear();
	void Update();
	void Draw();
};