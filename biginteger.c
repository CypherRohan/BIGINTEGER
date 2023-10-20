#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"biginteger.h"

struct node *newnode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory is Full!");
        return NULL;
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct node *insert_node(struct node *head, int num) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory is Full.");
        return head;
    }
    temp->data = num;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }

    return head;
}

void display(struct node *head) {
    struct node *itr = head;
    while (itr != NULL) {
        printf(" %d\t", itr->data);
        itr = itr->next;
    }
printf("\n");
}

struct node *arraytolist(char arr[]) {
    int i = 0, num;
    struct node *head = NULL;
    while (i < strlen(arr)-1) {
        if (isdigit(arr[i])){
        num = (int)arr[i] - '0';
        head = insert_node(head, num);}
        i++;
    }
    return head;
}

struct node*reverse(struct node*head)
{
    if(head==NULL)
    {
        return head;
    }
    struct node* current=NULL;
    struct node* forward=head->next;
    head->next=NULL;
    while(forward!=NULL)
    {
        current=forward;
        forward=forward->next;
        current->next=head;
        head=current;
    }
    return head;
}

struct node*push(struct node*head,int val)
{
    struct node*res=(struct node*)malloc(sizeof(struct node));
    res->data=val;
    res->next=head;
    head=res;
    return head;
}

void backnum(struct node*head)
{
    struct node*temp=head;
    //printf("\nsum is:");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

struct node* add(struct node* head1, struct node* head2) {
    struct node* result = NULL;
    int c = 0;

    while (head1 != NULL || head2 != NULL || c != 0) {
        int s=0,c=0;

        if (head1 != NULL) {
            s =s+ head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL) {
            s =s+ head2->data;
            head2 = head2->next;
        }

        c = s / 10;
        s =s% 10;

        result = insert_node(result, s);
    }

    return result;
}


struct node* subtract(struct node* head1, struct node* head2) {
    struct node* itr1 = head1;
    struct node* itr2 = head2;
    struct node* result = NULL;
    struct node* ptr = NULL;
    int borrow = 0;

    if (head2 == NULL)
        return head1;
    if (head1 == NULL) {
        head2->data = -(head2->data);
        return head2;
    }

    while (itr1 != NULL || itr2 != NULL) {
        int num1 = (itr1 != NULL) ? itr1->data : 0;
        int num2 = (itr2 != NULL) ? itr2->data : 0;

        int diff = borrow + num1 - num2;

        if (diff < 0) {
            diff =diff+ 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        struct node* new_node = newnode(diff);
        if (result == NULL) {
            result = new_node;
            ptr = result;
        } else {
            ptr->next = new_node;
            ptr = ptr->next;
        }

        if (itr1 != NULL)
            itr1 = itr1->next;
        if (itr2 != NULL)
            itr2 = itr2->next;
    }

    return reverse(result);
}


void addtwoll(struct node* head1, struct node* resitr) {
    struct node* c1 = head1;
    struct node* c2 = resitr;
    int carry = 0;
    while (c1 != NULL || carry != 0) {
        int sum = carry + (c1 != NULL ? c1->data : 0) + (c2->next != NULL ? c2->next->data : 0);
        int digit = sum % 10;
        carry = sum / 10;

        if (c2->next != NULL) {
            c2->next->data = digit;
        } else {
            c2->next = new_node(digit);
        }

        if (c1 != NULL) {
            c1 = c1->next;
        }
        c2 = c2->next;
    }
}


struct node* mult_LL_with_digit(struct node* head, int digit) {
    struct node* dummy = new_node(0);
    struct node* ac = dummy;
    struct node* curr = head;
    int carry = 0;
    
    while (curr != NULL || carry != 0) {
        int sum = carry + (curr != NULL ? curr->data : 0) * digit;
        carry = sum / 10;
        int digit_sum = sum % 10;
        
        ac->next = new_node(digit_sum);  // Create a new node with digit_sum
        ac = ac->next;  // Move ac to the newly created node
        
        if (curr != NULL) {
            curr = curr->next;
        }
    }
    
    return dummy->next;  // Return the next node of the dummy node, which is the actual result list
}


struct node* multiplytwoLL(struct node* head1, struct node* head2) {
    struct node* L2_itr = head2;
    struct node* dummy = new_node(0);  // Initialize dummy with a new node
    struct node* resitr = dummy;
    
    while (L2_itr != NULL) {
        struct node* prd = mult_LL_with_digit(head1, L2_itr->data);
        L2_itr = L2_itr->next;
        
        addtwoll(prd, resitr);
        resitr = resitr->next;
    }
    
    struct node* result = dummy->next;  // Store the actual result list
    free(dummy);  // Free the dummy node
    return result;  // Return the actual result list
}

