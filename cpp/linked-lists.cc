#include <stdio.h>

template<typename T>
struct LL {
	T data;
	LL *next = nullptr;

	~LL();
	void Append(T data);
	LL<T>* InsertBefore(LL<T> *item, T new_data);
	LL<T>* InsertAfter(LL<T> *item, T new_data);
	void Print();
};

template<typename T>
LL<T>::~LL() {
	if (next) {
		delete next;
	}
}

template<typename T>
void LL<T>::Append(T data) {
	LL<T> *current = this;
	while (current->next != nullptr) {
		current = current->next;
	}
	LL<T> *new_item = new LL<T>;
	new_item->data = data;
	current->next = new_item;
}

template<typename T>
LL<T>* LL<T>::InsertBefore(LL<T> *item, T new_data) {
	LL<T> *current = this;
	while (current != nullptr) {
		if (current == item) {
			LL<T> *new_item = new LL<T>;
			new_item->data = current->data;
			current->data = new_data;
			new_item->next = current->next;
			current->next = new_item;
			return new_item;
		}
		current = current->next;
	}
	return nullptr;
}

template<typename T>
LL<T>* LL<T>::InsertAfter(LL<T> *item, T new_data) {
	LL<T> *current = this;
	while (current != nullptr) {
		if (current == item) {
			LL<T> *new_item = new LL<T>;
			new_item->data = new_data;
			new_item->next = current->next;
			current->next = new_item;
			return new_item;
		}
		current = current->next;
	}
	return nullptr;
}


template<typename T>
void LL<T>::Print() {
	LL<T> *current = this;
	while (current != nullptr) {
		printf("%d\n", (int)current->data);
		current = current->next;
	}
}

void LinkedListsSetup(LL<int> **list_ref) {
	*list_ref = new LL<int>;
	LL<int> *list = *list_ref;
	list->data = 100;
	list->Append(101);
	list->Append(102);
}

void LinkedListsTeardown(LL<int> **list_ref) {
	delete *list_ref;
	*list_ref = nullptr;
}


void LinkedListsMain() {
	printf("===============================================\n");
	printf("LINKED LISTS\n");
	printf("===============================================\n");
	LL<int> *list = nullptr;

	printf("---------------------------\n");
	printf("InsertBefore\n");
	printf("---------------------------\n");
	LinkedListsSetup(&list);
	list->InsertBefore(list, 99);
	list->InsertBefore(list->next->next, 1005);
	list->Print();
	LinkedListsTeardown(&list);

	printf("---------------------------\n");
	printf("InsertAfter\n");
	printf("---------------------------\n");
	LinkedListsSetup(&list);
	list->InsertAfter(list->next, 999);
	list->Print();
	LinkedListsTeardown(&list);
}