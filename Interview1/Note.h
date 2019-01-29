#ifndef __NOTE_H__
#define __NOTE_H__

#include <string>
#include <set>
#include <iostream>

class Note
{
  public:
    Note() = delete;
    Note(const std::string& title, const std::string& text, const std::set<std::string>& tags);
    std::string title() const;
    std::string text() const;
    std::set<std::string> tags() const;

    void setTitle(const std::string& title);
    void setText(const std::string& text);
    void setTags(const std::set<std::string>& tags);
    void addTag(const std::string& tag);
    void removeTag(const std::string& tag);
    friend std::ostream& operator<< (std::ostream& stream, const Note& note);
  private:
    std::string m_title;
    std::string m_text;
    std::set<std::string> m_tags;
};

#endif
