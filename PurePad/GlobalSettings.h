#pragma once

#include "SyntaxHighlighting.h"
#include <unordered_map>

namespace Settings
{
	enum AppTheme
	{
		LIGHT = 0,
		DARK = 1
	};

	enum AppLang
	{
		EN = 0,
		RU = 1
	};

	static AppTheme currentTheme;
	static AppLang currentLanguage;

	static std::unordered_map<int, CodeLang> codePageLang;	// stores lang selection for each code page
}