#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int xc, yc, r, x = 0, y, p;

    printf("Enter center (xc, yc): ");
    scanf("%d%d", &xc, &yc);

    printf("Enter radius r: ");
    scanf("%d", &r);

    printf("Midpoint Circle Drawing Algorithm");

    initgraph(&gd, &gm, "");

    y = r;
    p = 1 - r;

    while (x <= y) {
        // Plot 8 symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}
