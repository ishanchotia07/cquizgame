#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct question
{
    char question[200];
    char opta[20];
    char optb[20];
    char optc[20];
    char optd[20];
    char answer;
} question;
void startquiz(void);
void displayque(question que[], int total, int timelimit);
void playgame(char name[], int difficulty);
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

question medium[5] =
    {
        {"Who invented the C language?",
         "James Gosling",
         "Dennis Ritchie",
         "Bjarne Stroustrup",
         "Ken Thompson",
         'B'},

        {"Which is the correct extension for C files?",
         ".cpp",
         ".java",
         ".c",
         ".py",
         'C'},

        {"How many bits are in one byte?",
         "4",
         "8",
         "16",
         "32",
         'B'},

        {"Which operator gives the remainder?",
         "/",
         "*",
         "%",
         "//",
         'C'},

        {"Which loop executes at least once?",
         "For loop",
         "While loop",
         "Do while",
         "Nested loop",
         'C'}};

question hard[5] =
    {
        {"What is the time complexity of binary search?",
         "O(n)",
         "O(log n)",
         "O(n^2)",
         "O(1)",
         'B'},

        {"Which data structure uses LIFO?",
         "Queue",
         "Tree",
         "Stack",
         "Graph",
         'C'},

        {"What is the value of 2^10?",
         "512",
         "1000",
         "2048",
         "1024",
         'D'},

        {"Which sorting algorithm is stable?",
         "Selection",
         "Bubble",
         "Quick",
         "Heap",
         'B'},

        {"Which is not a programming paradigm?",
         "Procedural",
         "Functional",
         "Object-based",
         "Compilation",
         'D'}};

void startquiz()
{
    char playername[50];
    int difficulty;
    printf("================================\n");
    printf("            start quiz          \n");
    printf("================================\n");
    printf("Enter your name : ");

    scanf(" %49[^\n]", playername);
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

void displayque(question que[], int total, int timelimit)
{
    int i, n;
    int correct = 0;
    int score = 0;
    char ans;
    time_t start, end;
    double time_taken;

    for (i = 0; i < total; i++)
    {
        printf("\n================================\n");
        printf("Question %d/%d\n", i + 1, total);
        printf("================================\n");

        printf("%s\n\n", que[i].question);

        printf("A. %s\n", que[i].opta);
        printf("B. %s\n", que[i].optb);
        printf("C. %s\n", que[i].optc);
        printf("D. %s\n\n", que[i].optd);

        printf("Enter answer: ");

        start = time(NULL);

        if (scanf(" %c", &ans) != 1)
            return;

        end = time(NULL);

        time_taken = difftime(end, start);

        while (getchar() != '\n');

        if (time_taken >= timelimit)
        {
            printf("Time is up! No points awarded.\n");
            continue;
        }

        if (ans >= 'a' && ans <= 'd')
            ans = ans - 32;

        if (ans < 'A' || ans > 'D')
        {
            printf("Invalid answer! No points awarded.\n");
            continue;
        }

        if (que[i].answer == ans)
        {
            printf("Correct answer!\n");
            correct++;
            score += 10;
        }
        else
        {
            printf("Wrong answer!\n");
            printf("Correct answer: %c\n", que[i].answer);
        }
    }

    printf("\nYour score is: %d/%d\n", score, total * 10);
    printf("%.2f percent accuracy\n\n",
           ((float)correct / total) * 100);

    printf("Thanks for playing!\n");
    printf("1. Play again\n0. Return to main menu\n");

    scanf("%d", &n);

    if (n == 1)
        startquiz();
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
    switch (difficulty)
    {
    case 1:
        displayque(easy, 5, 15);
        break;

    case 2:
        displayque(medium, 5, 30);
        break;

    case 3:
        displayque(hard, 5, 60);
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
