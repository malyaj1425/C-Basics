#include<iostream>
#include<conio.h>
using namespace std;
//FUNCTIONS
/*

string HelloPrt()
{
    cout<<"hello";
}
void passbyaddress(int*ptr)
{
    *ptr=30;
}


//FUNCTION OVERLOADING

void print(int i){
cout<<"Here is int "<<i<<endl;
}
void print(double f){
cout<<"Here is float "<<f<<endl;
}
void print(char *c){
cout<<"Here is char "<<c<<endl;
} //or char const*c

*/

// global variable int x=10;

/*  //POINTER
void geeks(){
int var=20;
int *ptr;
ptr=&var;
cout<<"Value at ptr = "<<ptr<<"\n";
cout<<"Value at var = "<<var<<"\n";
cout<<"value at *ptr = "<<*ptr<<"\n";

}*/
/* //CLASS AND OBJECTS
class Student{
public:
    int id;
    string name;
};
class abc{
int a,b,c;
public:
    void input();
    void dis()
    {
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};
void abc::input()
{
    cin>>a>>b>>c;
}*/
/* //COPY CONSTRUCTOR
class counter{
int c;
public:
    counter(int a){
    c=a;
    }
    counter(counter &ob){
    cout<<"copy const. invoked";
    c=ob.c;
    }
    void show()
    {
        cout<<c;
    }
};*/
/* //DESTRUCTOR
class counter{
int id;
public:
    counter(int i){
    id=i;
    cout<<"const. called of objects with id="<<id;
    }
    ~counter()
    {
        cout<<"destructor called with id="<<id;
    }

    };*/
/* //BINARY SEARCH FUNCTION
int binarySearch(int[],int,int,int);
int binarySearch(int a[],int first,int last,int search_num)
{
    int middle =(first + last)/2;
    if(a[middle] == search_num)
    {
        return middle+1;
    }
    else if(a[middle]<search_num)
    {
        return binarySearch(a,middle+1,last,search_num);
    }
    else
    {
        return binarySearch(a,first,middle-1,search_num);
    }



}*/
/* //BUBBLE SORT
void bubble_sort(int a[],int n){
   int i=0,j=0,tmp;
   for (i = 0; i < n; i++) {
       for (j = 0; j < n - i -1; j++){
           if (a[j] > a[j+1]){
              tmp = a[j];
              a[j]= a[j+1];
              a[j+1]=tmp;
           }
       }
   }
}*/
/* //LINKED LIST
   class Node{
   public:
       int data;
       Node*next;
   } ;
   //traverse
   void printList(Node*n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
   }*/
