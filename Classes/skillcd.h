//////////////////////////////////////////////////////////////////////////
//技能cd
//技能时间
//技能背景图
//
//
//////////////////////////////////////////////////////////////////////////
#pragma once
#include "cocos2d.h"
//#include "cocos-ext.h"
#include "ui/CocosGUI.h" 
using namespace cocos2d;
using namespace ui;

class SkillCD : public Layer
{
	DECLARE_CLASS_GUI_INFO
public:
	SkillCD();
	virtual ~SkillCD();
	CREATE_FUNC(SkillCD);
	void setSkillCDFile(std::string strFileName);
	void setSkillStart();
	void setSkillCD(int cd);
	
	bool getTouch(){return m_bTouch; }
private:
	void updateCD(float dt);
	float m_nSkillCDTime;//cd时间
	float m_nSkillCDTimeMax;
	ProgressTimer *m_pProgressTimer;
	bool m_bStartCD;
	bool m_bTouch;
};

