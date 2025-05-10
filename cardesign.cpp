#include <graphics.h>
#include <conio.h>
#include <dos.h>  // for delay()

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for (int x = 0; x < getmaxx() - 100; x += 5) {
        cleardevice();

        // Draw car body
        rectangle(x, 200, x + 100, 230);         // lower body
        rectangle(x + 20, 180, x + 80, 200);     // upper body (cabin)

        // Draw wheels
        circle(x + 25, 240, 10);                 // front wheel
        circle(x + 75, 240, 10);                 // rear wheel

        // Fill body
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + 1, 201, WHITE);

        // Fill cabin
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(x + 21, 181, WHITE);

        // Fill wheels
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(x + 25, 240, WHITE);
        floodfill(x + 75, 240, WHITE);

        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
