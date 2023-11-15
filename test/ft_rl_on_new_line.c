/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_on_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:40:44 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/07 16:46:10 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
    char* input = readline("Inserisci una stringa: ");
    printf("Hai inserito: %s\n", input);
    rl_on_new_line();
    free(input);
    return 0;
}
