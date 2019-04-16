#include "StdAfx.h"
#include "BaseFunc.h"
#include <ctype.h>
#include "b64.h"


void HexStr2HexMem(const char* pszStr, char* pHexMem, int nSize)
{
	char ch;
	char chTemp;
	char* pszTemp = (char*)pszStr;
	int i=0;
	int nCount = 0;
	if ( strlen(pszStr) > nSize*2 )
	{
		return;
	}
	while( *pszTemp )
	{
		if ( *pszTemp >= '0' && *pszTemp <= '9' )
		{
			chTemp = *pszTemp - '0';
		}else if ( *pszTemp >= 'A' && *pszTemp <= 'Z' )
		{
			chTemp = *pszTemp - 'A'+10;
		}else if ( *pszTemp >= 'a' && *pszTemp <= 'z' )
		{
			chTemp = *pszTemp - 'a'+10;
		}else
		{
			break;
		}

		if ( i==0 )
		{
			ch = chTemp;
			i++;
		}
		else
		{
			ch = (ch<<4) | chTemp;
			pHexMem[nCount] = ch;
			i=0;
			nCount++;
		}
		pszTemp++;
	}
}

void String2Hex(const char* pszStr, char* pszHexStr, int nSize)
{
	const char szData[] = "0123456789ABCDEF";
	unsigned char chHigh;
	unsigned char chLow;
	int nSizeTemp = 0;

	if ( nSize <= strlen(pszStr)*2   )
	{
		return;
	}
	char* pszTemp = (char*)pszStr;
	while ( *pszTemp )
	{
		chLow = *pszTemp & 0x0F;
		chHigh = (*pszTemp>>4) & 0x0F;
		pszHexStr[nSizeTemp] = szData[chHigh];
		pszHexStr[nSizeTemp+1] = szData[chLow];
		nSizeTemp += 2;
		pszTemp++;
	}
	pszHexStr[nSizeTemp] = '\0';
}

void WideString2Hex(const wchar_t* pwszStr, char* pszHexStr, int* pnSize)
{
	char* pszData = NULL;
	int nSizeTemp = 0;
	do 
	{
		Unicode2Ascii(pwszStr, pszData, &nSizeTemp);
		pszData = new char[nSizeTemp+1];
		if ( !pszData )
		{
			break;
		}
		Unicode2Ascii(pwszStr, pszData, &nSizeTemp);

		if ( !pszHexStr )
		{
			break;
		}
		if ( *pnSize < (nSizeTemp+1)*2 )
		{
			break;
		}
		String2Hex(pszData, pszHexStr, (nSizeTemp+1)*2);
	} while (false);

	*pnSize = (nSizeTemp+1)*2;
	delete [] pszData;
	pszData = NULL;
}

DWORD WideHex2String(const wchar_t* pwszWideHexStr, char* pszStr, int* pnSize)
{
	DWORD dwRet = ERR_OK;
	char* pszData = NULL;
	int nSizeTemp = 0;
	do 
	{
		Unicode2Ascii(pwszWideHexStr, pszData, &nSizeTemp);
		pszData = new char[nSizeTemp+1];
		if ( !pszData )
		{
			break;
		}
		Unicode2Ascii(pwszWideHexStr, pszData, &nSizeTemp);

		if ( !pszStr )
		{
			break;
		}
		if ( *pnSize < (nSizeTemp+1)*2 )
		{
			break;
		}
		dwRet = Hex2String(pszData, pszStr, (nSizeTemp+1)*2);
	} while (false);

	*pnSize = (nSizeTemp+1)*2;
	delete [] pszData;
	pszData = NULL;

	return dwRet;
}

bool IsHexString(const char* pszHexStr)
{
	bool bRet = true;
	int nLen = strlen(pszHexStr);
	if ( nLen%2 != 0 )
	{
		return false;
	}
	for ( int nIndex = 0; nIndex < nLen; nIndex++ )
	{
		if ( pszHexStr[nIndex] < '0' || (pszHexStr[nIndex] > '9' && pszHexStr[nIndex] < 'A') || (pszHexStr[nIndex] > 'Z' && pszHexStr[nIndex] < 'a' ) || pszHexStr[nIndex] > 'z' )
		{
			bRet = false;
			break;
		}
	}
	return bRet;
}

DWORD Hex2String(const char* pszHexStr, char* pszStr, int nSize)
{
	unsigned char chTemp = 0;
	unsigned char chData = 0;
	char* pszTemp = (char*)pszHexStr;
	int nSizeTemp = 0;

	if ( strlen(pszHexStr)/2 >= nSize )
	{
		return  ERR_DATA_LEN;
	}
	if ( !IsHexString(pszHexStr) )
	{
		return ERR_DATA_FORMAT;
	}
	int i = 0;
	while ( *pszTemp )
	{
		if ( *pszTemp >= '0' && *pszTemp <= '9' )
		{
			chTemp = *pszTemp - '0';
		}else if ( *pszTemp >= 'A' && *pszTemp <= 'Z' )
		{
			chTemp = *pszTemp - 'A' + 10;
		}else if ( *pszTemp >= 'a' && *pszTemp <= 'z')
		{
			chTemp = *pszTemp - 'a' + 10;
		}else
		{
			break;
		}

		if ( i == 0 )
		{
			chData = chTemp;
			i++;
		}
		else
		{
			chData = (chData<<4) | chTemp;
			pszStr[nSizeTemp] = chData;
			nSizeTemp++;
			i=0;
			chData = 0;
			chTemp = 0;
		}
		pszTemp++;
	}
	pszStr[nSizeTemp] = '\0';
	
	return ERR_OK;
}

