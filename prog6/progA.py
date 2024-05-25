def f(sf):
	try:
		Minlen=-1
		f=open(sf,'r')
		for s in [s for s1 in f for s2 in s1.split('\t') for s3 in s2.split(' ') for s4 in s3.split(',') for s5 in s4.split('.') for s in s5.split('\n') if s!='']:
			if s[1:].isalpha() and s[0].isdigit():
				if Minlen<0:
					word=s ; Minlen=len(s)
				elif len(s) < Minlen:
					word=s ; Minlen =len(s)
		f.close();
		if Minlen <0:
			return "No correct words",0,""
		else:
			return "",Minlen,word
	except FileNotFoundError:
		return "Can't open file",0,""
#---------------------------------------------------------------------------------------------------------------------------
def mainA1():
	err,dlin,word=f("KEK.txt")
	if err!='':
		print(err)
	else:
		print("dlina= ",dlin,", word= ",word,sep='')
#--------------------------------------------------------------------------------------------------------------------------
def zadacha(n):
	n1=(n*29)%46+1
	n2=(n*29+10)%46+1
	n3=(n*29+20)%46+1
	print(n1,n2,n3)
#--------------------------------------------------------------------------------------------------------------------------
def mainA2():
	x=[1,2,3]
	b=[1,2,3]
	b[1]=b[0]
	for i in x:
		print(i,end='  ')
#		print(n[i],end=' ')
	print()
	for i in b:
		print(i,end=' ')
	print()
	for i in range(len(x)):
		print("x[",i,"]=",x[i],sep='')
#--------------------------------------------------------------------------------------------------------------------------
def proga(FileName):
	try:
		f=open(FileName,'r')
		x=[1,2,3,4,5]
		k=0
		for s in [int(sx) for s1 in f for s2 in s1.split('\t') for s3 in s2.split(' ') for sx in s3.split('\n') if sx!='']:
			for i in range(len(x)):
				if s==x[i]:
					k=k+1 ; x.pop(i)
		return "",k
	except FileNotFoundError:
		return "Can't open file",k
#--------------------------------------------------------------------------------------------------------------------------
def main():
	err=''
	coll=None
	err,coll=proga("KEK.txt")
	if err!='':
		print(err)
	else:
		print("Quantity of items found=",k)

