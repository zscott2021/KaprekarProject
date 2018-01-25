/**
 * Author: Zac Scott
 * Date: 2018/1/25
 * 
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers 
 * whose sum is equal to the original number.  For the purposes of 
 * this method, we restrict our consideration to base-10 representations.</p>
 * 
 * For example, 45 is a Kaprekar number, because 
 *   45<sup>2</sup> = 2025 
 * and 
 *   20 + 25 = 45. 
 * 
 * <p>See Wikipedia's  
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 * 
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number, 
 * <code>false</code> otherwise.
 */
//Put header first and added author and date lines
 
//add standard library
#include<math.h>
#include "kaprekarUtils.h"
#include<stdlib.h>

int isKaprekar(int n) {

  if(n < 1) {
    exit(1); //Switched "return false" to "exit(1)" to properly exit the program.  Requires standard library to be present
  }

  int i;
  long square = n * (long) n;
  int numberOfDigits = (int) log10(n) + 1; //Changed numDigits to numberOfDigits to agree with code below and help code be more self explanatory
  long modulus = 0;
  long first, second;

  //for each possible "split" of the square...
  for(i=1; i<=numberOfDigits; i++) {
    //increase the modulus by a factor of 10
    modulus *= 10;

    //split the square into two parts
    first = square / modulus;
    second = square % modulus;

    //test if the split makes a Kaprekar number
    if(second > 0 &&
       first + second == n) {
      return 1;
    }
  }
  return 0;
  
}
