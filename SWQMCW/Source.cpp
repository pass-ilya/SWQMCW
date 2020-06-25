#include <iostream>
#include<iomanip>
#include <vector>

using namespace std;

struct tree
{
	int value;
	unsigned char height;
	//int depth; //глубина
	tree* left;
	tree* right;
	tree() { height = 1; value = 0;  left = NULL; right = NULL; }
};


tree* remove(tree* h, int k);
tree* findmin(tree* h);
tree* removemin(tree* h);
tree* rotateright(tree* h);
tree* rotateleft(tree* q);
tree* balance(tree* h);




unsigned char height(tree* p)//высота узла(ячейки)
{
	return p ? p->height : 0;
}

int bfactor(tree* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(tree* p)//
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}



void show(tree* h, int i, bool flag) {
	if (h == NULL)
		return;
	if (flag)
		i += 5;
	show(h->left, i, flag);
	cout << setw(65 - i) << h->value << endl;
	show(h->right, i, flag);
}

void del(tree*& h) {
	if (h != NULL) {
		del(h->left);
		del(h->right);
		delete h;
		h = NULL;
	}
}

//solution of bug duplicate element message
void add(tree*& h, int val) {
	if (h == NULL) {
		tree* head = new tree;
		head->value = val;
		head->right = NULL;
		head->left = NULL;
		h = head;
		// cout << head->value << endl;
		//return;
	}
	if (val < h->value)
		add(h->left, val);
	if (val > h->value)
		add(h->right, val);
	if (val == h->value)//{cout << "Такой элемент уже есть" << endl; return;}
		cout << "Такой элемент уже есть" << endl;

	h = balance(h);
}


void addElem(tree *&head, int quantity, vector<int> elems)
{
	for (int i = 0; i < quantity; i++)
	{
		add(head, elems[i]);
	}
}



void main() {
	setlocale(LC_ALL, "rus");
	tree* head = new tree;
	head = NULL;
	bool flag = true;
	cout << endl;
	while (flag) {
		tree* tmp = new tree;

		int ans;
		cout << "1) Добавить элемент\n"
			<< "2) Удалить элемент\n"
			<< "3) Показать дерево\n"
			<< "4) Балансировка\n"
			<< "5) Выход\n" << endl;
		cin >> ans;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		switch (ans)
		{
		case 1: 
		{
			cout << "Введите количество добавляемых элементов\n";
			int quantity;
			cin >> quantity;
			int numb;
			vector<int> elems;
			for (int i = 0; i < quantity; i++)
			{
				cout << "Введите добавляемое число \n";
				cin >> numb;
				elems.push_back(numb);
			}
			addElem(head, quantity, elems);
			
			
			break;

		}			
		case 2:
			cout << "Введите удаляемое число\n";
			int numb2; 
			cin >> numb2;
			head = remove(head, numb2);
			break;
		case 3:
			if (head)
				show(head, 0, true);
			else
				std::cout << "Дерево пустое " << std::endl;
			break;
		case 4:
			if (head != NULL)
				head = balance(head);
			else cout << "Дерево пустое!";
			break;
		case 5:
			cout << "Выход\n";
			del(head);
			flag = false;
			break;
		default:
			cout << "Введите повторно!\n";
			break;
		}
		delete tmp;
	}


	//system("pause");
	//return EXIT_SUCCESS;
}






tree* balance(tree* p) // балансировка узла p
{
	if (p != NULL) {
		fixheight(p);

		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		if (p->left != NULL) balance(p->left);
		if (p->right != NULL) balance(p->right);
	}

	return p; // балансировка не нужна
}
tree* remove(tree* h, int k) // удаление ключа k из дерева h
{
	if (!h) return NULL;
	if (k < h->value)
		h->left = remove(h->left, k);
	else if (k > h->value)
		h->right = remove(h->right, k);
	else // k == h->key
	{
		tree* q = h->left;
		tree* r = h->right;
		delete h;
		if (!r) return q;
		tree* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(h);
}
tree* rotateright(tree* p) // правый поворот вокруг p
{
	tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}
tree* rotateleft(tree* q) // левый поворот вокруг q
{
	tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

tree* findmin(tree* h) // поиск узла с минимальным значением в дереве h
{
	return h->left ? findmin(h->left) : h;
}
tree* removemin(tree* h) // удаление узла с минимальным значением из дерева h
{
	if (h->left == NULL)
		return h->right;
	h->left = removemin(h->left);
	return balance(h);
} 
