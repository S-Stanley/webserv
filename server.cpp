#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "poll.h"

#include <iostream>
#include <fstream>

#define PORT 8080

std::string get_file(std::string name)
{
    std::ifstream   fd;
    std::string     to_return;
    std::string     line;

    fd.open(name);
    while (getline(fd, line))
    {

        to_return = to_return + line + '\n';
    }
    return (to_return);
}

void    check_poll(int fd)
{
    struct pollfd pfds[2];

    while (true)
    {
        pfds[0].fd = 0;
        pfds[0].events = POLLIN;
        pfds[0].fd = fd;
        pfds[0].events = POLLIN;
        poll(pfds, 2, -1);
        if (pfds[0].revents & POLLIN){
            break ;
        }
    }
}

int main(int argc, char **argv)
{
    int server_fd, new_socket, valread;

    struct sockaddr_in address;

    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    std::string hello = get_file("http/200") + '\n' + get_file("pages/200.html");

    // check_poll(server_fd);
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // check_poll(server_fd);
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("setcokopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // check_poll(server_fd);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        // check_poll(server_fd);
        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }

        // check_poll(server_fd);
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // check_poll(new_socket);
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);
        check_poll(new_socket);
        send(new_socket, hello.c_str(), strlen(hello.c_str()), 0);
        printf("hello message sent\n");
        check_poll(new_socket);
        close(new_socket);
    }
    return (0);
}
