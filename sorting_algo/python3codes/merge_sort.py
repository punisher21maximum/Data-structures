def merge(arr, l, m, r):
    n1 = m-l+1; n2 = r-l

    left = arr[l:l+n1]
    right = arr[m+1:m+1+n2]

    i=0; j=0; k=l

    while i<n1 and j<n2:
        if left[i]>=right[j]:
            arr[k] = left[i]
            i+=1
        else:
            arr[k] = right[j] 
            j+=1
        k+=1 

    while i<n1:
        arr[k] = left[i] 
        k+=1; i+=1 
         
    while j<n2:
        arr[k] = right[j] 
        k+=1; j+=1

def mergeSort(arr, l, r):
    if l<=r : return

    m = l + (r-l)/2
    # split
    mergeSort(arr, l, m)
    mergeSort(arr, m+1, r)
    # merge
    merge(arr, l, m, r)


arr = [3, 7, 1, 33, -12, 4, 12, 99, -6]
print(arr)
mergeSort(arr, 0, len(arr))
print('mergeSort')
print(arr)