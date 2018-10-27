
#include <bits/stdc++.h> 
  
using namespace std; 
  
string LongestSubstring(string str) 
{ 
    int i; 
    int n = str.length(); 
  
 
    int st = 0; 
    int currlen; 
  
    int maxlen = 0; 
  
 
    int start; 
    unordered_map<char, int> pos; 
    pos[str[0]] = 0; 
  
    for (i = 1; i < n; i++) { 
  
    
        if (pos.find(str[i]) == pos.end()) 
            pos[str[i]] = i; 
  
        else { 
           
            if (pos[str[i]] >= st) { 
  
                currlen = i - st; 
                if (maxlen < currlen) { 
                    maxlen = currlen; 
                    start = st; 
                } 
  
             
                st = pos[str[i]] + 1; 
            } 
  
            
            pos[str[i]] = i; 
        } 
    } 
  
  
    if (maxlen < i - st) { 
        maxlen = i - st; 
        start = st; 
    } 
  
    
    return str.substr(start, maxlen); 
} 
  
int main() 
{ 
    string str = "somiljain"; 
    cout <<LongestSubstring(str); 
    return 0; 
} 