/* //DOUBLY LINKED LIST
class node{
    public:
        int data;
        node *prev;
        node *next;
};
class Doubly_Linked_List
{
    node *front;
    node *end;
    public: Doubly_Linked_List()
    {
        front =NULL;
        end = NULL;
    }
    void add_front(int);
    void add_after(node*,int);
    void add_before(int,int);
    void add_end(int);
    void delete_node(int);
    void forward_traverse();
    void backward_traverse();
};
void Doubly_Linked_List::add_front(int d)
{
    node *temp;
    temp=new node();
    temp->data =d;
    temp->prev=NULL;
    temp->next=front;
    if(front==NULL)
        end=temp;
    else
        front->prev=temp;
    front=temp;
}
void Doubly_Linked_List::add_end(int d)
{
    node *temp;
    temp=new node();
    temp->data =d;
    temp->prev=end;
    temp->next=NULL;
    if(end==NULL)
        front=temp;
    else
        end->next=temp;
    end=temp;
}

void Doubly_Linked_List::add_before(int pos,int d)
{
    int cnt=1;
    node *ptr;
    ptr=front;
    while(cnt<pos-1)
    {
        ptr=ptr->next;
        cnt++;
    }
    node *temp;
    temp=new node();
    temp->data =d;
    temp->prev=ptr->prev;
    temp->next=ptr;
    ptr->prev=temp;
    if(ptr->prev==NULL)
    front=temp;
}
void Doubly_Linked_List::add_after(node*n,int d)
{
    node *temp;
    temp=new node();
    temp->data =d;
    temp->prev=n;
    temp->next=n->next;
    n->next=temp;
    if(n->next==NULL)
    end=temp;
}
void Doubly_Linked_List::forward_traverse()
{
    node*trav;
    trav=front;
    while(trav!=NULL)
    {
        cout<<trav->data<<endl;
        trav=trav->next;
    }
}
void Doubly_Linked_List::backward_traverse()
{
    node*trav;
    trav=end;
    while(trav!=NULL)
    {
        cout<<trav->data<<endl;
        trav=trav->prev;
    }
}
void Doubly_Linked_List::delete_node(int pos)
{
    int cnt=1;
    node*ptr=front;
    while(cnt!=pos){ptr=ptr->next;cnt++;}
    if(ptr->prev==NULL)
    {
        front=ptr->next;
        front->prev=NULL;
    }
    else if(ptr->next==NULL){
        end=ptr->prev;
        end->next=NULL;
    }
    else
    {
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        delete(ptr);

    }
}*/
/* //CIRCULAR LINKED LIST
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void insert(int newdata) {
   struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
   struct Node *ptr = head;
   newnode->data = newdata;
   newnode->next = head;
   if (head!= NULL) {
      while (ptr->next != head)
      ptr = ptr->next;
      ptr->next = newnode;
   } else
   newnode->next = newnode;
   head = newnode;
}
void display() {
   struct Node* ptr;
   ptr = head;
   do {
      cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
}
void deleteNode(Node**head,int key)
{
    if(*head==NULL)
        return;
    if((*head)->data==key&&(*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
    Node *last=*head,*d;
    if((*head)->data==key)
        while(last->next!=*head)
        last=last->next;
    last->next=(*head)->next;
    free(*head);
    *head=last->next;
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<endl<<"no such keyfound"<<endl;
}*/
/* //CIRCULAR LINKED LIST2
   class Node{
   public:
        int data;
        Node*next;
       };
    void push(Node**head_ref,int data)
    {
        Node*temp=new Node();
        temp->data=data;
        temp->=*head_ref;

        if(*head_ref!=NULL)
        {
            Node*ptr=*head_ref;
            while(ptr->next!=*head_ref)
                ptr=ptr->next;
            ptr->next=temp;
        }
        else
            temp->next=temp;
        *head_ref=temp;
    }
    void printList(Node*head)
    {
        Node*ptr=head;
        if(head!=NULL){
            do{
                cout<<ptr->data<<"";
                ptr=ptr->next;
            }while(ptr!=head);
        }
        cout<<endl;

    }*/
