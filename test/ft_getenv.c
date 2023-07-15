/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:55:23 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 05:07:53 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char* home = getenv("HOME");
	if (home != NULL) {
		printf("La directory home dell'utente è: %s\n", home);
	} else {
		printf("Variabile di ambiente HOME non trovata.\n");
	}

	return 0;
}
