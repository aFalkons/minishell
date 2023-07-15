/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:44:16 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:44:17 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor = open("file.txt", O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Errore durante l'apertura del file");
        return 1;
    }

    char buffer[100];
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Errore durante la lettura del file");
        close(fileDescriptor);
        return 1;
    }
    buffer[bytesRead] = '\0';

    printf("Contenuto del file: %s\n", buffer);

    close(fileDescriptor);
    return 0;
}
