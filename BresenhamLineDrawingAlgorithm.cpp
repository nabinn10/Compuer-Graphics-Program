#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, p, x, y;

    printf("Enter x1, y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d%d", &x2, &y2);

    printf("Bresenham’s Line Drawing Algorithm");

    initgraph(&gd, &gm, "");

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x <= x2) {
        putpixel(x, y, WHITE);
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * (dy - dx);
        }
    }

    getch();
    closegraph();
    return 0;
}
