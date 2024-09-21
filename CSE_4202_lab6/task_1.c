#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main()
{
    FILE *src = fopen("d:/IUT accademic/CSE_4202_lab6/100dollars.tif", "rb");
    FILE *dst = fopen("100dollars_flipped.tif", "wb");

    BYTE metadata1[8];
    fread(&metadata1, sizeof(BYTE), 8, src);
    fwrite(&metadata1, sizeof(BYTE), 8, dst);

    BYTE rdata[500][1192], wdata[500][1192];

    fread(&rdata, sizeof(BYTE), 500 * 1192, src);
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 1192; j++)
        {
            wdata[i][j] = rdata[i][1192 - j - 1];
        }
    }
    fwrite(&wdata, sizeof(BYTE), 500 * 1192, dst);

    BYTE pix;
    while (fread(&pix, sizeof(BYTE), 1, src))
    {
        fwrite(&pix, sizeof(BYTE), 1, dst);
    }

    fclose(src);
    fclose(dst);

    printf("Image Successfully processed\n");
    return 0;
}
