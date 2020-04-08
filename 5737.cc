/*
*  Program for Problem #5737 (Pills) on UVALive
*  This is from 2011 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: April 7, 2020
*/
#include<bits/stdc++.h>

using namespace std;

// Create a global array to store the number of ways there are for each
// Combination of whole and half pills
long long numWays[30][60];

// Function used to calculate the number of ways there are for a particular
// combination of whole and half pils
long long calcWays(int whole, int half){
  // If we have already calculated this before return the stored value
  if(numWays[whole][half] > 0){
    return numWays[whole][half];
  }
  // If the amount of whole pills is 0, store the number 1 in the array
  // and return that value
  if(whole == 0){
    numWays[whole][half] = 1;
    return numWays[whole][half];
    // If the amount of half pills is 0, then calculate the ways again with
    // whole minus 1 and half equal to 1
  } else if(half == 0){
    numWays[whole][half] = calcWays((whole - 1), 1);
    return numWays[whole][half];
    // Otherwise calculate the ways again with the same whole amount and half - 1
    // plus the ways with whole minus 1 and half + 1
  } else {
    numWays[whole][half] = calcWays(whole, (half - 1)) + calcWays((whole - 1), (half + 1));
    return numWays[whole][half];
  }
}

int main(){
  int n;
  // Loop through the cases until the input is 0
  while (cin >> n && n != 0){
    // Output the number of ways
    cout << calcWays(n, 0) << endl;
  }

  return 0;
}
