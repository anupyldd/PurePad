#pragma once

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
}