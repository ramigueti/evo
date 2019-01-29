#include "ItemStack.h"

ItemStack::ItemStack(const std::string& title, const float& cost, const unsigned int& count):
  m_title(title), m_cost(cost), m_count(count)
{

}

std::string ItemStack::title () const
{
  return m_title;
}

float ItemStack::cost() const
{
  return m_cost;
}

unsigned int ItemStack::count() const
{
  return m_count;
}
    
void ItemStack::setTitle(const std::string& title)
{
  m_title = title;
}
    
void ItemStack::setCost(const float& cost)
{
  m_cost = cost;
}
    
void ItemStack::setCount(const float& count)
{
  m_count = count;
}
void ItemStack::retreive()
{
  if(m_count > 0)
  {
    m_count--;
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << " ERROR stack is empty" << std::endl;
}
    
std::ostream& operator<< (std::ostream& stream, const ItemStack& itemStack)
{
  stream << "- title: " << itemStack.m_title << "\n- cost: " << itemStack.m_cost << "\n- count: " << itemStack.m_count;

  return stream;
}

