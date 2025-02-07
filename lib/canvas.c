#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_CIRCLES 40

/*
typedef struct Position
{
    int x;
    int y;

} Position;

typedef struct Color
{
    int red;
    int green;
    int blue;
} Color;

Color random_color()
{
    Color tmp = {
        .red = rand() % 255, .green = rand() % 255, .blue = rand() % 255};

    return tmp;
}

typedef struct Circle
{
    Position position;
    int radius;
    Color color;

} Circle;

Circle random_circle()
{
    Circle tmp;
    tmp.radius = rand() % 50;
    tmp.position.x = rand() % 1000 + tmp.radius;
    tmp.position.y = rand() % 1000 + tmp.radius;
    tmp.color = random_color();

    return tmp;
}
*/

typedef struct Circle
{
    int x;  // position x
    int y;  // position y
    int r;  // radius
    int cr; // color r
    int cg; // color g
    int cb; // color b
} Circle;

typedef struct CircleAnimationData
{
    int x;  // position x
    int y;  // position y
    int r;  // radius
    int vx; // velocity x
    int vy; // velocity y
    int dx; // direction x (1 = forward)
    int dy; // direction y (1 = forward)

} CircleAnimationData;

Circle random_circle()
{
    Circle tmp;
    tmp.r = rand() % 50;
    tmp.x = rand() % 1000 + tmp.r;
    tmp.y = rand() % 1000 + tmp.r;
    tmp.cr = rand() % 255;
    tmp.cg = rand() % 255;
    tmp.cb = rand() % 255;

    return tmp;
}

Circle circles[NUMBER_OF_CIRCLES];
CircleAnimationData animation_data[NUMBER_OF_CIRCLES];

Circle *get_circles(int canvas_width, int canvas_height)
{
    // update animation
    for (int i = 0; i < NUMBER_OF_CIRCLES; ++i)
    {
        // collision
        if ((animation_data[i].x + animation_data[i].r) >= canvas_width)
        {
            animation_data[i].dx = 0;
        }

        if ((animation_data[i].x - animation_data[i].r) <= 0)
        {
            animation_data[i].dx = 1;
        }

        if ((animation_data[i].y + animation_data[i].r) >= canvas_height)
        {
            animation_data[i].dy = 0;
        }

        if ((animation_data[i].y - animation_data[i].r) <= 0)
        {
            animation_data[i].dy = 1;
        }

        // update position
        if (animation_data[i].dx == 1)
        {
            animation_data[i].x += animation_data[i].vx;
        }
        else
        {
            animation_data[i].x -= animation_data[i].vx;
        }

        if (animation_data[i].dy == 1)
        {
            animation_data[i].y += animation_data[i].vy;
        }
        else
        {
            animation_data[i].y -= animation_data[i].vy;
        }

        // update circles
        circles[i].x = animation_data[i].x;
        circles[i].y = animation_data[i].y;
    }

    return circles;
}

int main()
{
    printf("init circles\n");

    srand(time(NULL));

    // create circles
    for (int i = 0; i < NUMBER_OF_CIRCLES; ++i)
    {
        int r = rand() % 50;
        int x = rand() % 1000 + r;
        int y = rand() % 1000 + r;
        int cr = rand() % 255;
        int cg = rand() % 255;
        int cb = rand() % 255;

        // circle
        circles[i].x = x;
        circles[i].y = y;
        circles[i].r = r;
        circles[i].cr = cr;
        circles[i].cg = cg;
        circles[i].cb = cb;

        // circle animation
        animation_data[i].x = x;
        animation_data[i].y = y;
        animation_data[i].r = r;
        animation_data[i].vx = rand() % 10;
        animation_data[i].vy = rand() % 10;
        animation_data[i].dx = 1;
        animation_data[i].dy = 1;
    }

    /* emscripten_run_script("render()"); */
    EM_ASM(
        { render($0, $1); }, NUMBER_OF_CIRCLES * 6,
        6); // Circle struct consist of 6 ints
    return 0;
}
