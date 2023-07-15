/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:52:17 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/15 04:10:33 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	// Apri il file in modalità scrittura
	int fileDescriptor = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fileDescriptor == -1) {
		perror("Errore durante l'apertura del file");
		return 1;
	}

	// Salva il file descriptor dell'output standard
	int originalStdout = dup(STDOUT_FILENO);

	// Ridireziona l'output standard sul file
	if (dup2(fileDescriptor, STDOUT_FILENO) == -1) {
		perror("Errore durante la ridirezione dell'output");
		close(fileDescriptor);
		return 1;
	}

	// Stampa qualcosa che verrà scritto nel file
	printf("Questo verrà scritto nel file\n");

	// Ripristina l'output standard originale
	if (dup2(originalStdout, STDOUT_FILENO) == -1) {
		perror("Errore durante il ripristino dell'output originale");
		close(fileDescriptor);
		return 1;
	}

	// Chiudi il file
	close(fileDescriptor);

	// Stampa qualcosa che verrà visualizzato sulla console
	printf("Questo verrà visualizzato sulla console\n");

	return 0;
}

