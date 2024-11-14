#include<stdio.h>
#include<stdlib.h>
int SIZE;
int top = -1;
int stack[];
void Push(){
    int x;
    printf("Enter the Number\n");
    scanf("%d",&x);
    if(top == SIZE-1){
        printf("OverFlow\n");
        return;
    }
    top++;
    stack[top]=x;
}

void Pop(){
    int popped;
    if(top==-1){
        printf("Underflow\n");
        return;
    }
        popped = stack[top];
        top--;
        printf("%d\n",popped);
} 

void Peak(){
    if(top==-1){
        printf("Empty Stack\n");
        return;
    }
        printf("\n%d is the Element\n",stack[top]);
    
}

void Display() {
    int i;
    for(i = top; i >= 0; i--) { 
        printf("| %d |", stack[i]);
    }
    printf("\n");
}

void isEmpty(){
    if(top==-1){
        printf("Stack is Empty\n");
    }else{
        printf("This Stack is Not Empty\n");
    }
}
int main(){
    printf("\n-Stack Operations-\n");
    printf("\nEnter the Size of the Array: \n");
    scanf("%d", &SIZE);
    int stack[SIZE];

    if(SIZE <=0){
        printf("Invalid Size\n");
        return 1; 
    }
    int choice;
    int j=top;
    while(j<=SIZE-1){
        printf("<--STACK OPERATIONS-->\n");
        printf("\n1.Push\n2.Pop\n3.Peak\n4.Display\n5.Check if the Stack is Empty\n");
        printf("\nEnter your choice: \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                Push();
                j++;
                break;

            case 2:
                Pop();
                break;

            case 3:
                Peak();
                j++;
                break;

            case 4:
                Display();
                break;

            case 5:
                isEmpty();
                break;
            case 6:
                exit(0);
                break;

            default :
                printf("Andha hai kya?\n");
            
        }
    }
    return 0;
}