#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Head
    circle(250, 100, 50); // center at (250,100) with radius 50

    // Eyes
    circle(235, 85, 5);   // left eye
    circle(265, 85, 5);   // right eye

    // Smile
    arc(250, 105, 200, 340, 25); // smile arc

    // Body
    line(250, 150, 250, 300);

    // Arms
    line(180, 200, 320, 200);

    // Legs
    line(250, 300, 200, 400); // left leg
    line(250, 300, 300, 400); // right leg

    getch(); // Wait for a key press
    closegraph();
    return 0;
}
