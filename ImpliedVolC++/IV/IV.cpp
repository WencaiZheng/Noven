// IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class F1
{
public:
	double Value(double x) { return x * x - 2; }
	double Deriv(double x) { return 2 * x; }
};
class F2
{
private:
	double a; //parameter
public:
	F2(double a_) { a = a_; }
	double Value(double x) { return x * x - a; }
	double Deriv(double x) { return 2 * x; }
};
int main()
{
	F1 MyF1;
	F2 MyF2(3.0);
	double Acc = 0.001;
	double LEnd = 0.0, REnd = 2.0;
	double Tgt = 0.0;
	cout << "Root of F1 by bisect: " << SolveByBisect<F1>(&MyF1, Tgt, LEnd, REnd, Acc) << endl;
	cout << "Root of F2 by bisect: " << SolveByBisect<F2>(&MyF2, Tgt, LEnd, REnd, Acc) << endl;
	double Guess = 1.0;
	cout << "Root of F1 by Newton-Raphson: " << SolveByNR<F1>(&MyF1,Tgt,Guess,Acc)
		<< endl;
	cout << "Root of F2 by Newton-Raphson: " << SolveByNR<F2>(&MyF2,Tgt,Guess,Acc)
		<< endl;
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
