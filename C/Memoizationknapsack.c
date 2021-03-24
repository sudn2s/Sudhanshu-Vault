
#include <stdio.h>
#include<stdlib.h>

int **MemoizationTable;

int Max(int a,int b){
   return (a>b)?a:b;
}

int createMemoization(int n,int capacity){
    MemoizationTable =(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    *(MemoizationTable+i)=(int*)malloc(capacity*sizeof(int));
    for(int i=0;i<n;i++)
        for(int j=0;j<capacity;j++)
            *(*(MemoizationTable+i)+j)=-1;
    
    }

int knapsack(int n,int *weight,int *profit,int capacity){
    //No item is left 
    //bag is full
    if(capacity==0||n==0){
        return 0;
    }

    //weight of item is capacity left
    else if(weight[n-1]>capacity){
        return knapsack(n-1,weight,profit,capacity);
    }
    //
    else{
        return Max(knapsack(n-1,weight,profit,capacity), profit[n-1]+knapsack(n-1,weight,profit,capacity-weight[n-1]));
    }
}

int DpMemoizationknapsack(int n,int *weight,int *profit,int capacity){
   
    if(MemoizationTable[n-1][capacity-1]==(-1)){
         //No item is left 
        //bag is full
        if(capacity==0||n==0){
        return 0;
         }

        //weight of item is greater than capacity left
         else if(weight[n-1]>capacity){
        return DpMemoizationknapsack(n-1,weight,profit,capacity);
         }
         //
         else{
             int result =Max(DpMemoizationknapsack(n-1,weight,profit,capacity), profit[n-1]+DpMemoizationknapsack(n-1,weight,profit,capacity-weight[n-1]));
             MemoizationTable[n-1][capacity-1]= result;
        return result;
            }
    }
    else{
        return MemoizationTable[n-1][capacity-1];
    }
}
int main() {
    int n,*weight,*profit,capacity;
    scanf("%d",&n);
    weight =(int*) malloc(n*sizeof(int));
    profit =(int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    scanf("%d",&weight[i]);

    for(int i=0;i<n;i++)
    scanf("%d",&profit[i]);
    
    scanf("%d",&capacity);
    //Recurrio
    //printf("Maximum profit=%d\n",knapsack(n,weight,profit,capacity));
    // printf("%d\n",n);
    // for(int i=0;i<n;i++)
    // printf("%d",weight[i]);
    //  printf("\n");
    // for(int i=0;i<n;i++)
    // printf("%d",profit[i]);
    // printf("\n");
    // printf("%d",capacity);
    createMemoization(n,capacity);
    printf("Maximum profit By Memoization=%d\n",DpMemoizationknapsack(n,weight,profit,capacity));
    for(int i=0;i<n;i++){
        for(int j=0;j<capacity;j++)
            printf("%d ",*(*(MemoizationTable+i)+j));
        printf("\n");
    }
}
