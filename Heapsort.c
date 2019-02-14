
#include <stdio.h>

int parentNode(int i){
	return (i-1)/2;
}
int leftChild(int i){
	return (i+1)*2-1;
}

int rightChild(int i){
	return (i+1)*2;
}

void exchange(int A[],int i, int j){
	int tmp;
	tmp = A[i];
	A[i]=A[j];
	A[j]=tmp;
}

void MaxHeapify(int A[],int i, int n){
	int left = leftChild(i);
	int right = rightChild(i);
	int max = i, tmp, j;

	if(left<n && A[left]>A[max]){
		max = left;
	}

	if(right<n && A[right]>A[max]){
		max = right;
	}
	
	if(max!=i){
		exchange(A,i,max);
		MaxHeapify(A,max,n);
	}
}

void buildMaxHeap(int A[], int n) {
	int i;
	for(i=n/2;i>=0;i--){
		MaxHeapify(A,i,n);
	}
}

void heapSort(int A[],int n){
	int i, s = n;
	
	buildMaxHeap(A, n);
	for(i=n-1; i>0;i--){
		exchange(A, i, 0);
		s--;
		MaxHeapify(A, 0, s);
	}
}

void printArray( int A[], int n){
int i;
printf("[");
for (i = 0; i < n; i++) {
	printf("%d", A[i]);
	if (i < n-1) printf(", ");
	}
	printf("]");
}

void printHeap(int A[], int n){
	
	int i, l, r;
	
	printf("graph g {\n");
	for (i = 0; i < n; i++){ 
		l = leftChild(i); 
		r = rightChild(i); 
		if (l < n) printf(" %d -- %d\n", A[i], A[l]); 
		if (r < n) printf(" %d -- %d\n", A[i], A[r]); 
	}
	printf("}");
}

void main() {

	int A[100], n, i;
	
	printf("Enter an unsorted array (type 'end' to stop): ");
	n = 0;
	while(scanf("%d", &A[n]) == 1) {
		n++;
	}

	buildMaxHeap(A, n);
	printHeap(A, n);
	heapSort(A, n);
	printf("\n");
	printf("Sorted array:");
	printArray(A,n);


}

