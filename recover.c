#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
BYTE cord[512];

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover filename.JPEG \n");
        return 1;
    }

    char *IN_file_name = argv[1];
    FILE *inpic = fopen(argv[1], "r");

    if (inpic == NULL)
    {
        fclose(inpic);
        fprintf(inpic, "Could not open file %s.\n", argv[1]);
        return 2;
    }
    int counter = 0;
    FILE *outpic = NULL;
    char OUT_file_name[8] ;
    while (fread(&cord, 512, 1, inpic) == 1)
    {
        if (cord[0] == 0xff && cord[1] == 0xd8 && cord[2] == 0xff && (cord[3] & 0xf0) == 0xe0)
        {
            if (!(counter == 0))
            {
                fclose(outpic);
            }
            sprintf(OUT_file_name, "%03i.jpg", counter);
            outpic = fopen(OUT_file_name, "w");
            counter++;
        }
        if (!(counter == 0))
        {
            fwrite(&cord, 512, 1, outpic);
        }
    }
    fclose(inpic);
    fclose(outpic);
    return 0;
}
