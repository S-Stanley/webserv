#include "parsing.hpp"

void    clean_servers(server_config *servers)
{
    server_config   *tmp;

    while (servers)
    {
        tmp = servers->next;
        std::cout << servers->server_id << std::endl;
        delete servers;
        servers = tmp;
    }
}

server_config   *create_new_server(unsigned int server_id)
{
    server_config   *new_server = new server_config;

    new_server->next = NULL;
    new_server->server_id = server_id;
    return (new_server);
}

server_config   *push_back_server_config(server_config *lst, unsigned int server_id)
{
    server_config   *tmp = lst;
    server_config   *new_server = create_new_server(server_id);

    if (!tmp)
        return (new_server);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_server;

    return (lst);
}

bool    check_unexpected_token_server(std::string line)
{
    if (line[0] != ' ' && line[1] != ' ')
    {
        return (false);
    }
    if (line[0] == ' ' && line[1] != ' ')
    {
        return (false);
    }
    return (true);
}

server_config    *get_servers(std::string filename)
{
    std::ifstream   fd;
    std::string     line;
    unsigned int    server_id = 0;
    server_config   *servers = NULL;

    fd.open(filename.c_str());
    if (!fd.is_open())
    {
        std::cerr << "Error while opening file" << std::endl;
        exit(1);
    }

    while (getline(fd, line))
    {
        if (strcmp(line.c_str(), "server:") == 0)
        {
            servers = push_back_server_config(servers, server_id);
            server_id++;
        }
        else if (!check_unexpected_token_server(line))
        {
            clean_servers(servers);
            std::cerr << "Unexpected token found while parsing server keyword" << std::endl;
            exit(1);
        }
    }

    fd.close();
    return (servers);
}

bool    verif_servers(server_config *servers)
{
    if (!servers)
    {
        return (false);
    }
    return (true);
}

void    parse_config_file(std::string filename)
{
    server_config   *servers = get_servers(filename);
    if (!verif_servers(servers))
    {
        clean_servers(servers);
        std::cout << "Error on your configuration file" << std::endl;
        exit(1);
    }
    clean_servers(servers);
}