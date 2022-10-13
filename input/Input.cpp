#include "Input.h"

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

Input* Input::GetInstacne()
{
    static Input instacne;

    return &instacne;
}

void Input::Initialize(WinApp* winApp)
{

    HRESULT result;

    this->winApp = winApp;

    //DirectInputのインスタンス生成
    result = DirectInput8Create(winApp->GetHInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, nullptr);

    //キーボードデバイス生成
    result = dinput->CreateDevice(GUID_SysKeyboard, &devkeyboard, NULL);

    //入力データ形式のセット
    result = devkeyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式

    //排他的制御レベルのセット
    result = devkeyboard->SetCooperativeLevel(winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
}

void Input::Updata()
{

    HRESULT result;

    //前回のキー入力を保存
    memcpy(keyPre, key, sizeof(key));

    //キーボード情報の取得開始
    result = devkeyboard->Acquire();

    //全キーの入力情報を取得する
    result = devkeyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
    //指定キーを押していればtrueを返す
    if (key[keyNumber])
    {
        return true;
    }

    //そうでなければfalseを返す
    return false;
}

bool Input::Triggerkey(BYTE keyNumber)
{
    //指定キーを押していればtrueを返す
    if (key[keyNumber] && !keyPre[keyNumber])
    {
        return true;
    }

    //そうでなければfalseを返す
    return false;
}
