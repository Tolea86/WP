#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{


    static TCHAR szAppName[] = TEXT ("HelloWin") ;
    HWND hwnd ;
    MSG msg ;
    WNDCLASS wndclass ;
    wndclass.style = CS_HREDRAW | CS_VREDRAW ;
    wndclass.lpfnWndProc = WndProc ;
    wndclass.cbClsExtra = 0 ;
    wndclass.cbWndExtra = 0 ;
    wndclass.hInstance = hInstance ;
    wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wndclass.lpszMenuName = NULL ;
    wndclass.lpszClassName = szAppName ;

    if (!RegisterClass (&wndclass))
    {
            MessageBox (NULL, TEXT ("This program requires Windows NT!"),szAppName, MB_ICONERROR) ;
    return 0 ;
    }
    hwnd = CreateWindow (szAppName, // window class name
                         TEXT ("Lab#1"), // window caption
                         WS_OVERLAPPEDWINDOW, // window style
                         CW_USEDEFAULT, // initial x position
                         CW_USEDEFAULT, // initial y position
                         CW_USEDEFAULT, // initial x size
                         CW_USEDEFAULT, // initial y size
                         NULL, // parent window handle
                         NULL, // window menu handle
                         hInstance, // program instance handle
                         NULL) ; // creation parameters

    ShowWindow (hwnd, iCmdShow) ;
    UpdateWindow (hwnd) ;
    while (GetMessage (&msg, NULL, 0, 0))
    {
        TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
    }
    return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HFONT tempFont;
    HWND button;
    HWND button2;
    HDC hdc ;
    PAINTSTRUCT ps ;
    RECT rect ;
    switch (message)
    {
        case WM_CREATE:
            return 0 ;
        case WM_PAINT:
            hdc = BeginPaint (hwnd, &ps) ;

            GetClientRect (hwnd, &rect) ;
            DrawText (hdc, TEXT ("Done with Pride and Prejudice by Iuzvac Anatolie"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;

            button = CreateWindow("BUTTON", TEXT ("THIS IS A BUTTON"), WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 50, 200, 20, hwnd, NULL, NULL, NULL );
            button2 = CreateWindow("BUTTON", TEXT ("THIS IS A BUTTON 2"), WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 100, 300, 30, hwnd, NULL, NULL, NULL );

            //HFONT hFont = (HFONT)GetStockObject(OEM_FIXED_FONT);
            tempFont = CreateFont(10, 5, 15, 15, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

            SendMessage(button2, WM_SETFONT, (WPARAM)tempFont, MAKELPARAM(TRUE, 0));


            EndPaint (hwnd, &ps) ;
            return 0 ;

        case WM_DESTROY:
            PostQuitMessage (0) ;
            return 0 ;
    }
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}
