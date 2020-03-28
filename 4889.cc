/*
*  Program for Problem #4889 (Post Office) on UVALive
*  This is from 2010 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: March 27, 2020
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  double a = 0.0;
  double b = 0.0;
  double c = 0.0;

  while(cin >> a >> b >> c && a != 0 && b != 0 && c != 0){
    vector<double> sizes;
    sizes.push_back(a);
    sizes.push_back(b);
    sizes.push_back(c);
    sort(sizes.begin(), sizes.end());

    double length, height, thick;
    length = sizes[2];
    // might need to determine which one actually has a decimal
    height = sizes[1];
    thick = sizes[0];

    if(length >= 125 && height >= 90 && thick >= 0.25){
        if(length <= 290 && height <= 155 && thick <= 7){
        cout << "letter" << endl;
        } else {
            if ( length <= 380 &&  height <= 300 && thick <= 50){
              cout << "packet" << endl;
        }  else {
          if(length + (2*height + 2*thick) <= 2100){
            cout << "parcel" << endl;
          }
        }
      }
    } else {
      cout << "not mailable" << endl;
    }

  }

  return 0;
}
