/****************
 *              *
 *  线索二叉树  *
 *              *
 ****************/
#include <iostream>
using namespace std;

struct TBTNode
{
	int data;
	int lTag;
	int rTag;
	TBTNode *lChild;
	TBTNode *rChild;
};

void visit(TBTNode *p);
void testTBTree(TBTNode *root);
void preThread(TBTNode *p, TBTNode *&pre);//先序线索化
void inThread(TBTNode *p, TBTNode *&pre);//中序线索化
void postThread(TBTNode *p, TBTNode *&pre);//后序线索化
void preOrder(TBTNode *tbt);//遍历先序线索二叉树
void inOrder(TBTNode *tbt);//遍历中序线索二叉树
void postOrder(TBTNode *tbt);//遍历后序线索二叉树

int main()
{
	TBTNode root, *pre = NULL;
	testTBTree(&root);
	preThread(&root, pre);
	preOrder(&root);
	cout << endl;
	return 0;
}

void visit(TBTNode *p)
{
	cout << p->data << " -> ";
}

void testTBTree(TBTNode *root)
{
	root->data = 1;
	root->lChild = NULL;
	root->rChild = NULL;
	root->lTag = root->rTag = 0;
	TBTNode *newp1 = new TBTNode();
	newp1->data = 2;
	newp1->lChild = NULL;
	newp1->rChild = NULL;
	newp1->lTag = newp1->rTag = 0;
	root->lChild = newp1;
	TBTNode *newp2 = new TBTNode();
	newp2->data = 3;
	newp2->lChild = NULL;
	newp2->rChild = NULL;
	newp2->lTag = newp2->rTag = 0;
	root->rChild = newp2;
	TBTNode *newp3 = new TBTNode();
	newp3->data = 4;
	newp3->lChild = NULL;
	newp3->rChild = NULL;
	newp3->lTag = newp3->rTag = 0;
	newp1->lChild = newp3;
	TBTNode *newp4 = new TBTNode();
	newp4->data = 5;
	newp4->lChild = NULL;
	newp4->rChild = NULL;
	newp4->lTag = newp4->rTag = 0;
	newp1->rChild = newp4;
	TBTNode *newp5 = new TBTNode();
	newp5->data = 6;
	newp5->lChild = NULL;
	newp5->rChild = NULL;
	newp5->lTag = newp5->rTag = 0;
	newp2->lChild = newp5;
	TBTNode *newp6 = new TBTNode();
	newp6->data = 7;
	newp6->lChild = NULL;
	newp6->rChild = NULL;
	newp6->lTag = newp6->rTag = 0;
	newp2->rChild = newp6;
	TBTNode *newp7 = new TBTNode();
	newp7->data = 8;
	newp7->lChild = NULL;
	newp7->rChild = NULL;
	newp7->lTag = newp7->rTag = 0;
	newp3->lChild = newp7;
	TBTNode *newp8 = new TBTNode();
	newp8->data = 9;
	newp8->lChild = NULL;
	newp8->rChild = NULL;
	newp8->lTag = newp8->rTag = 0;
	newp3->rChild = newp8;
	TBTNode *newp9 = new TBTNode();
	newp9->data = 10;
	newp9->lChild = NULL;
	newp9->rChild = NULL;
	newp9->lTag = newp9->rTag = 0;
	newp4->rChild = newp9;
	TBTNode *newp10 = new TBTNode();
	newp10->data = 11;
	newp10->lChild = NULL;
	newp10->rChild = NULL;
	newp10->lTag = newp10->rTag = 0;
	newp5->lChild = newp10;
	TBTNode *newp11 = new TBTNode();
	newp11->data = 12;
	newp11->lChild = NULL;
	newp11->rChild = NULL;
	newp11->lTag = newp11->rTag = 0;
	newp6->lChild = newp11;
	TBTNode *newp12 = new TBTNode();
	newp12->data = 13;
	newp12->lChild = NULL;
	newp12->rChild = NULL;
	newp12->lTag = newp12->rTag = 0;
	newp6->rChild = newp12;
}

void preThread(TBTNode *p, TBTNode *&pre)
{
	if (p != NULL)
	{
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->lTag = 1;
		}
		if (pre != NULL&&pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rTag = 1;
		}
		pre = p;
		if (p->lTag == 0)
			preThread(p->lChild, pre);
		if (p->rTag == 0)
			preThread(p->rChild, pre);
	}
}

void inThread(TBTNode *p, TBTNode *&pre)
{
	if (p != NULL)
	{
		inThread(p->lChild, pre);
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->lTag = 1;
		}
		if (pre != NULL&&pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rTag = 1;
		}
		pre = p;
		inThread(p->rChild, pre);
	}
}

void postThread(TBTNode *p, TBTNode *&pre)
{
	if (p != NULL)
	{
		postThread(p->lChild, pre);
		postThread(p->rChild, pre);
		if (p->lChild == NULL)
		{
			p->lChild = pre;
			p->lTag = 1;
		}
		if (pre != NULL&&pre->rChild == NULL)
		{
			pre->rChild = p;
			pre->rTag = 1;
		}
		pre = p;
	}
}

void preOrder(TBTNode *tbt)
{
	if (tbt != NULL)
	{
		TBTNode *p = tbt;
		while (p != NULL)
		{
			while (p->lTag == 0)
			{
				visit(p);
				p = p->lChild;
			}
			visit(p);
			p = p->rChild;
		}
	}
}

void inOrder(TBTNode *tbt)
{
	TBTNode *p = tbt;
	while (p->lTag == 0)
		p = p->lChild;
	while (p != NULL)
	{
		visit(p);
		if (p->rTag == 0)
		{
			p = p->rChild;
			while (p != NULL&&p->lTag == 0)
				p = p->lChild;
		}
		else
			p = p->rChild;

	}
}

void postOrder(TBTNode *tbt)
{
	
}