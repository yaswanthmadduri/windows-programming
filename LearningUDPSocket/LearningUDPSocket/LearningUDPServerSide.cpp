#include <iostream>
#include <Windows.h>
#include <winsock.h>

using namespace std;

int main() {


	WSADATA WinSocketData;
	int iWsaStartup;
	int iWsaCleanup;

	SOCKET UDPSocket;
	struct sockaddr_in UDPClient;

	char Buffer[512];
	int iBufferLength = strlen(Buffer) + 1;
	
	int iBind;
	int iReceiveFrom;

	int iUDPClientLength = sizeof(UDPClient);
	int iCloseSocket;

	cout << "----------------------------Server side-----------------------" << endl;

	// 1 WSAStartup initialization
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSocketData);

	if (iWsaStartup != 0) {
		cout << "WSA Startup Failed" << endl;
	}
	cout << "WSA Startup Succeeded" << endl;

	//2 udp Client (socket address) structure filling

	UDPClient.sin_family = AF_INET;
	UDPClient.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPClient.sin_port = htons(8001);
	// htons converts little endian to big endian format, and all the protocols run in big endian format

	//3 socket creation
	 
	UDPSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (UDPSocket == INVALID_SOCKET) {

		cout << "Socket creation failed with : "<< WSAGetLastError() << endl;

	}
	cout << "Socket created successfully" << endl;

	//4 bind server

	iBind = bind(UDPSocket, (SOCKADDR*)&UDPClient, sizeof(UDPClient));

	if (iBind == SOCKET_ERROR) {
		cout << "Server binding failed with : " << WSAGetLastError() << endl;
	}

	cout << "Server bind succeeded " << endl;


	//5 receive data from client

	iReceiveFrom = recvfrom(UDPSocket, Buffer, iBufferLength, MSG_PEEK, (SOCKADDR*)&UDPClient, &iUDPClientLength);
	if (iBind == SOCKET_ERROR) {

		cout << "Receive data from client failed with : " << WSAGetLastError() << endl;

	}
	
	cout << "Data received from client is : " << Buffer << endl;


	// 6 close socket

	iCloseSocket = closesocket(UDPSocket);

	if (iCloseSocket == SOCKET_ERROR) {
		cout << "closing socket failed" << WSAGetLastError() << endl;
	}
	cout << "Closed socket successfully" << endl;

	//7 WSA Cleanup function for terminating dll
	iWsaCleanup = WSACleanup();
	
	if (iWsaCleanup == SOCKET_ERROR) {
		cout << "closing socket failed" << WSAGetLastError() << endl;
	}
	cout << "WSA cleanedup successfully" << endl;

	return 0;
}