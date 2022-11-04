#include "expload.h"
#include<qpixmap.h>
expload::expload()
{
	for (int i = 1; i <= BOMB_MAX; i++)
	{
		QString str = QString(BOMB_PATH).arg(i);
		m_pixArr.push_back(QPixmap(str));
	}
	//位置
	m_x = m_y = 0;
	
	//空闲状态
	m_free = true;

	//当前下标
	m_index = 0;

	//播放爆炸间隔记录
	m_Recorder = 0;
}

void expload::updateInfo()
{
	if (m_free)
	{
		return;
	}
	m_Recorder++;
	if (m_Recorder < BOMB_INTERVAL)
	{
		return;
	}
	//重置记录
	m_Recorder = 0;
	m_index++;
	if (m_index > BOMB_MAX - 1)
	{
		m_index = 0;
		m_free = true;
	}
}
