
// char a [8] = "+A-C-A+";
// char b [6] = "B+C+B";
// char c [6] = "A-C-A";
// int leng = 200000;
char a [19] = "F-[[A]+A]+F[+FA]-A";
char f [3] = "FF";



#include <string.h>
#include <stdio.h>


int replace(char str [], int i);

int string_builder (char str []) {

   // char str [leng];
   strcpy(str, "A");

   int level;
   printf("Please enter level: ");
   scanf("%d", &level);

   for (int i = 1; i <= level; ++i) {
      int k = 0;
      while (k < strlen(str)) {
	if (str[k] != '-' && str[k] != '+' && str[k] != '[' && str[k] != ']') 
	   k += replace(str, k);
	else 
	   ++k;
      }
      printf("Level %d: %s \n", i, str);
      // printf("String:  %s\n", str);

   }   	
   return 0;
};
int replace(char str [], int i) {
	char temp [strlen(str) + 10];
	int substr_len;
	if (str[i] == 'A') {
	   strcpy(temp, a);
	   substr_len = strlen(a);
	}
	// else if (str[i] == 'F') { 
	//    strcpy(temp, f);
	//    substr_len = strlen(f);
	// } 
	else {
	   strcpy(temp, f);
	   substr_len = strlen(f);
	}
	
	strcat(temp, &str[i+1]);
	strcpy(&str[i], temp);
	
	return substr_len;
};

// int replace(char str [], int i) {
// 	char temp [strlen(str) + 10];
// 	int substr_len;
// 	if (str[i] == 'A') {
// 	   strcpy(temp, a);
// 	   substr_len = strlen(a);
// 	}
// 	else if (str[i] == 'B') { 
// 	   strcpy(temp, b);
// 	   substr_len = strlen(b);
// 	} 
// 	else {
// 	   strcpy(temp, c);
// 	   substr_len = strlen(c);
// 	}
	
// 	strcat(temp, &str[i+1]);
// 	strcpy(&str[i], temp);
	
// 	return substr_len;
// };
