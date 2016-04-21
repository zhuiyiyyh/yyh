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
}

void SkillCD::setSkillCDFile(std::string strFileName)
{
	
	
	//���õ�����ͼƬΪcd��תͼƬ
	Sprite *pSprite = Sprite::create(strFileName.c_str());
	m_pProgressTimer = ProgressTimer::create(pSprite);
	m_pProgressTimer->setType(ProgressTimer::Type::RADIAL);
	m_pProgressTimer->setReverseProgress(true);
	m_pProgressTimer->setPercentage(100.f);
	m_pProgressTimer->setVisible(false);
	this->addChild(m_pProgressTimer);
	m_pProgressTimer->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	m_pProgressTimer->setAnchorPoint(this->getAnchorPoint());
}
void SkillCD::setSkillCD(int cd)
{
	m_nSkillCDTime = cd;//cdʱ��
	m_nSkillCDTimeMax = cd;
}
void SkillCD::setSkillStart()
{
	if (!m_bStartCD)
	{
		m_bTouch = true;
		m_bStartCD = true;
		this->setTouchEnabled(false);
		m_pProgressTimer->setVisible(true);
		schedule(schedule_selector(SkillCD::updateCD));
	}
}

void SkillCD::updateCD(float dt)
{
	if (m_bStartCD)
	{
		float fPercentage = m_pProgressTimer->getPercentage();
		m_nSkillCDTime -= dt;
		//CCLOG("%d", m_nSkillCDTime );
		m_pProgressTimer->setPercentage(m_nSkillCDTime * 100 / m_nSkillCDTimeMax);
		if (m_nSkillCDTime < 0)
		{
			this->setTouchEnabled(true);
			m_bStartCD = false;
			m_bTouch = false;
			m_nSkillCDTime = m_nSkillCDTimeMax;
			unschedule(schedule_selector(SkillCD::updateCD));
			m_pProgressTimer->setVisible(false);
			m_pProgressTimer->setPercentage(100.f);
		}
	}
}
