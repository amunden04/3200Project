/*
*  Program for Problem #5740 (Citizenship Application) on UVALive
*  This is from 2011 Rocky Mountain Regional Contest
*  Written by: Amanda Munden
*  Date: April 9, 2020
*/
#include<bits/stdc++.h>

using namespace std;

//
// Date class from Howard's code Library
//
// This is an implementation of some common functionalities for dates.
// It can represent dates from Jan 1, 1753 to after (dates before that
// time are complicated...).
//

#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include <cctype>

using namespace std;
using namespace std::rel_ops;

struct Date {

  int yyyy;
  int mm;
  int dd;

  // no dates before 1753
  static int const BASE_YEAR = 1753;

  // Enumerated type for names of the days of the week
  enum dayName {SUN,MON,TUE,WED,THU,FRI,SAT};

  // Is a date valid
  static bool validDate(int yr, int mon, int day)
  {
    return yr >= BASE_YEAR && mon >= 1 && mon <= 12 &&
    day > 0 && day <= daysIn(mon, yr);
  }

  bool isValid() const
  {
    return validDate(yyyy, mm, dd);
  }

  // Constructor to create a specific date.  If the date is invalid,
  // the behaviour is undefined
  Date(int yr = 1970, int mon = 1, int day = 1)
  {
    yyyy = yr;
    mm = mon;
    dd = day;
  }

  // Returns the day of the week for this
  dayName dayOfWeek() const
  {
    int a = (14 - mm) / 12;
    int y = yyyy - a;
    int m = mm + 12 * a - 2;
    return (dayName)((dd + y + y/4 - y/100 + y/400 + 31 * m / 12) % 7);
  }

  // comparison operators
  bool operator==(const Date &d) const
  {
    return dd == d.dd && mm == d.mm && yyyy == d.yyyy;
  }

  bool operator<(const Date &d) const
  {
    return yyyy < d.yyyy || (yyyy == d.yyyy && mm < d.mm) ||
    (yyyy == d.yyyy && mm == d.mm && dd < d.dd);
  }

  // Returns true if yr is a leap year
  static bool leapYear(int y)
  {
    return (y % 400 ==0 || (y % 4 == 0 && y % 100 != 0));
  }

  // number of days in this month
  static int daysIn(int m, int y)
  {
    switch (m) {
      case 4  :
      case 6  :
      case 9  :
      case 11 :
      return 30;
      case 2  :
      if (leapYear(y)) {
        return 29;
      }
      else {
        return 28;
      }
      default :
      return 31;
    }
  }

  // increment by day, month, or year
  //
  // Use negative argument to decrement
  //
  // If adding a month/year results in a date before BASE_YEAR, the result
  // is undefined.
  //
  // If adding a month/year results in an invalid date (Feb 29 on a non-leap
  // year, Feb 31, Jun 31, etc.), the results are automatically "rounded down"
  // to the last valid date

  // add n days to the date: complexity is about n/30 iterations
  void addDay(int n = 1)
  {
    dd += n;
    while (dd > daysIn(mm,yyyy)) {
      dd -= daysIn(mm,yyyy);
      if (++mm > 12) {
        mm = 1;
        yyyy++;
      }
    }

    while (dd < 1) {
      if (--mm < 1) {
        mm = 12;
        yyyy--;
      }
      dd += daysIn(mm,yyyy);
    }
  }

  // add n months to the date: complexity is about n/12 iterations
  void addMonth(int n = 1)
  {
    mm += n;
    while (mm > 12) {
      mm -= 12;
      yyyy++;
    }

    while (mm < 1)  {
      mm += 12;
      yyyy--;
    }

    if (dd > daysIn(mm,yyyy)) {
      dd = daysIn(mm,yyyy);
    }
  }

  // add n years to the date
  void addYear(int n = 1)
  {
    yyyy += n;
    if (!leapYear(yyyy) && mm == 2 && dd == 29) {
      dd = 28;
    }
  }

  // number of days since 1753/01/01, including the current date
  int daysFromStart(int smonth, int sday, int syear) const
  {
    int c = 0;
    Date d(syear, smonth, sday);
    Date d2(d);

    d2.addYear(1);
    while (d2 < *this) {
      c += leapYear(d.yyyy) ? 366 : 365;
      d = d2;
      d2.addYear(1);
    }

    d2 = d;
    d2.addMonth(1);
    while (d2 < *this) {
      c += daysIn(d.mm, d.yyyy);
      d = d2;
      d2.addMonth(1);
    }
    while (d <= *this) {
      d.addDay();
      c++;
    }
    return c;
  }
};

