import numpy as np
from math import *
import sys
import itertools

class canvas():
    def __init__(self,size=None):
        pass
        #if size==None:
            #self.size=(30,70)
        #else:
            #self.size=size
        #canvas=self.make_canvas(self.rows,self.cols)
        #canvas[4][3]='*'
        #self.plot_canvas(canvas,sys.stdout)

    def plot_canvas(self,canvas,output_file):
        for line in canvas:
            output_file.write(' '.join(line))
            output_file.write('\n')

    def make_canvas(self,size):
        rows,cols=size
        canvas=[]
        for i in range(rows):
            canvas.append(list(' ')*cols)
        return canvas
        
class plot(canvas):
    def __init__(self,x,y,size=(30,70)):
        
        #size=(10,10)
        #x=[1,2,3,4,5]
        #y=[2,4,6,8,10]
        #x,y=[],[]
        #for i in range(30):
            #x.append(i)
            #y.append(2*i)
        self.x=x
        self.y=y
        #canvas.__init__(self,size)
        my_canvas=plot.make_canvas(self,size)
        xmin, xmax = min(x), max(x)
        ymin, ymax = min(y), max(y)
        len_x = float(xmax - xmin)
        len_y = float(ymax - ymin)
        for x_i,y_i in self.map_point(x,y,xmin,ymin,xmax,ymax,size,len_x,len_y):
            #print x_i,y_i
            my_canvas[size[0]-x_i-1][y_i]='*'
        plot.plot_canvas(self,my_canvas,sys.stdout)

    def map_point(self,x, y, xmin, ymin, xmax, ymax, size,len_x,len_y):
        """Return a pair of indices corresponding to
        the point x, y in the domain (xmin,...)
        """
        for x_a,y_a in itertools.izip(x,y):
            xi = int(round((x_a - xmin)/len_x*(size[0]-1)))
            yi = int(round((y_a - ymin)/len_y*(size[1]-1)))
            yield xi, yi


def main():
    c=canvas()
    x=[]
    y=np.linspace(0,2*pi,50)
    for num in y:
        x.append(sin(num))
    plot(x,y)

if __name__=='__main__':
    main()

