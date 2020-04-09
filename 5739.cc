/*
*  Program for Problem #5739 (User Names) on UVALive
*  This is from 2011 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: April 8, 2020
*/
#include<bits/stdc++.h>

using namespace std;

//Create a set of usernames that will act as a database for each case
set<string> usernames;

// Function to remove all non letter characters from the name and
// Make all the letters lowercase
string cleanUpString(string s){
  string clean = "";
  // Loop through all the characters. If they are letters then add the
  // lowercase version of them to the string
  for(int i = 0; i <= s.length()-1; i++){
    if(isalpha(s[i])){
      clean += tolower(s[i]);
    }
  }
  // Return the clean string
  return clean;
}

// Function to add two strings together while still ensuring that the result
// is the required length
string addRightAmount(string a, string b, int length){
  string result;
  // If size of adding the two strings together is still less than or equal
  // to the length then just add them together
  if((a.size() + b.size()) <= length){
    result = a + b;
    // Otherwise take a substring of the first string so that the size of the substring
    // is the length minus the size of b and then add b to that substring
  } else {
    result = a.substr(0, (length-b.size())) + b;
  }
  // Return the resulting string
  return result;
}

// Function to generate the username given the input name and the allowed length
string generateUsername(string name, int length){
  string fName, lName, username;
  // Turn the name into a stringstream
  istringstream iss(name);
  // Pull out the first name
  iss >> fName;
  // Loop through the rest until you get the last word which will be the last name
  while(iss >> lName);
  // Call the cleanUpString function on both the first and last names
  fName = cleanUpString(fName);
  lName = cleanUpString(lName);
  // Begin the username with the first letter of the first name
  username = fName[0];
  // Loop through the last name adding on as many letters as you can until the allowed
  // length is reached
  for(int i = 0; i <= lName.length()-1; i++){
    username += lName[i];
    if(username.length() == length){
      break;
    }
  }
  // Check to see that the username has not already been used
  if(usernames.find(username) == usernames.end()){
    // Add it to the set of usernames and return it
    usernames.insert(username);
    return username;
    // If it has already been used then we need to add a number to the end
  } else {
    int endNum = 1;
    string num = "";
    string temp;
    // Loop through checking it with all numbers sequentially until you find
    // one that has not been used
    while (true){
      num = to_string(endNum);
      temp = addRightAmount(username, num, length);
      if(usernames.find(temp) == usernames.end()){
        break;
      }
      endNum++;
    }
    // Make the one you found the username, add it to the set and return it
    username = temp;
    usernames.insert(username);
    return username;
  }
}

int main(){
  int n, length;
  int caseNum = 1;

  //Loop through each case until the input is 0 0
  while(cin >> n >> length && n != 0 && length != 0){
    string temp, name, username;
    // Get rid of the end of line character
    getline(cin, temp);

    // Output the Case number
    cout << "Case " << caseNum << endl;

    // Loop through each of the input names
    for(int i = 0; i < n; i++){
      getline(cin, name);
      // For each name generate the username
      username = generateUsername(name, length);
      // Output the username
      cout << username << endl;
    }
    // Clear out the set and increase the case number before the next case
    usernames.clear();
    caseNum++;
  }

  return 0;
}
