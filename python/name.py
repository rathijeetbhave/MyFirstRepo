import numpy

def name():

	a=numpy.loadtxt('name.csv',
					delimiter=",",
					unpack=True,
					dtype='str')
	#print a[0][10]
	#print range(len(a)),range(len(a[0]))
	for j in range(len(a)):
		for i in range(len(a[j])):
			if(ord(a[j][i])==32):
				a[j]=a[j][0].upper() + a[j][1:i] + ' ' + a[j][i+1].upper() + a[j][i+2:]
				saveFile=open('capital.csv','a')
				saveFile.write(a[j] + '\n')
				saveFile.close()
				print a[j]


def main():
	name()

if __name__ == '__main__':
	main()
