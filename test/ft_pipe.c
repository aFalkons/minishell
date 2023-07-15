/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:52:48 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:52:50 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Errore durante la creazione della pipe");
        return 1;
    }

    int readEnd = pipefd[0];
    int writeEnd = pipefd[1];

    char buffer[100];
    ssize_t bytesRead;

    if (fork() == 0) {
        // Codice eseguito dal processo figlio
        close(writeEnd);

        bytesRead = read(readEnd, buffer, sizeof(buffer) - 1);
        buffer[bytesRead] = '\0';

        printf("Messaggio ricevuto dal padre: %s\n", buffer);

        close(readEnd);
    } else {
        // Codice eseguito dal processo padre
        close(readEnd);

        char* message = "Ciao, figlio!";
        write(writeEnd, message, strlen(message));

        close(writeEnd);
    }

    return 0;
}
