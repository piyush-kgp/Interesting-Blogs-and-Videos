
#include <string>

class Student{
private:
  int sleep, hangover;
public:
  std::string name;
  Student(std::string, int, int); //constructor
  Student fight(Student);
};
