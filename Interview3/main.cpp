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
  std::cout << std::endl; 
  bt.search(5) ? std::cout << "Found 5 in binary search tree " <<std::endl 
  : std::cout << "Not found 5 in binary search tree" <<std::endl;  
  bt.search(3) ? std::cout << "Found 3 in binary search tree " <<std::endl 
  : std::cout << "Not found 3 in binary search tree" <<std::endl;  
  std::cout << "Inorder" << std::endl; 
  for (auto it = bt.beginInorder(); it != bt.endInorder(); ++it)
  {
    std::cout << *it << " ";
  }  
  std::cout << std::endl; 
  std::cout << "Preorder" << std::endl; 
  for (auto it = bt.beginPreorder(); it != bt.endPreorder(); ++it)
  {
    std::cout << *it << " ";
  }  
  std::cout << std::endl; 
  std::cout << std::endl; 
  std::cout << "Postorder" << std::endl; 
  for (auto it = bt.beginPostorder(); it != bt.endPostorder(); ++it)
  {
    std::cout << *it << " ";
  }  
  std::cout << std::endl; 
  return 0;
}
