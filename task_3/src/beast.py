from enum import Enum

from animal import *

class BeastType(Enum):
    PREDATORS = "PREDATORS"
    HERBIVORES = "HERBIVORES"
    INSECTIVORES = "INSECTIVORES"

class Beast(Animal):

    def __init__(self):
        super().__init__()
        self.type = None

    def ReadFromFile(self, strArray, i):
        i = super().ReadFromFile(strArray, i)
        if (i >= len(strArray) or i == 0):
            return 0
        t = strArray[i]
        if t == BeastType.PREDATORS.name:
            self.type = BeastType.PREDATORS
        elif t == BeastType.HERBIVORES.name:
            self.type = BeastType.HERBIVORES
        elif t == BeastType.INSECTIVORES.name:
            self.type = BeastType.INSECTIVORES
        else:
            print("Wrong Beast Type")
            return 0
        i += 1
        return i

    def ReadRnd(self):
        super().ReadRnd()
        t = get_random_type()
        if t == 0:
            self.type = BeastType.PREDATORS
        elif t == 1:
            self.type = BeastType.HERBIVORES
        elif t == 2:
            self.type = BeastType.INSECTIVORES

    def PrintToConsole(self):
        print("Beast: name: {}, weight: {}, type: {}, codes / weight: {}".format(self.name, self.weight, self.type.name, self.CodesDividedByWeight()))

    def WriteToFile(self, ostream):
        ostream.write("Beast: name: {}, weight: {}, type: {}, codes / weight: {}\n".format(self.name, self.weight, self.type.name, self.CodesDividedByWeight()))

    def Write(self, ostream):
        ostream.write("beast\n")
        ostream.write(str(self.name)+"\n")
        ostream.write(str(self.weight)+"\n")
        ostream.write(str(self.type.name)+"\n")

    def CodesDividedByWeight(self):
        return super().CodesDividedByWeight()
