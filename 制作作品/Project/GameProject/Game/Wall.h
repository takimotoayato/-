#pragma once
#include "../Base/Base.h"

class Wall : public Base {
private:
	//�摜�I�u�W�F�N�g�i�O�i�j
	CImage m_Wall;
	

public:
	/// �R���X�g���N�^
	Wall();
	/// �`��
	void Draw();

	
};
