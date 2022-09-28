/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:45:22 by tamchoor          #+#    #+#             */
/*   Updated: 2022/07/20 11:32:59 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse_map.h"

int	strarr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	is_player_ch(char ch)
{
	if (ch == 'N' || \
			ch == 'S' || \
			ch == 'E' || \
			ch == 'W')
		return (1);
	else
		return (0);
}

int	is_allowed_ch(char ch)
{
	if (ch == ' ' || \
			ch == '1' || \
			ch == '0' || \
			ch == 'C' || \
			ch == 'M' || \
			ch == 'D' || \
			ch == 'N' || \
			ch == 'S' || \
			ch == 'E' || \
			ch == 'W')
		return (VALID_OK);
	else
		return (VALID_ERR);
}

char	get_ch_in_dot(int x, int y, char **map)
{
	if (map && y < strarr_len(map) && y >= 0 && \
				x < (int)ft_strlen(map[y]) && x >= 0)
		return (map[y][x]);
	else
		return (0);
}
