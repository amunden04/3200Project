/*
*  Program for Problem #5737 (Pills) on UVALive
*  This is from 2011 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: March 30, 2020
*/
#include<bits/stdc++.h>

using namespace std;

long long numWays[30][60];

long long calcWays(int whole, int half){
  if(numWays[whole][half] > 0){
    return numWays[whole][half];
  }
  if(whole == 0){
    numWays[whole][half] = 1;
    return numWays[whole][half];
  } else if(half == 0){
    numWays[whole][half] = calcWays((whole - 1), 1);
    return numWays[whole][half];
  } else {
    numWays[whole][half] = calcWays(whole, (half - 1)) + calcWays((whole - 1), (half + 1));
    return numWays[whole][half];
  }
}

int main(){
  int n;

  while (cin >> n && n != 0){
    cout << calcWays(n, 0) << endl;
  }

  return 0;
}
