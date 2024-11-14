#include<stdio.h>
int prefixsum(int a[],int i){
    int sum=0;
    for(int j=0;j<=i;j++){
        sum+=a[j];
    }
    return sum;
}
int main(){
    printf("Enter size of array: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in the array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter index: ");
    int ind;
    scanf("%d", &ind);
    int sum=prefixsum(a,ind);
    printf("Prefix sum till index %d is %d",ind,sum);
}