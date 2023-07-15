/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:42:24 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:42:29 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* numbers = malloc(5 * sizeof(int));
    int i;
    for (i = 0; i < 5; i++) {
        numbers[i] = i + 1;
    }

    for (i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
    return 0;
}
