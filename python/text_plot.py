def Range(a,size):
    if (round(min(a)) ==0 and round(max(a))==0):
        a_new=[]
        for i in range(len(a)):
            a_new.append(int(round(a[i])))
        return a_new
    a_new=[]
    a_max=max(a)
    a_min=min(a)
    if a_min <0:
        a_range=a_max-a_min
    else:
        a_min=0
        a_range=a_max
    for i in range(len(a)):
        k=(float(a[i]-a_min)*size/a_range)
        a_new.append(int(round(k)))
    #print a_new
    return a_new
def plot_list(x_new,y_new):
    y_plot=sorted(y_new,reverse=True)
    x_plot=[]
    for k in range(len(y_plot)):
        num=y_plot[k]
        if (k>0 and num==y_plot[k-1]):
            indx=y_new.index(num,indx+1)
        else:
            indx=y_new.index(num)
        x_plot.append(x_new[indx])
    i=0
    while i<len(y_plot):
        a=y_plot[i]
        k=y_plot.count(a)
        temp=x_plot[i:i+k-1]
        x_plot[i:i+k-1]=sorted(temp)
        i=i+k
    #print x_plot,y_plot,sorted(x_plot)
    return x_plot,y_plot
def print_str(x_list,x_zero):
    str=''
    j=0
    for i in range(len(x_list)):
        while j <= x_list[i]:
            if (j==x_zero and j!=x_list[i]):
                str=str+'|'
            elif j==x_list[i]:
                str=str+'*'
            else:
                str=str+' '
            j=j+1
    str=str+'\n'
    return str

def zeroaxes(x,y,Hor_size,Ver_size):
    x_zero,y_zero=0,0
    if round(min(x)) < 0 :
        x_zero=int(round(-min(x)*Hor_size/(max(x)-min(x))))
    if round(min(y)) < 0:
        y_zero=int(round(-min(y)*Ver_size/(max(y)-min(y))))
    return x_zero,y_zero
def check(x,y):
    try:
        if len(x) !=len(y):
            raise IndexError
        for i in range(len(x)):
            a=int(x[i])
            b=int(y[i])
    except (ValueError,IndexError),e:
        if __name__=='__main__':
            print "Eror in the input",e
        return e
    return 1
def plot(x,y):
    Hor_size=80
    Ver_size=30
    e=check(x,y)
    if e!=1:
        return e
    x_zero,y_zero=zeroaxes(x,y,Hor_size,Ver_size)
    x_new=Range(x,Hor_size)
    y_new=Range(y,Ver_size)
    x_plot,y_plot=plot_list(x_new,y_new)
    Full_str=''
    for i in range(Ver_size,-1,-1):
        if i==y_zero:
            str=''
            for j in range(Hor_size+1):
                if (j in x_plot and y_plot[x_plot.index(j)]==y_zero):
                    str=str+'*'
                else:
                    str=str+'-'
            Full_str=Full_str+str+'\n'
        elif i in y_plot:
            indx=y_plot.index(i)
            y_count=y_plot.count(i)
            xlist=[x_zero]
            for j in range(y_count):
                xlist.append(x_plot[indx+j])
            xlist.sort()
            str=''
            for j in range(max(xlist)+1):
                if (j in xlist and j !=x_zero):
                    str=str+'*'
                elif j==x_zero:
                    str=str+'|'
                else:
                    str=str+' '
            Full_str=Full_str+str+'\n'
        else:
            str=''
            for j in range(x_zero):
                str=str+' '
            Full_str=Full_str+str+'|\n'
    #print __name__
    if __name__=='__builtin__':
        print Full_str
    else:
        return Full_str
if __name__=='__main__':
    import math
    x=[]
    y=[]
    for i in range(51):
        x.append(i)
        y.append(math.sin(i*2*math.pi/50))
    str=plot(x,y)
    print str
                