/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 20:21:43 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/23 20:21:57 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == *s2 && *s1 != '*')
		return (nmatch(s1 + 1, s2 + 1));
	else if (*s2 == '*' && *s1 == '\0')
		return (nmatch(s1, s2 + 1));
	else if (*s1 == '*' && *s2 == '\0')
		return (0);
	else if (*s1 == '*' && *s2 == '*')
		return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2) +
			nmatch(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
	else
		return (0);
}
