#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
int cmp(const void *a, const void *b)
{
    const char *name1 = a;
    const char *name2 = b;
    int i = 0;
    while (name1[i] == name2[i] &&
           name1[i] != '\0' &&
           name2[i] != '\0')
    {
        i++;
    }
 
    if (name1[i] < name2[i])
        return -1;
 
    if (name1[i] > name2[i])
        return 1;
 
    return 0;
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    char (*name)[61] = malloc(n * sizeof(*name));
 
    if (name == NULL)
        return 1;
 
    for (int i = 0; i < n; i++)
    {
        scanf(" %60[^\n]", name[i]);
 
        int j = 0;
        while (name[i][j] != '\0')
        {
            if (j == 0 || name[i][j - 1] == ' ')
            {
                name[i][j] = toupper((unsigned char)name[i][j]);
            }
            else
            {
                name[i][j] = tolower((unsigned char)name[i][j]);
            }
            j++;
        }
    }
    qsort(name, n, sizeof(*name), cmp);
 
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", name[i]);
    }
    free(name);
 
    return 0;
}