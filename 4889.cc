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

  // Loop through the cases until the input is 0 0 0
  while(cin >> a >> b >> c && a != 0 && b != 0 && c != 0){
    // Create a vector of sizes
    vector<double> sizes;
    // Put the three input sizes into the vector
    sizes.push_back(a);
    sizes.push_back(b);
    sizes.push_back(c);
    // Sort the vector to get the sizes from smallest to largest
    sort(sizes.begin(), sizes.end());

    double length, height, thick;
    // Make the largest size the length
    length = sizes[2];
    // Make the middle size the height
    height = sizes[1];
    // Make the smallest size the thickness
    thick = sizes[0];

    // Check to make sure all the sizes are greater than the minimum size
    // If they are not output "not mailable"
    if(length >= 125 && height >= 90 && thick >= 0.25){
      // Check to see if the dimensions fall within the size of a letter
      // if so output "letter"
        if(length <= 290 && height <= 155 && thick <= 7){
          cout << "letter" << endl;
          // Otherwise check to see if it falls within the dimensions for
          // a packet and output "packet"
        } else if ( length <= 380 && height <= 300 && thick <= 50){
          cout << "packet" << endl;
          // Otherwise check to see if it falls within the dimensions for a
          // parcel and output "parcel"
        } else if(length + (2*height + 2*thick) <= 2100){
          cout << "parcel" << endl;
          // If it doesn't fit within any of the three categories then output
          // "not mailable"
        } else {
          cout << "not mailable" << endl;
        }
    } else {
      cout << "not mailable" << endl;
    }

  }

  return 0;
}
