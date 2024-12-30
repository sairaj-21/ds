#include <stdio.h>
#include <string.h>
void getInput(char *str, const char *prompt);
int findAndReplace(char *str, const char *pattern, const char *replacement, char *result);

int main()
{
    char str[100], pattern[20], replacement[20], result[120];
    int found;

    getInput(str, "Enter the main string: ");
    getInput(pattern, "Enter the pattern to search: ");
    getInput(replacement, "Enter the replacement string: ");

    found = findAndReplace(str, pattern, replacement, result);

    if (!found)
    {
        printf("Pattern not found in the main string.\n");
    }
    else
    {
        printf("Modified string after replacement: %s\n", result);
    }

    return 0;
}

void getInput(char *str, const char *prompt)
{
    printf("%s", prompt);
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}
int findAndReplace(char *str, const char *pattern, const char *replacement, char *result)
{
    int i, j, k, l, flag, found = 0;
    int strLen = strlen(str);
    int patLen = strlen(pattern);
    int repLen = strlen(replacement);

    for (i = 0; i < strLen; i++)
    {
        flag = 1;

        for (j = 0; j < patLen; j++)
        {
            if (str[i + j] != pattern[j])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            for (j = 0; j < repLen; j++, k++)
            {
                result[k] = replacement[j];
            }
            i += patLen - 1;
            found = 1;
        }
        else
        {
            result[k++] = str[i];
        }
    }

    result[k] = '\0';
    return found;
}
