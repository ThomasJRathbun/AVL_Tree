#include "avl_tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	avl_tree tree;
	
	
	cout << "height NULL" << endl;
	cout << tree.height() << endl;
	
	
	cout << "height 0" << endl;	
	tree.insertRec(2);
	cout << "inserted" << endl;	
	cout << tree.height() << endl;
	
	cout << "height 1" << endl;	
	tree.insertRec(0);
	cout << "inserted" << endl;	
	cout << tree.height() << endl;
	
	cout << "height 2" << endl;	
	tree.insertRec(1);
	cout << "inserted" << endl;	
	cout << tree.height() << endl;
	
	
//	cout << "height 3" << endl;	
//	tree.insertRec(1);
//	cout << "inserted" << endl;	
//	cout << tree.height() << endl;
//	
//	cout << "height 4" << endl;	
//	tree.insertRec(0);
//	cout << "inserted" << endl;	
//	cout << tree.height() << endl;

	return 0;
}
