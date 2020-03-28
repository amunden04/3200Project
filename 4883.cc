/*
*  Program for Problem #4883 (Ropes) on UVALive
*  This is from 2010 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: March 27, 2020
*/
#include<bits/stdc++.h>

using namespace std;

int calcPeople(int r, int p){
  int numPeople = 0;
  while(r >= 0){
    r = r - p;
    numPeople++;
  }
  return numPeople;
}

bool longEnough(int r, int p){
  if(r >= 2 * p){
      return true;
    } else {
      return false;
    }
}

int main(){
  int n;

  while (cin >> n && n != 0){
    vector<int> pitches;
    int temp;
    int total = 0;
    int maxPeople;
    int pitch;
    for(int i = 0; i < n; i++){
      cin >> temp;
      pitches.push_back(temp);
      total += pitches[i];
    }
    sort(pitches.begin(), pitches.end());
    pitch = pitches[n-1];

    maxPeople = calcPeople(50, pitch);
    if(longEnough(50, total) && maxPeople > 1){
      cout << maxPeople << " ";
    } else {
      cout << 0 << " ";
    }

    maxPeople = calcPeople(60, pitch);
    if(longEnough(60, total && maxPeople > 1)){
      cout << maxPeople << " ";
    } else {
      cout << 0 << " ";
    }

    maxPeople = calcPeople(70, pitch);
    if(longEnough(70, total) && maxPeople > 1){
      cout << maxPeople << endl;
    } else {
      cout << 0 << endl;
    }

  }

  return 0;
}
