import sys
import gcd
def test_gcd(a,b):
        print type(a)
        try:
            if int(a)<0 or int(b)<0:
                raise ValueError
        except ValueError:
            print "Negative number entered"
            return
        try:
            if type(a) != 'int' or type(b) != 'int' or type(a) != 'long' or type(b) != 'long':
                raise TypeError
        except TypeError:
            print "invalid type entered"
            return
        c = gcd.gcd(a,b)
        print c



#if __name__ == '__main__':
#    test_gcd()

