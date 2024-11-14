#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    char gender;
    char designation[50];
    char department[50];
    float basicPay;
    float grossPay;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        
        printf("Name: ");
        scanf("%s", employees[i].name);
        
        printf("Gender (M/F): ");
        scanf(" %c", &employees[i].gender);
        
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        
        printf("Department: ");
        scanf("%s", employees[i].department);
        
        printf("Basic Pay: ");
        scanf("%f", &employees[i].basicPay);
        
        employees[i].grossPay = employees[i].basicPay + (0.25 * employees[i].basicPay) + (0.50 * employees[i].basicPay);
        
        printf("\n");
    }

    printf("\nEmployee Data:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Gender: %c\n", employees[i].gender);
        printf("Designation: %s\n", employees[i].designation);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Pay: %.2f\n", employees[i].basicPay);
        printf("Gross Pay: %.2f\n", employees[i].grossPay);
        printf("\n");
    }

    free(employees);
    
    return 0;
}