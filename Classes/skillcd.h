//////////////////////////////////////////////////////////////////////////
//����cd
//����ʱ��
//���ܱ���ͼ
//
//
//////////////////////////////////////////////////////////////////////////
#pragma once
#include "cocos2d.h"
//#include "cocos-ext.h"
#include "ui/CocosGUI.h" 
using namespace cocos2d;
using namespace ui;

class SkillCD : public Button
{
public:
	SkillCD();
	~SkillCD();
	CREATE_FUNC(SkillCD);
	void setSkillCDFile(std::string strFileName);
	void setSkillStart();
	void setSkillCD(int cd);
	void updateCD(float dt);
	bool getTouch(){return m_bTouch; }
private:
	float m_nSkillCDTime;//cdʱ��
	float m_nSkillCDTimeMax;
	ProgressTimer *m_pProgressTimer;
	bool m_bStartCD;
	bool m_bTouch;
};

