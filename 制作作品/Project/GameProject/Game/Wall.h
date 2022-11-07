#pragma once
#include "../Base/Base.h"

class Wall : public Base {
private:
	//画像オブジェクト（前景）
	CImage m_Wall;
	

public:
	/// コンストラクタ
	Wall();
	/// 描画
	void Draw();

	
};
