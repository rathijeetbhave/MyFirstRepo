def fib(n):    # write Fibonacci series up to n a, b = 0, 1
    a,b=0,1
    while b < n:
        print b,
        a, b = b, a+b
	return 2
def fib2(n): # return Fibonacci series up to n
    result = []
    a, b = 0, 1
    k=0
    for k in range(n):
        result.append(a)
        a, b = b, a+b
    return result

def findmin(col):
	#col=numpy.matrix([[1],[2],[3],[0]])
	minimum=col[col>0].min() 
	print minimum

def hello(n):
	for i in range(n):
		print 'hello'

#def myfib(n):
 #   for num in range(n):

