#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Student {
  string name;
  string nim;
  string region;
  string department;
  string faculty;
};

struct SkipNode {
  Student student;
  SkipNode** next;
  int level;
};

class SkipList {
 private:
  SkipNode* head;
  int max_level;
  int size;

 public:
  SkipList();
  void insert(Student student);
  void remove(string nim);
  Student* search(string nim);
  int getSize();
};

SkipList::SkipList() {
  head = new SkipNode;
  head->student = Student{"", "", "", "", ""};
  head->next = new SkipNode*[MAX_LEVEL + 1];
  head->level = MAX_LEVEL;
  for (int i = 0; i <= MAX_LEVEL; i++) {
    head->next[i] = NULL;
  }
  max_level = 0;
  size = 0;
}

void SkipList::insert(Student student) {
  SkipNode* current = head;
  SkipNode* update[MAX_LEVEL + 1];
  memset(update, 0, sizeof(SkipNode*) * (MAX_LEVEL + 1));

  for (int i = max_level; i >= 0; i--) {
    while (current->next[i] != NULL && current->next[i]->student.nim < student.nim) {
      current = current->next[i];
    }
    update[i] = current;
  }
  current = current->next[0];

  if (current == NULL || current->student.nim != student.nim) {
    int level = randomLevel();
    if (

