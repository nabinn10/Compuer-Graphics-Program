#include <graphics.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    printf("Line Drawing Alforithm using line() function \n");

    printf("Enter x1, y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, ""); // Initialize graphics mode

    line(x1, y1, x2, y2);    // Draw line using built-in function

    getch();                 // Wait for key press
    closegraph();            // Close graphics mode
    return 0;
}
