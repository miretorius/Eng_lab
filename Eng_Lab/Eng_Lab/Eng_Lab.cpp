#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void input(int**,int);
float processing(int**,int,int);
void output(int**,int);
int** change(int**, int *order);

enum menu
{
	input_v=1,
    output_v=2,
    proessing_v=3,
	output_sum=4,
	change_v=5,
	exit_v=6
};
enum 
{
	manually=1,
	randomly=2
};

void main(void)
{
	printf("firts commit");
	int order,element,quarter,variant=0;
	float sum=0;
	setlocale(LC_ALL, "rus");
	do{
		printf("¬ведите пор€док матрицы: ");
	    scanf("%d",&order);
		fflush(stdin);
	  }while(order<=1);
	do{
		printf("¬ведите четверть: ");
        scanf("%d",&quarter);
		fflush(stdin);
	  }while(quarter<1||quarter>4);
	int **a= new int*[order]();
	for(int i=0;i<order;i++)
	{
		a[i]=new int[order]();
	}
	while(variant!=exit_v)
	{
		printf("\n1-ввод\n2-обработка\n3-вывод элементов\n4-вывод значени€\n5-изменение размерности массива\n6-выхооод из программы\n-");
		scanf("%d",&variant);
		switch(variant)
		{
			case input_v:
				input(a,order);
		        break;
			case output_v:
				sum=processing(a,order,quarter);
		        break;
			case proessing_v:
				output(a,order);
		        break;
			case output_sum:
				printf("%f",sum);
				break;
			case change_v:
				a=change(a, &order);
			
		}
	}
}

void input(int **a,int order)
{
	int element,variant;
    printf("\n—пособ ввода данных(1-с клавиатуры,2-рандомные значени€): ");
	scanf("%d",&variant);
	if(variant==manually)
	{
		for(int i=0;i<order;i++)
		{
			for(int j=0;j<order;j++)
			{
				printf("\n¬ведите элемент матрицы(%d;%d): ",i+1,j+1);
				scanf("%d",&element);
				a[i][j]=element;
			}
		}
	}
	if(variant==randomly)
	{
		for(int i=0;i<order;i++)
		{
			for(int j=0;j<order;j++)
			{
				a[i][j]=rand()%9;
			}
		}

	}
}
void output(int **a,int order)
{

	for(int i=0;i<order;i++)
	{
		printf("\n");
		for(int j=0;j<order;j++)
	    {
		    printf("%d ",a[i][j]);
	    }
    }

}
float processing(int **a,int order,int quarter)
{
	float sum=0;
	int counter=0;

	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			if(quarter==1)
			{
				if(j>=i&&i+j<=order-1)
			    {
					sum+=a[i][j];
					counter++;
			    }
		    }
			if(quarter==2)
			{
				if(j>=i&&i+j>=order-1)
				{
					sum+=a[i][j];
					counter++;
				}
			}
			if(quarter==3)
			{
				if(j<=i&&i+j>=order-1)
			    {
					sum+=a[i][j];
					counter++;
			    }
			}
            if(quarter==4)
			{
				if(j<=i&&i+j<=order-1)
			    { 
					sum+=a[i][j];
					counter++;
			    }
			}
		}
	}
	 
	return sum/counter;
}
int** change(int **a, int *order)
{
	delete [] *a;
	do{
		printf("¬ведите пор€док матрицы: ");
	    scanf("%d",order);
		fflush(stdin);
	  }while(*order<=1);
	int **b= new int*[*order]();
	for(int i=0;i<*order;i++)
	{
		b[i]=new int[*order];
	}
	return b;
}

