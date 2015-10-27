#include <ArduinoUnit.h>

bool is_leap_year(int year)
{
 // if year is devisable by 4 but NOT 100 OR is devisable by 400, return true 
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

//test for a typical common year, should return false

test(A_typical_common_year_returns_false)
{

//if test does NOT return true, test is passed
  
  assertFalse(is_leap_year(2001));
}

//test for a typical leap year, should return true

test(a_typical_leap_year_returns_true)
{
  
  //if test DOES return true, test is passed
  
  assertTrue(is_leap_year(1996));
}

//test for an atypical common year, should return false

test(a_atypical_common_year)
{

  //if test does NOT return true, test is passed
  
  assertFalse(is_leap_year(1900));
}

//test for an atypical leap year, should return true

test(a_atypical_leap_year)
{

//if test DOES return true, test is passed

  assertTrue(is_leap_year(2000));
}

//run on start up

void setup(){
  Serial.begin(115200);
  
}

//run repeatedly 

void loop() {
  Test::run();
}
