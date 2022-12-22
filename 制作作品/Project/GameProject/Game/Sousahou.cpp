#include "Sousahou.h"
#include "Title.h"
#include "Game.h"
Sousahou::Sousahou() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{

	m_img = COPY_RESOURCE("haikei1", CImage);
	m_img2 = COPY_RESOURCE("上下左右矢印キー", CImage);
	m_img3 = COPY_RESOURCE("space", CImage);
	//m_img4 = COPY_RESOURCE("Z", CImage);
	m_img4 = COPY_RESOURCE("Zキー", CImage);
	//m_img5 = COPY_RESOURCE("C", CImage);
	m_img5 = COPY_RESOURCE("Cキー", CImage);
	
	

}

Sousahou::~Sousahou()
{
	
	


}

void Sousahou::Update()
{
	//ボタン3でタイトル破棄
	if (PUSH(CInput::eButton3)) 
	{
		m_kill = true;
	Base::Add(new Title());
	}



}

void Sousahou::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//矢印キー出力
	m_img2.Draw();
	m_img2.SetSize(200, 200);
	m_img2.SetCenter(100, 100);
	m_img2.SetPos(800, 300);
	//矢印キー出力
	m_img3.Draw();
	m_img3.SetSize(400, 200);
	m_img3.SetCenter(200, 100);
	m_img3.SetPos(1000, 500);
	//Zキー出力
	m_img4.Draw();
	m_img4.SetSize(100, 100);
	m_img4.SetCenter(50, 50);
	m_img4.SetPos(800, 700);
	//Zキー出力
	m_img5.Draw();
	m_img5.SetSize(100, 100);
	m_img5.SetCenter(50, 50);
	m_img5.SetPos(990, 900);
	//文字表示
	m_title_text.Draw(680, 120, 0, 0, 0, "     操作方法");
	m_title_text.Draw(64, 320, 0, 0, 0, "↑↓→←キーで移動");
	m_title_text.Draw(64, 520, 0, 0, 0, "スペースキーで弾の発射");
	m_title_text.Draw(64, 720, 0, 0, 0, "Zキーでトラップ設置");
	m_title_text.Draw(64, 920, 0, 0, 0, "Cキーでタイトル画面へ戻る");

}