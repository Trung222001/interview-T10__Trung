#include <stdio.h>
void sort( int array[],int size){
    for(int i=0; i<size; i++){
        for(int j = 0;j<size;j++){
            if(array[i]<array[j]){
                int temp= array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

int countArray(int array[], int size){
   for (int i = 0; i < size; i++) {
        int count = 0;
        int check = 0;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                check = 1;
                break;
            }
        }

        if (check==0) {
            for (int j = 0; j < size; j++) {
                if (array[i] == array[j]) {
                    count++;
                }
            }
            printf("số %d xuất hiện %d lần.\n", array[i], count);
        }
    }
}

int main(){
    int array[]={1,2,3,2,3,4,7,5,4,2,1,3,4,2,1,4,3};
    int size= sizeof(array)/sizeof(array[0]);
    printf("%d\n\n",size);
    //sort(array,size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    countArray(array,size);
}
