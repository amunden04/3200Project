/*
*  Program for Problem #5739 (User Names) on UVALive
*  This is from 2011 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: April 7, 2020
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, length;

  while(cin >> n >> length && n != 0 && length != 0){
    string temp;
    getline(cin, temp);
    vector<string> names;
    for(int i = 0; i < n; i++){
      string name;
      getline(cin, name);
      names.push_back(name);
    }

    
  }


  return 0;
}
