#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float shx, shy;
    int xs1, ys1, xs2, ys2;

    initgraph(&gd, &gm, NULL);
    printf("Shearing of a line \n");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    printf("Enter shearing factors (shx shy): ");
    scanf("%f%f", &shx, &shy);

    xs1 = x1 + shx * y1;
    ys1 = y1 + shy * x1;

    xs2 = x2 + shx * y2;
    ys2 = y2 + shy * x2;

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Original Line");

    // Draw sheared line
    setcolor(RED);
    line(xs1, ys1, xs2, ys2);
    outtextxy(xs1, ys1 - 10, "Sheared Line");

    getch();
    closegraph();
    return 0;
}
