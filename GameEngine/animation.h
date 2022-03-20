#pragma once
#include <SDL_image.h>
#include <string>
#include <map>
#include "renderer.h"

enum class FLIP { NONE, HORIZONTAL, VERTICAL, FLIP_SIZE };

const std::string IMAGE_PATH = "Assets\\Art\\";
const std::string IMAGE_FILETYPE = ".bmp";

class animation
{
public:
	animation();
	animation(renderer* _renderer, std::string _filename, bool _use_transparency = true);
	~animation();

	int get_width();
	int get_height();

	void next_frame();

	void set_frames(int _rows, int _columns, bool _loop = true);
	void set_frame_duration(int _ms);

	void draw(int _x, int _y, int _width, int _height, double _rotation = 0, FLIP _flip = FLIP::NONE);

private:
	SDL_Texture* m_p_bmp_texture{ nullptr };
	SDL_Renderer* m_p_renderer{ nullptr };

	int m_src_width{ 0 };
	int m_src_height{ 0 };

	int m_current_frame{ 0 }, m_max_frames{ 1 };
	int m_frame_width{ 0 }, m_FrameHeight{ 0 };

	int m_frame_rows{ 0 }, m_frame_columns{ 0 };

	int m_frame_duration{ 0 };
	int m_frame_start{ 0 };

	bool m_animated{ false };

	bool m_loop{ true };
};