#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);

        printf("\n");
    }
}

void drawRectangle(int width, int height)
{
    int i, j;

    for(i = 2; i < 2 + height; i++)
        for(j = 2; j < 2 + width; j++)
            canvas[i][j] = '*';
}

void drawLine(int length)
{
    int j;

    for(j = 5; j < 5 + length; j++)
        canvas[10][j] = '*';
}

void drawTriangle(int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j <= i; j++)
        {
            canvas[2 + i][20 + j] = '*';
        }
    }
}

void drawCircle(int radius)
{
    int i, j;
    int centerX = 30;
    int centerY = 10;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            int dx = j - centerX;
            int dy = i - centerY;

            if(dx * dx + dy * dy <= radius * radius)
                canvas[i][j] = '*';
        }
    }
}

int main()
{
    int choice, value;

    initializeCanvas();

    do
    {
        printf("\n1. Rectangle\n");
        printf("2. Line\n");
        printf("3. Triangle\n");
        printf("4. Circle\n");
        printf("5. Display\n");
        printf("6. Clear Picture\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter width and height: ");
                scanf("%d%d", &value, &choice);
                drawRectangle(value, choice);
                break;

            case 2:
                printf("Enter line length: ");
                scanf("%d", &value);
                drawLine(value);
                break;

            case 3:
                printf("Enter triangle height: ");
                scanf("%d", &value);
                drawTriangle(value);
                break;

            case 4:
                printf("Enter radius: ");
                scanf("%d", &value);
                drawCircle(value);
                break;

            case 5:
                displayCanvas();
                break;

            case 6:
                initializeCanvas();
                break;
        }

    } while(choice != 0);

    return 0;
}