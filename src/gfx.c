#include <gfx.h>

gfx_context_t *gfx_init(const char *title, int w, int h, int x, int y, Uint32 flags)
{
    gfx_context_t *context = malloc(sizeof(gfx_context_t));
    if (!context)
        return NULL;

    SDL_Init(SDL_INIT_VIDEO);

    context->window = SDL_CreateWindow(title, x, y, w, h, flags);
    if (!context->window)
    {
        SDL_Quit();
        free(context);
        return NULL;
    }

    context->renderer = SDL_CreateRenderer(context->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!context->renderer)
    {
        SDL_DestroyWindow(context->window);
        SDL_Quit();
        free(context);
        return NULL;
    }

    context->width = w;
    context->height = h;
    context->aspect_ratio = (float)w / (float)h;
    context->delta_time = 0;
    context->last = SDL_GetPerformanceCounter();

    return context;
}

void gfx_put_pixel(gfx_context_t *context, int x, int y, gfx_color_t color)
{
    SDL_SetRenderDrawColor(context->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(context->renderer, x, y);
}

void gfx_update(gfx_context_t *context)
{
    SDL_RenderPresent(context->renderer);
    unsigned long long now = SDL_GetPerformanceCounter();
    context->delta_time = (float)(now - context->last) / SDL_GetPerformanceFrequency();
    context->last = now;
}

void gfx_clear(gfx_context_t *context, gfx_color_t color)
{
    SDL_SetRenderDrawColor(context->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(context->renderer);
}

void gfx_destroy(gfx_context_t *context)
{
    SDL_DestroyRenderer(context->renderer);
    SDL_DestroyWindow(context->window);
    SDL_Quit();
    free(context);
}
