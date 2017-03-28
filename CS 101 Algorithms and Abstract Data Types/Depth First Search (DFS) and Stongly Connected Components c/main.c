#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Graph.h"


#define MAX_LEN 160

int main(int argc, char* argv[])
{
    int  count=0;
    FILE *in, *out;
    char* line = malloc(MAX_LEN*sizeof(char));
    int** dArray;
    int j, i = 0;





    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if( in==NULL )
    {
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }
    if( out==NULL )
    {
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }

    /* read each line of input file, then count and print tokens */
    while( fgets(line, MAX_LEN, in) != NULL)
    {
        count++;

    }
    fclose(in);


    dArray = calloc( count, sizeof(int*));
    for(i = 0; i < count; i ++)
    {
        dArray[i] = calloc( 2, sizeof(int));
    }







    in = fopen(argv[1], "r");
    if( in==NULL )
    {
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }
    fscanf(in, "%d", &dArray[0][0]);
    for (i = 1; i < count; i++)
    {
        for (j = 0; j < 2; j++)
        {

            fscanf(in, "%d", &dArray[i][j]);

        }


    }


    Graph G = newGraph(dArray[0][0]);
    for (i = 1; i < count; i++)
    {
        j = 0;

        addArc(G,dArray[i][j], dArray[i][j+1]);
    }




    printGraph( out, G);
    List S= getGraphVerices(G);
    DFS(G,S);
    Graph T = transpose(G);
    DFS(T, S);

    fprintf( out, " \n");


    List O = newList();
    int k = 0;

    fprintf( out, "G contains %d strongly connected components:\n",
             getNrOfComponents(T));

    for (moveBack(S); index(S) >= 0; movePrev(S))
    {
        prepend(O, get(S));
        if(getParent(T,get(S)) == NILL)
        {
            k++;
            fprintf(out, "Component %d: ", k);
            for(moveFront(O); index(O) >= 0; moveNext(O))
            {
                fprintf(out,"%d ", get(O));
            }
            fprintf(out, "\n");
            clear(O);
        }
    }









    for (i = 0 ; i < count; i++)
    {
        free(dArray[i]);
    }

    free(line);
    free(dArray);
    freeGraph(&G);
    freeGraph(&T);
    freeList(&O);
    fclose(in);
    fclose(out);


    return 0;
}
