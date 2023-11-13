#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *ptr;
    uint8_t lenght;
    uint8_t quanlity;
    bool status;
} words;

bool check(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

words *splitstring(char string[], uint8_t size)
{
    words *array = (words *)malloc(sizeof(words) * size);
    uint8_t index = 0;
    uint8_t count = 0;
    array[index].ptr = string;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            array[index].lenght = count;
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
    array[index].lenght = count;
    return array;
}
int sizeStr(char string[])
{
    uint8_t count = 0;
    while (*string != '\0')
    {
        if (*string == ' ')
            count++;
        string++;
    }
    return count + 1;
}

bool compare(const char arr1[], const char arr2[])
{
    uint8_t i = 0;
    while (arr1[i] != ' ')
    {
        if (arr1[i] > arr2[i])
            return true;
        else if (arr1[i] < arr2[i])
            return false;
        i++;
    }
    return false;
}

void prinWords(words array[],uint8_t size)
{   
    for(int i = 0; i<size; i++){
        if(array[i].status == true){
        for( int j =0;j<array[i].lenght; j++){
            printf("%c",array[i].ptr[j]);
            }
        printf("\t xuất hiện %d lần \n",array[i].quanlity);
        }
    }
}
void findName(words array[], uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {      uint8_t count = 0;
        for(int j=0 ;j< size;j++)
        {   uint8_t index=0;
            while(array[i].ptr[index] == array[j].ptr[index]){
            index++;
            if(array[i].lenght==index && array[j].lenght== index){
                count++;
                if(count>=2) array[j].status= false;
                else array[j].status = true;
                break;
                }
            }
            index=0;
        }
        array[i].quanlity = count;
    }
}
int main()
{
   
    char string[] = "mot hai mot hai mot hai ba bon bon ba";
    uint8_t size = sizeStr(string);
    words *array = splitstring(string, size);
    findName(array, size);
    printf("so lan xuat hien mỗi phần tử:\n");
   prinWords(array, size);
    free(array);
}
