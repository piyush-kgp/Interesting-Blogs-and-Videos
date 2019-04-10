

// https://www.youtube.com/watch?v=Rub-JsjMhWY&t=2291s
// derek banas nice video


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void makeYoung(int *age){
  (*age)--; // --takes precedence over * as an operator so we need paranthesis
}

void makeYoungV2(int *ptr){
  (*ptr)--;
}

void makeYoungV3(int &age){
  age--;
}

void makeYoungV4(int &age){
  age--;
}


class Animal{
  private: //means these can only be changed from functions defined inside the class this is called encapsulation
    int height;
    int weight;
    string name;
    static int numOfAnimals; //means this varible's value is shared by every object of Animal class ever created
    // think of @staticmethod

  public:
    int getHeight(){ return height; }
    int getWeight(){ return weight; }
    string getName(){ return name; }
    void setHeight(int h){ height = h; }
    void setWeight(int w){ weight = w; }
    void setName(string n){ name = n; }

    void setAll(int, int, string); //prototype of a fn.

    Animal(int, int, string); //prototype of constructor

    ~Animal(); //prototype of destructor

    Animal(); //another constructor that doesnt receive anything
    // this is an example of operator overaloading
    // to overload a function name is same but arguments are differnt

    static int getNumOfAnimals(){ return numOfAnimals; }

    void toString();

}; //similar to struct classes also need a semicolon at end


//one weird thind with cpp is if you are defining methods inside class you call
//your object attributes directly as attr and when outside you use this->attr


//let us actually define the methods whose prototypes we declared to the class
int Animal::numOfAnimals = 0;

void Animal::setAll(int h, int w, string n){
  cout << "setting attributes" << endl;
  this->height = h; //think of this as self.height = h
  this->weight = w;
  this->name = n;
  Animal::numOfAnimals++;
}


Animal::Animal(int h, int w, string n){
  //doing same thing as setAll but using constructor
  cout << "creating animal with attributes" << endl;
  this->height = h; //think of this as self.height = h
  this->weight = w;
  this->name = n;
  Animal::numOfAnimals++;
}


Animal::~Animal(){
  cout << this->name << " destroyed." << endl;
}


Animal::Animal(){
  //overloaded constructor
  cout << "Animal created with nothing " << endl;
  Animal::numOfAnimals++;
};

void Animal::toString(){
  cout << this->name << " is " << this->height << " cms tall and " << \
  this ->weight << " kgs in weight" << endl;
}



//Inheritance
class Dog: public Animal{
private:
  string sound = "woof";
public:
  string getSound(){ return sound ; }
  Dog(int, int, string, string);
  Dog() : Animal(){}; //inherit
  void toString(); //overwrites the Animal's toString method
};

//actually defining those methods
Dog::Dog(int h, int w , string n, string bark) : Animal(h, w, n){
  //inherits constrctor from superclass
  this->sound = bark;
}

void Dog::toString(){
  // Animal::toString is overwritten completely
  cout << this->getName() << " is " << this->getHeight() << " cms tall, " << \
  this->getWeight() << " kgs in weight " << "and says " << this->getSound() << endl;
}


int overload(int);
int overload(char); //overaloading



class Animally{
public:
  void getFamily(){ cout << "we are animals" << endl; }
  virtual void getClass(){ cout << "I am an animal" << endl; }
};

class Doggy : public Animally{
public:
  void getClass(){ cout << "I'm a dog" << endl; }
};


class GermanShepard: public Doggy{
public:
  void getClass(){ cout << "I'm a German Shepard" << endl; }
  void getDerived(){ cout << "I'm an animal and a dog" << endl; }
};


void whatClassAreYou(Animally *ani){
  ani->getClass();
}

