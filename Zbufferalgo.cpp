
#include <graphics.h>
#include <conio.h>

#define WIDTH 640
#define HEIGHT 480

float zbuffer[WIDTH][HEIGHT];

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Initialize z-buffer with far depth
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            zbuffer[x][y] = 9999.0;

    // Rectangle 1 (Red) at z = 5
    for (int x = 100; x <= 300; x++) {
        for (int y = 100; y <= 300; y++) {
            if (5 < zbuffer[x][y]) {
                putpixel(x, y, RED);
                zbuffer[x][y] = 5;
            }
        }
    }

    // Rectangle 2 (Green) at z = 3 (closer)
    for (int x = 150; x <= 350; x++) {
        for (int y = 150; y <= 350; y++) {
            if (3 < zbuffer[x][y]) {
                putpixel(x, y, GREEN);
                zbuffer[x][y] = 3;
            }
        }
    }

    outtextxy(10, 10, "Z-Buffer: Green overlaps red because it's closer (z=3 < z=5)");
    getch();
    closegraph();
    return 0;
}
