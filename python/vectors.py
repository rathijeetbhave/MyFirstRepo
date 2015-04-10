class Vector():
    def __init__(self,a,b,c):
        self.a=a
        self.b=b
        self.c=c
        self.__rmul__=self.__mul__

    def __repr__(self):
        return "Vector("+ str(self.a) +","+ str(self.b)+ "," + str(self.c) + ")"
        

    def __add__(self,vec2):
        return Vector(self.a+vec2.a,self.b+vec2.b,self.c+vec2.c)

    def __sub__(self,vec2):
        return Vector(self.a-vec2.a,self.b-vec2.b,self.c-vec2.c)

    def __mul__(self,d):
        return Vector(self.a*d,self.b*d,self.c*d)

    def __rmul__(self,d):
        self.__mul__(self,d)