/* //FACTORIAL OF A NUMBER
long fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}*/
/* //PUSH AND POP
int stack[100], n=100, top = -1;
void push(int val){
 if (top>=n-1){
    cout<<"Overflow detected"<<endl;
 }
 else{
    top++;
    stack[top]=val;
 }
}
void pop(){
    if (top<=-1){
        cout<<"underflow"<<endl;
    }
    else{
        top--;
    }
}
void display(){
  for(int i=top;i>=0;i--){
    cout<<stack[i]<<" ";
    cout<<endl;
  }
}*/
/* //QUEUE
class CQQueue{
    int SIZE = 100;
    int front = -1;
    int rear = -1;
    int *array;
    public:
        CQQueue(){
            array = new int[SIZE];
        }

        void enQueue(int data){
            if (rear == SIZE)   // Queue is full
                return;
            if(front == -1 && rear == -1){
                front++;
                rear++;
            }else
                rear++;
            array[rear] = data;
            cout<<data<<" enqueued to queue.\n";
        }

        int deQueue(){
            if (front > rear){
                cout<<"Queue is Empty."<<endl;
                return -1;
            }
            int item = array[front];
            front++;
            cout<<item<<" dequeued from queue.\n";
            return item;
        }
};*/
/* // Queue with Linked List
class QNode {
	public:
	int data;
	QNode* next;

	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};
class Queue {
	public:
	QNode *front, *rear;
	Queue()
	{
		front = rear = NULL;
	}
	bool isempty()
	{
 		if(front == NULL && rear == NULL)
		 	return true;
 		else
 			return false;
	}

void enQueue(int x)
	{
		// Create a new LL node
		QNode* temp = new QNode(x);
		// If queue is empty, then
		// new node is front and rear both
		if (isempty()) {
			front = rear = temp;
			return;
		}
		// Add the new node at
		// the end of queue and change rear
		rear->next = temp;
		rear = temp;
	}
	// Function to remove
	// a key from given queue q
	void deQueue()
	{
		// If queue is empty, return NULL.
		if (isempty())
			return;
		// Store previous front and
		// move front one node ahead
		QNode* temp = front;
		front = front->next;
		// If front becomes NULL, then
		// change rear also as NULL
		if (front == NULL)
			rear = NULL;
		delete (temp);
	}


	void displayQueue()
	{
 		if (isempty())
  			cout<<"Queue is empty\n";
 		else
 		{
  			QNode *ptr = front;
  			while( ptr !=NULL)
  			{
   				cout<<ptr->data<<" ";
   				ptr= ptr->next;
  			}
 		}
	}

void insertFront(int x)
{
	QNode* temp = new QNode(x);	// Create a new LL node
	// If queue is empty, then new node is front and rear both
	if (isempty()) {
		front = rear = temp;
		return;
	}
	// Add the new node at the beginning of queue
	temp->next = front;
	front= temp;
}
void deleteRear()
{
	// If queue is empty, return NULL.
	if (isempty())
		return;

	//if single node
	if(front==rear)
	{
		delete(rear);
		front=rear=NULL;
	}

	// Find the address of node just before the rear
	QNode* temp = front;
	while(temp->next!=rear)
		temp=temp->next;
	delete (rear);
	rear=temp;
}

};*/
/* //DeQueue with Array */
#define SIZE 10
class dequeue {
   int a[20],f,r;
   public:
      dequeue();
      void insert_at_beg(int);
      void insert_at_end(int);
      void delete_fr_front();
      void delete_fr_rear();
      void show();
};
dequeue::dequeue() {
   f=-1;
   r=-1;
}
void dequeue::insert_at_end(int i) {
   if(r>=SIZE-1) {
      cout<<"\n insertion is not possible, overflow!!!!";
   } else {
      if(f==-1) {
         f++;
         r++;
      } else {
         r=r+1;
      }
      a[r]=i;
      cout<<"\nInserted item is"<<a[r];
   }
}
void dequeue::insert_at_beg(int i) {
   if(f==-1) {
      f=0;
      a[++r]=i;
      cout<<"\n inserted element is:"<<i;
   } else if(f!=0) {
      a[--f]=i;
      cout<<"\n inserted element is:"<<i;
   } else {
      cout<<"\n insertion is not possible, overflow!!!";
   }
}
void dequeue::delete_fr_front() {
   if(f==-1) {
      cout<<"deletion is not possible::dequeue is empty";
      return;
   }
   else {
      cout<<"the deleted element is:"<<a[f];
      if(f==r) {
         f=r=-1;
         return;
      } else
         f=f+1;
      }
   }
   void dequeue::delete_fr_rear() {
      if(f==-1) {
         cout<<"deletion is not possible::dequeue is empty";
         return;
      }
      else {
         cout<<"the deleted element is:"<<a[r];
         if(f==r) {
            f=r=-1;
         } else
            r=r-1;
      }
   }
   void dequeue::show() {
      if(f==-1) {
         cout<<"Dequeue is empty";
      } else {
         for(int i=f;i<=r;i++) {
            cout<<a[i]<<" ";
         }
      }
   }


