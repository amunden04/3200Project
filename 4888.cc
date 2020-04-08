/*
*  Program for Problem #4888 (Railroad) on UVALive
*  This is from 2010 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: March 27, 2020
*/
#include<bits/stdc++.h>

using namespace std;

bool makeTrain(int train1[], int train2[], int desired[]){


}

int main(){
  int n, m;
  while(cin >> n >> m && n != 0 && m != 0){
    int train1[1001];
    int train2[1001];
    int desired[2002];
    for (int i = 0; i < n; i++){
      cin >> train1[i];
    }
    for (int i = 0; i < m; i++){
      cin >> train2[i];
    }
    for (int i = 0; i < (n+m); i++){
      cin >> desired[i];
    }

    if(makeTrain(train1, train2, desired)){
      cout << "possible" << endl;
    } else {
      cout << "not possible" << endl;
    }

  }

  return 0;
}
