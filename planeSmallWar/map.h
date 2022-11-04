#ifndef MAP_H
#define MAP_H
#include<QPixmap>
#include<config.h>
class map
{
public:
    map();

    //地图滚动坐标计算
    void mapPosition();
    //地图对象
    QPixmap m_map1;
    QPixmap m_map2;

    //地图Y轴坐标
    int m_map_1_posY;
    int m_map_2_posY;

    //地图滚动速度
    int m_scroll_speed;
    bool playing=1;

};

#endif // MAP_H
