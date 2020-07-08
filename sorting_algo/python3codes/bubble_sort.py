def bubbleSort(arr, n):   
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

arr = [3, 12, 2, 56, 23, 1, -5]
n = len(arr)
print(arr)
bubbleSort(arr, n)
print(arr)