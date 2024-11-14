#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("Enter the no. of inputs: ");
    scanf("%d", &n);
    int a[n];
    int largest=0;
    int smallest= a[0];
    int slargest=-1;
    int ssmallest= INT_MAX;
    
    printf("Enter the numbers : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>slargest){
            slargest=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]!=smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }
    }
    printf("The second smallest number is: %d",ssmallest);
    printf("The second largest number is: %d",slargest);
    return 0;
}