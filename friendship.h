#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define SIZE 20

class Relations { // класс дерева
public:
    struct Friend { // структура узла
        Friend();
        Friend(std::string name, int id) : name_(name), id_(id) {};
        Friend& operator=(const Friend& name);
        Friend(const Friend& name);
        std::string name_;
        int id_;
    };
    Relations();
    
    void addFriend(std::string name); // добавление друга
    void delFriend(std::string name); // удаление друга
    void addFriendship(std::string name_1, std::string name_2); // установка дружбы между людьми
    void delFriendship(std::string name_1, std::string name_2); // удаление дружбы между людьми
    void threeHandShakes(); // три рукопожатия
    
    bool friendOrNot(const std::string& name_1, const std::string& name_2); // наличие дружбы
    bool friendOr(const int name_1, const int name_2);
    Friend* attendName(const std::string& name); // наличие человека
    std::vector<Friend> friendList; // хранилище друзей
    int matrixFriend[SIZE][SIZE]; // матрица дружбы
};