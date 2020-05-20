#include <iostream>
#include <string>
#include <queue>

struct animalNode {
    std::string question;
    std::string guess;
    animalNode* yesAnswer;
    animalNode* noAnswer;
};

void printPreorder(struct animalNode* node){
    if (node == NULL)
        return;
  
    std::cout << node->question << " " << node->guess << "\n";
    printPreorder(node->yesAnswer);
    printPreorder(node->noAnswer);
}

int main(){
    bool flag = true;
    std::queue< animalNode* > q0;

    animalNode* cNode = new animalNode();
    cNode->guess = "mammual";
    cNode->yesAnswer = nullptr;
    cNode->noAnswer = nullptr;
    q0.push(cNode);

    std::string question;
    std::string input;
    std::string otherAnimal0;
    std::string otherAnimal1;

    std::cout << "Let's play the 'Guess the Animal' game.\n";
  
    animalNode* curNode = nullptr;
    animalNode* head = nullptr;
    head = cNode;
  
    curNode = cNode;

    while (flag) {
        if ((curNode->yesAnswer == nullptr) & (curNode->noAnswer == nullptr)) {
            std::cout << " Is it a(n) " << curNode->guess << "\n";
            getline(std::cin, input);
            if ((input == "y") |(input == "yes") ) {
                std::cout << " Good ! I guessed your animal\n";
            }
            else {
                otherAnimal0 = curNode->guess;
                std::cout << "What is your animal?\n";
                getline(std::cin, otherAnimal1);
                std::cout << "What is a yes/no question that I can use to tell a " << otherAnimal0 << " from a " << otherAnimal1 << "\n";
                getline(std::cin, question);
                animalNode* newAnimal1 = new animalNode();
                animalNode* newAnimal0 = new animalNode();
                newAnimal0->guess = otherAnimal0;
                newAnimal0->noAnswer = nullptr;
                newAnimal0->yesAnswer = nullptr;
                newAnimal1->guess = otherAnimal1;
                newAnimal1->noAnswer = nullptr;
                newAnimal1->yesAnswer = nullptr;
                curNode->guess.clear();
                curNode->question = question;
              
                q0.push(newAnimal0);
                q0.push(newAnimal1);

                std::cout << "For " << otherAnimal1 << " Is the answer yes or no? \n";
                getline(std::cin, input);
                if (input == "yes") {
                    curNode->yesAnswer = newAnimal1;
                    curNode->noAnswer = newAnimal0;
                }
                else {
                    curNode->yesAnswer = newAnimal0;
                    curNode->noAnswer = newAnimal1;
                }
            }

            std::cout << "Try again?\n";
            getline(std::cin, input);

            if ((input == "y" ) | (input == "yes")) {
                curNode = head;
                continue;
            }
            else {
                break;
            }
        }
        else {
            std::cout << curNode->question << "\n";
            getline(std::cin, input);
            if ((input == "y") | (input == "yes")) {
                curNode = curNode->yesAnswer;
                continue;
            }
            if ((input == "n") | (input == "no")) {
                curNode = curNode->noAnswer;
                continue;
            }
        }
    }

    std::cout << "Preoder Output of the tree built : \n";
    printPreorder(head);

    while (!q0.empty()) {
        cNode = q0.front();
        q0.pop();
        delete cNode;
    }
}


