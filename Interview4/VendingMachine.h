#ifndef __VENDINGMACHINE_H__
#define __VENDINGMACHINE_H__

#include <regex>
#include <map>
#include <string>
#include <memory>

class ItemStack;

class VendingMachine
{
public:
	void addItemStack(const std::string& grid_position, const ItemStack& item_stack);
	void deleteItemStack(const std::string& grid_postion);
  void addMoney(const float& money);
  std::shared_ptr<ItemStack> queryForItem(const std::string& grid_postion) const;
  void retrieveItem(const std::string& grid_postion);
  float returnChange();	
private:
  std::map<std::string, ItemStack> m_item_stacks;
  float m_money = 0;  
  const std::regex m_grid_regex("[A-Z][0-1]?[0-9]");
};

#endif
