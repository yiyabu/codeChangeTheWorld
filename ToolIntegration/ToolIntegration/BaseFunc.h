#ifndef _BASE_FUNC_H_
#define _BASE_FUNC_H_

// ´íÎóÂë
#define ERR_OK				0x00000000
#define ERR_DATA_FORMAT		0xA0000001
#define ERR_DATA_LEN		0xA0000002
#define ERR_FILE_OPEN		0xA0000003


#ifdef __cplusplus

extern "C"
{
	void Unicode2Ascii(const wchar_t* pwszData, char* pszData, int* pnSize);
	void Ascii2Unicode(const char* pszData, wchar_t* pwszData,  int* pnSize);
	DWORD Hex2String(const char* pszHexStr, char* pszStr, int nSize);
	void String2Hex(const char* pszStr, char* pszHexStr, int nSize);
	void HexStr2HexMem(const char* pszStr, char* pHexMem, int nSize);

	DWORD WideHex2String(const wchar_t* pwszWideHexStr, char* pszStr, int* pnSize);
	void WideString2Hex(const wchar_t* pwszStr, char* pszHexStr, int* pnSize);
	DWORD ToUpper(wchar_t* pwszStr);
	DWORD ToLower(wchar_t* pwszStr);
	DWORD Base64_Encode(wchar_t* pwszInput, char* pOutput, int* pOutputLen);
	DWORD Base64_Decode(wchar_t* pwszInput, char* pOutput, int* pOutputLen);
	DWORD SaveToBinaryFile(wchar_t* pwszData, wchar_t* pwszFilePath);
};


#endif // __cplusplus

#endif //_BASE_FUNC_H_



