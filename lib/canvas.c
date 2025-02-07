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
    int x;
    int y;
    int r;
    int cr;
    int cg;
    int cb;

} Circle;

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

Circle *get_circles() { return circles; }

int main()
{
    printf("init circles\n");

    srand(time(NULL));

    // create circles
    for (int i = 0; i < NUMBER_OF_CIRCLES; ++i)
    {
        circles[i] = random_circle();
    }

    /* emscripten_run_script("render()"); */
    EM_ASM(
        { render($0, $1); }, NUMBER_OF_CIRCLES * 6,
        6); // Circle struct consist of 6 ints
    return 0;
}
