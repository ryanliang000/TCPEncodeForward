#pragma once
#include "qstring.h"
class CTextHexDecode
{
public:
    CTextHexDecode(void);
    ~CTextHexDecode(void);
public:
    static QString textToAnsiHex(QString sText);
    static QString textToUtf8Hex(QString sText);
    static QString textToUnicodeHex(QString sText);

    static QString ansiHexToText(QString sHexText);
    static QString utf8HexToText(QString sHexText);
    static QString unioceHexToText(QString sHexText);

	static QByteArray utf8HexToByteArray(QString sHexText);
public:
    // char/w_char to hex
    static QString convertWCharToHex(wchar_t ch);
    static QString convertCharToHex(char ch);
    static QString byteArrayToHex(const QByteArray& bytArray);
    static QString wstringToHex(const std::wstring& str);


    // hex to char/w_char
    static wchar_t convertHexToWChar(char ch1, char ch2, char ch3, char ch4);
    static unsigned char convertHexToChar(char ch1, char ch2);
};

