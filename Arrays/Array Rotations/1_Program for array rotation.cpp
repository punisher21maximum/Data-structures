#include<iostream>
using namespace std;

void disp(int arr[], int n)
{
    cout<<"\n--->";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
}

void method1Left(int arr[], int n, int d)//n - length
{
    /*
    1.save arr[0] in temp
    2.shift all ele to left
    3.set arr[n-1] = temp
    */
    for(int i=0; i<d; i++)
    {
        int left = arr[0];
        for(int j=0; j<n-1; j++)
        {
            arr[j] = arr[j+1];
        }
        arr[n-1] = left;
    }
}

void method1Right(int arr[], int n, int d)//n - length
{
    for(int i=0; i<d; i++)
    {
        int right = arr[n-1];
        for(int j=n-1; j>0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = right;
    }
}

void method2Left(int arr[], int n, int d)//n - length
{
    /*
    1.save first d ele in tempArr
    2.shift remaining ele by d to left
    3.copy tempArr ele at end of arr
    */
    
    int tempA[d];

    for(int i=0; i<d; i++)
        tempA[i] = arr[i];
    
    for(int i=0; i<n-d; i++)
        arr[i] = arr[d+i];

    for(int i=0; i<d; i++)
        arr[n-d+i] = tempA[i]; 

}

int gcdFunc(int a, int b)
{
    if(b==0) return a;
    return gcdFunc(b, a%b);
}

void method3Left(int arr[], int n, int d)//n - length
{
    /*
    1.find gcd(d, n)
    2.for i=0 to i<gcd
        index = i
        save arr[i] in ele
        while (index+d) %n is not i again
            arr[index] = arr[(index+d)%n]
            index = (index+d)%n
        set arr[index] = ele
    */
    
    d = d % n;
    int gcd = gcdFunc(d, n);

    for(int i=0; i<gcd; i++)
    {
        int index = i;
        int ele = arr[i];
        while((index + d ) % n != i)
        {
            arr[index] = arr[(index + d ) % n];
            index = (index + d ) % n;
        }
        arr[index] = ele;
    }
}

void reverseArray(int arr[], int l, int r)
{
    int lenn = r - l + 1;
    for(int i=0; i<lenn/2; i++)
    {
        int temp = arr[l+i];
        arr[l+i] = arr[r-i];
        arr[r-i] = temp;
    }
}

void method4Left(int arr[], int n, int d)
{
    /*
    reverse : 0 to d-1 (indexes)
    reverse : d to n-1
    revserse : o to n-1
    */
    
    d = d % n;
    if(d==0) return;
    reverseArray(arr, 0, d-1);disp(arr, n);//pass indexes
    reverseArray(arr, d, n-1);disp(arr, n);
    reverseArray(arr, 0, n-1);
}

void method5Left(int arr[], int n, int d)//n - length
{
    /*
    1.use rotatedArray 
    2.in rotatedArray store : d to last
    3.in rotatedArray store : 0 to d-1
    */
    int rotatedArray[n];
    for(int i=0; i<n; i++)
    {
        rotatedArray[i] = arr[(d+i)%n];
    }
    for(int i=0; i<n; i++)
    {
        arr[i] = rotatedArray[i];
    }
}

void swap(int arr[], int left_index, int right_index, int swaps)
{
    for(int i=0; i<swaps; i++)
    {
        int temp = arr[left_index+i];
        arr[left_index+i] = arr[right_index+i];
        arr[right_index] = temp;
    }
}

void method6left(int arr[], int d, int n)
{
    /*
    block swap algo
    */
    if ( d==0 or d==n ) return;

    if(n-d==d)
    {
        swap(arr, 0, d, d);
        return;
    }
    else if(d < n-d)
    {
        //A < B
        //ABlBr   ---- BrBlA
        swap(arr, 0, n-d, d);
        method6left(arr, d, n-d);
    }
    else// d > n-d
    {
        //A > B
        //AlArB --- BArAl
        swap(arr, 0, d, n-d);
        method6left(arr+n-d, 2*d-n, d);
    }

}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    disp(arr, n);
    int d=4;
    method5Left(arr, n, d);
    disp(arr, n);
    // method1Right(arr, n, d);
    // disp(arr, n);

    return 0;
}

// fast_index = (index + d ) % n;
// if(fast_index==i) break;
// arr[index] = arr[fast_index];
// index = fast_index;