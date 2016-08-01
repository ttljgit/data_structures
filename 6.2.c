/*���е�·��
��һϵ�и������ֲ���һ����ʼΪ�յ�С����H[]����������������±�i����ӡ��H[i]��������·��

����������
5 3
46 23 26 24 10
5 4 3

���������
24 23 10
46 23 10
26 10*/
#include <stdio.h>
#include <stdlib.h>
#define MAXH 1001
#define MINH -10001

int H[MAXH], size;
void Create();
int IsFull();
void Insert(int);

void Create()
{
	size = 0;
	H[0] = MINH;	//sentinel
}

void Insert(int X)
{
	int i;
	
	if(IsFull())
		return;
	
	for (i = ++size; H[i/2] > X; i/=2)
		H[i] = H[i/2];	
	H[i] = X;	
}

int IsFull()
{
	return size == 1000;
}

int main()
{
	int n, m, x, i, j;
	
	scanf("%d%d",&n,&m);
	Create();		//��ʼ���� 
	for (i = 0; i < n; i++){		//Ԫ��������뷽ʽ���� 
		scanf("%d",&x);
		Insert(x);
	}
	//�ظ������������
	for(i = 0; i < m; i++){
		scanf("%d",&j);
		printf("%d ",H[j]);
		while(j > 1){
			j/=2;
			printf("%d ",H[j]);
		}
		printf("\n");
	} 
	return 0;
}
