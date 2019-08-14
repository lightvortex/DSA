#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
struct node { 
   int data,key; 
   struct node *next; 
}; 
 
struct node *head = NULL; 
 
void printList() { 
   struct node *ptr = head; 
   printf("\n[ "); 
  
   while(ptr != NULL) { 
      printf("%d,%d ",ptr->key,ptr->data); 
      ptr = ptr->next; 
   } 
  
   printf(" ]"); 
} 
 
void insertFirst(int data) { 
   struct node *new = (struct node*) malloc(sizeof(struct node)); 
  
    
   new->data = data; 

   new->next = head; 

   head = new; 
} 

void deleteFirst() { 

   struct node *temp = head; 
 
   head = head->next; 

   temp->next = NULL; 
   free(temp); 
} 

bool isEmpty() { 
   return head == NULL; 
} 
 
int length() { 
   int length = 0; 
   struct node *current; 
  
   for(current = head; current != NULL; current = current->next) { 
      length++; 
   } 
  
   return length; 
} 
 
struct node* find(int key) { 
 
   int flag = 0;    
 
   struct node* current = head; 
 
   if(head == NULL) { 
      return NULL; 
   } 

   while (current != NULL){ 
 if(current -> data == key){ 
  flag = 1; 
  break; 
 } 
 else 
  current = current ->next;       
    } 
    if (flag == 1) 
 return current; 
    else  
 return NULL; 
} 
 
void insert_last(int key){ 

 struct node *new; 
 new = (struct node*) malloc(sizeof(struct node)); 

 struct node *temp; 
 temp = head; 

 while(temp -> next != NULL) 
  temp = temp ->next; 
 
 temp -> next = new; 
 new -> data = key; 
  
} 
void delete_last(){ 

 struct node *temp; 
 temp = head; 
 
 if(head ->next == NULL) 
  deleteFirst(); 
 else{ 
 
  while(temp -> next ->next != NULL) 
   temp = temp ->next; 
 } 
 struct node *temp2 = temp -> next; 
 temp -> next = NULL; 
 free(temp2); 
} 
void insert_pos(int pos, int key){ 

 struct node *new; 
 new = (struct node*) malloc(sizeof(struct node)); 
 
 struct node *temp; 
 temp = head; 

 int i; 
 for(i = 0; i < pos-1; i++) 
  temp = temp -> next; 
 
 new -> next = temp -> next; 
 temp -> next = new; 
 new -> data = key; 
} 
void delete_pos(int pos){ 
 struct node *temp; 
 temp = head; 
  
 int i; 
 for(i = 0; i < pos-1 && temp->next->next != NULL; i++) 
  temp = temp -> next; 
 struct node *temp2 = temp -> next; 
 temp -> next = temp2 -> next; 
 temp2 -> next = NULL; 
 free(temp2); 
} 
 
 
void sort() { 
 
   int i, j, k, tempData; 
   struct node *temp1; 
   struct node *temp2; 
  
   int size = length(); 
   k = size ; 
  
   for ( i = 0 ; i < size - 1 ; i++, k-- ) { 
      temp1 = head; 
      temp2 = head->next; 
   
      for ( j = 1 ; j < k ; j++ ) {    
 
         if ( temp1->data > temp2->data ) { 
            tempData = temp1->data; 
            temp1->data = temp2->data; 
            temp2->data = tempData; 
 
         } 
    
         temp1 = temp1->next; 
         temp2 = temp2->next; 
      } 
   }    
} 
 
void reverse(struct node** head_ref) { 
   struct node *prev   = NULL; 
   struct node *current = *head_ref; 
   struct node *next; 
  
   while (current != NULL) { 
      next  = current->next; 
      current->next = prev;    
      prev = current; 
      current = next; 
   } 
  
   *head_ref = prev; 
} 
 
void main() { 
    
   
  
  
   printf("\nList after deleting all items: "); 
   printList(); 
   insertFirst(10); 
   insertFirst(20); 
   insert_last(30); 
   insert_last(80); 
   insert_pos(4,40); 
   insert_pos(5,50); 
 
 printf("\n The list is \n");  
   printList(); 
 
   deleteFirst(); 
   delete_pos(3); 
   delete_last(); 
    
   printf("\nNew List: "); 
   printList(); 
   printf("\n");   
 
   insert_last(30); 
   insert_last(80); 
 
   struct node *foundnode = find(4); 
  
   if(foundnode != NULL) { 
      printf("Element found: "); 
      printf("(%d,%d) ",foundnode->key,foundnode->data); 
      printf("\n");   
   } else { 
      printf("Element not found."); 
   } 
 
//   delete(4); 
   printf("List after deleting an item: "); 
   printList(); 
   printf("\n"); 
   foundnode = find(4); 
  
   if(foundnode != NULL) { 
      printf("Element found: "); 
      printf("(%d,%d) ",foundnode->key,foundnode->data); 
      printf("\n"); 
   } else { 
      printf("Element not found."); 
   } 
  
   printf("\n"); 
   sort(); 
  
   printf("List after sorting the data: "); 
   printList(); 
  
   reverse(&head); 
   printf("\nList after reversing the data: "); 
   printList(); 
}