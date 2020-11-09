#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class User;
class UserStatus;
class PrivateChat;
class GroupChat;
class AddRequest;
class Message;

enum UserStatusType {
	Offline, Away, Idle, Available, Busy
};

enum RequestStatus {
	Unread, Read, Accepted, Rejected
};

// UserManager serves as a central place for core user actions.
class UserManager {
	static UserManager* instance;
// maps from a user id to a user
	unordered_map<int, User*> usersById;

	// maps from an account name to a user
	unordered_map<string, User*> usersByAccountName;

	// maps from the user id to an online user
	unordered_map<int, User*> onlineUsers;

public:
	static UserManager* getInstance(){
		if(instance == nullptr){
	instance = new UserManager();
}
		return instance;
}

// void addUser(User* fromUser, string toAccountName {...}
// void approveAddRequest(AddRequest* req) {...}
// void rejectAddRequest(AddRequest* req) {..}
// void userSignedOn(string accountName) {...}
// void userSignedOff(string accountName) {...}
};

class User {
	int id;
	UserStatus* status = nullptr;

	// maps from the other participant's user id to the chat
	unordered_map<int, PrivateChat*> privateChats;

	// list of group chats
	vector<GroupChat*> groupChat;

	// maps from the other person's user id to the add request
	unordered_map<int, AddRequest*> receivedAddRequests;

	// maps from the other person's user id to the add request
	unordered_map<int, AddRequest*> sentAddRequests;

	// maps from the user id to user object
	unordered_map<int, User*> contacts;

	string accountName;
	string fullName;

public:
	/*
	User(int id, string accountName, string fullName) {...}
	bool sendMessageToUser(User* to, string content) {...}
	bool sendMessageToGroupChat(int id, string content) {...}
	void setStatus(UserStatus* status) {...}
	UserStatus* getStatus() {...}
	bool addContact(User* user) {...}
	void receivedAddRequest(AddRequest* req) {...}
	void sentAddRequest(AddRequest* req) {...}
	void removeAddRequest(AddRequest* req) {...}
	void requestAddUser(string accountName) {...}
	void addConversation(PrivateChat* conversation) {...}
	void addConversation(GroupChat* conversation) {...}
	int getId() {...}
	string getAccountName() {...}
	string getFullName() {...}
	*/
};

class Conversation {
protected:
	vector<User*> participants;
	int id;
	vector<Message*> messages;

	/*
public:
	vector<Message*> getMessages() {...}
	bool addMessage(Messag* m) {...}
	int getid() {...}
	*/
};

class GroupChat : public Conversation {
	/*
public:
	void removeParticipant(User* user) {...}
	void addParticipant(User* user) {...}
	*/
};

class PrivateChat : public Conversation {
/*
public:
	PrivateChat(User* user1, User* user2) {...}
	User* getOtherParticipant(User* primary) {...}
*/
};

class Message {
	string content;
	// Date date;
/*
public:
	Message(string content, Date date) {...}
	string getContent() {...}
	Date getDate() {...}
*/
};

class AddRequest {
	User* fromUser;
	User* toUser;
	// Date date;
	RequestStatus* status;

/*
public:
	AddRequest(User* from, User* to, Date date) {...}
	RequestStatus* getStatus() {...}
	User* getFromUser() {...}
	User* getToUser() {...}
	Date getDate() {...}
*/
};

class UserStatus {
	string message;
	UserStatusType* type;
/*
public:
	UserStatus(UserStatusType type, string message) {...}
	UserStatusType getStatusType() {...}
	string getMessage() {...}
*/
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
