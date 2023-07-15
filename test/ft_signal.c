/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:46:22 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:46:24 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal) {
    printf("Ricevuto segnale: %d\n", signal);
}

int main() {
    signal(SIGINT, signalHandler);

    printf("Il programma è in esecuzione. Premi CTRL+C per inviare un segnale SIGINT.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}
