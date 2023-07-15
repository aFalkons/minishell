/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgoto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:57:29 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:57:32 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termcap.h>

int main() {
    char termBuffer[2048];
    char* terminalType = "xterm";

    if (tgetent(termBuffer, terminalType) != 1) {
        perror("Errore durante l'ottenimento delle informazioni sul terminale");
        return 1;
    }

    int numColumns = tgetnum("co");
    int numRows = tgetnum("li");

    printf("Numero di colonne: %d\n", numColumns);
    printf("Numero di righe: %d\n", numRows);

    char* clearScreenSequence = tgetstr("cl", NULL);
    char* cursorHomeSequence = tgetstr("ho", NULL);

    printf("Sequenza per cancellare lo schermo: %s\n", clearScreenSequence);
    printf("Sequenza per posizionare il cursore all'inizio: %s\n", cursorHomeSequence);

    return 0;
}
