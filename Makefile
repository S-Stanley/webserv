all:
	c++ client.cpp -o client
	c++ server.cpp -o server
clean:
	rm client server