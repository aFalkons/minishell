/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttyname.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:54:20 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:54:22 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    char* tty = ttyname(STDIN_FILENO);
    if (tty != NULL) {
        printf("Nome del terminale: %s\n", tty);
    } else {
        perror("Errore durante l'ottenimento del nome del terminale");
        return 1;
    }

    return 0;
}
