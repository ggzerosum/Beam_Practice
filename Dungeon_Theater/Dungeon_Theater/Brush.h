#pragma once

namespace myNameSpace
{
	class Brush
	{
	private:
		HBRUSH handle;

	private: //복사, 대입 연산자 금지
		Brush(Brush &ref);
		void operator=(Brush &ref);

	public:
		Brush(COLORREF color);
		~Brush();

	public:
		HBRUSH getHandle();
	};
}