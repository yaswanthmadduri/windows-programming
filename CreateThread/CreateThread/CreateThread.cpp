#include <iostream>
#include <Windows.h>
using namespace std;


DWORD WINAPI startAddressFunction(LPVOID LPParam) {
	return 0; // just a function
}

int main() {

	HANDLE hThread = NULL;
	DWORD ThreadId;

	hThread = CreateThread(NULL, 0, startAddressFunction, NULL, 0, &ThreadId);

	if (hThread == FALSE) {
		cout << "Thread creation failed" << GetLastError() << endl;
	}

	cout << "Thread is running successfully" << endl;
	cout << "Thread ID : " << ThreadId << endl;

	
	if (hThread) {
		CloseHandle(hThread);
	}
	system("PAUSE");
	return 0;
}