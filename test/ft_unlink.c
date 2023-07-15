/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:50:55 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:51:20 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    if (unlink("file.txt") == -1) {
        perror("Errore durante l'eliminazione del file");
        return 1;
    }

    printf("File eliminato con successo.\n");
    return 0;
}
