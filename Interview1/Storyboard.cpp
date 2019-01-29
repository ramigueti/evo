#include "Storyboard.h"
#include "Note.h"

void Storyboard::addNote(const Note& note)
{
  m_notes.push_back(note);
}

void Storyboard::deleteNote(const std::string& title, bool all_ocurrences)
{
  bool finished = false;
 
  std::vector<std::vector<Note>::const_iterator> its_to_delete; 
  for (auto it = m_notes.begin(); it != m_notes.end() && !finished; ++it)
  {
    if(it->title() == title)
    {
      its_to_delete.push_back(it);
      if(!all_ocurrences)
      {
        finished = true;
      }
    }
  }
  for (auto it_to_delete : its_to_delete)
  {
    m_notes.erase(it_to_delete);
  }
}

std::vector<Note> Storyboard::searchByTitle(const std::string& title) const
{
  std::vector<Note> notes_found;

  for(const auto& note : m_notes)
  {
    if(note.title() == title)
    {
      notes_found.push_back(note);
    }
  }

  return notes_found;
}

std::vector<Note> Storyboard::searchByText(const std::string& text) const
{
  std::vector<Note> notes_found;

  for(const auto& note : m_notes)
  {
    if(note.text() == text)
    {
      notes_found.push_back(note);
    }
  }

  return notes_found;
}

std::vector<Note> Storyboard::searchByTag(const std::vector<std::string>& tags) const
{
  std::vector<Note> notes_found;

  if(!tags.empty())
  {
    for(const auto& note : m_notes)
    {
      bool found = true;
      for(auto it = tags.begin(); it != tags.end() && found; ++it)
      {
        auto note_tags = note.tags();
        if(note_tags.find(*it)==note_tags.end())
        {
          found = false; 
        }
      }
      if(found)
      {
        notes_found.push_back(note);
      }
    }
  }

  return notes_found;
}

