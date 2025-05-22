#include <graphics.h>
#include <conio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmin = 100, ymin = 100, xmax = 300, ymax = 200;
    int x1 = 50, y1 = 120, x2 = 350, y2 = 180;
    float x, y;
    int code1 = 0, code2 = 0, code_out, accept = 0;

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Region codes
    if (x1 < xmin) code1 |= LEFT;
    if (x1 > xmax) code1 |= RIGHT;
    if (y1 < ymin) code1 |= BOTTOM;
    if (y1 > ymax) code1 |= TOP;

    if (x2 < xmin) code2 |= LEFT;
    if (x2 > xmax) code2 |= RIGHT;
    if (y2 < ymin) code2 |= BOTTOM;
    if (y2 > ymax) code2 |= TOP;

    while (1) {
        if ((code1 | code2) == 0) {
            accept = 1;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (float)(y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (float)(y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (float)(x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (float)(x2 - x1);
                x = xmin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = 0;
                if (x1 < xmin) code1 |= LEFT;
                if (x1 > xmax) code1 |= RIGHT;
                if (y1 < ymin) code1 |= BOTTOM;
                if (y1 > ymax) code1 |= TOP;
            } else {
                x2 = x;
                y2 = y;
                code2 = 0;
                if (x2 < xmin) code2 |= LEFT;
                if (x2 > xmax) code2 |= RIGHT;
                if (y2 < ymin) code2 |= BOTTOM;
                if (y2 > ymax) code2 |= TOP;
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);  // Only draw the clipped part
    }

    outtextxy(10, getmaxy() - 20, "Only clipped line is shown.");
    getch();
    closegraph();
    return 0;
}
