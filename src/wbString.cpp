/**
*  @brief character encoding conversion.
*  @file  wbString.cpp
*  @author loach 
*  @Email < loachmr@sina.com >
*
* Copyright (C) 1996-2010 SINA Corporation, All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*/



#include "wbString.h"
#include "strconv.h"
#include "Urlcode.h"
#include <string.h>
#include <stdlib.h>


#if defined(WIN32) || defined(WINCE)

#if defined(UNICODE) || defined(_UNICODE)

const char* UnicodeToMbcs(const wchar_t *zWide , char** outstr)
{
	char* pout = 0;

	if( lo_W2C(&pout , zWide ) <= 0 )
		return "";

	*outstr = pout;
	return pout;
}

const char* UnicodeToUTF8(const wchar_t *zWide , char** outstr )
{
	char* pout = 0;
	if( lo_W2Utf8(&pout , zWide ) <= 0 )
		return "";

	*outstr = pout;
	return pout;
}

#endif // unicode

const wchar_t* MbcsToUnicode(const char *zinname,wchar_t** outstr)
{
	wchar_t* pout = 0;
	if( lo_C2W(&pout , zinname ) <= 0 )
		return L"";

	*outstr = pout;
	return pout;
}

const char* MbcsToUTF8(const char *zz , char** outstr)
{
	char* pout = 0;
	if( lo_C2Utf8(&pout , zz ) <= 0 )
		return "";

	*outstr = pout ;
	return pout;
}

#else // ! WIN32
// 其它平台

#include "common/bbiconv.h"

const char* MbcsToUTF8(const char *zz , char** outstr)
{
	//
	size_t in_len  = strlen(zz);
	size_t outlen = bbiconv_counts_utf8_2_gbk(zz , in_len);

	//
	char* pout = (char*)malloc( (outlen*sizeof(char)) + sizeof(char) );
	bbiconv_utf8_2_gbk( zz , in_len , pout , outlen);

	//
	*outstr = pout;
	return pout;
}



#endif
