#include "VendingMachine.h"
#include "ItemStack.h"

void VendingMachine::addItemStack(const std::string& grid_position, const ItemStack& item_stack)
{
  if(std::regex_match(grid_position, m_grid_regex))
  {
    m_item_stacks.insert(std::make_pair(grid_position, item_stack));
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << " ERROR grid position = " << grid_position << " not valid!!" << std::endl;
  }
}

void VendingMachine::deleteItemStack(const std::string& grid_position)
{
  if(std::regex_match(grid_position, m_grid_regex))
  {
    m_item_stacks.erase(grid_position);
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << " ERROR grid position = " << grid_position << " not valid!!" << std::endl;
  }
}

void VendingMachine::addMoney(const double& money)
{
  if (money > 0.0)
  {
    m_money = m_money + money;
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << " ERROR money negative" << std::endl;
  }
}

std::shared_ptr<ItemStack> VendingMachine::queryForItem(const std::string& grid_position) const
{
  std::shared_ptr<ItemStack> item = nullptr;

  if(std::regex_match(grid_position, m_grid_regex))
  {
    auto it = m_item_stacks.find(grid_position);
    if (it!=m_item_stacks.end())
    {
      item = std::make_shared<ItemStack>(it->second);
    }
    else
    {
      std::cerr << __PRETTY_FUNCTION__ << " ERROR grid is empty" << std::endl;
    }
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << " ERROR grid position = " << grid_position << " not valid!!" << std::endl;
  }

  return item;
}

void VendingMachine::retrieveItem(const std::string& grid_position)
{
  if(m_money > 0.0)
  {
    if(std::regex_match(grid_position, m_grid_regex))
    {
      auto it = m_item_stacks.find(grid_position);
      if (it!=m_item_stacks.end())
      {
        if(it->second.count() >= 1)
        {
          if(m_money >= it->second.cost())
          {
            it->second.retreive();
            m_money = m_money - it->second.cost();
            std::cout << "pick up " << it->second.title() << " available money " << m_money<< std::endl;
          }
          else
          {
            std::cerr << __PRETTY_FUNCTION__ << " ERROR not money " << m_money << " for buy this item " << it->second.cost() << std::endl;
          }
        }
        else
        {
          std::cerr << __PRETTY_FUNCTION__ << " ERROR no stock" << std::endl;
        }
      }
      else
      {
        std::cerr << __PRETTY_FUNCTION__ << " ERROR grid is empty" << std::endl;
      }
    }
    else
    {
      std::cerr << __PRETTY_FUNCTION__ << " ERROR grid position = " << grid_position << " not valid!!" << std::endl;
    }
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << " ERROR not money for buy this item" << std::endl;
  }
}

double VendingMachine::returnChange()
{
  double change = m_money;
  
  m_money = 0.0;
  std::cout << "Your change thanks " << change << " €" << std::endl;
  return change;
}

