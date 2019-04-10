
from student import Student

john = Student("John", 10, 1)
alec = Student("Alec", 100, 4)
rick = Student("Rick", 5, 0)

firstWinner = john.fight(alec)
finalWinner  = firstWinner.fight(rick)
print(finalWinner.name + " won!! ")
