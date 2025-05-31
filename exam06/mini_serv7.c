#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

fd_set active_fds, write_fds, read_fds;

char *message_buffer[1025];
char write_buffer[100];
char read_buffer[100];
int fd_to_id[1025];
int max_fd = 0;
int id = 0;

void	fatal_error(void){
	write(2, "Fatal error\n", 12);
	exit(1);
}

char	*strjoin(char *buf, char *add)
{
	char *newbuf;
	int	len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf)* (len + strlen(add) + 1));
	if (newbuf == 0);
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return(newbuf);
}

int	extract_message(char **buf, char **msg)
{
	char *newbuf;
	int	i;

	*msg = 0;
	if ((*buf) == 0)
		return 0;
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf)*(strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			(*buf) = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

void	forward_message(int fd, char *message)
{
	for (int client = 0; client <=max_fd; client++)
	{
		if (client != fd && FD_ISSET(client, &write_fds))
			send(client, message, sizeof(message), 0);
	}
}

void	send_message(int fd)
{
	char *message = NULL;
	while(extract_message(&message_buffer[fd], &message))
	{
		sprintf(write_buffer, "client %d: ", fd_to_id[fd]);
		forward_message(fd, write_buffer);
		forward_message(fd, message);
		free(message);
	}
}

void	remove_client(int fd)
{
	FD_CLR(fd, &active_fds);
	close(fd);
	sprintf(write_buffer, "server: client %d just left\n", fd_to_id[fd]);
	forward_message(fd, write_buffer);
	fd_to_id[fd] = -1;
	free(message_buffer[fd]);
	message_buffer[fd] = NULL;
	if (max_fd == fd)
	{
		while( max_fd > 0 && fd_to_id[max_fd] == -1)
			max_fd--;
	}
}

void handle_new_client(int fd) {
	FD_SET(fd, &active_fds);
	fd_to_id[fd] = id++;
	sprintf(write_buffer, "server: client %d just arrived\n", fd_to_id[fd]);
	forward_message(fd, write_buffer);
	if (fd > max_fd)
		max_fd = fd;
}

int main(int argc, char **argv) {
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	int port = atoi(argv[1]);

	FD_ZERO(&active_fds);
	FD_ZERO(&read_fds);
	FD_ZERO(&write_fds);

	int listener_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listener_fd < 0)
		fatal_error();
	max_fd = listener_fd;
	FD_SET(listener_fd, &active_fds);

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
				if (new_client_fd >= 0)
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
					break;
				}
				read_buffer[read_bytes] = 0;
				message_buffer[i] = strjoin(message_buffer[i], read_buffer);
				send_message(i);
			}
		}
	}
	return(0);
}
