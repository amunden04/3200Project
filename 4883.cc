/*
*  Program for Problem #4883 (Ropes) on UVALive
*  This is from 2010 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: March 27, 2020
*/
#include<bits/stdc++.h>

using namespace std;

// Function that returns true or false depending on whether or not the
// Rope is long enough for the entire climb
bool longEnough(int r, int p){
  if(r >= 2 * p){
      return true;
    } else {
      return false;
    }
}

int main(){
  int n;

  // Loop through the cases until 0 is input
  while (cin >> n && n != 0){
    // Create a vector of pitches
    vector<int> pitches;
    int temp, maxPeople, pitch;
    int total = 0;

    // Get the pitch input and put it into the vector
    // Keep a running total of the distance of the pitches
    for(int i = 0; i < n; i++){
      cin >> temp;
      pitches.push_back(temp);
      total += pitches[i];
    }
    // Sort the pitches
    sort(pitches.begin(), pitches.end());
    // Make pitch equal to the longest pitch
    pitch = pitches[n-1];

    // Calculate the maxPeople that could climb with a 50m rope
    maxPeople = (50/pitch) + 1;
    // If the rope is long enough for the total climb and more than one
    // person can climb output the maxPeople otherwise output 0
    if(longEnough(50, total) && maxPeople > 1){
      cout << maxPeople << " ";
    } else {
      cout << 0 << " ";
    }

    // Calculate the maxPeople that could climb with a 60m rope
    maxPeople = (60/pitch) + 1;
    // If the rope is long enough for the total climb and more than one
    // person can climb output the maxPeople otherwise output 0
    if(longEnough(60, total) && maxPeople > 1){
      cout << maxPeople << " ";
    } else {
      cout << 0 << " ";
    }

    // Calculate the maxPeople that could climb with a 70m rope
    maxPeople = (70/pitch) + 1;
    // If the rope is long enough for the total climb and more than one
    // person can climb output the maxPeople otherwise output 0
    if(longEnough(70, total) && maxPeople > 1){
      cout << maxPeople << endl;
    } else {
      cout << 0 << endl;
    }

  }

  return 0;
}
