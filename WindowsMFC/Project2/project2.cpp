#include "stdafx.h"
#include "WindowsProject6.h"
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LOADSTRING 100

static short lineCount = 0;
short wordCount = 0;
int x = 0, y = 0;

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HFONT CreateMyFont(HDC hDC, int height, LPCWSTR , COLORREF color);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此处放置代码。

	// 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT6, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT6));

	MSG msg;

	// 主消息循环:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT6));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT6);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}



//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	HFONT hf;
	PAINTSTRUCT PtStr;
	TEXTMETRIC tm;
	
	LPCWSTR psz[] = {
		L"这是测试样例的第一行（楷体）",
		L"这是测试样例的第二行（黑体）",
		L"这是测试样例的第三行（宋体）",
		L"这是测试样例的第四行（黑体）",
		L"这是测试样例的第五行（楷体）"
	};
	LPCWSTR fontsName[] = {
		L"楷体",
		L"黑体",
		L"宋体",
		L"黑体",
		L"楷体"
	};

	//calculate length o' every line
	int lineSize[5];
	for (int i = 0; i < 5; i++) {
		lineSize[i] = lstrlen(psz[i]);
	}

	switch (message)
	{
	case WM_CREATE:	
		SetTimer(hWnd, 1, 2000, NULL);
		break;
	case WM_PAINT:											
		hdc = BeginPaint(hWnd, &PtStr);						
		wordCount = 0;

		Sleep(800);

		//calculate y position, changes every line
		y = lineCount ? (y + 40) : 10;

		while (wordCount < lineSize[lineCount]) {
			//calculate x position, changes every word
			x = wordCount ? (x + 40) : 10;

			//calculate font size, from 8 to 40
			double tmp = (double)32 / (double)lineSize[lineCount];
			double height = (double)8 + tmp * (double)wordCount;
			int height_para = (int)height;

			//calculate font colour, from 0, 0, 0, to 255, 255, 255
			tmp = 255 / (double)lineSize[lineCount];
			COLORREF cr = RGB(wordCount*tmp, wordCount*tmp, wordCount*tmp);

			//set hf
			hf = CreateMyFont(hdc, height_para, fontsName[lineCount], cr);
			SelectObject(hdc, hf);

			//get current char and print
			WCHAR word[1];
			word[0] = psz[lineCount][wordCount];
			LPCWSTR pszWordAfterConversion = word;
			TextOut(hdc, x, y, pszWordAfterConversion, 1);

			wordCount++;
		}
		break;
	case WM_TIMER:	
		if (wParam == 1)
		{
			lineCount = (lineCount + 1) % 5;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_DESTROY:								
		PostQuitMessage(0);									
		break;
	default:												
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

HFONT CreateMyFont(HDC hDC, int height, LPCWSTR FontName, COLORREF CR)
{
	HFONT hF;	

	hF = CreateFont(
		height,			
		0,						
		0,						
		0,						
		FW_NORMAL,				
		0,						
		0,						
		0,						
		GB2312_CHARSET,			
		OUT_DEFAULT_PRECIS,		
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,		
		DEFAULT_PITCH,			
		FontName			
	);

	SetTextColor(hDC, CR);	//设置字体颜色
	return hF;
}
