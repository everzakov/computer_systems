import distutils

from animal import *

class Bird(Animal):

    def __init__(self):
        super().__init__()
        self.flyRelationship = None

    def ReadFromFile(self, strArray, i):
        i = super().ReadFromFile(strArray, i)
        if i>=len(strArray) or i == 0:
            return 0
        if (strArray[i] == "True" or strArray[i] == "False"):
            self.flyRelationship = strArray[i] == "True"
            i+=1
        else:
            print("Wrong bool type")
            return 0
        return i

    def ReadRnd(self):
        super().ReadRnd()
        t = get_random_bool()
        if t == 0:
            self.flyRelationship = False
        else:
            self.flyRelationship = True

    def PrintToConsole(self):
        print("Bird: name: {}, weight: {}, flyRelationship: {}, codes / weight: {}".format(self.name, self.weight, self.flyRelationship, self.CodesDividedByWeight()))

    def WriteToFile(self, ostream):
        ostream.write("Bird: name: {}, weight: {}, flyRelationship: {}, codes / weight: {}\n".format(self.name, self.weight, self.flyRelationship, self.CodesDividedByWeight()))

    def Write(self, ostream):
        ostream.write("bird\n")
        ostream.write(str(self.name)+"\n")
        ostream.write(str(self.weight)+"\n")
        ostream.write(str(self.flyRelationship)+"\n")

    def CodesDividedByWeight(self):
        return super().CodesDividedByWeight()