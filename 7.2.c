//插入排序 
void InsertionSort(ElementType A[], int N)
{
	int P, j;
	ElementType Tmp;
	
	for(P = 1; P < N; P++){
		Tmp = A[P];	//取出未排序中的第一个元素
		for (i = P; i > 0 && A[i-1] > Tmp; i--){
			A[i] = A[i-1];	//依次与已经排序序列中元素比较并且右移 
		} 
		A[i] = Tmp;
	}
} 
