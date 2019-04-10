
class Student:
    def __init__(self, name, sleep, hangover):
        self.name = name
        self.sleep = sleep
        self.hangover = hangover
        print(name + " is alive!")

    def fight(self, other):
        myRating = self.sleep**-self.hangover
        othersRating = other.sleep**-other.hangover
        if myRating>othersRating:
            print(self.name + " won vs " + other.name)
            return self
        else:
            print(other.name + " won vs " + self.name)
            return other
