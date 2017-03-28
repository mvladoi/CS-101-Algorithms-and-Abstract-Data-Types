#ifndef _Graph_H_INCLUDED
#define _Graph_H_INCLUDED

#include "List.h"

// Exported type --------------------------------------------------------------
typedef struct GraphObj* Graph;


/*** Constructors-Destructors ***/

// newGraph()
// Returns reference to new empty Graph object.
Graph newGraph(int n);


// freeGraph()
// Frees all heap memory associated with Graph *pG, and sets *pG to NULL.
void freeGraph(Graph* pG);



/*** Access functions ***/


// getOrder()
// Returns the value at the order.
// Pre: G != NULL
int getOrder(Graph G);


// getSize()
// Returns the size of the Graph.
// Pre: G != NULL
int getSize(Graph G);

// getSource()
// Returns the value of the source of the Graph.
// Pre: G != NULL
int getSource(Graph G);

// getParent()
// Returns the value of the parent of u.
// Pre: G != NULL &&  1<=u < getOrder()
int getParent(Graph G, int u);

// getDist()
// Returns the value of the distance to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getDist(Graph G, int u);


// getPath()
// Appends to the List the the vertices of a shortest path in G
// Pre: G != NULL && getSource(G)!=NULL &&  1<=u< getOrder()
void getPath(List L, Graph G, int u);




/*** Manipulation procedures ***/

// makeNull()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void makeNull(Graph G);

// addEdge()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void addEdge(Graph G, int u, int v);

// addArc()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void addArc(Graph G, int u, int v);

// BFS()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void BFS(Graph G, int s);



/*** Other operations ***/


// printGraph()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void printGraph(FILE* out, Graph G);



#endif // GRAPH_H_INCLUDED
