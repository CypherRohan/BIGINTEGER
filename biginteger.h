#ifndef BIGINTEGER_H
#define BIGINTEGER_H
struct node *newnode(int);
struct node *insert_node(struct node *, int );
void display(struct node *);
struct node *arraytolist(char );
struct node*reverse(struct node*);
struct node*push(struct node*,int);
void backnum(struct node*);

struct node* add(struct node*, struct node*);
struct node* subtract(struct node* , struct node*);

struct node* new_node(int);

void addtwoll(struct node* , struct node* );
struct node* mult_LL_with_digit(struct node*, int);
struct node* multiplytwoLL(struct node*, struct node*);


#endif