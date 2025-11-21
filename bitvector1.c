#include <stdio.h>
#include <ctype.h>

char uni_set[26] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};

char set1[26], set2[26];
int bit_vec1[26], bit_vec2[26], result[26];

void initializeSet()
{
    for (int i = 0; i < 26; i++) {
        bit_vec1[i] = 0;
        bit_vec2[i] = 0;
        result[i] = 0;
    }
}

void bitVector(char ary[], int bit[], int num)
{
    for (int i = 0; i < num; i++) {
        char c = tolower(ary[i]);
        for (int j = 0; j < 26; j++) {
            if (c == uni_set[j]) {
                bit[j] = 1;
            }
        }
    }
}

void setUnion(int bit1[], int bit2[])
{
    for (int i = 0; i < 26; i++) {
        result[i] = bit1[i] | bit2[i];
    }
}

void setIntersection(int bit1[], int bit2[])
{
    for (int i = 0; i < 26; i++) {
        result[i] = bit1[i] & bit2[i];
    }
}

void setComplement(int bit[])
{
    for (int i = 0; i < 26; i++) {
        result[i] = (bit[i] == 0) ? 1 : 0;
    }
}

void setDifference(int bit1[], int bit2[])
{
    int temp[26];
    for (int i = 0; i < 26; i++)
        temp[i] = (bit2[i] == 0) ? 1 : 0;   // complement

    for (int i = 0; i < 26; i++)
        result[i] = bit1[i] & temp[i];
}

void displaySet(int bit[])   // NEW DISPLAY FUNCTION
{
    printf("{ ");
    for (int i = 0; i < 26; i++) {
        if (bit[i] == 1)
            printf("%c ", uni_set[i]);
    }
    printf("}\n");
}

void displayResult()
{
    printf("Result set: ");
    displaySet(result);
}

int main()
{
    int num1, num2, choice;

    initializeSet();

    printf("Enter number of elements in set1: \n");
    scanf("%d", &num1);
    printf("Enter set1 elements: ");
    for (int i = 0; i < num1; i++)
        scanf(" %c", &set1[i]);

    printf("Enter number of elements in set2: \n");
    scanf("%d", &num2);
    printf("Enter set2 elements: ");
    for (int i = 0; i < num2; i++)
        scanf(" %c", &set2[i]);

    bitVector(set1, bit_vec1, num1);
    bitVector(set2, bit_vec2, num2);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display Set1\n");
        printf("2. Display Set2\n");
        printf("3. Union\n");
        printf("4. Intersection\n");
        printf("5. Complement of Set1\n");
        printf("6. Difference (Set1 - Set2)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Set1: ");
                displaySet(bit_vec1);
                break;
            case 2:
                printf("Set2: ");
                displaySet(bit_vec2);
                break;
            case 3:
                setUnion(bit_vec1, bit_vec2);
                displayResult();
                break;
            case 4:
                setIntersection(bit_vec1, bit_vec2);
                displayResult();
                break;
            case 5:
                setComplement(bit_vec1);
                displayResult();
                break;
            case 6:
                setDifference(bit_vec1, bit_vec2);
                displayResult();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

