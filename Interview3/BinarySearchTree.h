#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include <memory>
#include <iterator>
#include <stack>

template <class T>
class InorderIterator;

template <class T>
class PreorderIterator;

template <class T>
class PostorderIterator;

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
    PostorderIterator<T> beginPostorder()
    {
      PostorderIterator<T> it = PostorderIterator<T>(m_root.get());

      return it;
    }  
    PostorderIterator<T> endPostorder()
    {
      PostorderIterator<T> it = PostorderIterator<T>(nullptr); 

      return it;
    }  
};

template <class T>
class InorderIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Node<T>*;
    using difference_type = Node<T>*;
    using pointer = Node<T>**;
    using reference = Node<T>*&;

    InorderIterator(value_type root)
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
      value_type node = m_stack.top();
      m_stack.pop();
      value_type head = node->m_right.get();
      leafNode(head);
      return *this;
    }

    InorderIterator operator++(int aux)
    {
      InorderIterator temp = *this; 
      ++(*this); 
      return temp;
    }

  private:
    void leafNode(value_type root)
    {
      while(nullptr!=root){
        m_stack.push(root);
        root=root->m_left.get();
      }
    }

    std::stack<value_type> m_stack;
};

template <class T>
class PreorderIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Node<T>*;
    using difference_type = Node<T>*;
    using pointer = Node<T>**;
    using reference = Node<T>*&;

    PreorderIterator(value_type root)
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
      PreorderIterator temp = *this; 
      ++(*this); 
      return temp;
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

    std::stack<value_type> m_stack;
    value_type m_current = nullptr;
};

template <class T>
class PostorderIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Node<T>*;
    using difference_type = Node<T>*;
    using pointer = Node<T>**;
    using reference = Node<T>*&;

    PostorderIterator(value_type root)
    {
      fillStack(root); 
    }

    bool operator!=(PostorderIterator<T> const & other) const
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

    PostorderIterator operator++()
    {
      value_type node = m_stack.top();
      m_stack.pop();
      return *this;
    }

    PostorderIterator operator++(int aux)
    {
      PostorderIterator temp = *this; 
      ++(*this); 
      return temp;
    }

  private:
    void fillStack(value_type root)
    {
      if (nullptr == root)
      {
        return;
      }
      std::stack<value_type> aux;

      aux.push(root);

      while (!aux.empty()) {
        auto current = aux.top();
        m_stack.push(current);
        aux.pop();
        if (nullptr != current->m_left)
        {
          aux.push(current->m_left.get());
        }
        if (nullptr != current->m_right)
        {
          aux.push(current->m_right.get());
        }
      }
    }

    std::stack<value_type> m_stack;
};
#endif
