#include <vector>
#include <iostream>

template<class T>
class Set {
    private:
        std::vector<T> data;

    public:
        Set();
        void add(T newItem);
        int getSize() const;
        T* getArray();
};

template<class T>
Set<T>::Set() {}

template<class T>
void Set<T>::add(T newItem) {
    data.push_back(newItem);
}

template<class T>
int Set<T>::getSize() const {
    return (data.size());
}

template<class T>
T* Set<T>::getArray() {
    return data.data(); 
}

using namespace std;

int main()
{
    Set<int> s1;
    Set<string> s2;
    int* intArray = NULL;
    string* stringArray = NULL; 
    int i;

    // Add some sample integers to the set
    s1.add(34); 
    s1.add(61);
    s1.add(31);
    s1.add(1);
    intArray = s1.getArray ();
    cout << "Set one has " << s1.getSize () << " items. Here they are: "<< endl;
    for (i = 0; i < s1.getSize(); i++)
        cout << intArray[i] << endl;
    
    // Add some sample strings to the set
    s2.add("apple") ;
    s2.add("orange");
    s2.add("chery") ;
    s2.add("banana") ;
    stringArray = s2.getArray();

    cout << "Set two has " << s2.getSize () << " items. Here they are: " << endl;
    for (i = 0; i < s2.getSize(); i++)
        cout << stringArray[i] << endl;

    return (0);
}
