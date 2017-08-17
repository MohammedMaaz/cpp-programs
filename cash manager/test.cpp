#include <cash_manager.h>
using namespace std;

int main{

float angle = 360; // num_of_sides;
float start_x = 0;
float start_y = 0;

x = startX;
y = startX;
for(int i(0); i < num_of_sides; ++i)
{
  float endX, endY;
  rotateOffsetByAngle(x, y, x + lenth_of_side, y, angle * i, endX, endY);
  drawline(x, y, endX, endY);
  x = endX;
  y = endY;
}

}


drawline(float startX, startY, endX, endY)
{
  //does code that draws line between the start and end coordinates;
}

rotateOffsetByAngle(float startX, startY, endX, endY, angle, &outX, &outY)
{
  //the in-parameters startX, startY and endX, endY describe a line
  //we treat this line as the offset from the starting point

  //do code that rotates this line around the point startX, startY, by the angle.
  //after this rotation is done endX and endY are now at the same
  //distance from startX and startY that they were, but rotated.

  outX = endX;
  outY = endY; //pass these new coordinates back out by reference;

}
