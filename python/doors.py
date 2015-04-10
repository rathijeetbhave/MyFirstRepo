def doors():
    	a=[0]*10
	for i in range(1,11):
		for j in range(i,11,i):
			a[j-1]=~a[j-1]
	print a

def main():
	doors()

if __name__ == '__main__':
	main() 
        #sdsgsgszsdgsg
