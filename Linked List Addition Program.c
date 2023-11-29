/* Linked List Programming Task 1 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

// calculateLength ufnction to calculate the length of a string
size_t calculateLength(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// push function to add a new node with a value to the front of the linked list
struct node* push(struct node* head, int val) {
    struct node* newP = (struct node*)malloc(sizeof(struct node));
    
    if (newP == NULL) {
        printf("Memory allocation failed!\n");
        return head; 
    }
    newP->data = val;
    newP->link = head; 
    return newP; 
}

// add function to perform addition of two linked lists
struct node* add(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    int carry = 0, sum;

	// Logic to add two linked lists by iterating through nodes and handling carry
    while (ptr1 || ptr2 || carry) {
        sum = carry + (ptr1 ? ptr1->data : 0) + (ptr2 ? ptr2->data : 0);
        carry = sum / 10;
        sum %= 10;
        head3 = push(head3, sum);
        if (ptr1) ptr1 = ptr1->link;
        if (ptr2) ptr2 = ptr2->link;
    }
    return head3;
} 

// reverseLL function to reverse the linked list
struct node* reverseLL(struct node* head){
    struct node *prev = NULL, *current = head, *next = NULL;
    
    // Logic to reverse the linked list by rearranging pointers
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// strToll fuction to convert a string to a linked list of digits
struct node* strToLL(char* numStr) {
    int len = calculateLength(numStr);
    struct node* head = NULL;
    int i; 
    for (i = len - 1; i >= 0; i--) 
        head = push(head, numStr[i] - '0');
    return head;
}

// displayReverse function to display the elements of a linked list in reverse order
void displayReverse(struct node* head){
    while (head != NULL) {
        printf("%d%s", head->data, head->link ? " <- " : "");
        head = head->link;
    }
}

//Main function 
int main(){
    printf("========== Linked List Addition Program ==========\n\n");
    char numStr1[1000], numStr2[1000];
    printf("Enter the first number: ");
    scanf("%s", numStr1);
    printf("Enter the second number: ");
    scanf("%s", numStr2);

    struct node *head1 = reverseLL(strToLL(numStr1));
    struct node *head2 = reverseLL(strToLL(numStr2));
    struct node *head3 = add(head1, head2);

    printf("--------------------------------------------------");
	printf("\nResultant Linked List After Addition: ");
    displayReverse(head3);
    printf("\n--------------------------------------------------");
    
    return 0;
}

