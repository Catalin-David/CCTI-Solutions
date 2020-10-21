#include <iostream>
#include <queue>
#include <memory>

class Animal
{
protected:
    Animal(std::string &&animalName) : name(std::move(animalName))
    {
        orderNo = -1;
    }

public:
    virtual ~Animal()
    {
    }

    void setOrder(size_t order)
    {
        orderNo = order;
    }

    size_t getOrder() const
    {
        return orderNo;
    }

    const std::string &getName() const
    {
        return name;
    }

    bool operator < (const Animal &other)
    {
        return orderNo < other.orderNo;
    }

    template <typename T>
    static std::shared_ptr<Animal> create(std::string &&name)
    {
        return std::make_shared<T>(std::move(name));
    }

private:
    std::string name;
    size_t orderNo;
};

class Dog: public Animal
{
public:
    Dog(std::string &&name) : Animal(std::move(name))
    {
    }
};

class Cat: public Animal
{
public:
    Cat(std::string &&name) : Animal(std::move(name))
    {
    }
};

class Shelter
{
public:
    Shelter() : nextOrderNo(0)
    {
    }

    void enqueue(std::shared_ptr<Animal> &&animal)
    {
        if (auto dog = std::dynamic_pointer_cast<Dog>(animal))
        {
            dog->setOrder(nextOrderNo++);
            dogs.push(std::move(dog));
        }
        else if (auto cat = std::dynamic_pointer_cast<Cat>(animal))
        {
            cat->setOrder(nextOrderNo++);
            cats.push(std::move(cat));
        }
        else
            throw BadAnimalException();
    }

    std::shared_ptr<Animal> dequeueAny()
    {
        if (dogs.empty())
            return dequeueCat();
        else if (cats.empty())
            return dequeueDog();
        else if (*dogs.front() < *cats.front())
            return dequeueDog();
        else
            return dequeueCat();
    }

    std::shared_ptr<Animal> dequeueCat()
    {
        auto cat = cats.front();
        cats.pop();
        return std::static_pointer_cast<Animal>(cat);
    }

    std::shared_ptr<Animal> dequeueDog()
    {
        auto dog = dogs.front();
        dogs.pop();
        return std::static_pointer_cast<Animal>(dog);
    }

    class BadAnimalException {};

private:
    std::queue<std::shared_ptr<Dog>> dogs;
    std::queue<std::shared_ptr<Cat>> cats;
    size_t nextOrderNo;
};


int main()
{
    Shelter shelter;
    shelter.enqueue(Animal::create<Dog>("Rex"));
    std::cout<<shelter.dequeueDog()->getName()<<'\n';
    shelter.enqueue(Animal::create<Cat>("Lix"));
    std::cout<<shelter.dequeueAny()->getName()<<'\n';
    return 0;
}
