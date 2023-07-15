/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigaddset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:46:58 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:47:00 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);

    pid_t pid = getpid();
    int result = kill(pid, SIGUSR1);
    if (result == -1) {
        perror("Errore durante l'invio del segnale");
        return 1;
    }

    printf("Segnale inviato correttamente.\n");
    return 0;
}
