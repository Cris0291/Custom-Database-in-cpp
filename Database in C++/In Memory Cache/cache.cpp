#include "cache.h"
#include <winsock2.h>
#include <stdexcept>
#include <iostream>

using namespace std;

void mainloop(int s) {
	struct sockaddr_in cli;
	int len{};
	SOCKET s2{};
	char* ip{};
	int16 port{};

	s2 = (accept(s, (struct sockaddr*)&cli, &len));
	if (s2 == INVALID_SOCKET) {
		return;
	}

	port = (int16)htons((int)cli.sin_port);
	ip = inet_ntoa(cli.sin_addr);
}

int initserver(int16 port)
{
	struct sockaddr_in sock;
	SOCKET s{};

	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
	sock.sin_addr.s_addr = inet_addr(HOST);

	s = socket(AF_INET, SOCK_STREAM, 0);
	assert(s != INVALID_SOCKET);

	
	if (bind(s, (struct sockaddr*)&sock, sizeof(sock))) throw invalid_argument{ "Something unexpected happened" };

	if (listen(s, 20) == SOCKET_ERROR) throw invalid_argument{ "Something unexpected happened" };

	cout << "Server listening on" << HOST << port << endl;

	return s;
};
