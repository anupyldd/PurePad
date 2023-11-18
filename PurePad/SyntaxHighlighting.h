#pragma once

#include "wx/wx.h"

enum CodeLang
{
	CPP = 0,
	PYTHON = 1,
	JAVA = 2,
	JS = 3
};

namespace Keywords
{
	static CodeLang currentCodeLang;

	static wxString cpp("alignas alignof and and_eq asm atomic_cancel atomic_commit atomic_noexcept auto bitand bitor break case catch class compl concept const consteval constexpr constinit const_cast continue co_await co_return co_yield decltype default delete do dynamic_cast else enum explicit export extern false for friend goto if inline mutable namespace new noexcept not not_eq nullptr operator or or_eq private protected public reflexpr register reinterpret_cast requires return sizeof static static_assert static_cast struct switch synchronized template this thread_local throw true try typedef typeid typename union using virtual volatile while xor xor_eq");
	static wxString cpp2("const signed unsigned int float void char double bool char8_t char16_t char32_t wchar_t");

	static wxString python("False None True and as assert async await break class continue def del elif else except finally for from global if import in is lambda nonlocal not or pass raise return try while with yield");

	static wxString java("abstract assert break case catch class continue default do else enum extends final finally for if implements import instanceof interface native new null package private protected public return static strictfp super switch synchronized this throw throws transient try void volatile while");
	static wxString java2("boolean byte char double float int long short");

	static wxString javaScript("abstract arguments await break case catch class const continue debugger default delete do else enum eval export extends false final finally for function goto if implements import in instanceof interface let long native new null package private protected public return short static super switch synchronized this throw throws transient true try typeof var volatile while with yield");
	static wxString javaScript2("boolean byte char double float int void");
}