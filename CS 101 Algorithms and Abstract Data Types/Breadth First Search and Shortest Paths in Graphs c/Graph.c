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
    char* color;
    int* parent;
    int* distance;
    int order;
    int size;
    int source;
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

    G->color = malloc((n+1) * sizeof(char));
    G->parent = malloc((n+1) * sizeof(int));
    G->distance = malloc((n+1) * sizeof(int));
    G->size = 0;
    G->order = n;
    G->source = NILL;


    return G;
}



// freeGraph()
// Frees heap memory pointed to by *pG, sets *pG to NULL.
// Private.
void freeGraph(Graph* pG)
{


    if ((*pG)->color != NULL){
        free ((*pG)->color);
        (*pG)->color = NULL;
    }

     if ((*pG)->distance != NULL){
        free ((*pG)->distance);
        (*pG)->distance = NULL;
    }

     if ((*pG)->parent != NULL){
        free ((*pG)->parent);
        (*pG)->parent = NULL;
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



// getSource()
// Returns the value of the source of the Graph.
// Pre: G != NULL
int getSource(Graph G)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getSource() on NULL Graph reference\n");
        exit(1);
    }
    return G->source;

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
// Returns the value of the distance to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getDist(Graph G, int u)
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

    if(G->distance) return G->distance[u];
    return INF;

}



// getPath()
// Appends to the List the the vertices of a shortest path in G
// Pre: G != NULL && getSource(G)!=NULL &&  1<=u< getOrder()
void getPath(List L, Graph G, int u)
{
    if( G==NULL )
    {
        printf("Graph Error: calling getPath() on NULL Graph reference\n");
        exit(1);
    }

    if((u < 1) && (u > getOrder(G)))
    {
        printf("Graph Error: calling getPath() on vertex out of bound\n");
        exit(1);
    }

    if (getSource(G) == 0)
    {
        printf("Graph Error: calling getPath() on NULL source\n");
        exit(1);
    }

    int s = getSource(G);
    if (u == s)
    {
        append(L, s);
    }
    else if (G->parent[u] == NILL)
    {
        append(L, NILL);
    }
    else
    {
        getPath(L, G, G->parent[u]);
    }

    append(L,u);

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
    G->source = NILL;

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





    insertSorted(G->listPtr[u], v);
    insertSorted(G->listPtr[v], u);

}



// addArc()
// Insert a new edge joining v to u
// Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void addArc(Graph G, int u, int v)
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


    insertSorted(G->listPtr[u], v);


}



// BFS()
// Runs BFS algorithm on graph G
void BFS(Graph G, int s)
{

    if( G==NULL )
    {
        printf("Graph Error: calling BFS() on NULL Graph reference\n");
        exit(1);
    }

    if((s < 1) && (s > getOrder(G)))
    {
        printf("Graph Error: calling addEdge() on vertex  source out of bound\n");
        exit(1);
    }

    int i;
    for(i = 0; (i <=getOrder(G)); i++)
    {
        G->color[i] = 'w';
        G->distance[i] = INF;
        G->parent[i] = NILL;
    }

    G->color[s] = 'g';
    G->distance[s] = 0;
    G->parent[s] = NILL;

    //int g;
    //for (g = 1; (g <= getOrder(G)); g++){
    // printf("%d",  G->parent[g]);
    //}
    List queue = newList();
    prepend(queue, s);
    while(!isEmpty(queue))
    {
        moveFront(queue);
        int u = get(queue);
        deleteFront(queue);

        for(moveFront(G->listPtr[u]); index(G->listPtr[u]) >= 0;
                moveNext(G->listPtr[u]))
        {
            int v = get(G->listPtr[u]);

            if(G->color[v] == 'w')
            {
                G->color[v] = 'g';
                G->distance[v]= G->distance[u] + 1;
                G->parent[v] = u;
                append(queue, v);
            }


        }
        G->color[u] = 'b';

    }

}





/*** Other operations ***/
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
