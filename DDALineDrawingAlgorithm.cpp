#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, i;
    float dx, dy, steps, x, y, x_inc, y_inc;

    printf("Enter x1, y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d%d", &x2, &y2);

    printf("DDA Algorithm");

    initgraph(&gd, &gm, "");

    dx = x2 - x1;
    dy = y2 - y1;

    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }

    getch();
    closegraph();
    return 0;
}
