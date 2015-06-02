#include "McCadGeneTool.hxx"

McCadGeneTool::McCadGeneTool()
{
}

TCollection_AsciiString McCadGeneTool::ToAsciiString(const QString& theStr)
{
    char aStr[theStr.length()];
    QByteArray ba = theStr.toAscii();
    strcpy(aStr, ba.data());
    TCollection_AsciiString anAsciiStr(aStr);
    return anAsciiStr;
}
