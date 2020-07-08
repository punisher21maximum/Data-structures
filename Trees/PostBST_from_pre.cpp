#include <iostream> 
using namespace std; 

void printPostforBSTfromPre(int pre[], int n)//n is number of elements
{
    //split into left and right
    int leftA[10], rightA[10], lc=0, rc=0;
    for(int i=1; i<n; i++)
    {
        if(pre[i]<pre[0]) 
            leftA[lc++] = pre[i];
        else
            rightA[rc++] = pre[i];
    }

    //print left
    if(lc>0) printPostforBSTfromPre(leftA, lc);
    //print right
    if(rc>0) printPostforBSTfromPre(rightA, rc);
    //print root
    cout<<pre[0]<<" ";
}

// Driver program to test above functions 
int main() 
{ 
	int pre[] = { 40, 30, 35, 80, 100 }; 
    printPostforBSTfromPre(pre, 5);

	return 0; 
} 
