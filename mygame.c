#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void createMatrix(int arr[][4]);
void showMatrix(int arr[][4]);
int winner(int arr[][4]);
void swap(int *x, int *y);
int readEnteredKey();
int shiftUp(int arr[][4]);
int shiftDown(int arr[][4]);
int shiftRight(int arr[][4]);
int shiftLeft(int arr[][4]);
void gameRule(int arr[][4]);

int main()
{
    int arr[4][4];
    int maxTry = 10;
    char name[20];
    for(int k=0;k<3;k++)
      printf("\n");
    printf("Enter Your  Name:");
    scanf("%s", name);

    system("cls");

    while (1)
    {
        createMatrix(arr);
        gameRule(arr);

        while (!winner(arr))
        {
            system("cls");
            if (!maxTry)
                break;

            printf("\n\n Welcome %s ,Move remainimg : %d\n\n", name, maxTry);

            showMatrix(arr);

            int key = readEnteredKey();

            switch (key)
            {
            case 101:
                
            case 69:
                printf("\a\a\a\a\a\n      Thanks for Playing!    \n\a");
                printf("\nHit  'Enter' to exit the Game  \n");
                key = readEnteredKey();
                return 0;

            case 72:
                if (shiftUp(arr))
                    maxTry--;
                    break;

            case 80:
                if (shiftDown(arr))
                    maxTry--;
                    break;

            case 77:
                if (shiftLeft(arr))
                    maxTry--;
                    break;

            case 75:
                if (shiftRight(arr))
                    maxTry--;
                    break;

            default:

                printf("\n\n      \a\a  Not Allowed     \a\a\a\a");
            }
        }
        if (!maxTry)
            printf("\n\a   YOU LOSE YOUR GAME      \a\a\n");
        else
        {
            printf("\n\a!!!!!!!!!!!!!!!!!!!  CONGRALUATION  !!!!!!!!!!!!!!!!!!!");
            printf("\a                  You have won Game      \a\a\a ");
        }
        fflush(stdin);
        char check;
        printf("\n Want to play again ? \n");
        printf("Enter 'y' to play again: ");
        scanf("%c", &check);
        if (check != 'y' && check != 'Y')
            break;
        maxTry = 10;
    }
    return 0;
}
void createMatrix(int arr[][4])
{
    int n = 15;
    int num[n], i, j;
    for (i = 0; i < 15; i++)
        num[i] = i + 1;

    srand(time(NULL));

    int lastIndex = n - 1, index;

    for (i = 0; i < 4; i++)
    
        for (j = 0; j < 4; j++)
        {
            if (lastIndex >= 0)
            {
                index = rand() % (lastIndex + 1);
                arr[i][j] = num[index];
                num[index] = num[lastIndex--];
            }
        }
    arr[i - 1][j - 1] = 0;
    
}

void showMatrix(int arr[][4])
{
    int i, j;
    printf("----------------------------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
                printf("%2d|", arr[i][j]);
            else
                printf("   | ");
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
}

int winner(int arr[][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
        {
            if (arr[i][j] != k && k != 16)
                break;
        }
        if (j < 4)
            break;
    }
    if (j < 4)
        return 0;
    return 1;
}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
     printf(" ");
}

int readEnteredKey()
{
    char c;
    c = _getch();
    if (c == -32)
          c = _getch();
    return c;
}

int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i == 3)
        return 0;
        swap(&arr[i][j], &arr[i + 1][j]);
        return 1;
}

int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i == 0)
        return 0;
        swap(&arr[i][j], &arr[i - 1][j]);
        return 1;
}

int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j == 0)
        return 0;
    swap(&arr[i][j], &arr[i][j - 1]);
    return 1;
}

int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j == 3)
        return 0;
    swap(&arr[i][j], &arr[i][j + 1]);
    return 1;
}

void gameRule(int arr[][4])
{
    system("cls");

    // int x = readEnteredKey();
    int i, j, k = 1;
    printf("                        PUZZLE GAME                         ");
    printf(" \n\n                     RULE OF THIS GAME                     ");
    printf("\n1.You can move only 1 step at a time by arrow key ");
    printf("\n        Move Up      : by Up arrow key        ");
    printf("\n        Move Down    : by Down arrow key        ");
    printf("\n        Move Left    : by Left Arrow key        ");
    printf("\n        Move Right   : by right arrow key        ");

    printf("\n2.You can move number at empty place only ");
    printf("\n");
    printf("\n3.For each valid move  : your total number of move will decrease by 1 ");
    printf("\n4.Winning situation    : number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n                        winning situation                  \n");

    printf("--------------------------------------\n");
    for (i = 0; i < 4; i++)
    {
          printf("| ");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("%-2d | ", 4 * i + j + 1);
            }
            else
            {
                printf(" | ");
            }
        }
        printf("\n");
    }
    printf("--------------------------------------\n");
    printf("\n5.You can exit game at any time by pressinfg 'E' or 'e' ");

    printf("\nSo try to win in minimum noof move \n");
    printf("\n           Happy gaming , Good Luck\n");

    printf("\nEnter any key to continue......  : ");
    int x = readEnteredKey();
}
