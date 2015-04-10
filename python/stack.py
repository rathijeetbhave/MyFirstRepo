from classstack import *
def mystack():
    s=stack()
    for i in range(6):
        s.push(i)
    s.pop()
    s.Printstack()

def main():
    mystack()
    
if __name__ == '__main__':
    main()


