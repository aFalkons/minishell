/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ioctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:54:40 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 05:09:50 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

int main() {
	struct winsize size;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == -1) {
		perror("Errore durante l'ottenimento delle dimensioni del terminale");
		return 1;
	}

	printf("Dimensioni del terminale: %d colonne x %d righe\n", size.ws_col, size.ws_row);

	return 0;
}
