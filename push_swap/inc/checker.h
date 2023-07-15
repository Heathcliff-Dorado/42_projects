/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado <hdorado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:42:33 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/15 14:29:53 by hdorado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common_functions.h"

//checker_utils
int		ft_confirmation(t_stack **stack, int elements);
void	ft_rrotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_rrotate(t_stack **stack);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
//checker
int		ft_command(t_stack **stack_a, t_stack **stack_b, char *str);
int		ft_rotate_checker(t_stack **stack_a, t_stack **stack_b, char *str);
void	ft_do_swap(t_stack **stack);
void	ft_do_push(t_stack **donor, t_stack **receiver);

#endif
