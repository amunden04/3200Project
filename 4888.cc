/*
*  Program for Problem #4888 (Railroad) on UVALive
*  This is from 2010 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: April 8, 2020
*/
#include<bits/stdc++.h>

using namespace std;

// Create global arrays. Store the int values on train1, train2 and desired
// and a bool array to store if a certain combination is possible
bool train[1004][1004];
int train1[1004];
int train2[1004];
int desired[2008];

// Function to determine with two index values if it is possible to create
// That particular train
bool makeTrain(int i, int j){
  // Base Case
  // When both i and j are 0 then train[0][0] is true
  if(i == 0 && j == 0){
  train[0][0] = true;
  return train[i][j];
  }
  // Recursion
  // If j is equal to zero then we just look at if we can choose cars from
  // train1
  if(j == 0){
    train[i][0] = (train1[i] == desired[i]) && makeTrain((i-1), 0);
    return train[i][j];
    // If i is equal to zero then we just look at if we can choose cars from
    // train2
  } else if(i == 0){
    train[0][j] = (train2[j] == desired[j]) && makeTrain(0, (j-1));
    return train[i][j];
    // Otherwise, we look through the possibilities of choosing from train1 or train2
  } else {
    train[i][j] = ((train1[i] == desired[i+j]) && makeTrain((i-1), j)) ||
    ((train2[j] == desired[i+j]) && makeTrain(i, (j-1)));
    return train[i][j];
  }

}

int main(){
  int n, m;
  // Loop through all the cases until the input is 0
  while(cin >> n >> m && n != 0 && m != 0){
    // Get the input for train1
    for (int i = 1; i <= n; i++){
      cin >> train1[i];
    }
    // Get the input for train2
    for (int i = 1; i <= m; i++){
      cin >> train2[i];
    }
    // Get the input for the desired train
    for (int i = 1; i <= (n+m); i++){
      cin >> desired[i];
    }

    // If it is possible to make the desired train output possible
    if(makeTrain(n, m)){
      cout << "possible" << endl;
      // Otherwise, output not possible
    } else {
      cout << "not possible" << endl;
    }

  }

  return 0;
}
