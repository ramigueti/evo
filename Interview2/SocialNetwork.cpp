#include <algorithm>
#include <iterator>
#include "SocialNetwork.h"
#include "User.h"

SocialNetwork::SocialNetwork(unsigned int max_users)
{
  unsigned int i = 1;
  std::generate_n(std::inserter(m_free_ids, m_free_ids.begin()), max_users, [&i](){ return i++; });
}

unsigned int SocialNetwork::next_id()
{
  unsigned int id=0;

  if(!m_free_ids.empty())
  {
    auto it = m_free_ids.begin();
    id = *it;
  }

  return id;
}

void SocialNetwork::removeFriend(const unsigned int& id_user)
{
  for (auto& user: m_users)
  {
    user.second.removeFriend(id_user);
  }
}

void SocialNetwork::addUser(User& user)
{
  auto id = next_id();
  if(id > 0)
  {
    user.m_id = id;
    bool friends_exist = true;
    auto friends = user.friends();
    for(auto it = friends.begin(); it != friends.end() && friends_exist; ++it)
    {
      if(0==m_users.count(*it))
      {
        friends_exist = false;
      }
    }
    if(friends_exist)
    {
    m_users.insert(std::make_pair(user.id(), user));
    m_free_ids.erase(user.id());
    }
    else
    {
    std::cerr << __PRETTY_FUNCTION__ << "ERROR: Some friend does not exist!!" << std::endl;
    }
  }
  else
  {
    std::cerr << __PRETTY_FUNCTION__ << "ERROR: Max users reached!!" << std::endl;
  }
}

void SocialNetwork::deleteUser(const User& user)
{
  auto id_user = user.id();
  if(m_users.count(id_user)!=0)
  {
    m_users.erase(id_user);
    m_free_ids.insert(id_user);
    removeFriend(id_user);
  }
}

std::vector<User> SocialNetwork::searchUserByName(const std::string& name) const
{
  std::vector<User> users_found;

  for(const auto& user : m_users)
  {
    if(user.second.name() == name)
    {
      users_found.push_back(user.second);
    }
  }

  return users_found;
}

std::vector<User> SocialNetwork::searchUserByAge(const unsigned short& age) const
{
  std::vector<User> users_found;

  for(const auto& user : m_users)
  {
    if(user.second.age() == age)
    {
      users_found.push_back(user.second);
    }
  }

  return users_found;
}

std::vector<User> SocialNetwork::searchUserByHobbies(const std::vector<std::string>& hobbies) const
{
  std::vector<User> users_found;

  if(!hobbies.empty())
  {
    for(const auto& user : m_users)
    {
      bool found = true;
      for(auto it = hobbies.begin(); it != hobbies.end() && found; ++it)
      {
        auto user_hobbies = user.second.hobbies();
        if(user_hobbies.find(*it)==user_hobbies.end())
        {
          found = false; 
        }
      }
      if(found)
      {
        users_found.push_back(user.second);
      }
    }
  }

  return users_found;
}

std::set<unsigned int> SocialNetwork::getFriendsOfUser(const User& user) const
{
  auto id_user = user.id();
  auto it = m_users.find(id_user);
  
  std::set<unsigned int> friends;
  if(it == m_users.end())
  {
    std::cerr << __PRETTY_FUNCTION__ << "ERROR id user " << id_user <<" not found" << std::endl;
  }
  else
  {
    friends = it->second.friends();
  }

  return friends;
}

