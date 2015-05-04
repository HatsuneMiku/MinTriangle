#include <Windows.h>
#include "windowutil.h"
#include "D3DManager.h"


auto szTitle = L"MinTriangle";
auto szWindowClass = L"MinTriangle";

int WINAPI WinMain(
        HINSTANCE hInstance, // ���݂̃C���X�^���X�̃n���h��
        HINSTANCE hPrevInstance, // �ȑO�̃C���X�^���X�̃n���h��
        LPSTR lpCmdLine, // �R�}���h���C��
        int nCmdShow // �\�����
        )
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    D3DManager d3d;

    auto hWnd=windowutil::NewWindow(
            szWindowClass
            , szTitle
            , &d3d);
    if(!hWnd)return 1;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // create d3d
	if (!d3d.CreateDevice())return 2;

    // main loop
    MSG msg;
    while (true)
    {
        if (PeekMessage (&msg,NULL,0,0,PM_NOREMOVE))
        {
            if (!GetMessage (&msg,NULL,0,0))
                return msg.wParam ;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            // clear render target
            d3d.Render(hWnd);
        }
    }
    return (int) msg.wParam;
}

