/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcgetattr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:56:18 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/07 16:13:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
	struct termios originalAttributes, modifiedAttributes;

	// Salva le impostazioni originali del terminale
	if (tcgetattr(STDIN_FILENO, &originalAttributes) == -1) {
		perror("Errore durante l'ottenimento delle impostazioni del terminale");
		return 1;
	}

	// Copia le impostazioni originali
	modifiedAttributes = originalAttributes;

	// Modifica le impostazioni desiderate
	modifiedAttributes.c_lflag &= ~(ICANON | ECHO);

	// Applica le impostazioni modificate al terminale
	if (tcsetattr(STDIN_FILENO, TCSANOW, &modifiedAttributes) == -1) {
		perror("Errore durante l'applicazione delle impostazioni del terminale");
		return 1;
	}

	// Utilizza il terminale con le impostazioni modificate

	// Ripristina le impostazioni originali del terminale
	if (tcsetattr(STDIN_FILENO, TCSANOW, &originalAttributes) == -1) {
		perror("Errore durante il ripristino delle impostazioni del terminale");
		return 1;
	}

	return 0;
}
