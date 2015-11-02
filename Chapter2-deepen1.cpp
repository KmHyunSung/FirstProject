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
			// 콘솔에서 유니코드 한글 출력을 위해 필요하다.
			_tsetlocale(LC_ALL, _T(""));

			//연산 데이터 입력
			TCHAR tmp[1024];
			_tprintf(_T("Input : "));
			_tscanf(_T("%s"), tmp);


			CString str = tmp;

			int sum=0, sub=0, mul=0, div=0;	// +,-,*,/ 값을 저장할 변수
			CString left, right;	// 왼쪽에 입력될 수와 오른쪽에 입력될 수를 담을 변수

			sum = str.FindOneOf( _T( "+" )) + 1; //덧셈값 인덱스 저장
			sub = str.FindOneOf( _T( "-" )) + 1; //뺄셈값 인덱스 저장
			mul = str.FindOneOf( _T( "*" )) + 1; //곱 값 인덱스 저장
			div = str.FindOneOf( _T( "/" )) + 1; //나누기 값 인덱스 저장

			int length = str.GetLength();	//입력한 문자의 총 길이 저장

			if(sum != 0) {		
				
				left = str.Left(sum-1);			
				right = str.Mid(sum, length);	
			
				int left_num = _ttoi(left);		//문자로 저장된 left를 정수로 변환
				int right_num = _ttoi(right);	//문자로 저장된 right를 정수로 변환
				
				_tprintf(_T("\n\t%s + %s = %d 입니다.\n\n"), left, right, left_num + right_num);	
			}

			if(sub != 0) {		
				
				left = str.Left(sub-1);	
				right = str.Mid(sub, length);
					
				int left_num = _ttoi(left);
				int right_num = _ttoi(right);
				
				_tprintf(_T("\n\t%s - %s = %d 입니다.\n\n"), left, right, left_num - right_num);
			}

			if(mul != 0) {		
				
				left = str.Left(mul-1);
				right = str.Mid(mul, length);

				int left_num = _ttoi(left);
				int right_num = _ttoi(right);
				
				_tprintf(_T("\n\t%s * %s = %d 입니다.\n\n"), left, right, left_num * right_num);
			}

			if(div != 0) {		
				
				left = str.Left(div-1);	
				right = str.Mid(div, length);

				float left_num = _ttoi(left);	//나눈 값이 소수가 될 수 있으므로 float 사용.
				float right_num = _ttoi(right);
				
				_tprintf(_T("\n%s / %s결과는 %.2lf 입니다.\n\n"), left, right, left_num / right_num);
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
