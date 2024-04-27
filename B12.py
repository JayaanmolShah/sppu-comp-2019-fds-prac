'''
a) Write a Python program to store names and mobile numbers 
of your friends in sorted order on names. Search your friend 
from list using binary search (recursive and nonrecursive). 
Insert friend if not present in phonebook 
b) Write a Python program to store names and mobile numbers 
of your friends in sorted order on names. Search your friend 
from list using Fibonacci search. Insert friend if not present in 
phonebook.
'''
def binary_search_recursive(phonebook, name, left, right):
    if left > right:
        return None

    mid = (left + right) // 2

    if phonebook[mid][0] == name:
        return phonebook[mid]
    elif phonebook[mid][0] > name:
        return binary_search_recursive(phonebook, name, left, mid - 1)
    else:
        return binary_search_recursive(phonebook, name, mid + 1, right)

def binary_search_non_recursive(phonebook, name):
    left, right = 0, len(phonebook) - 1

    while left <= right:
        mid = (left + right) // 2

        if phonebook[mid][0] == name:
            return phonebook[mid]
        elif phonebook[mid][0] > name:
            right = mid - 1
        else:
            left = mid + 1

    return None

def insert_friend(phonebook, name, number):
    left, right = 0, len(phonebook) - 1

    while left <= right:
        mid = (left + right) // 2

        if phonebook[mid][0] == name:
            return  # Friend already in the phonebook
        elif phonebook[mid][0] > name:
            right = mid - 1
        else:
            left = mid + 1

    phonebook.insert(left, (name, number))

def main():
    phonebook = [("Alice", "1234567890"), ("Bob", "9876543210"), ("Charlie", "5678901234")]

    while True:
        print("\nOptions:")
        print("1. Search for a friend (Binary Search - Recursive)")
        print("2. Search for a friend (Binary Search - Non-Recursive)")
        print("3. Insert a friend")
        print("4. Quit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            name = input("Enter the name to search for: ")
            result = binary_search_recursive(phonebook, name, 0, len(phonebook) - 1)
            if result:
                print(f"{result[0]}'s number is {result[1]}.")
            else:
                print(f"{name} not found in the phonebook.")
        elif choice == 2:
            name = input("Enter the name to search for: ")
            result = binary_search_non_recursive(phonebook, name)
            if result:
                print(f"{result[0]}'s number is {result[1]}.")
            else:
                print(f"{name} not found in the phonebook.")
        elif choice == 3:
            name = input("Enter the friend's name to insert: ")
            number = input("Enter the friend's number: ")
            insert_friend(phonebook, name, number)
            print(f"{name} added to the phonebook.")
        elif choice == 4:
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
