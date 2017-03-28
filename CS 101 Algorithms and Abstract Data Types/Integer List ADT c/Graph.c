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
typedef struct GraphObj{
   List listPtr;
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
Graph newGraph(int n){
Graph G = malloc(sizeof(GraphObj));
G->listPtr = NULL;
G->color = NULL;
G->parent = NULL;
G->distance = NULL;
G->size = 0;
G->order = n;
G->source = 0;
return G;
}



// freeNode()
// Frees heap memory pointed to by *pG, sets *pG to NULL.
// Private.
void freeNode(Graph* pG){
   if( pG!=NULL && *pG!=NULL ){
      free(*pG);
      *pG = NULL;
   }
}



// getOrder()
// Returns the value at the order.
// Pre: G != NULL
int getOrder(Graph G){
if( G==NULL ){
      printf("Graph Error: calling getOrder() on NULL Graph reference\n");
      exit(1);
   }

   return G->order;

}


// getSize()
// Returns the size of the Graph.
// Pre: G != NULL
int getSize(Graph G){
if( G==NULL ){
      printf("Graph Error: calling getsize() on NULL Graph reference\n");
      exit(1);
   }
   return G->size;
}



// getSource()
// Returns the value of the source of the Graph.
// Pre: G != NULL
int getSource(Graph G){
if( G==NULL ){
      printf("Graph Error: calling getSource() on NULL Graph reference\n");
      exit(1);
   }
   return G->source;

}


// getParent()
// Returns the value of the parent of u.
// Pre: G != NULL &&  1<=u < getOrder()
int getParent(Graph G, int u){
if( G==NULL ){
      printf("Graph Error: calling getParent() on NULL Graph reference\n");
      exit(1);
   }

if((u < 1) && (u > getOrder())) {
     printf("Graph Error: calling getParent() on vertex out of bound\n");
      exit(1);
   }

if(parent) return parent[u];
return parent;

}


// getDist()
// Returns the value of the distance to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getDist(Graph G, int u){
if( G==NULL ){
      printf("Graph Error: calling getDist() on NULL Graph reference\n");
      exit(1);
   }

if((u < 1) && (u > getOrder())) {
     printf("Graph Error: calling getDist() on vertex out of bound\n");
      exit(1);
   }

if(distance) return distance[u];
return distance;

}



// getPath()
// Appends to the List the the vertices of a shortest path in G
// Pre: G != NULL && getSource(G)!=NULL &&  1<=u< getOrder()
void getPath(List L, Graph G, int u){
if( G==NULL ){
      printf("Graph Error: calling getPath() on NULL Graph reference\n");
      exit(1);
   }

if((u < 1) && (u > getOrder())) {
     printf("Graph Error: calling getPath() on vertex out of bound\n");
      exit(1);
   }

if (getSource(G) == NULL){
    printf("Graph Error: calling getPath() on NULL source\n");
      exit(1);
}


}

