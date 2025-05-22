#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw base of the house
    rectangle(150, 200, 300, 350); // house body

    // Draw roof
    line(150, 200, 225, 130); // left roof
    line(225, 130, 300, 200); // right roof

    // Draw door
    rectangle(190, 275, 230, 350);

    // Draw left window
    rectangle(160, 220, 185, 245);

    // Draw right window
    rectangle(265, 220, 290, 245);

    getch();
    closegraph();
    return 0;
}