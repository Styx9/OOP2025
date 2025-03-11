#include "Canvas.h"
#include <iostream>
#include <cmath>
using namespace std;

Canvas::Canvas(int width, int height) : width(width), height(height) {
	matrix = new char* [height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new char[width];
	}
	Clear();
}
void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}
void Canvas :: Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << matrix[i][j];
		cout << endl;
	}
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		matrix[y][x] = ch;
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int d = (i - y) * (i - y) + (j - x) * (j - x);
			if (d >= ray * (ray - 1) && d <= ray * (ray + 1)) {
				SetPoint(j, i, ch);
			}
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if ((i - y) * (i - y) + (j - x) * (j - x) <= ray * ray)		
				SetPoint(j, i, ch);
		}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int i = top; i <= bottom; i++)
	{
		SetPoint(left, i, ch);
		SetPoint(right, i, ch);
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
		{
			SetPoint(j, i, ch);
		}
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}