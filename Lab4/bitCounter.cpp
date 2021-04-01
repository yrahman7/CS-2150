#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int numOf1s(int n) {
  int count = 0;
  if (n == 1)
    count++;
  else {
    if (n%2 == 0)
      count = numOf1s(n/2);
    else
      count = numOf1s(n/2) + 1;
  }
  return count;
}

string Int2String(int n) { //helper function for base conversion
  if (n >= 0 && n <= 9) {
    string result = to_string(n);
    return result;
  }
  else {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result(1, alphabet.at(n - 10));
    return result;
  }
}

void reverseString(string& str) { //helper function for base conversion
  int n = str.length();
  for (int i = 0; i < n/2; i++)
    swap(str[i], str[n-i-1]);
}

string convert(string toConvert, int startBase, int endBase) {
  //convert from start base to base 10
  int converted = 0;
  int j = 0;
  for(int i = toConvert.length() - 1; i >= 0; i--) {
    if (startBase <= 10)
      converted += (toConvert.at(i) - '0') * pow(startBase, j);
    else
      converted += (toConvert.at(i) - '0' - 7) * pow(startBase, j);
    j++;
  }
  if (endBase != 10) {
  //convert from base 10 to end base
    int remainder;
    string result;
    while (converted != 0) {
      remainder = converted % endBase;
      converted /= endBase;
      string str = Int2String(remainder);
      result.append(str);
    }
    reverseString(result); //reverse string helper function called
    return result;
  }
  else
    return to_string(converted);
}

int main(int argc, char **argv) {
  if (argc == 5) {
    string input = argv[1];
    string input2 = argv[2];
    string input3 = argv[3];
    string input4 = argv[4];

    int result1 = numOf1s(stoi(input));
    string result2 = convert(input2, stoi(input3), stoi(input4));

    cout << input << " has " << result1 << " bit(s)" << endl;
    cout << input2 << " (base " << input3 << ") = " << result2 << " (base " << input4 << ")" << endl;
  }
  else
    cout << "Not the right amount of arguments" << endl;
}
