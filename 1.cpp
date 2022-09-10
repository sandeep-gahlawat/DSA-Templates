#include <bits/stdc++.h>
using namespace std;
bool palindrome(string &str)
{
      int low  = 0,high = str.length()-1;
      while(low<high)
      {
          if(str[low]!=str[high])return false;
          low++;
          high--;
      }
      return true;
}
string base_k(long long n,int k)
{
    string str = "";
    while(n>0)
    {
        str.push_back(n%k);
        n/=k;
    }
    reverse(str.begin(),str.end());
    return str;
}
long long generate_palindrome(int n,bool flag)
{
    long long temp_n = n;
    if(flag)
    {
         temp_n/=10;
    }
    while(temp_n>0)
    {
        int r = temp_n%10;
        n = n*10 +r;
        temp_n/=10;
    }
    return n;
}

long long kMirror(int k, int n)
{
         long long sum = 0;
         for(long long i = 0;n;i*=10)
         {
             //generting odd digitd palindrome
             for(int j = i;j<i*10 && n;j++)
             {
                 long long num = generate_palindrome(j,true);
                 string str = base_k(num,k);
                 if(palindrome(str))
                 {
                     sum+=num;
                     n--;
                 }
             }
             //generting even digit palindrome
             for(int j = i;j<i*10 && n;j++)
             {
                 long long num = generate_palindrome(j,false);
                 string str = base_k(num,k);
                 if(palindrome(str))
                 {
                     sum+=num;
                     n--;
                 }
             }
             
         } 
         return sum;
}