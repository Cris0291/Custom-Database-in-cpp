#include <iostream>
#include "tree.h"

Tree root = {
	{
		(TagRoot | TagNode),
		(Node*)&root,
		0,
		0,
		"/"
}
};

Node* create_node(Node* parent, int8* path) {
	assert(parent);

	Node* n{ new Node {} };

	parent->west = n;
	n->tag = TagNode;
	n->north = parent; 
	strncpy((char*)n->path, (char*)path, 255);

	return n;
}

int main()
{
	Node* n{ create_node((Node*)&root, (int8*)"/Users") };
	return 0;
}

