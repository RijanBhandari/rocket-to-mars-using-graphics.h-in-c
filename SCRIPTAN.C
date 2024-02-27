#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define TURBOC_GRAPHICS
#define BGI "C:\\turboc3\\bgi"


void earthOnSpace(int *rx, int *ry)
{
  int x, y, earthRadius, earthCenterX, earthCenterY, stars, i;
  // Draw the Earth (a blue circle)
  earthRadius = 100;
  earthCenterX = 10;
  earthCenterY = 250;
  // printf("x = %d and y = %d", earthCenterX, earthCenterY);
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

  for (i = 0; i < 500; i++)
  {
    x = rx[i] / 50;
    y = ry[i] / 80;

    // remove the stars from the earth
    if (y > earthCenterY - earthRadius && y < earthCenterY + earthRadius && x < earthCenterX + earthRadius)
    {
      x += earthCenterX + earthRadius;
    }
    // Draw stars
    putpixel(x, y, WHITE);
    // To make stars more visible
    if (x % 2 == 0)
      putpixel(x + 1, y, WHITE);
    else
      putpixel(x, y + 1, WHITE);
  }
}

void marsOnSpace(int *rx, int *ry)
{
  int x, y, marsRadius, marsCenterX, marsCenterY, i;
  // Draw the Mars (a Red circle)
  marsRadius = 100;
  marsCenterX = 640;
  marsCenterY = 250;
  // printf("x = %d and y = %d", marsCenterX, marsCenterY);
  setcolor(RED);
  setfillstyle(SOLID_FILL, RED);
  fillellipse(marsCenterX, marsCenterY, marsRadius, marsRadius);

  // Draw the continents (just for demonstration)
  setcolor(WHITE);
  setfillstyle(SOLID_FILL, WHITE);
  // Draw poles
  fillellipse(marsCenterX + 12, marsCenterY - 98, 40, 2); // north pole
  setcolor(BROWN);
  setfillstyle(SOLID_FILL, BROWN);
  fillellipse(marsCenterX + 4, marsCenterY - 93, 40, 4); // south pole
  setcolor(BROWN);
  setfillstyle(SOLID_FILL, BROWN);
  fillellipse(marsCenterX + 11, marsCenterY + 96, 40, 4); // south pole

  setcolor(WHITE); // set drawing color to white
  // draw stars using random white pixels
  for (i = 0; i < 200; i++)
  {
    x = rx[i] / 50;
    y = ry[i] / 80;
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

void typeOnScreen(char *sc,int xpos, int ypos)
{
  int i;
  int text;
  if(ypos == 0)
  cleardevice();
  for (i = 0; i < strlen(sc); i++)
  {
    text = sc[i];
    outtextxy(200+xpos + i * 10, 239+ypos, &text);
    delay(100);
  }
}

void countDown()
{
  int i;
  char count[] = "9 8 7 6 5 4 3 2 1";
  char text[2];
  for (i = 0; i < strlen(count); i++)
  {
    text[0] = count[i];
    text[1] = '\0';
    delay(500);
    cleardevice();
    outtextxy(319, 239, &text);
  }
}

void script(int control)
{
       char sc1[] = "Hello fellow adventurer",
       sc2[] = "Let's go to mars",
       sc3[] = "Mission Successful",
       sc4[] = "Animation Project by",
       sc5[] = "Rijan Bhandari",
       sc6[] = "and",
       sc7[] = "Vinam Kumar Shrestha";

  if (control == 1)
{

  typeOnScreen(sc1,0,0);
  delay(100);
  typeOnScreen(sc2,20,0);
  delay(100);
  countDown();
  }
  else
  {
    typeOnScreen(sc3,4,-120);
    delay(100);
    typeOnScreen(sc4,4,-100);
    delay(100);
    typeOnScreen(sc5,4,-80);
    delay(100);
    typeOnScreen(sc6,4,-65);
    delay(100);
    typeOnScreen(sc7,4,-50);
  }

}

void rocket(int x, int y, int rl)
{
  int i, fireEffect;
  setcolor(YELLOW);

  for (i = 0; i < 12; i++)
  {
    fireEffect = i / 3;
    line(x, y + 10 + i, x + 85, y + 10); // upper triangle
    line(x, y + 10 - i, x + 85, y + 10); // lower triangle
    fireEffect = -fireEffect;
  }
  // booster brown sceal
  setcolor(BROWN);
  for (i = 0; i < 11; i++)
  {
    line(x + 42, y + 10 + i, x + 85, y + 10); // upper triangle
    line(x + 42, y + 10 - i, x + 85, y + 10); // lower triangle
  }
  // rocket fin
  setcolor(WHITE);
  for (i = 0; i < 21; i++)
  {
    line(x + 59, y + 10 + i, x + 130, y + 10); // upper triangle
    line(x + 59, y + 10 - i, x + 130, y + 10); // lower triangle
  }

  // Set the rocket's color
  setcolor(WHITE);

  // Draw the rocket
  for (i = 0; i < 40; i++)
  {
    if (i < 21)
      line(x + 50, y + i, x + rl, y + i); // body

    ellipse(x + 150 - i, y + 10, 270, 90, 40, 10); // head
  }
}

void randomFun(int *rx[], int *ry[])
{
  int i;
  srand(time(NULL)); // initialize random seed
  for (i = 0; i < 500; i++)
  {
    rx[i] = rand();
    ry[i] = rand();
  }
}
void motion(int x, int y, int rl, int move, int choice, int *rx, int *ry)
{
  int x1 = x;
  while (1)
  {
    // Move the rocket and fire to the right

    x1 = x1 + 4;
    move++;
    // Clear the previous position of the rocket and fire
    cleardevice();

    rocket(x1, y, rl);
    if (move < 130 && choice == 1)
    {
      earthOnSpace(rx, ry);
    }
    else if (move < 60 && choice == 0)
    {
      marsOnSpace(rx, ry);
    }
    else
    {
      return;
    }
    delay(50);
  }
}


void drawRocket(float scaleFactor, int x, int y,int control)
{
  int i;
  x = x + 29;
  y = y + 50;

  // main rocket base
  y = y - 2;
  setcolor(DARKGRAY);
  for (i = 0; i < 16; i++)
  {
    line(x, y, x + i, y + 20); // upper triangle
    line(x, y, x - i, y + 20); // lower triangle
  }

  x = x - 27;
 if(control ==1){
  // left booster base
  for (i = 0; i < 12; i++)
  {
    line(x, y, x + i, y + 20); // upper triangle
    line(x, y, x - i, y + 20); // lower triangle
  }
  }
  x = x + 27 + 27;
  if (control ==1){
  // right booster base
  for (i = 0; i < 12; i++)
  {
    line(x, y, x + i, y + 20); // upper triangle
    line(x, y, x - i, y + 20); // lower triangle
  }
  }
  setcolor(WHITE);
  x = x - 55;
  y = y - 170;
  // main rocket
  // rocket fin
  for (i = 0; i < 30; i++)
  {
    line(x + 29, y + 140, x + 29 + i, y + 170); // upper triangle
    line(x + 29, y + 140, x + 29 - i, y + 170); // lower triangle
  }
  // body
  for (i = 0; i < 180; i++)
  {
    line(x + 16, y + i, x + 40, y + i);
  }
  // head
  for (i = 0; i < 30; i++)
  {
    ellipse(x + 28, y + 15 - i, 0, 180, 12 * scaleFactor, 12 * scaleFactor);
  }
  if (control == 1)
  {
  // leftbooster body
  for (i = 0; i < 135; i++)
  {
    line(x - 9, y + 45 + i, x + 13, y + 45 + i);
  }

  for (i = 0; i < 30; i++)
  {
    ellipse(x + 2, y + 60 - i, 0, 180, 11 * scaleFactor, 11 * scaleFactor);
  }

  // Rightbooster body
  for (i = 0; i < 135; i++)
  {
    line(x + 43, y + 45 + i, x + 65, y + 45 + i);
  }

  for (i = 0; i < 30; i++)
  {
    ellipse(x + 54, y + 60 - i, 0, 180, 11 * scaleFactor, 11 * scaleFactor);
  }
  }
}

void drawFlames(float scaleFactor, int x, int y, int control)
{
  // Body flames
  y = y + 55;
  setcolor(14);
  setfillstyle(1, 14);
  circle(x + 28, y + 28, 17 * scaleFactor);
  floodfill(x + 28, y + 28, 14);
  circle(x + 28, y + 50, 11 * scaleFactor);
  floodfill(x + 28, y + 50, 14);
  circle(x + 28, y + 65, 8 * scaleFactor);
  floodfill(x + 28, y + 65, 14);
  if (control == 1)
  {
  // Booster 1 flames
  circle(x + 2, y + 24, 14 * scaleFactor);
  floodfill(x + 2, y + 24, 14);
  circle(x + 2, y + 40, 11 * scaleFactor);
  floodfill(x + 2, y + 40, 14);
  circle(x + 2, y + 55, 8 * scaleFactor);
  floodfill(x + 2, y + 55, 14);

  // Booster 2 flames
  circle(x + 55, y + 24, 14 * scaleFactor);
  floodfill(x + 55, y + 24, 14);
  circle(x + 55, y + 40, 11 * scaleFactor);
  floodfill(x + 55, y + 40, 14);
  circle(x + 55, y + 55, 8 * scaleFactor);
  floodfill(x + 55, y + 55, 14);
  }

}

void drawScene(float scaleFactor, int x, int y,int control)
{ if (control == 1)
  // Background
  {setfillstyle(SOLID_FILL, LIGHTCYAN);
  floodfill(50, 50, LIGHTCYAN);

  setcolor(GREEN);
  setfillstyle(SOLID_FILL, GREEN);
  rectangle(0, 420, 650, 500);
  floodfill(325, 460, WHITE);

  }

  else
  {
    setfillstyle(SOLID_FILL, RED);
    floodfill(50, 50, RED);

      setcolor(BROWN);
  setfillstyle(SOLID_FILL, BROWN);
  rectangle(0, 420, 650, 500);
  floodfill(325, 460, WHITE);
  }
  if (control != 2)
  // Draw Flames
  drawFlames(scaleFactor, x, y,control);

  // Draw Rocket
  drawRocket(scaleFactor, x, y,control);
}

int main()
{
  // Initialize the graphics system
  int gd = DETECT, gm, move = 0;
  int xo, yo, rl, rx[501], ry[501], x, y,i;
  initgraph(&gd, &gm, "c:\\TurboC3\\BGI");
  x = 300, y = 300;

  script(1);

  setbkcolor(LIGHTCYAN);
  // Initial scene
  drawScene(1, x, y,1);

  // Animation
  for (i = 1; i <= 330; i += 10)
  {

    drawScene(1.0, x, y - i,1);

    delay(70);
    cleardevice();
  }


  setbkcolor(BLACK);
  // Set the initial position of the rocket on space
  xo = 100; // x axis of rocket
  yo = 220; // y axis of rocket
  rl = 150; // rocket length

  randomFun(rx, ry);

  rocket(xo, yo, rl);
  motion(xo, yo, rl, move, 1, rx, ry);
  motion(xo - 20, yo, rl, move, 0, rx, ry);

  cleardevice();
    setbkcolor(RED);
  // Initial scene
  drawScene(1, x, y,0);

  // Animation
  for (i = 330; i >= -5; i -= 5)
  {
    drawScene(1.0, x, y - i,0);
    // turn off busters when lands
    if(i == 3)
    drawScene(1.0,x,y-i,2);

    delay(70);

    cleardevice();
  }
  drawScene(1.0,x,y+50,2);
  delay(100);
  script(0);
  getch();
  closegraph();
  return 0;
}
