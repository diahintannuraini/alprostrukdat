#include <iostream>
#include <queue>
#include <string>

class Animal {
public:
    std::string type;
    int order;

    Animal(std::string t, int o) : type(t), order(o) {}
};

class AnimalShelter {
private:
    std::queue<Animal> dogs;
    std::queue<Animal> cats;
    int order;

public:
    AnimalShelter() : order(0) {}

    void enqueue(std::string type) {
        Animal animal(type, order++);
        if (type == "dog") {
            dogs.push(animal);
            std::cout << "Enqueued dog with order " << animal.order << std::endl;
        } else if (type == "cat") {
            cats.push(animal);
            std::cout << "Enqueued cat with order " << animal.order << std::endl;
        } else {
            std::cout << "Invalid animal type!" << std::endl;
        }
    }

    Animal dequeueAny() {
        if (dogs.empty() && cats.empty()) {
            std::cout << "No animals available for adoption." << std::endl;
            return Animal("none", -1);
        }

        if (dogs.empty()) {
            return dequeueCat();
        }

        if (cats.empty()) {
            return dequeueDog();
        }

        Animal dog = dogs.front();
        Animal cat = cats.front();

        if (dog.order < cat.order) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    Animal dequeueDog() {
        if (dogs.empty()) {
            std::cout << "No dogs available for adoption." << std::endl;
            return Animal("none", -1);
        }

        Animal dog = dogs.front();
        dogs.pop();
        std::cout << "Dequeued dog with order " << dog.order << std::endl;
        return dog;
    }

    Animal dequeueCat() {
        if (cats.empty()) {
            std::cout << "No cats available for adoption." << std::endl;
            return Animal("none", -1);
        }

        Animal cat = cats.front();
        cats.pop();
        std::cout << "Dequeued cat with order " << cat.order << std::endl;
        return cat;
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");

    shelter.dequeueAny();
    shelter.dequeueDog();
    shelter.dequeueCat();
    shelter.dequeueAny();

    return 0;
}
