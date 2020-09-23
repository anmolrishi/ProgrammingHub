#include<stdio.h>
typedef struct element
{
	int index;
	int weight;
	float value;
}element;
typedef struct include_item_struct
{
	int index;
	int weight;
	float contribution;
}include_item_struct;
void sort(element [],int);
void get_fractions(int [],int [],element [],int);
void fractional_knapsack(element [],int ,int,float *,include_item_struct [],int *);
int main()
{
	int n,i,count_selected_item=0;
	int Capacity;
	include_item_struct item_included[100];
	float max_revenue=0;
	int weight[100],value[100];
	element fraction_item[100];
	printf("enter the no of items\n");
	scanf("%d",&n);
	printf("enter the weight of the items\n");
	for(i=0;i<n;i++)
	scanf("%d",&weight[i]);
	printf("enter the values/price of the items\n");
	for(i=0;i<n;i++)
	scanf("%d",&value[i]);
	printf("enter the capacity of the bag\n");
	scanf("%d",&Capacity);
	
	
	get_fractions(weight,value,fraction_item,n);
	sort(fraction_item,n);

	fractional_knapsack(fraction_item,n,Capacity,&max_revenue,item_included,&count_selected_item);
	
	
	printf("max revenue is %f\n",max_revenue);
	printf("no of items selected is %d\n",count_selected_item);
	printf("selected items are\n");
	for(i=0;i<count_selected_item;i++)
	{
		printf("item: %d \t weight taken: %d \t value contribution is: %f\n",item_included[i].index,\
		item_included[i].weight,item_included[i].contribution);
	}
	i--;
	
	
	printf("percentage of last one item is  %.2f %c",\
	((float)item_included[i].weight*100)/(float)weight[item_included[i].index-1],'%');
	
	return 0;
}
void get_fractions(int weight[],int value[],element fraction_item[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fraction_item[i].index=i+1;
		fraction_item[i].weight=weight[i];
		fraction_item[i].value=((float)value[i])/((float)weight[i]);
	}
}
void sort(element fraction_item[],int n)
{
	int i,j;
	float key;
	int w_temp,index;
	for(i=1;i<n;i++)
	{
		index=fraction_item[i].index;
		key=fraction_item[i].value;
		w_temp=fraction_item[i].weight;
		j=i-1;
		while(j>=0&&key<fraction_item[j].value)
		{
			fraction_item[j+1].index=fraction_item[j].index;
			fraction_item[j+1].value=fraction_item[j].value;
			fraction_item[j+1].weight=fraction_item[j].weight;
			j--;
		}
			fraction_item[j+1].value=key;
			fraction_item[j+1].weight=w_temp;
			fraction_item[j+1].index=index;
	}
}
void fractional_knapsack(element fraction_item[],int n,int Capacity,float *max_revenue,\
include_item_struct item_included[],int* count_selected_item)
{
	int i=n-1;
	int temp=0;
	while(i>=0&&Capacity>0)
	{
		if(fraction_item[i].weight<Capacity)
		{
			item_included[temp].index=fraction_item[i].index;
			item_included[temp].weight=fraction_item[i].weight;
			item_included[temp].contribution=fraction_item[i].value*fraction_item[i].weight;
			(*max_revenue)+=fraction_item[i].value*fraction_item[i].weight;
			Capacity-=fraction_item[i].weight;
		}
		else
		{
			item_included[temp].index=fraction_item[i].index;
			item_included[temp].weight=Capacity;
			item_included[temp].contribution=fraction_item[i].value*Capacity;
			(*max_revenue)+=fraction_item[i].value*Capacity;
			Capacity=0;	
		}
		i--;
		temp++;
	}
	(*count_selected_item)=temp;
}
