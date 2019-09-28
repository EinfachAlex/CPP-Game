#pragma once

#include "wtypes.h"

RECT getDesktopResolution()
{
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow();

	GetWindowRect(hDesktop, &desktop);

	return desktop;
}