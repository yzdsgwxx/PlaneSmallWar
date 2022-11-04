#include "map.h"

map::map()
{
    //初始化
    m_map1.load(MAP3_PATH);
    m_map2.load(MAP3_PATH);
    //初始化Y轴坐标
    m_map_1_posY = -GAME_HEIGHT;
    m_map_2_posY = 0;

    //设置滚动速度
    m_scroll_speed = SCROLL_SPEED;
}

void map::mapPosition()
{
  m_map_1_posY+=m_scroll_speed;
  m_map_2_posY+=m_scroll_speed;
  if(m_map_1_posY>=0)
  {
      m_map_1_posY=-GAME_HEIGHT;
  }
  if(m_map_2_posY>=GAME_HEIGHT)
  {
      m_map_2_posY=0;
  }

}
