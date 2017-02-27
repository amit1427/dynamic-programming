#include <iostream>
#include <vector>
#define SIZE 100
using namespace std;

int main()
{
int a[SIZE] ={ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };         //output is 36
    int signs[SIZE] = {0};
    int dp[SIZE] = {1};
    for(int i=1;i<SIZE;i++)
        {
        for(int j = i-1; j>=0; j--)
        {
        int sign = signs[j];
    if( (sign == 0) || ( (sign < 0) && (a[i] - a[j] > 0) ) ||
                    ( (sign > 0) && (a[i] - a[j] < 0) ) )
                    {
            dp[i] = dp[j] + 1;
            signs[i] = a[i] - a[j];
                break;
            }
        }
    }
    cout << dp[SIZE-1] << endl;
    return 0;
}
