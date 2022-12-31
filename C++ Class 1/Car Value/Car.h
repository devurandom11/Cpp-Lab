#ifndef CARH
#define CARH

class Car
{
private:
    int modelYear = -1;
    int purchasePrice = -1;
    int currentValue = -1;

public:
    void SetModelYear(int userYear);

    int GetModelYear() const;

    void SetPurchasePrice(int userPurchasePrice);

    int GetPurchasePrice() const;

    void CalcCurrentValue(int currentYear);

    void PrintInfo() const;
};

#endif