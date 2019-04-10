
This can serve as a tool to quickly learn c++ if you're an expert in python.

###### Quick Tips
- 70-80% of moving from python to cpp is just getting used to the syntax
- indents becomes curly braces
- get used to thinking of datatypes for everything before using it
- everything in a if or while condition should be in paranthesis
- should have a main function
- dont forget the semicolon at every EOL.

These will get you through for a lot of stuff.

What you'll really need to learn to actually use C++ effectively is pointers and addresses. In C++ we can change a variable value without changing it:
```
int x = 0;
int *ptr = &x;
void change(ptr){
  *ptr = 100;
}
//use in main as
change(ptr);
cout << x << endl; //prints 100 not 0
```

Classes in Python and C++ are though syntactically not similar, the thought process
is exactly the same.
There is everything you liked in  Python classes: Inheritance, static methods, instance methods etc (but no class methods, make do with static methods);

One major change you'll notice is in C/C++, you dont need to define your function straight away. You can declare them just as you would a variable and then define later.

In proper projects you'd do the declaration stuff in a header file.

Makefile is a whole other concept. As you'll see it is very useful though for large (or even small) projects.
