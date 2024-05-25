def Summchet(FileName):
	try:
		f=open(FileName,"r")
		sum=0
		n=0
		for s in f:
			for s1 in s.split(' '):
				for s2 in s1.split(','):
					for s3 in s2.split('\t'):
						for s4 in s3.split('\n'):
							for s5 in s4.split('.'):
								try:
									if s5!=(''):
										i=int(s5)
										if i%2==0:
											n+=1
											sum+=i
								except ValueError:
									print("Error word:",s5,sep="", end="\n")
		f.close()
		if n>0:
			return 0,sum
		else:
			return 0,None
	except FileNotFoundError:
		return -2,0
#---------------------------------------------------------------------------------------------------------------------------

def sravn(FileName):
	try:
		f=open(FileName,'r')
		A=True
		for s in [sx for s1 in f for s2 in s1.split('\t') for s3 in s2.split(' ') for s4 in s3.split('.') for s5 in s4.split(',') for sx in s5.split('\n') if sx!=("")]:
			try:
				vmin = int(s) if A else min(vmin,int(s))
				A=False
			except ValueError:
				print('Error word',s)
		return 0,vmin
	except FileNotFoundError:
		print("Cant open file")
		return -1,None
	except UnboundLocalError:
		print("Fali is empty")
		return -2,None
#---------------------------------------------------------------------------------------------------------------------------
def main2():
	vmin,err=0,None
	err,vmin=sravn('KEK.txt')
	if err:
		print("Error",err)
	else:
		print("Min=",vmin)

#---------------------------------------------------------------------------------------------------------------------------
def main1():
	rez,err=0,0
	err,rez=Summchet('KEK.txt')
	if err:
		print("Error",err)
	if rez==None:
		print('File is empty')
	else:
		print("sum=",rez)

#---------------------------------------------------------------------------------------------------------------------------
def q(n):
	for i in range(n+1):
		yield i
#---------------------------------------------------------------------------------------------------------------------------
def q1(n):
	for i in range(n+1):
		yield i*i
#---------------------------------------------------------------------------------------------------------------------------
def fun1(n):
	s=0
	numbers=q1(n)
	for i in numbers:
		s+=i
	return s
#--------------------------------------------------------------------------------------------------------------------------
def fun2(n):
	A=q(n)
	for i in A:
		print(i)
#---------------------------------------------------------------------------------------------------------------------------
