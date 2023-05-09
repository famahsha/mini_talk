CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c utils.c
		$(CC) $(CFLAGS) client.c utils.c -o $(CLIENT)
$(SERVER) : server.c utils.c
		$(CC) $(CFLAGS) server.c utils.c -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c utils.c
		$(CC) $(CFLAGS) client_bonus.c utils.c -o $(CLIENT_BONUS)
$(SERVER_BONUS) : server_bonus.c utils.c
		$(CC) $(CFLAGS) server_bonus.c utils.c -o $(SERVER_BONUS)

clean:
	rm -rf $(CLIENT) $(SERVER) 

fclean: 
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus
