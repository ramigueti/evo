#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <memory>
#include <iterator>
#include <stack>

template <typename T>
class InorderIterator;

template <typename T>
class PreorderIterator;

template<class T>
struct Node
{
  T m_data;

  std::unique_ptr<Node<T>> m_left=nullptr;
  std::unique_ptr<Node<T>> m_right=nullptr;
  Node<T>(T data): m_data(data)
  {}
  friend std::ostream& operator<< (std::ostream& stream, const Node<T>& node)
  {
    stream << node.m_data;
  }
};

template<class T>
class BinarySearchTree
{
  private:
    std::unique_ptr<Node<T>> m_root = nullptr;

    void addNode(std::unique_ptr<Node<T>>& node, const T& data)
    {
      if (node->m_data > data) 
      {
        if (nullptr == node->m_left) 
        {
          node->m_left = std::make_unique<Node<T>>(data);
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
          node->m_right = std::make_unique<Node<T>>(data);
        } 
        else 
        {
          addNode(node->m_right, data);
        }
      }
    }

    bool searchNode(std::unique_ptr<Node<T>>& node, const T& data) const
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
    void printNode(const std::unique_ptr<Node<T>>& node) const
    {
      if (nullptr == node) return;
      printNode(node->m_left);
      std::cout<<*node<<' ';
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
        m_root = std::make_unique<Node<T>>(data);
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
    
    InorderIterator<T> beginInorder()
    {
      InorderIterator<T> it = InorderIterator<T>(m_root.get());

      return it;
    }  
    InorderIterator<T> endInorder()
    {
      InorderIterator<T> it = InorderIterator<T>(nullptr); 

      return it;
    }  
    PreorderIterator<T> beginPreorder()
    {
      PreorderIterator<T> it = PreorderIterator<T>(m_root.get());

      return it;
    }  
    PreorderIterator<T> endPreorder()
    {
      PreorderIterator<T> it = PreorderIterator<T>(nullptr); 

      return it;
    }  
};

template <typename T>
class InorderIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Node<T>;
    using difference_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    InorderIterator(Node<T>* root)
    {
      leafNode(root); 
    }

    bool operator!=(InorderIterator<T> const & other) const
    {
      if(m_stack.empty() && other.m_stack.empty())
      {
        return false;
      }
      else if(m_stack.empty() || other.m_stack.empty())
      {
        return true;
      }
      else
      {
        return m_stack.top() != other.m_stack.top();
      }
    }

    T &operator*() const {
      return m_stack.top()->m_data;
    }

    InorderIterator operator++()
    {
      Node<T>* node = m_stack.top();
      m_stack.pop();
      Node<T>* head = node->m_right.get();
      leafNode(head);
      return *this;
    }

    InorderIterator operator++(int aux)
    {
      Node<T>* temp = m_stack.top();
      Node<T>* node = m_stack.top();
      m_stack.pop();
      Node<T>* head = node->m_right.get();
      leafNode(head);
      return *temp;
    }

  private:
    std::stack<Node<T>*> m_stack;
    void leafNode(Node<T>* root)
    {
      while(root){
        m_stack.push(root);
        root=root->m_left.get();
      }
    }
};

template <typename T>
class PreorderIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Node<T>;
    using difference_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    PreorderIterator(Node<T>* root)
    {
      if(root)
      {
        m_stack.push(root); 
        next();
      }
    }

    bool operator!=(PreorderIterator<T> const & other) const
    {
      return m_current != other.m_current;
    }

    T &operator*() const {
      return m_current->m_data;
    }

    PreorderIterator operator++()
    {
      next();
      return *this;
    }

    PreorderIterator operator++(int aux)
    {
      Node<T>* temp = m_current;
      next();
      return *temp;
    }

  private:
    void next()
    {
      if(m_stack.empty())
      {
        m_current = nullptr;
        return;
      }

      m_current = m_stack.top();
      m_stack.pop();
      if (nullptr != m_current->m_right) 
      {
        m_stack.push(m_current->m_right.get());
      }
      if (nullptr != m_current->m_left)
      {
        m_stack.push(m_current->m_left.get());
      }
    }

    std::stack<Node<T>*> m_stack;
    Node<T>* m_current = nullptr;
};

#endif
