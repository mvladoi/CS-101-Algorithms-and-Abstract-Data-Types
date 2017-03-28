



class List<E> {

public class Node<E> {
    // Fields
    E data;
    Node<E> next;
    Node<E> prev;

    // Constructor
    Node(E data) { this.data = data; next = null; prev = null; }

    // toString():  overrides Object's toString() method
    public String toString() {
       return String.valueOf(data.toString());
    }

    // equals(): overrides Object's equals() method
    public boolean equals(Object x){
       boolean eq = false;
       Node<E> that;
       if(x instanceof Node){
          that = (Node) x;
          eq = (this.data.equals(that.data));
       }
       return eq;
    }
 }

 // Fields
 private Node<E> front;
 private Node<E> back;
 private Node<E> currPtr;
 private int length;
 private int curr;


 // Constructor
 List() {
    front = back = currPtr = null;
    length = 0;
    curr = -1;
 }


 // Access Functions --------------------------------------------------------



 // isEmpty()
 // Returns true if this List is empty, false otherwise.
 boolean isEmpty() {
    return length==0;
 }


 // length()
 // Returns length of this List.
 int length() {
    return length;
 }



 // index()
 // Return the value of curr.
 int index(){
	   return curr;
 }



 // back()
 // Returns back element.
 // Pre: !this.isEmpty().
  E back(){
       if( this.isEmpty() ){
          throw new RuntimeException(
             "List Error: back() called on empty List");
       }
       return back.data;
 }




 // front()
 // Returns front element.
 // Pre: !this.isEmpty().
 E front(){
    if( this.isEmpty() ){
       throw new RuntimeException(
          "List Error: front() called on empty List");
    }
    return front.data;
 }




 // get()
 // Returns cursor element.
 //Pre: length()>0, index()>=0
 E get(){
	   if (this.isEmpty()){
		  throw new RuntimeException(
		    "List Error: get() called on empty List");
     }
     if (this.index() == -1){
		 throw new RuntimeException(
		    "List Error: get() called on curr undefined");
	   }
    return currPtr.data;

 }




 // equals()
    // Overrides Object's equals() method.  Returns true if x is a Queue storing
    // the same integer sequence as this Queue, false otherwise.
    public boolean equals(Object x){
       boolean eq  = false;
       List<E> L;
       Node<E> N, M;

       if(x instanceof List){
          L = (List) x;
          N = this.front;
          M = L.front;
          eq = (this.length==L.length);
          while( eq && N!=null ){
             eq = N.equals(M);
             N = N.next;
             M = M.next;
          }
       }
       return eq;
    }





 // Manipulation Procedures -------------------------------------------------





 // clear()
 // Resets this List to its original empty state.
 void clear(){
	   front = back = currPtr = null;
	   length = 0;
	   curr = -1;

 }




 //void moveFront()
 // Places the cursor under the front element,
 // Pre:!this.isEmpty(), otherwise does nothing.
 void moveFront(){
	   if (!this.isEmpty()){
		   curr = 0;
		   currPtr = front;
	   }
 }




 // moveBack()
 // Places the cursor under the back element,
 // Pre:!this.isEmpty(), otherwise does nothing.
  void moveBack(){
 	   if (!this.isEmpty()){
 		   curr = length -1;
 		   currPtr = back;
 	   }
 }





  // movePrev()
  // Moves cursor one step toward
  // Pre: If cursor is defined and not at front of this List, if cursor is defined and at front, cursor becomes
  // undefined, if cursor is undefined does nothing.

  void movePrev(){
		if (index() == 0){
			curr = -1;
			currPtr = null;
		}
		if ((index() != -1) && (length() > 0)){
			curr --;
			currPtr = currPtr.prev;
		}
 }





 // moveNext()
 // Moves cursor one step back
 // Pre: If cursor is defined and not at back of this List, if cursor is defined and at back, cursor becomes
 // undefined, if cursor is undefined does nothing.

  void moveNext(){
 		if (index() == length() -1){
 			curr = -1;
 			currPtr = null;
 		}
 		if ((index() != -1) && (index() < length())){
 			curr ++;
 			currPtr = currPtr.next;
 		}
 }




