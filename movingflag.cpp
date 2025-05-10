#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>

#define PI 3.14159265

// Wave parameters
float amplitude = 5;
float frequency = 0.1;

int waveY(int y, int xOffset, int t) {
    return y + (int)(amplitude * sin(frequency * y + t + xOffset * 0.05));
}

void drawWavingNepalFlag(int xOffset, int t) {
    cleardevice();
    setbkcolor(WHITE);

    int baseX = xOffset + 100;
    int baseY = 100;

    int height1 = 150;
    int height2 = 300;
    int width = 130;

    // Draw top triangle
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, 3);
    for (int i = 0; i <= width; i++) {
        int x1 = baseX;
        int y1 = waveY(baseY, i, t);

        int x2 = baseX;
        int y2 = waveY(baseY + height1, i, t);

        int x3 = baseX + i;
        int y3 = waveY(baseY + height1 - (height1 * i / width), i, t);

        putpixel(x3, y3, BLUE);
    }

    // Draw bottom triangle
    for (int i = 0; i <= width; i++) {
        int x1 = baseX;
        int y1 = waveY(baseY + height1, i, t);

        int x2 = baseX;
        int y2 = waveY(baseY + height2, i, t);

        int x3 = baseX + i;
        int y3 = waveY(baseY + height2 - (height1 * i / width), i, t);

        putpixel(x3, y3, BLUE);
    }

    // Fill with red
    setfillstyle(SOLID_FILL, RED);
    floodfill(baseX + 10, baseY + 10, BLUE);
    floodfill(baseX + 10, baseY + height1 + 10, BLUE);

    // Draw white crescent moon
    int moonX = baseX + 40;
    int moonY = waveY(baseY + 50, 0, t);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(moonX, moonY, 15, 15);  // outer
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(moonX, moonY - 5, 15, 15);  // inner to cut

    // Draw white sun with rays
    int sunX = baseX + 45;
    int sunY = waveY(baseY + height1 + 80, 0, t);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(sunX, sunY, 15, 15);  // sun core
    for (int i = 0; i < 12; ++i) {
        int angle = i * 30;
        int dx = 20 * cos(angle * PI / 180);
        int dy = 20 * sin(angle * PI / 180);
        line(sunX, sunY, sunX + dx, sunY + dy);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int t = 0;

    while (!kbhit()) {
        drawWavingNepalFlag(50, t);
        delay(50);
        t += 1;
    }

    getch();
    closegraph();
    return 0;
}
