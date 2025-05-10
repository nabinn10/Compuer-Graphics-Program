#include <graphics.h>
#include <conio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    initgraph(&gd, &gm, NULL);
    printf("Reflection of a line \n");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Reflection about X-axis
    int x1_ref = x1;
    int y1_ref = -y1;
    int x2_ref = x2;
    int y2_ref = -y2;

    // Shift into visible screen
    int shiftX = 0;   // if needed
    int shiftY = 300; // shift downward so negative y becomes positive

    x1_ref += shiftX;
    y1_ref += shiftY;
    x2_ref += shiftX;
    y2_ref += shiftY;

    setcolor(RED);
    line(x1_ref, y1_ref, x2_ref, y2_ref);

    getch();
    closegraph();
    return 0;
}
