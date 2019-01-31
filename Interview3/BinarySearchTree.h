#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <memory>


template<class T>
class BinarySearchTree
{
      struct Node
      {
        T m_data;

        std::unique_ptr<Node> m_left=nullptr;
        std::unique_ptr<Node> m_right=nullptr;
        Node(T data): m_data(data)
        {}
        friend std::ostream& operator<< (std::ostream& stream, const Node& node)
        {
          stream << node.m_data;
        }
      };
  private:
    std::unique_ptr<Node> m_root = nullptr;

    void addNode(std::unique_ptr<Node>& node, const T& data)
    {
      if (node->m_data > data) 
      {
        if (nullptr == node->m_left) 
        {
          node->m_left = std::make_unique<Node>(data);
        } 
        else 
        {
          addNode(node->m_left, data);
        }
      } 
      else 
      {
        if (nullptr == node->m_right) 
        {
          node->m_right = std::make_unique<Node>(data);
        } 
        else 
        {
          addNode(node->m_right, data);
        }
      }
    }

    bool searchNode(std::unique_ptr<Node>& node, const T& data) const
    {
      bool found = false;
      if(node->m_data == data)
      {
        return true;
      }
      else if (node->m_data > data) 
      {
        if (node->m_left) 
        {
          found = searchNode(node->m_left, data);
        }
      } 
      else 
      {
        if (node->m_right) 
        {
          found = searchNode(node->m_right, data);
        }
      }

      return found;
    }
    void printNode(const std::unique_ptr<Node>& node) const
    {
      if (nullptr == node) return;
      printNode(node->m_left);
      std::cout<<node->m_data<<' ';
      printNode(node->m_right);
    }

  public:
    void add(const T& data) {
      if (m_root) 
      {
        addNode(m_root, data);
      } 
      else 
      {
        m_root = std::make_unique<Node>(data);
      }
    }
    void print() const 
    {
      printNode(this->m_root); 
    }
    bool search (const T& data) 
    {
      bool found = false;

      if(m_root)
      {
        found = searchNode(m_root, data);
      }

      return found;
    }
};

#endif
