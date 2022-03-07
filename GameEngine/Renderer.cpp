#include "renderer.h"

renderer::renderer(SDL_Window* m_Window)
{
    m_renderer = SDL_CreateRenderer(
		m_Window, -1, 0);

	if (nullptr == m_renderer)
	{
		std::cout << "Window initialisation failed: " << SDL_GetError() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		_getch();
	}
}

renderer::~renderer()
{
    if (nullptr != m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void renderer::Update()
{
    if (nullptr == m_renderer) return;
	
	SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);

}

SDL_Renderer* renderer::GetRenderer()
{
	return m_renderer;
}

//void renderer::Render(text _text)
//{
//	_text.draw();
//}
//
//void renderer::Render(slider _slider)
//{
//	_slider.draw();
//}
//
//void renderer::Render(image _image)
//{
//	_image.draw();
//}
//
//void renderer::Render(hotbar _hotbar)
//{
//	_hotbar.draw();
//}
//
//void renderer::Render(button _button)
//{
//	_button.draw();
//}