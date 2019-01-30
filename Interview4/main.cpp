#include <iostream>
#include "VendingMachine.h"
#include "ItemStack.h"

int main()
{
  ItemStack lemonade("Lemonade", 1.2, 6);
  ItemStack coke("Coke", 1.0, 6);
  ItemStack lollipop("Lollipop", 0.1, 6);
  VendingMachine vending_machine;
  vending_machine.addItemStack("A1", lemonade);
  vending_machine.addItemStack("A2", lemonade);
  vending_machine.addItemStack("A3", lemonade);
  vending_machine.addItemStack("B1", coke);
  vending_machine.addItemStack("B2", coke);
  vending_machine.addItemStack("B3", coke);
  vending_machine.addItemStack("C1", lollipop);

  vending_machine.addMoney(2.5);
  auto item_a1 = vending_machine.queryForItem("A1");
  if(nullptr != item_a1)
  {
    std::cout << "Item A1: " << *item_a1 << std::endl;
  }
  vending_machine.retrieveItem("A1");
  vending_machine.retrieveItem("C1");
  vending_machine.retrieveItem("A1");
  item_a1 = vending_machine.queryForItem("A1");
  if(nullptr != item_a1)
  {
    std::cout << "Item A1: " << *item_a1 << std::endl;
  }
  vending_machine.retrieveItem("A1");
  vending_machine.returnChange();

  return 0;
}
