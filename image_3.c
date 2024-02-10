#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 5
#define COLOME 5


void rec(int** arr,int i, int j)
{
    if(i < 0 || i >= ROW || j < 0 || j >= COLOME || arr[i][j] == 1){
        return;
    }
    arr[i][j] = 0;
    rec(arr,i,j + 1);
    rec(arr,i,j - 1);
    rec(arr,i + 1,j);
    rec(arr,i - 1,j);
}
int main()
{
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

    srand(time(0));
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLOME; ++j){
            arr[i][j] = rand() % 2;
        }
    }

    int count = 0;
    
    for(int i = 1; i < ROW - 1; ++i)
    {
        for(int j = 1; j < COLOME - 1; ++j)
        {
            if(arr[i][j] == 1)
            {
                ++count;
                rec(arr,i,j);
            }
        }
    }
    
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLOME; ++j){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    printf("%d",count);
    for(int i = 0; i < ROW; ++i){
        free(arr[i]);
    }
    free(arr);
}