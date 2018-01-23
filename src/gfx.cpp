#include <gfx.h>

struct gfx_context
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    unsigned int width;
    unsigned int height;
    float aspect_ratio;
    float delta_time;
    unsigned long long last;

    gfx_context(const char *title, int w, int h, int x, int y, Uint32 flags)
    {
        SDL_Init(SDL_INIT_VIDEO);

        this->window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (!this->window)
        {
            delete this;
        }

        this->renderer = SDL_CreateRenderer(context->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (this->renderer)
        {
            SDL_DestroyWindow(context->window);
            delete this;
        }

        this->width = w;
        this->height = h;
        this->aspect_ratio = (float)w / (float)h;
        this->delta_time = 0;
        this->last = SDL_GetPerformanceCounter();
    }
    
    ~gfx_context()
    {
        SDL_Quit();
    }
};
