import numpy
from classqueue import queue
def bfs():
    popped=[]
    q=queue()
    dist_matrix=numpy.array([[0,1,0,0,0,0],[1,0,1,1,0,0],[0,1,0,1,0,0],[0,1,1,0,1,1],[0,0,0,1,0,0],[0,0,0,1,0,0]])
    n,col=numpy.shape(dist_matrix)
    q.enqueue(1)
    q.printqueue()
    while q.IsEmpty():
   # for i in range(3):
	row=q.dequeue()
        popped.append(row)
        print row
        print q.name
	for j in range(1,n+1):
	    if dist_matrix[row-1,j-1]==1 and j not in popped and j not in q.name:

		q.enqueue(j)
                q.printqueue()
    print popped

def main():
    bfs()
    
if __name__ == '__main__':
    main()


