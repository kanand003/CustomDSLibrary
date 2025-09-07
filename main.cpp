#include "CustomTree.h"
#include "CustomList.h"
#include "CustomVector.h"
#include <string>
#include <iostream>



void VectorMenu() {
    MyVector<int> vec;
    int choice, value, pos, start, end;

    do {
        std::cout << "\n--- MyVector Menu ---\n";
        std::cout << "1. Push Back\n";
        std::cout << "2. Pop Back\n";
        std::cout << "3. Insert at Position\n";
        std::cout << "4. Erase Range\n";
        std::cout << "5. Print Elements\n";
        std::cout << "6. Size & Capacity\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value: "; std::cin >> value;
            vec.push_back(value);
            break;
        case 2:
            vec.pop_back();
            break;
        case 3:
            std::cout << "Enter value & position: "; std::cin >> value >> pos;
            vec.insert(value, pos);
            break;
        case 4:
            std::cout << "Enter start & end index: "; std::cin >> start >> end;
            vec.erase(start, end);
            break;
        case 5:
            std::cout << "Elements: ";
            for (auto it = vec.begin(); it != vec.end(); ++it) std::cout << *it << " ";
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "Size: " << vec.getSize() << " Capacity: " << vec.getCapacity() << std::endl;
            break;
        }
    } while (choice != 0);
}

void ListMenu() {
    CustomList<int> list;
    int choice, value, index, start, end;

    do {
        std::cout << "\n===== Custom List Menu =====\n";
        std::cout << "1. Push Front\n";
        std::cout << "2. Push Back\n";
        std::cout << "3. Pop Front\n";
        std::cout << "4. Pop Back\n";
        std::cout << "5. Get Element at Index\n";
        std::cout << "6. Insert at Index\n";
        std::cout << "7. Remove at Index\n";
        std::cout << "8. Erase Range\n";
        std::cout << "9. Front Element\n";
        std::cout << "10. Back Element\n";
        std::cout << "11. Size of List\n";
        std::cout << "12. Is Empty?\n";
        std::cout << "13. Clear List\n";
        std::cout << "14. Display List\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.push_front(value);
            break;
        case 2:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.push_back(value);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            std::cout << "Enter index: ";
            std::cin >> index;
            try {
                std::cout << "Element at " << index << ": " << list.get(index) << "\n";
            }
            catch (...) {
                std::cout << "Invalid index!\n";
            }
            break;
        case 6:
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Enter value: ";
            std::cin >> value;
            list.insert(index, value);
            break;
        case 7:
            std::cout << "Enter index: ";
            std::cin >> index;
            list.remove(index);
            break;
        case 8:
            std::cout << "Enter start index: ";
            std::cin >> start;
            std::cout << "Enter end index: ";
            std::cin >> end;
            list.erase(start, end);
            break;
        case 9:
            if (!list.empty())
                std::cout << "Front element: " << list.front() << "\n";
            else
                std::cout << "List is empty!\n";
            break;
        case 10:
            if (!list.empty())
                std::cout << "Back element: " << list.back() << "\n";
            else
                std::cout << "List is empty!\n";
            break;
        case 11:
            std::cout << "Size of list: " << list.size() << "\n";
            break;
        case 12:
            std::cout << (list.empty() ? "List is empty\n" : "List is not empty\n");
            break;
        case 13:
            list.clear();
            std::cout << "List cleared.\n";
            break;
        case 14:
            std::cout << "List contents: ";
            list.drawList();
            break;
        case 0:
            std::cout << "Exiting List Menu...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

void TreeMenu() {
    CustomTree<int> intTree;
    int choice, value;

    do {
        std::cout << "\n--- Binary Search Tree Menu ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Search\n";
        std::cout << "4. Inorder Traversal\n";
        std::cout << "5. Preorder Traversal\n";
        std::cout << "6. Postorder Traversal\n";
        std::cout << "7. Clear\n";
        std::cout << "8. Display Tree\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            intTree.Insert(value);
            break;
        case 2:
            std::cout << "Enter value to remove: ";
            std::cin >> value;
            intTree.Remove(value);
            break;
        case 3:
            std::cout << "Enter value to search: ";
            std::cin >> value;
            std::cout << (intTree.search(value) ? "Found\n" : "Not Found\n");
            break;
        case 4:
            std::cout << "Inorder Traversal: ";
            intTree.inorder();
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Preorder Traversal: ";
            intTree.preorder();
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "Postorder Traversal: ";
            intTree.postorder();
            std::cout << std::endl;
            break;
        case 7:
            intTree.clear();
            std::cout << "Tree cleared.\n";
            break;
        case 8:
            intTree.Display();
            std::cout << "Displaying Tree";
            break;
        /*case 9:
            intTree.findmin();
            std::cout << "Enter value to Remove";
            break;*/

        case 0:
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

int main() {
    int choice;

    do {
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "1. Binary Search Tree\n";
        std::cout << "2. Custom List\n";
        std::cout << "3. MyVector\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            TreeMenu();
            break;
        case 2:
            ListMenu();
            break;
        case 3:
            VectorMenu();
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}