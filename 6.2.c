/*堆中的路径
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径

输入样例：
5 3
46 23 26 24 10
5 4 3

输出样例：
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
	Create();		//初始化堆 
	for (i = 0; i < n; i++){		//元素逐个插入方式建堆 
		scanf("%d",&x);
		Insert(x);
	}
	//沿根方向各结点输出
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
