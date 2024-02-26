#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void earthOnSpace(int *rx, int *ry)
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

  for (i = 0; i < 500; i++)
  {
    x = rx[i]/50;
    y = ry[i]/80;

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

void marsOnSpace(int *rx, int *ry)
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
  for (i = 0; i < 200; i++)
  {
    x = rx[i]/50;
    y = ry[i]/80;
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


void typeOnScreen(char* sc)
{
   int i;
   int text,pos;
   cleardevice();
   for (i=0; i< strlen(sc); i++)
   {
	text = sc[i];
	outtextxy(200+i*10,239,&text);
	delay(100);
   }
}


void countDown(){
	int i;
	char count[] = "9 8 7 6 5 4 3 2 1";
	char text[2];
	for (i=0; i < strlen(count); i++)
	{
		text[0] = count[i];
		text[1] = '\0';
		delay(500);
		cleardevice();
		outtextxy(319,239,&text);
	}
}

void script()
{
	char sc1[] = "Hello fellow adventurer",
	sc2[] = "Let's go to mars";

	typeOnScreen(sc1);
	delay(100);
	typeOnScreen(sc2);
	delay(100);
	countDown();
}
/*
void outerspace()
{
	earthOnSpace();
	delay(1000);
	cleardevice();
	marsOnSpace();

}
*/
void rocket(int x, int y, int rl)
{
    int i,fireEffect;
    setcolor(YELLOW);

    for (i=0;i<12;i++){
    fireEffect = i /3;
    line(x,y+10+i,x+85,y+10); //upper triangle
    line(x,y+10-i,x+85,y+10); //lower triangle
    fireEffect = -fireEffect;
    }
    //booster brown sceal
    setcolor(BROWN);
    for (i=0;i<11;i++){
    line(x+42,y+10+i,x+85,y+10); //upper triangle
    line(x+42,y+10-i,x+85,y+10); //lower triangle
    }
    //rocket fin
    setcolor(WHITE);
    for (i=0;i<21;i++){
    line(x+59,y+10+i,x+130,y+10); //upper triangle
    line(x+59,y+10-i,x+130,y+10); //lower triangle
    }

    // Set the rocket's color
    setcolor(WHITE);

    // Draw the rocket
    for (i=0;i<40;i++)
 {  if(i<21)
    line(x+50, y+i, x + rl, y+i); // body

    ellipse(x+150-i,y+10,270,90,40,10);//head
}
}

void randomFun(int *rx[], int *ry[])
{  int i;
   srand(time(NULL)); // initialize random seed
  for (i = 0; i < 500; i++)
  {
   rx[i] = rand();
   ry[i] = rand();
}
 }
void motion(int x,int y,int rl,int move, int choice,int *rx,int *ry)
{
	int x1= x;
    while (1)
    {
	// Move the rocket and fire to the right

	x1= x1+4;
	move++;
	// Clear the previous position of the rocket and fire
	cleardevice();

	rocket(x1,y,rl);
	if (move<130 && choice == 1)
	{
		earthOnSpace(rx,ry);
	}
	 else if(move<60 && choice == 0)
	 {
	marsOnSpace(rx,ry);
	 }
	 else
	 {
	return;
	}
	delay(50);
    }
}


int main() {
    // Initialize the graphics system
    int gd = DETECT, gm,move = 0;
    int x,y,rl, rx[501],ry[501];

    // Set the initial position of the rocket
    x = 100; // x axis of rocket
    y = 220; //y axis of rocket
    rl = 150; //rocket length

    randomFun(rx,ry);

  initgraph(&gd, &gm, "c:\\TurboC3\\BGI");
 // script();
  rocket(x,y,rl);
  motion(x,y,rl,move,1,rx,ry);
  motion(x-20,y,rl,move,0,rx,ry);
 // outerspace();
  getch();
  return 0;
}