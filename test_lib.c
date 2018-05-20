#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

#include "inttypes.h"
#include "fat16.h"

FILE *in, *out;

// Provide disk access function for FAT16 library
void FAT16_seek(uint32_t offset)
{
    fseek(in, offset, SEEK_SET);
}

int8_t FAT16_read(uint8_t *ptr, uint8_t bytes)
{
    return (int8_t)fread(ptr, 1, bytes, in);
}

int8_t FAT16_write(uint8_t bytes)
{
    return (int8_t)fwrite(fat16_buffer, 1, bytes, in);
}

int main(int argc, int8_t *argv[]) {
    int8_t bytes_read, counter = 0;
    int8_t x;

    // MUST MAKE THE FILE R/W as init() uses read to access and read the tables
    in = fopen("image.img", "r+");
    // Open disk image so fat16_seek and fat16_read work
    out = fopen("READ.txt", "a");
    
    // Use FAT16 library
    FAT16_init();

    x = FAT16_create_file("DATA    ", "TXT");
    printf("%d\n", x);
    

    while (gets(fat16_buffer) != 0)
    {
        while (fat16_buffer[counter] != 0) counter++;
        fat16_buffer[counter++] = '\n';
        bytes_read = FAT16_write_file(counter);
        fwrite(fat16_buffer, counter, 1, out); // Write read bytes
        counter = 0;
    }
    
    // Close file handles
    fclose(in);
    fclose(out);
    
    return 0;
}
