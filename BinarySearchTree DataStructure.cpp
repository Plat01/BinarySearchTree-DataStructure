

#include <iostream>
#include <locale.h>
#include <iomanip>
#include <vector>
using namespace std;

struct TreeNode
{
	int info;
	TreeNode* left, * right;
};

struct Way
{
	vector<int> nodes;
	int length;
};

// Прототипы функций
void makeTree(TreeNode*& root);
void insertNode(TreeNode*& root, int k);
void printTree(TreeNode*& root, const int level);

bool isMirror(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL) return true;
	if (left != NULL && right != NULL) return (isMirror(left->left, right->right) && isMirror(left->right, right->left));
	return  false;
}


int main() {
	setlocale(LC_ALL, "Russian");

	TreeNode* root = NULL;
	makeTree(root);

	cout << "Tree:" << endl;
	printTree(root, 0);

	if (isMirror(root->left, root->right))
		cout << "This tree is symmetrically";
	else
		cout << "This tree is not symmetrically";
	

	system("pause");
	return 0;
}

// Вставка в дерево с корнем root новой вершины с ключом k
// В случае совпадения ключа операция отклюняется
void insertNode(TreeNode*& root, int k)
{
	if (root == NULL)
	{
		root = new TreeNode;
		root->info = k;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (k < root->info)
			insertNode(root->left, k);
		else
			if (k > root->info)
				insertNode(root->right, k);
			else
				cout << "Duplicate number!" << endl;
	}
	return;
}

// Формирование БДП с корнем root по входной последовательности
// целых чисел
void makeTree(TreeNode*& root)
{
	int k;
	cout << "Input numbers for 0" << endl;
	cin >> k;
	while (k)
	{
		insertNode(root, k);
		cin >> k;
	}
	return;
}

// Вывод бинарного дерева на консоль
void printTree(TreeNode*& root, const int level)
{
	if (root)
	{
		printTree(root->left, level + 1);
		cout << setw(4 * level) << "" << root->info << endl;
		printTree(root->right, level + 1);
	}
	return;
}
