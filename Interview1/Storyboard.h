#ifndef __STORYBOARD_H__
#define __STORYBOARD_H__

#include <vector>
#include <string>

class Note;

class Storyboard
{
public:
	void addNote(const Note& note);
	void deleteNote(const std::string& title, bool all_ocurrences=true);
  std::vector<Note> searchByTitle(const std::string& title) const;
  std::vector<Note> searchByText(const std::string& text) const;
  std::vector<Note> searchByTag(const std::vector<std::string>& tags) const;
	
private:
  std::vector<Note> m_notes;	
};

#endif
