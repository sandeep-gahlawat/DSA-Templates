#include<bits/stdc++.h>
using namespace std;
//generate hash for substrings 
//hash of abc = (a-'a')*26^2 + (b-'a')*(26^1) + (c-'a')*(26^0) like this generate hash for substrings . if hash of two substrings match of equal length then there are huge chances that they are same
class Solution {
public:
    int prime=10000001;
     vector<int> power;
     bool check(string &s,int len){
       
         int n=s.size();
         int curr=0;
         unordered_map<int,vector<int>> hash;
         //we are taking modulo of hash by using long prime number to prevent the ovelflow
         for(int i=0;i<len;i++){
             curr= (curr*26 + (s[i] -'a'))%prime;
         }
         
         hash[curr]={0};
         //slinding window calculating hash for every substring of length k
         for(int i=len;i<n;i++){
             curr=((curr - power[len-1]*(s[i-len] - 'a'))%prime + prime)%prime;
             curr=(curr*26 + (s[i] -'a'))%prime;
             
             if(hash.find(curr) ==hash.end()){
                 hash[curr] ={i -len+1};//store staring index of of substring with having hash as curr
             }
             else{
                 //if hash matches then there may dublicate substring present so check all the substing with the same hash value
                 for(int index : hash[curr]){
                     string str=s.substr(i-len+1,len);
                     
                     if(s.substr(index,len)==str){
                         return true;
                     }
                 }
                 hash[curr].push_back({i-len + 1});
             }
         }
         
         
         return false;
    }
    
    string longestDupSubstring(string s) {
        
        //TTTTFFFFFFFF=>Need to find last true;
        
        power=vector<int> (s.size());
        int p=1;
        
        power[0]=1;
        for(int i=1;i<s.size();i++){
            power[i]=(power[i-1]*26)%prime;
        }
        
        int l=0,r=s.size()-1;
        while(r>l){
            int mid  = l +  (r - l + 1)/2;
            
            if(check(s,mid)){
                l=mid;
            }
            else{
                r= mid - 1;
            }
        }
        
        if(l==0){
            return "";
        }
        unordered_map<string,int> mp;
        
        string slidestring="";
        int k=l;
        
        for(int i=0;i<k;i++){
            slidestring+=s[i];
        }
        mp[slidestring]++;
        int maxrep=0;
        
        maxrep=max(maxrep, mp[slidestring]);
        for(int j=k;j<s.size();j++){
            slidestring.erase(slidestring.begin());
            slidestring+=s[j];
             mp[slidestring]++;
             if(mp[slidestring]==2){
                 return  slidestring;
             }
        }
      
        return "";
    }
};