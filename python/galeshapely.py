import sys
import gale
import numpy
malepref=numpy.matrix([[2,4,1,3],[3,1,4,2],[2,3,1,4],[4,1,3,2]])
femalepref=numpy.matrix([[2,1,4,3],[4,3,1,2],[1,4,3,2],[2,1,4,3]])
#malepref,femalepref=gale.readcsv()
global n
#n=4
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

def main():
    galeshapely()
    
if __name__ == '__main__':
    main()


	 
					
