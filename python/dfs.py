import numpy
from classstack import *
def dfs():
    graph=numpy.array([[0,1,0,0,0,0],[1,0,1,1,0,0],[0,1,0,1,0,0],[0,1,1,0,1,1],[0,0,0,1,0,0],[0,0,0,1,0,0]])
    s=stack()
    visited=[]
    n,col=numpy.shape(graph)
    s.push(1)
    while s.IsEmpty():
        row=s.pop()
        visited.append(row)
        for j in range(1,n+1):
            if graph[row-1,j-1]==1 and j not in visited and j not in s.name:
                s.push(j)

    print visited


def main():
   dfs()
    
if __name__ == '__main__':
    main()


