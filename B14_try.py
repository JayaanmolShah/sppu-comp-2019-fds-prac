'''Write a Python program to store first year percentage of students in
array. Write function for sorting array of floating point numbers in
ascending order using
a) Selection Sort b) Bubble sort and display top five scores.'''
def selection_sort(marks):
    for i in range(len(marks)):
        min = i
        for j in range(i+1, len(marks)):
            if marks[min]>marks[j]:
                min=j
        marks[i], marks[min] = marks[min], marks[i]
    display(marks)
    top_five(marks)
    
def bubble_sort(marks):
    n=len(marks)
    for i in range(n-1):
        for j in range(0,n-i-1):
            if marks[j]>marks[j+1]:
                marks[j],marks[j+1]=marks[j+1],marks[j]
    display(marks)
    top_five(marks)

def display(marks):
    for i in marks:
        print(i)

def top_five(marks):
    print("Top five scores are: ")
    m=marks[::-1]
    for i in range(5):
        print(m[i])

marks=[]
n=int(input("enter the number of students: "))
for i in range(n):
    ele=int(input("Enter the marks of student "+str(i+1)+" : "))
    marks.append(ele)
ch='y'
while(ch=='y' or ch=='Y'):
    print("1) Selection Sort")
    print("2) Bubble sort")
    choice=int(input("Enter your chocie: "))
    print()
    if choice==1:
        print("Selection Sort: ")
        selection_sort(marks)
    if choice==2:
        print("Bubblee sort: ")
        bubble_sort(marks)
    ch=input("enter y if you wish to continue: ")