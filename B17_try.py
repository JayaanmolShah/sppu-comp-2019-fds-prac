def insertion(arr):
    for i in range(1,len(arr)):
        up=arr[i]
        j=i-1
        while j>=0 and arr[j]>up:
            arr[j+1]=arr[j]
            j=j-1
        arr[j+1]=up
    return arr
def bucket_sort(per):
    bucket=[]
    max=int(10 * per[0])
    for i in range(1,len(per)):
        if max< int(10 * per[i]):
            max=int(10 * per[i]) +1
    print(max)
    for i in range(max):
        bucket.append([])
    for i in per:
        index=int(10 * i)
        bucket[index].append(i)
    for i in range(len(bucket)):
        bucket[i]=insertion(bucket[i])
    k=0
    for i in range(len(bucket)):
        for j in range(len(bucket[i])):
            per[k]=bucket[i][j]
            k=k+1
    return per
def top_five(arr):
    top=5
    if(len(arr)<top):
        top=len(arr)
    for i in range(top):
        print(f"{i+1}. {arr[-(i+1)]}%")
percentage=[.42, .32, .33, .52, .37, .47, .51]
# n=int(input("enter no of students: "))
# for i in range(n):
#     ele=float(input(f"Enter precentage of student {i+1}: "))
#     percentage.append(ele)
print("original percentage: ")
print(percentage)
print("sorted percentage: ")
sort=bucket_sort(percentage)
print(sort)
top_five(sort)