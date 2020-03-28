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
  while(cin >> pages && pages != 0){
    bool printed[1001] = {false};
    string r = " ";
    cin >> r;

    for(auto &c : r){
      if(c == ','){
        c = ' ';
      }
    }

    istringstream iss(r);

    int high, low;
    char c;
    while(iss >> low){
      if(iss.get(c) && c == '-'){
        iss >> high;
      } else {
        high = low;
      }

      if(low > pages){
        continue;
      }
      if(high > pages){
        high = pages;
      }

      for(int i = low; i <= high; i++){
        printed[i] = true;
      }
    }

    cout << count(printed, printed+1001, true) << endl;

  }

  return 0;
}
