#include <iostream>
#include<stdio.h>
 #define SIZE 10000
 using namespace std;
 int main()
 {
    int t, n, arr[SIZE], lis[SIZE], lisSzArr[SIZE], max, allIterMax, len = 0;
    cin>>t;
    while(t--)
        {
        max = 1;
        scanf("%d", &n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &arr[i]);
        }
        allIterMax = 0;
        for (int shift=0; shift<n; ++shift) {
            lis[0] = 1;
            lisSzArr[0] = arr[shift];
            len = 1;
            for (int i=(shift+1)%n; i!=shift; i=(i+1)%n) {
                if (lisSzArr[0]>arr[i]) {
                    lisSzArr[0] = arr[i];
                    lis[i] = 1;
                } else if (lisSzArr[len-1]<arr[i]) {
                    lisSzArr[len] = arr[i];
                    lis[i] = len+1;
                    ++len;
                } else {
                    int ind = -1;
                    int start = 0;
                    int end = len-1;
                    while (start<=end) {
                        int middle = (start+end)/2;
                        if (lisSzArr[middle] == arr[i]) {
                            ind = -2;
                            break;
                        } else if (lisSzArr[middle]>arr[i]) {
                            end = middle-1;
                        } else {
                            start = middle+1;
                        }
                    }
                    if (ind == -1) {
                        ind = start;
                        lisSzArr[ind] = arr[i];
                    }
                }
                for (int j=0; j<len; ++j) {
                }
            }
            if (allIterMax<len) {
                allIterMax = len;
            }
        }
        cout<<allIterMax<<endl;
    }
    return 0;
}
