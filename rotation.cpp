#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float angle, rad;
    int xr1, yr1, xr2, yr2;

    initgraph(&gd, &gm, NULL);
    printf("Rotation of a line \n");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    printf("Enter rotation angle (degrees): ");
    scanf("%f", &angle);

    rad = angle * PI / 180;

    xr1 = x1 * cos(rad) - y1 * sin(rad);
    yr1 = x1 * sin(rad) + y1 * cos(rad);

    xr2 = x2 * cos(rad) - y2 * sin(rad);
    yr2 = x2 * sin(rad) + y2 * cos(rad);

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Original Line");

    // Draw rotated line
    setcolor(RED);
    line(xr1, yr1, xr2, yr2);
    outtextxy(xr1, yr1 - 10, "Rotated Line");

    getch();
    closegraph();
    return 0;
}
