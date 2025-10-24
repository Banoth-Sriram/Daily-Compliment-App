#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store batsman details
struct Player {
    int playerNo;
    char name[50];
    int runs;
    int balls;
    int fours;
    int sixes;
    struct Player *next; // Pointer to next player (Linked List)
};

// Function to create a new player node
struct Player* createPlayer(int no, char name[], int runs, int balls, int fours, int sixes) {
    struct Player newPlayer = (struct Player)malloc(sizeof(struct Player));
    if (newPlayer == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newPlayer->playerNo = no;
    strcpy(newPlayer->name, name);
    newPlayer->runs = runs;
    newPlayer->balls = balls;
    newPlayer->fours = fours;
    newPlayer->sixes = sixes;
    newPlayer->next = NULL;
    return newPlayer;
}

// Function to insert player at end
struct Player* insertPlayer(struct Player *head, int no, char name[], int runs, int balls, int fours, int sixes) {
    struct Player *newPlayer = createPlayer(no, name, runs, balls, fours, sixes);
    if (head == NULL) {
        return newPlayer;
    }
    struct Player *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newPlayer;
    return head;
}

// Function to display the scoreboard
void displayScoreboard(struct Player *head) {
    int totalRuns = 0, totalBalls = 0;
    printf("\n-----------------------------------------------------\n");
    printf("                   CRICKET SCOREBOARD                \n");
    printf("-----------------------------------------------------\n");
    printf("%-5s %-20s %-5s %-5s %-5s %-5s\n", "No", "Name", "Runs", "Balls", "4s", "6s");
    printf("-----------------------------------------------------\n");

    struct Player *temp = head;
    while (temp != NULL) {
        printf("%-5d %-20s %-5d %-5d %-5d %-5d\n",
               temp->playerNo, temp->name, temp->runs, temp->balls, temp->fours, temp->sixes);
        totalRuns += temp->runs;
        totalBalls += temp->balls;
        temp = temp->next;
    }
    printf("-----------------------------------------------------\n");
    printf("Total Runs: %d\tOvers: %.1f\n", totalRuns, totalBalls / 6.0);
    printf("-----------------------------------------------------\n");
}

int main() {
    struct Player *head = NULL;
    int n, i, no, runs, balls, fours, sixes;
    char name[50];

    printf("Enter number of players: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for player %d\n", i + 1);
        no = i + 1;
        printf("Name: ");
        scanf(" %[^\n]", name);
        printf("Runs: ");
        scanf("%d", &runs);
        printf("Balls faced: ");
        scanf("%d", &balls);
        printf("Fours: ");
        scanf("%d", &fours);
        printf("Sixes: ");
        scanf("%d", &sixes);

        head = insertPlayer(head, no, name, runs, balls, fours, sixes);
    }

    displayScoreboard(head);

    // Free the linked list memory
    struct Player *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}