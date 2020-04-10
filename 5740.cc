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

string removeSlashes(string s){
  string clean;
  for(int i = 0; i <= s.length()-1; i++){
    if(s[i] == '/'){
      s[i] = ' ';
    }
    clean += s[i];
  }
  return clean;
}

int main(){
  Date live, apply;
  string living, prStatus;
  int month1=0, day1=0, year1=0;
  int month2=0, day2=0, year2=0;
  getline(cin, living);
  living = removeSlashes(living);
  istringstream iss(living);
  iss >> month1;
  iss >> day1;
  iss >> year1;

  live.mm = month1;
  live.dd = day1;
  live.yyyy = year1;

  getline(cin, prStatus);
  prStatus = removeSlashes(prStatus);
  istringstream is(prStatus);
  is >> month2 >> day2 >> year2;
  apply.mm = month2;
  apply.dd = day2;
  apply.yyyy = year2;

  int daysBetween, credit;
  daysBetween = apply.daysFromStart(month1, day1, year1);
  cout << daysBetween << endl;
  credit = floor(daysBetween/2);
  cout << credit << endl;
  apply.addDay(1095);
  apply.addDay(-credit);

  cout << "apply date" << " " << apply.mm << '/' << apply.dd;
  cout << '/' << apply.yyyy << endl;

  return 0;
}
