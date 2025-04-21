
#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;
    float x, y, p1, p2;

    printf("Mid point Ellipse Drawing Algorithm \n");

    printf("Enter center (xc, yc): ");
    scanf("%d%d", &xc, &yc);

    printf("Enter x-radius (rx): ");
    scanf("%d", &rx);

    printf("Enter y-radius (ry): ");
    scanf("%d", &ry);

    initgraph(&gd, &gm, "");

    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    float dx = 2 * ry * ry * x;
    float dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy) {
        // 4-way symmetry
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        dx = dx + (2 * ry * ry);

        if (p1 < 0) {
            p1 = p1 + dx + (ry * ry);
        } else {
            y--;
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx - dy + (ry * ry);
        }
    }

    // Initial decision parameter of region 2
    p2 = ((ry * ry) * (x + 0.5) * (x + 0.5)) +
         ((rx * rx) * (y - 1) * (y - 1)) -
         (rx * rx * ry * ry);

    // Region 2
    while (y >= 0) {
        // 4-way symmetry
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        dy = dy - (2 * rx * rx);

        if (p2 > 0) {
            p2 = p2 + (rx * rx) - dy;
        } else {
            x++;
            dx = dx + (2 * ry * ry);
            p2 = p2 + dx - dy + (rx * rx);
        }
    }

    getch();
    closegraph();
    return 0;
}
