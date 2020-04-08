/*
*  Program for Problem #5733 (Iterated Difference) on UVALive
*  This is from 2011 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: April 7, 2020
*/
#include<bits/stdc++.h>

using namespace std;

// Function to check and see if all the numbers are the same
bool foundMatch(int nums[], int n){
  set<int> check;
  // Add all the numbers in the array into a set
  for(int i = 0; i < n; i++){
    check.insert(nums[i]);
  }
  // If the size of the set is 1 return true
  if(check.size() == 1){
    return true;
    // Otherwise return false
  } else {
    return false;
  }
}

// Function to calculate the number of iterations required
int calcIts(int nums[], int n){
  int times = 1000;
  int count = 0;
  int temp;
  // Count down the number of possible times to iterate. If you get out of this
  // loop return -1
  while(times --){
    // If all the numbers match return the count
    if(foundMatch(nums, n)){
      return count;
      // Otherwise do another iteration and increase the count by one
    } else {
      temp = nums[0];
      for(int i = 0; i < n; i++){
        if(i == (n-1)){
          nums[i] = max(nums[i], temp) - min(nums[i], temp);
        } else {
          nums[i] = max(nums[i], nums[i+1]) - min(nums[i], nums[i+1]);
        }
      }
    }
    count++;
  }

  return -1;
}

int main(){
  int n;
  int caseNum = 1;
  // Loop through all the cases until the input is 0
  while (cin >> n && n != 0){
    int nums[20];
    // Store the array of numbers
    for (int i = 0; i < n; i++){
      cin >> nums[i];
    }
    int ans = 0;
    // Call the calcIts function to get an answer
    ans = calcIts(nums, n);

    // Output either the number of iterations or that it is not attained
    cout << "Case " << caseNum << ": ";
    if(ans == -1){
      cout << "not attained" << endl;
    } else {
      cout << ans << " iterations" << endl;
    }
    caseNum++;
  }

  return 0;
}
