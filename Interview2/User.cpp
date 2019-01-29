#include "User.h"

User::User(const std::string& name, const short& age, const short& height, 
    const GenderEnum& gender, const std::set<std::string>& hobbies,
    const std::set<unsigned int>& friends): m_name(name), m_age(age), m_height(height),
  m_gender(gender), m_hobbies(hobbies), m_friends(friends)
{

}

unsigned int User::id () const
{
  return m_id;
}

std::string User::name() const
{
  return m_name;
}

short User::age() const
{
  return m_age;
}

short User::height() const
{
  return m_height;
}

GenderEnum User::gender() const
{
  return m_gender;
}

std::set<std::string> User::hobbies() const
{
  return m_hobbies;
}

std::set<unsigned int> User::friends() const
{
  return m_friends;
}

void User::setName(const std::string& name)
{
  m_name = name;
}

void User::setAge(const short& age)
{
  m_age = age;
}

void User::setGender(const GenderEnum& gender)
{
  m_gender = gender;
}

void User::setHobbies(const std::set<std::string>& hobbies)
{
  m_hobbies = hobbies;
}

void User::setFriends(const std::set<unsigned int>& friends)
{
  m_friends = friends;
}
void User::addHobby(const std::string& hobby)
{
  m_hobbies.insert(hobby);
}

void User::removeHobby(const std::string& hobby)
{
  m_hobbies.erase(hobby);
}

void User::addFriend(const unsigned int& id_friend)
{
  m_friends.insert(id_friend);
}

void User::removeFriend(const unsigned int& id_friend)
{
  m_friends.erase(id_friend);
}
std::ostream& operator<< (std::ostream& stream, const User& user)
{
  std::string gender_str;
  switch (user.m_gender)
  {
    case UNKNOWN:
      gender_str = "UNKNOWN";
      break;
    case MALE:
      gender_str = "MALE";
      break;
    case FEMALE:
      gender_str = "FEMALE";
      break;
    default:
      gender_str = "UNKNOWN";
      break;
  }

  stream << "- id: " << user.m_id << "\n- name: " << user.m_name << "\n- age: " << user.m_age << "\n- height: " << 
    user.m_height << "\n- gender: " << gender_str << "\n- hobbies: {";
  bool first=true;
  for (const auto& hobby : user.m_hobbies)
  {
    if (first)
    {
      stream << "\"";
      first=false;
    }
    else
    {
      stream << ", \"";
    }
    stream << hobby << "\"";
  }
  stream << "}\n- friends: {";
  first=true;
  for (const auto& id_friend : user.m_friends)
  {
    if (first)
    {
      stream << "\"";
      first=false;
    }
    else
    {
      stream << ", \"";
    }
    stream << id_friend << "\"";
  }
  stream << "}";
  return stream;
}

