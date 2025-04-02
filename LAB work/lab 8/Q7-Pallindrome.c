#include<stdio.h> 
#include <stdlib.h>  
#include <string.h>
typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack * ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack * ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack* ptr , char data)
{
    
    if(isFull(ptr))
    {printf("\n OVERFLOW ! CANNOT ADD DATA\n");}
    else
    {   
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

int pop(stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf(" \n UNDERFLOW! \n");
    }
    else{
        char data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}
int peek(stack* ptr , int i)
{
    int Arrayint = ptr->top-i+1;
    if(Arrayint<0)
    {
        printf("Invalid position");
        return -1;
    }
    else{
        return ptr->arr[Arrayint];
    }
}
void display(struct stack* ptr)
{

    while(ptr->top>=0)
    {
        printf("%c ",ptr->arr[ptr->top]);
        ptr->top--;
    }
}
int match(char a , char b)
{
    if(a=='{' && b=='}')
    {
        return 1;
    }
    else if(a=='[' && b==']')
    {
        return 1;
    }
    else if(a=='(' && b==')')
    {
        return 1;
    }
    else{
        return 0;
    }

}
int Pallindrome(char* exp, int size)
{   
    char popped;
    stack* sp = (stack*)malloc(sizeof(stack)); // Allocate memory for the stack structure
    sp->size = size;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    
    for (int i = 0; i < size; i++)
    {
        push(sp, exp[i]);
    }
    for (int i = 0; i < size; i++)
    {
        popped = pop(sp);
        if(popped!=exp[i])
        {
            return 0;
        }
    }
    
    free(sp->arr); // Free the allocated memory for the array
    free(sp);      // Free the allocated memory for the stack structure
    return 1;
}
int main(){
    char* exp = "*89598*";
    int size =strlen(exp);
    
    if(Pallindrome(exp,size))
    {
        printf("\n[ %s ] Is Pallindrome",exp);
    }
    else
    {
        printf("\n[ %s ] Is Not A Pallindrome",exp);
    }
    return 0;
}
