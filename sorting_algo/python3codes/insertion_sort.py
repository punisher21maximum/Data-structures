def insertionSort(arr, n):
    for i in range(1, n):
        j = i-1 ; item = arr[i]
        while(j>=0 and arr[j]>item):
            arr[j+1] = arr[j]
            j-=1
        arr[j+1] = item
              

arr = [3, 12, 2, 56, 23, 1, -5]
n = len(arr)
print(arr)
insertionSort(arr, n)
print(insertionSort.__qualname__)
print(arr)