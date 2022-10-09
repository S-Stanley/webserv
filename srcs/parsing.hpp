#ifndef PARSING_HPP
# define PARSING_HPP

#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>

#include "../helpers/helpers.hpp"

# define TO_MUCH_SERVER "You have too much server, please delete somes"
# define ERR_OPEN_FILE "Error: can't open config file"
# define ERR_NO_SERVER "Error: there is no server in your configuration file, you need at leat one"

struct route_config {
    std::string             endpoint;
    std::stack<std::string> route_type;
    std::string             folder;
    bool                    directory_listing;
    std::string             file_if_is_repertory;
    std::string             extention_for_cgi;
};

struct server_config {
    unsigned int    server_id;
    unsigned int    body_max;
    route_config    *routes;
    unsigned int    number_or_routes;
    std::string     error_pages;
    std::string     server_name;
    unsigned int    port;
    server_config   *next;
};

void    parse_config_file(std::string filename);

#endif