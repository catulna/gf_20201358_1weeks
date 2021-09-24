#include "Game.h"



bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 74, 168, 216, 255);
      }
      else 
      {
        return false; 
      }
    }
    else 
    {
      return false;
    }
  }
  else{
    return false;
  }

  SDL_Surface* pTempSurFace = SDL_LoadBMP("Assets/rider.bmp");

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurFace);
  SDL_FreeSurface(pTempSurFace);

  SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
  m_sourceRectangle.x = 50;
  m_sourceRectangle.y = 50;

  m_destinationRectangle.w = m_sourceRectangle.w = 50;
  m_destinationRectangle.h = m_sourceRectangle.h = 50;



  m_destinationRectangle.x = 40;
  m_destinationRectangle.y = 40;
  
  m_bRunning =  true;
  return true;
}


void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}