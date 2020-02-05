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

#include <stdio.h>
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
		scanf("%d %d %d", &scores[0], &scores[1], &scores[2]);
		if (scores[0] == -1 && scores[1] == -1 && scores[2] == -1)
			break;
		data_set[i] = grade_tests(scores);
		i++;
	}
	i = 0;
	while (data_set[i])
		printf("%c\n", data_set[i++]);
	return (0);
}
