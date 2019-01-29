#include <iostream>
#include "SocialNetwork.h"
#include "User.h"

int main()
{
  SocialNetwork social_network;
  
  User jochen("Jochen", 36, 180, MALE, {"Jogging", "Football", "Tennis"});
  social_network.addUser(jochen);
  User rafael("Rafael", 32, 190, MALE, {"Football", "Music", "Motorbike"}, {jochen.id()});
  social_network.addUser(rafael);
  User maria("Maria", 32, 166, FEMALE, {"Music", "Motorbike"}, {jochen.id(), rafael.id()});
  social_network.addUser(maria);

  auto search_by_name = social_network.searchUserByName("Rafael");
  std::cout << "Result for search by name: " << std::endl;

  for (auto it = search_by_name.begin(); it != search_by_name.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }

  auto search_by_age = social_network.searchUserByAge(36);
  std::cout << "\nResult for search by age: " << std::endl;

  for (auto it = search_by_age.begin(); it != search_by_age.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  
  auto search_by_hobbies = social_network.searchUserByHobbies({"Football"});
  std::cout << "\nResult for search by hobbies {\"Football\"}: " << std::endl;

  for (auto it = search_by_hobbies.begin(); it != search_by_hobbies.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  
  auto friends_of_rafa  = social_network.getFriendsOfUser(rafael);
  std::cout << "\nResult friends of rafa: " << std::endl;

  for (auto it = friends_of_rafa.begin(); it != friends_of_rafa.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  auto friends_of_maria  = social_network.getFriendsOfUser(maria);
  std::cout << "\nResult friends of maria: " << std::endl;

  for (auto it = friends_of_maria.begin(); it != friends_of_maria.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
 
  std::cout << "\nDelete Jochen" << std::endl;
  social_network.deleteUser(jochen); 
  auto friends_of_rafa_2  = social_network.getFriendsOfUser(rafael);
  std::cout << "\nResult friends of rafa: " << std::endl;

  for (auto it = friends_of_rafa_2.begin(); it != friends_of_rafa_2.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }

  auto friends_of_maria_2  = social_network.getFriendsOfUser(maria);
  std::cout << "\nResult friends of maria: " << std::endl;

  for (auto it = friends_of_maria_2.begin(); it != friends_of_maria_2.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  return 0;
}
