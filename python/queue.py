import numpy
from classqueue import *
def myqueue():
    q=queue()
    for i in range(6):
        q.enqueue(i)
    q.dequeue()
    q.printqueue()


def main():
    myqueue()
    
if __name__ == '__main__':
    main()



