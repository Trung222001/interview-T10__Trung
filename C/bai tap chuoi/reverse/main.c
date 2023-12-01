#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct
{
    char *ptr;
    uint8_t length;
} words;
words *split(char string[], uint8_t size)
{
    words *array = (words *)malloc(sizeof(words) * size);
    uint8_t count = 0;
    uint8_t index = 0;
    array[index].ptr = string;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            array[index].length = count;
            count = 0;
            string++;
            index++;
            
            array[index].ptr = string;
        }
        else
        {
           count++;
            string++;
        }
    }
    array[index].length = count;
    return array;
}
int sizeStr (char string[]){
    uint8_t count =0;
    while (*string != '\0')
    {   
        if(*string == ' ')
            count ++;
            string++;
        
    }
    return count +1;
    
}

void prinWords(words array[], uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        for (uint8_t j = 0; j < array[i].length; j++)
        {
            printf("%c", array[i].ptr[j]);
        }
        printf(" ");
    }
}

void reverse(words array[], uint8_t size)
{
    for (int i = 0; i < size / 2; i++)
    {
        words temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

int main()
{
    char string[] = " The electronics industry is roughly divided into four major electronics specializations";
    // đảo chuỗi
    char text[]= "electronics";
    uint8_t size = sizeStr(string);
    words* array= split(string,size);
    reverse(array,size);
    prinWords(array,size);
}
