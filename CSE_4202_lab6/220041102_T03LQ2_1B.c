#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef long long int ll;

#define HIGHT 500
#define WIDTH 1192

#define wo(a)  while(!feof(a))

void neg(uint8_t image[HIGHT][WIDTH],ll x,ll y, ll m, ll n){
    for(ll i =x;i<m+x;i++){
        for(ll j=y;j<n+y;j++){
            if (i >= 0 && i < HIGHT && j >= 0 && j < WIDTH) image[i][j] = 255 - image[i][j];
        }
    }
}

int main(){
    FILE *openInput = fopen("d:/IUT accademic/CSE_4202_LQ_02/100Dollars.tif","rb");
    FILE *openOutput = fopen("d:/IUT accademic/CSE_4202_LQ_02/100Dollars_neg.tif", "wb");
    uint8_t metadata[8];
    uint8_t image[HIGHT][WIDTH];
    uint8_t pix;
    ll t;

    fread(&metadata,sizeof(uint8_t),8,openInput);
    fwrite(&metadata,sizeof(uint8_t),8,openOutput);
    fread(&image,sizeof(uint8_t),HIGHT*WIDTH,openInput);

    scanf("%lld",&t);

    while (t--){
        ll x,y,m,n;
        scanf("%lld %lld %lld %lld", &x,&y,&m,&n);
        neg(image,x,y,m,n);
    }

    fwrite(&image,sizeof(uint8_t),HIGHT*WIDTH,openOutput);

    wo(openInput){
        fread(&pix, sizeof(uint8_t),1,openInput);
        fwrite(&pix, sizeof(uint8_t),1,openOutput);
    }

    fclose(openInput);
    fclose(openOutput);

    printf("DONE NEGATION\n");

    return 0;
}