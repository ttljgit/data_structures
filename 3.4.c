//����ʽADT
#include <stdio.h>
#include <stdlib.h>
#define MaxDegree 100
typedef struct{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} * Polynomial;
//����ʽ��ʼ��Ϊ0
void ZeroPolynomial(Polynomial Poly)
{
	int i;
	
	for(i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}
//������ߴ���
int max(const Polynomial p1, const Polynomial p2)
{
	return p1->HighPower > p2->HighPower ? p1->HighPower : p2->HighPower;	
} 
//��������ʽ���
void Add(const Polynomial p1, const Polynomial p2)
{
	int i;
	Polynomial psum;
	
	ZeroPolynomial(psum);
	psum->HighPower = max(p1, p2);
	if(psum->HighPower > MaxDegree)
		printf("Exceeded array size");
	for(i = psum->HighPower; i>=0; i--)
		psum->CoeffArray[i] = p1->CoeffArray[i] + p2->CoeffArray[i];
}
//��������ʽ���
void Mul(const Polynomial p1, const Polynomial p2)
{
	int i, j;
	Polynomial pmul;
	
	ZeroPolynomial(pmul);
	pmul->HighPower = p1->HighPower + p2->HighPower;
	if(pmul->HighPower > MaxDegree)
		printf("Exceeded array size");
	else{
		for(i = 0; i <= p1->HighPower; i++){
			for(j = 0; j <= p2->HighPower; j++){
				pmul->CoeffArray[i+j] += p1->CoeffArray[i] * p2->CoeffArray[j];
			}
		}
	}
} 
int main()
{
	return 0;
}
