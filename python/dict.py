def mydict():
    dict={}
    for i in range(1,101,1):
        if i%3==0 and i%5==0:
            dict[i]='FizzBuzz'
        elif i%3==0:
            dict[i]='Fizz'
        elif i%5==0:
            dict[i]='Buzz'

    print dict


def collatz(n):
    result=[]
    result.append(n)
    while n!=1:
       n= c_helper(n)
       result.append(n)
    print result
    

def c_helper(n):
    if n%2==0:
       return n/2
    else:
        return (3*n+1)


def FixStart(s):
    ch=s[0]
    s=s.replace(s[0],'*')
    result=ch+s[1:]
    print result


def rangeofnum(s):
    res=[]
    for num in s:
        if num==',':
            continue
        else:
            if '-' in num:
                l=num[0:num.index('-')]
                print l
                r=num[num.index('-')+1:]
                print r
                for i in range(int(l),int(r)+1):
                    res.append(i)
            else:
                res.append(int(num))
    print res


def parse(s):
    s=s.replace(',',' ')
    dd=s[:s.index(' ')]
    s=s[s.index(' ')+1:]
    mm=s[:s.index(' ')]
    s=s[s.index(' ')+1:]
    yy=s
    print dd,mm,yy
    ref={'jan':01,'feb':02,'mar':03,'apr':04,'may':05,'jun':06,'jul':07,'aug':8,'sep':9,'oct':10,'nov':11,'dec':12}
    month=ref[mm[:3].lower()]
    if month<10:
        result=(int(yy),int(0+month),int(dd))
    else:
        result=(int(yy),month,int(dd))
    
    print result


def CountChars(s):
    dict={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,'m':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,'y':0,'z':0,'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0}

    str=['',',''','.','?','!',':',';','-','/',',',' ']
    for ch in s:
        if ch.lower() in str:
            continue
        else:
            dict[ch.lower()]=dict[ch.lower()]+1
    for i in dict.keys():
        if dict[i]==0:
            del dict[i]
    print dict


def CountVowels(s):
    str='aeiou'
    count=0
    for ch in s:
        if ch.lower() in str:
            count+=1
    print count


def factorialnum(n):
    res=1
    if n==0:
        print 1
    else:
        for i in range(1,n+1):
            res=res*i
        print res

def LetterMissed(s):
    s4=[]
    for i in range(len(s)):
        s1=s[0:i]
        s2=s[i+1:]
        s3=[s1,s2]
        s4.append(('').join(s3))
    s4.sort()
    print s4

