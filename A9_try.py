'''
This program is created by ATHARVA PAWAR

Experiment No. 9 : Write a Python Program to compute following computation on matrices :
                   a)Addition of two matrices
                   b)Subtraction of two matrices
                   c)Multiplication of two matrices
                   d)Transpose of a matix
'''
def get_data(rows,columns,A):
    for i in range(rows):
        A[i]=[]
        for j in range(columns):
            a=int(input(f"enter A[{i}][{j}]th element: "))
            A[i].append(a)

def display(A):
    print("Matrix: ")
    for i in A:
        print(i)
    print()

def add(A,B,result,rows,columns):
    for i in range(rows):
        for j in range(columns):
            result[i][j]=A[i][j]+B[i][j]
    return result

def sub(A,B,result,rows,columns):
    for i in range(rows):
        for j in range(columns):
            result[i][j]=A[i][j]-B[i][j]
    return result

def mul(A,B,result,rows,columns):
    for i in range(rows):
        for j in range(columns):
            for k in range(columns):
                result[i][j] += A[i][k] * B[k][j]
    return result

def transpose(A,result,rows,columns):
    for i in range(rows):
        for j in range(columns):
            result[j][i]=A[i][j]
    return result   

rows=int(input("Enter the number of rows: "))
columns=int(input("Enter the number of columns: "))

A=[[] for _ in range(rows)]
B=[[] for _ in range(rows)]
result=[[] for _ in range(rows)]
for i in range(rows):
    result[i]=[]
    for j in range(columns):
        result[i].append(0)
print("Enter the values of Matrix A: ")
get_data(rows,columns,A)
print("Enter the values of Matrix B: ")
get_data(rows,columns,B)

display(A)
display(B)

ch='y'
while(ch=='y' or ch=='Y'):
    print("1) Addition of two matrices")
    print("2) Subtraction of two matrices")
    print("3) Multiplication of two matrices")
    print("4) Transpose of a matix")
    choice=int(input("Enter your chocie: "))
    print()
    if choice==1:
        print("Addition: ")
        display(add(A,B,result,rows,columns))
    if choice==2:
        print("Subtraction: ")
        display(sub(A,B,result,rows,columns))
    if choice==3:
        if rows==columns:
            print("Multiplication: ")
            display(mul(A,B,result,rows,columns))
    if choice==4:
        if rows==columns:
            print("Transpose of MAtrix A: ")
            display(transpose(A,result,rows,columns))
            print("Transpose of MAtrix B: ")
            display(transpose(B,result,rows,columns))
    ch=input("enter y if you wish to continue: ")