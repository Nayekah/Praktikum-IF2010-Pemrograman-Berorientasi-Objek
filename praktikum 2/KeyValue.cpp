#include <iostream>
#include <cmath>
#include <string>

using namespace std;


template <class K, class V>
class KeyValue {
    private:
        K keys[10];
        V values[10];
        int size;

    public:
        KeyValue() : size(0) {}

        KeyValue(const KeyValue& other) : size(other.size) {
            int i;
            for (i = 0; i < size; i++) {
                keys[i] = other.keys[i];
                values[i] = other.values[i];
            }
        }

        ~KeyValue() {}

        KeyValue& operator=(const KeyValue& other) {
            if (this != &other) {
                size = other.size;

                int i;
                for (i = 0; i < size; i++) {
                    keys[i] = other.keys[i];
                    values[i] = other.values[i];
                }
            }
            return *this;
        }

        void set(const K& key, const V& value) {
            int i;
            int index = -1;
            for (i = 0; i < size; i++) {
                if (keys[i] == key) {
                    index = i;
                    break;
                }
            }
            
            if (index != -1) {
                values[index] = value;
            } else if (size < 10) {
                keys[size] = key;
                values[size] = value;
                size++;
            } else {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
        }

        void display(const K& key) const {
            int i;
            int index = -1;
            for (i = 0; i < size; i++) {
                if (keys[i] == key) {
                    index = i;
                    break;
                }
            }
            
            if (index != -1) {
                cout << values[index] << endl;
            } else {
                cout << "Key tidak ditemukan!" << endl;
            }
        }
};


template <class V>
class KeyValue<double, V> {
    private:
        double keys[10];
        V values[10];
        int size;
        const double EPSILON = 1e-10;

    public:
        KeyValue() : size(0) {}

        KeyValue(const KeyValue& other) : size(other.size) {
            int i;
            for (i = 0; i < size; i++) {
                keys[i] = other.keys[i];
                values[i] = other.values[i];
            }
        }

        ~KeyValue() {}

        KeyValue& operator=(const KeyValue& other) {
            if (this != &other) {
                size = other.size;

                int i;
                for (i = 0; i < size; i++) {
                    keys[i] = other.keys[i];
                    values[i] = other.values[i];
                }
            }
            return *this;
        }

        void set(const double& key, const V& value) {
            int i;
            int index = -1;
            for (i = 0; i < size; i++) {
                double diff = abs(keys[i] - key);
                if (diff < 0.01 - EPSILON) {
                    index = i;
                    break;
                }
            }
            
            if (index != -1) {
                values[index] = value;
            } else if (size < 10) {
                keys[size] = key;
                values[size] = value;
                size++;
            } else {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
        }

        void display(const double& key) const {
            int i;
            int index = -1;
            for (i = 0; i < size; i++) {
                double diff = abs(keys[i] - key);
                if (diff < 0.01 - EPSILON) {
                    index = i;
                    break;
                }
            }
            
            if (index != -1) {
                cout << values[index] << endl;
            } else {
                cout << "Key tidak ditemukan!" << endl;
            }
        }
};
