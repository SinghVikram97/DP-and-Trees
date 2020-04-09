// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/
#include <bits/stdc++.h>
using namespace std;
int help(string &s)
{

  int n = s.length();

  // a represents possible no of subsequences ending with a (a^i) where i>=1 ex. a,aa,aaa etc.
  int a = 0;
  // b represents possible no of subsequences ending with ab (a^i b^j) where i>=1,j>=1 ex. ab,aab,abb etc.
  int b = 0;
  // c represents possible no of subsequences ending with ab (a^i b^j c^k) where i>=1,j>=1,k>=1 ex. abc,abbc,abcc,aabc etc.
  int c = 0;

  for (int i = 0; i < n; i++)
  {

    if (s[i] == 'a')
    {
      // Incoming a
      // Can be joined with all existing subseqence ending with a so --> a possiblities more
      // Or can be starting of a new a subsequqence --> 1
      // And we have existing a as well (if we don't consider this incoming a) --> a
      // So a=(a)+(a+1)
      // a=(2*a)+1
      a = (2 * a) + 1;
    }
    else if (s[i] == 'b')
    {
      // Incoming b
      // Can be joined with all existing subsequnce starting with a and ending with b (abb)--> b possibilites
      // Or can be taken as a new b and can be joined with existing subsequences ending with a --> a possibilties
      // And we have existing subsequences as well --> b
      // So b=(b)+(b+a)
      // b=(2*b)+a
      b = (2 * b) + a;
    }
    else if (s[i] == 'c')
    {
      // Incoming c
      // Can be joined with all existing subsequnce starting with a, having b inbetween and ending with c (abbcc)--> c possibilites
      // Or can be taken as a new c and can be joined with existing subsequences ending with b and starting with a --> b possibilties
      // And we have existing subsequences as well --> c
      // (Can't be joined with a as we need a inbetween)
      // So c=(c)+(c+b)
      // c=(2*c)+b
      c = (2 * c) + b;
    }
  }
  return c;
}
int main()
{
  string s;
  cin >> s;
  cout << help(s) << endl;
}