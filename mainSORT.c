# include <stdio.h>
# include "for_isort.h"

# define SIZE 50
int arr[SIZE];

int main(){

    int i = 0;

    while ((scanf("%d" , &arr[i]))!=EOF && i < SIZE){
        i++;
    }

    insertion_sort(arr , SIZE);

    for (int j = 0 ; j < SIZE-1 ; j++){
        printf("%d," , arr[j]);
    }
    
    printf("%d\n" , arr[SIZE-1]);


    return 0;

}