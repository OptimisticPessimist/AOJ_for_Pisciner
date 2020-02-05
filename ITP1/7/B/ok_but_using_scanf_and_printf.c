/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITP1_7_B_How_Many_ways.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosaka <42tokyo_jan2020_pisciner>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:57:49 by mkosaka           #+#    #+#             */
/*   Updated: 2020/02/05 11:57:49 by mkosaka          ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		combination_sum_equals(int n, int sum)
{
	int count;
	int index[3];

	count = 0;
	index[0] = 1;
	while (index[0] <= n - 2)
	{
		index[1] = index[0] + 1;
		while (index[1] <= n -1)
		{
			index[2] = index[1] + 1;
			while (index[2] <= n)
			{
				if (index[0] + index[1] + index[2] == sum)
					count += 1;
				index[2]++;
			}
			index[1]++;
		}
		index[0]++;
	}
	return (count);
}

void	print_integers(int *integers, int ammounts)
{
	int i;

	i = 0;
	while (i < ammounts)
	{
		printf("%d\n", integers[i]);
		i++;
	}
}

int		main(void)
{
	int *counts;
	int n;
	int x;
	int i;

	counts = (int *)malloc(sizeof(int) * 300);
	i = 0;
	while (1)
	{
		scanf("%d %d", &n, &x);
		if (n == 0 && x == 0)
			break;
		counts[i] = combination_sum_equals(n, x);
		i++;
	}
	print_integers(counts, i);
	return (0);
}
