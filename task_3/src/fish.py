from enum import Enum

from animal import *


class FishType(Enum):
    RIVER = "RIVER"
    SEA = "SEA"
    LAKE = "LAKE"


class Fish(Animal):

    def __init__(self):
        super().__init__()
        self.place = None

    def ReadFromFile(self, strArray, i):
        i = super().ReadFromFile(strArray, i)
        if (i >= len(strArray) or i == 0):
            return 0
        place = strArray[i]
        if place == FishType.RIVER.name:
            self.place = FishType.RIVER
        elif place == FishType.SEA.name:
            self.place = FishType.SEA
        elif place == FishType.LAKE.name:
            self.place = FishType.LAKE
        else:
            print("Wrong fish place")
            return 0
        i+=1
        return i

    def ReadRnd(self):
        super().ReadRnd()
        place = get_random_type()
        if place == 0:
            self.place = FishType.RIVER
        elif place == 1:
            self.place = FishType.SEA
        elif place == 2:
            self.place = FishType.LAKE

    def PrintToConsole(self):
        print("Fish: name: {}, weight: {}, place: {}, codes / weight: {}".format(self.name, self.weight, self.place.name, self.CodesDividedByWeight()))

    def Write(self, ostream):
        ostream.write("fish\n")
        ostream.write(str(self.name)+"\n")
        ostream.write(str(self.weight)+"\n")
        ostream.write(str(self.place.name)+"\n")

    def WriteToFile(self, ostream):
        ostream.write("Fish: name: {}, weight: {}, place: {}, codes / weight: {}\n".format(self.name, self.weight, self.place.name, self.CodesDividedByWeight()))

    def CodesDividedByWeight(self):
        return super().CodesDividedByWeight()
