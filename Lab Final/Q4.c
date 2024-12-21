#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000

struct Team {
	int team_id;
	char name[50];
	int t_win;
	int t_loss;
};

void add();
void update();
void print();

int main() {
	int choice;
	
//	printf("=======Team Management System=======\n");
//	printf("1. Add new team\n");
//	printf("2. Update a Team's record\n");
//	printf("3. Print all team's record \n");
//	printf("4. Exit\n");
	
	do {
		
		printf("=======Team Management System=======\n");
		printf("1. Add new team\n");
		printf("2. Update a Team's record\n");
		printf("3. Print all team's record \n");
		printf("4. Exit\n");
			
		printf("\nEnter a choice : ");
		scanf("%d", &choice);
		
		if(choice == 1) {
			add();
		}
		
		else if(choice == 2) {
			update();
		}
		
		else if(choice == 3) {
			print();
		}
		
		else if(choice == 4) {
			printf("Exiting..");
		}
		
		else {
			printf("Invalid Choice.");
		}
		
	} while(choice !=4);
}

void add() {
	FILE *fp = fopen("team.txt", "a");
	if(fp == NULL) {
		printf("Error: cannot open file.");
		exit(1);
	}
	
	struct Team t;
	
	printf("Enter Team ID : ");
	scanf(" %d", &t.team_id);
	
	printf("Enter Team Name : ");
	scanf(" %[^\n]", &t.name);
	
	printf("\n");
	
	fprintf(fp, "%d %d %d %s\n", t.team_id, 0 , 0 , t.name);
	
	fclose(fp);
	
}

void update() {
	FILE *fp = fopen("team.txt", "r");
	if(fp == NULL) {
		printf("Error: cannot open file.");
		exit(1);
	}
	
	struct Team t[max];
	
	int count = 0;
	
	while(fscanf(fp, "%d %d %d %[^\n]", &t[count].team_id, &t[count].t_win, &t[count].t_loss, t[count].name) == 4) {
		count++;
	}
	
	fclose(fp);
	
	int search;
	int search2;
	int i;
	int j;
	int found = 0;
	int found2 = 0;
	int opt;
	int update = 0;
	
	printf("Enter Team ID : ");
	scanf("%d", &search);
	
	for(i = 0 ; i < count ; i++) {
		if(search == t[i].team_id) {
			found = 1;
			printf("\nTeam Found!, Team Name : %s\n",t[i].name);
			
			printf("\nEnter second Team ID with whom they had match : ");
			scanf("%d", &search2);
			
			for(j=0 ; j < count ; j++) {
				
				if(search == search2) {
					printf("Error : Both team entered same.\n\n");
					return;
				}
				
				else if(search2 == t[j].team_id) {
					found2 = 1;
					
					printf("\nTeam 2 Found!, Team Name : %s\n",t[j].name);
					
					printf("Did Team %s win or lose (press 1 for win , 2 for lose) : ",t[i].name);
					scanf("%d", &opt);
					
					if(opt == 1) {
						t[i].t_win++;
						t[j].t_loss++;
						update = 1;
					}
					
					else if(opt == 2) {
						t[j].t_win++;
						t[i].t_loss++;
						update = 1;
					}
					
					else {
						printf("invalid input\n");
						return;
					}
					
				}
			}
			if(!found2){
				printf("Team 2 not found");
			}
			
		}
	}
	
	if(!found) {
		printf("Team not found!");	
	}
	
	printf("\n");
	
	if(update) {
		FILE *fp = fopen("team.txt", "w");
		if(fp == NULL) {
			printf("Error");
			return;
		}
		
		for(i = 0 ; i < count ; i++) {
			fprintf(fp, "%d %d %d %s\n", t[i].team_id, t[i].t_win , t[i].t_loss , t[i].name);
		}
		
		fclose(fp);
		
	}
	
	
}

void print() {
	FILE *fp = fopen("team.txt", "r");
	
	if(fp == NULL) {
		printf("Error: cannot open file.");
		exit(1);
	}
	
	struct Team t[max];
	
	int count = 0;
	int i;
	int total[max];
	int avg[max];
	
	
	while(fscanf(fp, "%d %d %d %[^\n]", &t[count].team_id, &t[count].t_win, &t[count].t_loss, t[count].name) == 4) {
		count++;
	}
	
	fclose(fp);
	
	for(i=0 ; i< count ; i++) {
		
		total[i] = t[i].t_loss + t[i].t_win;
		
		avg[i] = t[i].t_win/total[i];
		
	}
	
	int highest_avg = 0;
	int highest_win = 0;
	
	for(i=0 ; i< count ; i++) {
		
		if(avg[highest_avg]< avg[i]) {
			highest_avg = i;
		}
		
	}
	
	for(i=0 ; i< count ; i++) {
		
		if(t[highest_win].t_win < t[i].t_win) {
			highest_win = i;
		}
		
	}
	
	printf("\nTeam %s has highest wins.\n",t[highest_win].name);
	
	printf("\nTeam %s has highest win percentage.\n\n", t[highest_avg].name );