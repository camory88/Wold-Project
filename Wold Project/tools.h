#pragma once
#include <Windows.h>

bool getKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000) != 0;
}
