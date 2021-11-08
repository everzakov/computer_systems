import sys
from container import Container

def errMessage1():
    print("incorrect command line!\n"+
            "  Waited:\n"+
            "     command -f infile outfile01 outfile02\n"+
            "  Or:\n"+
            "     command -n number outfile01 outfile02\n")


def errMessage2():
    print("incorrect qualifier value!\n"+
            "  Waited:\n"+
            "     command -f infile outfile01 outfile02\n"+
            "  Or:\n"+
            "     command -n number outfile01 outfile02\n")


if __name__ == '__main__':
    argv = sys.argv
    argc = len(argv)

    if argc != 5:
        errMessage1()
        exit(1)
    print("Start")

    container = Container()

    if argv[1] == "-f":
        ifile = open(argv[2])
        str = ifile.read()
        ifile.close()
        strArray = str.replace("\n", " ").split(" ")
        print("Read From File Start")
        container.ReadFromFile(strArray)
        print("Read From File End")
    elif argv[1] == "-n":
        size = 0
        try:
            size = int(argv[2])
            if (not (size > 0 and size <= 10000)):
                print("Number should be: 0 < number <= 10000")
                exit(1)
        except:
            print("Size should be int")
            exit(1)
        print("RND Start")
        container.ReadRnd(size)
        print("RND End")
    else:
        errMessage2()
        exit(1)
    print("Write To File Start")
    ofile = open(argv[3], "w")
    container.WriteToFile(ofile)
    ofile.close()
    print("Write To File End")

    print("Sort Start")
    container.sort()
    print("Sort End")

    print("Write To File Start")
    ofile = open(argv[4], "w")
    container.WriteToFile(ofile)
    ofile.close()
    print("Write To File End")

