#ifndef __ITEMSTACK_H__
#define __ITEMSTACK_H__

#include <string>
#include <iostream>

class ItemStack
{
  public:
    ItemStack() = delete;
    ItemStack(const std::string& title, const float& cost, const unsigned int& count);
    std::string title() const;
    float cost() const;
    unsigned int count() const;

    void setTitle(const std::string& title);
    void setCost(const float& cost);
    void setCount(const unsigned int& count);
    void retreive();
    friend std::ostream& operator<< (std::ostream& stream, const ItemStack& itemStack);
  private:
    std::string m_title;
    float m_cost; 
    unsigned int m_count;
};

#endif
