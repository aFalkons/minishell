/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:43:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 05:10:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
	if (access("file.txt", F_OK) == 0) {
		printf("Il file esiste.\n");
	} else {
		printf("Il file non esiste.\n");
	}
	return 0;
}
