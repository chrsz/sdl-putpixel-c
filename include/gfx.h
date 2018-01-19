#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

typedef struct gfx_context
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    unsigned int width;
    unsigned int height;
    float aspect_ratio;
    float delta_time;
    unsigned long long last;
} gfx_context_t;

typedef struct gfx_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} gfx_color_t;

gfx_context_t *gfx_init(const char *, int, int, int, int, Uint32);
void gfx_put_pixel(gfx_context_t *, int, int, gfx_color_t);
void gfx_update(gfx_context_t *);
void gfx_clear(gfx_context_t *, gfx_color_t);
void gfx_destroy(gfx_context_t *);
