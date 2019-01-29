/* In this exercise we want to design a simple binary search tree with different kinds of iterators.
 * Our binary tree should store an arbitrary type which is comparable (e.g. int, string, float etc.)
 * The tree should provide an "add(...)" method which inserts a new element
 * into the tree (preserving the binary search tree's invariant) as well as a "search(...)" method.
 * In this exercise we do not care about deleting elements in the search tree.
 * The tree should provide three different iterators which traverse the tree in preorder, postorder and inorder.
 *
 * E.g.:
 * Assume we have the following binary tree:
 *                               6
 *                          4         8
 *                       2     5   7      9
 *
 * Consider having the instance "bt" of our binary tree.
 * To construct the above tree and traverse it in preorder we do:
 *     bt.add(6);
 *     bt.add(4);
 *     bt.add(8);
 *     bt.add(2);
 *     bt.add(5);
 *     bt.add(7);
 *     bt.add(9);
 *     auto itPre = bt.beginPreorder();
 *     for(;itPre != bt.endPreorder(); ++itPre) {
 *	       std::cout << *itPre << " ";
 *	   }
 *
 * The output of this code snippet should be "6 4 2 5 8 7 9".
 * Similiarly we want iterators for postorder (beginPostorder() ; endPostOrder()) and for
 * inorder (beginInorder() ; endInorder()). If you're not familiar with the traversion orders you can 
 * look them up online.
 *
 * A very important part of this exercise are the unit tests. Show how you would test the functionality of the
 * binary search tree and the three different iterators.
 * Don't use any testing framework. Simple if-statements are sufficient for this exercise.
 *
 */