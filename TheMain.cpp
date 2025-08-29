#include <iostream>
#include <list>

using namespace std;

struct BTree
{
	int data;
	BTree* nextR{ nullptr };
	BTree* nextL{ nullptr };
};

void PrintTree(BTree* p, int depth)
{
	static auto printDepth
	{
		[](int depth)
		{
			for (int i = 0; i < depth; i++)
			{
				printf(" ");
			}
		}
	};

	if (!p)
	{
		return;
	}
	PrintTree(p->nextL, depth + 2);
	printDepth(depth);
	printf("%d\n", p->data);
	PrintTree(p->nextR, depth + 2);
}

int main()
{
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

	t[A] = { 1, &t[B], &t[C] };
	t[B] = { 2, &t[D], &t[E] };
	t[C] = { 3, nullptr, nullptr };
	t[D] = { 4, nullptr, nullptr };
	t[E] = { 5, nullptr, nullptr };

	PrintTree(&t[A], 0);

	return 0;
}