    #include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, sx, sy;

    initgraph(&gd, &gm, NULL);
    printf("Scalling of a line \n");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    printf("Enter scaling factors (sx sy): ");
    scanf("%d%d", &sx, &sy);

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Original Line");

    // Draw scaled line
    setcolor(RED);
    line(x1 * sx, y1 * sy, x2 * sx, y2 * sy);
    outtextxy(x1 * sx, y1 * sy - 10, "Scaled Line");

    getch();
    closegraph();
    return 0;
}
