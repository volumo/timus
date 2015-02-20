#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j)
{
    return (i<j);
}

int main(int argc, char *argv[])
{
    bool min1 = false;
    vector<int> res;
    int inp = 0;
    cin >> inp;
    bool r = false;
    int i=0;
    if (inp==1)
    {
        res.push_back(1);
    }
    if (inp==0)
    {
        res.push_back(10);
        inp=1;
    }
    while (inp != 1)
    {
        r=false;
        for (i=9; i>1; i--)
        {
            if (inp % i == 0)
            {
                r=true;
                res.push_back(i);
                //cout << i;
                inp /= i;
                break;
            }
        }
        if (r==false)
        {
            inp=1;
            min1 = true;
        }
    }
    if (min1)
    {
        cout << -1;
    }
    else
    {
        std::sort(res.begin(),res.end(),myfunction);
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i];
        }
    }
    return 0;
}

