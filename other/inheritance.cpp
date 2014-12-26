#include <iostream>

class Parent {
    public:
    Parent(const size_t x) {
        x_ = x;
    }

    virtual void say() const {
        std::cout << "x = " << x_ << std::endl;
    }

    protected:
    virtual size_t x_;
};


class Child : public Parent {
    public:
    Child(const size_t x, const size_t px) : Parent(px) {
        //this->Parent::x_ = x;
        this->x_ = x;
    }

    //void say() const {
    //    std::cout << "x = " << _x << std::endl;
    //}

    private:
    size_t x_;
};


int main() {
    Parent p(1);
    p.say();

    Child c(2,1);
    c.say();
    
    return 0;
}
