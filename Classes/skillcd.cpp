#include "skillcd.h"
SkillCD::SkillCD()
{
	m_nSkillCDTime = 0.f;
	m_nSkillCDTimeMax = 0.f;
	m_pProgressTimer = NULL;
	m_bStartCD = false;
	m_bTouch = false;
}

SkillCD::~SkillCD()
{
	m_pProgressTimer = NULL;
	this->unscheduleUpdate();
}

void SkillCD::setSkillCDFile(std::string strFileName)
{
	
	
	//设置第三章图片为cd旋转图片
	Sprite *pSprite = Sprite::create(strFileName.c_str());
	m_pProgressTimer = ProgressTimer::create(pSprite);
	m_pProgressTimer->setType(ProgressTimer::Type::RADIAL);
	m_pProgressTimer->setReverseProgress(true);
	m_pProgressTimer->setPercentage(100.f);
	m_pProgressTimer->setVisible(false);
	this->addChild(m_pProgressTimer);
	Button *pButton = dynamic_cast<Button*>(this->getParent());
	if (pButton)
	{
		m_pProgressTimer->setPosition(Vec2(pButton->getContentSize().width / 2, pButton->getContentSize().height/ 2));
	}
	
	//m_pProgressTimer->setAnchorPoint(Vec2::ZERO);
}
void SkillCD::setSkillCD(int cd)
{
	m_nSkillCDTime = cd;//cd时间
	m_nSkillCDTimeMax = cd;
}
void SkillCD::setSkillStart()
{
	if (!m_bStartCD)
	{
		m_bTouch = true;
		m_bStartCD = true;
		Button *pButton = dynamic_cast<Button*>(this->getParent());
		if (pButton)
		{
			pButton->setTouchEnabled(false);
		}
		if (m_pProgressTimer)
		{
			m_pProgressTimer->setVisible(true);
		}
		schedule(schedule_selector(SkillCD::updateCD));
	}
}

void SkillCD::updateCD(float dt)
{
	if (m_bStartCD)
	{
		if (m_pProgressTimer)
		{
			float fPercentage = m_pProgressTimer->getPercentage();
			m_nSkillCDTime -= dt;
			//CCLOG("%d", m_nSkillCDTime );
			m_pProgressTimer->setPercentage(m_nSkillCDTime * 100 / m_nSkillCDTimeMax);
			if (m_nSkillCDTime < 0)
			{
				Button *pButton = dynamic_cast<Button*>(this->getParent());
				if (pButton)
				{
					pButton->setTouchEnabled(true);
				}
				m_bStartCD = false;
				m_bTouch = false;
				m_nSkillCDTime = m_nSkillCDTimeMax;
				unschedule(schedule_selector(SkillCD::updateCD));
				m_pProgressTimer->setVisible(false);
				m_pProgressTimer->setPercentage(100.f);
			}
		}
		
	}
}
