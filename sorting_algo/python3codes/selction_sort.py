def selectionSort(arr, n):
    for i in range(n-1):
        maxx = arr[0] ; maxx_index = 0
        for j in range(1, n-i):
            if arr[j]>maxx:
                maxx = arr[j]
                maxx_index = j 
        arr[maxx_index] = arr[n-i-1]
        arr[n-i-1] = maxx



arr = [3, 12, 2, 56, 23, 1, -5]
n = len(arr)
print(arr)
selectionSort(arr, n)
print(arr)