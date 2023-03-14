// Project2.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Project2.h"
#include <string>
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
// 프로그램의 인스턴스핸들
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // - wWinMian : 이게 메인 함수
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance); // - 있어도 되고 없어도 된다. 타고 들어가면 p하나 있고 아무것도 없음
    UNREFERENCED_PARAMETER(lpCmdLine);// - 있어도 되고 없어도 된다. 타고 들어가면 p하나 있고 아무것도 없음

    // TODO: 여기에 코드를 입력합니다.
    
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);// - IDS_APP_TITLE 여기에는 아이디 값이 들어가고 이 아이디값에 맞는 문자열을 szTitle 여기에 대입을 해준다.
    LoadStringW(hInstance, IDC_PROJECT2, szWindowClass, MAX_LOADSTRING);// - IDS_APP_TITLE 여기에는 아이디 값이 들어가고 이 아이디값에 맞는 문자열을 szTitle 여기에 대입을 해준다.
    // - IDS_APP_TITLE , IDC_PROJECT2 두 개의 아이디 값은 다르지만 둘다 현재의 프로젝트 명인 Project2가 들어가게 된다.
    // - 이때 Title 창에 뜨는 이름을 임의로 변경하고 싶다면 szTitle이 들어간 함수는 삭제해도 무관하다
    // szWindowClass는 사용처가 따로 있기 때문에 삭제하면 안된다
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // -HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT2));
    // - 단축키를 사용하겠다하면 이 변수를 사용해야 한다.
    // - Accelerator:단축키를 의미한다. 단축키를 의미하는 shorcut이 있지만 이 이름의 다른 기능이 존재한다.


    MSG msg; // - 여기에 내가 어떠한 동작을 했다는 메시지가 저장된다

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0)) // - 여기서 내가 작동한 메시지를 알려주게 된다.
    {
        //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // - 만약 키를 두 가지 이상 누르게 되면 단축키로 인식하게 되는 if문
        // -> 사용하는 경우가 없기 때문에 없애면 된다. => 게임 환경 내의 단축키는 따로 직접 작성하는 것
        // HACCEL hAccelTable 이 변수가 사용되면 쓸일 이 있는 if문
        {
            TranslateMessage(&msg); // - 이때 키보드를 입력하면 키보드에서 소문자인지 대문자인지 특수문자인지 등등 구분해주는 함수
            DispatchMessage(&msg); // - 여기서 WndProc 여기로 타고 들어가게 된다.
        }
    }

    return (int) msg.wParam;
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance) // 윈도우를 이런식으로 만들거다 라고 데이터를 집어넣는 것 // 설계도 같은 느낌
{ // h = 핸들의 약자
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW; // 윈도우 창이 위치좌표나 뭔가 변경이 되거나 하면 메시지를 발송시켜준다!!
    wcex.lpfnWndProc    = WndProc; // long point function WndProc : 함수 포인터가 들어가는 변수
    wcex.cbClsExtra     = 0; // 그냥 0 넣어으면 된다 메모리 추가로 얼마나 줄거냐 (거의 0아닌 경우가 없다)
    wcex.cbWndExtra     = 0; // 그냥 0 넣어으면 된다 메모리 추가로 얼마나 줄거냐(거의 0아닌 경우가 없다)
    wcex.hInstance      = hInstance; // 어플리케이션의 아이디
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT2)); // IDI_PROJECT2 이 아이디에 해당하는 아이콘을 불러올것이다? -> 아이콘을 바꾸고 싶으면 project2 이부분을 수정하면 되는 건가?
    // -> 맞다! -> 바꾸고 싶으면 리소스 파일에 추가해서 하면 아이디 값을 자동으로 추가되기 때문에 그 아이디를 쓰면 된다
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); // - IDC_ARROW 화살표 모양 아이콘을 LoadCursor 불러온다
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); // 백그라운드 색깔을 HBRUSH 브러쉬로 COLOR_WINDOW+1 이 색깔로 칠해줄 것이다
    wcex.lpszMenuName   = NULL;// MAKEINTRESOURCEW(IDC_PROJECT2); // 파일, 도움말 같은 상단바 메뉴 -> 필요가 없다면 NULL을 넣으면 된다; ->정확히는 NULL을 넣어야 한다.
    wcex.lpszClassName  = szWindowClass; // - InitInstance 이 함수 설명된 것 보기!
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); // IDI_SMALL 이 아이디에 해당하는 작은 아이콘을 불러 올것이다
    // - 화면 크기 즉, 해상도가 달라지면 화질이 깨질수도 있기 때문에 큰거 작은거 둘다 구분하는 것이다

    return RegisterClassExW(&wcex); // 내가 지금껏 만든 window창 정보를 등록시키는 함수
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

   // - WCHAR -> WCHAR 타입 : typedef wchar_t WCHAR 이거는 widechar 형태
   // => 멀티바이트 : 영어라면 1byte로 읽고 이외의 문자들은 2btye로 읽는 것
   // => 유니코드 : 모든 문자열을 2byte 읽는 것
   //  widechar 형태는 유니코드 형식으로 일반적으로 써왔던 char 형태와 다르다
   // 그렇기 때문에 문자열을 넣을때 L"~~~~" 형태로 써줘야 한다.

   HWND hWnd = CreateWindowW(
       szWindowClass,   // szWindowClass : 내가 만든 등록되어있는 windows 클래스의 검색키워드라고 생각하며 된다. 이 값으로 구분해서 윈도우를 만들게 된다.
       szTitle, // 타이틀 이름
       WS_SYSMENU | WS_MINIMIZEBOX, // <- WS_OVERLAPPEDWINDOW 원래 얘가 들어가있따!
       //WS_OVERLAPPED  :0값을 가지므로 의미가 없다.
       //WS_CAPTION     :타이틀 바를 가진다. -> 캡션이 가장 위 바를 뜻함
       //WS_SYSMENU     :시스템 메뉴를 가진다. -> 시스템 메뉴가 끄고 닫고 화면 키우고 이거인데 이거만 써도 캡션은 나오기 때문에 캡션은 삭제해도 무관하다
       //WS_MINIMIZEBOX :최소화 버튼을 가진다.
       //WS_MAXIMIZEBOX :최대화 버튼을 가진다.
       //WS_THICKFRAME  :크기조절을 가능하게 한다.
       CW_USEDEFAULT, 0, // - x ,y 좌표
       CW_USEDEFAULT, 0, // - x, y의 높낮이(너비, 높이)
       nullptr, // hWndParent : 어플리케이션을 실행해서 윈도우 창이 뜨면 둘 이상의 창을 띄우고 싶을 때
       nullptr,  // hMenu 우리는 상단의 메뉴바를 쓰지 않으므로 필요가 없다
       hInstance, // 어플리케이션 핸들 값은 필요하므로 사용
       nullptr); // lpParam 윈도우 창을 딱 실행했을 때 곧바로 뭔가 실행되어야 한다 할 때 값을 집어넣는 것이다!
      // 그러면 WndProc 이 함수의 lParam에 들어가서 어떠한 동작을 한다?

   if (!hWnd) // 만약 윈도우를 만드는 것에 실패 했으면 FALSE을 반환
   {
      return FALSE;
   }
   // 윈도우 창을 만들면 실행되는 부분
   ShowWindow(hWnd, nCmdShow); // 우리에게 윈도우 창을 보여주는 것이므로 반드시 필요하다
   //UpdateWindow(hWnd); // 내가 만든 윈도우를 업데이트 하는 함수인데 한번 보여줄때 업데이트가 되므로 없어도 되는 코드!

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
    //case WM_COMMAND: // 단축키를 사용할 때 쓸 일이 생기는 case
    //    {
    //        int wmId = LOWORD(wParam);
    //        // 메뉴 선택을 구문 분석합니다:
    //        switch (wmId)
    //        {
    //        case IDM_ABOUT:
    //            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); // 예를 들어 도구창이나 도움말 같은 command를 입력헀을 때 출력되는 화면들
    //            break;
    //        case IDM_EXIT:
    //            DestroyWindow(hWnd);
    //            break;
    //        default:
    //            return DefWindowProc(hWnd, message, wParam, lParam);
    //        }
    //    }
    //    break;
    case WM_PAINT: // 강사님 수업자료 DC부터 같이 보기!!!!
        {


            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            std::wstring str = L"TEST test TEST";
            TextOut(hdc, 10, 10, str.c_str(), str.length());
            // 문자열 주소라기 보단 문자열 자체가 시작주소 주면 알아서 NULL있을 때까지 읽기 때문에 시작 주소 주는 것이다!

            str = L"TEST test test Test test TEST test Test test test Test test TEST test Test test Test test TEST test Test test";
            // 길게 써야 그 범위를 알 수 있다!!!!!!
            RECT rect = { 100, 100 ,400 ,300 };
            DrawText(hdc, str.c_str(), -1, &rect, DT_CENTER | DT_WORDBREAK);
            EndPaint(hWnd, &ps);

            // 여기서 프로젝트 속성에 문자 집합이 유니코드인지 멀티바이트 인지에 따라 TextOut, DrawText 매크로가 처리되는게 달라진다.
            // 만약 유니코드라면 string 선언시 w를 붙혀 wide 즉 long타입인지를 붙혀줘야 한고
            // 멀티바이트라면 string으로만 선언하면 된다
            // 만약 메크로를 사용하지 않을거라면 유니코드라면 TextOutW, 멀티바이트는 TextOutA 이런식으로 함수를 호출하면 된다!!
            // 유니코드는 모든 문자 데이터를 2byte로 읽고 멀티바이트는 1byte, 2byte 각각 알아서 맞게 읽어들인다
            // 즉, 유니코드는 처리속도가 빠르되 많은 공간을 잡아먹고, 멀티바이트는 byte를 구분해야하므로 처리속도는 느리되 비교적 적은 공간을 차지하게 된다!!
            // --->> 그러면 최적하가 뭐가 좋은거지? 
            // 이거는 케바케 이므로 각각의 장단점에 따라 구분해서 적절히 사용할 것!!!
        }
        break;
    case WM_DESTROY: // WM_Close 도 따로 있다. 하지만 Close가 없더라도 DESTORY가 알아서 Close처럼 작동하기 때문에 destory를 사용해도 된다.
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam); // 위에 모든 case문이 없더라도 얘는 꼭 있어야 한다.
        // 위에 없는 case문이 실행되면 얘가 호출되면서 default값으로 처리가 되기 때문이다
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다. case문에서 commend를 사용할 때 필요한 함수
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
