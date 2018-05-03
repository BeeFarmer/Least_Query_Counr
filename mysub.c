#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

void print_list(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void init(int arr[], int arr2[], int n, int end)
{
    int i=0;
    for ( ; i<n; ++i)
        arr[i] = arr2[i];
    arr[i] = end;
}

void parse(int res[], int n)
{
    int siz = 0; int temp[4];
    for (int i=0; i<n/4; i++)
    {
        for (int j=0; j<4; j++)
            temp[j] = i*4+j+1;
        res[siz++] = QCOUNT(1, temp);
    }
}

int mysub(int n)
{
    int A[n/2+1], Asize=0;
    int B[n/2+1], Bsize=0;
    int myarray[4] = {1,2,3,4};
    bool flag = false;


    int result[n/4+1];
    parse(result, n);
    print_list(result, n/4);
    int base = QCOUNT(1, myarray);
    A[Asize++] = myarray[3];
    for (int i=5; i<=n; ++i)
    {
        if (Asize>n/2 || Bsize>n/2){
            flag = true;;
            break;}
        myarray[3] = i;
        int temp = QCOUNT(1, myarray);
        if (temp==base)
            A[Asize++] = myarray[3];
        else
            B[Bsize++] = myarray[3];
    }

    if (flag==false)
    {
        if (Asize>=3)
        {
            for (int i=1; i<4; ++i)
            {
                int tarray[4]; init(tarray, A, 3, i);
                int te = QCOUNT(1, tarray);
                if (te==4)
                    A[Asize++] = tarray[3];
                else
                    B[Bsize++] = tarray[3];
            }
        } else {
            for (int i=1; i<4; ++i)
            {
                int tarray[4]; init(tarray, B, 3, i);
                int te = QCOUNT(1, tarray);
                if (te==4)
                    B[Bsize++] = tarray[3];
                else
                    A[Asize++] = tarray[3];
            }
        }
    }


    /*if (Asize>Bsize)
        return A[0];
    else if (Asize<Bsize)
        return B[0];*/
    return (0);
}
