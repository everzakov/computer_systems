from bird import Bird
from rnd import *
from beast import Beast
from fish import Fish

class Container:

    def __init__(self):
        self.container = []

    def PrintToConsole(self):
        print("Container is store ", len(self.container), "animals:")
        for animal in self.container:
            animal.PrintToConsole()
        print("Summa of codes / weights  = ", self.CodesDividedByWeight())

    def Write(self, ostream):
        ostream.write(str(len(self.container))+"\n")
        for animal in self.container:
            animal.Write(ostream)

    def WriteToFile(self, ostream):
        ostream.write("Container is store "+str(len(self.container))+ " animals:\n")
        i = 0
        for animal in self.container:
            ostream.write(str(i)+" ")
            animal.WriteToFile(ostream)
            i+=1
        ostream.write("Summa of codes / weights  = {}\n".format(self.CodesDividedByWeight()))

    def ReadRnd(self, size):
        while len(self.container) < size:
            t = get_random_type()
            if t == 0:
                beast = Beast()
                beast.ReadRnd()
                self.container.append(beast)
            elif t == 1:
                bird = Bird()
                bird.ReadRnd()
                self.container.append(bird)
            elif t == 2:
                fish = Fish()
                fish.ReadRnd()
                self.container.append(fish)

    def ReadFromFile(self, strArray):
        if (len(strArray) == 0):
            print("File is empty")
            exit(1)
        try:
            size = int(strArray[0])
            if (not (size > 0 and size <= 10000)):
                print("Number should be: 0 < number <= 10000")
                exit(1)
        except:
            print("Number of animals should be int")
            exit(1)
        i = 1
        while i < len(strArray) and len(self.container) < size:
            try:
                type = strArray[i]
                i += 1
                if type == "beast":
                    beast = Beast()
                    i = beast.ReadFromFile(strArray, i)
                    self.container.append(beast)
                elif type == "bird":
                    bird = Bird()
                    i = bird.ReadFromFile(strArray, i)
                    self.container.append(bird)
                elif type == "fish":
                    fish = Fish()
                    i = fish.ReadFromFile(strArray, i)
                    self.container.append(fish)
                else:
                    print("Wrong Animal Type")
                    exit(1)
                if i == 0:
                    print("Something got wrong")
                    exit(1)
            except EOFError:
                print("Size Of Animal is less than N")
                exit(1)
        if (len(self.container) < size):
            print("Size Of Animal is less than N")
            exit(1)

    def sort(self):
        for i in range(len(self.container)):
            for j in range(i+1, len(self.container)):
                if self.container[j].CodesDividedByWeight() > self.container[i].CodesDividedByWeight():
                    self.container[i], self.container[j] = self.container[j], self.container[i]

    def CodesDividedByWeight(self):
        sum = 0
        for animal in self.container:
            sum += animal.CodesDividedByWeight()
        return sum