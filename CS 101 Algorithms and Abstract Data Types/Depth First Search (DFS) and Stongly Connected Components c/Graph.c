//-----------------------------------------------------------------------------
// Graph.c
// Implementation file for Graph ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"
#include "List.h"




// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct GraphObj
{
    List* listPtr;
    int* finish;
    int* parent;
    int* discover;
    char* color;
    int order;
    int size;

} GraphObj;


// private Node type
typedef GraphObj* Graph;


// Constructors-Destructors ---------------------------------------------------

// newGraph()
// Returns reference to new empty Graph object.
Graph newGraph(int n)
{
    Graph G = malloc(sizeof(GraphObj));
    G->listPtr = malloc( (n+1) * sizeof(List));

    int i;
    for (i = 0; i <=n; i++)
    {
        List temp = newList();
        G->listPtr[i] = temp;

    }

    G->finish =   malloc((n+1) * sizeof(int));
    G->parent =   malloc((n+1) * sizeof(int));
    G->discover = malloc((n+1) * sizeof(int));
    G->color =    malloc((n+1) * sizeof(char));
    for(i = 1; i <= n; i++)
    {
        G->finish[i] = UNDEF;
        G->discover[i] = UNDEF;
        G->parent[i] = NILL;
        G->color[i] = 'w';
    }
    G->size = 0;
    G->order = n;


    return G;
}



// freeGraph()
// Frees heap memory pointed to by *pG, sets *pG to NULL.
// Private.
void freeGraph(Graph* pG)
{


    if ((*pG)->finish!= NULL)
    {
        free ((*pG)->finish);
        (*pG)->finish = NULL;
    }

    if ((*pG)->discover != NULL)
    {
        free ((*pG)->discover);
        (*pG)->discover = NULL;
    }

    if ((*pG)->parent != NULL)
    {
        free ((*pG)->parent);
        (*pG)->parent = NULL;
    }

    if ((*pG)->color != NULL)
    {
        free ((*pG)->color);
        (*pG)->color = NULL;
    }


    if( pG!=NULL && *pG!=NULL )
    {
        free(*pG);
        *pG = NULL;
    }



}



// getOrder()
// Returns the value at the order.
// Pre: G != NULL
int getOrder(Graph G)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getOrder() on NULL Graph reference\n");
        exit(1);
    }

    return G->order;

}


// getSize()
// Returns the size of the Graph.
// Pre: G != NULL
int getSize(Graph G)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getsize() on NULL Graph reference\n");
        exit(1);
    }
    return G->size;
}


// getGraphVertices()
// Return a List with all vertices in the Graph
List getGraphVerices(Graph G)
{
    List A = newList();
    int i;
    for (i = 1; i <= getOrder(G); i++)
    {
        if (!isEmpty(G->listPtr[i]))
        {
            append(A,i);
        }
    }

    return A;
}






// getParent()
// Returns the value of the parent of u.
// Pre: G != NULL &&  1<=u < getOrder()
int getParent(Graph G, int u)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getParent() on NULL Graph reference\n");
        exit(1);
    }

    if((u < 1) && (u > getOrder(G)))
    {
        printf("Graph Error: calling getParent() on vertex out of bound\n");
        exit(1);
    }

    if(G->parent != NULL) return G->parent[u];
    return  NILL;

}


// getDist()
// Returns the value of the discover time to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getDiscover(Graph G, int u)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getDist() on NULL Graph reference\n");
        exit(1);
    }

    if((u < 1) && (u > getOrder(G)))
    {
        printf("Graph Error: calling getDist() on vertex out of bound\n");
        exit(1);
    }

    if(G->discover) return G->discover[u];
    return UNDEF;

}




// getFinish()
// Returns the value of the finish time to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getFinish(Graph G, int u)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getFinish() on NULL Graph reference\n");
        exit(1);
    }

    if((u < 1) && (u > getOrder(G)))
    {
        printf("Graph Error: calling getFinish() on vertex out of bound\n");
        exit(1);
    }

    if(G->finish) return G->finish[u];
    return UNDEF;

}



int getNrOfComponents(Graph G)
{
    int j = 0;
    int i;

    for(i = 1; i <= getOrder(G); i++)
    {
        if(getParent(G, i) == NILL)
        {
            j++;
        }
    }

    return j;
}






void makeNull(Graph G)
{

    if( G==NULL )
    {
        printf("Graph Error: calling makeNull() on NULL Graph reference\n");
        exit(1);
    }
    int i;
    for (i = 1; i <= getOrder(G); i++ )
    {
        for ( moveFront(G->listPtr[i]); index(G->listPtr[i]) >= 0;
                moveNext(G->listPtr[i]))
        {
            clear(G->listPtr[i]);
        }
    }

    G->size = 0;


}


