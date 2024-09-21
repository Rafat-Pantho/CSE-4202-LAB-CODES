#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef long long ll;

#define WIDTH       1192
#define HEIGHT      500
#define f(i,n)      for (ll i=0;i<n;i++)
#define f1(i,n)     for (ll i=7;i<n-7;i++)
#define f2(i,n)     for (ll i=-n;i<=n;i++)
#define f3(i,n)     for (ll i=0;i<n;i+=2)
#define wo(a)       while(!feof(a))

void flipHorizontal(uint8_t image[HEIGHT][WIDTH]){
    f(i,HEIGHT) f(j,WIDTH/2) {
        uint8_t temp = image[i][j];
        image[i][j] = image[i][WIDTH-1-j];
        image[i][WIDTH-1-j] = temp;
        j++;
    }
}

void flipVertical(uint8_t image[HEIGHT][WIDTH]){
    f(i,HEIGHT/2) {
        f(j,WIDTH) {
            uint8_t temp = image[i][j];
            image[i][j]=image[HEIGHT-1-i][j];
            image[HEIGHT-1-i][j] = temp;
        }
        i++;
    }
}

void neg(uint8_t image[HEIGHT][WIDTH]){
    f3(i,HEIGHT) f(j,WIDTH){
        image[i][j] = 255 - image[i][j];
    }
}

void blur(uint8_t image[HEIGHT][WIDTH], int redi){
    uint8_t new_img[HEIGHT][WIDTH];
    
    f(i, HEIGHT) {
        f(j, WIDTH) new_img[i][j] = image[i][j];
    }
    f(i, HEIGHT) f(j, WIDTH) {
        int sum = 0, cnt = 0;
        f2(di,redi) f2(dj,redi) {
            ll ddi = i + di,ddj = j + dj;
            if (ddi >= 0 && ddi < HEIGHT && ddj >= 0 && ddj < WIDTH) {
                sum += new_img[ddi][ddj];
                cnt++;
            }
        }
        image[i][j] = sum / cnt;
    }
}

int main() {
    FILE *inputFile = fopen("d:/IUT accademic/CSE_4202_lab6/100dollars.tif", "rb");
    FILE *outputFile = fopen("d:/IUT accademic/CSE_4202_lab6/fun_neg_img.tif", "wb");
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

    int r;
    printf("Enter radius for your blurring: ");
    scanf("%d",&r);

    //flipHorizontal(image);
    //flipVertical(image);
    neg(image);
    blur(image,r);

    fwrite(&image, sizeof(uint8_t), HEIGHT*WIDTH, outputFile);

    uint8_t trailing ;
    wo(inputFile){
        fread(&trailing, sizeof(uint8_t), 1, inputFile);
        fwrite(&trailing, sizeof(uint8_t), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Image blurred and saved successfully.\n");

    return 0;
}