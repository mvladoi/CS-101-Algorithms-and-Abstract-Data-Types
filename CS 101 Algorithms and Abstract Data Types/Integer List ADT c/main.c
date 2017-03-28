



#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Graph.h"


#define MAX_LEN 160

int main(int argc, char* argv[])
{
   int  count=0;
   FILE *in, *out;
   char* line = "";
   int** dArray;
   int j = 0;
   int i = 0;


   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   /* read each line of input file, then count and print tokens */
   while( fgets(line, MAX_LEN, in) != NULL)  {
    count++;

   }
   fclose(in);


   /* allocate the array */
   dArray = calloc( count, sizeof(int*));
   for(i = 0; i < count; i ++){
    dArray[i] = calloc( 2, sizeof(int));
   }



   /* read the input */
   in = fopen(argv[1], "r");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

   fscanf(in, "%d", &dArray[0][0]);
   for (i = 1; i < count; i++){
    for (j = 0; j < 2; j++){

        fscanf(in, "%d", &dArray[i][j]);
    }
   }

     //G = newGraph(dArray[0][0]);



  /* for (i=0 ; i<count; i++) {
   for (j = 0; j < 2; j++){
    printf( "%d" , dArray[i][j]);
     }
     printf( "%s", "\n");
 }*/


   fclose(in);
   fclose(out);


    return 0;
}
