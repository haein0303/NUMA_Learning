#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <psapi.h>
#include <tchar.h>

#include<iostream>
#include<mutex>
#include<thread>
#include<vector>

using namespace std;

void func(int num) {
	volatile int tmp = 0;
	while (1) {
		if (tmp > 100000000) {
			tmp = 0;
			cout << num << " is work" << endl;
		}
		tmp++;
	}
}

int main(int argc, const wchar_t* argv[]) {
	
	SYSTEM_INFO SystemInfo;
	GetSystemInfo(&SystemInfo);
	ULONG NumberOfProcessors = SystemInfo.dwNumberOfProcessors;
	DWORD  PageSize = SystemInfo.dwPageSize;
	
	ULONG HighestNodeNumber;

	if (!GetNumaHighestNodeNumber(&HighestNodeNumber))
	{
		_tprintf(_T("GetNumaHighestNodeNumber failed: %d\n"), GetLastError());
		return 0;
	}
	cout << "NUMA NODE COUNT : " << HighestNodeNumber + 1 << endl;

	cout << "Processor COUNT : " << NumberOfProcessors << endl;
	
}