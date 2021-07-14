/* https://docs.microsoft.com/en-us/windows/win32/api/psapi/nf-psapi-enumprocesses */



#include <Windows.h>
#include <Psapi.h>
#include <wchar.h>
#include <tchar.h>
#include <iostream>

using namespace std;

void listAllProcessesRunning( DWORD dwprocessID ) {

	HANDLE hProcess;
	HMODULE hModule;
	DWORD bytesNeeded = 0;
	DWORD dwDesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
	BOOL bInheritHandle = FALSE;
	BOOL bEnumProcessModule = FALSE;
	TCHAR ProcessName[MAX_PATH] = TEXT("Unknown/ hidden");
	TCHAR ProcessPath[MAX_PATH] = TEXT("Unknown/ hidden process Path");

	// process_query_info ==> Required to retrieve certain information about a process, such as its token, exit code, and priority class
	//process_vm_read ==> reads from the memory in a process

	hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwprocessID);
	//openProcess creates handle for an existing process object.

	if (hProcess != NULL) {



		bEnumProcessModule = EnumProcessModulesEx(hProcess, &hModule, sizeof(hModule), &bytesNeeded, LIST_MODULES_ALL);

		if (bEnumProcessModule != FALSE) {

			//getting process module name
			GetModuleBaseName(hProcess, hModule, ProcessName, sizeof(ProcessName) / sizeof(TCHAR));


			//getting process path
			GetModuleFileNameEx(hProcess, hModule, ProcessPath, sizeof(ProcessPath) / sizeof(TCHAR));

		}
	}


	//displaying the process name (module base name), path, process identifier

	_tprintf(TEXT("Module base name : %s \n"), ProcessName);
	_tprintf(TEXT("Process path : %s \n"), ProcessPath);
	wcout << "Process identifier : " << dwprocessID << endl << endl;
	cout << "---------------------------------------" << endl;

	// closing handle
	if (hProcess) {

		CloseHandle(hProcess);

	}

}


int main() {
	DWORD aProcesses[2048] = { 0 };
	BOOL bEnumProcess = FALSE;
	DWORD bytesNeeded = 0;

	DWORD totalNoOfProcesses = 0;

	bEnumProcess = EnumProcesses(aProcesses, sizeof(aProcesses), &bytesNeeded);

	// aProcesses gets an array of PROCESS IDENTIFIERS of all running processes.

	if (bEnumProcess == FALSE) {
		cout << "ENUM Process function failed" << endl;
		cout << "Error number: " << GetLastError << endl;
 	}

	cout << "ENUM Process function succeeded" << endl;

	totalNoOfProcesses = bytesNeeded / sizeof(DWORD); 
	//for example, 1024/4 = 256 processes; 1024 bytes needed and each dword is 4 bytes (32bit) length

	for (int i = 0; i < totalNoOfProcesses; i++) {

		listAllProcessesRunning(aProcesses[i]);

	}

	wcout << "Total number of processes running : " << totalNoOfProcesses << endl;


	return 0;
}