#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 5
#define COLOME 5

void walk_around(int** arr)
{
    for(int i = 0; i < ROW; ++i)
    {
        for(int j = 0; j < COLOME / 2; ++j)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[i][COLOME - 1 - j];
            arr[i][COLOME - 1 - j] = tmp;  
        }
    }
}

void insert(int** arr)
{
    for(int i = 0; i < ROW; ++i)
    {
        for(int j = 0; j < COLOME; ++j)
        {
            arr[i][j] = arr[i][j] ^ 1;
        }
    }
}
int main()
{
    srand(time(0));
    int** arr = (int**)malloc(ROW * sizeof(int*));
    if(arr == NULL){
        return 0;
    }
    for(int i = 0; i < ROW; ++i){
        arr[i] = (int*)malloc(COLOME * sizeof(int));
        if(arr[i] == NULL){
            return 0;
        }
    }
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLOME; ++j){
            arr[i][j] = rand() % 2;
        }
    }
    
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLOME; ++j){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    walk_around(arr);
    
    insert(arr);
    
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLOME; ++j){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < ROW; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}