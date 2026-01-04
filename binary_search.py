# Day 3: Binary Search Algorithm in Python (Iterative Approach)

def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid  # Target found
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1  # Target not found

# Sample sorted array
arr = [3, 8, 15, 23, 42, 56, 78]

# Target element
target = 42

# Perform binary search
result = binary_search(arr, target)

# Output result
if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the array.")
