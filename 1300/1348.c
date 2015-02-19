#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    typedef struct Point
    {
        int x;
        int y;
        int x_a;
        int y_a;
        int x_b;
        int y_b;
    } point;

    point a;
    point b;
    point c;
    int l;

    scanf("%i", &a.x);
    scanf("%i", &a.y);
    scanf("%i", &b.x);
    scanf("%i", &b.y);
    scanf("%i", &c.x);
    scanf("%i", &c.y);
    scanf("%i", &l);
    double rast, max;
    if ((a.x == b.x) && (a.y == b.y))
    {
        rast = sqrt(pow(a.x-c.x,2)+pow(a.y-c.y,2));
        max = sqrt(pow(a.x-c.x,2)+pow(a.y-c.y,2));
    }
    else
    {
        a.x_a = a.x - a.x;
        a.y_a = a.y - a.y;

        b.x_a = b.x - a.x;
        b.y_a = b.y - a.y;

        c.x_a = c.x - a.x;
        c.y_a = c.y - a.y;
        double cos_a = (b.x_a*c.x_a + b.y_a*c.y_a)/(sqrt((pow(b.x_a, 2) + pow(b.y_a, 2))*(pow(c.x_a, 2) + pow(c.y_a, 2))));
        
	a.x_b = a.x - b.x;
        a.y_b = a.y - b.y;

        b.x_b = b.x - b.x;
        b.y_b = b.y - b.y;

        c.x_b = c.x - b.x;
        c.y_b = c.y - b.y;
        double cos_b = (a.x_b*c.x_b + a.y_b*c.y_b)/(sqrt((pow(a.x_b, 2) + pow(a.y_b, 2))*(pow(c.x_b, 2) + pow(c.y_b, 2))));
        
	if (cos_a <=0)
        {
            rast = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
            max = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
        }
        else if (cos_b <= 0)
        {
            max = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
            rast = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
        }
        else
        {
            double ac = sqrt(pow(a.x-c.x,2)+pow(a.y-c.y,2));
            double ab = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
            double bc = sqrt(pow(b.x-c.x,2)+pow(b.y-c.y,2));
            double p = 0.5*(ac+ab+bc);
            rast = 2*sqrt(p*(p-ac)*(p-ab)*(p-bc))/(ab);
            double max1 = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
            double max2 = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
            if (max1>max2)
            {
                max = max1;
            }
            else
            {
                max=max2;
            }
        }

    }
    double ans1,ans2;
    if ((rast - l) < 0)
    {
        ans1 = 0;
    }
    else
    {
        ans1=rast-l;
    };
    if ((max - l) < 0)
    {
        ans2 = 0;
    }
    else
    {
        ans2=max-l;
    };
    printf("%0.2f %0.2f", ans1,ans2);


     return 0;
}
