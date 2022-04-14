#include "friendship.h"

int main()
{
	Relations fri;

	fri.addFriend("Nicola");
	fri.addFriend("Varvara");
	fri.addFriend("Lisaveta");
	fri.addFriend("Maria");
	fri.addFriend("Petr");
	fri.addFriend("Stepan");
	fri.addFriend("Daria");
	fri.addFriend("Anton");
	fri.addFriend("Ivan");
	
	fri.addFriendship("Nicola", "Varvara");
	fri.addFriendship("Nicola", "Anton");
	fri.addFriendship("Nicola", "Ivan");
	fri.addFriendship("Varvara", "Lisaveta");
	fri.addFriendship("Varvara", "Daria");
	fri.addFriendship("Lisaveta", "Maria");
	fri.addFriendship("Maria", "Petr");
	fri.addFriendship("Petr", "Stepan");
	
	fri.threeHandShakes();
}