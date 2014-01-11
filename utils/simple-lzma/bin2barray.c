/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *in;
    char *fname = argv[1];
    unsigned char c;
    int count = 0;
    
    if (fname == NULL) {
        printf("input name error\n");
        return -1;
    }

    if ((in = fopen(fname, "rb")) == NULL) {
        printf("open file fails\n");
        return -1;
    }

    printf("const unsigned char vmlrd_lzma[] = {\n");

    while (fread(&c, sizeof(unsigned char), 1, in)) {
        printf("0x%02x, ", c);
        count++;
        if (count % 16 == 0)
            printf("\n");
    }

    printf("0x00};\n");
    printf("const unsigned long vmlrd_lzmaSize = sizeof(vmlrd_lzma);\n");

    fclose(in);
        
    return 0;
}
