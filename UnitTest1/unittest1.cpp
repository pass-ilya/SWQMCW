#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SWQMCW/Source.cpp"
const int n1 = 1;
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace BlackBox
{
	void equalTree(tree* h1, tree* h2) {
		if (h1 == NULL && h2 == NULL)
		{
			return;
		}

		equalTree(h1->left, h2->left);
		Assert::AreEqual(h1->value, h2->value);
		equalTree(h1->right, h2->right);
	}


	void addTest(tree*& h, int val) {
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
			addTest(h->left, val);
		if (val > h->value)
			addTest(h->right, val);
		if (val == h->value)
			cout << "Такой элемент уже есть" << endl;

		//h = balance(h);
	}


	TEST_CLASS(BlackBox)
	{
	public:

		TEST_METHOD(TwoElem)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;

			add(head1, 2);
			add(head1, 3);



			addTest(head2, 2);
			addTest(head2, 3);

			equalTree(head1, head2);


			Assert::AreEqual(head1->value, head2->value);
		}

		TEST_METHOD(LineBalance)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;

			add(head1, 2);
			add(head1, 3);
			add(head1, 1);


			addTest(head2, 2);
			addTest(head2, 3);
			addTest(head2, 1);

			equalTree(head1, head2);


			Assert::AreEqual(head1->value, head2->value);
		}

		TEST_METHOD(BalanceNullTree)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;


			balance(NULL);

			equalTree(head1, head2);

		}

		TEST_METHOD(TypicalBalance)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;

			add(head1, 2);
			add(head1, 3);
			add(head1, 1);
			add(head1, 5);
			add(head1, 6);
			add(head1, 7);



			addTest(head2, 5);
			addTest(head2, 2);
			addTest(head2, 3);
			addTest(head2, 1);
			addTest(head2, 6);
			addTest(head2, 7);

			equalTree(head1, head2);


			Assert::AreEqual(head1->value, head2->value);
		}

	};
}

namespace WhiteBox
{
	void equalTree(tree* h1, tree* h2) {
		if (h1 == NULL && h2 == NULL)
		{
			return;
		}

		equalTree(h1->left, h2->left);
		Assert::AreEqual(h1->value, h2->value);
		equalTree(h1->right, h2->right);
	}


	void addTest(tree*& h, int val) {
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
			addTest(h->left, val);
		if (val > h->value)
			addTest(h->right, val);
		if (val == h->value)
			cout << "Такой элемент уже есть" << endl;

		//h = balance(h);
	}



	TEST_CLASS(WhiteBox)
	{
	public:


		TEST_METHOD(NullTree)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;


			balance(NULL);

			equalTree(head1, head2);

		}

		TEST_METHOD(BalanceLRSubTree)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;

			add(head1, 7);
			add(head1, 15);
			add(head1, 14);
			add(head1, 5);
			add(head1, 6);



			addTest(head2, 14);
			addTest(head2, 15);
			addTest(head2, 6);
			addTest(head2, 5);
			addTest(head2, 7);



			equalTree(head1, head2);


			Assert::AreEqual(head1->value, head2->value);
		}

		TEST_METHOD(BalanceAbove)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;


			add(head1, 5);
			add(head1, 6);
			add(head1, 7);
			add(head1, 8);
			add(head1, 9);
			add(head1, 4);

			//5,6,7,8,9,4


			addTest(head2, 6);
			addTest(head2, 5);
			addTest(head2, 4);
			addTest(head2, 8);
			addTest(head2, 7);
			addTest(head2, 9);



			equalTree(head1, head2);


			Assert::AreEqual(head1->value, head2->value);
		}


	};
}

namespace ImplementTests {

	void equalTree(tree* h1, tree* h2) {
		if (h1 == NULL && h2 == NULL)
		{
			return;
		}

		equalTree(h1->left, h2->left);
		Assert::AreEqual(h1->value, h2->value);
		equalTree(h1->right, h2->right);
	}


	int NodeCount(tree* node)
	{
		if (node->left == NULL && node->right == NULL)
			return 1;
		int left, right;
		if (node->left != NULL)
			left = NodeCount(node->left);
		else
			left = 0;
		if (node->right != NULL)
			right = NodeCount(node->right);
		else
			right = 0;

		return left + right + 1;
	}


	TEST_CLASS(NewTests)
	{
	public:

		TEST_METHOD(CheckAddSomeElements)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;
			vector<int> elems;

			add(head1, 2);
			add(head1, 3);
			add(head1, 1);
			add(head1, 5);
			add(head1, 6);
			add(head1, 7);

			elems.push_back(2);
			elems.push_back(3);
			elems.push_back(1);
			elems.push_back(5);
			elems.push_back(6);
			elems.push_back(7);


			addElem(head2, 6, elems);

			equalTree(head1, head2);


			Assert::AreEqual(head1->value, head2->value);
			
		}


		TEST_METHOD(CheckAddQuantityElements)
		{
			struct tree* head1 = new tree;
			head1 = NULL;
			struct tree* head2 = new tree;
			head2 = NULL;
			vector<int> elems;

			elems.push_back(2);
			elems.push_back(3);
			elems.push_back(1);
			elems.push_back(5);
			elems.push_back(6);
			elems.push_back(7);


			addElem(head2, 6, elems);


			Assert::AreEqual((int)elems.size(), NodeCount(head2));
		}


		TEST_METHOD(DelFromNullTree)
		{
			struct tree* head1 = new tree;
			head1 = NULL;

			Assert::IsNull(remove(head1, 11));
		}



	
	};

}