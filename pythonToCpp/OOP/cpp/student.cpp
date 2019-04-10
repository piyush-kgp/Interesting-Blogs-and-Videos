
#include <iostream>
#include <string>
#include <math.h>
#include "student.h"


Student::Student(std::string name, int sleep, int hangover){
  //constructor, doesnt return anything, notice that nothing to left of fn name
  //constrctor is not actually a function in c++, it's built in the language
  //because you need to have return type for function like int or char or void
  std::cout << name << " is alive!" << std::endl;
  this->name = name;
  this->sleep = sleep;
  this->hangover = hangover;
}

Student Student::fight(Student other){
  double myRating = pow(sleep, -hangover);
  double othersRating = pow(other.sleep, -other.hangover);
  if (myRating>othersRating){
    std::cout << name  << " won vs " << other.name << std::endl;
    return *this;
  } else {
    std::cout << other.name << " won vs " << name << std::endl;
    return other;
  }
}
