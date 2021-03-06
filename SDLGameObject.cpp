#include "SDLGameObject.h"
#include "Game.h"


SDLGameObject::SDLGameObject(const LoaderParams* pParams)
:GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0, 0){
  //m_x = pParams->getX();
  //m_y = pParams->getY();
  m_width = pParams->getwidth();
  m_height = pParams->getheight();
  m_textureID = pParams->gettextureID();
  m_currentRow = 0;
  m_currentFrame = 0; 
}

void SDLGameObject::update(){
  
  //m_position.setX(m_position.getX() + 1);
  //m_position.setY(m_position.getY() + 1); 
  m_velocity += m_acceleration;
  m_position += m_velocity;

}

void SDLGameObject::draw(){
  TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

