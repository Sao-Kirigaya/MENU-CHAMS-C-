#include "main.h"
#include <tchar.h>
#include <tlhelp32.h>
#pragma comment(lib, "d3d9.lib")
#include <sstream>
#include <dwmapi.h>
#include <thread>
#pragma comment(lib, "Dwmapi.lib")
#include <ShObjIdl_core.h>
#pragma comment(lib, "library_x64.lib")
#include "Chams/Visuals.h"

bool DisableParticles = true;
bool ChamsButton = true;
bool ShowChams = false;
bool StartChams = false;

static int KeyHide = VK_INSERT;
static int KeyDelete = VK_DELETE;

DWORD picker_flags = ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha;

void Menu_DLL()
{
    WNDCLASSEXW wc;
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = CS_CLASSDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = NULL;
    wc.cbWndExtra = NULL;
    wc.hInstance = nullptr;
    wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = L"MEND3ZZKONG";
    wc.lpszClassName = L"MEND3ZZKONG";
    wc.hIconSm = LoadIcon(0, IDI_APPLICATION);

    RegisterClassExW(&wc);
    hwnd = CreateWindowExW(NULL, wc.lpszClassName, L"Chams", WS_POPUP, (GetSystemMetrics(SM_CXSCREEN) / 2) - (menu_size.x / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (menu_size.y / 2), menu_size.x, menu_size.y, 0, 0, 0, 0);

    SetWindowLongA(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 255, LWA_ALPHA);

    MARGINS margins = { -1 };
    DwmExtendFrameIntoClientArea(hwnd, &margins);

    SetWindowRgn(hwnd, CreateRoundRectRgn(0, 0, menu_size.x, menu_size.y, 10, 10), TRUE); // Ñîçäàíèå ñêðóãëåííûõ óãëîâ

    POINT mouse;
    rc = { 0 };
    GetWindowRect(hwnd, &rc);

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return ;
    }

    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    D3DX11_IMAGE_LOAD_INFO info; ID3DX11ThreadPump* pump{ nullptr };
    io.Fonts->AddFontFromMemoryTTF(&PoppinsRegular, sizeof PoppinsRegular, 22, NULL, io.Fonts->GetGlyphRangesCyrillic());
    ImFont* Nev = io.Fonts->AddFontFromMemoryTTF(&Nevan, sizeof Nevan, 19, NULL, io.Fonts->GetGlyphRangesCyrillic());

    bold_font = io.Fonts->AddFontFromMemoryTTF(&PoppinsBold, sizeof PoppinsBold, 35, NULL, io.Fonts->GetGlyphRangesCyrillic());

    second_font = io.Fonts->AddFontFromMemoryTTF(&PoppinsRegular, sizeof PoppinsRegular, 18, NULL, io.Fonts->GetGlyphRangesCyrillic());

    icon_font = io.Fonts->AddFontFromMemoryTTF(&icomoon, sizeof icomoon, 20, NULL, io.Fonts->GetGlyphRangesCyrillic());

    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    ImVec4 clear_color = ImVec4(0.6f, 0.6f, 0.6f, 1.00f);

    ImGuiStyle& s = ImGui::GetStyle();

    s.FramePadding = ImVec2(5, 3);
    s.WindowPadding = ImVec2(0, 0);
    s.FrameRounding = 1.f;
    s.WindowRounding = 2.f;
    s.WindowBorderSize = 0.f;
    s.PopupBorderSize = 0.f;
    s.WindowPadding = ImVec2(0, 0);
    s.ChildBorderSize = 10;
    s.WindowShadowSize = 0;

    bool done = false;
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        static bool hide = true;
        static int opticaly = 255;
        if (GetAsyncKeyState(KeyHide) & 0x1) hide = !hide;
        opticaly = ImLerp(opticaly, opticaly <= 255 && hide ? 300 : 0, ImGui::GetIO().DeltaTime * 8.f);
        if (opticaly > 255) opticaly = 255;
        SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), opticaly, LWA_ALPHA);
        ShowWindow(hwnd, opticaly > 0 ? SW_SHOW : SW_HIDE);

        if (GetAsyncKeyState(KeyDelete) & 1)
        {
            exit(0);
        }

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(550, 550));
            ImGui::Begin("General", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoBringToFrontOnFocus);
            {
                main_window = ImGui::GetCurrentWindow();
                auto draw = ImGui::GetWindowDrawList();
                const auto& p = ImGui::GetWindowPos();

                draw->AddRectFilled(p, p + menu_size, ImColor(0.03f, 0.03f, 0.03f, 0.4f), 2.f);

                if (menu_state == 1)
                {
                    if (!loader_animation)
                        loader_animation = GetTickCount();
                    if (GetTickCount() > loader_animation + (1 * 15))
                    {

                        if (text_animation_hide)
                        {

                            if (text_animation < 0.80f)
                                text_animation += 0.04f / ImGui::GetIO().Framerate * 60.f;
                            if (text_animation >= 0.80f)
                                text_animation_hide = false;
                        }

                        else
                        {
                            if (text_animation > 0.00f)
                                text_animation -= 0.04f / ImGui::GetIO().Framerate * 60.f;
                            if (text_animation <= 0.00f)
                                text_animation_hide = true;

                        }
                        loader_animation = 0;
                    }
                }
                else
                {
                    draw->AddRectFilled(p, p + ImVec2(755, 550), background_color, 2.f, ImDrawFlags_RoundCornersTop);
                    draw->AddRectFilled(p, p + ImVec2(755, 550), background_color, 2.f, ImDrawFlags_RoundCornersLeft);

                    // Definir la resolución de la ventana
                    const ImVec2 window_size(407, 549);
                    const ImVec2& min = ImGui::GetWindowPos(); // Obtener la posición de la ventana
                    ImVec2 max = min + window_size; // Establecer el tamaño total de la ventana
                    ImDrawList* draw_list = ImGui::GetWindowDrawList(); // Obtener la lista de dibujo

                    // Configuraciones del borde
                    float border_thickness = 2.0f; // Ajusta según sea necesario
                    float rounding = 10.0f; // Ajusta según sea necesario
                    ImU32 border_color = IM_COL32(49, 255, 55, 100); // Color rojo

                    // Dibuja el borde alrededor de la ventana
                    draw_list->AddRect(min, max, border_color, rounding, ImDrawCornerFlags_All, border_thickness);
                    ImGui::PushFont(bold_font);
                    ImVec4 animated_color = ImVec4(255, 255, 255, text_animation);

                    ImVec4 animated_color2 = ImVec4(255, 0, 0, text_animation);

                    ImGui::PushFont(Nev);

                    // Dibuja el texto con sombra
                    ImGui::ShadowText("Menu Chams Source", IM_COL32(255, 255, 255, 255), IM_COL32(75, 245, 66, 255), 140.0f, ImVec2(55 + p.x, 20 + p.y));

                    // Restaura la fuente original
                    ImGui::PopFont();

                    draw->AddShadowCircle(p + ImVec2(WIDTH / 2, HEIGHT + 150), 150.f, main_color_shadow, 750.f, ImVec2(0, 0));

                    ImGui::PopFont();

                    ImGui::SetCursorPos(ImVec2(10, 90));
                    ImGui::BeginChild("Tabs", ImVec2(90, 530), false);

                    ImGui::Tab("d", &iTabs, 0);
                    ImGui::Tab("c", &iTabs, 1);
                    ImGui::Tab("g", &iTabs, 2);

                    ImGui::EndChild();

                    if (iTabs == 0)
                    {
                        ImGui::SetCursorPos(ImVec2(80, 80));
                        ImGui::BeginChild("Chams 1", ImVec2(450, 530), false);

                        if (ChamsButton)
                        {
                            if (ImGui::Checkbox("Start: Chams", &StartChams))
                            {
                                CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Fenix_GLS, nullptr, 0, nullptr);

                                ShowChams = true;
                                ChamsButton = false;
                            }
                        }

                        if (ShowChams)
                        {
                            ImGui::Checkbox("Chams 3D", &Chams3D);

                            ImGui::Checkbox("Chams Glow", &Glow);

                            ImGui::Checkbox("Chams Animated Glow", &GlowAnimado);

                            ImGui::Checkbox("Chams Solid", &Solido);

                            ImGui::Checkbox("Chams Orion 3D", &Oreon);

                            ImGui::Checkbox("Chams Wukong Color", &ChamsWokung);

                            ImGui::Checkbox("Chams Wukong Color Old", &ChamsWokungOld);

                            ImGui::Checkbox("Chams Volcano", &Lava);

                            ImGui::Checkbox("Chams Glitch", &Glitch);

                            ImGui::Checkbox("Chams Glitch White", &whiteglich);

                            ImGui::Checkbox("Chams Wukong Solara 3D", &WukongSolara);

                            ImGui::Checkbox("Chmas Raiden 3D", &Araña3D);

                            ImGui::Checkbox("Chams Santino 3D", &Santino3D);
                        }
                        ImGui::EndChild();
                    }
                    if (iTabs == 1)
                    {
                        ImGui::SetCursorPos(ImVec2(80, 80));
                        ImGui::BeginChild("Chams 2", ImVec2(450, 530), false);

                        if (ShowChams)
                        {
                            ImGui::Checkbox("Chams Pick", &Pick);

                            ImGui::Checkbox("Chams Starfield", &starfield);

                            ImGui::Checkbox("Chams Ajedrez", &Creeper);

                            ImGui::Checkbox("Chams Matrix", &matrix);

                            ImGui::Checkbox("Chams Spiderman", &Spiderman);

                            ImGui::Checkbox("Chams Galaxy", &galaxy);

                            ImGui::Checkbox("Chams Golden Galaxy", &goldengalaxy);

                            ImGui::Checkbox("Chams Bendi Map", &MapaBendi);

                            ImGui::Checkbox("Chams WireFrame", &Wireframe);

                            ImGui::Checkbox("Chams Legendary", &ChamsLegendario);

                            ImGui::Checkbox("Chams Black Glow", &Black);

                            ImGui::Checkbox("Chams HDR Map", &HdRmap);

                            ImGui::Checkbox("Chams Night Map", &MapaOcuro);
                        }

                        ImGui::EndChild();
                    }
                    if (iTabs == 2)
                    {
                        ImGui::SetCursorPos(ImVec2(80, 80));
                        ImGui::BeginChild("Chams Settings", ImVec2(300, 490), false, ImGuiWindowFlags_NoScrollbar);

                        if (ShowChams)
                        {
                            ImGui::Checkbox("RGB Mode", &Rgb);

                            ImGui::SliderInt("Distance Chams", &countThreshold, 0, 10000, "%d");

                            ImGui::SliderFloat("Width Glow", &lineWidth, 1.f, 10.f, "%.0f");

                            ImGui::SliderFloat("Frequency", &frequency, 1.f, 10.f, "%.1f");

                            ImGui::ColorEdit4("Chams Color", (float*)&blendColor1, picker_flags);

                            ImGui::ColorEdit4("Wukong Color", (float*)&blendColor2, picker_flags);
                        }

                        ImGui::ColorEdit4("Panel Color", (float*)&main_color, picker_flags);

                        ImGui::Checkbox("Disable Particles", &DisableParticles);

                        ImGui::EndChild();
                    }
                }
                if (DisableParticles == true) {
                    Trinage_background();
                }
            }
            move_window();
            ImGui::End();
            RenderBlur(hwnd);
        }
        ImGui::Render();
        const float clear_color_with_alpha[4] = { 0 };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        g_pSwapChain->Present(1, 0);
    }
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return ;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam);
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}

#ifdef _WINDLL

HANDLE hCurrentUIThread = nullptr;
HMODULE hCurrentModule = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved, HMODULE hMod, DWORD reason)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);
        hCurrentModule = hinstDLL;
        hCurrentUIThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Menu_DLL, nullptr, NULL, nullptr);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Fenix_GLS, (LPVOID)hMod, NULL, NULL);
    }

    if (fdwReason == DLL_PROCESS_DETACH)
        TerminateThread(hCurrentUIThread, 0);

    return TRUE;
}

#else

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Menu_DLL();

    return 0;
}

#endif
