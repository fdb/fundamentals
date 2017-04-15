#include <stdio.h>

struct ListNode {
    char data;
    ListNode *next = nullptr;
};

struct LinkedList {
    ListNode *start = nullptr;

    ~LinkedList();
    ListNode* Append(char new_data);
    //ListNode* InsertBefore(ListNode *item, char new_data);
    //ListNode* InsertAfter(ListNode *item, char new_data);
    bool Delete(ListNode *item);
    void Print();
};

LinkedList::~LinkedList() {
    // TODO: find a way to delete nodes without recursion.
}

ListNode* LinkedList::Append(char new_data) {
    ListNode *new_node = new ListNode;
    new_node->data = new_data;
    if (start == nullptr) {
        start = new_node;
    } else {
        // Walk to end of list.
        ListNode *cur = this->start;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    return new_node;
}

bool LinkedList::Delete(ListNode *item) {
  if (start == nullptr) return false;
  ListNode **ref = &start;
  while (*ref != nullptr) {
    if ((*ref) == item) {
      ListNode *next = (*ref)->next;
      delete *ref;
      *ref = next;
      return true;
    }
    ref = &((*ref)->next);
  }
  return false;
}

// template<typename T>
// LL<T>* LL<T>::InsertBefore(LL<T> *item, T new_data) {
// 	LL<T> *current = this;
// 	while (current != nullptr) {
// 		if (current == item) {
// 			LL<T> *new_item = new LL<T>;
// 			new_item->data = current->data;
// 			current->data = new_data;
// 			new_item->next = current->next;
// 			current->next = new_item;
// 			return new_item;
// 		}
// 		current = current->next;
// 	}
// 	return nullptr;
// }

// template<typename T>
// LL<T>* LL<T>::InsertAfter(LL<T> *item, T new_data) {
// 	LL<T> *current = this;
// 	while (current != nullptr) {
// 		if (current == item) {
// 			LL<T> *new_item = new LL<T>;
// 			new_item->data = new_data;
// 			new_item->next = current->next;
// 			current->next = new_item;
// 			return new_item;
// 		}
// 		current = current->next;
// 	}
// 	return nullptr;
// }


void LinkedList::Print() {
  ListNode* it = start;
  printf("[");
  bool first = true;
  while (it != nullptr) {
    if (first) {
      first = false;
    } else {
      printf(" ");
    }
    printf("%c", it->data);
    it = it->next;
  }
  printf("]\n");
}

void LinkedListSetup(LinkedList *list) {
  list->Append('A');
  list->Append('B');
  list->Append('C');
}

void LinkedListTeardown(LinkedList *list) {
  // TODO: Delete list-items.
  list->start = nullptr;
}


void LinkedListMain() {
    printf("===============================================\n");
    printf("LINKED LISTS\n");
    printf("===============================================\n");
    LinkedList list;
    
    printf("---------------------------\n");
    printf("Setup / Teardown\n");
    printf("---------------------------\n");
    list.Print();
    LinkedListSetup(&list);
    list.Print();
    LinkedListTeardown(&list);
    list.Print();
    
    printf("---------------------------\n");
    printf("Delete\n");
    printf("---------------------------\n");
    LinkedListSetup(&list);
    list.Delete(list.start->next);
    list.Print();
    list.Delete(list.start);
    list.Print();
    list.Delete(list.start);
    list.Print();
    list.Delete(list.start);
    list.Print();
    LinkedListTeardown(&list);
    
    
    // printf("---------------------------\n");
    // printf("InsertBefore\n");
    // printf("---------------------------\n");
    // LinkedListSetup(&list);
    // list->InsertBefore(list, 99);
    // list->InsertBefore(list->next->next, 1005);
    // list->Print();
    // LinkedListTeardown(&list);

    // printf("---------------------------\n");
    // printf("InsertAfter\n");
    // printf("---------------------------\n");
    // LinkedListSetup(&list);
    // list->InsertAfter(list->next, 999);
    // list->Print();
    // LinkedListTeardown(&list);
}