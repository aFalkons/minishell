/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:52:17 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:52:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    int fileDescriptor = open("file.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fileDescriptor == -1) {
        perror("Errore durante l'apertura del file");
        return 1;
    }

    int newFileDescriptor = dup(fileDescriptor);
    if (newFileDescriptor == -1) {
        perror("Errore durante la duplicazione del file descriptor");
        close(fileDescriptor);
        return 1;
    }

    printf("File descriptor originale: %d\n", fileDescriptor);
    printf("Nuovo file descriptor: %d\n", newFileDescriptor);

    close(fileDescriptor);
    close(newFileDescriptor);
    return 0;
}
