#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hasLowercase(char x[]) {

	int i,result,point = 0;
	for(i=0;i<strlen(x);i++) {
		result = islower(x[i]);
		if (result > 0) {
			point = 1;
			break;
		}
	}
	return point;
}

int hasUppercase(char x[]) {

	int i, result, point = 0;
	for(i=0;i<strlen(x);i++) {
		result = isupper(x[i]);
		if (result > 0) {
			point = 1;
			break;
		}
	}
	return point;
}

int hasDigit(char x[]) {

	int i, result, point = 0;
	for(i=0;i<strlen(x);i++) {
		result = isdigit(x[i]);
		if (result > 0) {
			point = 1;
			break;
		}
	}
	return point;
}

int hasSpecialChar(char x[]) {

	int i, result, result1, result2, point = 0;
	for(i=0;i<strlen(x);i++) {
		result = isdigit(x[i]);
		result1 = islower(x[i]);
		result2 = isupper(x[i]);
		if (result == 0 && result1 == 0 && result2 == 0) {
			point = 1;
			break;
		}
	}
	return point;
}

int bigLength(char x[]) {
	
	if (strlen(x) >= 12) {
		return 1;
	} else {
		return 0;
	}
}

void evaluateStrength(char x[]) {

	int total = bigLength(x)+hasLowercase(x)+hasUppercase(x)+hasDigit(x)+hasSpecialChar(x);
	if (total <= 2) {
		printf("Password \"%s\" Strength: WEAK\n",x);
		printf("\n");
	} else if (total == 3 || total == 4) {
		printf("Password \"%s\" Strength: MODERATE\n",x);
		printf("\n");
	} else {
		printf("Password \"%s\" Strength: STRONG\n",x);
		printf("\n");
	}
}

int main() {
	
	char password[500];
	char initial[500];
	int choice;
	int count = 1;
	while(1) {
		printf("********** Password Resilience Analyzer **********\n");
		printf("\n");
		printf("Test New Password ------------------> Press 1\n");
		printf("View Strength of Previous Password -> Press 2\n");
		printf("Exit -------------------------------> Press 3\n"); 
		printf("\nEnter Your Choice ------------------> ");
		fflush(stdin);
		scanf("%[^\n]s",initial);
		printf("\n");
		while (isdigit(initial[0]) == 0 || strlen(initial) != 1 || initial[0] - '0' > 3 || initial[0]-'0' < 1) {
			fflush(stdin);
			printf("Incorrect input, try again.\n");
			printf("\n");
			printf("Test New Password ------------------> Press 1\n");  
                	printf("View Strength of Previous Password -> Press 2\n");
                	printf("Exit -------------------------------> Press 3\n");  
                	printf("\nEnter Your Choice ------------------> ");
			scanf("%[^\n]s",initial);
			printf("\n");
		}
		if (initial[0] - '0' == 1) {
			fflush(stdin);
			printf("Enter Password: ");
			scanf("%[^\n]s",password);
			if(strlen(password) >= 8) {
				count = 2;
				evaluateStrength(password);
			} else {
				printf("Password too short, must be at least 8 characters.");	
			}
			printf("\n");
                } else if (initial[0] - '0' == 2) {
			if (count == 1) {
				printf("There is no strength to show as a password has not been entered.\n");
				printf("\n");
			} else {
				evaluateStrength(password);
			}
                } else {
			printf("Exiting.....\n");
			return 0;
                }
	}
}	
