// WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WinAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
//WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    //LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    //HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI));
    //Accelerator:단축키를 의미한다. 단축키를 의미하는 shorcut이 있지만 이 이름의 다른 기능이 존재한다.

    ULONGLONG FPS = 30;     // Frame Per Seconds
    INT invFPS = 1000 / FPS;  // 1초 : 1000

    ULONGLONG frameTime, limitFrameTime = GetTickCount64();

    MSG msg;
    // 기본 메시지 루프입니다:
    while (true) //GetMessage(&msg, nullptr, 0, 0) 게임 루프는 계속 돌아야 하므로 제거.
    {            //GetMessage는 메시지를 받을 때까지 대기를 하므로 같은 기능을 하는 PeekMessage를 사용한다.

        //0U:unsigned형의 모든 상수 접미사는 'U'를 사용한다
        //PM_REMOVE:처리된 메시지는 큐에서 제거된다.
        //메시지가 발생하면 WndProc가 호출되게 한다. TranslateMessage와 DispatchMessage가 호출해준다.
        //PeekMessage는 메시지가 있으면 true(1) 없으면 false(0)를 반환.
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) //!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)
        {                                               //Accelerator를 사용할 수 있게해준다.
                                                        //키보드 입력을 받으면 WM_COMMAND 메시지 처리가 되도록 한다.

            if (WM_QUIT == msg.message) break; //while 조건에서 GetMessage를 제거했기 때문에,
                                               //프로그램이 종료되었다는 것을 알리는 WM_QUIT를 확인하여 게임 루프를 종료한다.
                                               //PostQuitMessage 함수가 호출되면 발생.

            TranslateMessage(&msg); // WM_KEYDOWN, WM_KEYUP이 발생하면 가상 키 코드(VK_)를 WM_CHAR에서 사용가능한 문자로 변환.
            DispatchMessage(&msg); // 발생한 메시지를 WndProc()에 발송, WndProc()가 호출.
        }
        else
        {
            //여기서 그리기와 이벤트 처리하는 내용을 추가하면 된다.
            frameTime = GetTickCount64();       //윈도우가 시작된 후 지금까지 시간. 1/1000초.
            if (!(limitFrameTime > frameTime))  //0.03초마다 업데이트.
            {
                float elapsed = (frameTime - limitFrameTime + invFPS) * 0.001f; //유저의 시스템 환경에 따라 발생하는 시간차이.
                limitFrameTime = frameTime + invFPS;//30 => 0.03초.
            }
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;//MAKEINTRESOURCEW(IDC_WINAPI); 메뉴 바를 사용하지 않음.
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = NULL;// LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
   //WS_OVERLAPPEDWINDOW
   //WS_OVERLAPPED  :0값을 가지므로 의미가 없다.
   //WS_CAPTION     :타이틀 바를 가진다.
   //WS_SYSMENU     :시스템 메뉴를 가진다.
   //WS_MINIMIZEBOX :최소화 버튼을 가진다.
   //WS_MAXIMIZEBOX :최대화 버튼을 가진다.
   //WS_THICKFRAME  :크기조절을 가능하게 한다.
   HWND hWnd = CreateWindowW(szWindowClass, L"타이틀 이름!!"/*szTitle*/, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   //-----------------------------------------------------------
   // 윈도우 작업영역을 화면의 중앙에 맞추기 위해 코드 추가.
   RECT rcWinBounds;
   if (GetWindowRect(hWnd, &rcWinBounds))
   {
       int nScreenWidth = GetSystemMetrics(SM_CXFULLSCREEN);  //SM_CXFULLSCREEN:전체화면의 너비.
       int nScreenHeight = GetSystemMetrics(SM_CYFULLSCREEN); //SM_CYFULLSCREEN:전체화면의 높이.
                                                              //테스크바에의해 영향을 받기 때문에 그게 싫다면,
                                                              //SM_CXSCREEN, SM_CYSCREEN을 사용하면 된다.
       int nWidth = rcWinBounds.right - rcWinBounds.left;
       int nHeight = rcWinBounds.bottom - rcWinBounds.top;
       int fDestX = static_cast<int>((nScreenWidth - nWidth) * 0.5f);
       int fDestY = static_cast<int>((nScreenHeight - nHeight) * 0.5f);

       MoveWindow(hWnd, fDestX, fDestY, nWidth, nHeight, true);
   }
   //-----------------------------------------------------------

   //SetWindowText(hWnd, L"타이틀 이름!!");

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        //WM_COMMAND는 사용하지 않는다.
    //case WM_COMMAND:
    //    {
    //        int wmId = LOWORD(wParam);
    //        // 메뉴 선택을 구문 분석합니다:
    //        switch (wmId)
    //        {
    //        case IDM_ABOUT:
    //            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    //            break;
    //        case IDM_EXIT:
    //            DestroyWindow(hWnd);
    //            break;
    //        default:
    //            return DefWindowProc(hWnd, message, wParam, lParam);
    //        }
    //    }
    //    break;
    ////그리기는 게임루프에서 처리.
    //case WM_PAINT:
    //    {
    //        PAINTSTRUCT ps;
    //        HDC hdc = BeginPaint(hWnd, &ps);
    //        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    //        EndPaint(hWnd, &ps);
    //    }
    //    break;
    case WM_KEYDOWN:
    {
        //esc 키를 누르면 어플리케이션 종료하겠다.
        if (VK_ESCAPE == wParam)
        {
            PostQuitMessage(0);
        }
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

// 정보 대화 상자의 메시지 처리기입니다.
// 시용하지 않음.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
