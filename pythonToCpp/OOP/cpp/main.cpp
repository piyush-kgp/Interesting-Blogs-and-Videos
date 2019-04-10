
// Python To C++: Classes, Header Files and Source Files
// https://www.youtube.com/watch?v=GwGo-9kC8to
// Alec Thilenius

#include <iostream>
#include <string>
#include "student.h"

int main(){
  // The easy way
  // Student john("John", 10, 1);
  // Student alec("Alec", 100, 4);
  // Student rick("Rick", 5, 0);
  // Student firstWinner = john.fight(alec);
  // Student finalWinner = firstWinner.fight(rick);
  // std::cout << finalWinner.name << " won!!" << std::endl;

  //the not so easy way
  Student john("John", 10, 1);
  Student alec = Student("Alec", 100, 4);
  Student *rick = new Student("Rick", 5, 0);
  Student firstWinner = john.fight(alec);
  Student finalWinner = firstWinner.fight(*rick);
  std::cout << finalWinner.name << " won!!" << std::endl;
  return 0;
}
