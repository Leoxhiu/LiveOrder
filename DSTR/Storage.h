#include <iostream>

using namespace std;

template <typename T>
class Storage {

    private:
        static Storage* instance;
        T data;

        // Private constructor so that no object can be created.
        Storage() {};

    public:
        //instance remains static and well not be overwritten easily without functions related to linked list and dynamic array
        static Storage<T>* getInstance() { 
            if (!instance) {
                instance = new Storage;
            }
              
            return instance;
        }

        T getData() {
            return this->data;
        }

        void setData(T data) {
            this->data = data;
        }
};