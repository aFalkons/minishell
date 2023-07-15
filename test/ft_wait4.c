/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:45:51 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:45:53 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid = fork();
    if (childPid == 0) {
        // Codice eseguito dal processo figlio
        printf("Sono il processo figlio.\n");
        sleep(2);
        printf("Processo figlio terminato.\n");
    } else if (childPid > 0) {
        // Codice eseguito dal processo padre
        printf("Sono il processo padre. PID del figlio: %d\n", childPid);
        int status;
        waitpid(childPid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Il figlio è terminato normalmente con codice di uscita: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Il figlio è stato terminato da un segnale: %d\n", WTERMSIG(status));
        }
        printf("Processo figlio terminato.\n");
    } else {
        perror("Errore durante la creazione del processo");
        return 1;
    }
    return 0;
}
