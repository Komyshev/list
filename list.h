#include "io.h"

struct node_list{
	int val;
	node_list *next;
};

void addBegin(int, node_list *&, node_list *&);

void addEnd(int, node_list *&, node_list *&);

int addAfter(int, int, node_list *, node_list *&);

int addBefore(int, int, node_list *&, node_list *);

int erase(int, node_list *&, node_list *&);

int sorting(node_list *&, node_list *&);

void print(node_list *);

int menuList();
