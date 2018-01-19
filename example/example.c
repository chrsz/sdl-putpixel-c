#include <gfx.h>

#define BLACK {0, 0, 0, 255}
#define RED {255, 0, 0, 255}
#define YELLOW {255, 255, 0, 255}
#define GREEN {0, 255, 0, 255}
#define BLUE {0, 0, 255, 255}

int main(int argc, char *argv[])
{
    int width = 1280;
    int height = 720;
    int half_width;
    int half_height;

    gfx_context_t *context = gfx_init("Example", width, height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_RESIZABLE);

    gfx_color_t black = BLACK;
    gfx_color_t red = RED;
    gfx_color_t yellow = YELLOW;
    gfx_color_t green = GREEN;
    gfx_color_t blue = BLUE;

    SDL_Event event;
    for (;;)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        SDL_GetWindowSize(context->window, &width, &height);
        half_width = width * 0.5f;
        half_height = height * 0.5f;

        gfx_clear(context, black);
        
        for (int i = 0; i < 100; i++)
        {
            gfx_put_pixel(context, half_width + i, half_height + i, red);
            gfx_put_pixel(context, half_width - i, half_height + i, yellow);
            gfx_put_pixel(context, half_width + i, half_height - i, green);
            gfx_put_pixel(context, half_width - i, half_height - i, blue);
        }
        
        gfx_update(context);
    }

    gfx_destroy(context);

    return 0;
}
