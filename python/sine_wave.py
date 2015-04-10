import math
import itertools
import sys
import numpy
def main():
    size=(20,30)
    rows,cols=size
    x,y=[],[]
    x=numpy.linspace(0,2*numpy.pi,20)
    for i in x:
        y.append(math.sin(i))
    plot(x,y,size)

def plot(x,y,size):
    rows,cols=size
    canvas=make_canvas(rows,cols)
    print canvas
    xmax,xmin=max(x),min(x)
    ymax,ymin=max(y),min(y)
    len_x=float(xmax-xmin)
    len_y=float(ymax-ymin)
#    for x_i,y_i in map_point(x,y,xmin,ymin,xmax,ymax,len_x,len_y,size):
 #       print x,y
     
def make_canvas(rows,cols):
    canvas=numpy.empty((30,80),dtype=str)
    for row in range(rows):
        for col in range(cols):
            canvas[row][col]=" "
    return canvas
def map_point(x,y,xmin,ymin,xmax,ymax,len_x,len_y,size):
    for x_a,y_a in itertools.izip(x,y):
        x_i=(x_a-xmin)/len_x*size[1]
        y_i=(y_a-ymin)/len_y*size[0]
        yield x_i,y_i

        
if __name__=='__main__':
    main()

