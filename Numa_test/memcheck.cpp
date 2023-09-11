#include <Windows.h>
#include <iostream>

using namespace std;

const int DIV = 1024 * 1024 * 1024;
//���ϴ� ������ ��ŭ�� �޸𸮸� ����
const int AvailableSize = 1000;

int main()
{

	//�޸𸮸� ����
	MEMORYSTATUS ms;
	GlobalMemoryStatus(&ms);

	//���ϴ� ��ŭ �޸𸮰� ���ٸ� ? �� ������ ������ ó��
	if (ms.dwAvailVirtual < AvailableSize)
		cout << "�޸𸮺���" << endl;
	else
	{
		cout << "���� " << ms.dwMemoryLoad << "%�� �޸𸮸� ����ϰ� �ֽ��ϴ�" << endl;
		cout << ms.dwTotalPhys / DIV << " Gbyte of Physical Memory (total) " << endl;
		cout << ms.dwAvailPhys / DIV << " Gbyte of Physical Memory (free) " << endl;

		cout << ms.dwTotalPageFile / DIV << " Gbyte of Paging File (total)" << endl;
		cout << ms.dwAvailPageFile / DIV << " Gbyte of Paging File (free) " << endl;

		cout << ms.dwTotalVirtual / DIV << " Gbyte of virtual memory (total)" << endl;
		cout << ms.dwAvailVirtual / DIV << " Gbyte of virtual memory (free)" << endl;
	}


	return 0;
}
