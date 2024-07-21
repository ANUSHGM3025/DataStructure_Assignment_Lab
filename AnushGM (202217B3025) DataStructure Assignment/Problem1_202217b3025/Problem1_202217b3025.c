#include <stdio.h>

#define MAX 10

void create(void);
void insert(void);
void deletion(void);
void search(void);
void display(void);

int b[MAX], n, pos, i;

int main()
{
    int ch;
    char g = 'y';

    do
    {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("\nEnter the correct choice:\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g); // Note the space before %c to consume newline or other whitespace
    }
    while (g == 'y' || g == 'Y');

    return 0;
}

void create(void)
{
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the Elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion(void)
{
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0)
    {
        printf("\nInvalid Location\n");
    }
    else
    {
        for (i = pos; i < n - 1; i++)
        {
            b[i] = b[i + 1];
        }
        n--;

        printf("\nThe Elements after deletion:\n");
        display();
    }
}

void search(void)
{
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &pos);

    for (i = 0; i < n; i++)
    {
        if (b[i] == pos)
        {
            printf("Value %d is in position %d\n", pos, i + 1);
            return; // Exit function after finding the element
        }
    }

    printf("Value %d is not in the list\n", pos);
}

void insert(void)
{
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0)
    {
        printf("\nInvalid Location\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &b[pos]);

        n++;

        printf("\nThe list after insertion:\n");
        display();
    }
}

void display(void)
{
    printf("\nThe Elements of The list ADT are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
