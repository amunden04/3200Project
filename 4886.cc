/*
*  Program for Problem #4886 (Page Count) on UVALive
*  This is from 2010 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: March 27, 2020
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
  int pages = 0;
  // Loop through the cases until 0 is input
  while(cin >> pages && pages != 0){
    // Create a boolean array and initialize it to false
    bool printed[1001] = {false};
    // Get the page ranges input as a string
    string r = " ";
    cin >> r;

    // Change all the commas in the input to spaces
    for(auto &c : r){
      if(c == ','){
        c = ' ';
      }
    }

    // Put the page range string into a string stream
    istringstream iss(r);

    int high, low;
    char c;
    // Take the first number as the low end of the range
    while(iss >> low){
      // If there is a dash make the next number the high end of the range
      if(iss.get(c) && c == '-'){
        iss >> high;
        // Otherwise the high is equal to the low
      } else {
        high = low;
      }

      // If the low end of the range is greater than the number of pages
      // continue with the next range
      if(low > pages){
        continue;
      }

      // If the high end of the range is greater than the number of pages
      // make it equal to the number of pages
      if(high > pages){
        high = pages;
      }

      // For every index in the range change the boolean array value to true
      for(int i = low; i <= high; i++){
        printed[i] = true;
      }
    }

    // Output the number of "true" values in the boolean array
    cout << count(printed, printed+1001, true) << endl;

  }

  return 0;
}