void Unicode2Ascii(const wchar_t* pwszData, char* pszData, int* pnSize)
{
	int nSize = WideCharToMultiByte(CP_ACP, 0, pwszData, -1, NULL, 0, NULL, NULL);
	if ( pszData )
	{
		if ( *pnSize < nSize )
		{
			return;
		}
		WideCharToMultiByte(CP_ACP, 0, pwszData, -1, pszData, nSize, NULL, NULL);
	}
	*pnSize = nSize;
}

void Ascii2Unicode(const char* pszData, wchar_t* pwszData, int* pnSize)
{
	int nSize = MultiByteToWideChar(CP_ACP, 0, pszData, -1, NULL, 0);
	if ( pszData )
	{
		if ( *pnSize < nSize )
		{
			return;
		}
		MultiByteToWideChar(CP_ACP, 0, pszData, -1, NULL, 0);
	}
	*pnSize = nSize;
}

DWORD ToUpper(wchar_t* pwszStr)
{
	int nLen = wcslen(pwszStr);
	char chTemp = 0;
	for ( int nIndex = 0; nIndex < nLen; nIndex++ )
	{
		chTemp = toupper(pwszStr[nIndex]);
		pwszStr[nIndex] = chTemp;
	}
	return 0;
}

DWORD ToLower(wchar_t* pwszStr)
{
	int nLen = wcslen(pwszStr);
	char chTemp = 0;
	for ( int nIndex = 0; nIndex < nLen; nIndex++ )
	{
		chTemp = tolower(pwszStr[nIndex]);
		pwszStr[nIndex] = chTemp;
	}
	return 0;
}

DWORD Base64_Encode(wchar_t* pwszInput, char* pOutput, int* pOutputLen)
{
	DWORD dwRet = ERR_OK;
	int Len = WideCharToMultiByte(CP_ACP, 0, pwszInput, -1, NULL, 0, NULL, NULL);
	char* pszData = new char[Len];
	memset(pszData, 0, Len);
	WideCharToMultiByte(CP_ACP, 0, pwszInput, -1, pszData, Len, NULL, NULL);

	char* pszOutput = (char*)b64_encode((const unsigned char*)pszData, Len-1);
	int OutputLen = strlen(pszOutput);
	do 
	{
		if ( pOutput )
		{
			if ( strlen(pszOutput) > *pOutput )
			{
				dwRet = ERR_DATA_LEN;
				break;
			}
			memcpy(pOutput, pszOutput, OutputLen);
			*(pOutput+OutputLen) = '\0';
		}
		*pOutputLen = OutputLen+1;
	} while (false);
	
	if ( pszOutput )
	{
		free(pszOutput);
		pszOutput = NULL;
	}
	delete []pszData;
	pszData = NULL;
	return dwRet;
}

DWORD Base64_Decode(wchar_t* pwszInput, char* pOutput, int* pOutputLen)
{
	DWORD dwRet = ERR_OK;
	int Len = WideCharToMultiByte(CP_ACP, 0, pwszInput, -1, NULL, 0, NULL, NULL);
	char* pszData = new char[Len];
	memset(pszData, 0, Len);
	WideCharToMultiByte(CP_ACP, 0, pwszInput, -1, pszData, Len, NULL, NULL);

	char* pszOutput = (char*)b64_decode((const char*)pszData, Len-1);
	int OutputLen = strlen(pszOutput);
	do 
	{
		if ( pOutput )
		{
			if ( strlen(pszOutput) > *pOutput )
			{
				dwRet = ERR_DATA_LEN;
				break;
			}
			memcpy(pOutput, pszOutput, OutputLen);
			*(pOutput+OutputLen) = '\0';
		}
		*pOutputLen = OutputLen+1;
	} while (false);

	if ( pszOutput )
	{
		free(pszOutput);
		pszOutput = NULL;
	}
	delete []pszData;
	pszData = NULL;
	return dwRet;
}

DWORD SaveToBinaryFile(wchar_t* pwszData, wchar_t* pwszFilePath)
{
	DWORD dwRet = ERR_OK;
	int Len = WideCharToMultiByte(CP_ACP, 0, pwszData, -1, NULL, 0, NULL, NULL);
	char* pszData = new char[Len];
	memset(pszData, 0, Len);
	WideCharToMultiByte(CP_ACP, 0, pwszData, -1, pszData, Len, NULL, NULL);
	char szFilePath[MAX_PATH] = {0};
	WideCharToMultiByte(CP_ACP, 0, pwszFilePath, -1, szFilePath, MAX_PATH, NULL, NULL);
	do 
	{
		if ( !IsHexString(pszData) )
		{
			dwRet = ERR_DATA_FORMAT;
			break;
		}
		char* pHexMem = new char[Len/2+1];
		HexStr2HexMem(pszData, pHexMem, Len/2+1);
		FILE* fp = NULL;
		fp = fopen(szFilePath, "wb+");
		if ( !fp )
		{
			dwRet = ERR_FILE_OPEN;
			break;
		}
		fwrite(pHexMem, 1, Len/2+1, fp);
		fclose(fp);

	} while (false);
	
	delete []pszData;
	pszData = NULL;
	return dwRet;
}