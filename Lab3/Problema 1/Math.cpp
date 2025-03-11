#pragma warning(disable : 4996)
#include "Math.h"
#include <cstring>
#include <stdarg.h>
int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	int i;
	int val = 0;
	va_list vl;
	va_start(vl, count);
	for (i = 0; i < count; i++)
	{
		val = val + va_arg(vl, int);
	}
	va_end(vl);
	return val;
}
char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	size_t lenc = strlen(a) + strlen(b) + 1;
	char* c = new char[lenc];
	strcpy(c, a);
	strcat(c, b);
	return c;
}
