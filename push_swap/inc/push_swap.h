/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdorado- <hdorado-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:47:09 by hdorado-          #+#    #+#             */
/*   Updated: 2023/07/17 13:07:27 by hdorado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common_functions.h"

//push_swap_utils
void	ft_rotate_overlap(t_stack **s_1, t_stack **s_2, int index, int min);
void	ft_prepare_push(t_stack **s_1, t_stack **s_2, int index, int min);
void	ft_movenumber(t_stack **s_1, t_stack **s_2, t_stack **max, int el_b);
void	ft_s_r(t_stack **stack);
void	ft_s_rr(t_stack **stack);
//push_swap_utils_2
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **donor, t_stack **receiver, char c);
void	ft_rrx(t_stack **stack_a, t_stack **stack_b, int n);
void	ft_rx(t_stack **stack_a, t_stack **stack_b, int n);
void	ft_rr(t_stack **stack, int n, char c);
//push_swap_utils_3
void	ft_r(t_stack **stack, int n, char c);
void	ft_new_max(t_stack **stack, t_stack **max, int elem_in_b);
int		ft_max(int moves, int counter);
int		ft_elem_in_b(t_stack **stack);
int		ft_get_min_moves(t_stack **stack, t_stack **max, int value);
//push_swap_utils_4
int		ft_get_value(t_stack **stack, int index);
int		ft_cm_next(t_stack **s_2, t_stack **s_1, t_stack **max, int index);
int		ft_cm_pr(t_stack **s_2, t_stack **s_1, t_stack **max, int counter);
int		ft_check_down(t_stack **stack, int value, int index);
int		ft_check_up(t_stack **stack, int value, int index);
//push_swap_utils_5
int		ft_overlap_equal(int index, t_stack **stack_2, int value);
int		ft_find_overlap(t_stack **stack_2, int value, int index, int min);
void	ft_rotate_no_overlap(int index, t_stack **s_1, t_stack **s_2, int min);
void	ft_special_condition(t_stack **stack);
void	ft_organize_3(t_stack **stack, int elm);
//push_swap
void	ft_final_sort(t_stack **stack_2, t_stack **max);
void	ft_pushswap_large(t_stack **s_1, t_stack **s_2, t_stack **max, int el);
void	ft_push_swap(t_stack **s_1, t_stack **s_2, int el);

#endif
