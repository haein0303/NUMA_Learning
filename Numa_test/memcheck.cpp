#include <Windows.h>
#include <iostream>

using namespace std;

const int DIV = 1024 * 1024 * 1024;
//원하는 사이즈 만큼에 메모리를 지정
const int AvailableSize = 1000;

int main()
{

	//메모리를 얻어옴
	MEMORYSTATUS ms;
	GlobalMemoryStatus(&ms);

	//원하는 만큼 메모리가 없다면 ? 이 곳에서 적절한 처리
	if (ms.dwAvailVirtual < AvailableSize)
		cout << "메모리부족" << endl;
	else
	{
		cout << "현재 " << ms.dwMemoryLoad << "%의 메모리를 사용하고 있습니다" << endl;
		cout << ms.dwTotalPhys / DIV << " Gbyte of Physical Memory (total) " << endl;
		cout << ms.dwAvailPhys / DIV << " Gbyte of Physical Memory (free) " << endl;

		cout << ms.dwTotalPageFile / DIV << " Gbyte of Paging File (total)" << endl;
		cout << ms.dwAvailPageFile / DIV << " Gbyte of Paging File (free) " << endl;

		cout << ms.dwTotalVirtual / DIV << " Gbyte of virtual memory (total)" << endl;
		cout << ms.dwAvailVirtual / DIV << " Gbyte of virtual memory (free)" << endl;
	}


	return 0;
}
