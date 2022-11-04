#pragma once
#include<Qmovie>
#include<config.h>
class expload
{
public:
	expload();
	
	//
	void updateInfo();

public:

	//爆炸数组
	QVector<QPixmap> m_pixArr;

	//爆炸位置
	int m_x;
	int m_y;

	//爆炸状态
	bool m_free;
	
	//爆炸切图时间
	int m_Recorder;

	//爆炸时加载的图片下标
	int m_index;
};

