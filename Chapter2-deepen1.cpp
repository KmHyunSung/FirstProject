// Chapter2-deepen1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chapter2-deepen1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// �ֿܼ��� �����ڵ� �ѱ� ����� ���� �ʿ��ϴ�.
			_tsetlocale(LC_ALL, _T(""));

			//���� ������ �Է�
			TCHAR tmp[1024];
			_tprintf(_T("Input : "));
			_tscanf(_T("%s"), tmp);


			CString str = tmp;

			int sum=0, sub=0, mul=0, div=0;	// +,-,*,/ ���� ������ ����
			CString left, right;	// ���ʿ� �Էµ� ���� �����ʿ� �Էµ� ���� ���� ����

			sum = str.FindOneOf( _T( "+" )) + 1; //������ �ε��� ����
			sub = str.FindOneOf( _T( "-" )) + 1; //������ �ε��� ����
			mul = str.FindOneOf( _T( "*" )) + 1; //�� �� �ε��� ����
			div = str.FindOneOf( _T( "/" )) + 1; //������ �� �ε��� ����

			int length = str.GetLength();	//�Է��� ������ �� ���� ����

			if(sum != 0) {		
				
				left = str.Left(sum-1);			
				right = str.Mid(sum, length);	
			
				int left_num = _ttoi(left);		//���ڷ� ����� left�� ������ ��ȯ
				int right_num = _ttoi(right);	//���ڷ� ����� right�� ������ ��ȯ
				
				_tprintf(_T("\n\t%s + %s = %d �Դϴ�.\n\n"), left, right, left_num + right_num);	
			}

			if(sub != 0) {		
				
				left = str.Left(sub-1);	
				right = str.Mid(sub, length);
					
				int left_num = _ttoi(left);
				int right_num = _ttoi(right);
				
				_tprintf(_T("\n\t%s - %s = %d �Դϴ�.\n\n"), left, right, left_num - right_num);
			}

			if(mul != 0) {		
				
				left = str.Left(mul-1);
				right = str.Mid(mul, length);

				int left_num = _ttoi(left);
				int right_num = _ttoi(right);
				
				_tprintf(_T("\n\t%s * %s = %d �Դϴ�.\n\n"), left, right, left_num * right_num);
			}

			if(div != 0) {		
				
				left = str.Left(div-1);	
				right = str.Mid(div, length);

				float left_num = _ttoi(left);	//���� ���� �Ҽ��� �� �� �����Ƿ� float ���.
				float right_num = _ttoi(right);
				
				_tprintf(_T("\n%s / %s����� %.2lf �Դϴ�.\n\n"), left, right, left_num / right_num);
			}
		}// TODO: code your application's behavior here.
		
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
