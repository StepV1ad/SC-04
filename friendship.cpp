#include "friendship.h"

Relations::Friend& Relations::Friend::operator=(const Friend& friendName) {
    name_ = friendName.name_;
    id_ = friendName.id_;
    return *this;
}
Relations::Friend::Friend(const Friend& friendName)
{
    name_ = friendName.name_;
    id_ = friendName.id_;
}

Relations::Relations() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrixFriend[i][j] = 0;
}

void Relations::addFriend(std::string name)
{
    //cout << "ya tyt\n";
    if (attendName(name) != nullptr)
        return;
    static int id = 0;
    //cout << "id: " << id << endl;
    Friend newFriend = Friend(name, id++);
    friendList.push_back(newFriend);
}

void Relations::delFriend(std::string name)
{
    Friend* delFriend = attendName(name);
    if (delFriend == nullptr)
        return;
    for (unsigned int i = 0; i < friendList.size(); i++) {
        matrixFriend[i][delFriend->id_] = 0;
        matrixFriend[delFriend->id_][i] = 0;
    }
    for (auto delName : friendList)
        if (delName.name_ == name)
            friendList.erase(friendList.begin() + delFriend->id_);
}

void Relations::addFriendship(std::string name_1, std::string name_2)
{
    if ((attendName(name_1) == nullptr) || (attendName(name_2) == nullptr))
        return;
    Friend* f1 = attendName(name_1);
    Friend* f2 = attendName(name_2);
    if (f1->id_ < 0 || f2->id_ < 0)
        return;
    matrixFriend[f1->id_][f2->id_] = 1;
    matrixFriend[f2->id_][f1->id_] = 1;
}

void Relations::delFriendship(std::string name_1, std::string name_2)
{
    Friend* delOne = attendName(name_1);
    Friend* delTwo = attendName(name_2);
    if ((delOne->id_ < 0) || (delTwo->id_ < 0))
        return;
    for (unsigned int i = 0; i < friendList.size(); i++) {
        matrixFriend[delTwo->id_][delOne->id_] = 0;
        matrixFriend[delOne->id_][delTwo->id_] = 0;
    }
}

void Relations::threeHandShakes()
{
    int levels[SIZE];
    for (int i = 0; i < SIZE; i++) {
        levels[i] = -1;
    }
    levels[0] = 0;

    std::vector<int> queue;
    queue.push_back(0);

    while (queue.size()) {
        int currentManIndex = queue[0];
        queue.pop_back();
        for (int i = 0; i < friendList.size(); i++)
            if (friendOrNot(friendList[currentManIndex].name_, friendList[i].name_) &&
                levels[i] == -1)
            {
                levels[i] = levels[currentManIndex] + 1;
                queue.push_back(i);
            }
    }

    for (int i = 0; i < friendList.size(); i++) {
        for (int j = i + 1; j < friendList.size(); j++) {
            if (abs(levels[i] - levels[j]) <= 3) {
                std::cout << friendList[i].name_ << " " << friendList[j].name_ << std::endl;
            }
        }
    }
}


bool Relations::friendOr(const int name_1, const int name_2)
{
    for (auto& findName1 : friendList)
        for (auto& findName2 : friendList)
            if ((findName1.id_ == name_1) && (findName2.id_ == name_2))
                return (matrixFriend[findName1.id_][findName2.id_] == 1);
    return false;
}

bool Relations::friendOrNot(const std::string& name_1, const std::string& name_2)
{
    for (auto& findName1 : friendList)
        for (auto& findName2 : friendList)
            if ((findName1.name_ == name_1) && (findName2.name_ == name_2))
                return (matrixFriend[findName1.id_][findName2.id_] == 1);
    return false;
}

Relations::Friend* Relations::attendName(const std::string& name)
{
    for (auto& findName : friendList)
        if (findName.name_ == name)
            return &findName;
     return nullptr;
}
