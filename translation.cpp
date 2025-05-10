#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, tx, ty;

    initgraph(&gd, &gm, NULL);

    printf("Translation of a line \n");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    printf("Enter translation factors (tx ty): ");
    scanf("%d%d", &tx, &ty);

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Original Line");

    // Draw translated line
    setcolor(RED);
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
    outtextxy(x1 + tx, y1 + ty - 10, "Translated Line");

    getch();
    closegraph();
    return 0;
}
