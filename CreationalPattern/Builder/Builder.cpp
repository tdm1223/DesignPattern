#include<iostream>
#include<memory>
#include<string>

// Product
class Pizza
{
private:
    std::string dough;
    std::string sauce;
    std::string topping;

public:
    Pizza() = default;
    ~Pizza() = default;

    void SetDough(const std::string& d)
    {
        dough = d;
    };

    void SetSauce(const std::string& s)
    {
        sauce = s;
    };

    void SetTopping(const std::string& t)
    {
        topping = t;
    }

    void ShowPizza()
    {
        std::cout << "Yummy !!!" << std::endl
            << "Pizza with Dough as " << dough
            << ", Sauce as " << sauce
            << " and Topping as " << topping
            << " !!! " << std::endl;
    }
};

// Abstract Builder
class PizzaBuilder
{
protected:
    std::unique_ptr<Pizza> pizza;
public:
    PizzaBuilder() = default;
    virtual ~PizzaBuilder() {}
    std::unique_ptr<Pizza> GetPizza()
    {
        return std::move(pizza);
    }

    void createNewPizzaProduct()
    {
        pizza.reset(new Pizza);
    }

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
};

// ConcreteBuilder
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    HawaiianPizzaBuilder() : PizzaBuilder() {}
    ~HawaiianPizzaBuilder() = default;

    void buildDough()
    {
        pizza->SetDough("cross");
    }

    void buildSauce()
    {
        pizza->SetSauce("mild");
    }

    void buildTopping()
    {
        pizza->SetTopping("ham and pineapple");
    }
};

// ConcreteBuilder
class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    SpicyPizzaBuilder() : PizzaBuilder() {}
    ~SpicyPizzaBuilder() = default;

    void buildDough()
    {
        pizza->SetDough("pan baked");
    }

    void buildSauce()
    {
        pizza->SetSauce("hot");
    }

    void buildTopping()
    {
        pizza->SetTopping("pepperoni and salami");
    }
};

// Director
class Waiter
{
private:
    PizzaBuilder* pizzaBuilder;
public:
    Waiter() : pizzaBuilder(NULL) {}
    ~Waiter() = default;

    void SetPizzaBuilder(PizzaBuilder* b)
    {
        pizzaBuilder = b;
    }

    std::unique_ptr<Pizza> GetPizza()
    {
        return pizzaBuilder->GetPizza();
    }

    void ConstructPizza()
    {
        pizzaBuilder->createNewPizzaProduct();
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildTopping();
    }
};

// A customer ordering a pizza.
int main()
{
    Waiter waiter;

    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    waiter.SetPizzaBuilder(&hawaiianPizzaBuilder);
    waiter.ConstructPizza();
    std::unique_ptr<Pizza> pizza = waiter.GetPizza();
    pizza->ShowPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    waiter.SetPizzaBuilder(&spicyPizzaBuilder);
    waiter.ConstructPizza();
    pizza = waiter.GetPizza();
    pizza->ShowPizza();

    return 0;
}