#include "stdafx.h"
#include "StringUtilities.h"
#include <algorithm>
#include <list>
#include <sstream>

list<wstring> StringUtilities::Split(const wstring& str, const wstring& separator)
{
	list<wstring> strs;
	auto separatorSize = separator.size();
	size_t start = 0;
	size_t pos;
	while ((pos = str.find(separator, start)) != wstring::npos)
	{
		strs.push_back(str.substr(start, pos - start - separatorSize));
		start = pos + separatorSize;		
	}

	pos = str.size() - separatorSize;
	if (start < pos)
	{
		strs.push_back(str.substr(start, pos));
	}

	return strs;
}

wstring StringUtilities::Convert(const wstring& str, int(*const converter)(int))
{
	wstring convertedStr;
	convertedStr.resize(str.size());
	transform(str.begin(), str.end(), convertedStr.begin(), converter);
	return convertedStr;
}

wstring StringUtilities::Join(const list<wstring> strings, const wstring& separator)
{
	wstringstream result;
	auto first = true;
	for (auto stringIterator = strings.begin(); stringIterator != strings.end(); ++stringIterator)
	{
		if (first)
		{
			first = false;
		}
		else
		{
			result << separator;
		}
		
		result << *stringIterator;		
	}

	return result.str();
}

wstring StringUtilities::Replace(const wstring& strSource, const wstring& replaceFrom, const wstring& replaceTo)
{
	if(strSource.size() == 0 || replaceFrom.size() == 0 || replaceTo.size() == 0)
	{
		return strSource;
	}

	size_t posn;
	auto result = strSource;
	while (std::wstring::npos != (posn = result.find(replaceFrom)))
	{
		result.replace(posn, replaceFrom.length(), replaceTo);
	}

	return result;
}
