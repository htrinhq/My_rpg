/*
** EPITECH PROJECT, 2017
** utilities.c
** File description:
** basic string functions
*/

#include "rpg.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
        int i = 0;

        n = n - 1;
        while (s1[i] == s2[i] && s1[i] && s2[i] && i < n) {
                i = i + 1;
        }
        if (i == n && s1[i] == s2[i])
                return (1);
        return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
        int i = 0;

        while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
                i = i + 1;
        }
        if (s1[i] == '\0' && s2[i] == '\0')
                return (1);
        return (0);
}

int check_env(char **envp)
{
	int i = 0;
	char dsp = 0;

	if (envp == NULL)
		return (84);
	for (i = 0; envp[i]; i = i + 1)
		if (my_strncmp(envp[i], "DISPLAY", 7) == 1)
			dsp = 1;
	if (dsp == 0)
		return (84);
	return (0);
}
