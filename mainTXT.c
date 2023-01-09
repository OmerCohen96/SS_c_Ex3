# include <stdio.h>
# include <string.h>
# include "for_isort.h"
# include "for_txtfind.h"

# define LINE 256
# define WORD 30


//printf("%s" , input_word);

int main () {


	char temp[LINE] = {0};
	char input_word[WORD] = {0};
	char choise = 0;
	int i = 0;
	int first_row = 0;

	while ((scanf("%c" , &temp[i]))!=EOF){

		if (temp[i] == ' ' && !first_row)
		{
			strcpy(input_word , temp);
		}
		else if (temp[i-1] == '\n' && temp[i] == '\n' && !first_row)
		{
			int jump = getWord(temp);
			choise = temp[jump+1];

			first_row = 1;
			temp[i-1] = '\0';
			temp[i] = '\0';
			i = -1;
		}
		else if ((temp[i] == '\n' || (temp[i] == '\0')) && first_row){

			temp[i] = 0;

			switch (choise){
				case 'a':
					print_lines(input_word , temp);
					break;
				case 'b':
					print_similar_word(input_word , temp);
					break;	

			}
			i = -1;
		}
		i++;	
	}

	return 0;
}

