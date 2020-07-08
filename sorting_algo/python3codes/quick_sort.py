def partition(arr, l, r):
    pivot = arr[r]

    index = l 
    for i in range(l, r-1):
        if arr[i]<pivot:
            arr[i], arr[index] = arr[index], arr[i]
            index+=1 
    arr[r] = arr[index] 
    arr[index] = pivot 

    return index

def quickSort(arr, l, r):
    if l>=r: return 

    partition_index = partition(arr, l, r)
    quickSort(arr, l, partition_index-1)
    quickSort(arr, partition_index+1, r)

arr = [3, 7, 1, 33, -12, 4, 12, 99, -6]
print(arr)
quickSort(arr, 0, len(arr)-1)
print('quickSort')
print(arr)