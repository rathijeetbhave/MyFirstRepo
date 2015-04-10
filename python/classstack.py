class stack:
    def __init__(self):
        self.name=[]
        self.top=-1
    def push(self,elem):
        self.name.append(elem)
        self.top+=1
    def pop(self):
        b=self.name.pop()
        self.top=self.top-1
        return b
    def Printstack(self):
        print self.name
    def IsEmpty(self):
        if len(self.name)==0:
            return 0
        else:
            return 1
    def Empty(self):
        for v in range(len(self.name)):
           self.name.pop()
        self.top=-1
    def peek(self):
        b=self.name.pop()
        self.name.append(b)
        return b
      #  if self.top<0:
       #     return []
      #  else:
       #     print self.top
        #    return self.name[self.top]
