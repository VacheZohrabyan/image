#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
    unsigned char Cyan;
    unsigned char Magenta;
    unsigned char Yellow;
    unsigned char Black;
}Pixel;

typedef struct{
    int width;
    int height;
    Pixel** pixel;
}Image;

void rand_color(Image* image){
    srand(time(0));

    FILE* pgmimg;
    pgmimg = fopen("image.pgm","wb");// .pbm         .pgm         .ppm
    if(pgmimg == NULL){
        return;
    }
    fprintf(pgmimg,"P5\n");         // p1 || p4     p2 || p5     p3 || p6
    fprintf(pgmimg,"%d %d\n",image->height,image->width);
    fprintf(pgmimg,"255\n");

    for(int i = 0; i < image->height;++i){
        for(int j = 0; j < image->width; ++j){
            fprintf(pgmimg,"%d %d %d %d %d %d %d",
                image->pixel[i][j].Red = rand() % 256 - rand() % 256,
                image->pixel[i][j].Green = rand() % 256 - rand() % 256,
                image->pixel[i][j].Blue = rand() % 256 - rand() % 256,
                image->pixel[i][j].Black = rand() % 256 - rand() % 256,
                image->pixel[i][j].Yellow = rand() % 256 - rand() % 256,
                image->pixel[i][j].Cyan = rand() % 256 - rand() % 256,
                image->pixel[i][j].Magenta = rand() % 256 - rand() % 256 
            );     
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
}
void create_memory(Image* image){
    image->height = 2160;
    image->width = 3840;
    image->pixel = (Pixel**)malloc(image->height * sizeof(Pixel*));
    if (image->pixel == NULL){
        free(image->pixel);
        return;
    }
    for (int i = 0; i < image->height; ++i)   {
        image->pixel[i] = (Pixel*)malloc(image->width * sizeof(Pixel));
        if (image->pixel[i] == NULL){
            for(int j = 0; j < i; ++j){
                free(image->pixel[j]);
            }
            free(image->pixel);
            free(image);
            return;
        }
    }
}

void load(Image* image, int i, int y){
    if(i < 0 && i >= image->height && y < 0 && y >= image->width){
        return;
    }
    printf("your cordinat in RGB red = %d, green = %d, blue = %d \n ",
                            image->pixel[i][y].Red,
                            image->pixel[i][y].Green,
                            image->pixel[i][y].Blue
                            );
}

void klear_memory(Image* image){
    for (int i = 0; i < image->height; ++i){
        free(image->pixel[i]);
    }
    free(image->pixel);
    free(image);
}
int main()
{
    Image* image;
    image = (Image*)malloc(sizeof(Image));
    if (image == NULL){
        return 0;
    }
    create_memory(image);
    if(image->pixel == NULL){
        free(image);
        return 0;
    }
    rand_color(image);

    printf("enter your ROW and COLUME__\b\b");
    int i = 0;
    int y = 0;
    scanf("%d %d",&i,&y);
    load(image,i,y);
    klear_memory(image);
}