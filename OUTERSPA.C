#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void earthOnSpace()
{
  int x, y, earthRadius, earthCenterX, earthCenterY, stars, i;
  // Draw the Earth (a blue circle)
  earthRadius = 100;
  earthCenterX = 10;
  earthCenterY = 250;
  //printf("x = %d and y = %d", earthCenterX, earthCenterY);
  setcolor(BLUE);
  setfillstyle(SOLID_FILL, BLUE);
  fillellipse(earthCenterX, earthCenterY, earthRadius, earthRadius);

  setcolor(WHITE);
  setfillstyle(SOLID_FILL, WHITE);
  // Draw some continents
  // This is just a basic representation
  fillellipse(earthCenterX + 3, earthCenterY - 80, 40, 20); // north pole
  fillellipse(earthCenterX + 3, earthCenterY + 80, 40, 20); // south pole
  setcolor(GREEN);

  setfillstyle(SOLID_FILL, GREEN);
  // For continent of earthx
  fillellipse(earthCenterX + 50, earthCenterY + 10, 50, 20);
  fillellipse(earthCenterX + 50, earthCenterY + 10, 20, 40);
  fillellipse(earthCenterX + 10, earthCenterY + 10, 10, 20);
  fillellipse(earthCenterX + 70, earthCenterY - 50, 15, 5);

  setcolor(WHITE); // set drawing color to white
  // draw stars using random white pixels
  srand(time(NULL)); // initialize random seed
  for (i = 0; i < 500; i++)
  {
    x = rand() / 50;
    y = rand() / 80;
    // remove the stars from the earth
    if (y > earthCenterY - earthRadius && y < earthCenterY + earthRadius && x < earthCenterX + earthRadius)
    {
      x += earthCenterX + earthRadius;
    }
    //Draw stars
    putpixel(x, y, WHITE);
    //To make stars more visible
    if (x % 2 == 0)
      putpixel(x + 1, y, WHITE);
    else
      putpixel(x, y + 1, WHITE);
  }
}

void marsOnSpace()
{
int x, y, marsRadius, marsCenterX, marsCenterY, i;
  // Draw the Mars (a Red circle)
  marsRadius = 100;
  marsCenterX = 640;
  marsCenterY = 250;
  //printf("x = %d and y = %d", marsCenterX, marsCenterY);
  setcolor(RED);
  setfillstyle(SOLID_FILL, RED);
  fillellipse(marsCenterX, marsCenterY, marsRadius, marsRadius);

  // Draw the continents (just for demonstration)
  setcolor(WHITE);
  setfillstyle(SOLID_FILL, WHITE);
  // Draw poles
  fillellipse(marsCenterX+12, marsCenterY - 98, 40, 2); // north pole
  setcolor(BROWN);
  setfillstyle(SOLID_FILL,BROWN);
  fillellipse(marsCenterX + 4, marsCenterY - 93, 40, 4); // south pole
  setcolor(BROWN);
  setfillstyle(SOLID_FILL,BROWN);
  fillellipse(marsCenterX + 11, marsCenterY + 96, 40, 4); // south pole

  setcolor(WHITE); // set drawing color to white
  // draw stars using random white pixels
  srand(time(NULL)); // initialize random seed
  for (i = 0; i < 200; i++)
  {
    x = rand() / 50;
    y = rand() / 80;
    // remove the stars from the mars
    if (y > marsCenterY - marsRadius && y < marsCenterY + marsRadius && x > marsCenterX - marsRadius)
    {
      x += marsCenterX + marsRadius;
    }
    putpixel(x, y, WHITE);
    if (x % 2 == 0)
      putpixel(x + 1, y, WHITE);
    else
      putpixel(x, y + 1, WHITE);
  }
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  earthOnSpace();
  delay(1000);
  cleardevice();
  marsOnSpace();

  getch();
  closegraph();
  return 0;
}