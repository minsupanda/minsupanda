// Project1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Project1.h"
#pragma comment(lib, "msimg32.lib")

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


HBITMAP Chess, Dog;
int g_nX = 0, g_nY = 0;
void Draw(HWND Hwnd, HDC hdc);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);

    MSG msg;

    Chess = (HBITMAP)LoadImage(NULL, L"block_w_00.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    Dog = (HBITMAP)LoadImage(NULL, L"00.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    HDC hdc = GetDC(hWnd);

    ULONGLONG checkTime, limitTime = GetTickCount64();
    // clock()과 비슷한 기능을 하는 함수
    // clock은 int형으로 값을 받기 때문에 범위가 넉넉하지 않다.
    // GetTickCount64()은 Unsinged Long Long 형태로 받아오기 때문에 범위가 넉넉하다.

    int fps = 1000 / 120;// 프레임

    while (1)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
            // PeekMessage : 메시지가 발생했는지 확인하는 함수
            // PM_ROMOVE : 발생한 메시지를 큐에서 제거
        {
            if (WM_QUIT == msg.message) break; // Quit 메시지가 오면 break
            // WM_DISTORY에서 PostQuitMessage(0);가 호출되서 윈도우 창이 없어지더라도 종료된 것이 아니다.
            // 그렇기 때문에 이 라인이 없으면 제대로 종료가 되지 않는 것 (무한반복 돌고 있음)

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else // 게임에서는 메시지가 발생하지 않더라도 계속해서 새로 그려야하기 때문에 있는 조건
        {
            checkTime = GetTickCount64();
            if (limitTime <= checkTime)
            {
                float deltaTime = (checkTime - limitTime + fps) * 0.001f;
                // 이 라인까지 오는데 걸린 시간을 확인하는 변수
                // checkTime - limitTime 하면 최소 0이고 무조건 양수 값이 나오게 된다.
                // + fps는 프레임 제한을 걸기 떄문에 저 값만큼 지연이 되므로?
                // * 0.001f은 세컨드 값으로 바꿔주기 위해 곱해주는 것

                limitTime = checkTime + fps;
                // 다시 제한시간 초기화
                // + fpas는 프레임에 제한을 걸기 위해 더해주는 것

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    g_nX += 500 * deltaTime;
                    // 거리 = 속력 * 시간
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    g_nX -= 500 * deltaTime;
                }

                Draw(hWnd, hdc);
            }
        }
    }

    DeleteObject(Chess);
    DeleteObject(Dog);
    ReleaseDC(hWnd, hdc);

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


HBITMAP MyCreateDIBSection(HDC hdc, int width, int height)
{
    BITMAPINFO bm_info;
    ZeroMemory(&bm_info.bmiHeader, sizeof(BITMAPINFOHEADER));
    bm_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);

    bm_info.bmiHeader.biBitCount = 24;
    bm_info.bmiHeader.biWidth = width; 
    bm_info.bmiHeader.biHeight = height;
    bm_info.bmiHeader.biPlanes = 1;
    LPVOID pBits;
    return CreateDIBSection(hdc, &bm_info, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
}


void Draw(HWND Hwnd, HDC hdc)
{
    RECT clientRect;
    GetClientRect(Hwnd, &clientRect);
    // 클라이언트 크기 알아주는 함수
   
    HBITMAP backBitmap = MyCreateDIBSection(hdc, clientRect.right + 1, clientRect.bottom + 1);
    // GetClientRect함수로 클라이언트 크기를 알아올 때 픽셀의 인덱스 수로 알아온다 
    // Ex. 120픽셀이면 119 => 그러므로 + 1을 해줘서 클라이언트의 크기에 맞도록 해준다
     
    //HBITMAP backBitmap = CreateCompatibleBitmap(hdc, clientRect.right + 1, clientRect.bottom + 1);
    // MyCreateDIBSection 이것 외에 버퍼 공간을 만드는 함수
    // 하지만 컬러가 더욱 제한적이다. 16bit가 최대

    HDC backDC = CreateCompatibleDC(hdc);
    SelectObject(backDC, backBitmap);

    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, Chess);
    TransparentBlt(backDC, 100 + g_nX, 100, 125, 125, memDC, 0, 0, 125, 125, RGB(255, 0, 255));
    SelectObject(memDC, oldBitmap);
    oldBitmap = (HBITMAP)SelectObject(memDC, Dog);

    BitBlt(backDC, 0, 0, 145, 245, memDC, 0, 0, SRCCOPY);
    StretchBlt(backDC, 200, 200, 245, 345, memDC, 0, 0, 145, 245, SRCCOPY);
    //SelectObject(memDC, oldBitmap);
    DeleteDC(memDC);

    BitBlt(hdc, 0, 0, clientRect.right + 1, clientRect.bottom + 1, backDC, 0, 0, SRCCOPY);
    // 그냥 출력만 해주는 함수이기 때문에 사용 (나머지 StrectBlt, TransparentBlt 는 다른 처리가 이루어지기 때문에 처리 속도가 오래 걸린다)

    DeleteDC(backDC);
    DeleteObject(backBitmap);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}