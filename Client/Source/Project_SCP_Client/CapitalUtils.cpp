#include "CapitalUtils.h"

FText UCapitalUtils::GetCapitalLetters(const FText& Input)
{
	FString InString = Input.ToString();
	FString Result;

	for (TCHAR Char : InString)
	{
		if (FChar::IsUpper(Char))
		{
			Result.AppendChar(Char);
		}
	}

	return FText::FromString(Result);
}
