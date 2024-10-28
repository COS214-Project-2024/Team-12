#ifndef COAL_H
#define COAL_H

class Coal : IncomeResourceProduct1 {


private:
	Coal(int quantity, int marketValue);

	~Coal();

public:
	void displayStatus();
};

#endif
