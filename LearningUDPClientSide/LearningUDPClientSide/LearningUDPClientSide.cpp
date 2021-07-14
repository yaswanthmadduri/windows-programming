#include <iostream>
#include <Windows.h>
#include <winsock.h>

using namespace std;

int main() {
	cout << "----------------------------Client side-----------------------" << endl;

	WSADATA WinSocketData;
	int iWsaStartup;
	int iWsaCleanup;

	SOCKET UDPClientSocket;
	struct sockaddr_in UDPServer;

	char Buffer[512] = "Message typed in the udp client side";
	int iBufferLength = strlen(Buffer) + 1;



	int iSendTo;

	int iUDPClientLength = sizeof(UDPClientSocket);
	int iCloseSocket;

	//1 initialize winsock
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSocketData);

	if (iWsaStartup != 0) {
		cout << "WSA Startup Failed" << endl;
	}
	cout << "WSA Startup Succeeded" << endl;

	//2 filling the UDP Server structure;

	UDPServer.sin_family = AF_INET;
	UDPServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPServer.sin_port = htons(8001);

	//3 UDP Socket creation for client
	UDPClientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (UDPClientSocket == INVALID_SOCKET) {
		cout << "UDP Client socket creation failed with error code : " << WSAGetLastError() << endl;
	}
	cout << "UDP Client socket created" << endl;

	//4 Function for sending data to server
	
	iSendTo = sendto(UDPClientSocket, Buffer, iBufferLength, 0 , (SOCKADDR*)&UDPServer, sizeof(UDPServer));

	if (iSendTo == SOCKET_ERROR) {

		cout << "UDP Client didnot send data. It failed with error code : " << WSAGetLastError() << endl;
	}
	cout << "UDP Client socket sent data to server" << endl;

	
	 // 5 closing socket after sending data

	iCloseSocket = closesocket(UDPClientSocket);

	if (iCloseSocket == SOCKET_ERROR) {
		cout << "UDP Client close connection failed with error code : " << WSAGetLastError() << endl;
	}

	cout << "UDP Client socket closed successfully" << endl;

	
	
	//6 WSA Cleanup function for terminating dll
	iWsaCleanup = WSACleanup();

	if (iWsaCleanup == SOCKET_ERROR) {
		cout << "closing socket failed" << WSAGetLastError() << endl;
	}
	cout << "WSA Cleaned up successfully" << endl;
	return 0;
}