 // append()
 // Appends data to back of this List.
 void append(E data){
    Node<E> N = new Node<> (data);
    if( this.isEmpty() ) {
       front = back = N;
    }else{
       back.next = N;
       N.prev = back;
       back = N;
    }
    length++;
 }




 // prepend()
 // Prepends data to front of this List.
 // Pre: !isEmpty()
 void prepend(E data){
       Node<E> N = new Node<> (data);
       if( this.isEmpty() ) {
          front = back = N;
       }else{
          front.prev = N;
          N.next = front;
          front = N;
       }
       length++;
       if(index() != -1){
			 curr++;
		 }
 }




 // deleteFront List()
 // Deletes front element from this List.
 // Pre: !this.isEmpty()
 void deleteFront(){
    if(this.isEmpty()){
       throw new RuntimeException(
          "List Error: deleteFront() called on empty List");
    }
    if(this.length>1){
       front = front.next;
       front.prev = null;

    }else{
       front = back = null;

    }
    length--;
    if (index() != -1){
		  curr --;
	  }
 }







 // deleteBack List()
 // Deletes back element from this List.
 // Pre: !this.isEmpty()
    void deleteBack(){
       if(this.isEmpty()){
          throw new RuntimeException(
             "List Error: deleteBack() called on empty List");
       }
       if(this.length>1){
          back = back.prev;
          back.next = null;

       }else{
          front = back = null;

       }
       length--;
       if(index() == length() -1){
			 curr = -1;
		 }

 }





 // delete()
 // Deletes cursor element, making cursor undefined.
 // Pre: length()>0, index()>=0

 void delete(){
	   if(this.isEmpty()){
	               throw new RuntimeException(
	                  "List Error: delete() called on empty List");
       }
     if(index() == -1){
	               throw new RuntimeException(
	                  "List Error: delete() curr is undefined");
       }
     if(index() == 0) {
		   deleteFront();
	     }
	   else if (index() == length() -1){
		   deleteBack();
	   }
	   else  {
		   currPtr.prev.next = currPtr.next;
		   currPtr.next.prev = currPtr.prev;
		   curr = -1;
		   length--;
		   currPtr = null;
	   }


 }






  //insertBefore(int data)
  // Insert new element before cursor.
	// Pre: length()>0, index()>=0
  void insertBefore(E data){
	 if(this.isEmpty()){
	               throw new RuntimeException(
	                  "List Error: insertBefore() called on empty List");
       }
     if(index() == -1){
	               throw new RuntimeException(
	                  "List Error: insertBefore() curr is undefined");
       }

      if (curr == 0){
			prepend(data);
		}
		else{
       Node<E> M = new Node<> (data);
       currPtr.prev.next = M;
       M.prev = currPtr.prev;
       M.next = currPtr;
       currPtr.prev = M;
       length ++;
       curr ++;
	 }

	 }





	  //insertAfter(int data)
	  // Insert new element before cursor.
	  // Pre: length()>0, index()>=0
	   void insertAfter(E data){
	  	 if(this.isEmpty()){
	  	               throw new RuntimeException(
	  	                  "List Error: insertAfter() called on empty List");
	           }
	         if(index() == -1){
	  	               throw new RuntimeException(
	  	                  "List Error: insertAfter() curr is undefined");
	           }

	          if (index() == length() -1){
	  			append(data);
	  		}
	  		else{

	           Node<E> M = new Node<> (data);
	           currPtr.next.prev = M;
	           M.next = currPtr.next;
	           currPtr.next = M;
	           M.prev = currPtr;
  	  	   length ++;
		   }
	 }






 // Other Functions ---------------------------------------------------------



 // toString()
 // Overides Object's toString() method.
 public String toString(){
    StringBuffer sb = new StringBuffer();
    Node<E> N = front;
    while(N!=null){
       sb.append(N.toString());
       sb.append(" ");
       N = N.next;
    }
    return new String(sb);
 }


//copy()
// Returns a new Queue identical to this Queue.
 //public List<E> copy(){
    //List<E> Q = new List<>();
    //Node<E> N = this.front;

    //while( N!=null ){
      // Q.append(N.data);
       ///N = N.next;
    //}
    //return Q;
 //}


}
