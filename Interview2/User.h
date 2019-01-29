#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <set>
#include <iostream>
 
class SocialNetwork;

enum GenderEnum
{
  UNKNOWN,
  MALE,
  FEMALE
};

class User
{
  public:
    User() = delete;
    User(const std::string& name, const short& age=-1, const short& height=-1, 
        const GenderEnum& gender=UNKNOWN, const std::set<std::string>& hobbies={},
        const std::set<unsigned int>& friends={});
    unsigned int id() const;
    std::string name() const;
    short age() const;
    short height() const;
    GenderEnum gender() const;
    std::set<std::string> hobbies() const;
    std::set<unsigned int> friends() const;

    void setName(const std::string& name);
    void setAge(const short& age);
    void setHeight(const short& height);
    void setGender(const GenderEnum& gender);
    void setHobbies(const std::set<std::string>& hobbies);
    void setFriends(const std::set<unsigned int>& hobbies);
    void addHobby(const std::string& hobby);
    void removeHobby(const std::string& hobby);
    void addFriend(const unsigned int& id_friend);
    void removeFriend(const unsigned int& id_friend);

  private:
    friend std::ostream& operator<< (std::ostream& stream, const User& user);
    //Declare SocialNetwork friend because set of id is delegate and m_id should be private
    // for protection
    friend class SocialNetwork;
    unsigned int m_id=0;
    std::string m_name;
    short m_age;
    short m_height; //cm
    GenderEnum m_gender;
    std::set<std::string> m_hobbies;
    std::set<unsigned int> m_friends;
};

#endif

