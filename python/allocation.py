import sys
import numpy
import operator
import itertools
import csv

class student:
    def __init__(self,marks,name,pref):
        self.marks=marks
        self.name=name
        self.pref=pref
        self.IsAssigned=False

class committee:
    def __init__(self,number,max_count,proj_list,aoi_list):
        self.curr_count=0
        self.number=number
        self.max_count=max_count
        self.aoi_list=aoi_list
        self.proj_list=proj_list

def main():
    comm_list=[]
    stud_list=[]
    #with open('aoi_to_comm.csv') as csvFile:
        #readcsv=csv.reader(csvFile,delimiter=',')
        #for row in readcsv:
            #comm_list.append(committee(row[0][1:],10))
        #for comm in comm_list:
            #print comm.number,comm.max_count
    comm_list.append(committee(1,8,[3,5],[1]))
    comm_list.append(committee(2,8,[2],[2,3,4]))
    comm_list.append(committee(3,8,[],[5,6]))
    comm_list.append(committee(4,8,[4,9],[7,8,9]))
    comm_list.append(committee(5,8,[6,7,8,18],[10,11]))
    comm_list.append(committee(6,8,[12,13],[12]))
    comm_list.append(committee(7,8,[1,15],[13,14,15,16]))
    comm_list.append(committee(8,8,[10,11],[17,18]))
    comm_list.append(committee(9,8,[],[19,20,21]))
    comm_list.append(committee(10,8,[14,19],[22,23,24]))
    comm_list.append(committee(11,8,[],[25,26]))
    comm_list.append(committee(12,8,[],[25,26,27]))
    comm_list.append(committee(13,8,[20,21],[28,29]))
    comm_list.append(committee(14,8,[],[30,31,32]))
    comm_list.append(committee(15,8,[],[30,33]))

    with open('comm_mapping.csv') as csvFile:
        readcsv=csv.reader(csvFile,delimiter=',')
        for row in readcsv:
            stud_list.append(student(int(row[1]),row[0],row[2:]))
    #for i in stud_list:
        #print i.name,i.marks,i.pref

    assigned={}
    unassigned=[]
    #stud_list.sort(key=operator.attrgetter('marks'),reverse=True)
    stud_list.sort(key=lambda student:student.marks)
    #for name in stud_list:
        #print name.marks,name.name,name.pref

    for stud in stud_list:
        for i in xrange(4):
           comm=find_comm(stud.pref[i],comm_list,i)
           if comm==None:
               continue
           #print comm.number
           if comm.curr_count<comm.max_count:
               assigned[stud.name]=comm.number
               stud.IsAssigned=True
               comm.curr_count+=1
               break
        else:
            unassigned.append(stud.name)
    for key,value in assigned.iteritems():
        print key,value
    print '\n'
    print '\n'
    for name in unassigned:
        print name
    for comm in comm_list:
        print comm.curr_count,comm.max_count

def find_comm(pref,comm_list,i):
    for comm in comm_list:
        if i<2:
            if int(pref) in comm.proj_list:
                return comm
        else:
            if int(pref) in comm.aoi_list:
                return comm
        
if __name__=='__main__':
    main()


