
char a [19] = "F-[[A]+A]+F[+FA]-A";
char f [3] = "FF";

#include <string.h>
#include <stdio.h>


int replace(char str [], int i);

int string_builder (char str []) {

	// setting Axiom
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
   }   	
   return 0;
};

int string_builder_level (char str [], int level) {

   strcpy(str, "A");

   for (int i = 1; i <= level; ++i) {
      int k = 0;
      while (k < strlen(str)) {
	if (str[k] != '-' && str[k] != '+' && str[k] != '[' && str[k] != ']') 
	   k += replace(str, k);
	else 
	   ++k;
      }
      printf("Level %d: %s \n", i, str);
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
	else {
	   strcpy(temp, f);
	   substr_len = strlen(f);
	}
	
	strcat(temp, &str[i+1]);
	strcpy(&str[i], temp);
	
	return substr_len;
};