/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:53:58 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:54:00 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Errore durante l'apertura del file");
        printf("Errore: %s\n", strerror(errno));
        return 1;
    }

    // ... Operazioni sul file ...

    fclose(file);
    return 0;
}
