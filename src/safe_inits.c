/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:13:23 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/14 20:58:51 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		ft_error_exit("Error: malloc failed\n");
	return (ptr);
}

void	ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	int	ret;

	if (LOCK == opcode)
		pthread_mutex_lock(mutex);
	else if (UNLOCK == opcode)
	{
		ret = pthread_mutex_unlock(mutex);
		if (ret)
			ft_error_exit("Error: pthread_mutex_unlock failed\n");
	}
	else if (INIT == opcode)
	{
		ret = pthread_mutex_init(mutex, NULL);
		if (ret)
			ft_error_exit("Error: pthread_mutex_init failed\n");
	}
	else if (DESTROY == opcode)
	{
		ret = pthread_mutex_destroy(mutex);
		if (ret)
			ft_error_exit("Error: pthread_mutex_destroy failed\n");
	}
}

static void	ft_handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}

void ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		ft_handle_thread_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		ft_handle_thread_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		ft_handle_thread_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		ft_handle_thread_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Error: wrong opcode. it Need: \n
			LOCK, UNLOCK, INIT, DESTROY\n");
}

void	ft_safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		ft_handle_thread_error(pthread_create(thread, NULL, foo, NULL), opcode);
	else if (JOIN == opcode)
		ft_handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		ft_handle_thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("Error: wrong opcode. it Need: \n
			CREATE, JOIN, DETACH\n");	
}
