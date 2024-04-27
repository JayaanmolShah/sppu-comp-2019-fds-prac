def average(marks,n):
    sum=0
    for i in marks:
        sum =sum+i
    return sum/n
def highest(marks):
    max=marks[0]
    for i in range(1,len(marks)):
        if max<marks[i]:
            max=marks[i]
    return max
def lowest(marks):
    min=marks[0]
    for i in range(1,len(marks)):
        if min>marks[i]:
            min=marks[i]
    return min
def absent(marks):
    count=0
    for i in marks:
        if i==-1:
            count+=1
    return count
def frequency(marks):
    pass
marks=[]
students=int(input("enter number of students: "))
print('Enter marks of students and if a student was absent for the test enter "-1"')
for i in range(students):
    mark=int(input("enter the marks of student"+str(i+1)+": "))
    marks.append(mark)
ch='y'
while (ch=='y' or ch=='Y'):
    print("1. The average score of class")
    print("2. Highest score and lowest score of a class")
    print("3. count of students who were absent for test")
    print("4. Display mark with highest frequency")
    choice=int(input("Enter your choice: "))
    if choice==1:
        print("The average score of the class: "+str(average(marks,students))+"\n")
    if choice==2:
        print("\nHighest score of the class: "+str(highest(marks)))
        print("Lowest score of the class: "+str(lowest(marks))+"\n")
    if choice==3:
        print("\nCount of students who were absent: "+str(absent(marks))+"\n")
    if choice==4:
        print("Highest frequency of the class: "+str(frequency(marks))+"\n")
    ch=input("enter y if you want to continue: ")

