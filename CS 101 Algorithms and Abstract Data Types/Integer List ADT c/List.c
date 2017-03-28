
//-----------------------------------------------------------------------------
// List.c
// Implementation file for List ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   int data;
   struct NodeObj* next;
   struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private QueueObj type
typedef struct ListObj{
   Node front;
   Node back;
   Node currPtr;
   int length;
   int curr;
} ListObj;


// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int data){
   Node N = malloc(sizeof(NodeObj));
   N->data = data;
   N->next = N->prev = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newQueue()
// Returns reference to new empty Queue object.
List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->front = L->back = L->currPtr = NULL;
   L->length = 0;
   L->curr = -1;
   return(L);
}


// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.S
void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL) {
      while( !isEmpty(*pL) ) {
         deleteFront(*pL);
      }
      free(*pL);
      *pL = NULL;
   }
}


// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L){
   if( L==NULL ){
      printf("List Error: calling front() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling front() on an empty List\n");
      exit(1);
   }
   return(L->front->data);
}



// back()
// Returns the value at the back of L.
// Pre: !isEmpty(L)
int back(List L){
   if( L==NULL ){
      printf("List Error: calling back() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling back() on an empty List\n");
      exit(1);
   }
   return(L->back->data);
}

// getLength()
// Returns the length of L.
int length(List L){
   if( L==NULL ){
      printf("List Error: calling length() on NULL List reference\n");
      exit(1);
   }
   return(L->length);
}


// index()
// Return the value of curr.
int index(List L){
    if( L==NULL ){
      printf("List Error: calling get() on NULL List reference\n");
      exit(1);
   }
	   return L->curr;
   }



// get()
// Returns cursor element.
//Pre: length()>0, index()>=0
int get(List L){
   if( L==NULL ){
      printf("List Error: calling get() on NULL List reference\n");
      exit(1);
   }

   if( isEmpty(L) ){
      printf("List Error: calling get() on an empty List\n");
      exit(1);
   }

   if (index(L) == -1){
      printf("List Error: calling get() on curr undefined\n");
      exit(1);

   }
    return L->currPtr->data;
}


// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
int isEmpty(List L){
   if( L==NULL ){
      printf("List Error: calling isEmpty() on NULL List reference\n");
      exit(1);
   }
   return(L->length==0);
}


// Manipulation procedures ----------------------------------------------------


// clear()
// Resets this List to its original empty state.
void clear(List L){
    int i;
    int j = length(L);

    if( L==NULL ){
      printf("List Error: calling front() on NULL List reference\n");
      exit(1);
   }
   for (i = 0; i < j; i++){
    deleteFront(L);
   }
   L->front = L->back = L->currPtr = NULL;

}



//void moveFront()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void moveFront(List L){
      if( L==NULL ){
       printf("List Error: calling moveFront() on NULL List reference\n");
       exit(1);
    }

     if (!isEmpty(L)){
        L->curr = 0;
        L->currPtr = L->front;

     }


}



//void moveBack()
// Places the cursor under the back element,
// Pre:!this.isEmpty(), otherwise does nothing.
void moveBack(List L){
      if( L==NULL ){
       printf("List Error: calling moveBack() on NULL List reference\n");
       exit(1);
    }

     if (!isEmpty(L)){
        L->curr = length(L) -1;
        L->currPtr = L->back;

     }


}


// movePrev()
// Moves cursor one step toward
// Pre: If cursor is defined and not at front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L){
       if( L==NULL ){
         printf("List Error: calling movePrev() on NULL List reference\n");
         exit(1);
      }

      if(index(L) == 0){
        L->curr = -1;
        L->currPtr = NULL;
      }

      if ((index(L) != -1) && (length(L) > 0)){
			L->curr --;
			L->currPtr = L->currPtr->prev;
		}

}




// moveNext()
// Moves cursor one step back
// Pre: If cursor is defined and not at front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L){
       if( L==NULL ){
         printf("List Error: calling moveNext() on NULL List reference\n");
         exit(1);
      }

      if(index(L) == length(L)-1){
        L->curr = -1;
        L->currPtr = NULL;
      }

      if ((index(L) != -1) && (index(L) < length(L)-1)){
			L->curr ++;
			L->currPtr = L->currPtr->next;
		}

}




