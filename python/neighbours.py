import networkx as nx
def neighbours():
    g=nx.read_adjlist("adjlist.txt")
    print g.neighbours('u1')

def main():
    neighbours()
    
if __name__ == '__main__':
    main()


