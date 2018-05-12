/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** getnbr
*/

int condit(char const *str, int i, int nb)
{
	while (str[i] <= '9' && str[i] >= '0') {
		nb = nb	+ (str[i] - 48);
		nb = nb	* 10;
		i = i +	1;
	}
	return (nb);
}

int my_getnbr(char const *str)
{
	int minus_count = 0;
	int i = 0;
	int nb = 0;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-') {
			minus_count = minus_count + 1;
		}
		i = i + 1;
	}
	nb = condit(str, i, nb);
	if (nb != 0 && (minus_count % 2) != 0)
		nb = (nb) * (-1);
	nb = nb / 10;
	return (nb);
}

int find_greater(int *array, int size)
{
	int i = 0;
	int greater = array[0];

	while (i <= size) {
		if (array[i] > greater)
			greater = array[i];
		i = i + 1;
	}
	return (greater);
}

int sort_verifier(int *array, int size)
{
	int i = 0;
	int bol = 0;
	int greater = find_greater(array, size);

	while (i < size) {
		if (array[i] <= array[i + 1]) {
			bol = 1;
			i = i + 1;
		} else {
			bol = 0;
			return (bol);
		}
	}
	if (array[i] != greater)
		bol = 0;
	else
		bol = 1;
	return (bol);
}