// append()
// Places new data element at the end of L
void append(List L, int data)
{
   Node N = newNode(data);

   if( L==NULL ){
      printf("List Error: calling append() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ) {
      L->front = L->back = N;
   }else{
      L->back->next = N;
      N->prev = L->back;
      L->back = N;
   }
   L->length++;
}


// prepend()
// Places new data element at the end of L
void prepend(List L, int data)
{
   Node N = newNode(data);

   if( L==NULL ){
      printf("List Error: calling prepend() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ) {
      L->front = L->back = N;
   }else{
      L->front->prev = N;
      N->next = L->front;
      L->front = N;
   }
   L->length++;
   if (index(L) != -1){
   L->curr++;
   }
}




// DeleteFront()
// Deletes element at front of L
// Pre: !isEmpty(L)
void deleteFront(List L){
   Node N = NULL;

   if( L==NULL ){
      printf("List Error: calling deleteFront() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling deleteFront() on an empty List\n");
      exit(1);
   }
   N = L->front;
   if( length(L)>1 ) {
      L->front = L->front->next;
      L->front->prev = NULL;
   }else{
      L->front = L->back = NULL;
   }

   if (index(L) != -1){
    L->curr--;
   }

   L->length--;

   freeNode(&N);
}




// deleteBack()
// Deletes element at back of L
// Pre: !isEmpty(L)
void deleteBack(List L){
   Node N = NULL;

   if( L==NULL ){
      printf("List Error: calling deleteBack() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling deleteBack() on an empty List\n");
      exit(1);
   }
   N = L->back;

   if( length(L)>1 ) {
      L->back = L->back->prev;
      L->back->next = NULL;
   }else{
      L->front = L->back = NULL;
   }


   if(index(L) == length(L)-1){
    L->curr = -1;
   }



   L->length--;

   freeNode(&N);
}




   // delete()
   // Deletes cursor element, making cursor undefined.
   // Pre: length()>0, index()>=0

   void delete(List L){


   if( L==NULL ){
      printf("List Error: calling delete() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling delete() on an empty List\n");
      exit(1);
   }

    if (index(L) == -1){
      printf("List Error: calling delete() on curr undefined\n");
      exit(1);

   }

    if (index(L) == 0){
        deleteFront(L);
     }
    else if (index(L) == length(L)-1){
        deleteBack(L);
    }
    else{
        L->currPtr->prev->next = L->currPtr->next;
        L->currPtr->next->prev = L->currPtr->prev;
        L->curr = -1;
        L->length--;
        freeNode(&L->currPtr);
    }

   }

//insertBefore( ListL, int data)
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int data){

    if( L==NULL ){
      printf("List Error: calling insertBefore() on NULL List reference\n");
      exit(1);
   }
    if( isEmpty(L) ){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(1);
   }

     if (index(L) == -1){
      printf("List Error: calling insertBefore() on curr undefined\n");
      exit(1);

   }
    if (index(L) == 0){
        prepend(L, data);
    }
    else{
        Node M = newNode(data);
        L->currPtr->prev->next = M;
        M->prev = L->currPtr->prev;
        L->currPtr->prev = M;
        M->next = L->currPtr;
        L->length++;
        L->curr++;

    }

}



//insertAfter( ListL, int data)
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int data){

    if( L==NULL ){
      printf("List Error: calling insertAfter() on NULL List reference\n");
      exit(1);
   }
    if( isEmpty(L) ){
      printf("List Error: calling insertAfter() on an empty List\n");
      exit(1);
   }

     if (index(L) == -1){
      printf("List Error: calling insertAfter() on curr undefined\n");
      exit(1);

   }
    if (index(L) == length(L)-1){
        append(L, data);
    }
    else{
        Node M = newNode(data);
        L->currPtr->next->prev = M;
        M->next = L->currPtr->next;
        L->currPtr->next = M;
        M->prev = L->currPtr;
        L->length++;

    }

}


// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
void printList(List L){
   Node N = NULL;

   if( L==NULL ){
      printf("List Error: calling printList() on NULL List reference\n");
      exit(1);
   }

   for(N = L->front; N != NULL; N = N->next){
      printf("%d ", N->data);
   }

   printf("\n");
}

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B){
   int eq = 0;
   Node N = NULL;
   Node M = NULL;

   if( A==NULL || B==NULL ){
      printf("List Error: calling equals() on NULL List reference\n");
      exit(1);
   }

   eq = ( A->length == B->length );
   N = A->front;
   M = B->front;
   while( eq && N!=NULL){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
}


// copyList(List L)
// Returns a new List identical to this List.
List copyList(List L){
List Q = newList();
Node N = L->front;

while(N != NULL){
    append(Q, N->data);
    N = N->next;
}

return Q;

}




//concat(List A, List B)
// Returns a new List which is the concatenation of
// this list followed by L. The cursor in the new List
// is undefined, regardless of the states of the cursors
// in this List and L. The states of this List and L are
// unchanged.
List concat(List A, List B){

     List M = newList();
	 M = copyList(A);
	 Node N = B->front;

	       while( N!=NULL ){
	          append(M, N->data);
	          N = N->next;
        }

    return M;
}












