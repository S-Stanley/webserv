# Tips

1. To use HTTP/1.1 or HTTP/1.0 we juste have to send in the response from the server to the client, at least the HTTP version and the response code. E.g `HTTP/1.0 200 OK`
1. We can also specify which http version curl should be used using the flag `--http`, for example `curl --http0.9 localhost:8080`
1. Other curl options to use may be `--verbose` and `-I`, the latter allow to get more info about the request.
1. The server send text (string), it could be a file. For example an HTML file (with requirement about the HTTP request first);