#include<bits/stdc++.h>
using namespace std;

//problems like
//1=> segregate even and odd 
//2=> sort a binary array (one trick for this is count 0's and 1's seperatly and then place them)
//3=>segregate positive and negetive numbers

void segposneg(vector<int>&arr,int n)
{
    int i = -1,j = n;
    while(1)
    {
        do{
            i++;
        }while(arr[i]<0);
        do{
            j--;
        }while(arr[j]>=0);
        if(i>=j)return ;
        swap(arr[i],arr[j]);
    }
}

// like this we can solve partion questions