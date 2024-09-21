#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef long long ll;

#define WIDTH       1192
#define HEIGHT      500
#define f(i,n)      for (ll i=0;i<n;i++)
#define f1(i,n)     for (ll i=0;i<n;i+=2)
#define wo(a)       while(!feof(a))


void flipHorizontal(uint8_t image[HEIGHT][WIDTH]){
    f(i,HEIGHT) f(j,WIDTH/2) {
        uint8_t temp = image[i][j];
        image[i][j]=image[i][WIDTH-1-j];
        image[i][WIDTH-1-j] = temp;
        j++;
    }
}

int main() {
    FILE *inputFile = fopen("d:/IUT accademic/CSE_4202_lab6/100dollars.tif", "rb");
    FILE *outputFile = fopen("d:/IUT accademic/CSE_4202_lab6/flipped_image.tif", "wb");
    if (inputFile == NULL) {
        printf("Error opening input image file.\n");
        return 1;
    }
    if (outputFile == NULL) {
        printf("Error opening output image file.\n");
        return 1;
    }

    uint8_t metadata[8];
    fread(&metadata, sizeof(uint8_t), 8, inputFile);
    fwrite(&metadata, sizeof(uint8_t), 8, outputFile);

    uint8_t image[HEIGHT][WIDTH];

    fread(&image, sizeof(uint8_t),HEIGHT*WIDTH, inputFile);

    flipHorizontal(image);

    fwrite(&image, sizeof(uint8_t), HEIGHT*WIDTH, outputFile);

    uint8_t trailing ;
    wo(inputFile){
        fread(&trailing, sizeof(uint8_t), 1, inputFile);
        fwrite(&trailing, sizeof(uint8_t), 1, outputFile);
    }
    


    fclose(inputFile);
    fclose(outputFile);
    printf("Image flipped and saved successfully.\n");

    return 0;
}