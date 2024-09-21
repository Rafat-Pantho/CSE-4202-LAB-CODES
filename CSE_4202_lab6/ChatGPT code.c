#include <stdio.h>
#include <stdint.h>

// Function to read a 16-bit little-endian unsigned integer from a file
uint16_t read_uint16(FILE *file) {
    uint8_t buffer[2];
    fread(buffer, sizeof(uint8_t), 2, file);
    return (buffer[1] << 8) | buffer[0];
}

// Function to read a 32-bit little-endian unsigned integer from a file
uint32_t read_uint32(FILE *file) {
    uint8_t buffer[4];
    fread(buffer, sizeof(uint8_t), 4, file);
    return (buffer[3] << 24) | (buffer[2] << 16) | (buffer[1] << 8) | buffer[0];
}

int main() {
    FILE *inputFile = fopen("d:/IUT accademic/CSE_4202_lab6/100dollars.tif", "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Skip TIFF header (8 bytes)
    fseek(inputFile, 8, SEEK_SET);

    // Read byte order (II for little-endian, MM for big-endian)
    uint8_t byteOrder[2];
    fread(byteOrder, sizeof(uint8_t), 2, inputFile);

    int littleEndian = (byteOrder[0] == 'I' && byteOrder[1] == 'I');

    // Read offset of the first IFD (Image File Directory) (4 bytes)
    uint32_t ifdOffset = read_uint32(inputFile);

    // Move to the first IFD
    fseek(inputFile, ifdOffset, SEEK_SET);

    // Read the number of entries in the IFD (2 bytes)
    uint16_t numEntries = read_uint16(inputFile);

    uint16_t imageWidth = 0, imageHeight = 0;
    int foundWidth = 0, foundHeight = 0;

    // Loop through IFD entries to find width and height tags
    for (int i = 0; i < numEntries; i++) {
        // Read tag ID (2 bytes)
        uint16_t tagID = read_uint16(inputFile);

        // Check for ImageWidth (0x0100) or ImageLength (0x0101) tag
        if (tagID == 0x0100 || tagID == 0x0101) {
            // Read data type (2 bytes) and number of values (4 bytes)
            fseek(inputFile, 6, SEEK_CUR);
            
            // Read tag value offset (4 bytes)
            uint32_t tagValueOffset = read_uint32(inputFile);

            // Read the tag value (assuming 16-bit) at the given offset
            fseek(inputFile, tagValueOffset, SEEK_SET);
            uint16_t tagValue = read_uint16(inputFile);

            // Store width or height value based on the tag
            if (tagID == 0x0100) {
                imageWidth = tagValue;
                foundWidth = 1;
            } else {
                imageHeight = tagValue;
                foundHeight = 1;
            }

            // Break the loop if both width and height tags are found
            if (foundWidth && foundHeight) {
                break;
            }
        } else {
            // Skip over the rest of the entry (10 bytes)
            fseek(inputFile, 10, SEEK_CUR);
        }
    }

    fclose(inputFile);

    // Check if both width and height tags were found
    if (!foundWidth || !foundHeight) {
        fprintf(stderr, "Width or height tag not found in TIFF file\n");
        return 1;
    }

    // Print image width and height
    printf("Image Width: %d\n", imageWidth);
    printf("Image Height: %d\n", imageHeight);

    return 0;
}