// Reads a date in yyyy/mm/dd format, assumes date is valid and in the
// right format
istream& operator>>(istream &is, Date &d)
{
  char c;
  return is >> d.yyyy >> c >> d.mm >> c >> d.dd;
}

// print date in yyyy/mm/dd format
ostream& operator<< (ostream &os, const Date &d) {
  char t = os.fill('0');
  os << d.yyyy << '/' << setw(2) << d.mm << '/' << setw(2) << d.dd;
  os.fill(t);
  return os;
}

// Start of my code
// Function to remove all the '/' characters from a string and replace them with spaces
string removeSlashes(string s){
  string clean;
  // Go through each character in the string and if it is '/' replace it with ' '
  for(int i = 0; i <= s.length()-1; i++){
    if(s[i] == '/'){
      s[i] = ' ';
    }
    clean += s[i];
  }
  // Return the string without the '/'
  return clean;
}

int main(){
  // Create two dates: the date you start living in Canada and the date you can apply
  Date live, apply, cstart;
  // Create two strings to get the input dates: first one for when you start living in Canada
  // and the second one for when you get permanent resident status
  string living, prStatus;
  int month1=0, day1=0, year1=0;
  int month2=0, day2=0, year2=0;
  // Loop through all cases
  while(!getline(cin, living).eof()){
    living = removeSlashes(living);
    istringstream iss(living);
    iss >> month1;
    iss >> day1;
    iss >> year1;
    // Add the first date input to the live date
    live.mm = month1;
    live.dd = day1;
    live.yyyy = year1;

    getline(cin, prStatus);
    prStatus = removeSlashes(prStatus);
    istringstream is(prStatus);
    is >> month2 >> day2 >> year2;
    // Add the second date input to the apply date
    apply.mm = month2;
    apply.dd = day2;
    apply.yyyy = year2;

    cstart.mm = month2;
    cstart.dd = day2;
    cstart.yyyy = year2;

    cstart.addDay(-731);
    // create two variables: dayBetween and credit
    // The daysBetween will be the number of days between getting to Canada and
    // being granted permanent resident status and the credit will be how much to subtract
    int daysBetween, credit;
    // Calculate the daysBetween
    daysBetween = apply.daysFromStart(month1, day1, year1);

    // Get the number of times they travelled out of the country
    string n;
    int t;
    getline(cin, n);
    t = stoi(n);

    int addTime = 0;
    // Loop through each of the times travelled out of the country
    for(int i = 0; i < t; i++){
      // Create two dates: one for the start of travel and one for the end of travel
      Date start, end;
      string info;
      int month, day, year;
      getline(cin, info);
      info = removeSlashes(info);
      istringstream in(info);
      in >> month >> day >> year;
      // Put the first date into the start date
      start.mm = month;
      start.dd = day;
      start.yyyy = year;
      in >> month >> day >> year;
      // Put the second date into the end date
      end.mm = month;
      end.dd = day;
      end.yyyy = year;
      if(daysBetween > 731){
        // If the "apply" date which is currently the date you get permanent resident status
        // is before the end of the travel period then add the time gone as full days
        if(cstart < end){
        addTime += end.daysFromStart(start.mm, start.dd, start.yyyy);
        // Otherwise, add the time gone as half days
        } else {
          addTime += floor(end.daysFromStart(start.mm, start.dd, start.yyyy)/2);
        }
      } else {
      // If the "apply" date which is currently the date you get permanent resident status
      // is before the end of the travel period then add the time gone as full days
      if(apply < end){
      addTime += end.daysFromStart(start.mm, start.dd, start.yyyy);
      // Otherwise, add the time gone as half days
      } else {
        addTime += floor(end.daysFromStart(start.mm, start.dd, start.yyyy)/2);
      }
    }
    }

    // If daysBetween is less than or equal to one or greater than or equal to 730
    // Then you add 1095 days to the date of gaining permanent resident status and subtract
    // the credit
    if(daysBetween <= 1 || daysBetween >= 730){
      if(daysBetween > 731){
        credit = floor(731/2);
      } else {
    credit = floor(daysBetween/2);
    }
    apply.addDay(1095);
    apply.addDay(-credit);
    // Otherwise, you add 1096 days to the date of gaining permanent resident status and
    // subtract the credit
  } else {
    credit = floor(daysBetween/2);
    apply.addDay(1096);
    apply.addDay(-credit);
  }
    // Add on the days of travel time that was previously calculated
    apply.addDay(addTime);
    // Output the date you can apply
    cout << apply.mm << '/' << apply.dd << '/' << apply.yyyy << endl;
  }

  return 0;
}
