#include <iostream>
#include <list>
using namespace std;

class ISubscriber {
    public:
        virtual void notify(string msg) = 0;
};

class Subscriber: public ISubscriber {
    private:
        int subscriberId;
    public:
        Subscriber(int subscriberId) {
            this->subscriberId = subscriberId;
        }

        void notify(string msg) {
            cout<<"Subscriber "<<subscriberId<<" received msg "<<msg<<endl;
        }
};

class Publisher {
    private:
        list<ISubscriber*> subscribers;
    public:
        void subscribe(ISubscriber* user) {
            subscribers.push_back(user);
        }
    
        void unsubscribe(ISubscriber* user) {
            subscribers.remove(user);
        }
    
        void notify(string msg) {
            for(auto user : subscribers)
                user->notify(msg);
        }
    };
    
int main() {
    Publisher* pub = new Publisher;

    Subscriber* subscriber1 = new Subscriber(1);
    Subscriber* subscriber2 = new Subscriber(2);
    Subscriber* subscriber3 = new Subscriber(3);

    pub->subscribe(subscriber1);
    pub->subscribe(subscriber2);
    pub->subscribe(subscriber3);

    pub->notify("new msg");

    pub->unsubscribe(subscriber1);
    pub->notify("new new msg");

    return 0;
}
