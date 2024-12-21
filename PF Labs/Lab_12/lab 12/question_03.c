#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rectangle{
    int width;
    int height;
}rect;

void modifyRectangle(rect *r) {
    r->width *=  20;
    r->height *=  10;
}

int main() {  
    rect r;

    printf("\nEnter the width of the rectangle: ");
    scanf("%d", &r.width);
    printf("\nEnter the height of the rectangle: ");
    scanf("%d", &r.height);

    modifyRectangle( &r );

    printf("\nModified width: %d\n", r.width);
    printf("\nModified height: %d\n", r.height);
    return 0;
}
    