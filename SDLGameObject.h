#pragma once

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vecter2D.h"

class SDLGameObject : public GameObject {
  public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean() {}
    virtual ~SDLGameObject() {}

  protected:
    //int m_x;
    //int m_y;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;

    Vecter2D m_position;
    Vecter2D m_velocity;
    Vecter2D m_acceleration;

    std::string m_textureID;
};