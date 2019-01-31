#include <iostream>
#include "BinarySearchTree.h"

int main()
{
  BinarySearchTree<int> bt;

  bt.add(6);
  bt.add(4);
  bt.add(8);
  bt.add(2);
  bt.add(5);
  bt.add(7);
  bt.add(9);

  std::cout << "Binary Search Tree: " << std::endl;
  bt.print();
  std::cout << std::endl; 
  bt.search(5) ? std::cout << "Found 5 in binary search tree " <<std::endl 
  : std::cout << "Not found 5 in binary search tree" <<std::endl;  
  bt.search(3) ? std::cout << "Found 3 in binary search tree " <<std::endl 
  : std::cout << " Not found 3 in binary search tree" <<std::endl;  
  return 0;
}
