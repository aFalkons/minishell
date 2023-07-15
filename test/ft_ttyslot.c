/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttyslot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:54:29 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:54:30 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main() {
    int slot = ttyslot();
    if (slot == -1) {
        perror("Errore durante l'ottenimento del numero di terminale");
        return 1;
    }

    printf("Numero di terminale: %d\n", slot);

    return 0;
}
