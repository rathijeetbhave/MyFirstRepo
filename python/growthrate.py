import numpy as np
import matplotlib.pyplot as plt

def growthrate():
	n = np.array(range(0,1001))
	a=n+250
	b=n**1.35
	c=500+np.log10(n)
	d=200+np.sqrt(n)
	e=2**(n/100)

	plt.plot(n,a,'r')
	#plt.plot(n,b,'b')
	plt.plot(n,c,'g')
	plt.plot(n,d,'yellow')
	#plt.plot(n,e,'purple')
	plt.show()

def main():
	growthrate()

if __name__ == '__main__':
	main()


