'''
In second year computer engineering class, group A student‟s 
play cricket, group B students play badminton and group C 
students play football. Write a Python program using functions 
to compute following: 
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not 
both 
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not 
badminton
'''
def remove_duplicate(d):
    lst=[]
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst
def intersection(list1,list2):
    list3=[]
    for val in list1:
        if val in list2:
            list3.append(val)
    return list3
def union(list1,list2):
    list3=list1.copy()
    for val in list2:
        if val not in list3:
            list3.append(val)
    return list3
def diff(list1,list2):
    list3=[]
    for val in list1:
        if val not in list2:
            list3.append(val)
    return list3
def sym_diff(list1,list2):
    list3=[]
    D1=diff(list1,list2)
    D2=diff(list2,list1)
    list3=union(D1,D2)
    return list3

SEComp=[]
n=int(input("Enter the no of students in SE Comp: "))
for i in range(n):
    ele=input("Enter the name of "+str(i+1)+" student: ")
    SEComp.append(ele)
print()
print("the original list"+str(SEComp))
SEComp=remove_duplicate(SEComp)
print("the list after removing duplicates"+str(SEComp))
print()

Cricket=[]
n=int(input("Enter the no of students in Cricket: "))
for i in range(n):
    ele=input("Enter the name of "+str(i+1)+" student: ")
    Cricket.append(ele)
print()
print("the original list"+str(Cricket))
Cricket=remove_duplicate(Cricket)
print("the list after removing duplicates"+str(Cricket))
print()

Badminton=[]
n=int(input("Enter the no of students in Badminton: "))
for i in range(n):
    ele=input("Enter the name of "+str(i+1)+" student: ")
    Badminton.append(ele)
print()
print("the original list"+str(Badminton))
Badminton=remove_duplicate(Badminton)
print("the list after removing duplicates"+str(Badminton))
print()

Football=[]
n=int(input("Enter the no of students in Football: "))
for i in range(n):
    ele=input("Enter the name of "+str(i+1)+" student: ")
    Football.append(ele)
print()
print("the original list"+str(Football))
Football=remove_duplicate(Football)
print("the list after removing duplicates"+str(Football))
print()

while(True):
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both ")
    print("3. Number of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit")
    choice=int(input("Enter your choice"))
    print()
    if(choice==1):
        print("List of students who play both cricket and badminton are:")
        list=intersection(Cricket,Badminton)
        print(list)
        print("Number of students who playboth cricket and badminton are: "+str(len(list)))
        print()

    if(choice==2):
        print("List of students who play either cricket or badminton but not both are: ")
        list=sym_diff(Cricket,Badminton)
        print(list)
        print("Number of students who play either cricket or badminton but not both are: "+str(len(list)))
        print()

    if(choice==3):
        print("List of students who play neither cricket nor badminton are :")
        list=diff(SEComp,union(Cricket,Badminton))
        print(list)
        print(" Number of students who play neither cricket nor badminton are: "+str(len(list)))
        print()

    if(choice==4):
        print("List of students who play cricket and football but not badminton")
        list=diff(intersection(Cricket,Football),Badminton)
        print(list)
        print("Number of students who play cricket and football but not badminton are: "+str(len(list)))
        print()

    if(choice==5):
        print("Exiting Program")
        break