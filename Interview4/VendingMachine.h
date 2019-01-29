#ifndef __VENDINGMACHINE_H__
#define __VENDINGMACHINE_H__

#include <map>
#include <string>

class ItemStack;

class VendingMachine
{
public:
	void addItemStack(const std::string& grid_position, const ItemStack& item_stack);
	void deleteItemStack(const std::string& grid_postion);
  void addMoney(float money);
  ItemStack queryForItem(const std::string& grid_postion) const;
  void retrieveItem(const std::string& grid_postion);
	
private:
  std::map<std::string, ItemStack> m_item_stacks;
  float m_money = 0;  
};

#endif
