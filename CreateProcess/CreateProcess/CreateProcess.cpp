#include <Windows.h>
#include <iostream>
#include <tchar.h>

using namespace std; 

int main() {

	HANDLE hProcess; // not used anywhere..???
	HANDLE hThread;

	STARTUPINFO SI;// contains information on how to start a process
	PROCESS_INFORMATION PI; // contains process related information



	ZeroMemory(&SI, sizeof(SI)); // zero-ing all the data of structure
	ZeroMemory(&PI, sizeof(PI)); // """""""""""""""""""""""""""""


	BOOL bCreateProcess = FALSE;

	bCreateProcess = CreateProcess(L"C:\\Program Files\\Mozilla Firefox\\firefox.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &SI, &PI);
	if (bCreateProcess == FALSE) {
		cout << "Creating a process failed" << GetLastError() << endl;
	}

	cout << "Creating a process done" << endl;
	cout << "process id: " << GetProcessId(PI.hProcess) <<endl;



	WaitForSingleObject(PI.hProcess, INFINITE); //waits till the process/ app is closed

	CloseHandle(PI.hProcess);
	CloseHandle(PI.hThread);

	system("PAUSE");
	
	return 0;
}