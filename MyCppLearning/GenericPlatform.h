#pragma once

/**
* Generic types for almost all compilersand platforms
**/

struct FGenericPlatformTypes
{
	//~ Unsigned base types

	// 8-bit unsigned integer
	typedef unsigned char 		uint8;

	// 16-bit unsigned integer
	typedef unsigned short int	uint16;

	// 32-bit unsigned integer
	typedef unsigned int		uint32;

	// 64-bit unsigned integer
	typedef unsigned long long	uint64;

	//~ Signed base types.

	// 8-bit signed integer
	typedef	signed char			int8;

	// 16-bit signed integer
	typedef signed short int	int16;

	// 32-bit signed integer
	typedef signed int	 		int32;

	// 64-bit signed integer
	typedef signed long long	int64;

	//~ Character types

	// An ANSI character. 8-bit fixed-width representation of 7-bit characters.
	typedef char				ANSICHAR;

	// A wide character. In-memory only. ?-bit fixed-width representation of the platform's natural wide character set. Could be different sizes on different platforms.
	typedef wchar_t				WIDECHAR;

	// An 8-bit character type. In-memory only. 8-bit representation. Should really be char8_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
	typedef uint8				CHAR8;

	// A 16-bit character type. In-memory only.  16-bit representation. Should really be char16_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
	typedef uint16				CHAR16;

	// A 32-bit character type. In-memory only. 32-bit representation. Should really be char32_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
	typedef uint32				CHAR32;

	// A switchable character. In-memory only. Either ANSICHAR or WIDECHAR, depending on a licensee's requirements.
	typedef WIDECHAR			TCHAR;

	// Unsigned int. The same size as a pointer.
	//typedef SelectIntPointerType<uint32, uint64, sizeof(void*)>::TIntPointer UPTRINT;

	// Signed int. The same size as a pointer.
	//typedef SelectIntPointerType<int32, int64, sizeof(void*)>::TIntPointer PTRINT;

	// Unsigned int. The same size as a pointer.
	//typedef UPTRINT SIZE_T;

	// Signed int. The same size as a pointer.
	//typedef PTRINT SSIZE_T;

	typedef int32					TYPE_OF_NULL;
	typedef decltype(nullptr)		TYPE_OF_NULLPTR;
};

typedef FGenericPlatformTypes::uint8		uint8;
/// A 16-bit unsigned integer.
typedef FGenericPlatformTypes::uint16		uint16;
/// A 32-bit unsigned integer.
typedef FGenericPlatformTypes::uint32		uint32;
/// A 64-bit unsigned integer.
typedef FGenericPlatformTypes::uint64		uint64;

//~ Signed base types.
/// An 8-bit signed integer.
typedef	FGenericPlatformTypes::int8		int8;
/// A 16-bit signed integer.
typedef FGenericPlatformTypes::int16		int16;
/// A 32-bit signed integer.
typedef FGenericPlatformTypes::int32		int32;
/// A 64-bit signed integer.
typedef FGenericPlatformTypes::int64		int64;

//~ Character types.
/// An ANSI character. Normally a signed type.
typedef FGenericPlatformTypes::ANSICHAR	ANSICHAR;
/// A wide character. Normally a signed type.
typedef FGenericPlatformTypes::WIDECHAR	WIDECHAR;
/// Either ANSICHAR or WIDECHAR, depending on whether the platform supports wide characters or the requirements of the licensee.
typedef FGenericPlatformTypes::TCHAR		TCHAR;
/// An 8-bit character containing a UTF8 (Unicode, 8-bit, variable-width) code unit.
typedef FGenericPlatformTypes::CHAR8		UTF8CHAR;
/// A 16-bit character containing a UCS2 (Unicode, 16-bit, fixed-width) code unit, used for compatibility with 'Windows TCHAR' across multiple platforms.
typedef FGenericPlatformTypes::CHAR16		UCS2CHAR;
/// A 16-bit character containing a UTF16 (Unicode, 16-bit, variable-width) code unit.
typedef FGenericPlatformTypes::CHAR16		UTF16CHAR;
/// A 32-bit character containing a UTF32 (Unicode, 32-bit, fixed-width) code unit.
typedef FGenericPlatformTypes::CHAR32		UTF32CHAR;
/// The type of the NULL constant.
typedef FGenericPlatformTypes::TYPE_OF_NULL	TYPE_OF_NULL;
/// The type of the C++ nullptr keyword.
typedef FGenericPlatformTypes::TYPE_OF_NULLPTR	TYPE_OF_NULLPTR;