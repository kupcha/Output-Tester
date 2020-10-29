/*
@author Patrick Kupcha
This file is used to check output of my programs against the output of given reference programs. It will iterate through the files byte by byte to ensure they are the same.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
   if (argc != 3){
      printf("ERROR: input two files to check if they are the same.\n");
      return 0;
   }
   else{
      FILE *myOutput;
      FILE *referenceOutput;
      myOutput = fopen(argv[1], "r");
      referenceOutput = fopen(argv[2], "r");
      unsigned char mybuffer[1];
      unsigned char referenceBuffer[1];
      while(fread(mybuffer, sizeof(mybuffer), 1, myOutput) && fread(referenceBuffer, sizeof(referenceBuffer), 1, referenceOutput)){
         if (mybuffer[0] != referenceBuffer[0]){
            printf("Files are NOT equal.\n");
            return 0;
         }
      }
      printf("Files ARE equal.\n");
      return 1;
   }
}
