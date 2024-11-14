#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fptr;
    int arr[50];
    fptr= fopen("input.txt","w+");
     if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }
    else{
        int lbound;
        int ubound;
        int count;
        printf("Enter lower bound: ");
        scanf("%d",&lbound);
        printf("Enter upper bound: ");
        scanf("%d",&ubound);
        printf("Enter how many numbers you want to record from file: ");
        scanf("%d",&count);
        for (int i = 0; i < count; i++) {
            int random_number = rand() % (ubound - lbound + 1) + lbound;
            arr[i]=random_number;
            fprintf(fptr,"%d",random_number); 
            fscanf(fptr,"%d",&arr[i]);
            printf("%d\n",arr[i]);
        }
        for(int j=0;j<count;j++){
            for(int k=j+1;k<count;k++){
                if(arr[j]>arr[k]){
                    int temp=arr[j];
                    arr[j]=arr[k];
                    arr[k]=temp;
                }
            }
        }
        int dup=0;
        for(int l=0;l<count-1;l++){
            if(arr[l]==arr[l+1]){
                dup++;
            }
        }
        printf("Total number of duplicates is: %d\n",dup);
        int maxcount = 0; 
        int maxfreq; 
        for (int x = 0; x < count; x++) { 
            int ccount = 0; 
            for (int y = 0; y < count; y++) { 
                if (arr[x]== arr[y]) 
                    ccount++; 
            } 
            if (ccount > maxcount) { 
                maxcount = ccount; 
                maxfreq = arr[x]; 
            } 
        } 
        printf("Most repeating element in the array :%d",maxfreq); 
    return 0;
}
}