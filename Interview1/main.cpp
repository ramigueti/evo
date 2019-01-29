#include <iostream>
#include "Storyboard.h"
#include "Note.h"

int main()
{
  Storyboard storyboard;
  storyboard.addNote(Note("Test Traceplayer", 
        "Implement a unit test for the class Traceplayer of the spark core framework.",
        {"unit test", "traceplayer", "testing", "spark core"}));
  storyboard.addNote(Note("Example 2", 
        "This is an example note for test the storyboard.",
        {"unit test", "example", "testing"}));
  storyboard.addNote(Note("Shopping list", 
        "I have to buy milk, meat and eggs.",
        {"shopping list", "milk", "meat", "eggs", "testing"}));

  auto search_by_title = storyboard.searchByTitle("Test Traceplayer");
  std::cout << "Result for search by title: " << std::endl;

  for (auto it = search_by_title.begin(); it != search_by_title.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }

  auto search_by_text = storyboard.searchByText("This is an example note for test the storyboard.");
  std::cout << "\nResult for search by text: " << std::endl;

  for (auto it = search_by_text.begin(); it != search_by_text.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  
  auto search_by_tags = storyboard.searchByTag({"testing"});
  std::cout << "\nResult for search by tags {\"testing\"}: " << std::endl;

  for (auto it = search_by_tags.begin(); it != search_by_tags.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  
  auto search_by_tags_2 = storyboard.searchByTag({"unit test", "testing", "example"});
  std::cout << "\nResult for search by tags {\"unit test\", \"testing\", \"example\"}: " << std::endl;

  for (auto it = search_by_tags_2.begin(); it != search_by_tags_2.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  
  auto search_by_tags_3 = storyboard.searchByTag({"milk", "testing", "example"});
  std::cout << "\nResult for search by tags {\"unit test\", \"testing\", \"example\"}: " << std::endl;

  for (auto it = search_by_tags_3.begin(); it != search_by_tags_3.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  
  auto search_by_tags_4 = storyboard.searchByTag({"milk", "shopping list"});
  std::cout << "\nResult for search by tags {\"milk\", \"shopping list\"}: " << std::endl;

  for (auto it = search_by_tags_4.begin(); it != search_by_tags_4.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  storyboard.deleteNote("Shopping list");
  auto search_by_tags_5 = storyboard.searchByTag({"milk", "shopping list"});
  std::cout << "\nResult for search by tags {\"milk\", \"shopping list\"} after delete: " << std::endl;

  for (auto it = search_by_tags_5.begin(); it != search_by_tags_5.end(); ++it)
  {
    std::cout << *it << std::endl; 
  }
  return 0;
}
