
//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------

#ifndef _List_H_INCLUDE_
#define _List_H_INCLUDE_


// Exported type --------------------------------------------------------------
typedef struct ListObj* List;


// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object.
List newList(void);

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL);


// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L);


// back()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int back(List L);


// getLength()
// Returns the length of L.
int length(List L);

// index()
// Return the value of curr.
int index(List L);


// get()
// Returns cursor element.
//Pre: length()>0, index()>=0
int get(List L);


// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
int isEmpty(List L);


// Manipulation procedures ----------------------------------------------------

// clear()
// Resets this List to its original empty state.
void clear(List L);


//void moveFront()
// Places the cursor under the front element,
// Pre:!this.isEmpty(), otherwise does nothing.
void moveFront(List L);


//void moveBack()
// Places the cursor under the back element,
// Pre:!this.isEmpty(), otherwise does nothing.
void moveBack(List L);


// movePrev()
// Moves cursor one step toward
// Pre: If cursor is defined and not at front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L);



// moveNext()
// Moves cursor one step toward
// Pre: If cursor is defined and not at front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L);


// append()
// Places new data element at the end of L
void append(List L, int data);


// prepend()
// Places new data element at the end of L
void prepend(List L, int data);

// deleteFront()
// Deletes element at front of L
// Pre: !isEmpty(Q)
void deleteFront(List L);


// deleteBack()
// Deletes element at back of L
// Pre: !isEmpty(L)
void deleteBack(List L);


//insertBefore(int data)
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int data);





//insertAfter( ListL, int data)
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int data);


//insertSorted( ListL, int data)
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertSorted(List L, int data);
// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
void printList(List L);

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B);


// copy(List L)
// Returns a new List identical to this List.
List copyList(List L);

//concat(List A, List B)
// Returns a new List which is the concatenation of
// this list followed by L. The cursor in the new List
// is undefined, regardless of the states of the cursors
// in this List and L. The states of this List and L are
// unchanged.
List concat(List A, List B);




#endif
