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
	void deleteItemStack(const std::string& grid_position);
  void addMoney(const double& money);
  std::shared_ptr<ItemStack> queryForItem(const std::string& grid_position) const;
  void retrieveItem(const std::string& grid_position);
  double returnChange();	
private:
  std::map<std::string, ItemStack> m_item_stacks;
  double m_money = 0.0;  
  //regular expression to validate row and column
  const std::regex m_grid_regex = std::regex("[A-Z][0-1]?[0-9]");
};

#endif
