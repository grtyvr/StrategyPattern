#include <iostream>

class FlyBehaviour {
	// think of this as a strategy. In the context of flying behaviours,
	// the _thing_you_do_ = fly(),  _how_you_fly() will be determined later
	// implemented in a number of different instances of a flying behaviour/strategy.
	public:
		virtual ~FlyBehaviour() {} 
		// the _thing_you_do_ 
		virtual void fly() const = 0;		
};

class QuackBehaviour {
	public:
		virtual ~QuackBehaviour() {}
		virtual void quack() const = 0;
};

class FlyWings : public FlyBehaviour {  // a concrete strategy.  Fly using wings....
	public:
		void fly() const override 
		{
			std::cout << "Winged flight!" << std::endl;
		}
};

class FlyNo : public FlyBehaviour {
	public:
		void fly() const override 
		{
			std::cout << "No fly list." << std::endl;
		}
};

class Quack : public QuackBehaviour {
	public:
		void quack() const override {
			std::cout << "Quack" << std::endl;
		}
};

class Squeak : public QuackBehaviour {
	public:
		void quack() const override {
			std::cout << "squeekkk" << std::endl;
		}
};

class Mute : public QuackBehaviour {
	public:
		void quack() const override {
			std::cout << "shhh, wabbit season" << std::endl;
		} 
};

class Duck {
	private:
		// do not know what behaviours will be passed but
		// these will be a reference to that concrete strategy
		FlyBehaviour *flyBehaviour_;
		QuackBehaviour *quackBehaviour_;
	public:
		Duck()
		{

		}
		Duck(FlyBehaviour *flyBehaviour, QuackBehaviour *quackBehaviour)
		{

		}
		~Duck()
		{
			delete this->flyBehaviour_;
			delete this->quackBehaviour_;
		}
		void setFlyBehaviour(FlyBehaviour *flyBehaviour)
		{
			delete this->flyBehaviour_;
			this->flyBehaviour_ = flyBehaviour;
		}
		void performFly()
		{
			this->flyBehaviour_->fly();
		}

		void setQuackBehaviour(QuackBehaviour *quackBehaviour){
			delete this->quackBehaviour_;
			this->quackBehaviour_ = quackBehaviour;
		}
		void performQuack()
		{
				this->quackBehaviour_->quack();
		}
		void swim()
		{
			std::cout << "swimming" << std::endl;
		}
		void display()
		{
		}
};


int main(int argc, char *argv[])
{
	std::cout << "Duck world." << std::endl;
	Duck *malardDuck = new Duck();
	malardDuck->setFlyBehaviour(new FlyWings);
	malardDuck->setQuackBehaviour( new Quack);
	malardDuck->performQuack();
	malardDuck->performFly();
	// re-define the strategy  this mallard is a chic
	malardDuck->setQuackBehaviour(new Squeak);
	malardDuck->performQuack();

}
