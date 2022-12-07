#pragma once
#pragma once
#include "../Base/Base.h"

class Sousahou : public Base
{
	//画像オブジェクト
	CImage m_img;


	//文字表示オブジェクト
	CFont m_title_text;
public:
	Sousahou();
	~Sousahou();
	void Update();
	void Draw();
};