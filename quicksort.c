#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Quick Sort

void quickSort(int *array,int first,int last){
	
    int i; 
    int j; 
    int pivot; 
    int tmp; 
    pivot=first; 
   
    // If the last element done here is larger than the first element, as long as the last element is larger than the first element,  
	// An element smaller than the pivot is selected and replaced.
    if(last>first){
        pivot=first;
        i=first;
        j=last;
        while (i<j){
            while (array[i]<=array[pivot] && i<last && j>i){ // There is an element larger than the pivot at the beginning
                i++;
            }
            while (array[j]>=array[pivot] && j>=first && j>=i){ // There is an element smaller than the end pivot
                j--;
            }
            if (j>i){ 
                tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
        // re-pivot is selected and other parts of the split linked list are sent back to the quick sort function
        tmp=array[j];
        array[j]=array[pivot];
        array[pivot]=tmp;
        quickSort(array,first,j-1);
        quickSort(array,j+1,last);
    }
}
int main(){
	
	int n,k,j;
	time_t t;
	
	srand(time(NULL));
	
	printf("Enter size of array:");
	scanf("%d",&n);
	
	int *array1=(int*)malloc(n*sizeof(int));
	
	
	for(k=0;k<n;k++){
		array1[k]=(rand() %50);
	}
	

	
	printf("[");
	for(k=0;k<n;k++){
		printf("%d",array1[k]);
		if(k<n-1){
			printf(",");
		}
	}
	printf("]");
	
	
	
	
	quickSort(array1,0,n-1);
	
	
	
	
	printf("\nSorted array:[");
	for(k=0;k<n;k++){
		printf("%d",array1[k]);
		if(k<n-1){
			printf(",");
		}
	}
	printf("]");
	
    free(array1);
	
	return 0;
}
