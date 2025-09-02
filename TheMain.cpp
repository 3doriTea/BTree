#include <iostream>
#include <list>

using namespace std;

/// <summary>
/// 2分木の要素を表す構造体
/// </summary>
struct BTree
{
	int data;
	BTree* nextR{ nullptr };
	BTree* nextL{ nullptr };
};

/// <summary>
/// 2分木の子を構造的に表示する関数
/// </summary>
/// <param name="p">子を表示したい親のポインタ</param>
/// <param name="depth">深さ</param>
static void PrintTree(BTree* p, int depth = 0)
{
	static auto printDepth
	{
		[](int depth)
		{
			for (int i = 0; i < depth; i++)
			{
				printf("-");
			}
		}
	};

	if (!p)
	{
		return;
	}
	PrintTree(p->nextL, depth + 2);
	printDepth(depth);
	printf("%c\n", 'A' + p->data);
	PrintTree(p->nextR, depth + 2);
}

int main()
{
#pragma region 授業内で出てきた2分木を保存
	enum NAME
	{
		A,
		B,
		C,
		D,
		E,
		MAX
	};

	BTree t[NAME::MAX]{};

	t[A] = { A, &t[B], &t[C] };
	t[B] = { B, &t[D], &t[E] };
	t[C] = { C, nullptr, nullptr };
	t[D] = { D, nullptr, nullptr };
	t[E] = { E, nullptr, nullptr };
#pragma endregion

	PrintTree(&t[A]);  // 表示！

	return 0;
}