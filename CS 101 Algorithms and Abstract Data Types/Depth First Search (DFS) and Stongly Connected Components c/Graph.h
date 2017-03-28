#ifndef _Graph_H_INCLUDED
#define _Graph_H_INCLUDED



#include "List.h"


#define UNDEF -1
#define NILL -2
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



// getParent()
// Returns the value of the parent of u.
// Pre: G != NULL &&  1<=u < getOrder()
int getParent(Graph G, int u);

// getDiscover()
// Returns the value of the discover time to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getDiscover(Graph G, int u);


// getFinish()
// Returns the value of the finish time to the node u.
// Pre: G != NULL &&  1<=u< getOrder()
int getFinish(Graph G, int u);



// getGraphVertices()
// Return a List with all vertices in the Graph
List getGraphVerices(Graph G);


int getNrOfComponents(Graph G);






/*** Manipulation procedures ***/

// makeNull()
// Delete all edges of G
void makeNull(Graph G);

// addEdge()
// Insert a new edge joining u to v and v to u
// Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void addEdge(Graph G, int u, int v);

// addArc()
// Insert a new edge joining v to u
// Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void addArc(Graph G, int u, int v);

// DFS()
// Runs DFS algorithm on graph G
// Pre: length(S)==getOrder(G)

void DFS(Graph G, List S);



/*** Other operations ***/

//insertSorted()
//Insert the vertices in Adjacency List  in sorted order
//Pre: 1<= u <= getOrder(G),   1<= v <= getOrder(G)
void insertSorted(Graph G, int u, int v);


// printGraph()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void printGraph(FILE* out, Graph G);

//copyGraph()
//Copy the graph G
Graph copyGraph(Graph G);

//transpose()
//return the transpose graph of G
Graph transpose(Graph G);


void visit(Graph G, List S, int u, int* time);



#endif // GRAPH_H_INCLUDED
