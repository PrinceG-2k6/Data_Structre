#include<stdio.h> 
#include <stdlib.h>  
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

    while(ptr->top>0)
    {
        printf("%c |",ptr->arr[ptr->top]);
        ptr->top--;
    }
    printf("%c \n",ptr->arr[ptr->top]);
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
int paranthesisMatch(char* exp,int size)
{   
    char popped;
    stack* sp;
    sp->size=size;
    sp->top = -1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    for(int i =0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(sp,exp[i]);
        }
        else if(exp[i]==')'|| exp[i]==']' || exp[i]=='}')
        {   
           
            if(isEmpty(sp))
            {
                return 0;
            }
            popped =  pop(sp);
            if(!match(popped ,exp[i]))
            {
                return 0;
            }
        }
        
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(){
    char* exp = "*8*{[{}](9)}()";
    int size =0;;
    int i =0;
    char c = exp[i];
    while(c!='\0')
    {
        size++;
        i++;
        c= exp[i];
    }
    
    if(paranthesisMatch(exp,size))
    {
        printf("The Paranthesis is matching");
    }
    else
    {
        printf("The Paranthesis is not matching");
    }
    return 0;
}
