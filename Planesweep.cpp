#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Point
{
  int x, y;
};

bool
comparePoints (const Point & a, const Point & b)
{
  return a.x < b.x;
}

void
findMaximalPoints (Point points[], int num)
{
  if (num == 0)
    {
      cout << "No points to process.\n";
      return;
    }

  sort (points, points + num, comparePoints);

  stack < Point > maximalPointsStack;
  maximalPointsStack.push (points[0]);

  for (int i = 1; i < num; ++i)
    {
      while (!maximalPointsStack.empty ()
	     && points[i].y >= maximalPointsStack.top ().y)
	{
	  maximalPointsStack.pop ();
	}

      maximalPointsStack.push (points[i]);
    }

  cout << "Maximal Points: ";
  while (!maximalPointsStack.empty ())
    {
      Point currentPoint = maximalPointsStack.top ();
      cout << "(" << currentPoint.x << "," << currentPoint.y << ") ";
      maximalPointsStack.pop ();
    }
}

int
main ()
{
  int num;
  cout << "Enter number of points: ";
  cin >> num;

  Point *inputPoints = new Point[num];

  cout << "Enter points (x y): ";
  for (int i = 0; i < num; ++i)
    {
      cin >> inputPoints[i].x >> inputPoints[i].y;
    }

  findMaximalPoints (inputPoints, num);

  delete[]inputPoints;

  return 0;
}
