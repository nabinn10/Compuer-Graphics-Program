#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Car body
    rectangle(100, 200, 200, 230);         // Lower body
    rectangle(120, 180, 180, 200);         // Upper body (cabin)

    // Wheels
    circle(125, 240, 10);                  // Front wheel
    circle(175, 240, 10);                  // Rear wheel

    // Fill lower body
    setfillstyle(SOLID_FILL, RED);
    floodfill(101, 201, WHITE);

    // Fill cabin
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(121, 181, WHITE);

    // Fill wheels
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(125, 240, WHITE);
    floodfill(175, 240, WHITE);

    getch();
    closegraph();
    return 0;
}
