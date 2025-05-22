
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[3] = {200, 250, 300};
    int y[3] = {200, 150, 200};

    // Draw outline
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);

    int ymax = y[0], ymin = y[0];
    for (int i = 1; i < 3; i++) {
        if (y[i] > ymax) ymax = y[i];
        if (y[i] < ymin) ymin = y[i];
    }

    for (int scan = ymin; scan <= ymax; scan++) {
        int count = 0, xi[3];
        for (int i = 0; i < 3; i++) {
            int j = (i + 1) % 3;
            if ((y[i] <= scan && y[j] > scan) || (y[j] <= scan && y[i] > scan)) {
                xi[count++] = x[i] + (scan - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
            }
        }

        if (count == 2) {
            if (xi[0] > xi[1]) {
                int temp = xi[0]; xi[0] = xi[1]; xi[1] = temp;
            }
            for (int k = xi[0]; k <= xi[1]; k++) {
                putpixel(k, scan, GREEN);
            }
        }
    }

    outtextxy(10, 10, "Scanline Filled Triangle");
    getch();
    closegraph();
    return 0;
}
