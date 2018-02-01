/**
 *  \file parallel-mergesort.cc
 *
 *  \brief Implement your parallel mergesort in this file.
 */
//Jan.30.2018

// lai man tang, yuan qin
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"
<<<<<<< HEAD

void parallelSort (int N, keytype* A)
{

	mergesort(A, 0, N);
=======
keytype* B;
int s = & B;
void
parallelSort (int N, keytype* A)
{
	Pmergesort(A, 0, N, B, s);
>>>>>>> bdc58f287dff44eff9b60384435ff3e7832c9afa
	//sequentialSort(N, A);

}
void Pmergesort(keytype* A, int p, int r, keytype* B, s)
{
<<<<<<< HEAD
	if (p < r)
	{
		int q = (p + r) / 2;
		mergesort(A, p, q);
		mergesort(A, q + 1, r);	
		keytype* T = new keytype();
		Pmerge(A, p, q, q+1, r, T ,0);//!!!!!!!
=======
        int n = r-p+1;
        if (n == 1){
                B[s] = A[p]
        }else{
                keytype* T;
                int q = (p + r) / 2;
                int qt= q-p+1;
                Pmergesort(A,p,q,T,qt+1);
                Pmergesort(T,1,qt,qt+1,n,B,s);
        }

}
>>>>>>> bdc58f287dff44eff9b60384435ff3e7832c9afa

		


}
void Pmerge (keytype* T, int p1, int r1, int p2, int r2,keytype* A, int p3)
{
	int n1 = r1 - p1 + 1;
	int n2 = r2 - p2 + 1;
	if (n1 < n2) {//ensure that n1>=n2
		exchange(p1, p2);
		exchange(r1, r2);
		exchange(n1, n2);
	}
	if (n1 == 0) return;
	else {
		int q1 = (p1 + r1) / 2;
		int q2 = BinarySearch(*(T + q1), T, p2, r2);
		int q3 = p3 + (q1 - p1) + (q2 - p2);
		*(A + q3) = *(T + q1);
		Pmerge(T,p1,q1-1,p2,q2-1,A,p3);
		Pmerge(T, q1 + 1, r1, q2, r2, A, q3 + 1);
	}


}

void exchange(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

}
int BinarySearch(int x, keytype* T, int p, int r)
{
	int low = p;
	int high = (p >(r+1))? p:(r+1);	//max(p,r+1)
	while (low < high) {
		int mid = (low + high) / 2;
		if (x <= *(T + mid))
			high = mid;
		else low = mid + 1;
	}
	return high;
}

/* eof */
