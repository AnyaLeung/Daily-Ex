// WindowsProject8.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "WindowsProject8.h"
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HFONT CreateMyFont(HDC hdc, int height, LPCWSTR FontName, COLORREF FontColor);

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT8));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
	POINT pos[5][100]; //record every word position
	int i = 0;
	static short lineCount = 0;
	short wordCount = 0;
	LPCWSTR psz[] = {
		L"This is the first line",
		L"This is the second line",
		L"This is the third line",
		L"This is the fourth line",
		L"This is the fifth line"
	};
	LPCWSTR fontsName[] = {
		L"楷体",
		L"黑体",
		L"隶书",
		L"黑体",
		L"楷体"
	};

	//cal length o' every line
	int lineSize[5];
	for (int i=0; i<5; i++) {
		lineSize[i] = lstrlen(psz[i]);
	}

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_CREATE:
		while (!SetTimer(hWnd, 1, 2000, NULL))
				PostQuitMessage(1);
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

			Sleep(800);

			while (wordCount <= lineSize[lineCount]) {
				printf("linecount:");
				printf("%d", lineCount);
				printf("    ");
				printf("wordcount:");
				printf("%d", wordCount);
				printf("    ");

				//calculate position
				if (!wordCount) {
					pos[lineCount][wordCount].x = 0;
				}
				else {
					pos[lineCount][wordCount].x = pos[lineCount][wordCount - 1].x + pos[lineCount][wordCount].x;
				}

				if (!lineCount) {
					pos[lineCount][wordCount].y = 0;
				}
				else {
					pos[lineCount][wordCount].y = pos[lineCount][wordCount].y + pos[lineCount - 1][wordCount].y;
				}

				//calculate font size, from 8 to 40
				float tmp = 32 / lineSize[lineCount];
				int height = 8 + (int)tmp * wordCount;
				printf("height:");
				printf("%d", height);
				printf("     ");

				//calculate font color, from RGB(0, 0, 0) to RGB(255, 255, 255)
				tmp = 255 / lineSize[lineCount];
				printf("rgb:");
				printf("%f", tmp);
				COLORREF cr = RGB(wordCount*tmp, wordCount*tmp, wordCount*tmp);

				//print current char
				hf = CreateMyFont(hdc, height, fontsName[lineCount], cr);
				WCHAR word[1];
				word[0] = psz[lineCount][wordCount];
				LPCWSTR pszWordAfterConversion = word;
				TextOut(hdc, pos[lineCount][wordCount].x, pos[lineCount][wordCount].y,pszWordAfterConversion, 1);


				wordCount++;
			}
			
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
		if (wParam == 1)
		{
			lineCount = lineCount + 1;
			if (lineCount == 5) {
				lineCount = 0;
			}
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

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

HFONT CreateMyFont(HDC hdc, int height, LPCWSTR FontName, COLORREF FontColor)
{
	HFONT hf;

	hf = CreateFont(
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

	SetTextColor(hdc, FontColor);
	return hf;
}

