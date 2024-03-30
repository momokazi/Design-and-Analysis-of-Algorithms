#include <iostream>
using namespace std;

struct Point
{
  int x, y;
};

void
find2DMaxima (int n, Point p[])
{
  for (int i = 0; i < n; ++i)
    {
      bool maximal = true;

      for (int j = 0; j < n; ++j)
	{
	  if (i != j && p[i].x <= p[j].x && p[i].y <= p[j].y)
	    {
	      maximal = false;
	      break;
	    }
	}

      if (maximal)
	{
	  cout << "Maximal point: (" << p[i].x << ", " << p[i].y << ")\n";
	}
    }
}

int
main ()
{
  const int n = 5;		// Change the value of n as needed
  Point points[n] = { {1, 2}, {3, 1}, {4, 5}, {2, 3}, {5, 4} };

  find2DMaxima (n, points);

  return 0;
}
