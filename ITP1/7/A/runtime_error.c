/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosaka <42tokyo_jan2020_pisciner>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:22:59 by mkosaka           #+#    #+#             */
/*   Updated: 2020/02/05 14:22:59 by mkosaka          ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void init_chars(char *chars, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		chars[i] = '\0';
		i++;
	}
}

int  ft_atoi(char *str)
{
	int sign;
	int result;
	int i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (('0' <= str[i]) && (str[i] <= '9')))
	{
		result *= 10;
		result += (int)str[i] - '0';
		i++;
	}
	return (sign * result);
}

void split_scores(char *str, int *scores)
{
	int i;
	int digits;
	char buf[4];

	i = 0;
	digits = 0;
	init_chars(buf, 4);
	while (str[i] && str[i] != '\n')
	{
		if (str[i++] == ' ')
		{
			*scores = ft_atoi(buf);
			scores++;
			digits = 0;
			init_chars(buf, 4);
		}
		else
		{
			buf[digits] = str[i - 1];
			digits++;
		}
	}
	*scores = ft_atoi(buf);
	init_chars(str, 10);
}

char grade_tests(int *scores)
{
	if (scores[0] == -1 || scores[1] == -1 || scores[0] + scores[1] < 30)
		return ('F');
	else if (scores[0] + scores[1] >= 80)
		return ('A');
	else if (scores[0] + scores[1] >= 65)
		return ('B');
	else if (scores[0] + scores[1] >= 50)
		return ('C');
	else if ((scores[0] + scores[1] >= 30) && (scores[2] >= 50))
		return ('C');
	return ('D');
}

int  main(void)
{
	char str[11];
	int scores[3];
	char data_set[51];
	int i;

	init_chars(data_set, 51);
	scores[0] = 0;
	scores[1] = 0;
	scores[2] = 0;
	i = 0;
	while (i < 50)
	{
		read(0, str, 10);
		str[10] = '\0';
		split_scores(str, scores);
		if ((scores[0] == -1) && (scores[1] == -1) && (scores[2] == -1))
			break;
		data_set[i] = grade_tests(scores);
		i++;
	}
	i = 0;
	while (data_set[i])
	{
		write(1, &data_set[i++], 1);
		write(1, "\n", 1);
	}
	return (0);
}
