#include "Note.h"

Note::Note(const std::string& title, const std::string& text, const std::set<std::string>& tags):
  m_title(title), m_text(text), m_tags(tags)
{

}

std::string Note::title () const
{
  return m_title;
}

std::string Note::text() const
{
  return m_text;
}

std::set<std::string> Note::tags() const
{
  return m_tags;
}
    
void Note::setTitle(const std::string& title)
{
  m_title = title;
}
    
void Note::setText(const std::string& text)
{
  m_text = text;
}
    
void Note::setTags(const std::set<std::string>& tags)
{
  m_tags = tags;
}
    
void Note::addTag(const std::string& tag)
{
  m_tags.insert(tag);
}
    
void Note::removeTag(const std::string& tag)
{
  m_tags.erase(tag);
}

std::ostream& operator<< (std::ostream& stream, const Note& note)
{
  stream << "- title: " << note.m_title << "\n- text: " << note.m_text << "\n- tags: {" ;
  bool first=true;
  for (const auto& tag : note.m_tags)
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
    stream << tag << "\"";
  }
  stream << "}";
  return stream;
}

