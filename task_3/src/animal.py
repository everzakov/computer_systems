from abc import ABC, abstractmethod
from rnd import *
from constants import *

class Animal(ABC):

    def __init__(self):
        self.name = ""
        self.weight = MIN_WEIGHT

    @abstractmethod
    def ReadFromFile(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.name = strArray[i]
        try:
            self.weight = int(strArray[i+1])
            if (self.weight < 1):
                print("Weight cant be < 1")
                return 0
        except:
            return 0
        i += 2
        return i

    @abstractmethod
    def ReadRnd(self):
        self.name = get_random_name()
        self.weight = MIN_WEIGHT + get_random_weight()

    @abstractmethod
    def PrintToConsole(self):
        print("Animal: name: {}, weight: {}, codes / weight: {}".format(self.name, self.weight, self.CodesDividedByWeight()))

    @abstractmethod
    def Write(self, ostream):
        ostream.write("animal\n")
        ostream.write(str(self.name)+"\n")
        ostream.write(str(self.weight)+"\n")

    @abstractmethod
    def WriteToFile(self, ostream):
        ostream.write("Animal: name: {}, weight:{}, codes / weight: {}\n".format(self.name, self.weight, self.CodesDividedByWeight()))

    @abstractmethod
    def CodesDividedByWeight(self):
        sum = 0
        for char in self.name:
            sum += ord(char)
        return sum / self.weight
