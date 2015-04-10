class queue:
    def __init__(self):
        self.name=[]
    def enqueue(self,elem):
        self.name.append(elem)
    def dequeue(self):
        b=self.name.pop(0)
        return b 
    def printqueue(self):
        print self.name
    def IsEmpty(self):
        if len(self.name)==0:
            return 0
        else :
            return 1
