import sys
import gale
import numpy
malepref=numpy.matrix([[1,4,3,2],[1,2,3,4],[2,4,3,1],[3,1,2,4]])
femalepref=numpy.matrix([[3,1,2,4],[1,4,3,2],[2,4,3,1],[4,2,1,3]])
#malepref,femalepref=gale.readcsv()
#print sys.argv[1]
#malepref,femalepref=gale.readcsv(sys.argv[1],sys.argv[2])
#femalepref=gale.readcsv(sys.argv[2])

global n
#n=4
#def galeshapely(c,d):
def galeshapely():
	global n
	n=malepref.shape[0]
	print n
	nextcolumn=malepref[:,0]
	print nextcolumn
	j=-1
    	#i=0
    	missingvalue=numpy.random.rand(n,1)
	engaged=numpy.random.rand(n,2)
	k=[0]*n
	#k=numpy.matrix([[0],[0],[0],[0]])
	z=k
	print z
	while numpy.linalg.norm(missingvalue!=0):
		j=j+1
		for i in range(n):
			print nextcolumn[i]
			if nextcolumn[i]!=0:
				#print nextcolumn
				pos=gale.equal(nextcolumn,nextcolumn[i])
				print pos
				print femalepref[malepref[i,z[i]]-1,:]
				rowpos=gale.findpos(femalepref[malepref[i,z[i]]-1,:],pos)
				print rowpos
				minvalue=gale.findmin(rowpos)
				print minvalue
				if j==0:
					engaged[i,0]=malepref[i,0]
                			engaged[i,1]=femalepref[malepref[i,j]-1,minvalue-1]
				if j!=0:
					row=gale.findmin(rowpos)
					print row
					print nextcolumn[i]
					print femalepref[int(nextcolumn[i])-1,:].T
					if engaged[numpy.where(engaged[:,0]==malepref[i,z[i]]),1]<n+1:
			                	position=gale.findmin(gale.equal(femalepref[int(nextcolumn[i])-1,:].T,engaged[int(nextcolumn[i])-1,1]))
						print position
					print minvalue
					if engaged[numpy.where(engaged[:,0]==malepref[i,z[i]]),1]>n:
						engaged[numpy.where(engaged[:,0]==malepref[i,z[i]]),1]=femalepref[int(nextcolumn[i])-1,minvalue-1]
					elif minvalue<position:
				                engaged[numpy.where(engaged[:,0]==malepref[i,z[i]]),1]=femalepref[int(nextcolumn[i])-1,minvalue-1]
					else:
                				engaged[numpy.where(engaged[:,0]==malepref[i,z[i]]),1]=femalepref[int(nextcolumn[i])-1,position-1]
				print engaged
		if j==0:
			engageddash=gale.findpair(engaged)
            		engaged=engageddash
            		print engaged            	
         	missingvalue=gale.findmissingvalue(engaged[:,1])
		print missingvalue
		print z
		#print missingvalue[2,0],z[i]+1
		nextcolumn,z=gale.findnextcolumn(missingvalue,malepref,z)
		print nextcolumn 
	

'''def equal(a,x): 
	#x=3
	pos=numpy.random.rand(n,1)
	#print a
	for m in range(n):
		if a[m]==0: 
			pos[m]=0			
		elif a[m]==x:
			pos[m]=m+1			
		else:
			pos[m]=0
	#return m
	return pos

def findmin(col):
	#col=numpy.matrix([[1],[2],[3],[0]])
	minimum=col[col>0].min() 
	return(minimum)

def hello(n):
	for i in range(n):
		print 'hello'
		print 2
def findmissingvalue(engagged):
	b=1
	#engagged=numpy.matrix([[1],[2],[2],[4]])
	missingvalue=numpy.random.rand(n,1)
	for i in range(n):
		f=b in engagged
		if f==False:
			missingvalue[i]=i+1
			b=b+1
		else:
			missingvalue[i]=0
			b=b+1
	return missingvalue	

def findnextcolumn(missingvalue,malepref,k):
	#missingvalue=numpy.matrix([[1],[0],[3],[0]])
	#malepref=numpy.matrix([[2,1,3,4],[4,1,2,3],[1,3,2,4],[2,3,1,4]])
	#k=numpy.matrix([[0],[0],[0],[0]])
	nextcolumn=numpy.random.rand(n,1)
	for i in range(n):
		if missingvalue[i]==0:
			nextcolumn[i]=0
		else:
			#print malepref[missingvalue[i]-1,k[i]+1]
			nextcolumn[i]=malepref[missingvalue[i,0]-1,k[i]+1]
			k[i]=k[i]+1
	z=k
	return (nextcolumn,z)

def findpair(engageddash):
	k=4
	#engageddash=numpy.matrix([[3,2],[3,2],[3,2],[2,3]])
	engaged=numpy.random.rand(n,2)
	for j in range(1,n+1):
		f=j in engageddash[:,0]
		for i in range(n):
			if f==False:
				engaged[j-1,0]=j
				engaged[j-1,1]=k+1
				k=k+1
			else:
				c=numpy.where(engageddash[:,0]==j)
				engaged[j-1,0]=j
				engaged[j-1,1]=engageddash[c[0][0],1]
	return engaged

def findpos(row,col):
	#n=4
	rowpos=numpy.random.rand(n,1)
	for i in range(n):
		for j in range(n):
			if col[i]==row[0,j]:
				rowpos[i]=j+1
				break
			else:
				rowpos[i]=0
	return rowpos

def readcsv(A,B):
	print A
	a=numpy.loadtxt('A.csv',
					delimiter=",",
					unpack=True,
					dtype='str')
	b=numpy.loadtxt('B.csv',
					delimiter=",",
					unpack=True,
					dtype='str')
	for i in range(1,n+1):
		a[a=='W'+str(i)]=i
		b[b=='M'+str(i)]=i
	#print a
	malepref=numpy.matrix(a)[1:n+1,:].T.astype('int')
	femalepref=numpy.matrix(b)[1:n+1,:].T.astype('int')
	#print malepref[1,:],femalepref[:,1]
	return (malepref,femalepref) '''

def main():
	galeshapely()

if __name__ == '__main__':
	main()

