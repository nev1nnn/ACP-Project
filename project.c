#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 25
#define COLS 50

char canvas[ROWS][COLS];

/* Function Prototypes */
void initializeCanvas();
void displayCanvas();

void drawRectangle(int x, int y, int width, int height, char ch);
void drawLine(int x1, int y1, int x2, int y2, char ch);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, char ch);
void drawCircle(int xc, int yc, int r, char ch);

int main()
{
    int choice;

    initializeCanvas();

    do
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Picture\n");
        printf("6. Delete Rectangle Area\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,w,h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);
                drawRectangle(x,y,w,h,'*');
                break;
            }

            case 2:
            {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                drawLine(x1,y1,x2,y2,'*');
                break;
            }

            case 3:
            {
                int x1,y1,x2,y2,x3,y3;
                printf("Enter x1 y1 x2 y2 x3 y3: ");
                scanf("%d%d%d%d%d%d",
                      &x1,&y1,&x2,&y2,&x3,&y3);

                drawTriangle(x1,y1,x2,y2,x3,y3,'*');
                break;
            }

            case 4:
            {
                int xc,yc,r;
                printf("Enter center(x y) and radius: ");
                scanf("%d%d%d",&xc,&yc,&r);

                drawCircle(xc,yc,r,'*');
                break;
            }

            case 5:
                displayCanvas();
                break;

            case 6:
            {
                int x,y,w,h;
                printf("Enter x y width height to delete: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);
                drawRectangle(x,y,w,h,'_');
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}

/* Initialize canvas with '_' */
void initializeCanvas()
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

/* Display Picture */
void displayCanvas()
{
    int i,j;

    printf("\n");
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

/* Rectangle */
void drawRectangle(int x, int y, int width, int height, char ch)
{
    int i,j;

    for(i=y;i<y+height && i<ROWS;i++)
    {
        for(j=x;j<x+width && j<COLS;j++)
        {
            canvas[i][j]=ch;
        }
    }
}

/* Line using DDA Algorithm */
void drawLine(int x1, int y1, int x2, int y2, char ch)
{
    int x, y;
    if(y1 == y2)   /* Horizontal Line */
    {
        for(x = x1; x <= x2; x++)
        {
            canvas[y1][x] = ch;
        }
    }
    else if(x1 == x2)   /* Vertical Line */
    {
        for(y = y1; y <= y2; y++)
        {
            canvas[y][x1] = ch;
        }
    }
    else   /* Diagonal Line */
    {
        x = x1;
        y = y1;

        while(x <= x2 && y <= y2)
        {
            canvas[y][x] = ch;
            x++;
            y++;
        }
    }
}

/* Triangle */
void drawTriangle(int x1,int y1,
                  int x2,int y2,
                  int x3,int y3,
                  char ch)
{
    drawLine(x1,y1,x2,y2,ch);
    drawLine(x2,y2,x3,y3,ch);
    drawLine(x3,y3,x1,y1,ch);
}

/* Circle */
void drawCircle(int xc, int yc, int r, char ch)
{
    int x,y;

    for(y=0;y<ROWS;y++)
    {
        for(x=0;x<COLS;x++)
        {
            int dx=x-xc;
            int dy=y-yc;

            double dist=sqrt(dx*dx + dy*dy);

            if(fabs(dist-r) < 0.5)
            {
                canvas[y][x]=ch;
            }
        }
    }
}