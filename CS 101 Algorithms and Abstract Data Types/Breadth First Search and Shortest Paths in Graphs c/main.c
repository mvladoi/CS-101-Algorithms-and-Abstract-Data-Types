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
    int j, i, alpha = 0;
    int position = -1;
    List L = newList();




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
        if ((dArray[i][0] == 0) && (dArray[i][1] == 0) && (!alpha)){
            position = i;
            alpha = 1;
        }

    }

    Graph G = newGraph(dArray[0][0]);
    for (i = 1; i <= position; i++)
    {
        j = 0;

        addEdge(G,dArray[i][j], dArray[i][j+1]);
    }

    printGraph( out, G);

    for (i = position+1; i < count-1; i++)
    {

        BFS(G,dArray[i][0]);

        fprintf(out,"%s%d%s%d%s" , "\n\nThe distance from ", dArray[i][0],
                " to ", dArray[i][1], " is ");
                if (getDist(G,dArray[i][1]) == INF){
                    fprintf(out, "infinity");
                    fprintf( out,"\nNo %d-%d path exists" , dArray[i][0], dArray[i][1]);

                }
                else{
                    fprintf(out, "%d", getDist(G,dArray[i][1]));

        }


        if(getDist(G, dArray[i][1]) == 0)
        {
            fprintf(out,"\nA shortest %d-%d is: %d", dArray[i][0], dArray[i][1],
                    dArray[i][0]);

        }


        else if ((getDist(G, dArray[i][1]) > 0))
        {
            getPath(L,G,dArray[i][1]);
            fprintf(out,"\nA shortest %d-%d is: ", dArray[i][0], dArray[i][1]);
            deleteFront(L);
            for(moveFront(L); index(L) >=0; moveNext(L))
            {
                fprintf(out, "%d ", get(L));
            }

        }
        clear(L);
    }



    for (i = 0 ; i < count; i++){
        free(dArray[i]);
    }

    free(line);
    free(dArray);
    freeGraph(&G);
    freeList(&L);
    fclose(in);
    fclose(out);


    return 0;
}