// addEdge()
// Insert a new edge joining u to v and v to u
// Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void addEdge(Graph G, int u, int v)
{

    if( G==NULL )
    {
        printf("Graph Error: calling addEdge() on NULL Graph reference\n");
        exit(1);
    }

    if((u < 1) && (u > getOrder(G)))
    {
        printf("Graph Error: calling addEdge() on vertex  u out of bound\n");
        exit(1);
    }

    if((v < 1) && (v > getOrder(G)))
    {
        printf("Graph Error: calling addEdge() on vertex  v out of bound\n");
        exit(1);
    }





    insertSorted(G, u, v);
    insertSorted(G, v, u);

}



// addArc()
// Insert a new edge joining v to u
// Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void addArc(Graph G, int u, int v)
{

    if( G==NULL )
    {
        printf("Graph Error: calling addArc() on NULL Graph reference\n");
        exit(1);
    }

    if((u < 1) && (u > getOrder(G)))
    {
        printf("Graph Error: calling addArc() on vertex  u out of bound\n");
        exit(1);
    }

    if((v < 1) && (v > getOrder(G)))
    {
        printf("Graph Error: calling addEdge() on vertex  v out of bound\n");
        exit(1);
    }


    insertSorted(G, u, v);


}



// DFS()
// Runs DFS algorithm on graph G
// Pre: length(S)==getOrder(G)
void DFS(Graph G, List S)
{
    int time = 0;
    int u;
    List temp = copyList(S);
    for (moveFront(temp); index(temp) >= 0; moveNext(temp))
    {
        u = get(temp);
        deleteBack(S);
        if (G->color[u] == 'w')
        {
            visit(G,S,u, &time);
        }
    }

}





/*** Other operations ***/


void visit(Graph G, List S, int u, int* time)
{

    (*time) = (*time) + 1;
    G->discover[u] = (*time);
    G->color[u] = 'g';

    int v;
    for(moveFront(G->listPtr[u]); index(G->listPtr[u]) >= 0; moveNext(G->listPtr[u]))
    {
        v = get(G->listPtr[u]);


        if(G->color[v] == 'w')
        {
            G->parent[v] = u;
            visit(G,S,v,&(*time));
        }
    }
    G->color[u] = 'b';
    (*time)= (*time) + 1;
    G->finish[u] = (*time);

    prepend(S,u);

}



void printGraph(FILE* out, Graph G)
{
    if( G==NULL )
    {
        printf("Graph Error: calling addEdge() on NULL Graph reference\n");
        exit(1);
    }

    int i;
    for (i = 1; i <= getOrder(G); i++)
    {
        fprintf( out, "%d%s", i , ": " );

        for(moveFront(G->listPtr[i]); (index(G->listPtr[i])) >= 0;
                moveNext(G->listPtr[i]))
        {


            fprintf(out,"%d",get(G->listPtr[i]));
            fprintf(out,"%s", " ");

        }
        fprintf(out,"%s", "\n");


    }
}



//insertSorted()
//Insert the vertices in Adjacency List  in sorted order
//Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void insertSorted(Graph G, int u, int v)
{


    if( G->listPtr[u] == NULL )
    {
        printf("Graph Error: calling insertSorted() on NULL List reference\n");
        exit(1);
    }
    if( isEmpty(G->listPtr[u]) )
    {
        append(G->listPtr[u],v);
    }
    else
    {

        for(moveFront(G->listPtr[u]); index(G->listPtr[u]) >=0; moveNext(G->listPtr[u]))
        {
            int temp = get(G->listPtr[u]);
            if (temp > v)
            {
                insertBefore(G->listPtr[u],v);
                return;
            }

        }

        moveBack(G->listPtr[u]);
        insertAfter(G->listPtr[u],v);

    }




}



//copyGraph()
//Copy the graph G
Graph copyGraph(Graph G)
{

    if( G==NULL )
    {
        printf("Graph Error: calling copyGraph() on NULL Graph reference\n");
        exit(1);
    }
    Graph B = newGraph(getOrder(G));
    int i;
    int j ;
    for(i = 1; i <= getOrder(G); i++)
    {
        for(moveFront(G->listPtr[i]); index(G->listPtr[i]) >= 0; moveNext(G->listPtr[i]))
        {
            j = get(G->listPtr[i]);
            addArc(B, i, j);
        }
    }
    return B;

}


//transpose()
//return the transpose graph of G
Graph transpose(Graph G)
{


    if( G==NULL )
    {
        printf("Graph Error: calling transpose() on NULL Graph reference\n");
        exit(1);
    }
    Graph B = newGraph(getOrder(G));
    int i;
    int j ;
    for(i = 1; i <= getOrder(G); i++)
    {
        for(moveFront(G->listPtr[i]); index(G->listPtr[i]) >= 0; moveNext(G->listPtr[i]))
        {
            j = get(G->listPtr[i]);
            addArc(B, j, i);
        }
    }
    return B;

}





