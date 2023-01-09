#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
char tempArr[WORD];

int getLine(char *str)
{

    char *c = str;
    int counter = 0;

    while (*c && *c != '\n' && *c != '\r' && counter < LINE)
    {
        counter++;
        c++;
    }

    return counter;
}

int getWord(char *w)
{

    int i = 0;

    // while (*w == ' ')
    // {
    //     w++;
    // }

    while (*(w + i) && *(w + i) != ' ' && *(w + i) != '\n' && *(w + i) != '\r' && *(w + i) != '\t' && i <= WORD)
    {

        i++;
    }

    return i;
}

int substring(char *s1, char *s2)
{

    int s1_len = getWord(s1), s2_len = getWord(s2);

    if (s1_len >= s2_len)
    {

        int size = s1_len - s2_len + 1;

        for (int i = 0; i < size; i++)
        {

            int j = 0, is_sub = 0;

            if (*(s1 + i) == *(s2))
            {

                is_sub = 1;

                while (j < s2_len && is_sub)
                {

                    is_sub = *(s1 + i + j) == *(s2 + j);

                    j++;
                }

                if (is_sub)
                {

                    return 1;
                }
            }
        }
    }

    return 0;
}

// check if s2[] is similar to s1[]
// or if s2[] similar to s1[] if removing 1 char from s2

int similar(char *s1, char *s2)
{

    int s1_len = getWord(s1), s2_len = getWord(s2);

    if (s1_len == s2_len)
    {
        return substring(s1, s2);
    }

    else if ((s1_len + 1) == s2_len)
    {

        int is_sub = 0;

        for (int i = 0; i < s2_len; i++)
        {
            int j = 0, k = 0;

            while (j < s1_len)
            {
                if (k == i)
                {
                    k++;
                }

                *(tempArr + j) = *(s2 + k);

                j++;
                k++;
            }

            is_sub = substring(s1, tempArr);

            if (is_sub)
            {

                return 1;
            }
        }
    }
    return 0;
}

void print_the_line(char *str)
{
    int i = 0;
    char temp[LINE] = {0};

    while (*(str + i) != '\n' && *(str + i) != '\0' && i < LINE)
    {
        temp[i] = *(str + i);
        i++;
    }

    temp[i] = 0;

    puts(temp);
}

void print_lines(char *input_word, char *line)
{

    int input_word_len = getWord(input_word);

    int i = 0, jump = 0;

    while (*(line + i) != '\n' && *(line + i) != '\0' && i < LINE)
    {
        while (*(line + i) == ' ')
            i++;

        jump = getWord((line + i));

        if (input_word_len <= jump)
        {

            int toPrint = 0;
            toPrint = substring((line + i), input_word);

            if (toPrint)
            {
                puts(line);
                return;
            }
        }
        i += jump;
    }
}

void print_word(char *str, int num)
{
    char temp[WORD];

    for (int i = 0; i < num; i++)
    {
        temp[i] = *(str + i);
    }
    temp[num] = 0; //

    puts(temp);
}

void print_similar_word(char *input_word, char *line)
{

    int i = 0, jmp = 0,  is_similar = 0;

    while (*(line + i) != '\n' && *(line + i) != '\0' && i < LINE)
    {

        while (*(line + i) == ' ')
        {
            i++;
        }

        
        jmp = getWord((line + i));

        is_similar = similar(input_word, (line + i));

        if (is_similar)
        {
            print_word((line + i), jmp);
        }

        i += jmp;
    }
}
