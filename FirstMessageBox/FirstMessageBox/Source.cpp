#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLineArgs, int cmdShow) {

	MessageBox(NULL, TEXT("My first program"), TEXT("Learning GUI through WIN32"), MB_ICONINFORMATION);

	return 0;
}