main()
{

    //TOPICS COVERED

/* //LARGEST OF 3 NO.
    int a,b,c;
    cout<<"Input 3 values for a, b and c"<<endl;
    cin>>a>>b>>c;
    if(a >= b && a >= c)
    {
        cout<<endl<<"a is the greatest no.";
    }
    else if(b >= a && b >= c)
    {
        cout<<endl<<"b is the greatest no.";
    }
    else
    {
        cout<<endl<<"c is the greatest no.";
    }
    getch();
    return 0;*/


/*    //SWITCH CASE BREAK AND DEFAULT

    int day = 3;
    switch(day)
    {
    case 1:
        cout<<"Monday";
        break;
    case 2:
        cout<<"Tuesday";
        break;

    case 3:
        cout<<"Wednesday";
        break;

    case 4:
        cout<<"Thursday";
        break;

    case 5:
        cout<<"Friday";
        break;


    case 6:
        cout<<"Saturday";
        break;

    case 7:
        cout<<"Sunday";
        break;

    default:
        cout<<"Invalid";
        break;
    }
*/

/*    //LOOPING (ENTRY AND EXIT)

    int i;
    for(i=0;i<=10;i++)// for reverse i=10 and i-- and i>=0
        {
        cout<<i<<endl;

    }

*/
/*    //WHILE LOOP

    int i=1;
    while(i<6)
    {
        cout<<"yo\n";
        i++;
    }
*/

/*    //Printing multiplication with for loop

    int n;
    int i;
    int table;
    cin>>n;
    for(i=1;i<10;i++)
    {
        table=n*i;
        cout<<table<<"\n";

    }
*/

/*    //DO WHILE LOOP

    int i=2;
    do
    {
        cout<<"Hello\n";
        i++;
    }while(i<1);
    return 0;
*/

/*    //BREAK AND CONTINUE

    for(int i=1;i<=10;i++)
    {
        if(i==6)
            continue;
        else
            cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=10;i++)
    {
        if(i==6)
            break;
        else
            cout<<i<<" ";
    }
*/
/*    //FUNCTIONS

    HelloPrt(); //func. declared out of main
*/
/*    //PASS BY VALUE AND ADDRESS

    int x=20;
    passbyaddress(&x);*/

/*    //GLOBAL VARIABLE


*/
/*    //SCOPE RESOLUTION OPERATOR ::

    int x=0;
    cout<<::x;

*/
/*    //FUNCTION OVERLOADING

    print(10);
    print(10.6);
    print("I")

    return 0;
*/

/*    //POINTER

    geeks();
    ;
    */

/*    //POINTER EXPS AND POINTER ARITHMATIC
*/

/*    //POINTER TO POINTER

      char a;
      char *b;
      char **c;
      a='g';
      b=&a;
      c=&b;
      cout<<a<<endl<<b<<endl<<c;*/

/*    //CLASSES AND OBJECTS
      Student s1;
      s1.id=1425;
      s1.name="Malyaj";
      cout<<s1.id<<endl;
      cout<<s1.name<<endl;
      return 0;
      abc ob;
      ob.input();
      ob.dis();
      return 0;*/

/*    //COPY COUNTER
          counter C1(10);
          counter C2(C1);
          C1.show();
          C2.show();
          return 0;*/
/*    //DESTRUCTOR
      counter c1(1);
      counter c2(2);
      counter c3(3);
      cout<<"\n end of main";*/
/*    //ARRAY
      int arr[10]={72,43,88,65,33,12,25,76,98,45};
      for(int i;i<10;i++){
        cout<<arr[i]<<endl;
      }
      //SUM OF ARRAY

      int n=10, sum=0;
      for (int i=0;i<n;i++){
            sum+=arr[i];
      }
      cout<<sum<<endl;
      //INSERT ELEMENT IN ARRAY AT FIRST POSITION
      int arr[50], i, element, x, y;
    cout<<" Size for Array: ";
    cin>>y;
    cout<<"Enter "<<y<<" Elements: ";
    for(i=0; i<y; i++)
        cin>>arr[i];
    cout<<"\n Insert: ";
    cin>>element;
    cout<<"Position";
    cin>>x;
    for(i=y; i>=x; i--)
        arr[i] = arr[i-1];
        arr[i] = element;
    y++;
    cout<<"\nresult: \n";
    for(i=0; i<y; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;*/

/* // Garbage Value
    cout<<"if index more than element in an array then";
    int ar[5]={1,2,3,4,5};
    cout<<ar[6];*/

/* //DELETE AN ARRAY ELEMENT
*/

/* //BINARY SEARCH
   int num[10]={10,22,37,55,92,118};
   int search_num, loc=-1;
   cout<<"Enter number u wanna search Playah";
   cin>>search_num;
   loc=binarySearch(num,0,6,search_num);
   if(loc != -1)
   {
       cout<<search_num<<"found at"<<loc;
   }
   else
   {
       cout<<"Element not found";
   }
   return 0;*/
/* //BUBBLE SORT
   int a[10],n,i,d,swap;
   cout<<"enter no. of elements in a array"<<endl;
   cin>>n;
   cout<<"enter data"<<endl;
   for (i=0;i<n;i++)
    cin>>a[i];
   bubble_sort(a,n);
   cout<<"sorted list is: "<<endl;
   for (i=0;i<n;i++)
    cout<<a[i]<<endl;
   return 0;*/
/* //LINKED LIST
   Node*h=NULL;
   Node*s=NULL;
   Node*t=NULL;

   h=new Node();
   s= new Node();
   t= new Node();

   h->data=1;
   h->next=s;

   s->data=2;
   s->next=t;

   t->data=3;
   t->next=NULL;
   //to traverse
   printList(h);
   cout<<"\n";
   printList(s);
   cout<<"\n";
   printList(t);
   return 0;*/

/* //DOUBLY LINKED LIST
   Doubly_Linked_List obj;
   obj.add_front(4);
   obj.add_front(5);
   obj.add_end(7);
cout<<"Forward Traverse"<<endl;
   obj.forward_traverse();
cout<<"Backward Traverse with 2nd node deleted and adding new one"<<endl;

   obj.delete_node(2);
   obj.add_before(0,6);
   obj.backward_traverse();
   return 0;*/
/* //CIRCULAR LINKED LIST
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The circular linked list is: "<<endl;
   display();
   deleteNode(&head,3);
   cout<<"The circular linked list after deletion: "<<endl;
   display();
   return 0;*/

/* //PUSH POP
push(13);
push(14);
display();
pop();
display();*/
/* //factorial of a number
int a;
long f;
cin>>a;
f=fact(a);
cout<<"factorial of"<<a<<" is"<<f;*/
/* //QUEUE
CQQueue ob1;
    ob1.enQueue(10);
    ob1.enQueue(20);
    ob1.enQueue(30);
    ob1.enQueue(40);

    ob1.deQueue();
    ob1.deQueue();
    ob1.deQueue();
    ob1.deQueue();
    ob1.deQueue();

    ob1.enQueue(50);
   return 0;*/
/* //Queue with Linked List
    Queue q;
	q.displayQueue();
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	q.displayQueue();
	std::cout<<std::endl;
	q.insertFront(65);
	q.displayQueue();*/
/* //DeQueue with Array*/
int c,i;
      dequeue d;
      do//perform switch opeartion
      {
      cout<<"\n 1.insert at beginning";
      cout<<"\n 2.insert at end";
      cout<<"\n 3.show";
      cout<<"\n 4.deletion from front";
      cout<<"\n 5.deletion from rear";
      cout<<"\n 6.exit";
      cout<<"\n enter your choice:";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"enter the element to be inserted";
            cin>>i;
            d.insert_at_beg(i);
         break;
         case 2:
            cout<<"enter the element to be inserted";
            cin>>i;
            d.insert_at_end(i);
         break;
         case 3:
            d.show();
         break;
         case 4:
            d.delete_fr_front();
         break;
         case 5:
            d.delete_fr_rear();
         break;
         case 6:
            exit(1);
         break;
         default:
            cout<<"invalid choice";
         break;
      }
   } while(c!=7);

}
