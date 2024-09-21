#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(){
    FILE *src = fopen("d:/IUT accademic/CSE_4202_lab6/100dollars.tif", "rb");
    FILE *dst = fopen("100dollars_blurred.tif", "wb");

    BYTE metadata[8];

    fread(&metadata, sizeof(BYTE), 8, src);
    fwrite(&metadata, sizeof(BYTE), 8, dst);

    BYTE rdata[500][1192], wdata[500][1192];

    fread(&rdata, sizeof(BYTE), 500 * 1192, src);
    for (int i = 0; i < 500; i++){
        for (int j = 0; j < 1192; j++){
            int sum = 0, cnt = 0;
            for (int dx = -7; dx <= 7; dx++){
                for (int dy = -7; dy <= 7; dy++){
                    int x, y;
                    x = i + dy;
                    y = j + dx;
                    if (x >= 0 && y >= 0 && x < 500 && y < 1192){
                        sum += rdata[x][y];
                        cnt++;
                    }
                }
            }
            int res = sum / cnt;
            wdata[i][j] = res;
        }
    }
    fwrite(&wdata, sizeof(BYTE), 500 * 1192, dst);

    BYTE chunk;
    while (fread(&chunk, sizeof(BYTE), 1, src)) {
        fwrite(&chunk, sizeof(BYTE), 1, dst);
    }

    fclose(src);
    fclose(dst);

    printf("Image Successfully Processed\n");
    return 0;
}
