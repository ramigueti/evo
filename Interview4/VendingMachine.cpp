#include "VendingMachine.h"
#include "ItemStack.h"

void VendingMachine::addItemStack(const ItemStack& item_stack)
{
  m_item_stacks.push_back(item_stack);
}

void VendingMachine::deleteItemStack(const std::string& title, bool all_ocurrences)
{
  bool finished = false;
 
  std::vector<std::vector<ItemStack>::const_iterator> its_to_delete; 
  for (auto it = m_item_stacks.begin(); it != m_item_stacks.end() && !finished; ++it)
  {
    if(it->title() == title)
    {
      its_to_delete.push_back(it);
      if(!all_ocurrences)
      {
        finished = true;
      }
    }
  }
  for (auto it_to_delete : its_to_delete)
  {
    m_item_stacks.erase(it_to_delete);
  }
}

std::vector<ItemStack> VendingMachine::searchByTitle(const std::string& title) const
{
  std::vector<ItemStack> item_stacks_found;

  for(const auto& item_stack : m_item_stacks)
  {
    if(item_stack.title() == title)
    {
      item_stacks_found.push_back(item_stack);
    }
  }

  return item_stacks_found;
}

std::vector<ItemStack> VendingMachine::searchByText(const std::string& text) const
{
  std::vector<ItemStack> item_stacks_found;

  for(const auto& item_stack : m_item_stacks)
  {
    if(item_stack.text() == text)
    {
      item_stacks_found.push_back(item_stack);
    }
  }

  return item_stacks_found;
}

std::vector<ItemStack> VendingMachine::searchByTag(const std::vector<std::string>& tags) const
{
  std::vector<ItemStack> item_stacks_found;

  if(!tags.empty())
  {
    for(const auto& item_stack : m_item_stacks)
    {
      bool found = true;
      for(auto it = tags.begin(); it != tags.end() && found; ++it)
      {
        auto item_stack_tags = item_stack.tags();
        if(item_stack_tags.find(*it)==item_stack_tags.end())
        {
          found = false; 
        }
      }
      if(found)
      {
        item_stacks_found.push_back(item_stack);
      }
    }
  }

  return item_stacks_found;
}