int main(){
  //use switch
  int greeting = 2;
  switch (greeting) {
    // runs everything once case==option till break
    case 2: cout << "bonjour" << endl;
    // break makes sure we exit switch
    case 3: cout << "hola" << endl; break;
    default: cout << "uvw" << endl; // doesnt print because of break
  }

  //ternary op.
  //var=(cond)?true:false
  int bigger = (5>2)?5:2;
  cout << "bigger among 5 and 2 is " << bigger << endl;

  //arrays
  char chuck[2][6] = {{'c', 'h', 'u', 'c', 'k'}, {'c', 'h', 'e', 'e', 's', 'e'}};
  int nums[] = {3,2,4,0,1};
  cout << "size of array: " << sizeof(nums)/sizeof(nums[0]) << endl;
  cout << nums[10]<<endl; // gives us random number present at memory


  //for, while - easy


  // //do-while
  // int guess = 0; //remember ints are initiated with a random integer
  // string temp;
  // do{
  //   cout << "Guess a number between 1 and 10\n";
  //   getline(cin, temp);
  //   guess = stoi(temp);
  // }while(guess!=4);


  // //similar to python strings
  // char happy[6] = {'h', 'a',  'p', 'p', 'y', '\0'};
  // string bday = "birthday";
  // cout << happy+bday << endl;
  // cout << "what's your name\n";
  // string name;
  // getline(cin, name);
  // cout << "Hello "+name << endl;

  int x = stoi("531");
  double y = stod("-121.121");
  cout << x << " "<< y << endl;

  //c++ has a string comparison thing ie a string can be greater or smaller than
  // another.
  // I know.. weird.
  string cat = "cat";
  string dog = "dog";
  cout << dog.compare(dog) << endl; //0
  cout << cat.compare(dog) << endl; //-1(or neg int) cat<dog
  cout << dog.compare(cat) << endl; //1(or pos int) dog>cat


  // //string assign, erase, replace, insert
  // string name;
  // getline(cin, name);
  // cout << "Hello "+name << endl;
  // string wholename = name.assign(name);
  // string firstname = wholename.assign(wholename, 0, 5); //chuck cheese
  // cout << firstname << endl;
  // int lastname_index = name.find("cheese");
  // cout << "lastname_index " << lastname_index << endl;
  // name.insert(5, "Justin");
  // cout << "insert Justin at 5 " << name << endl;
  // name.erase(6, 7);
  // cout << "erase 6 to 7 " << name << endl;
  // name.replace(6, 3, "Maximus");
  // cout << "replace from 6 to 6+3 with Maximus " << name << endl;


  //vectors
  vector<int> lottery(10);
  int numslottery[5] = {30,20,40,10,50};
  lottery.insert(lottery.begin(), numslottery, numslottery+3);
  cout << "Lottery example " << lottery.at(4) << endl; //gives 0 as we have nothing at 4
  // and vectors are initialized with all 0s.
  cout << "size of vector " << lottery.size() << endl; //gives us 13 which means that
  //since we used insert, numbers 30, 20, 40 got inserted at 0 and moving the rest to right
  lottery.insert(lottery.begin()+5, 40); //another way to use insert now size is 14
  cout << "new size " << lottery.size() << endl;
  lottery.push_back(64); //size now 15
  cout << "new size " << lottery.size() << endl;
  //current vector {30, 20, 40, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 64}
  cout << "Last value " << lottery.back() << endl;
  lottery.pop_back(); //pops 64
  cout << "size after popping " << lottery.size() << endl;
  cout << "First value " << lottery.front() << endl;
  cout << "Is vector empty " << boolalpha << lottery.empty() << endl;


  //functions - easy, same as pythons


  // file i/o
  string stevequote = "A day without sunshine is like you know night";
  ofstream writer("steve.txt");
  if (!writer){
    cout << "Error creating file" << endl;
    return -1;
  } else {
    writer << stevequote;
    writer.close();
  }
  ofstream writer2("steve.txt", ios::app);
  //ios::app - append
  //ios::binary - treat as binary
  //ios::in - read input
  //ios::trunc - default
  //ios::out - write output
  if (!writer2){
    cout << "Error creating file" << endl;
    return -1;
  } else {
    writer2 << "\n - Steve Martin" << endl;
    writer2.close();
  }

  ifstream reader("steve.txt");
  if (!reader){
    cout << "Error opening file" << endl;
    return -1;
  } else {
    char letter;
    while (!reader.eof()){
      reader.get(letter);
      cout << letter;
    }
    cout << endl;
  }


  //exception handling - Divide by zero error
  int num = 0;
  try{
    if (num!=0) cout << 2/num << endl;
    else{
      throw num;
      cout << "After throw nothing is executed\n";
    }
  } catch(int number) {
    cout << number << " is not valid" << endl; //throw calls the catch f_n.
  }
  // notice how the construct is different from python
  //specifically we are not really allowing anything to happen inside try(which I would like)
  // but instead specifying rules so compiler knows beforehand when it's gonna run
  // into a problem.. (which I dont like)

  //catch is really like any other function and you can define multiple such
  //and what gets called depends on the dtype of what throw is called upon (I know... very weird)
  try{
    // char *x = "foo bar"; //prints annoying warnings
    char *x = (char *)"foo bar";
    throw x;
  } catch (int x) {
    cout << "caught an integer" << endl;
  } catch (char *x){
    cout << "caught a char pointer " << x << endl;
  }
  //there is also a catch(...) that gets called if x is none of the things on which catch is defined
  //for example
  try{
    throw 10.5;
  } catch (int x) {
    cout << "caught an integer" << endl;
  } catch (char *x){
    cout << "caught a char pointer " << x << endl;
  } catch (...){
    cout << "I dont know what I caught" << endl;
  }



  //pointers and references
  int age = 1000;
  char grade = 'A';
  cout << "size of int " << sizeof(age) << endl; //4 bytes
  cout << "size of char " << sizeof(grade) << endl; //1 byte
  cout << "age is located at " << &age << endl; //gives a hex memory address
  cout << "grade is located at " << &grade << endl;  //gives a char

  int ages[5] = {5,1,2,3,4};
  int *agePtr = ages; // pointer to int
  cout << "address "<< agePtr << " value " << *agePtr << endl;
  agePtr++;
  cout << "address "<< agePtr << " value " << *agePtr << endl;
  cout << "address "<< ages << " value " << *ages << endl;

  cout << "current age " << age << endl;
  makeYoung(&age);
  cout << "new age " << age << endl;

  int *ptr = &age;
  makeYoungV2(ptr);
  cout << "new age " << age << endl;
  //both are exactly same thing

  makeYoungV3(age);
  cout << "new age " << age << endl;
  //this is passing by refernce rather than by pointer
  //we can also do this as
  int &ageRef = age;
  makeYoungV4(ageRef);
  cout << "new age " << age << endl;

  //when to use pointers vs references
  //no hard rule but I like pointers


  //OOP..yay
  Animal fred;
  fred.setHeight(30);
  fred.setWeight(10);
  fred.setName("Fred");
  cout << fred.getName() << " is " << fred.getHeight()  << " cms tall and " << \
  fred.getWeight()  << " kgs in weight" << endl;

  Animal tom(36, 15, "Tom");
  tom.toString();
  // tom.setAll(40, 20, "Tommy");
  // tom.toString();
  // // tom.height = 20; //cant do this because height is private

  Dog spot(38, 16, "Spot", "woooooofff");
  spot.toString();
  spot.Animal::toString();

  cout << "Number of animals " <<  Animal::getNumOfAnimals() << endl; //tommy, fred, spot

  cout << "************************" << endl;
  //virtual methods and polymorphism
  Animally *ani = new Animally;
  Doggy *dogg= new Doggy;
  ani->getClass();
  dogg->getClass();
  //this runs fine but what if we need conflicting methods from a function
  // for this we need virtual keyword
  whatClassAreYou(ani);
  whatClassAreYou(dogg);

  cout << "##########################" << endl;
  Doggy spotty;
  GermanShepard max;
  Animally *ptrSpt = &spotty; //notice that we're able to create parent class pointer
  //with child class object
  Animally *ptrMax = &max;
  ptrSpt->getFamily();
  ptrSpt->getClass();
  ptrMax->getFamily();
  ptrMax->getClass();

  cout <<"________DONE_________"<<endl;
  return 0;
}
