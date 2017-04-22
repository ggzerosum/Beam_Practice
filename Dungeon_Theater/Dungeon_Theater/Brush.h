#pragma once

namespace myNameSpace
{
	class Brush
	{
	private:
		HBRUSH handle;

	private: //����, ���� ������ ����
		Brush(Brush &ref);
		void operator=(Brush &ref);

	public:
		Brush(COLORREF color);
		~Brush();

	public:
		HBRUSH getHandle();
	};
}