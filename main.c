#include <stdio.h>
#include <string.h>
typedef struct question
{
    char question[200];
    char opta[20];
    char optb[20];
    char optc[20];
    char optd[20];
    char answer;
} question;
question easy[5] =
    {
        {"Which planet is known as the Red Planet?",
         "Earth",
         "Mars",
         "Jupiter",
         "Venus",
         'B'},

        {"How many days are there in a leap year?",
         "364",
         "365",
         "366",
         "367",
         'C'},

        {"Which animal is known as the King of the Jungle?",
         "Tiger",
         "Elephant",
         "Lion",
         "Leopard",
         'C'},

        {"What is the largest ocean in the world?",
         "Atlantic",
         "Indian",
         "Arctic",
         "Pacific",
         'D'},

        {"How many sides does a hexagon have?",
         "Five",
         "Six",
         "Seven",
         "Eight",
         'B'}};
void displayque(question que[], int total)
{
    int i;
    int correct = 0;
    char ans;
    char a,b,c,d,A,B,C,D;
    for (i = 0; i < total; i++)
        
        {
           do {
                

                printf("\n================================\n");
                printf("Question %d/%d\n", i + 1, total);
                printf("================================\n");

                printf("%s\n\n", que[i].question);

                printf("A. %s\n", que[i].opta);
                printf("B. %s\n", que[i].optb);
                printf("C. %s\n", que[i].optc);
                printf("D. %s\n\n", que[i].optd);
                printf("enter answer : ");
                scanf(" %c", &ans);

                if ((ans >= 'a' && ans <= 'd') || (ans >= 'A' && ans <= 'D'))
                {
                    if (ans >= 'a' && ans <= 'z')
                    {
                        ans = ans - 32;
                    }
                    if (que[i].answer == ans)
                    {
                        printf("Correct answer\n");
                        correct++;
                    }
                    else
                    {
                        printf("Wrong answer\n");
                        printf("The correct answer will be : %c\n\n", que[i].answer);
                    }
                }
                else
                {
                    printf("enter a valid choice\n");
                }
            }
           while (ans != 'A' && ans != 'B' && ans != 'C' && ans != 'D');
            
        }
    printf("Your score is : %d/%d\n", correct, total);
    printf("%f percent accuracy\n\n", (float)(correct / total) * 100);
    printf("Thanks for playing\n\n");
}
void playgame(char name[], int difficulty)
{
    printf("================================\n           QUIZ MASTER            \n================================\n\n");

    printf("Player : %s\n", name);
    switch (difficulty)
    {
    case 1:
        printf("Difficulty: Easy\n\n");
        break;

    case 2:
        printf("Difficulty: Medium\n\n");
        break;

    case 3:
        printf("Difficulty: Hard\n\n");
        break;
    }
    {
        printf("================================\n           QUIZ STARTING           \n================================\n\n");
    }
    displayque(easy, 5);
}
void startquiz()
{
    char playername[50];
    int difficulty;
    printf("================================\n");
    printf("            start quiz          \n");
    printf("================================\n");
    printf("Enter your name : ");

    scanf("%s", playername);
    printf("\n");
    printf("Welcome, %s choose difficulty\n\n", playername);
    printf("1. Easy\n2. Medium\n3. Hard\n4. Back to Main Menu\n");
    printf("enter your choice : ");
    scanf("%d", &difficulty);
    switch (difficulty)
    {
    case 1:
        printf("Easy selected\n");
        playgame(playername, difficulty);
        break;
    case 2:
        printf("Medium selected\n");
        playgame(playername, difficulty);
        break;
    case 3:
        printf("Hard selected\n");
        playgame(playername, difficulty);
        break;
    case 4:
        return;

    default:
        printf("Invalid difficulty choice!");
        break;
    }
}

void showinstructions()
{
    int choice;
    printf("================================\n");
    printf("          INSTRUCTIONS          \n");
    printf("================================\n");
    printf("1. Each question has four options.\n2. Select your answer using A, B, C or D.\n3. Each correct answer gives 10 points.\n4. Wrong answers give 0 points.\n5. Your final score will be displayed after completing the quiz.\n\n");
    printf("Enter 0 to go to main menu : ");
    scanf("%d", &choice);

    if (choice == 0)
        return;
}

int main()
{
    int n;

    do
    {
        printf("================================\n");
        printf("          QUIZ MASTER           \n");
        printf("================================\n\n");
        printf("     Welcome to Quiz Master!  \n\n");
        printf("1. Start Quiz\n2. Instructions\n3. Exit\n");

        printf("enter your choice : ");
        scanf("%d", &n);
        printf("\n");
        switch (n)
        {
        case 1:
            startquiz();
            break;

        case 2:
            showinstructions();
            break;
        case 3:
            printf("Thanks for playing\n");
            break;

        default:
            printf("please enter a valid choice");
            break;
        }

    } while (n != 3);

    return 0;
}
