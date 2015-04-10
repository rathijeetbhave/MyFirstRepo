import numpy
def hungarian():
	m=numpy.matrix([[0.2,8,-5,2],[2,-5,8,0.2],[0.2,8,2,-5],[2,-5,0.2,8]])
	f=numpy.matrix([[2,8,-5,0.2],[0.,-5,2,8],[8,-5,0.2,2],[2,8,-5,0.2]])
	ms=-numpy.sort(-m)
	fs=-numpy.sort(-f)
	print ms
	for i in range(4):
		for j in range(4):
			ms[i,j]=numpy.where(m[i]==ms[i,j])[1]+1
			fs[i,j]=numpy.where(f[i]==fs[i,j])[1]+1

	print ms,fs

