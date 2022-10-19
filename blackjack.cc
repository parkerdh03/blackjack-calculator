#include <iostream>
#include <string>
#include <vector>

using namespace std;

int NumericValue(const string &face_value) {
  int numeric_value = 0;

  if ((face_value == "1") || (face_value == "K") || (face_value == "k") ||
      (face_value == "Q") || (face_value == "q") || (face_value == "J") ||
      (face_value == "j")) {
    numeric_value = 10;
  } else if ((face_value == "A") || (face_value == "a")) {
    numeric_value = 11;
  } else {
    numeric_value = stoi(face_value);
  }

  return numeric_value;
}

string FaceValue(const string &card) {
  try {
    return string(1, card.at(0));
  } catch (out_of_range const &problem) {
    cout << "The string doesn't have a 0th letter.\n";
    cout << problem.what() << "\n";
    exit(1);
  }
}

int main(int argc, char const *argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 3) {
    cout << "Please provide two cards.\n";
    cout << "For example:\n";
    try {
      cout << args.at(0) << " AS KH\n";
      cout << args.at(0) << " 3C 4D\n";
    } catch (out_of_range const &problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }
  string card_one;
  string card_two;
  try {
    card_one = args.at(1);
    card_two = args.at(2);
  } catch (out_of_range const &problem) {
    cout << "Uh-oh, you went out of bounds.\n";
    cout << problem.what() << "\n";
    return 1;
  }

  int card_one_value = 0;
  int card_two_value = 0;
  int sum = 0;

  card_one_value = NumericValue(FaceValue(card_one));
  card_two_value = NumericValue(FaceValue(card_two));
  sum = card_one_value + card_two_value;

  cout << card_one << " + " << card_two << " = " << sum << "\n";

  return 0;
}
