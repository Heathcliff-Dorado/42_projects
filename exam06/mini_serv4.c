#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

fd_set active_fds, read_fds, write_fds;

char	*message_buffer[1025];
char	write_buffer[100];
char	read_buffer[100];
int		fd_to_id[1025];
int		max_fd = 0;
int		id = 0;

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	int	port = atoi(argv[1]);

	FD_ZERO(&active_fds);
	FD_ZERO(&read_fds);
	FD_ZERO(&write_fds);

	int	listener_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listener_fd < 0)
		fatal_error();
	FD_SET(listener_fd, &active_fds);
	max_fd = listener_fd;

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(2130706433);

	if (bind(listener_fd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) != 0)
		fatal_error();
	if (listen(listener_fd, 10) != 0)
		fatal_error();

	while (1)
	{
		read_fds = write_fds = active_fds;
		if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
			fatal_error();
		for (int i = 0; i <= max_fd; i++)
		{
			if (!FD_ISSET(i, &read_fds))
				continue;
			if (i == listener_fd)
			{
				socklen_t addrlen = sizeof(servaddr);
				int new_client_fd = accept(listener_fd, (struct sockaddr *) &servaddr, &addrlen);
				if (new_client_fd > 0)
				{
					handle_new_client(new_client_fd);
					break;
				}
			}
			else
			{
				int read_bytes = recv(i, read_buffer, sizeof(read_buffer), 0);
				if (read_bytes <= 0)
				{
					remove_client(i);
					break ;
				}
				read_buffer[read_bytes] = '\0';
				message_buffer[i] = strjoin(message_buffer[i], read_buffer);
				send_message(i);
			}
		}
	}
	return (0);
}
