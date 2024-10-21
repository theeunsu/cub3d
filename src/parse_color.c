/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:08:08 by eahn              #+#    #+#             */
/*   Updated: 2024/10/21 16:10:59 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_rgb(char **line)
{
	int	rgb;
	int	comma;

	while (ft_isspace(**line))
		(*line)++;
	if (!ft_isdigit(**line))
		print_error("Invalid RGB value. Missing or incorrect value.\n");
	rgb = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	comma = 0;
	while (ft_isspace(**line) || **line == ',')
	{
		if (**line == ',')
		{
			if (comma)
				print_error("Invalid RGB value. Multiple commas.\n");
			comma = 1;
		}
		(*line)++;
	}
	if (!ft_isdigit(**line) && **line != '\0')
		print_error("Invalid RGB value. Missing or incorrect value.\n");
	return (rgb);
}

static void	assign_color(int *color, int r, int g, int b, char *str)
{
	if (*color != -1)
		print_error(str);
	*color = (r << 16 | g << 8 | b);
}

void	parse_color(t_map *map, char *line, char type)
{
	int	r;
	int	g;
	int	b;

	line += 2;
	while (ft_isspace(*line))
		line++;
	r = extract_rgb(&line);
	g = extract_rgb(&line);
	b = extract_rgb(&line);
	if (!(r >= 0 && r <= 255) || !(g >= 0 && g <= 255) || !(b >= 0 && b <= 255))
		print_error("RGB values must be between 0 ad 255.\n");
	if (type == 'F')
		assign_color(&map->f_color, r, g, b, "Floor color already set.\n");
	else if (type == 'C')
		assign_color(&map->c_color, r, g, b, "Ceiling color already set.\n");
	else
		print_error("Invalid color type.\n");
	printf("f_color: %d, c_color: %d\n", map->f_color, map->c_color);
}
