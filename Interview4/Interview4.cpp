/* In this exercise we want to design a Simple Vending Machine. This Vending Machine
 * contains many items (cola/beer) which can be purchased. Similar items are stacked together. 
 * Multiple stacks are arraged as a grid inside the vending machine, eg: 8 columns and 15 rows  
 *
 * Every stack has a title, a cost and counter for items in stack remaining. E.g.
 * 	- title: "Lemonade"
 * 	- cost: "1.20"
 * 	- count: 6 
 * 
 * The Vending Machine should enable us to 
 *      queryForItem("B6") // 2nd Column 6th Row 
 *      retrieveItem("D3") // 4th Column 3rd Row
 * 
 * The skeleton code below can be used as a starting point but doesn't have to.
 * The comments "fill in" are placeholders where you definitely have to put in some code when 
 * you use this skeleton code. But this doesn't mean that you shouldn't or can't put code anywhere else.
 * 
 * Also write some simple unit tests to show how you would test the functionality of the Vending Machine.
 * Don't use any testing framework. Simple if-statements are sufficient for this exercise.
 * 
 * Hint: Think about performance versus memory tradeoffs in your design, so you can give good 
 *       reasons for your decision. 
 */

class Item
{
	/*fill in*/
};

class ItemStack
{
	/*fill in*/
};

class VendingMachine
{
public:
	void addMoney(/*fill in*/);
	/*fill in*/ returnChange(/*fill in*/);

	/*fill in*/ queryForItem(/*fill in*/);
	/*fill in*/ retrieveItem(/*fill in*/);
	
private:
	/*fill in*/
};