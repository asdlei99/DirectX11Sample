/* 
 * Copyright (C) 2012 Yee Young Han <websearch@naver.com> (http://blog.naver.com/websearch)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#pragma once

#include <windows.h>
#include <string>

extern HRESULT giErrCode;
extern std::wstring gstrErrFunc;
extern std::wstring gstrErrFile;
extern int giErrLine;
extern TCHAR gszErrMsg[1024];

#define CHECK_FAILED(x)    \
{                          \
	HRESULT hrt = (x);       \
	if( FAILED(hrt) )        \
	{                        \
		WCHAR szBuf[512];      \
		MultiByteToWideChar( CP_ACP, 0, __FILE__, -1, szBuf, 512 ); \
		giErrCode = hrt;      \
		gstrErrFunc = L#x;    \
		gstrErrFile = szBuf;  \
		giErrLine = __LINE__; \
		return false;          \
	}                        \
}

const TCHAR * GetErrString();
