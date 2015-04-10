import networkx as nx
from classstack import *
import matplotlib.pyplot as plt
import numpy
import itertools

def c_list_gen(v,e_dash,matched,k):
    c_list=[]
    for e in e_dash:
        if v in e:
            if k%2==0: 
                if e not in matched and e[1] not in c_list:
                    c_list.append(e[1])
            else:
                for g in range(len(matched)):
                    if v in matched[g] and matched[g][0] not in c_list:
                        c_list.append(matched[g][0])
    return c_list
   
def hopcroft_karp():
          #  l1=[]
    g=nx.read_adjlist("adjlist.txt")
  #  print g.edges()
  #  print g.neighbors('u1')
  #  print nx.is_bipartite(g)
    g1,g2=nx.bipartite.sets(g)
    print g1
  #  print g2
#    matched=[('u3','v2'),('u4','v3'),('u1','v6')]
    matched=[('u3','v2')]
    for z in range(2):
        if len(matched)==len(g1):
            break
        l=[[],[]]
        edg=[[],[]]
        e0=[]
    ######................Find l0...........######

        for v in g1:
            flag=0
            for i in range(len(matched)):
                if v in matched[i]:
                    flag=1
                    break
            if flag==0:
                l[0].append(v)
        print l[0]
        
         ######..............Find free nodes in v2.........######
        free_nodes_in_v2=[]
        for v in g2:
            flag=0
            for i in range(len(matched)):
                if v in matched[i]:
                    flag=1
                    break
            if flag==0:
                free_nodes_in_v2.append(v)
        print free_nodes_in_v2
        ######................Find i_star.............######
        i=1
        k=1
        intersection=[]
        while intersection == []:
#        for q in range(2):
       # for j in range(3):
            if k%2==0:
                for v in l[i-1]:
                    print v 
                    for e in matched:
                        if v in e and e[0] not in l[i]:
                            l[i].append(e[0])
                            print l[i]
                        if v in e:
                            # print e[i-1]
                            edg[i-1].append(e)
                k+=1
            else:
                for v in l[i-1]:
                    print v
                    for e in list(set(g.edges())-set(matched)):
                        if v in e and e[1] not in l[i]:
                            l[i].append(e[1])
                            print l[i]
                        if v in e:
                            # print e[i-1]
                            edg[i-1].append(e)
                k+=1

            intersection=[val for val in free_nodes_in_v2 if val in l[i]]
            print intersection
            l.append([])
            edg.append([])
            i=i+1
            print l[i-1],edg[i-2]

        print l,i-1,edg[i-2]

    ######...............Construct new graph..............######
        val = [val for val in l[i-1] if val in free_nodes_in_v2]
        print val
        v_dash=[]
        e_dash=[]
        for j in range(i-1):
            v_dash=set().union(l[j],v_dash)  
        v_dash=set().union(v_dash,val) 
        print v_dash
        if i==2:
            for v in l[i-2]:
                for u in free_nodes_in_v2:
                    if (v,u) in g.edges():
                        e_dash.append((v,u))
            print "old=new "+ str(e_dash)
        else:
            for j in range((i-2)%i):
                e_dash=list(set().union(edg[j],e_dash))
            print "old e_dash " + str(e_dash)
            for v in l[i-2]:
                for u in free_nodes_in_v2:
                    if (v,u) in g.edges():
                        e_dash=set().union(e_dash,[(v,u)])
            print "new e_dash "+ str(e_dash)

    ######............End of step 1..............######

        s=stack()
        marked=[]
        n=0
        c_list=[1,2]
        s.push(l[0][n])
        print l[0]
        v=l[0][n]
        print v 
        marked.append(l[0][n])
        while s.IsEmpty():
            if len(matched)==len(g1):
                break
            v=s.peek()
            print v
            k=0
            c_list=c_list_gen(v,e_dash,matched,k)
            print c_list
            if c_list==[]:
                s.Empty()
                n+=1
                print n,len(l[0])
                if n==len(l[0]):
                    break
                v=l[0][n]
                s.push(v)
                marked.append(v)
            else:
                while c_list != [] :
                 #   c_list=c_list_gen(v,e_dash)
                    u=c_list[0]
                 #   print u
                    if u in marked:
                        c_list.remove(u)
                    else:
                        s.push(u)
                        marked.append(u)
                        v=u
                        print "v=u "+ v
                        k+=1
                        c_list=c_list_gen(v,e_dash,matched,k)
                        print c_list
                print v,l,i,l[0]
                if v not in l[i-1] and v not in l[0]:
                    s.pop()
                else:
                    if v in l[i-1]:
                        s.Printstack()
                      #  print s.name[1]
                        f=1
                        aug_paths=[]
                        for x in range(len(s.name)-1):
                            if f%2==0:
                                aug_paths.append((s.name[x+1],s.name[x]))
                                f+=1
                            else:
                                aug_paths.append((s.name[x],s.name[x+1]))
                                f+=1
                        print aug_paths
                        matched=list(set().union(matched,aug_paths)-(set(matched) & set(aug_paths))) 
                        print matched,len(g1)
                        if len(matched)==len(g1):
                            return 
                        s.Empty()
                        s.Printstack()
                        n+=1
                        v=l[0][n]
                        s.push(v)
                        marked.append(v)
                  
          #  while s.IsEmpty:
       #     v=s.pop()
       # print ('u5','v4')" in g.edges() 
       # nx.draw(g)
       # plt.show()
    print matched

def main():
    hopcroft_karp()
    
if __name__ == '__main__':
    main()


