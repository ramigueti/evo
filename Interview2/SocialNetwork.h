#ifndef __SOCIALNETWORK_H__
#define __SOCIALNETWORK_H__

#include <vector>
#include <set>
#include <map>
#include <string>

class User;

class SocialNetwork
{
public:
  SocialNetwork(unsigned int max_users=100);
  // User is a reference because addUser method setting identifier
	void addUser(User& user);
	void deleteUser(const User& user);
  std::vector<User> searchUserByName(const std::string& name) const;
  std::vector<User> searchUserByAge(const unsigned short& age) const;
  std::vector<User> searchUserByHobbies(const std::vector<std::string>& hobbies) const;
  std::set<unsigned int> getFriendsOfUser(const User& user) const;
  void addFriendOfUser(User& user, const User& user_friend) const;
	
private:
  unsigned int next_id();
  void removeFriend(const unsigned int& id_user);
  std::map<unsigned int, User> m_users;
  std::set<unsigned int> m_free_ids;  
};

#endif
