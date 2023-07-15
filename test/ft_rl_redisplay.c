/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_redisplay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:41:16 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/14 04:41:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* prompt = "Prompt> ";
    char* input = readline(prompt);

    rl_replace_line("Nuova riga di input", 0);
    rl_redisplay();

    free(input);
    return 0;
}
