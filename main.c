#include <stdio.h>
#include <stdlib.h>
void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int * arr , int low,int high ){ /**Still needs debugging**/

    int pivot = high;
    int i = low-1, j= high;

    int val1, val2 ;
    /**Partition**/
    while( i<= j){

        do{
            i++;
            val1 = arr[i];
            val2 = arr[ pivot ];
        }while( val1 <= val2 && i< pivot);

        do {
           j--;
           val1 = arr[pivot];
           val2 = arr[j];

        }while( val1 <= val2 && j>=0);

        if(i<j){
            swap( &arr[i], &arr[j] );
        }
    }
    /**Place pivot in its correct place*/
    swap( &arr[pivot] , &arr[i] ); /**Swap arr[i] that is > pivot, with pivot**/
    pivot = i;

    /** recursion **/
    if( low < pivot-1){
        quicksort(arr,low,pivot-1  );
    }
    if(high > pivot+1){
        quicksort(arr,pivot+1  ,high);
    }
}


int main(){

    int arr [] = {10 , 1 , 2 ,0, 5, 3, 6 , 9 , 8 , 14, 7};
    int size = sizeof(arr)/sizeof( arr[0]);

   // printf("%p\n", arr);
    quicksort(arr,0,size-1);

    //printf("%p\n", arr);

    for(int i= 0 ;i < size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\nEl7 Successful :) xD\n");
    return 0;
}
