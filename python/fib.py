import sys
import timeit
def fib(x):
#b= sys.argv[1]
#x=raw_input("enter a no.")
	x=int(x)
	a=range(x-1)
	#print a
	t1=0
	t2=1
	print t2
	for i in a:
	temp= t1+t2
	t1=t2
	t2=temp
	print temp
def main():
	fib(sys.argv[1])

if __name__ == '__main__':
main()
